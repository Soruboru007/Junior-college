#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// �萔�錾
	enum { NUM_NENGO = 6 };
	const char  eraStrings[NUM_NENGO][2 * 2 + 1] = {    // �N���̕�����
		"����", "�吳", "���a", "����", "�ߘa", "����",
	};

	// �ϐ��錾
	int i;
	int era;

	// ����
	printf("�N������͂��Ă��������B\n");
	for (i = 0; i < NUM_NENGO - 1; i++) {		// 0�`4�܂ł͓����`�Ȃ̂ŌJ��Ԃ��ŕ\��
		printf("%d = %s, ", i, eraStrings[i]);
	}
	printf("%d = %s ==>", i, eraStrings[i]);	// �`�̈Ⴄ5�����ʂŏ���
	fflush(stdout);
	scanf("%d", &era);

	// �o��
	printf("���͂��ꂽ�N����%s�ł��B\n", eraStrings[era]);


	return 0;
}