//
// Created by clare on 2021/6/19.
//


#include <reg52.h>
#include <stdio.h>


char LED1[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void set_key();
//位锁存
sbit LATCH1=P2^2;
//段锁存
sbit LATCH2=P2^3;

char light = 0x0;

// 初始化定时器
void Init_Time();
// 中断
void Timer_isr();

void set(int dtt);

void display(char i, char value);

void delay(int i);
 
#define SLEEP 3000

int DATA;
int main() {
    DATA = 56;
   Init_Time();
    while (1) {
        set_key();
    }
}



//定时器1
void Init_Time() {
    TMOD |= 0x01;	  //使用模式1，16位定时器，使用"|"符号可以在使用多个定时器时不受影响
    //TH0=0x00;	      //给定初值
    //TL0=0x00;
    EA=1;            //总中断打开
    ET0=1;           //定时器中断打开
    TR0=1;           //定时器开关打开
}

void Timer_isr() interrupt 1 using 1 {
    TH0=(65536-10000)/256;		  //重新赋值 2ms
    TL0=(65536-10000)%256;
    set(DATA);
}

//位锁存
char w[]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

// 显示
void display(char i, char value) {
    P0=w[7-i];
    LATCH1=1;
    LATCH1=0;
    P0=~LED1[value];
    LATCH2=1;
    LATCH2=0;
}

void set(int dtt) {
    int d = dtt;
    char w=0;
    while (1) {
        if (d < 10) {
            display(w, d);
            delay(200);
            return;
        }
        display(w, d%10);
        d=d/10;
        w++;
        delay(200);
    }
}


void delay(int j) {
    unsigned int i;
    for(i=0;i<j;i++);

}

sbit KEY1=P1^0;
sbit KEY2=P1^1;

void set_key() {
    if (KEY1==0) {
        delay(20);
        if (KEY1 == 0) {
            while (1) {
                if (KEY1 == 1) {
                    DATA++;
                    return;
                }
            }
        }
    }

    if (KEY2==0) {
        delay(20);
        if (KEY2 == 0) {
            while (1) {
                if (KEY2 == 1) {
                    DATA--;
                    return;
                }
            }
        }
    }
}