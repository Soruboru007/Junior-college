#include"figure.h"
#include<stdio.h>

// ��ʂ����������� ----------------------------------------------------- 
// �߂�l�@bool_t : �w�肳�ꂽ�傫�����X�N���[���Ɏ��܂��Ă���ꍇ�� TRUE�A 
//�����Ă���� FALSE 
// �����@�@screen : �X�N���[�� 
// �@�@�@�@fillChar : ���߂镶�� 
// �@�@�@�@size : �傫�� 
bool_t initialize(char(*screen)[MAX_SIZE + 1], char fillChar, int size) {
	int i, j;
	bool_t result=FALSE;

	if (0 <= size && size <= MAX_SIZE) { //�w�肳�ꂽsize���O�`�S�O�̎�����������
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				screen[i][j] = fillChar;
			}
			screen[i][j] = '\0';
		}
		result = TRUE;
	}

	return result;
}

//��ʂ�`�悷��(�Q�����z����w�肳�ꂽ�s�����o�͂���j
// �߂�l  �Ȃ�
// �����@�@screen : �X�N���[�� 
// �@�@�@�@size : �傫�� 
void  printScreen(const char(*screen)[MAX_SIZE + 1], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s\n", screen[i]);
	}
}

// �~��`�� ------------------------------------------------------------ 
// �߂�l�@�Ȃ� 
// �����@�@screen : �X�N���[��
// �@�@�@�@drawChar : �`������
// �@�@�@�@size : �傫��
void drawEx(char(*screen)[MAX_SIZE + 1], char drawChar, int size) {
	int i;
	int c;
	c = size;
	for (i = 0; i < size; i++) {
		screen[i][i] = drawChar;
		screen[i][--c] = drawChar;
	}

}

//���p�O�p�`��`��
// �߂�l�@�Ȃ� 
// �����@�@screen : �X�N���[��
// �@�@�@�@drawChar : �`������
// �@�@�@�@size : �傫��
void drawTriangle(char(*screen)[MAX_SIZE + 1], char drawChar, int size) {
	int i, j;
	int c;
	for (i = 0; i < size; i++) {
		c = size;
		for (j = 0; j < (i + 1); j++) {
			screen[i][--c] = drawChar;
		}
	}
}

// �g��`���@ ----------------------------------------------------------- 
// �߂�l�@bool_t : �w�肳�ꂽ�J�n�ʒu���X�N���[���Ɏ��܂��Ă���ꍇ�� TRUE�A 
//�����Ă���� FALSE 
// �����@�@screen : �X�N���[�� 
// �@�@�@�@drawChar : �`������ 
// �@�@�@�@size : �傫�� 
// �@�@�@�@start : �J�n�ʒu  
bool_t drawFrame1(char(*screen)[MAX_SIZE + 1], char drawChar, int size, int start) {

}

// �g��`���A ----------------------------------------------------------- 
// �߂�l�@bool_t   : �J�n�ʒu �� �I���ʒu�Ȃ� TRUE�A�����łȂ���� FALSE 
// �����@�@screen   : �X�N���[�� 
// �@�@�@�@drawChar : �`������ 
// �@�@�@�@start    : �J�n�ʒu  
// �@�@�@�@end      : �I���ʒu 
bool_t  drawFrame2(char(*screen)[MAX_SIZE + 1], char drawChar, int start, int end) {

}
