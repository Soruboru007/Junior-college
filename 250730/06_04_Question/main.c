#include"figure.h"
#include<stdio.h>

//�}�`1�`��
void drow1() {
	char screen[MAX_SIZE][MAX_SIZE + 1];
	int size = 20;
	if (initialize(screen, 'a', size)) {
		drawTriangle(screen, 'b', size);
		printScreen(screen, size);
	}
}
//�}�`�Q�`��
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
//�}�`�R�`�� (for���𗘗p��size�ɕύX�������Ă��Ή����������j
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

	printf("�}�`�P\n");
	drow1();
	printf("�}�`�Q\n");
	drow2();
	printf("�}�`�R\n");
	drow3();
	printf("���܂�\n");
	drow4();
	return 0;
}