#include <stdio.h>

int main(){
    int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
    scanf("%d%d%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy);
    int area = (Dy - Ay)*(Dx - Ax) + (Cy - By)*(Cx - Bx) + (Bx - Dx)*(Cy-Ay);
    int perimeter = (Dx-Ax)+(Cy-Dy)+(Cx-Dx)+(Cy-By)+(Cx-Bx)+(By-Ay)+(Bx-Ax)+(Dy-Ay);
    printf("%d\n%d\n",perimeter,area);
}