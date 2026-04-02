#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* ---------------- UART FLAGS ---------------- */

#define TXE  (1 << 7)
#define RXNE (1 << 5)

/* ---------------- UART REGISTER STRUCT ---------------- */

typedef struct
{
    volatile uint32_t SR;
    volatile uint8_t DR;
} UART_Reg;

UART_Reg USART2;

/* ---------------- RING BUFFER ---------------- */

#define BUF_SIZE 64

typedef struct
{
    uint8_t buf[BUF_SIZE];
    int head;
    int tail;
} RingBuffer;

RingBuffer tx_buffer;
RingBuffer rx_buffer;

/* ---------------- RING BUFFER FUNCTIONS ---------------- */

bool ringbuf_empty(RingBuffer *rb)
{
    return rb->head == rb->tail;
}

bool ringbuf_full(RingBuffer *rb)
{
    return ((rb->head + 1) % BUF_SIZE) == rb->tail;
}

void ringbuf_put(RingBuffer *rb, uint8_t data)
{
    if(!ringbuf_full(rb))
    {
        rb->buf[rb->head] = data;
        rb->head = (rb->head + 1) % BUF_SIZE;
    }
}

uint8_t ringbuf_get(RingBuffer *rb)
{
    uint8_t data = 0;

    if(!ringbuf_empty(rb))
    {
        data = rb->buf[rb->tail];
        rb->tail = (rb->tail + 1) % BUF_SIZE;
    }

    return data;
}

/* ---------------- UART HARDWARE SIMULATION ---------------- */

void uart_hw_tick()
{
    /* Simulate transmission */
    if((USART2.SR & TXE) == 0)
    {
        putchar(USART2.DR);
        fflush(stdout);
        USART2.SR |= TXE;
    }

    /* Simulate reception from keyboard */
    if(!(USART2.SR & RXNE))
    {
        int c = getchar();
        if(c != EOF)
        {
            USART2.DR = c;
            USART2.SR |= RXNE;
        }
    }
}

/* ---------------- DRIVER POLLING ---------------- */

void uart_driver_poll()
{
    /* Transmit handler */
    if((USART2.SR & TXE) && !ringbuf_empty(&tx_buffer))
    {
        USART2.DR = ringbuf_get(&tx_buffer);
        USART2.SR &= ~TXE;
    }

    /* Receive handler */
    if(USART2.SR & RXNE)
    {
        ringbuf_put(&rx_buffer, USART2.DR);
        USART2.SR &= ~RXNE;
    }
}

/* ---------------- UART API ---------------- */

void uart_init()
{
    USART2.SR = TXE;
    USART2.SR = ~RXNE;

    tx_buffer.head = tx_buffer.tail = 0;
    rx_buffer.head = rx_buffer.tail = 0;
}

void uart_write(uint8_t data)
{
    ringbuf_put(&tx_buffer, data);
}

void uart_write_string(const char *str)
{
    while(*str)
    {
        uart_write(*str++);
    }
}

uint8_t uart_read()
{
    while(ringbuf_empty(&rx_buffer))
    {
        uart_driver_poll();
        uart_hw_tick();
    }

    return ringbuf_get(&rx_buffer);
}

/* ---------------- APPLICATION ---------------- */

void process_data(uint8_t data)
{
    printf("\nReceived: %c\n", data);
}

/* ---------------- MAIN ---------------- */

int main()
{
    uart_init();

    uart_write_string("Hello UART\n");

    while(1)
    {
        uart_driver_poll();
        uart_hw_tick();

        if(!ringbuf_empty(&rx_buffer))
        {
            uint8_t data = uart_read();
            process_data(data);
        }
    }
}