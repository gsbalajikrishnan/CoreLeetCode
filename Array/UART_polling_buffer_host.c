#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#define SIZE 10
#define TXE (1<<7)
#define RXNE (1<<5)

typedef struct
{
    uint8_t data_buffer[SIZE];
    uint8_t head;
    uint8_t tail;
    /* data */
}CirBufdata;

CirBufdata txbuf, rxbuf;

typedef struct 
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    /* data */
}UART_Reg;

void uart_init(UART_Reg *uart);
void buffer_init();
void tx_buffer_write(char *data);
void uart_write_data(char *data);
void uart_buffer_polling(UART_Reg *uart_reg);
void uart_hw_tick(UART_Reg *uart_reg);

    /* Application
        ↓
    UART API
        ↓
    Driver (Polling / Interrupt)
        ↓
    Ring Buffer
        ↓
    UART Hardware */

int main()
{
    UART_Reg uart;

    uart_init(&uart);

    uart_write_data("Hello");
    while (1)
    {
        uart_buffer_polling(&uart);
        uart_hw_tick(&uart);
        /* code */
        if(txbuf.tail == txbuf.head) 
            break;
    }
    return 0;
}
void uart_init(UART_Reg *uart) {
    uart->SR |= TXE; // TXR is initially empty
}
void buffer_init() {
    txbuf.head = txbuf.tail = 0;
    rxbuf.head = rxbuf.tail = 0;
}
void tx_buffer_write(char *data) 
{
    uint8_t next = (txbuf.head+1)%SIZE;
    if((next!=txbuf.tail)) {
        txbuf.data_buffer[txbuf.head] = *data; 
        txbuf.head = (txbuf.head + 1) % SIZE;
    }
    else {
        printf("Buffer is Full");
    } 
} 

void uart_write_data(char *str) {
    while (*str!='\0')
    {
        tx_buffer_write(str);
        str++;
        /* code */
    }   
}
void uart_buffer_polling(UART_Reg *uart_reg) {
    if((uart_reg->SR & TXE) && (txbuf.head!=txbuf.tail)) {
        uart_reg->DR = txbuf.data_buffer[txbuf.tail];
        txbuf.tail = (txbuf.tail+1)%SIZE;
        uart_reg->SR &= ~(TXE);
    }
}
void uart_hw_tick(UART_Reg *uart) {
    //Simulate the real hardware
    //TDR to shift register to TX pin
    //DR → stdout / file
    if((uart->SR & TXE)==0) {
        putchar(uart->DR);
        uart->SR |= TXE;
    }
}