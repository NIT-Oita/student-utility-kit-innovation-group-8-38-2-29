#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"

int i;
int j;

void INPUT_MODE(void){
    Card cheet[128];
    int judge;

    for(i=0;i<128;i++){
        printf("単語を入力\n");
        fgets(cheet[i].word, sizeof(cheet[i].word), stdin);
        printf("\n単語の意味を入力\n");
        fgets(cheet[i].answer, sizeof(cheet[i].answer), stdin);
        
        printf("単語:%255s\n",cheet[i].word);
        printf("意味:%255s\n",cheet[i].answer);
        
        if(i < 127){
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
    }
}

void QUIZ_MODE(void){
    srand((unsigned int)time(NULL));
    Card cheet[128];
    int JUDGE;
    char ANSWER[256];

    while(1 != 0){
        i=rand()%128;

        printf("%d問目\n%255s",j,cheet[i].word);
        printf("答えを入力:");
        fgets(ANSWER, sizeof(ANSWER), stdin);
        if(strcmp(ANSWER,cheet[i].answer) == 0){
            printf("正解！\n");
        }else{
            printf("不正解...\n");
            printf("答え: %255s\n",cheet[i].answer);
        }

        printf("入力モードを終了しますか？\n「はい」なら「1」,「いいえ」なら(それ以外)を入力:");
        scanf("%d", &JUDGE);
        if(JUDGE == 1){
            printf("入力モード終了\n");
            break;
        }

        j++;
    }
}