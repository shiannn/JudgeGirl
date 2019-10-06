#include <stdio.h>
#include <assert.h>

#define inch2foot 12
#define foot2yard 3

void init(int length[3]) {
    /* add your code */
    length[0] = 0;
    length[1] = 0;
    length[2] = 0;
}
void add(int length[3], int i) {
    /* add your code */
    length[2] += i;
    length[1] += length[2]/inch2foot;
    length[2] %= inch2foot;
    length[0] += length[1]/foot2yard;
    length[1] %= foot2yard;
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    lengthc[2] = lengtha[2] + lengthb[2];
    lengthc[1] = lengtha[1] + lengthb[1];
    lengthc[0] = lengtha[0] + lengthb[0];

    lengthc[1] += lengthc[2]/inch2foot;
    lengthc[2] %= inch2foot;
    lengthc[0] += lengthc[1]/foot2yard;
    lengthc[1] %= foot2yard;
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    lengthc[2] = lengtha[2] - lengthb[2];
    lengthc[1] = lengtha[1] - lengthb[1];
    lengthc[0] = lengtha[0] - lengthb[0];
    if(lengthc[2]<0){
        lengthc[1] -= 1;
        lengthc[2] += inch2foot;
    }
    if(lengthc[1]<0){
        lengthc[0] -= 1;
        lengthc[1] += foot2yard;
    }
}
int main() {
    int a[3] = {-1, -1, -1}, b[3] = {-1, -1, -1};
    int c[3] = {-1, -1, -1}, d[3] = {-1, -1, -1};
    int e[3] = {-1, -1, -1}, f[3] = {-1, -1, -1};
    int cmd, x, y, z;
    scanf("%d", &cmd);
    if (cmd == 1) {
        init(a);
        printf("%d %d %d\n", a[0], a[1], a[2]);
    } else if (cmd == 2) {
        init(a);
        scanf("%d", &x);
        add(a, x);
        printf("%d %d %d\n", a[0], a[1], a[2]);
    } else if (cmd == 3) {
        init(a), init(b);
        scanf("%d %d", &x, &y);
        add(a, x), add(b, y);
        sum(a, b, c);
        printf("%d %d %d\n", c[0], c[1], c[2]);
    } else if (cmd == 4) {
        init(a), init(b), init(c), init(d);
        scanf("%d %d %d", &x, &y, &z);
        assert(x+y >= z);
        add(a, x), add(b, y);
        sum(a, b, c);
        add(d, z);
        diff(c, d, e);
        printf("%d %d %d\n", e[0], e[1], e[2]);
    }
    return 0;
}