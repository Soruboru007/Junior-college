#include"figure.h"
#include<stdio.h>

//ê}å`1ï`âÊ
void drow1() {
	char screen[MAX_SIZE][MAX_SIZE + 1];

	initialize(screen, 'a', 20);
	drawTriangle(screen, 'b', 20);
	printScreen(screen, 20);
}
//ê}å`ÇQï`âÊ
void drow2() {

}
//ê}å`ÇRï`âÊ
void drow3() {

}


int main(void) {
	

	printf("ê}å`ÇP\n");
	drow1();

	//printf("ê}å`ÇQ\n");
	//drow2();
	//printf("ê}å`ÇR\n");
	//drow3();
	return 0;
}