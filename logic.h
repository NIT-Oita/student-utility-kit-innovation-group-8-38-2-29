#ifndef LOGIC_H
#define LOGIC_H
#define MAX_TASKS 100
typedef struct {
 char word[256];
 char answer[256];
} Task;
int task_urgency(const Task *t,
 const char *today);
void task_sort(Task *list, int n);
#endif