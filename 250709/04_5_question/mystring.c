//文字数
// 戻り値　int    : 引数で指定された文字列の文字数
// 引数　　string : 対象文字列
int  myStrlen(const char* string) {
	int i;		
	for (i = 0; string[i]; i++) {
	}
	return i;	//くり返しの回数が文字数となる
}

//文字列の複写
// 戻り値　char * : 複写先の先頭アドレス
// 引数　　dst    : コピー先
// 　　　　src    : コピー元
//char* myStrcpy(char* dst, const char* src) {
//	//src配列からdst配列に1文字ずつ代入していく
//
//	return dst;
//}

// 文字列複写 （ポインタ利用）--------------
// 戻り値　char * : 複写先
// 引数　　dst : コピー先
// 　　　　src : コピー元
//char* myStrcpy2(char* dst, const char* src) {
//	char* strArr;	//戻り値用文字列
//
//	return strArr;
//}