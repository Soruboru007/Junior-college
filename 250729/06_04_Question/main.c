#include"figure.h"
#include<stdio.h>

//�}�`1�`��
void drow1() {
	char screen[MAX_SIZE][MAX_SIZE + 1];

	initialize(screen, 'a', 20);
	drawTriangle(screen, 'b', 20);
	printScreen(screen, 20);
}
//�}�`�Q�`��
void drow2() {

}
//�}�`�R�`��
void drow3() {

}


int main(void) {
	

	printf("�}�`�P\n");
	drow1();

	//printf("�}�`�Q\n");
	//drow2();
	//printf("�}�`�R\n");
	//drow3();
	return 0;
}