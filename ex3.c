#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_pilha
{
    float num;
    struct st_pilha *prox;
} pilha;

void inserir(pilha **cabeca, float c)
{
    pilha *op;
    op=malloc(sizeof(pilha));
    op->num=c;
    op->prox=NULL;
    if(cabeca == NULL)
    {
        op->prox=NULL;
        *cabeca=op;
    }
    else
    {        
        op->prox=*cabeca;
        *cabeca=op;
    }
    return;
}

void mostrar(pilha *cabeca)
{
    pilha *ms=cabeca;

    printf("\nResultado da operacao: ");
    while(ms!=NULL)
    {
        printf("%.2f\n", ms->num);
        ms=ms->prox;
    }

    return;
}

float retirar(pilha **cabeca)
{ 
    float valor=0;
    pilha *primeiro=*cabeca;

    *cabeca=primeiro->prox;
    valor=primeiro->num;
    free(primeiro);
    return valor;
} 

int n_elementos(pilha *cabeca)
{
    pilha *op=cabeca;
    int count=0;
    while(op!=NULL)
    {
        count++;
        op=op->prox;
    }
    return count;
}

void inicio(void)
{
    float res=0, x=0, y=0;
    pilha *cabeca=NULL;
    int cont_p=0;
    char exp[20];
    printf("\n\t\t\t\tCalculadora Polonesa Reversa\n");
    printf("Digite os numeros e logo em seguida coloque operador\n");
    printf("\nSoma -> +\nSubtracao -> -\nMultiplicacao -> *\nDivisao -> /\nResultado Final -> =\n\n");
    do
    {
        scanf("%s", &exp);
        if(!strcmp(exp, "+"))
        {
            x=retirar(&cabeca);
            y=retirar(&cabeca);
            res=x+y;
            inserir(&cabeca, res);
        }
        else if(!strcmp(exp, "-"))
        {
            x=retirar(&cabeca);
            y=retirar(&cabeca);
            res=y-x;
            inserir(&cabeca, res);
        }
        else if(!strcmp(exp, "*"))
        {
            x=retirar(&cabeca);
            y=retirar(&cabeca);
            res=x*y;
            inserir(&cabeca, res);  
        }
        else if(!strcmp(exp, "/"))
        {
            x=retirar(&cabeca);
            y=retirar(&cabeca);
            res=y/x;
            inserir(&cabeca, res);  
        }
        else if(!strcmp(exp, "="))
        {

            if(cabeca!=NULL)
            {
                mostrar(cabeca);
            }

        }
        else
            inserir(&cabeca, atof(exp)); //atoi -> string para inteiro, atof -> string para float
    }while(strcmp(exp, "="));

}



int main(void)
{
    char sair;
    do
    {
        inicio();
        printf("\nDeseja continuar? y/n\n");
        scanf("%s", &sair);
    }while(sair!='n');
    return 0;
}


