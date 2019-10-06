#include <stdio.h>
#include <string.h>

typedef struct person {
    unsigned int id;
    char name[32];
}person;
typedef struct friends {
    unsigned id1;
    unsigned id2;
}friends;

person ps[10000];
friends fs[10000];
int getidx(char name[]){
    for(int i=0;i<10000;i++){
        if(strcmp(ps[i].name,name)==0)return ps[i].id;
    }
}
int getrelation(int id1,int id2){
    for(int i=0;i<10000;i++){
        if(fs[i].id1 ==id1 && fs[i].id2==id2)return 1;
    }
    return 0;
}
int main(){
    FILE* fp = fopen("friends","rb");
    int size;
    int Ppeople,Ffriends;
    fread(&Ppeople,sizeof(int),1,fp);
    fread(ps,sizeof(person),Ppeople,fp);
    fread(&Ffriends,sizeof(int),1,fp); 
    fread(fs,sizeof(friends),Ffriends,fp);
    fclose(fp);
    char person1[32];
    char person2[32];
    while(scanf("%s",person1)!=EOF){
        if(strcmp(person1,"end")==0)break;
        scanf("%s",person2);
        int id1 = getidx(person1);
        int id2 = getidx(person2);
        if(getrelation(id1,id2)==1 || getrelation(id2,id1)==1)printf("yes\n");
        else printf("no\n");
    }
}