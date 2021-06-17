//
// Created by clare on 2021/6/17.
//



#include <reg52.h>
void delay1(int time);

char LED1[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
#define dp P0;
//位锁存
sbit LATCH1=P2^2;
//段锁存
sbit LATCH2=P2^3;

char light = 0x0;

int main() {

    int i;
    // 1111 1110 第0 位
    P0=0xfe;
    // 打开位锁存
    LATCH1=1;
    // 关闭
    LATCH1=0;

    while (1) {
        for (i = 0; i < sizeof(LED1); ++i) {
            // 段锁存
            P0=~LED1[i];
            LATCH2=1;
            LATCH2=0;
            delay1(30000);
            P0=light;
            LATCH2=1;
            LATCH2=0;
            delay1(30000);
        }

    }
    return 0;
}


void delay1(int j) {
    unsigned int i;
    for(i=0;i<j;i++);

}

