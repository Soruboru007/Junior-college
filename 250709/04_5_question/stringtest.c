//******************************************************************************
//  問題5　文字列操作関数動作確認プログラム
//  左から、操作する文字列、標準ライブラリ関数の実行結果、自作関数の実行結果
//******************************************************************************
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "mystring.h"

// 文字列に""をつけて固定長で出力 ----------------------------------------------
// 戻り値　なし
// 引数　　string : 出力文字列
//         length : 出力桁数
void  printFixedString(const char* string, int length)
{
	printf("\"%s\"%*s", string, length - strlen(string), "");
}

#ifdef ___TEST_STRLEN

// 「文字数」関数検査 ----------------------------------------------------------
// 戻り値　なし
// 引数　　targetString : 文字数を調べる文字列
void  testStrlen(const char* targetString)
{
	int		length, myLength;

	length = strlen(targetString);
	myLength = myStrlen(targetString);

	printFixedString(targetString, 6);
	printf(" : %d %d\n", length, myLength);
}

// 「文字数」関数全パターン検査 ------------------------------------------------
// 戻り値　なし
// 引数　　なし
void  testAllStrlen(void)
{
	printf("strlen\n");
	testStrlen("abcde");
	testStrlen("a");
	testStrlen("");
}

#endif // ___TEST_STRLEN

#ifdef ___TEST_STRCPY

// 「文字列複写」関数検査 ------------------------------------------------------
// 戻り値　なし
// 引数　　copyString   : 複写する文字列
void  testStrcpy(const char* copyString)
{
	char 	  testString[100 + 1];
	char	myTestString[100 + 1];

	strcpy(testString, copyString);
	myStrcpy(myTestString, copyString);

	printFixedString(copyString, 6);
	printf(" : ");
	printFixedString(testString, 6);
	printFixedString(myTestString, 6);
	printf("\n");
}

// 「文字列複写」関数全パターン検査 --------------------------------------------
// 戻り値　なし
// 引数　　なし
void  testAllStrcpy(void)
{
	char 	testString[100 + 1];
	char* testDst;

	testDst = myStrcpy(testString, "abcde");

	printf("strcpy\n");
	printf("pointer : %p %p\n", testDst, testString);
	testStrcpy("abcde");
	testStrcpy("a");
	testStrcpy("");
}

#endif // ___TEST_STRCPY

#ifdef ___TEST_STRCAT

// 「文字列連結」関数検査 ------------------------------------------------------
// 戻り値　なし
// 引数　　leftString   : 連結前文字列
//     　　rightString  : 連結文字列
void  testStrcat(const char* leftString, const char* rightString)
{
	char 	  testString[100 + 1];
	char	myTestString[100 + 1];

	strcat(strcpy(testString, leftString), rightString);
	myStrcat(myStrcpy(myTestString, leftString), rightString);

	printFixedString(leftString, 6);
	printFixedString(rightString, 6);
	printf(" : ");
	printFixedString(testString, 10);
	printFixedString(myTestString, 10);
	printf("\n");
}

// 「文字列連結」関数全パターン検査 --------------------------------------------
// 戻り値　なし
// 引数　　なし
void  testAllStrcat(void)
{
	const char* test5String = "abcde";
	const char* test1String = "a";
	const char* test0String = "";

	char 	  testString[100 + 1];
	char* testDst;

	strcpy(testString, test5String);
	testDst = strcat(testString, test5String);

	printf("strcat\n");
	printf("pointer : %p %p\n", testDst, testString);
	testStrcat(test5String, test5String);
	testStrcat(test5String, test1String);
	testStrcat(test5String, test0String);
	testStrcat(test1String, test5String);
	testStrcat(test1String, test1String);
	testStrcat(test1String, test0String);
	testStrcat(test0String, test5String);
	testStrcat(test0String, test1String);
	testStrcat(test0String, test0String);
}

#endif // ___TEST_STRCAT

#ifdef ___TEST_STRCMP

// 「文字列比較」関数検査 ------------------------------------------------------
// 戻り値　なし
// 引数　　leftString   : 比較される文字列
//     　　rightString  : 比較する字列
void  testStrcmp(const char* leftString, const char* rightString)
{
	int		result, myResult;

	result = strcmp(leftString, rightString);
	myResult = myStrcmp(leftString, rightString);

	printFixedString(leftString, 6);
	printFixedString(rightString, 6);
	printf(" : ");
	printf("%4d %4d\n", result, myResult);
}

// 「文字列比較」関数全パターン検査 --------------------------------------------
// 戻り値　なし
// 引数　　なし
void  testAllStrcmp(void)
{
	printf("strcmp\n");
	testStrcmp("abcde", "abcdf");
	testStrcmp("abcde", "abcde");
	testStrcmp("abcdf", "abcde");
	testStrcmp("abcde", "abzde");
	testStrcmp("abzde", "abcde");
	testStrcmp("ybcde", "abcde");
	testStrcmp("abcde", "ybcde");
	testStrcmp("abcde", "abc");
	testStrcmp("abc", "abcde");
	testStrcmp("abcde", "a");
	testStrcmp("a", "abcde");
	testStrcmp("abcde", "z");
	testStrcmp("z", "abcde");
	testStrcmp("abcde", "");
	testStrcmp("", "abcde");
	testStrcmp("a", "");
	testStrcmp("a", "a");
	testStrcmp("a", "z");
	testStrcmp("z", "a");
	testStrcmp("", "a");
	testStrcmp("", "");
	testStrcmp("\x61\x30", "\x81\x80");
}

#endif // ___TEST_STRCMP

// メイン関数 ------------------------------------------------------------------
int  main(void)
{
#ifdef    ___TEST_STRLEN
	testAllStrlen();
#endif // ___TEST_STRLEN
#ifdef    ___TEST_STRCPY
	testAllStrcpy();
#endif // ___TEST_STRCPY
#ifdef    ___TEST_STRCAT
	testAllStrcat();
#endif // ___TEST_STRCAT
#ifdef    ___TEST_STRCMP
	testAllStrcmp();
#endif // ___TEST_STRCMP

	return  0;
}