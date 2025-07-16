#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// �萔��` ------------------------------------------------------------
// �ő���͌���
enum { LIMIT_PRICES = 100 };
// �萔��` -----------------------------------------------
const int  pointBorder = 200;    // 1�|�C���g��t������P�ʋ��z

// �|�C���g���Z�o����B--------------------------------------
// �߂�l�@int   : �|�C���g
// �����@�@price : �|�C���g�Ώۉ��i
// ( 1 ) �߂�l�̌^�@( 2 ) ���� price �̌^
int  getPoint(int	price)
{
	int		point;             // ( 3 ) �߂�l�ƂȂ�ϐ� point �̌^

	point = price / pointBorder;     // ( 4 ) �|�C���g�̌v�Z

	return  point;
}


// �萔��` --------------------------------------------------------
enum { COUNT_DISCOUNT = 4 };           		    // �����̒i�K��
const int    discountBorders[COUNT_DISCOUNT] = {  // �����̊�z
	10000, 5000, 3000, 1000,
};
const double  discountRates[COUNT_DISCOUNT] = {  // ������
	  0.3,  0.2,  0.1, 0.05,
};

// �ō����i�̋��z�ɂ�芄���z���Z�o����B-------------------------------
// �߂�l�@???   : �l���z
// ����    price : �l���O���i
// ( 1 ) �߂�l�̌^�@( 2 ) ���� price �̌^
int getDiscountPrice(int price)
{
	int	 discountPrice;    // ( 3 ) �߂�l�ƂȂ�ϐ� discountPrice �̌^
	int  i;

	discountPrice = 0;
	for (i = 0; i < COUNT_DISCOUNT; i++) {
		if (discountBorders[i] <= price) {  // ( 4 ) �l�����̋��E��������
			discountPrice = (int)(price * discountRates[i]);	// ( 5 ) �l�������|����
			break;
		}
	}
	return  discountPrice;
}

// �ō����i�̋��z�ɂ�芄���z�y�ъ����㉿�i���Z�o����B--------------------
// �߂�l�@�Ȃ�
// �����@�@discountPrice : �����z
// �@�@�@�@totalPrice    : �����㉿�i
// �@�@�@�@price         : �����O���i
// ( 1 ) discountPrice �̌^�@( 2 ) totalPrice �̌^�@( 3 ) price �̌^
void  getPayment(int* discountPrice, int* totalPrice, int	price)
{
	// ( 4 ) �����z�����߂�BgetDiscountPrice( ) �֐����Ăяo���B
	*discountPrice = getDiscountPrice(price);
	// ( 5 ) �����㉿�i�����߂�B�����O���i���犄���z�������΂悢�B
	*totalPrice = price - *discountPrice;
}

// ���i���ׂ��o�͂���B-----------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@prices : ���i���i
// �@�@�@�@count  : ���i����
// ( 1 ) prices �̌^�@( 2 ) count �̌^
void  printPrices(const int* prices, int	count)
{
	int i;
	for (i = 0; i < count; i++) {// ( 3 ) ���i�������o�͂���B
			// ( 4 ) ���i�ڍׂ��o�͂���B	
		printf("%4d ���� : %7d �~\n", i + 1, prices[i]);
	}
}

// ���i���ׂ��獇�v�z���Z�o����B-------------------------------------
// �߂�l�@???    : ���v���z
// �����@�@prices : ���i���i
// �@�@�@�@count  : ���͌���
// ( 1 ) �߂�l�̌^�@( 2 ) prices �̌^�@( 3 ) count �̌^
int getTotalPrice(const int* prices, int	count)
{
	int  totalPrice;
	int  i;

	totalPrice = 0;
	for (i = 0; i < count; i++) {
		totalPrice += prices[i];  // ( 4 ) ���i���ׂ̑����Z
	}
	return		totalPrice;  // ( 5 ) ���v���z
}

// ���i���ׂ���͂���B-----------------------------------------------
// �߂�l�@???    : ���͌���
// �����@�@prices : ���i���i( �z�� )
// �@�@�@�@limit  : �ő���͉\��
// ( 1 ) �߂�l�̌^�@( 2 ) prices �̌^�@( 3 ) limit �̌^
int inputPrices(int* prices, int	limit) {
	int  count;
	int  price;
	int  i;

	printf("���i�̋��z�����ɓ��͂��Ă��������B\n");
	// ( 4 ) �ő���͉\��������͎҂ɒm�点��B
	printf("0 �~�ȉ�����͂��邩�A%d �����͂���ƏI�����܂��B\n", limit);
	count = 0;

	for (i = 0; i < limit; i++) {
		printf("==> ");
		fflush(stdout);
		scanf("%d", &price);
		if (price <= 0) {
			break;
		}

		// ( 5 ) ���͊z��z��Ɋi�[����B

		prices[count++] = price;
	}

	return count;
}
// getPoint( ) �֐��̓���m�F������B -----------------------
void  testGetPoint(int price)
{
	int  point;
	point = getPoint(price);
	printf("%6d �~�̃|�C���g�� %4d\n", price, point);
}

// getDiscountPrice( ) �֐��̓���m�F������B -----------------------
void testGetDiscountPrice(int price) {
	int discountPrice;
	discountPrice = getDiscountPrice(price);
	printf("%6d �~�̊����z�� %4d\n", price, discountPrice);

}

// getPayment() �֐��̓���m�F������B -----------------------
void testGetPayment(int price) {
	int discountPrice, totalPrice;
	getPayment(&discountPrice, &totalPrice, price);
	printf("%6d �~�̊����z��     %4d\n", price, discountPrice);
	printf("%6d �~�̊����㉿�i�� %4d\n", price, totalPrice);
}

// printPrices() �֐��̓���m�F������B -----------------------
void testPrintPrices() {
	int prices[] = { 0,10,100,1000,3000,5000,10000 };
	int count = sizeof(prices) / sizeof(prices[0]);
	printPrices(prices, count);
}

// getTotalPrice() �֐��̓���m�F������B -----------------------
void testGetTotalPrice() {
	int prices[] = { 0,10,100,1000,3000,5000,10000 };
	int count = sizeof(prices) / sizeof(prices[0]);
	int totalPrice = getTotalPrice(prices, count);

	printf("���v���z��     %7d\n", totalPrice);
}

// inputPrices() �֐��̓���m�F������B -----------------------
void testInpurPrices() {
	int  prices[LIMIT_PRICES];    // ���i����
	int  count;                     // ���i����


}


// ���C���֐� ----------------------------------------------------------
int main(void)
{
	// �ϐ��錾
	int  prices[LIMIT_PRICES];    // ���i����
	int  count;                     // ���i����
	int  totalPrice;                // ���i���v�z
	int  discountPrice;             // �����z
	int  payment;                   // �x�����z
	int  point;                     // �|�C���g

	// �^�C�g���o��
	printf("���i���̓��W�ł��B\n");
	// ���i�ڍד���
	count = inputPrices(prices, LIMIT_PRICES);

	// ���i���v�z�Z�o
	totalPrice = getTotalPrice(prices, count);
	// �l���z�Z�o
	getPayment(&discountPrice, &payment, totalPrice);
	// �|�C���g�Z�o
	point = getPoint(payment);
	// ���i�ڍ׏o��
	printPrices(prices, count);
	if (0 < discountPrice) {
		printf("���v���z %10d �~\n", totalPrice);		// ���v���z�o��
		printf("�����z   %10d �~\n", discountPrice);	// �����z�o��
	}
	printf("�x�����z %10d �~\n", payment);				// �x�����z�o��
	printf("�|�C���g %10d �_\n", point);				// �|�C���g�o��

	return  0;
}