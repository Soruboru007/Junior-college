#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, length;
	char moji[20];
	char* pmoji;

	//����
	printf("10 �������x�̉p�����̕��������͂��Ă��������i�X�y�[�X�Ȃ��j\n");
	fflush(stdout);
	scanf("%s", moji);

	//�v�Z
	/* �|�C���^�ɕ�����̃A�h���X���� */
	pmoji = moji;

	/* �|�C���^�̈ʒu�𕶎���̖��[�Ɉړ�(����������)�����Q���Q�l�� */
	length = 0;
	while (*pmoji != '\0') {
		pmoji++;
		length++;  //�|�C���^�̈ړ��񐔁i�������j
	}

	//�o��
	/* ������\���i���[�� 1 �������珇�X�ɕ\������������j */
//length���p��
	for (i = 0; i < length; i++) {
		printf("%s\n", --pmoji);
	}

//�A�h���X��r��
	/* �|�C���^�ɕ�����̃A�h���X���� */
	pmoji = moji;

	while (*pmoji != '\0') {
		pmoji++;
	}
	
	while (moji != pmoji) {
		printf("%s\n", --pmoji);
	}

	return 0;
}