#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 曜日型
typedef enum { SUN, MON, TUE, WED, THU, FRI, SAT } weekday_t;


//曜日を求める
//戻り値 weekday_t : 算出された曜日
//引数   year    : 曜日を求めたい年
// 　　  month   : 曜日を求めたい月
// 　　　day     : 曜日を求めたい日
weekday_t dayOfWeek(int year, int month, int day) {
	weekday_t week;
	int num;
	if (month >= 3) {
		month -= 2;
	}
	else {
		month += 10;
		year--;
	}
	num = year + year / 4 - year / 100 + year / 400 + (13 * month - 1) / 5 + day;
	week = (weekday_t)(num % 7);

	return week;
}

//メイン
int main(void) {
	// 定数宣言
	const char	strWeeks[][1 * 2 + 1] = { "日", "月", "火", "水", "木", "金", "土", };
	// 変数宣言
	int year, month, day;
	weekday_t week;

	// 入力
	printf("曜日を求めます。\n");
	printf("日付を入力してください。(年/月/日) ");
	fflush(stdout);
	scanf("%d/%d/%d", &year, &month, &day);

	// 計算
	week = dayOfWeek(year, month, day);
	// 出力
	printf("%d年%d月%d日は、%s曜日です。\n", year, month, day, strWeeks[week]);
	return 0;
}
