#define MaxN 5

typedef struct _lights{
    // Design by yourself
    int LightCells[MaxN][MaxN];
    int numOfBright;
}Lights;
 
void init(Lights *l);
int numOfLights(Lights *l,int N);
void flip(Lights *l,int i,int N);
void printLights(Lights *l,int N);