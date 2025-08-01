#include"figure.h"
#include<stdio.h>

//図形1描画
void drow1() {
	char screen[MAX_SIZE][MAX_SIZE + 1];
	int size = 20;
	if (initialize(screen, 'a', size)) {
		drawTriangle(screen, 'b', size);
		printScreen(screen, size);
	}
}
//図形２描画
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
//図形３描画 (for文を利用しsizeに変更があっても対応させたい）
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

	printf("図形１\n");
	drow1();
	printf("図形２\n");
	drow2();
	printf("図形３\n");
	drow3();
	printf("おまけ\n");
	drow4();
	return 0;
}