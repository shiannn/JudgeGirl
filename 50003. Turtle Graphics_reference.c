#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int L, X, Y;
 
int a[105][105];
 
int dx[8] = { 1, 0,-1, 0,-1, 1, 1,-1};
int dy[8] = { 0, 1, 0,-1, 1, 1,-1,-1};
 
int getid(int x, int y, int px, int py)
{
    if (x > px && y == py) return 0;
    else if (x < px && y == py) return 2;
    else if (x == px && y > py) return 1;
    else if (x == px && y < py) return 3;
    else if (x+y == px+py && y > py) return 4;
    else if (x+y == px+py && y < py) return 6;
    else if (x-y == px-py && y > py) return 5;
    else if (x-y == px-py && y < py) return 7;
    return -1;
}
 
int main(void)
{
    scanf("%d%d%d", &L, &X, &Y);
    bool tag = true;
    for (int l = 1; l <= L; l++) {
        int n; scanf("%d", &n);
        int px = -1, py = -1;
        for (int i = 1; i <= n; i++) {
            int x, y; scanf("%d%d", &x, &y);
            //printf("~%d %d\n", px, py);
            if (0 <= x && x < Y && 0 <= y && y < X) {
                if (px == -1 && py == -1) {
                    a[y][x] = 1;
                    px = x, py = y;
                } else {
                    if (x == px && y == py) continue;
                    int id = getid(x, y, px, py);//printf("%d\n", id);
                    if (id == -1) {
                        printf("ERROR %d %d\n", l, i);
                        tag = false;
                        break;
                    }
                    while (px != x || py != y) {
                        px += dx[id], py += dy[id];//printf("--%d,%d\n", px, py);
                        a[py][px] = 1;
                    }
                }
            } else {
                printf("ERROR %d %d\n", l, i);
                tag = false;
                break;
            }
 
            if (!tag) break;
        }
    }
    if (tag)
        for (int i = X-1; i >= 0; i--) {
            for (int j = 0; j < Y; j++)
                printf("%d", a[i][j]);
            puts("");
        }
    return 0;
}