#include <stdio.h>

int main(){
    int TaskType;
    scanf("%d",&TaskType);
    char pattern[8];
    if(TaskType == 0){// 4 to 1
        while(scanf("%s",pattern)!=EOF){
            unsigned long long int Output=0;
            unsigned int L;
            unsigned short int S;
            char c[5];
            scanf("%u%hu%s",&L,&S,c);
            //combine to a 64-bits
        #ifdef debug
            printf("[de] %s\n",pattern);
            printf("[de] %u %hu %c %c\n",L,S,c[0],c[1]);
        #endif 
            int check = 0;
            for(int i=0;i<4;i++){
                if(pattern[i]=='L'){
                    Output <<= 32;
                    Output |= L;
                }
                if(pattern[i]=='S'){
                    Output <<= 16;
                    Output |= S;
                }
                if(pattern[i]=='C'){
                    if(check==0){
                        Output <<= 8;
                        Output |= c[0];
                        check = 1;
                    }
                    else{
                        Output <<= 8;
                        Output |= c[1];
                    }
                }
            }
            printf("%llu\n",Output);
        }
    }
    else if(TaskType == 1){//1 to 4 
        unsigned long long int Input;
        while(scanf("%s%llu",pattern,&Input)!=EOF){
            int check = 0;
            unsigned int L = 0;
            unsigned short int S = 0;
            char c[5] = {0};
            for(int i=3;i>=0;i--){
                if(pattern[i]=='L'){
                    L |= Input;
                    Input >>= 32; 
                }
                if(pattern[i]=='S'){
                    S |= Input;
                    Input >>= 16;
                }
                if(pattern[i]=='C'){
                    if(check==0){
                        c[0] |= Input;
                        Input >>= 8;
                        check = 1;
                    }
                    else{
                        c[1] |= Input;
                        Input >>= 8;
                    }
                }
            }
            printf("%u %hu %c%c\n",L,S,c[1],c[0]);
        }
    }
}