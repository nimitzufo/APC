//Sintese
//  Objetivo: identificar uma data a partir de seu valor sequencial no ano
//  Entradas: numero de dias e ano
//  Saidas: dia, mes e ano

#include <stdio.h>

int validaDias(int *pDias, int *bissexto);
int validaAno(int *pAno);
int verificaBissexto(int *pAno);
void calculaDiaMes(int *pDias, int *pAno, int *bissexto);

int main ()
{
 //Declaracoes
    int dias, ano, bissexto;
 //Instrucoes
    // Entrada
    scanf("%d %d", &dias, &ano);
    if(!validaAno(&ano)){
      printf("Entradas invalidas!");
      return 0;
	}
    else {
    	bissexto = verificaBissexto(&ano);
		if(!validaDias(&dias, &bissexto)){
			printf("Entradas invalidas!");
			return 0;
		}
		else
			calculaDiaMes(&dias,&ano,&bissexto);
	}
    return 0;
}

// ================ SUBPROGRAMAS ==============

// Objetivo: validar sequencial que corresponde aos dias
// Parâmetros: sequelcial de dias
// Retorno: sequencial valido
int validaDias(int *pDias, int *pBissexto)
{
	int maxDias;
	if (*pBissexto)
	  maxDias = 366;
	else
	  maxDias = 365;
    if((*pDias <= 0 ) || (*pDias > maxDias))
       return 0;
    else
	   return 1;
}

// Objetivo: validar ano informado
// Parâmetros: ano
// Retorno: ano valido
int validaAno(int *pAno)
{
    if((*pAno < 0) || (*pAno > 9999))
       return 0;
    else
	   return 1;
}

// Objetivo: validar sequencial que corresponde aos dias
// Parâmetros: sequelcial de dias
// Retorno: sequencial valido
int verificaBissexto(int *pAno)
{
    if(((*pAno % 400) == 0) || (((*pAno % 4) == 0) && ((*pAno % 100) != 0)))
       return 1;
    else
	   return 0;
}

// Objetivo: calcula dia e mes
// Parâmetros: sequelcial de dias e ano
// Retorno: sem retorno
void calculaDiaMes(int *pDias, int *pAno, int *bissexto)
{
	int dia, mes;
	if(*bissexto) { 
	 if(*pDias <= 31){ // Jan=31
	  dia = *pDias;
	  mes = 1;
	 } 
	 else if (*pDias <= 60){  // Fev=29
	  dia = *pDias - 31;
	  mes = 2;
	 }
	 else if (*pDias <= 91){  // Mar=31
	  dia = *pDias - 60;
	  mes = 3;
	 }
	 else if (*pDias <= 121){ // Abr=30
	  dia = *pDias - 91;	
	  mes = 4;	
	 }	  
	 else if (*pDias <= 152){ // Mai=31
	  dia = *pDias - 121;	
	  mes = 5;
	 } 	  
	 else if (*pDias <= 182){  // Jun=30
	  dia = *pDias - 152;	
	  mes = 6;
	 }	  
	 else if (*pDias <= 213){  // Jul=31
	  dia = *pDias - 182;	
	  mes = 7;
	 }	  
	 else if (*pDias <= 243){  // Ago=31
	  dia = *pDias - 213;	
	  mes = 8;
	 } 	  
	 else if (*pDias <= 274){  // Set=30
	  dia = *pDias - 243;	
	  mes = 9;
	 }
	 else if (*pDias <= 304){  // Out=31
	  dia = *pDias - 274;	
	  mes = 10;
	 }
	 else if (*pDias <= 335){  // Nov=30
	  dia = *pDias - 304;	
	  mes = 11;
	 }	  
	 else if (*pDias <= 366){  // Dez=31
	  dia = *pDias - 335;	
	  mes = 12;
	 }
    }
    else  // Ano nao bissexto
    { 
	 if(*pDias <= 31){ // Jan=31
	  dia = *pDias;
	  mes = 1;
	 } 
	 else if (*pDias <= 59){  // Fev=28
	  dia = *pDias - 31;
	  mes = 2;
	 }
	 else if (*pDias <= 90){  // Mar=31
	  dia = *pDias - 59;
	  mes = 3;
	 }
	 else if (*pDias <= 120){ // Abr=30
	  dia = *pDias - 90;	
	  mes = 4;	
	 }	  
	 else if (*pDias <= 151){ // Mai=31
	  dia = *pDias - 120;	
	  mes = 5;
	 } 	  
	 else if (*pDias <= 181){  // Jun=30
	  dia = *pDias - 151;	
	  mes = 6;
	 }	  
	 else if (*pDias <= 212){  // Jul=31
	  dia = *pDias - 181;	
	  mes = 7;
	 }	  
	 else if (*pDias <= 242){  // Ago=31
	  dia = *pDias - 212;	
	  mes = 8;
	 } 	  
	 else if (*pDias <= 273){  // Set=30
	  dia = *pDias - 242;	
	  mes = 9;
	 }
	 else if (*pDias <= 303){  // Out=31
	  dia = *pDias - 273;	
	  mes = 10;
	 }
	 else if (*pDias <= 334){  // Nov=30
	  dia = *pDias - 303;	
	  mes = 11;
	 }	  
	 else if (*pDias <= 365){  // Dez=31
	  dia = *pDias - 334;	
	  mes = 12;
	 }
	}
	// Saida final
    system("CLS");
	printf("%02d/%02d/%04d",dia,mes,*pAno);
}
