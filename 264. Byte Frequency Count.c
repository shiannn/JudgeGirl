#include <stdio.h>

int main(){
    char filename[210];
    scanf("%s",filename);
    FILE* fp = fopen(filename,"rb");
    int lengthN;
    fread(&lengthN,sizeof(int),1,fp);
    #ifdef debug
    printf("len == %d\n",lengthN);
    #endif
    int times[100000] = {0};
    int maxTime = -1,maxnum;
    short int myShort;
    for(int i=0;i<lengthN;i++){
        fread(&myShort,sizeof(short int),1,fp);
        times[myShort+32768] += 1;
        if(times[myShort+32768] > maxTime){
            maxTime = times[myShort+32768];
            maxnum = myShort;
        }
        else if(times[myShort+32768] == maxTime){
            if(myShort > maxnum){
                maxTime = times[myShort+32768];
                maxnum = myShort;
            }
        }
    }
    #ifdef debug
    printf("maxnum == %d\n",maxnum);
    printf("maxTime == %d\n",maxTime);
    #endif
    printf("%d\n",maxnum);
    printf("%d\n",maxTime);
}