#ifndef LOGIC_H
#define LOGIC_H
#define MAX_TASKS 100
typedef struct {
 char word[256];
 char answer[256];
} Card;
void INPUT_MODE(void);
void QUIZ_MODE(void);
#endif