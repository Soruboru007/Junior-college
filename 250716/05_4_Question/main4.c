#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 型定義 --------------------------------------------------------------- 
// 体型 
typedef enum {
	THIN, STANDARD, FAT, SUPER_FAT,
	NUM_BODYTYPES,                   // 体型の種類数 
	NUM_BORDERS = NUM_BODYTYPES - 1, // 体型の境界値の個数 
}  bodyType_t;

// 定数定義 ------------------------------------------------------------- 
// 体型を判断する BMI の境界値 
const double  bodyTypeBorders[NUM_BORDERS] = {
	18.5, // やせ 
	25.0, // 標準 
	30.0, // 肥満 
};

// 体型を表す文字列 
const char* bodyTypeStrings[NUM_BODYTYPES] = {
	"やせ",
	"標準",
	"肥満",
	"高度肥満",
};

// cm → m 単位変換値 
const double  cmeter2meter = 100;

// 入力値の制限値 
const int  maxHeight = 300;	// 最高 272.3cm 
const int  minHeight = 50;	// 生後3ヶ月で女子 57.1 ～ 65.7cm 
const int  maxWeight = 600;	// 最高 560kg 
const int  minWeight = 5;	// 生後3ヶ月で女子 5.1 ～ 7.7kg 

// 値の入力	---------------------------------------------------------------  
// 戻り値　int    : 入力された値  
// 引数　　prompt : 入力促進文字列  
// 　　 　 min    : 入力可能最小値  
// 　　 　 max    : 入力可能最大値  
int  inputValue(const char* prompt, int    min, int    max)
{
	int  value;
	printf("%s( %d - %d ) ", prompt, min, max);
	fflush(stdout);
	scanf("%d", &value);
	while (!(min <= value && value <= max)) {
		printf("入力値 %d は範囲外です。\n", value);
		printf("もう一度、");
		printf("%s( %d - %d ) ", prompt, min, max);
		fflush(stdout);
		scanf("%d", &value);
	}
	return  value;
}

// BMI算出　　体重/身長(m単位）の2乗
double getBMI(int height, int weight) {
	double bmi;
	double heightM;
	heightM = (double)height / cmeter2meter;
	bmi = weight / heightM / heightM;  // weight / (heightM*heightM) or weight / pow(heightM,2)
	return bmi;
}

// 体型判定 　 bodyType_tを返す。
bodyType_t getBodyType(double bmi) {
	bodyType_t type =SUPER_FAT; //ループの中で体型が見つからなければ高度肥満になるため初期値とする
	int i;
	for (i = 0; i < NUM_BORDERS; i++) {
		if (bmi < bodyTypeBorders[i]) {
			type = (bodyType_t)i;
			break; //typeが定まったらループから抜ける（入れないと肥満に設定されてしまう）
		}
	}
	return type;
}

// メイン関数 ----------------------------------------------------------- 
int  main(void)
{
	// 変数定義 
	int         height, weight;	// 身長、体重 
	double      bmi;		// BMI値 
	bodyType_t  bodyType;		// 体型 

	// 入力 
	printf("あなたのBMI値を求めます。\n");
	// 身長入力 
	height = inputValue("身長を入力してください。[単位:cm] ", minHeight, maxHeight);
	// 体重入力 
	weight = inputValue("体重を入力してください。[単位:kg]", minWeight, maxWeight);

	// 計算 
	// BMI算出
	bmi = getBMI(height, weight);
	// 体型判定 
	bodyType = getBodyType(bmi);
	// 出力 
	// 判定結果出力 
	printf("身長 %dcm 体重 %dkg の方のBMIは %.2f、%s体型です。\n",
		height, weight, bmi, bodyTypeStrings[bodyType]);


	return  0;
}