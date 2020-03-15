#include <stdio.h>
#include <stdint.h>
#include <time.h> 

int main(){
    time_t seconds; 
    seconds = time(NULL); 
    printf("Seconds since January 1, 1970 = %ld\n", seconds);

    char inFile1[32],inFile2[32],outFile[32];
    scanf("%s%s%s",inFile1,inFile2,outFile);
    FILE *infp1 = fopen(inFile1,"rb");
    FILE *infp2 = fopen(inFile2,"rb");
    FILE *outfp = fopen(outFile,"wb");

    fseek(infp1,0,SEEK_END);
    int f1num = ftell(infp1);
    fseek(infp2,0,SEEK_END);
    int f2num = ftell(infp2);
    if(f2num>f1num){
        int tempnum = f2num;
        f2num = f1num;
        f1num = tempnum;
        FILE* temp = infp2;
        infp2 = infp1;
        infp1 = temp;
    }
    //1 > 2
    uint16_t sum;
    uint8_t carry=0;
    uint8_t buffer1,buffer2;
    uint8_t outArr[100]={0};
    for(int i=0;i<f1num;i++){
        fseek(infp1,f1num-i-1,SEEK_SET);
        fread(&buffer1,1,1,infp1);
        if(i<f2num){
            fseek(infp2,f2num-i-1,SEEK_SET);
            fread(&buffer2,1,1,infp2);
        }
        else buffer2=0;
        sum = (uint16_t)(buffer1+buffer2+carry);
        if(sum > 255)carry = 1;//sum -= 256;
        else carry = 0;

        outArr[99-(i%100)] = (uint8_t)sum;
        if(((i+1)%100==0)&& (i != 0)){
            fseek(outfp,f1num-i-1,SEEK_SET);
            fwrite(outArr,sizeof(uint8_t),100,outfp);
        }
    }
    if(f1num%100!=0){
        fseek(outfp,0,SEEK_SET);
        fwrite(&outArr[100-(f1num%100)],1,f1num%100,outfp);
    }
    fclose(infp1);
    fclose(infp2);
    fclose(outfp);
    seconds = time(NULL); 
    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    return 0;
}