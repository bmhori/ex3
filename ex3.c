#include <stdio.h>
#include <stdlib.h>

int a[5];
int top = -1;
int choice, value;
char Y;

void valor()
{
    if(top==4)
        printf("Pilha cheia");
    else
    {
        top=top+1;
        a[top]=value;
    }
}

void pop()
{
    if(top==-1)
        printf("Insira algum valor.");
    else
        top=top-1;
}

void display()
{
    int i;
    if(top==-1)
        printf("\nNada ainda.");
    else
    {
        printf("\nAte agora:\n");
        for(i=0; i<=top; i++)
        {
            printf("%d\n", a[i]);
        }
    }
}

int operacao()
{
    float X;
    //char M, D, P, S;
    Y=getchar();
    switch(Y)
    {
        case 'M':
            X = a[top]*a[top-1];
            printf("%f", X);
            break;
        case 'D':
            X = a[top]/a[top-1];
            printf("%f", X);
            break;
        case 'P':
            X = a[top]+a[top-1];
            printf("%f", X);
            break;
        case 'S':
            X = a[top]-a[top-1];
            printf("%f", X);
            break;
    }
}

int main()
{

    do
    {
        printf("\n1.Digitar Valor;");
        printf("\n2.Escolha Operacao;");
        printf("\n3.Desfazer;");
        printf("\n4.Display;");
        printf("\n0.Exit;");
        printf("\nO que deseja fazer? ");
        scanf("%d", &choice);

        if(choice==1)
        {
            printf("\nEnter the value: ");
            scanf("%d", &value);
            valor(value);
        }

        if(choice==2)
        {
            printf("\nM Multiplicacao;");
            printf("\nD Divizao;");
            printf("\nP Soma;");
            printf("\nS Subtracao;");
            printf("\nQual sua escolha? ");
            //Y = getchar();
            operacao();
        }

        if(choice==3)
            pop();

        if(choice==4)
            display();
    }
    while(choice!=0);
    getchar();

    return 0;
}

