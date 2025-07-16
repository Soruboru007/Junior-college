#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 定数定義 ------------------------------------------------------------
// 最大入力件数
enum { LIMIT_PRICES = 100 };
// 定数定義 -----------------------------------------------
const int  pointBorder = 200;    // 1ポイントを付加する単位金額

// ポイントを算出する。--------------------------------------
// 戻り値　int   : ポイント
// 引数　　price : ポイント対象価格
// ( 1 ) 戻り値の型　( 2 ) 引数 price の型
int  getPoint(int	price)
{
	int		point;             // ( 3 ) 戻り値となる変数 point の型

	point = price / pointBorder;     // ( 4 ) ポイントの計算

	return  point;
}


// 定数定義 --------------------------------------------------------
enum { COUNT_DISCOUNT = 4 };           		    // 割引の段階数
const int    discountBorders[COUNT_DISCOUNT] = {  // 割引の基準額
	10000, 5000, 3000, 1000,
};
const double  discountRates[COUNT_DISCOUNT] = {  // 割引率
	  0.3,  0.2,  0.1, 0.05,
};

// 税込価格の金額により割引額を算出する。-------------------------------
// 戻り値　???   : 値引額
// 引数    price : 値引前価格
// ( 1 ) 戻り値の型　( 2 ) 引数 price の型
int getDiscountPrice(int price)
{
	int	 discountPrice;    // ( 3 ) 戻り値となる変数 discountPrice の型
	int  i;

	discountPrice = 0;
	for (i = 0; i < COUNT_DISCOUNT; i++) {
		if (discountBorders[i] <= price) {  // ( 4 ) 値引率の境界を見つける
			discountPrice = (int)(price * discountRates[i]);	// ( 5 ) 値引率を掛ける
			break;
		}
	}
	return  discountPrice;
}

// 税込価格の金額により割引額及び割引後価格を算出する。--------------------
// 戻り値　なし
// 引数　　discountPrice : 割引額
// 　　　　totalPrice    : 割引後価格
// 　　　　price         : 割引前価格
// ( 1 ) discountPrice の型　( 2 ) totalPrice の型　( 3 ) price の型
void  getPayment(int* discountPrice, int* totalPrice, int	price)
{
	// ( 4 ) 割引額を決める。getDiscountPrice( ) 関数を呼び出す。
	*discountPrice = getDiscountPrice(price);
	// ( 5 ) 割引後価格を決める。割引前価格から割引額を引けばよい。
	*totalPrice = price - *discountPrice;
}

// 商品明細を出力する。-----------------------------------------------
// 戻り値　なし
// 引数　　prices : 商品価格
// 　　　　count  : 商品件数
// ( 1 ) prices の型　( 2 ) count の型
void  printPrices(const int* prices, int	count)
{
	int i;
	for (i = 0; i < count; i++) {// ( 3 ) 商品件数分出力する。
			// ( 4 ) 商品詳細を出力する。	
		printf("%4d 件目 : %7d 円\n", i + 1, prices[i]);
	}
}

// 商品明細から合計額を算出する。-------------------------------------
// 戻り値　???    : 合計金額
// 引数　　prices : 商品価格
// 　　　　count  : 入力件数
// ( 1 ) 戻り値の型　( 2 ) prices の型　( 3 ) count の型
int getTotalPrice(const int* prices, int	count)
{
	int  totalPrice;
	int  i;

	totalPrice = 0;
	for (i = 0; i < count; i++) {
		totalPrice += prices[i];  // ( 4 ) 商品明細の足し算
	}
	return		totalPrice;  // ( 5 ) 合計金額
}

// 商品明細を入力する。-----------------------------------------------
// 戻り値　???    : 入力件数
// 引数　　prices : 商品価格( 配列 )
// 　　　　limit  : 最大入力可能数
// ( 1 ) 戻り値の型　( 2 ) prices の型　( 3 ) limit の型
int inputPrices(int* prices, int	limit) {
	int  count;
	int  price;
	int  i;

	printf("商品の金額を順に入力してください。\n");
	// ( 4 ) 最大入力可能件数を入力者に知らせる。
	printf("0 円以下を入力するか、%d 件入力すると終了します。\n", limit);
	count = 0;

	for (i = 0; i < limit; i++) {
		printf("==> ");
		fflush(stdout);
		scanf("%d", &price);
		if (price <= 0) {
			break;
		}

		// ( 5 ) 入力額を配列に格納する。

		prices[count++] = price;
	}

	return count;
}
// getPoint( ) 関数の動作確認をする。 -----------------------
void  testGetPoint(int price)
{
	int  point;
	point = getPoint(price);
	printf("%6d 円のポイントは %4d\n", price, point);
}

// getDiscountPrice( ) 関数の動作確認をする。 -----------------------
void testGetDiscountPrice(int price) {
	int discountPrice;
	discountPrice = getDiscountPrice(price);
	printf("%6d 円の割引額は %4d\n", price, discountPrice);

}

// getPayment() 関数の動作確認をする。 -----------------------
void testGetPayment(int price) {
	int discountPrice, totalPrice;
	getPayment(&discountPrice, &totalPrice, price);
	printf("%6d 円の割引額は     %4d\n", price, discountPrice);
	printf("%6d 円の割引後価格は %4d\n", price, totalPrice);
}

// printPrices() 関数の動作確認をする。 -----------------------
void testPrintPrices() {
	int prices[] = { 0,10,100,1000,3000,5000,10000 };
	int count = sizeof(prices) / sizeof(prices[0]);
	printPrices(prices, count);
}

// getTotalPrice() 関数の動作確認をする。 -----------------------
void testGetTotalPrice() {
	int prices[] = { 0,10,100,1000,3000,5000,10000 };
	int count = sizeof(prices) / sizeof(prices[0]);
	int totalPrice = getTotalPrice(prices, count);

	printf("合計金額は     %7d\n", totalPrice);
}

// inputPrices() 関数の動作確認をする。 -----------------------
void testInpurPrices() {
	int  prices[LIMIT_PRICES];    // 商品明細
	int  count;                     // 商品件数


}


// メイン関数 ----------------------------------------------------------
int main(void)
{
	// 変数宣言
	int  prices[LIMIT_PRICES];    // 商品明細
	int  count;                     // 商品件数
	int  totalPrice;                // 商品合計額
	int  discountPrice;             // 割引額
	int  payment;                   // 支払総額
	int  point;                     // ポイント

	// タイトル出力
	printf("商品入力レジです。\n");
	// 商品詳細入力
	count = inputPrices(prices, LIMIT_PRICES);

	// 商品合計額算出
	totalPrice = getTotalPrice(prices, count);
	// 値引額算出
	getPayment(&discountPrice, &payment, totalPrice);
	// ポイント算出
	point = getPoint(payment);
	// 商品詳細出力
	printPrices(prices, count);
	if (0 < discountPrice) {
		printf("合計金額 %10d 円\n", totalPrice);		// 合計金額出力
		printf("割引額   %10d 円\n", discountPrice);	// 割引額出力
	}
	printf("支払総額 %10d 円\n", payment);				// 支払総額出力
	printf("ポイント %10d 点\n", point);				// ポイント出力

	return  0;
}