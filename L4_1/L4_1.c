#include <stdio.h>
typedef struct{
    int codigo;
    float preco;
    int qtd_estoque;
}tProduto;
tProduto LeProduto(){
    tProduto produto;
    scanf("%d;%f;%d",&produto.codigo,&produto.preco,&produto.qtd_estoque);
    return produto;
}
int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
    if(p1.preco>p2.preco){
        return 1;
    }else{
        return 0;
    }
}
int EhProduto1MenorQ2(tProduto p1, tProduto p2){
    if(p1.preco<p2.preco){
        return 1;
    }else{
        return 0;
    }
}
int TemProdutoEmEstoque(tProduto p){
    if(p.qtd_estoque!=0){
        return 1;
    }else{
        return 0;
    }
}
void ImprimeProduto(tProduto p){
    printf("COD %d, PRE %.2f, QTD %d\n",p.codigo,p.preco,p.qtd_estoque);
}
int main(){
    int n,i;
    scanf("%d",&n);
    tProduto maior = LeProduto();
    tProduto menor= maior;
    if(!TemProdutoEmEstoque(maior)){
            printf("FALTA:");
            ImprimeProduto(maior);
        }
    for (i = 1; i < n; i++)
    {
        tProduto produto =LeProduto();
        if(EhProduto1MaiorQ2(produto,maior)){
            maior=produto;
        }
        if(EhProduto1MenorQ2(produto, menor)){
            menor=produto;
        }
        if(!TemProdutoEmEstoque(produto)){
            printf("FALTA:");
            ImprimeProduto(produto);
        }
    }
    printf("MAIOR:");
    ImprimeProduto(maior);
    printf("MENOR:");
    ImprimeProduto(menor);
}