#include<stdio.h>
#include<stdlib.h>

void clearscreen(){
    system("cls");
}
int main(){
    int sentaku;

    while(1){
        clearScreen();
        printf("======================================\n");
        printf("==========英単語テストシステム==========\n");
        printf("======================================\n");
        printf("1:単語入力\n");
        printf("2:テスト\n");
        printf("3:終了\n");
    }
}