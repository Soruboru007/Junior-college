//������
// �߂�l�@int    : �����Ŏw�肳�ꂽ������̕�����
// �����@�@string : �Ώە�����
int  myStrlen(const char* string) {
	int i;		
	for (i = 0; string[i]; i++) {
	}
	return i;	//����Ԃ��̉񐔂��������ƂȂ�
}

//������̕���
// �߂�l�@char * : ���ʐ�̐擪�A�h���X
// �����@�@dst    : �R�s�[��
// �@�@�@�@src    : �R�s�[��
char* myStrcpy(char* dst, const char* src) {
	
	int i;
	for (i = 0; src[i]; i++) {
		//src�z�񂩂�dst�z���1������������Ă���
		dst[i] = src[i];
	}
	//\0���܂܂�Ă��Ȃ����Ƃɒ��ӂ���
	dst[i] = '\0';
	return dst;
}

// �����񕡎� �i�|�C���^���p�j--------------
// �߂�l�@char * : ���ʐ�
// �����@�@dst : �R�s�[��
// �@�@�@�@src : �R�s�[��
char* myStrcpy2(char* dst, const char* src) {
	char* strArr;	//�߂�l�p������
	strArr = dst;
	while (*src) {
		*dst++ = *src++;
	}
	*dst = '\0';

	return strArr;
}

// ������A�� ------------------------------------------------------------------
// �߂�l�@char * : �A����
// �����@�@dst : �A����
// �@�@�@�@src : �A����
char* myStrcat(char* dst, const char* src) {
	//dst��\0�̈ʒu�i������̌��j��src���R�s�[
	myStrcpy(dst + myStrlen(dst), src);
	return dst;
}