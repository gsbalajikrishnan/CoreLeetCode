#include<stdio.h>
#include<stdint.h>
typedef union{
    uint8_t Reg;
    struct
    {
        uint8_t id:1;
        uint8_t data:5;
        uint8_t reserved:2;
        /* data */
    }Bits;
    /* data */
}GPIO_CTRL_REG;
int main() {
    GPIO_CTRL_REG GPIO_CTRL;
    //GPIO_CTRL ctrl_reg;
    GPIO_CTRL.Reg = 0x90;
    GPIO_CTRL.Bits.id = 1;
    GPIO_CTRL.Bits.data = 11;
    GPIO_CTRL.Bits.reserved = 3;
    printf("%x ",GPIO_CTRL.Reg);
    printf("%x ",GPIO_CTRL.Bits.id);
    printf("%x ",GPIO_CTRL.Bits.reserved);
    return 0;
}
