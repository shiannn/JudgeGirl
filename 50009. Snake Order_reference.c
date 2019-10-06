#include <stdio.h>

int snake(int *ptr, int *row, int *column) {
    // find columns
    int index = 0;
    *column = 0;
    for (int i = 0; i == ptr[index]; i++, index++) {
        (*column)++;
    }
    index = 0;
    *row = 0;
    while (ptr[index] != 0 || index == 0) {
        //printf("row == %d\n",*row);
        if (*row % 2 == 1) {
            for (int i = *column - 1; i >= 0; i--, index++) {
                if (ptr[index] != (*row) * (*column) + i) {
                    *column = i;
                    return 0;
                }
            }
        }
        else {
            for (int i = 0; i < *column; i++, index++) {
                if (ptr[index] != (*row) * (*column) + i) {
                    *column = i;
                    return 0;
                }
            }
        }
        (*row)++;
    }
    return 1;
}
int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}