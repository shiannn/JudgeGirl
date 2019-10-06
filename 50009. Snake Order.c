#include <stdio.h>

int snake(int *ptr, int *row, int *column) {
    // add your code
    int k;
    for(k=0;;k++){
        if(ptr[k]+1 != ptr[k+1]){
            break;
        }
    }
    *column = k+1;
    int flag = 1;
    int left = 0,right = *column;
    int start = left,end = right;
    int count = 0;
    int prev = -1;
    while(flag){
        count++;
        if(count%2==1){
            start = left;
            end = right;
        }
        else{
            start = right-1;
            end = left-1;
        }
        for(int i=start;i!=end;){
            //printf("%d ",ptr[i]);
            if(ptr[i]!=prev+1 && ptr[i]!=0){
                *row = count-1;
                if(count%2==1){
                    *column = i%(*row);
                }
                else{
                    //printf("col %d\n",*column);
                    //printf("%d\n",(i%(*column)));
                    *column = (*column-1) - (i%(*column));
                }
                return 0;
            }
            prev = ptr[i];
            if(ptr[i] == 0 && i!=0){
                flag = 0;
                break;
            }
            if(start<end){
                i++;
            }
            else{
                i--;
            }
        }
        left = right;
        right = left+*column;
    }
    *row = count-1;
    return 1;
}
int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}