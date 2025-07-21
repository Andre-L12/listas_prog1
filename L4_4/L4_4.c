#include <stdio.h>
#include <math.h>
typedef struct 
{
    int x;
    int y;
}tPonto;

tPonto InicilizarPonto(int x,int y){
    tPonto ponto;
    ponto.x=x;
    ponto.y=y;
    return ponto;
}
tPonto LePonto(){
    tPonto ponto;
    int x,y;
    scanf("%d %d",&x,&y);
    ponto.x=x;
    ponto.y=y;
    return ponto;
}
void ImprimePonto(tPonto ponto){
    printf("(%d,%d)",ponto.x,ponto.y);
}
tPonto AlteraX(tPonto ponto, int x){
    ponto.x=x;
    return ponto;
}
tPonto AlteraY(tPonto ponto, int y){
    ponto.y=y;
    return ponto;
}
int RetornaX(tPonto ponto){
    int x;
    x=ponto.x;
    return x;
}
int RetornaY(tPonto ponto){
    int y;
    y=ponto.y;
    return y;
}
tPonto Movimenetacao(tPonto ponto, int x,int y){
    ponto.y=ponto.y+y;
    ponto.x=ponto.x+x;
    return ponto;
}
double Distancia(tPonto p1,tPonto p2){
    double distancia;
    distancia=sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
    return distancia;
}
int Quadrante(tPonto ponto){
    int quadrante;
    if(ponto.x>0 && ponto.y>0){
        quadrante=1;
    }else if(ponto.x==0 || ponto.y==0){
        quadrante=0;
    }
    else if(ponto.x<0 && ponto.y>0){
        quadrante=2;
    }
    else if(ponto.x<0 && ponto.y<0){
        quadrante=3;
    }
    else if(ponto.x>0 && ponto.y<0){
        quadrante=4;
    }return  quadrante;
}
tPonto Simetrico(tPonto ponto){
    ponto.x=ponto.x*-1;
    ponto.y=ponto.y*-1;
    return ponto;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for ( i = 0; i <n; i++)
    {
        tPonto ponto=LePonto();
        ImprimePonto(ponto);
        int quadrante=Quadrante(ponto);
        printf(" %d ",quadrante);
        tPonto simetrico=Simetrico(ponto);
        ImprimePonto(simetrico);
        int quadrante_simetrico=Quadrante(simetrico);
        printf(" %d\n",quadrante_simetrico);
        
    }
    
}