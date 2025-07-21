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
int DiasFev(tData data){
    int dia_fev;
if(EhBissexto(data)){
        dia_fev=29;
    }else{
        dia_fev=28;
    }
    return dia_fev;
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
    printf("%d'",data.ano);
}


tData ProximaData(tData data){
    data.dia++;
    int dia_fev=DiasFev(data);
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
tData ValidaData(tData data){
    int dia_fev= DiasFev(data);
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


int main(){
    int n,i;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        tData data=LeData();
        data = ValidaData(data);
        ImprimeData(data);
        if(EhBissexto(data)){
            printf(":Bisexto\n");
        }else{
            printf(":Normal\n");
        }

    }
    
    return 0;
}