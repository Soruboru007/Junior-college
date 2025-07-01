#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// �萔��`
	// ��̎��
	typedef enum {
		UNKNOWN = -1,    // �s���Ȏ�
		STONE,           // ��
		SCISSORS,        // �͂���
		PAPER,           // ��
		NUM_HANDTYPE,    // ��̐�
	}  handType_t;

	// ���\�����͕���
	const char  inputChars[NUM_HANDTYPE + 1] = "gcp";
	// ���\��������
	const char  handStrings[NUM_HANDTYPE][3 * 2 + 1] = {
		"�O�[", "�`���L", "�p�[",
	};
	// ����̎��
	typedef enum {
		WIN,            // ����
		EVEN,           // ��������
		LOSE,           // ����
		NUM_JUDGETYPE,  // ����̎�ސ�
	}  judge_t;

	// ���茋�ʂ�\��������
	const char  judgeStrings[NUM_JUDGETYPE][6 * 2 + 1] = {
		"���Ȃ��̏���", "������", "���Ȃ��̕���",
	};

	// ���s�e�[�u��
	const judge_t  judgeTable[NUM_HANDTYPE][NUM_HANDTYPE] = {
		EVEN,WIN,LOSE,
		LOSE,EVEN,WIN,
		WIN,LOSE,EVEN,
	};

	// �ϐ���`
	int i;
	char inputCh, smallCh;			//���͒l�A���������������͒l
	handType_t myHand, otherHand;	//�����̎�Ƒ���̎�
	judge_t judge;					//���s��ۑ�

	// ����
	// �@�@�u����񂯂�𔻒肵�܂��B�v�ƃO�[�A�`���L�A�p�[�̓��͕�����\������B
	printf("����񂯂�𔻒肵�܂��B\n");
	for (i = 0; i < NUM_HANDTYPE; i++) {
		printf("%c : %s ", inputChars[i], handStrings[i]);
	}
	printf("\n");
	//�����̎����
	// �A�@���͂��󂯕t����B
	printf("�����̎����͂��Ă��������B(%s)", inputChars);
	fflush(stdout);
	scanf("%*[\r\n]");
	scanf("%c", &inputCh);
	// �B�@�啶�� �� �������ϊ�����B
	smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
	// �C�@��̔��ʂ��s���B�igcp �� STONE, SCISSORS, PAPER �ϊ�������B�j
	myHand = UNKNOWN;
	for (i = 0; i < NUM_HANDTYPE; i++) {
		if (inputChars[i] == smallCh) {
			myHand = (handType_t)i;
			break;
		}
	}
	// �D�@while(�肪���ʂł��Ȃ�) {
	while (myHand == UNKNOWN) {
		// �E�@�@�@�ē��͂𑣂��B
		printf("%c �����ʂł��܂���B\n", inputCh);
		printf("������x�����̎����͂��Ă��������B(%s) \n ", inputChars);
		// �F�@�@�@�A�`�C���s���B�i�R�[�h���̂��̂����̂܂܃R�s�[���Ă悢�B�j
		fflush(stdout);
		scanf("%*[\r\n]");
		scanf("%c", &inputCh);
		// �B�@�啶�� �� �������ϊ�����B
		smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
		// �C�@��̔��ʂ��s���B�igcp �� STONE, SCISSORS, PAPER �ϊ�������B�j
		myHand = UNKNOWN;
		for (i = 0; i < NUM_HANDTYPE; i++) {
			if (inputChars[i] == smallCh) {
				myHand = (handType_t)i;
				break;
			}
		}

	}

	//����̎����
	// �A�@���͂��󂯕t����B
	printf("����̎����͂��Ă��������B(%s)", inputChars);
	fflush(stdout);
	scanf("%*[\r\n]");
	scanf("%c", &inputCh);
	// �B�@�啶�� �� �������ϊ�����B
	smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
	// �C�@��̔��ʂ��s���B�igcp �� STONE, SCISSORS, PAPER �ϊ�������B�j
	otherHand = UNKNOWN;
	for (i = 0; i < NUM_HANDTYPE; i++) {
		if (inputChars[i] == smallCh) {
			otherHand = (handType_t)i;
			break;
		}
	}
	// �D�@while(�肪���ʂł��Ȃ�) {
	while (otherHand == UNKNOWN) {
		// �E�@�@�@�ē��͂𑣂��B
		printf("%c �����ʂł��܂���B\n", inputCh);
		printf("������x����̎����͂��Ă��������B(%s) \n", inputChars);
		// �F�@�@�@�A�`�C���s���B�i�R�[�h���̂��̂����̂܂܃R�s�[���Ă悢�B�j
		fflush(stdout);
		scanf("%*[\r\n]");
		scanf("%c", &inputCh);
		// �B�@�啶�� �� �������ϊ�����B
		smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
		// �C�@��̔��ʂ��s���B�igcp �� STONE, SCISSORS, PAPER �ϊ�������B�j
		otherHand = UNKNOWN;
		for (i = 0; i < NUM_HANDTYPE; i++) {
			if (inputChars[i] == smallCh) {
				otherHand = (handType_t)i;
				break;
			}
		}

	}

	// �v�Z
	judge = judgeTable[myHand][otherHand];

	// �o��
	printf("%s �� %s �� %s �ł��B\n", handStrings[myHand], handStrings[otherHand], judgeStrings[judge]);

	return 0;
}