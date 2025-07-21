#include <stdio.h>

typedef struct 
{
    int dia;
    int mes;
    int ano;
}tData;
int EhBissexto(tData data){
    if((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano% 400 == 0)){
        return 1;
    }else{
        return 0;
    }
}
tData LeData(){
    tData data;
    scanf("%d %d %d",&data.dia,&data.mes,&data.ano);
    return data;
}
void ImprimeData(tData data){
    if(data.dia<10){
        printf("'0%d/",data.dia);
    }else{
        printf("'%d/",data.dia);
    }
    if(data.mes<10){
        printf("0%d/",data.mes);
    }else{
        printf("%d/",data.mes);
    }
    printf("%d'\n",data.ano);
}
tData ValidaData(tData data){
    dia_fev=DiasFev(data);
    if(data.mes<1){
        data.mes=1;
    }else if(data.mes>12){
        data.mes=12;
    }
    if(data.dia>dia_fev && data.mes==2){
        data.dia=28;
    } if(data.dia>30 &&(data.mes==4||data.mes==6||data.mes==9||data.mes==11)){
        data.dia=30;
    } if(data.dia>31 &&(data.mes==1||data.mes==3||data.mes==5||data.mes==7||data.mes==8||data.mes==10||data.mes==12)){
        data.dia=31;
    }
    return data;
    
}
int DiasFev(tData data){
if(EhBissexto(data.ano)){
        dia_fev=29;
    }else{
        dia_fev=28;
    }
    return dia_fev;
}
tData ProximaData(tData data){
    data.dia++;
    dia_fev=DiasFev(data);
    if(data.dia>dia_fev && data.mes==2){
        data.dia=1;
        data.mes++;
    } if(data.dia>30 &&(data.mes==4||data.mes==6||data.mes==9||data.mes==11)){
        data.dia=1;
        data.mes++;
    } if(data.dia>31 &&(data.mes==1||data.mes==3||data.mes==5||data.mes==7||data.mes==8||data.mes==10||data.mes==12)){
        data.dia=1;
        data.mes++;
    }
    if(data.mes>12){
        data.mes=1;
        data.ano++;
        data.dia=1;
    }
    return data;
}
void VarreDatas(tData inicio,tData fim){
while(inicio.dia!=fim.dia || inicio.mes!=fim.mes || inicio.ano!=fim.ano){
    ImprimeData(inicio);
    inicio=ProximaData(inicio);
}
}

int main(){
    tData inicio,fim;
    inicio=LeData();
    inicio=ValidaData(inicio);
    fim=LeData();
    fim=ValidaData(fim);
    VarreDatas(inicio,fim);
    return 0;
}