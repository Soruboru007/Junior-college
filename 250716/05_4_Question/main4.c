#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// �^��` --------------------------------------------------------------- 
// �̌^ 
typedef enum {
	THIN, STANDARD, FAT, SUPER_FAT,
	NUM_BODYTYPES,                   // �̌^�̎�ސ� 
	NUM_BORDERS = NUM_BODYTYPES - 1, // �̌^�̋��E�l�̌� 
}  bodyType_t;

// �萔��` ------------------------------------------------------------- 
// �̌^�𔻒f���� BMI �̋��E�l 
const double  bodyTypeBorders[NUM_BORDERS] = {
	18.5, // �₹ 
	25.0, // �W�� 
	30.0, // �얞 
};

// �̌^��\�������� 
const char* bodyTypeStrings[NUM_BODYTYPES] = {
	"�₹",
	"�W��",
	"�얞",
	"���x�얞",
};

// cm �� m �P�ʕϊ��l 
const double  cmeter2meter = 100;

// ���͒l�̐����l 
const int  maxHeight = 300;	// �ō� 272.3cm 
const int  minHeight = 50;	// ����3�����ŏ��q 57.1 �` 65.7cm 
const int  maxWeight = 600;	// �ō� 560kg 
const int  minWeight = 5;	// ����3�����ŏ��q 5.1 �` 7.7kg 

// �l�̓���	---------------------------------------------------------------  
// �߂�l�@int    : ���͂��ꂽ�l  
// �����@�@prompt : ���͑��i������  
// �@�@ �@ min    : ���͉\�ŏ��l  
// �@�@ �@ max    : ���͉\�ő�l  
int  inputValue(const char* prompt, int    min, int    max)
{
	int  value;
	printf("%s( %d - %d ) ", prompt, min, max);
	fflush(stdout);
	scanf("%d", &value);
	while (!(min <= value && value <= max)) {
		printf("���͒l %d �͔͈͊O�ł��B\n", value);
		printf("������x�A");
		printf("%s( %d - %d ) ", prompt, min, max);
		fflush(stdout);
		scanf("%d", &value);
	}
	return  value;
}

// BMI�Z�o�@�@�̏d/�g��(m�P�ʁj��2��
double getBMI(int height, int weight) {
	double bmi;
	double heightM;
	heightM = (double)height / cmeter2meter;
	bmi = weight / heightM / heightM;  // weight / (heightM*heightM) or weight / pow(heightM,2)
	return bmi;
}

// �̌^���� �@ bodyType_t��Ԃ��B
bodyType_t getBodyType(double bmi) {
	bodyType_t type =SUPER_FAT; //���[�v�̒��ő̌^��������Ȃ���΍��x�얞�ɂȂ邽�ߏ����l�Ƃ���
	int i;
	for (i = 0; i < NUM_BORDERS; i++) {
		if (bmi < bodyTypeBorders[i]) {
			type = (bodyType_t)i;
			break; //type����܂����烋�[�v���甲����i����Ȃ��Ɣ얞�ɐݒ肳��Ă��܂��j
		}
	}
	return type;
}

// ���C���֐� ----------------------------------------------------------- 
int  main(void)
{
	// �ϐ���` 
	int         height, weight;	// �g���A�̏d 
	double      bmi;		// BMI�l 
	bodyType_t  bodyType;		// �̌^ 

	// ���� 
	printf("���Ȃ���BMI�l�����߂܂��B\n");
	// �g������ 
	height = inputValue("�g������͂��Ă��������B[�P��:cm] ", minHeight, maxHeight);
	// �̏d���� 
	weight = inputValue("�̏d����͂��Ă��������B[�P��:kg]", minWeight, maxWeight);

	// �v�Z 
	// BMI�Z�o
	bmi = getBMI(height, weight);
	// �̌^���� 
	bodyType = getBodyType(bmi);
	// �o�� 
	// ���茋�ʏo�� 
	printf("�g�� %dcm �̏d %dkg �̕���BMI�� %.2f�A%s�̌^�ł��B\n",
		height, weight, bmi, bodyTypeStrings[bodyType]);


	return  0;
}