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
    double distancia=0;
    distancia=sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
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
typedef struct 
{
    tPonto p1;
    tPonto p2;
}tReta;

tReta InicializarReta(tPonto inicio,tPonto fim){
   tReta reta;
    reta.p1=inicio;
    reta.p2=fim;
    return reta;
}
tReta LeReta(){
    tReta reta;
    tPonto inicio=LePonto();
    reta.p1=inicio;
    tPonto fim=LePonto();
    reta.p2=fim;
    return reta;
}
void ImprimeReta(tReta reta){
    printf("[(%d,%d):(%d,%d)]",reta.p1.x,reta.p1.y,reta.p2.x,reta.p2.y);
}
tPonto PontoInicial(tReta reta){
    tPonto inicio=reta.p1;
    return inicio;
}
tPonto PontoFinal(tReta reta){
    tPonto final=reta.p2;
    return final;
}
tReta Movimentacao(tReta reta, int x,int y){
    reta.p1.x=reta.p1.x+x;
    reta.p2.x=reta.p2.x+x;
    reta.p1.y=reta.p1.y+y;
    reta.p2.y=reta.p2.y+y;
    return reta;
}
int Tamanho(tReta reta){
    double tamanho=Distancia(reta.p1,reta.p2);
    return tamanho;
}
void VerificaProximidade(){
    tPonto ponto=LePonto();
    tReta reta=LeReta();
    tPonto inicio=PontoInicial(reta);
    tPonto fim=PontoFinal(reta);
    double dist_inicio=Distancia(ponto,inicio);
    double dist_fim=Distancia(ponto,fim);
    if(dist_inicio>dist_fim){
        printf("FIM\n");
    }else if(dist_inicio<dist_fim){
        printf("INICIO\n");
    }else{
        printf("EQUIDISTANTE\n");
    }

}
void ContidaQuadrante(){
    tReta reta=LeReta();
    tPonto inicial=PontoInicial(reta);
    tPonto fim=PontoFinal(reta);
    int quad1=Quadrante(inicial);
    int quad2=Quadrante(fim);
    if(quad1==quad2 &&quad1!=0){
        printf("MESMO\n");
    }else{
        printf("DIFERENTE\n");
    }

}
int main(){
    int n,i;
    scanf("%d",&n);
    for ( i = 0; i <n; i++)
    {
        ContidaQuadrante();
    }
    
}