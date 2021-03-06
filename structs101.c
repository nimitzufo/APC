#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*Síntese
Objetivo: obter maior e menor altura, média das alturas das mulheres e o nro de homens.
Entrada: strings(masculino, feminino), alturas de 10 pessoas.
Saída: maior e menor altura, media das alturas(mulhres), nro de homens
*/
 
typedef struct pessoa{
  char sexo[10];
  float altura;
} PESSOA;
 
void menAltura(PESSOA *vPessoa, float *menorAlt){
    int aux = 0;
    float tmp = vPessoa[0].altura;
    for(aux=1;aux<10;aux++){
        if(vPessoa[aux].altura<tmp)
            tmp=vPessoa[aux].altura;
    }
    *menorAlt = tmp;
}
void maiAltura(PESSOA *vPessoa, float *maiorAlt){
    int aux = 0;
    float tmp = vPessoa[0].altura;
    for(aux=0;aux<10;aux++){
        if(vPessoa[aux+1].altura>tmp)
            tmp=vPessoa[aux+1].altura;
    }
    *maiorAlt = tmp;
}  
 
void mediaAltMulheres(PESSOA *vPessoa, int nroMulheres, float *mediaAltFem){
    int aux=0;
    float soma = 0.00;
    for(aux=0;aux<10;aux++){
        if(strcmp(vPessoa[aux].sexo, "feminino")==0)
            soma+=vPessoa[aux].altura;
    }
    *mediaAltFem = soma/nroMulheres;
}
 
 main(){
    PESSOA vPessoa[10];
    float menorAlt, maiorAlt, mediaAltFem;
    int nroHomens=0, nroMulheres=0, aux=0;
   
    for(aux=0;aux<10;aux++){
        printf("Registro nro %d\n", aux);
        printf("Informe a altura: ");
        scanf("%f", &vPessoa[aux].altura);
        getchar();
        printf("Informe o sexo: ");
        scanf("%s", vPessoa[aux].sexo);
        if(strcmp(vPessoa[aux].sexo, "masculino")==0)
        	nroHomens++;
        if(strcmp(vPessoa[aux].sexo, "feminino")==0)
        	nroMulheres++;
        if(strcmp(vPessoa[aux].sexo, "masculino")!=0&&strcmp(vPessoa[aux].sexo, "feminino")!=0){
            printf("entrada invalida!");
            exit(1);     
        }
    }
     maiAltura(vPessoa, &maiorAlt);
     menAltura(vPessoa, &menorAlt);
     mediaAltMulheres(vPessoa, nroMulheres, &mediaAltFem);
     printf("Maior altura %.2f, menor altura %.2f, media de altura das mulheres %.2f, numero de homens %d", maiorAlt, menorAlt, mediaAltFem, nroHomens);
   
 }
