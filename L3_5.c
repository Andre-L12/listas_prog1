#include <stdio.h>
int Propiedade(int num){
    int cd = num%100;
    int ab = num/100;
    int ef=ab+cd;
    int propiedade=ef*ef;
    if(propiedade ==num){
        return num;
    }else{return 0;}
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    for(i=n+1;i<m;i++){
        int satisfaz=Propiedade(i);
        if(satisfaz){
            printf("%d\n",satisfaz);
        }
    }
    return 0;
}