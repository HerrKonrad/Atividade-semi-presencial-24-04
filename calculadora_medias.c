#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Algoritmos e Programa��o - 2021/1
 * Atividade Semipresencial 24/4
 * Nome: Arthur Konrad
 * Aten��o: Este c�digo � apenas um desafio pessoal para tentar implementar uma forma de calcular com uma quantidade quase ilimitada de numeros
 * sem precisar mexer no c�digo. Farei a atividade da forma normal com meu grupo.
 */


//Esta fun��o n�o � minha. Ela serve para ordenar o array de double
static int compare (const void * a, const void * b)
{
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

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

    resultado = novaQuantidade > 0  ?  (double) novaQuantidade / (double) soma   : 0.0;
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
    resultado =  novaQuantidade > 0 ? pow(multiplicacao, (double)1.0 / (double) novaQuantidade) : 0;
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

size_t pedirQuantidadeNumeros()
{
    size_t qtd;
    puts("Quantos numeros deseja inserir: ");
    scanf("%zu", &qtd);
    return qtd;
}

main()
{
    size_t quantidade = pedirQuantidadeNumeros();
    size_t  ler_quantidade;
    double valores[quantidade];
    size_t i;
    double maior_valor = 0.0;
    double menor_valor = 0.0;
    double media_aritmetica = 0.0;
    double media_geometrica = 0.0;
    double media_harmonica = 0.0;

    for( i = 0 ; i < quantidade ; i++) //Pede uma quantidade x de numeros, de acordo com o determinado pela vari�vel "quantidade"

    {
        double temp = 0.0;
        puts("# Digite um numero: ");
        scanf("%lf", &temp);
        valores[i] = temp;
    }

    qsort(valores, quantidade, sizeof(double), compare); //Ordena em ordem crescente nosso array

    maior_valor = valores[quantidade-1];
    menor_valor = valores[0];
    media_aritmetica = fazerMediaAritmetica(valores, quantidade);
    media_geometrica = fazerMediaGeometrica(valores, quantidade);
    media_harmonica = fazerMediaHarmonica(valores, quantidade);

    printf("Maior valor: %lf \n", maior_valor);
    printf("Menor valor: %lf \n", menor_valor);
    printf("%Media aritmetica: %.1lf \n", media_aritmetica);
    printf("Media geometrica: %.2lf \n", media_geometrica);
    printf("Media harmonica: %.3lf \n", media_harmonica);
}