#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// �萔�錾
	// �N��
	typedef enum {
		MEIJI, TAISHOU, SHOUWA, HEISEI, REIWA, SEIREKI,
		NUM_NENGO, UNKNOWN_ERA,
	}  era_t;

	const char  eraStrings[NUM_NENGO][2 * 2 + 1] = {    // �N���̕�����
		"����", "�吳", "���a", "����", "�ߘa", "����",
	};
	const char  eraHeadChars[NUM_NENGO + 1] = "mtshrw";  // �N���̓�����

	const int  firstYears[NUM_NENGO] = {    // �e�N���̌��N�̐���N
	1868, 1912, 1926, 1989, 2019, 1,
	};

	// �ϐ��錾
	int i;
	char   eraInput;
	era_t  eraType;			// ���ʂ����N��
	char   eraChar;			// �������ϊ���̔N���̓�����
	int    year;			// ���͔N
	int	   westYear;		// ����ɏC�������N

	// ����
	printf("�a��𐼗�ɕϊ����܂��B\n");
	printf("�N���́A���̕�������͂��Ă��������B\n");
	for (i = 0; i < NUM_NENGO - 1; i++) {		// m�`r�܂ł͓����`�Ȃ̂ŌJ��Ԃ��ŕ\��
		printf("%c = %s, ", eraHeadChars[i], eraStrings[i]);
	}
	printf("%c = %s\n", eraHeadChars[i], eraStrings[i]);	// �`�̈Ⴄ5�����ʂŏ���
	printf("�N���Ƙa��̔N����͂��Ă��������B(��:����22�N h22) ");
	fflush(stdout);
	scanf("%c%d", &eraInput, &year);

	//�������ϊ�
	eraChar = eraInput + ('A' <= eraInput && eraInput <= 'Z' ? 'a' - 'A' : 0);

	// ���͂��ꂽ�����ŔN�����m�肳���� ���z��̓Y�����i�v�f�ԍ��j�̌���
	eraType = UNKNOWN_ERA;
	if (eraChar == eraHeadChars[0]) {
		eraType = (era_t)0;
	}
	if (eraChar == eraHeadChars[1]) {
		eraType = (era_t)1;
	}
	if (eraChar == eraHeadChars[2]) {
		eraType = (era_t)2;
	}
	if (eraChar == eraHeadChars[3]) {
		eraType = (era_t)3;
	}
	if (eraChar == eraHeadChars[4]) {
		eraType = (era_t)4;
	}
	if (eraChar == eraHeadChars[5]) {
		eraType = (era_t)5;
	}

	while (eraType == UNKNOWN_ERA) {
		printf("���͂��ꂽ '%c' �͔N���Ƃ��ĔF���ł��܂���B",eraInput);
		printf("������x�A�N���Ƙa��̔N����͂��Ă��������B(��:����22�N h22) ");
		fflush(stdout);
		scanf("%*[\r\n]");
		scanf("%c%d", &eraInput, &year);

		//�������ϊ�
		eraChar = eraInput + ('A' <= eraInput && eraInput <= 'Z' ? 'a' - 'A' : 0);

		// ���͂��ꂽ�����ŔN�����m�肳���� ���z��̓Y�����i�v�f�ԍ��j�̌���
		eraType = UNKNOWN_ERA;
		if (eraChar == eraHeadChars[0]) {
			eraType = (era_t)0;
		}
		if (eraChar == eraHeadChars[1]) {
			eraType = (era_t)1;
		}
		if (eraChar == eraHeadChars[2]) {
			eraType = (era_t)2;
		}
		if (eraChar == eraHeadChars[3]) {
			eraType = (era_t)3;
		}
		if (eraChar == eraHeadChars[4]) {
			eraType = (era_t)4;
		}
		if (eraChar == eraHeadChars[5]) {
			eraType = (era_t)5;
		}
	}

	// �v�Z  �a�����ϊ�
		westYear = year + firstYears[eraType] - 1;

	// �o��
		printf("%s %d�N�́A���� %d�N�ł��B\n", eraStrings[eraType], year, westYear);
	

	return 0;
}