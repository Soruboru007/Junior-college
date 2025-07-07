#include <stdio.h>

int main (void)
{
    int i,length;
    char moji[20];
    char *pmoji;

    printf("10文字程度の英文字の文字列を入力してください。\n");
    scanf("%s",moji);

    pmoji = moji;
    while(*pmoji != '\0')
    {
        printf("%s\n",pmoji);
        pmoji++;
    }

    
}