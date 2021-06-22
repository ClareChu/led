//
// Created by clare on 2021/6/17.
//



#include <reg52.h>
void delay1(int time);
void display(int i, int value);
void set(long jj);
char LED1[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
#define dp P0;
//位锁存
sbit LATCH1=P2^2;
//段锁存
sbit LATCH2=P2^3;

long dt=65712529;

char light = 0x0;

int main() {
    while (1) {
        long jj;
        for (jj = dt; jj > 0;jj--) {
            set(jj);
            delay1(600);
        }
    }
     return 0;
}


void delay1(int j) {
    unsigned int i;
    for(i=0;i<j;i++);

}

char w[]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

void display(int i, int value) {
    P0=w[i];
    LATCH1=1;
    LATCH1=0;
    P0=~LED1[value];
    LATCH2=1;
    LATCH2=0;
}

void set(long dtt) {
    long d = dtt;
    long j = 7;
    long value;
    while (1) {
        if (d < 10) {
            display(j ,d);
            delay1(100);
            return;
        }
        value = d%10;
        d = d/10;
        display(j, value);
        delay1(100);
        j--;
    }
}