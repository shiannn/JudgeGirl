#include <stdio.h>
#include <stdlib.h>


typedef struct student{
    int studentId;
    int chinese;
    int english;
    int math;
    int science;
    int social;
    int total;
}student;

student studentArray[20010];

int sumStudent(student studentIns){
    int ret = studentIns.chinese+\
            studentIns.english+\
            studentIns.math+\
            studentIns.science+\
            studentIns.social;
    return ret;
}

int cmp(const void* ptr1, const void* ptr2){
    student* stud1 = (student*)ptr1;
    student* stud2 = (student*)ptr2;
    if(stud1->total > stud2->total){
        return -1;
    }
    else if(stud1->total < stud2->total){
        return 1;
    }
    else if(stud1->math > stud2->math){
        return -1;
    }
    else if(stud1->math < stud2->math){
        return 1;
    }
    else if(stud1->english > stud2->english){
        return -1;
    }
    else if(stud1->english < stud2->english){
        return 1;
    }
    else if(stud1->science > stud2->science){
        return -1;
    }
    else if(stud1->science < stud2->science){
        return 1;
    }
    else if(stud1->chinese > stud2->chinese){
        return -1;
    }
    else if(stud1->chinese < stud2->chinese){
        return 1;
    }
    else if(stud1->social > stud2->social){
        return -1;
    }
    else if(stud1->social < stud2->social){
        return 1;
    }
    else if(stud1->studentId < stud2->studentId){
        //all same
        return -1;
    }
    else if(stud1->studentId > stud2->studentId){
        //all same
        return 1;
    }
}

int same(student A,student B){
    if(A.total == B.total&&\
        A.math == B.math&&\
        A.english == B.english&&\
        A.science == B.science&&\
        A.chinese == B.chinese&&\
        A.social == B.social){
            return 1;
    }
    else{
            return 0;
    }
}

int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d%d%d",&studentArray[i].studentId,\
                            &studentArray[i].chinese,\
                            &studentArray[i].english,\
                            &studentArray[i].math,\
                            &studentArray[i].science,\
                            &studentArray[i].social\
                            );
        studentArray[i].total = sumStudent(studentArray[i]);
    }
#ifdef debug
    for(int i=0;i<N;i++){
        printf("%d %d %d %d %d %d %d\n",studentArray[i].studentId,\
                            studentArray[i].chinese,\
                            studentArray[i].english,\
                            studentArray[i].math,\
                            studentArray[i].science,\
                            studentArray[i].social,\
                            studentArray[i].total);
    }
#endif

    qsort(studentArray,N,sizeof(student),cmp);
#ifdef debug
    printf("---------------------\n");
    for(int i=0;i<N;i++){
        printf("%d %d %d %d %d %d %d\n",studentArray[i].studentId,\
                            studentArray[i].chinese,\
                            studentArray[i].english,\
                            studentArray[i].math,\
                            studentArray[i].science,\
                            studentArray[i].social,\
                            studentArray[i].total);
    }
#endif

    for(int i=0;i<M;i++){
        printf("%d\n",studentArray[i].studentId);
    }
    for(int i=M;same(studentArray[i],studentArray[i-1])&&i<N;i++){
        printf("%d\n",studentArray[i].studentId);
    }
}