#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

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

typedef struct
{
    uint32_t SR;
    uint32_t DR; 
    /* data */
}UART_Reg;


void circular_buff_init(CirBufdata *cb);
int write_data(CirBufdata *cb, int data);
int read_data(CirBufdata *cb, int *data_read);
void uart_write();
void uart_write_data_poll(UART_Reg *uart_reg, uint8_t data) {
    if((uart_reg->SR & TXE)) {
        uart_reg->DR = data;
    }
} 
void tx_status_flag(UART_Reg *uart_reg) {
    if(uart_reg->DR!=0) {
        uart_reg->SR = 0x00000040;
    }
    //uart_reg->SR = 0x00000000;
    
    
}
void UART_init(UART_Reg *uart_reg) {
    uart_reg->SR = 0x00000000;
    uart_reg->DR = 0x00000000;
}

int main(void) {

    // CirBufdata txbuf, rxbuf;
    UART_Reg uart_reg;
    // circular_buff_init(&txbuf);
    // circular_buff_init(&rxbuf);
    
    uart_write_data(&uart_reg, 10);

    return 0;
}

void circular_buff_init(CirBufdata *cb) {
    cb->head = 0;
    cb->tail = 0;
}
int uart_write_data(CirBufdata *cb, int data) {
    int next = ((cb->head+1)%SIZE);
    if(next == cb->tail){
        return 0;
    }
    cb->data_buffer[cb->head] = data;
    cb->head = next;
    return 1;
}
int uart_poll_tx(CirBufdata *txbuf, UART_Reg *uart2) 
{ 
    if((uart2->SR & TXE) && (txbuf->head != txbuf->tail)) 
    { 
        uart2->DR = txbuf->data_buffer[txbuf->tail]; 
        txbuf->tail = (txbuf->tail + 1) % SIZE; 
        return 1;
    }
    return 0; 
} 

int uart_read_data(CirBufdata *cb, int *data_read) {
    if(cb->tail==cb->head) {
        return 0;
    }
    *data_read = cb->data_buffer[cb->tail];
    cb->tail = ((cb->tail+1)%SIZE);
    return 1;
}
int uart_poll_rx(CirBufdata *rxbuf, UART_Reg *uart2) 
{ 
    int next = (rxbuf->head + 1) % SIZE;
    if((uart2->SR & RXNE) && (next != rxbuf->tail)) 
    { 
        rxbuf->data_buffer[rxbuf->head] = uart2->DR;
        rxbuf->tail = next; 
        return 1;
    }
    return 0; 
} 
