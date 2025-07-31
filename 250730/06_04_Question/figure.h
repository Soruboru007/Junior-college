#pragma once
// �^��` ------------------------------------------------------------- 
typedef enum { FALSE, TRUE, }bool_t;
// �_���^ 

// �萔��` ----------------------------------------------------------- 
enum { MAX_SIZE = 40 };// �c���̍ő�l 

// ��ʂ����������� ----------------------------------------------------- 
// �߂�l�@bool_t : �w�肳�ꂽ�傫�����X�N���[���Ɏ��܂��Ă���ꍇ�� TRUE�A 
//�����Ă���� FALSE 
// �����@�@screen : �X�N���[�� 
// �@�@�@�@fillChar : ���߂镶�� 
// �@�@�@�@size : �傫�� 
bool_t initialize(char(*screen)[MAX_SIZE + 1], char fillChar, int size);

//��ʂ�`�悷��(�Q�����z����w�肳�ꂽ�s�����o�͂���j
// �߂�l  �Ȃ�
// �����@�@screen : �X�N���[�� 
// �@�@�@�@size : �傫�� 
void  printScreen(const char(*screen)[MAX_SIZE + 1], int size);

// �~��`�� ------------------------------------------------------------ 
// �߂�l�@�Ȃ� 
// �����@�@screen : �X�N���[��
// �@�@�@�@drawChar : �`������
// �@�@�@�@size : �傫��
void drawEx(char(*screen)[MAX_SIZE + 1], char drawChar, int size);

//���p�O�p�`��`��
// �߂�l�@�Ȃ� 
// �����@�@screen : �X�N���[��
// �@�@�@�@drawChar : �`������
// �@�@�@�@size : �傫��
void drawTriangle(char(*screen)[MAX_SIZE + 1], char drawChar, int size);


// �g��`���@ ----------------------------------------------------------- 
// �߂�l�@bool_t : �w�肳�ꂽ�J�n�ʒu���X�N���[���Ɏ��܂��Ă���ꍇ�� TRUE�A 
//�����Ă���� FALSE 
// �����@�@screen : �X�N���[�� 
// �@�@�@�@drawChar : �`������ 
// �@�@�@�@size : �傫�� 
// �@�@�@�@start : �J�n�ʒu  
bool_t drawFrame1(char(*screen)[MAX_SIZE + 1], char drawChar,int size, int start);

// �g��`���A ----------------------------------------------------------- 
// �߂�l�@bool_t   : �J�n�ʒu �� �I���ʒu�Ȃ� TRUE�A�����łȂ���� FALSE 
// �����@�@screen   : �X�N���[�� 
// �@�@�@�@drawChar : �`������ 
// �@�@�@�@start    : �J�n�ʒu  
// �@�@�@�@end      : �I���ʒu 
bool_t  drawFrame2(char(*screen)[MAX_SIZE + 1], char drawChar,   int start, int end);