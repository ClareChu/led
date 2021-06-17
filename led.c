
#include<reg52.h>
#include "util/delay.h"

char LED[]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

void main (void) {
	char j;
  while (1)
 {
 	unsigned short i;
//	 char j;
	for (i=0;i<8;i++) {
		P0=LED[i];
		delay();
	}
 }
}
