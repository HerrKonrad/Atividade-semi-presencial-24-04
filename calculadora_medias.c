#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Algoritmos e Programação - 2021/1
 * Atividade Semipresencial 24/4
 * Nome: Arthur Konrad
 * Atenção: Este código é apenas um desafio pessoal para tentar implementar uma forma de calcular com uma quantidade quase ilimitada de numeros
 * sem precisar mexer no código. Farei a atividade da forma normal com meu grupo.
 */

//Esta função não é minha. Ela serve para ordenar o array de double
static int compare (const void * a, const void * b)
{
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

//Funções para calculo

double fazerMediaHarmonica(double numeros[], size_t quantidade)
{
    size_t novaQuantidade = 0;
    double soma = 0.0;
    double resultado = 0.0;
    size_t i;

    for( i = 0 ; i < quantidade ; i++ )
    {
        if(numeros[i] > 0.0)
        {
            soma += (double) 1.0 / (double)numeros[i];
            novaQuantidade++;
        }
    }

    resultado = novaQuantidade > 0  ?  (double) novaQuantidade / (double) soma   : 0.0 ; //Caso existam numero validos, vamos aplicar a fórmula. Caso nenhum numero seja valido (maior de zero) retornaremos 0.0
    return resultado;
}

double fazerMediaGeometrica(double numeros[], size_t quantidade)
{
    size_t novaQuantidade = 0;
    double multiplicacao = 1.0;
    double resultado = 0.0;
    size_t i;

    for( i = 0 ; i < quantidade ; i++ )
    {
        if(numeros[i] > 0.0)
        {
            multiplicacao *= numeros[i];
            novaQuantidade++;
        }
    }
    resultado =  novaQuantidade > 0 ? pow(multiplicacao, (double) 1.0 / (double) novaQuantidade) : 0;
    return resultado;
}

double fazerMediaAritmetica(double numeros[], size_t quantidade)
{
    size_t i;
    double resultado = 0.0;
    double soma = 0.0;

    for( i = 0 ; i < quantidade ; i++ )
    {
        soma += numeros[i];
    }
    resultado = soma / quantidade;
    return resultado;
}

//As funções abaixo são destinadas para interação com usuário
size_t pedirQuantidadeNumeros()
{
    size_t qtd;
    long temp = 0;
    puts("Quantos numeros deseja inserir: ");

    if(! scanf("%ld", &temp) ) // Isso é uma limpeza de teclado, caso o usuário digite qualquer tralha, o programa vai pedir o numero de novo
    {
        puts("Digitacao incorreta. Apenas numeros decimais sao permitidos");
        while(fgetc(stdin)!='\n');
        qtd = pedirQuantidadeNumeros();
    }
    if( temp <= 0)
    { // O numero de quantidade não pode ser menor igual a zero, o programa vai ficar pedindo até vir um válido
        puts("Digitacao incorreta. Apenas numeros maiores de zero sao permitidos");
        qtd = pedirQuantidadeNumeros();
    }
    qtd = (size_t) temp;
    return qtd;
}

double pedirNumero()
{
    double temp = 0.0;

    puts("# Digite um numero: ");
    if( ! scanf("%lf", &temp) ) // Limpeza de teclado, caso o usuário digite qualquer tralha, o programa vai ficar pedindo de novo até ter um input válido
    {
        puts("Digitacao incorreta. Apenas numeros decimais com ou sem ponto");
        while(fgetc(stdin)!='\n');
        temp = pedirNumero();
    }
    return temp;
}

main()
{
    size_t quantidade = pedirQuantidadeNumeros();
    double* valores = (double*) malloc(quantidade);
    size_t i;
    double maior_valor = 0.0;
    double menor_valor = 0.0;
    double media_aritmetica = 0.0;
    double media_geometrica = 0.0;
    double media_harmonica = 0.0;

    for( i = 0 ; i < quantidade ; i++) //Pede uma quantidade x de numeros, de acordo com o determinado pela variável "quantidade"
    {
        valores[i] = pedirNumero();
    }

    qsort(valores, quantidade, sizeof(double), compare); //Ordena em ordem crescente nosso array


   //Fazemos os calculos chamando as devidas funções
    maior_valor = valores[quantidade-1];
    menor_valor = valores[0];
    media_aritmetica = fazerMediaAritmetica(valores, quantidade);
    media_geometrica = fazerMediaGeometrica(valores, quantidade);
    media_harmonica = fazerMediaHarmonica(valores, quantidade);

    //Finalmente, imprimimos os valores
    printf("Maior valor: %lf \n", maior_valor);
    printf("Menor valor: %lf \n", menor_valor);
    printf("Media aritmetica: %.1lf \n", media_aritmetica);
    printf("Media geometrica: %.2lf \n", media_geometrica);
    printf("Media harmonica: %.3lf \n", media_harmonica);
}
