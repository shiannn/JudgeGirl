#include <stdio.h>
#include <string.h>
#define Allchar 10000010
#define Totalword 18000
#define TotalLine 1025

char word[40];
char dummy;
char Allword[Allchar];
char* wordPtr[Totalword];
char**linePtr[TotalLine];
int wordNumberEachLine[TotalLine];

int main(){
    int N;
    scanf("%d",&N);
    //construct level1 level2
    int pos = 0,wordNum=0,lineNum=0,wordOnlyOneLine=0;
    for(int i=0;i<N;i++){
        wordOnlyOneLine = 0;
        linePtr[lineNum] = &wordPtr[wordNum];
        while(scanf("%s%c",word,&dummy)!=EOF){
            //printf("%s\n",word);
            //put into a long array
            strcpy(&Allword[pos],word); 
            wordPtr[wordNum] = &Allword[pos];
            pos += (strlen(word)+1); // length + '\0'
            wordNum += 1;
            wordOnlyOneLine += 1;
            if(dummy=='\n')break;
        }
        wordNumberEachLine[lineNum] = wordOnlyOneLine;
        lineNum += 1;
    }
    //exchange
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int l1,w1,l2,w2;
        scanf("%d%d%d%d",&l1,&w1,&l2,&w2);
        //swap 指標的值
        char** line1 = linePtr[l1];
        char* word1ptr = line1[w1];
        char** line2 = linePtr[l2];
        char* word2ptr = line2[w2];
        //printf("w1==%s w2==%s\n",word1ptr,word2ptr);
        //swap line1[w1] line2[w2]
        char* temp = line1[w1];
        line1[w1] = line2[w2];
        line2[w2] = temp;
    }
    for(int i=0;i<N;i++){
        //printf("%d ",wordNumberEachLine[i]);
        for(int j=0;j<wordNumberEachLine[i];j++){
            char** line = linePtr[i];
            char* wordptr = line[j];
            if(j!=0)printf(" ");
            printf("%s",wordptr);
        }
        printf("\n");
    }
#ifdef debug
    //scope ?
    for(int i=0;i<wordNum;i++){
        printf("%s\n",wordPtr[i]);
    }
#endif
#ifdef debugline
    for(int i=0;i<lineNum;i++){
        char** linei = linePtr[i];
        char* word = linei[0]; //start word in linei
        printf("%s\n",word);
    }
#endif
}