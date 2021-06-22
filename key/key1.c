//
// Created by clare on 2021/6/18.
//

#include <reg52.h>

sbit LED = P0^1;
sbit KEY_BORD=P1^1;

int main() {
    while (1) {

        if (KEY_BORD == 0) {
            int i;
            for (i = 0; i < 5000; ++i) {

            }
            if (KEY_BORD != 0){
                while (KEY_BORD == 0){

                }
                LED = !KEY_BORD;
            }
        }

        LED=KEY_BORD;
    }
    return 0;
}

