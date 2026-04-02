#include<stdio.h>
#include<stdint.h>

#define TXE (1<<7)
#define RXNE (1<<5)

typedef struct 
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    /* data */
}UART_Reg;
void uart_init(UART_Reg *uart);
void uart_write_data(UART_Reg *uart_reg, uint8_t);
void uart_hw_tick(UART_Reg *uart_reg);
int main()
{
    UART_Reg uart;

    uart_init(&uart);

    uart_write_data(&uart, 'H');
    uart_hw_tick(&uart);

    uart_write_data(&uart, 'i');
    uart_hw_tick(&uart);

    return 0;
}
void uart_init(UART_Reg *uart) {
    uart->SR |= TXE; // TXR is initially empty
}
void uart_write_data(UART_Reg *uart, uint8_t data) {
    if(uart->SR & TXE) {
        uart->DR = data;
        uart->SR &= ~(TXE);
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