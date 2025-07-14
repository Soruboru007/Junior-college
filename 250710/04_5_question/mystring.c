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
char* myStrcpy(char* dst, const char* src) {
	
	int i;
	for (i = 0; src[i]; i++) {
		//src配列からdst配列に1文字ずつ代入していく
		dst[i] = src[i];
	}
	//\0が含まれていないことに注意する
	dst[i] = '\0';
	return dst;
}

// 文字列複写 （ポインタ利用）--------------
// 戻り値　char * : 複写先
// 引数　　dst : コピー先
// 　　　　src : コピー元
char* myStrcpy2(char* dst, const char* src) {
	char* strArr;	//戻り値用文字列
	strArr = dst;
	while (*src) {
		*dst++ = *src++;
	}
	*dst = '\0';

	return strArr;
}

// 文字列連結 ------------------------------------------------------------------
// 戻り値　char * : 連結先
// 引数　　dst : 連結先
// 　　　　src : 連結元
char* myStrcat(char* dst, const char* src) {
	//dstの\0の位置（文字列の後ろ）にsrcをコピー
	myStrcpy(dst + myStrlen(dst), src);
	return dst;
}