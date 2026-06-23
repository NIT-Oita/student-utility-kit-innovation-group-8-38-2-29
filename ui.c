#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"logic.h"
#include"ui.h"

static void clearScreen(){//画面を消す
    system("cls");
    return;
}

static void tango_nyuryoku_gamen(void){
        clearScreen();
        printf("======================================\n");
        printf("=============単語入力画面==============\n");
        printf("======================================\n");

        INPUT_MODE();

        printf("Enterキーを押すとメニュー選択画面に戻ります");
        while(getchar()!='\n');
        getchar();
}

static void test_gamen(void){
        printf("======================================\n");
        printf("==============テスト画面===============\n");
        printf("======================================\n");

        QUIZ_MODE();
        printf("Enterキーを押すとメニュー選択画面に戻ります");
        while(getchar()!='\n');
        getchar();
}

void start_app(void){
    int sentaku;
    char menu_buf[16];

    while(1){
    clearScreen();//画面を1度消す
        printf("======================================\n");
        printf("==========英単語テストシステム==========\n");
        printf("======================================\n");
        printf("1:単語入力\n");
        printf("2:テスト\n");
        printf("3:終了\n");
        printf("選択してください: ");


        if(fgets(menu_buf,sizeof(menu_buf),stdin)==NULL){
            continue;
        }

        sentaku=atoi(menu_buf);

        if(sentaku==3){//3が押されたとき
            printf("システムを終了します\n");
            break;
        }

        if(sentaku<1 || sentaku>3){
            clearScreen();
            printf("[エラー]正しい番号を入力してください\n");
            printf("\nEnterキーを押すとメニューに戻ります...");
            getchar();
            continue;
        }
        
        clearScreen();
        if(sentaku==1){//1が押されたとき
            tango_nyuryoku_gamen();
        }else if(sentaku ==2){//2が押されたとき
            test_gamen();
        }
        
        
    }
}
