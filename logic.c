#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "logic.h"

int i=0;
int j=1;
int r;
Card cheet[128];

void trim_newline(char *str){
    str[strcspn(str, "\n")] = '\0';
}

void INPUT_MODE(void){
    int judge;
    int c;


    while(i < MAX_TASKS){
        printf("単語を入力\n");
        fgets(cheet[i].word, sizeof(cheet[i].word), stdin);
        trim_newline(cheet[i].word);

        printf("\n単語の意味を入力\n");
        fgets(cheet[i].answer, sizeof(cheet[i].answer), stdin);
        trim_newline(cheet[i].answer);
        
        printf("単語:%s\n",cheet[i].word);
        printf("意味:%s\n",cheet[i].answer);

        i++;

        if(i < MAX_TASKS){
            printf("入力モードを終了しますか？\n「はい」なら「1」,「いいえ」なら(それ以外)を入力:");
            scanf("%d", &judge);

            if(judge == 1){
                printf("入力モード終了\n");
                break;
            }
        }else{
            printf("容量に達した為，入力モード終了\n");
            break;
        }

        while((c = getchar()) != '\n' && c != EOF);
    }
}

void QUIZ_MODE(void){
    srand((unsigned int)time(NULL));
    
    int JUDGE;
    char ANSWER[256];
    int c;


    if(i == 0){
        printf("単語が登録されていません\n先に入力モードをやってください\n");
        return;
    }

    while(1){
        r=rand()%i;

        printf("%d問目\n%s\n",j,cheet[r].word);
        printf("答えを入力:");
        fgets(ANSWER, sizeof(ANSWER), stdin);
        trim_newline(ANSWER);

        if(strcmp(ANSWER,cheet[r].answer) == 0){
            printf("正解！\n");
        }else{
            printf("不正解...\n");
            printf("答え: %s\n",cheet[r].answer);
        }

        printf("クイズモードを終了しますか？\n「はい」なら「1」,「いいえ」なら(それ以外)を入力:");
        scanf("%d", &JUDGE);

        if(JUDGE == 1){
            printf("クイズモード終了\n");
            break;
        }

        j++;

        while((c = getchar()) != '\n' && c != EOF);

        
    }
}