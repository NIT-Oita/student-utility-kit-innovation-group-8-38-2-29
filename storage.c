#include <stdio.h>
#include "logic.h"
int load_tasks(const char *path,
Card *list, int max) {
FILE *fp = fopen(path, "r");
if (!fp) return 0;        /* ファイルがまだ無い */
char line[256];
fgets(line, sizeof line, fp);   /* ヘッダ行を読み飛ばす */
int n = 0;
while (n < max &&
fscanf(fp, "%255[^\n] %255[^\n]",
list[n].word,
list[n].answer) == 2) {
n++;
}
fclose(fp);
return n;
}