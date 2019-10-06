#include <stdio.h>
#include <string.h>

int getmini(char toIn[][4],int k){
    int choose = -1;
    char MIN[4]={0};
    MIN[0]=123,MIN[1]=123,MIN[2]=123;
    for(int i=0;i<k;i++){
        if(strcmp(toIn[i],"+++")!=0){
            if(strcmp(toIn[i],MIN)<0){
                choose = i;
                strcpy(MIN,toIn[i]);
            }
        }
    }
    return choose;
}
int main(){
    FILE* fp[30];
    FILE* fpout;
    char filename[30][30];
    char outName[30];
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%s",filename[i]);
        fp[i] = fopen(filename[i],"r");
    }
    scanf("%s",outName);
    fpout = fopen(outName,"w");
    //從k個4字元陣列得到最小的丟進output file
    //然後去讀新的進來
    char toIn[30][4]={0};
    int Stop=0;
    for(int i=0;i<k;i++){
        char* state=fgets(toIn[i],4,fp[i]);
        //為什麼是4
        toIn[i][3]='\0';
        if(state==NULL){
            strcpy(toIn[i],"+++");
            Stop++;
        }
    }
    int choose = getmini(toIn,k);
    while(Stop<k){
        //printf("%s\n",toIn[choose]);
        fprintf(fpout,"%s",toIn[choose]);
        char* state = fgets(toIn[choose],4,fp[choose]);
        if(state==NULL){
            strcpy(toIn[choose],"+++");
            Stop++;
        }
        choose = getmini(toIn,k);
    }
}