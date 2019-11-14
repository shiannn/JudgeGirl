#include <stdio.h>
#include <string.h>

#define MaxLength 1030

char SrcString[MaxLength];
char tempString[MaxLength];
char command[MaxLength];
int main(){
    scanf("%s",SrcString);
    while(scanf("%s",command)!=EOF){
        if(strcmp(command,"p")==0){
            printf("%s\n",SrcString);
        }
        else{
            // s% <string1> % <string2> %
            char del = command[1];
            char string1[MaxLength];
            char string2[MaxLength];
            int i,j;
            for(i=2,j=0;command[i]!=del;i++,j++){
                string1[j] = command[i];
            }
            string1[j]='\0';
            i += 1;
            for(j=0;command[i]!=del;i++,j++){
                string2[j] = command[i];
            }
            string2[j]='\0';
            //printf("%s\n%s\n",string1,string2);
            int Srclen = strlen(SrcString);
            int len1 = strlen(string1);
            int len2 = strlen(string2);
            
            for(i=0;i<Srclen;i++){
                if(strncmp(&SrcString[i],string1,len1)==0){
                    break;
                }
                else{
                    tempString[i] = SrcString[i];
                }
            }
            if(i<Srclen){
                //record string1 next
                int tail = i+len1; 
                //paste string2
                for(j=0;j<len2;j++,i++){
                    tempString[i] = string2[j];
                }
                //paste string1
                for(j=tail;j<Srclen;j++,i++){
                    tempString[i] = SrcString[j];
                }
                tempString[i] = '\0';
                //printf("%s\n",tempString);
                strcpy(SrcString,tempString);
            }
        }
    }
}