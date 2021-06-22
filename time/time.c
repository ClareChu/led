//
// Created by clare on 2021/6/19.
//

#include <reg52.h>

void Init_Time();
void Timer_isr1();
void Timer_isr();
sbit LED = P0^1;

void Init_Time1();

int main() {
    Init_Time1();
    while (1) {

    }
}

//定时器1
void Init_Time() {
    TMOD |= 0x01;
    TH0 = 0x00;
    TL0=0x00;
    EA=1;
    ET0=1;
    TR0=1;
}

// 定时器2

int Sleep_Time=2000;

void Init_Time1() {
    RCAP2H = (65536-Sleep_Time)/256;
    RCAP2L = (65536-Sleep_Time)%256;
    ET2=1;
    EA=1;
    TR2=1;
}

void Timer_isr() interrupt 1 using 1 {
    TH0 = 0x00;
    TL0=0x00;
    LED = ~LED;
}


void Timer_isr1() interrupt 5 using 1 {
    TF2=0;
    LED = ~LED;
}
