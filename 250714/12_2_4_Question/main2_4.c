#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// �萔��`	
	// �ϐ���`
	int month;

	// ����
	printf("������͂��Ă��������B");
	fflush(stdout);
	scanf("%d", &month);

	while (!(1 <= month && month <= 12)) {
		printf("��������ł��B\n");
		printf("������x���͂��Ă��������B");
		fflush(stdout);
		scanf("%d", &month);
	}
	// �o��
	printf("%d ��", month);
	printf("���������ł��B\n");


	return 0;
}