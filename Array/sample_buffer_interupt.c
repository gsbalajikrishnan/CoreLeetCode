//Example Interrupt Driver Design

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 32

#define TXE  (1<<7)
#define RXNE (1<<5)

#define TXEIE  (1<<7)
#define RXNEIE (1<<5)

/* ---------------- Ring Buffer ---------------- */

typedef struct
{
    uint8_t data[SIZE];
    uint8_t head;
    uint8_t tail;

} CirBuf;

CirBuf txbuf, rxbuf;

/* ---------------- UART Registers ---------------- */

typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CR1;

} UART_Reg;

UART_Reg USART2;

/* ---------------- Buffer Functions ---------------- */

bool check_if_buf_empty(CirBuf *buf)
{
    return buf->head == buf->tail;
}

bool check_if_buf_full(CirBuf *buf)
{
    return ((buf->head + 1) % SIZE) == buf->tail;
}

void buffer_write(CirBuf *buf, uint8_t data)
{
    if(!check_if_buf_full(buf))
    {
        buf->data[buf->head] = data;
        buf->head = (buf->head + 1) % SIZE;
    }
}

uint8_t buffer_read(CirBuf *buf)
{
    uint8_t data = buf->data[buf->tail];
    buf->tail = (buf->tail + 1) % SIZE;
    return data;
}

/* ---------------- UART Init ---------------- */

void uart_init()
{
    USART2.SR = TXE;        // TX register empty
    USART2.CR1 |= RXNEIE;   // enable RX interrupt
}

/* ---------------- UART API ---------------- */

void uart_write(uint8_t data)
{
    buffer_write(&txbuf, data);

    /* enable TX interrupt */
    // USART2.CR1 |= TXEIE;
}

void uart_write_string(char *str)
{
    while(*str)
    {
        uart_write(*str++);
    }
    /* enable TX interrupt */
    USART2.CR1 |= TXEIE;
}


uint8_t uart_read()
{
    while(check_if_buf_empty(&rxbuf));

    return buffer_read(&rxbuf);
}

/* ---------------- UART ISR ---------------- */

void USART2_IRQHandler()
{
    /* TX interrupt */

    if((USART2.SR & TXE))
    {
        if(!check_if_buf_empty(&txbuf))
        {
            USART2.DR = buffer_read(&txbuf);
            USART2.SR &= ~TXE;
        }
        else
        {
            /* disable interrupt if buffer empty */

            USART2.CR1 &= ~TXEIE;
        }
    }

    /* RX interrupt */

    if((USART2.SR & RXNE) && (USART2.CR1 & RXNEIE))
    {
        buffer_write(&rxbuf, USART2.DR);
        USART2.SR &= ~RXNE;
    }
}

/* ---------------- Hardware Simulation ---------------- */

void uart_hw_tick()
{
    /* simulate transmission */
    if(USART2.CR1 & TXEIE)
        USART2_IRQHandler();

    if((USART2.SR & TXE) == 0)
    {
        putchar(USART2.DR);
        fflush(stdout);

        USART2.SR |= TXE;

    }
}

/* ---------------- Application ---------------- */

void process_data(uint8_t data)
{
    printf("\nRX:%c\n", data);
}

/* ---------------- Main ---------------- */

int main()
{
    uart_init();

    uart_write_string("Hello Interrupt UART\n");

    while (txbuf.head!=txbuf.tail)
    {
        uart_hw_tick();
        /* code */
    }
    return 0;
}