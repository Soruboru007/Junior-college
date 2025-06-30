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

	// �ϐ��錾
	int i;
	char   eraInput;
	era_t  eraType;   // ���ʂ����N��
	char   eraChar;   // �������ϊ���̔N���̓�����

	// ����
	printf("�N������͂��Ă��������B\n");
	for (i = 0; i < NUM_NENGO - 1; i++) {		// m�`r�܂ł͓����`�Ȃ̂ŌJ��Ԃ��ŕ\��
		printf("%c = %s, ", eraHeadChars[i], eraStrings[i]);
	}
	printf("%c = %s ==>", eraHeadChars[i], eraStrings[i]);	// �`�̈Ⴄ5�����ʂŏ���
	fflush(stdout);
	scanf("%c", &eraInput);

	//�������ϊ�
	eraChar = eraInput + ('A' <= eraInput && eraInput <= 'Z' ? 'a' - 'A' : 0);

	// ���͂��ꂽ�����ŔN�����m�肳����
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

	// �o��
	printf("���͂��ꂽ");
	if (eraType != UNKNOWN_ERA) {
		printf("�N����%s�ł��B\n", eraStrings[eraType]);
	}
	else {
		printf("����'%c'�͎��ʕs�\�ł��B\n",eraInput);
	}

	return 0;
}