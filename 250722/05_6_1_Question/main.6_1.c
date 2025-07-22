#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// �^��` -------------------------------------------------------------------
typedef enum { WIN, EVEN, LOSE, NUM_JUDGES, }        judge_t;  // ���茋��
typedef enum { STONE, SCISSORS, PAPER, NUM_HANDS, }  hand_t;   // ��

// �萔��` -----------------------------------------------------------------
const char* chHands = "gcp";                        // ���͕��� �O�[,�`���L,�p�[
const char* handStrings[NUM_HANDS] = {             // �\��������
    "�O�[", "�`���L", "�p�[",
};
const judge_t judgeTable[NUM_HANDS][NUM_HANDS] = { // ���s�\
    EVEN, WIN, LOSE,
    LOSE, EVEN, WIN,
    WIN, LOSE, EVEN,
};
const char* judgeStrings[NUM_JUDGES] = {           // ���s�\��������
    "���Ȃ��̏���",
    "��������",
    "���Ȃ��̕���",
};

//�v�����v�g���b�Z�[�W�̕\��
//�߂�l�E�@�����@�Ȃ�
void promptMessage() {
    int i;
    printf("����񂯂�𔻒肵�܂��B\n");
    for (i = 0; i < NUM_HANDS; i++) {
        printf("%c : %s  ", chHands[i], handStrings[i]);
    }
    printf("\n");
}

// ��𕶎��œ��� -----------------------------------------------------------------------------
// �߂�l char   : ���͂��ꂽ��
// �����@ prompt : ���͂𑣂�������
char inputHand(const char* prompt) {
    char ch;
    printf("%s", prompt);
    fflush(stdout);
    scanf("%*[\r\n]");
    scanf("%c", &ch);
    return ch;
}

// ������ -----------------------------------------------------------------------------------
// �߂�l hand_t : ���͂��ꂽ��
// �����@ prompt : ���͂𑣂�������
hand_t getHand(const char* prompt) {
    hand_t hand;
    char inputCH, smallCh;
    const char* foundCh;

    inputCH =inputHand(prompt);
    //��������
    smallCh = tolower(inputCH);
    //gcp�ɑ��݂��邩����
    foundCh = strchr(chHands, smallCh);

    //�Ȃ�������ē���
    while (foundCh==NULL) {
        printf("%c �����ʂł��܂���B\n", inputCH);
        printf("������x�A");
        inputCH = inputHand(prompt);
        //��������
        smallCh = tolower(inputCH);
        //gcp�ɑ��݂��邩����
        foundCh = strchr(chHands, smallCh);
    }
    //����������z��̉��Ԗڂɓ����Ă��邩�v�Z����
    hand = (hand_t)(foundCh - chHands);

    return hand;
}

//main�֐�------------------------------------------------------------
int main(void) {
    //�ϐ���`
    hand_t  myHand, otherHand;       //�����̎�A����̎�
    judge_t judge;
    //����
    promptMessage();
    myHand = getHand("�����̎����͂��Ă��������B");
    otherHand = getHand("����̎����͂��Ă��������B");
    // �v�Z
    judge = judgeTable[myHand][otherHand];
    //�o��
    printf("%s �� %s �� %s �ł��B\n",
        handStrings[myHand], handStrings[otherHand], judgeStrings[judge]);
    return 0;
}