//******************************************************************************
//  ���5�@�����񑀍�֐�����m�F�v���O����
//  ������A���삷�镶����A�W�����C�u�����֐��̎��s���ʁA����֐��̎��s����
//******************************************************************************
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "mystring.h"

// �������""�����ČŒ蒷�ŏo�� ----------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@string : �o�͕�����
//         length : �o�͌���
void  printFixedString(const char* string, int length)
{
	printf("\"%s\"%*s", string, length - strlen(string), "");
}

#ifdef ___TEST_STRLEN

// �u�������v�֐����� ----------------------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@targetString : �������𒲂ׂ镶����
void  testStrlen(const char* targetString)
{
	int		length, myLength;

	length = strlen(targetString);
	myLength = myStrlen(targetString);

	printFixedString(targetString, 6);
	printf(" : %d %d\n", length, myLength);
}

// �u�������v�֐��S�p�^�[������ ------------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@�Ȃ�
void  testAllStrlen(void)
{
	printf("strlen\n");
	testStrlen("abcde");
	testStrlen("a");
	testStrlen("");
}

#endif // ___TEST_STRLEN

#ifdef ___TEST_STRCPY

// �u�����񕡎ʁv�֐����� ------------------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@copyString   : ���ʂ��镶����
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

// �u�����񕡎ʁv�֐��S�p�^�[������ --------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@�Ȃ�
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

// �u������A���v�֐����� ------------------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@leftString   : �A���O������
//     �@�@rightString  : �A��������
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

// �u������A���v�֐��S�p�^�[������ --------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@�Ȃ�
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

// �u�������r�v�֐����� ------------------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@leftString   : ��r����镶����
//     �@�@rightString  : ��r���鎚��
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

// �u�������r�v�֐��S�p�^�[������ --------------------------------------------
// �߂�l�@�Ȃ�
// �����@�@�Ȃ�
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

// ���C���֐� ------------------------------------------------------------------
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