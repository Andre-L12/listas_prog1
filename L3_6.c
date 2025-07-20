#include <stdio.h>
int area (int x1, int y1, int x2, int y2){
    int area=(x2-x1)*(y2-y1);
    return area;
}
int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
    int intersecao;
    int area1=area(r1_x1,r1_y1,r1_x2,r1_y2);
    int area2=area(r2_x1,r2_y1,r2_x2,r2_y2);
    int i_x1,i_x2,i_y1,i_y2;
    if(r1_x1<r2_x1){
        i_x1=r2_x1;
        i_y1=r2_y1;
    }else{
        i_x1=r1_x1;
        i_y1=r1_y1;
    }
    if(r1_y2<r2_y2){
        i_x2=r1_x2;
        i_y2=r1_y2;
    }
    else{
        i_x2=r2_x2;
        i_y2=r2_y2;
    }
    if(i_x1<i_x2 && i_y1<i_y2){
    intersecao=area(i_x1,i_y1,i_x2,i_y2);}
else{
intersecao=0;
}
    return area1+area2-intersecao;
}
int main()
{ 
    int r1_x1,r1_x2,r1_y1,r1_y2,r2_x1,r2_x2,r2_y1,r2_y2;
    scanf("%d %d %d %d",&r1_x1,&r1_y1,&r1_x2,&r1_y2);
    scanf("%d %d %d %d",&r2_x1,&r2_y1,&r2_x2,&r2_y2);
    int soma=area_total(r1_x1,r1_y1,r1_x2,r1_y2,r2_x1,r2_y1,r2_x2,r2_y2);
    printf("RESP:%d",soma);
    return 0;
}