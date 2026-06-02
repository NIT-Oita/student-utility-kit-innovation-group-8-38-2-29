#include<stdio.h>
#include<stdlib.h>
#include"logic.h"
#include"ui.h"

static clearScreen(){
    system("cls");
}

static void tango_nyuryoku_gamen(void){
        clearScreen();
        printf("======================================\n");
        printf("=============単語入力画面===============\n");
        printf("======================================\n");

        logic_input_word();//仮

        printf("Enterキーを押すとメニュー選択画面に戻ります");
        while(getchar()!='\n');
        getchar();
}

static void test_gamen(void){
        printf("======================================\n");
        printf("==============テスト画面===============\n");
        printf("======================================\n");

        logic_start_test();
        printf("Enterキーを押すとメニュー選択画面に戻ります");
        while(getchar()!='\n');
        getchar();
}

void start_app(void){
    int sentaku;
    while(1){
    clearScreen();
        printf("======================================\n");
        printf("==========英単語テストシステム==========\n");
        printf("======================================\n");
        printf("1:単語入力\n");
        printf("2:テスト\n");
        printf("3:終了\n");
        printf("選択してください: ");

        if (scanf("%d",&sentaku)!=1){
            clearScreen();
            printf("[エラー]数字を入力してください\n");
            printf("\nEnterキーを押すとメニューに戻ります...");
            while(getchar()!='\n');
            getchar();
            continue;
        }

        if(sentaku==3){
            printf("システムを終了します\n");
            break;
        }

        if(sentaku<1 || sentaku>3){
            clearScreen();
            printf("[エラー]正しい番号を入力してください\n");
            printf("\nEnterキーを押すとメニューに戻ります...");
            while(getchar()!='\n');
            getchar();
            continue;
        }
        clearScreen();
        if(sentaku==1){
            tango_nyuryoku_gamen();
        }else if(sentaku ==2){
            test_gamen();
        }
        
    }
}
       
