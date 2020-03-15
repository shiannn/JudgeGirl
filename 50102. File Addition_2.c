#include<stdio.h>
int main(){
    char name1[32],name2[32],out[32];
    scanf("%s%s%s",name1,name2,out);
    FILE *f1=fopen(name1,"rb");
    FILE *f2=fopen(name2,"rb");
    FILE *f3=fopen(out,"wb");
    fseek(f1,0,SEEK_END);
    fseek(f2,0,SEEK_END);    
    long length1=ftell(f1),length2=ftell(f2);
    if(length1<length2){
        FILE *tmp=f1;
        f1=f2;
        f2=tmp;
        int t=length1;
        length1=length2;
        length2=t;
    }int carry=0,sum=0;
    for(int i=0;i<length1;i++){
        unsigned char a,b;
        fseek(f1,length1-i-1,SEEK_SET);
        fread(&a,sizeof(unsigned char),1,f1);
        if(i<length2){
            fseek(f2,length2-i-1,SEEK_SET);
            fread(&b,sizeof(unsigned char),1,f2);
        }else b=0;
        sum=carry+a+b;
        if(sum>255)carry=1;
        else carry=0;
        fseek(f3,length1-i-1,SEEK_SET);
        fwrite(&sum,sizeof(unsigned char),1,f3);
    }fclose(f1);
    fclose(f2);
    fclose(f3);
}