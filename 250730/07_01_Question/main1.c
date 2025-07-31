#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	//�^��`
	typedef enum { BILL, COIN, TYPE_COUNT, }  denom_t;    // �ʉ݂̎��

	//�萔��`
	const int	denoms[] = {								// �ʉݒP��
		10000, 5000, 2000, 1000, 500,  100,  50, 10,  5,  1,
	};
	enum {DENOM_COUNT=sizeof(denoms)/sizeof(denoms[0]) };	//�ʉ݂̎�ސ�

	denom_t denomTypes[DENOM_COUNT] = {
	 BILL, BILL, BILL, BILL, COIN, COIN, COIN, COIN, COIN, COIN, };//��ށi�D�A�ʁj     �z�� �y�񋓌^�萔�z
	
	const char* denomStr[TYPE_COUNT] = { "�D","��" };//"�D"�A"��" �̕�����    �y�����^�|�C���^�萔�z

	//�ϐ���`
	int counts[DENOM_COUNT];//���� �z��
	int price;
	int remain;
	int i;

	//����
	printf("����v�Z�����܂��B\n");
	printf("���z����͂��Ă��������B ");
	fflush(stdout);
	scanf("%d", &price);

	//�v�Z
	remain = price;
	for (i = 0; i < DENOM_COUNT; i++) {
		counts[i] = remain / denoms[i];
		remain = remain % denoms[i];
	}

	//�o��
	printf("���z %8d�~\n", price);
	for (i = 0; i < DENOM_COUNT; i++) {
		if (0 < counts[i]) {
			printf("%-5d�~%s %2d��\n", denoms[i], denomStr[denomTypes[i]], counts[i]);
		}
	}
	return 0;
}