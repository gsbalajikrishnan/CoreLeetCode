#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define TXE    (1<<7)
#define RXNE   (1<<5)
#define TXEIE  (1<<7)
#define RXNEIE (1<<5)

typedef struct
{
    uint32_t CR1;
    uint32_t SR;
    uint32_t DR;
    /* data */
}UART_Reg;

UART_Reg reg;

void uart_init();
void uart_write(uint8_t data);
void uart_hw_read();
void UART_IRQhandler();

int main() {
    
    uart_init();
    int i=0;
    char data[] = "Hello world data";
    int len = strlen(data)-1;
    while (i<=len)
    {
        uart_write(data[i]);
        uart_hw_read();
        /* code */
        i++;
    }
    return 0;
}
void uart_init() {
    reg.SR |= TXE;
    reg.CR1 |= RXNEIE;
}
void uart_write(uint8_t data) {
    if(reg.SR & TXE) {
        reg.DR = data;
        reg.SR &= ~TXE;
        reg.CR1 |= RXNEIE;
    }
    //reg->SR &= ~TXE;
}
void UART_IRQhandler() {
    if((reg.SR & TXE)==0) {
        putchar(reg.DR);
        reg.SR |= TXE;
        reg.CR1 &= ~RXNEIE;
    }
}
void uart_hw_read() {
    if(reg.CR1 & RXNEIE){
        UART_IRQhandler();
    }
}
