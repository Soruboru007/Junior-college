#include"figure.h"
#include<stdio.h>

//ê}å`1ï`âÊ
void drow1() {
	char screen[MAX_SIZE][MAX_SIZE + 1];
	int size = 20;
	if (initialize(screen, 'a', size)) {
		drawTriangle(screen, 'b', size);
		printScreen(screen, size);
	}
}
//ê}å`ÇQï`âÊ
void drow2() {
	char screen[MAX_SIZE][MAX_SIZE + 1];
	int size = 20;
	char drawCh = '@';
	if (initialize(screen, ' ', size)) {
		drawEx(screen,drawCh, size);
		drawFrame1(screen,drawCh, size,0);
		printScreen(screen, size);
	}
}
//ê}å`ÇRï`âÊ (forï∂ÇóòópÇµsizeÇ…ïœçXÇ™Ç†Ç¡ÇƒÇ‡ëŒâûÇ≥ÇπÇΩÇ¢Åj
void drow3() {
	char screen[MAX_SIZE][MAX_SIZE + 1];
	int size =20;
	char drawCh = '0';
	int i;
	if (initialize(screen, ' ', size)) {
		for (i = 0; drawFrame1(screen, drawCh, size, i); i += 2) {
		}
		printScreen(screen, size);
	}
}

void drow4() {
	char screen[MAX_SIZE][MAX_SIZE + 1];
	int size = 20;
	char drawCh = '0';
	if (initialize(screen, ' ', size)) {
		int start = 0;
		int end = size-1;
		while (drawFrame2(screen, drawCh, start, end)) {
			start += 2;
			end -= 2;
		}
		
		printScreen(screen, size);
	}
}



int main(void) {

	printf("ê}å`ÇP\n");
	drow1();
	printf("ê}å`ÇQ\n");
	drow2();
	printf("ê}å`ÇR\n");
	drow3();
	printf("Ç®Ç‹ÇØ\n");
	drow4();
	return 0;
}