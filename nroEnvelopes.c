#include <stdio.h>

/*Síntese:
Objetivo: Determinar nro max de envelopes para promocao
Entradas: quantidade de rótulos, número de balas que a SBC produz/especificando cada rótulo
Saídas: nro máximo de envelopes a se enviar*/

int main(){
	int nroRotulos, tiposBala, aux=0, svRot=0, stipBala=0;
	scanf("%d %d", &nroRotulos, &tiposBala);
	int vRotulos[nroRotulos];
	for(aux=0;aux<nroRotulos;aux++){
		scanf("%d", &vRotulos[aux]);
	}
	int maxEnvelopes;
	//somar elementos do vRotulos, cada envelope estará completo
	//quando a (soma de vRotulos)/Somatório(tiposBala)==1, add 1 envelope a cada vez 
	for(aux=0;aux<nroRotulos;aux++)
		svRot+= *(vRotulos+aux);
	aux=0;	
	for(aux=0;aux<(tiposBala+1);aux++)
		stipBala+=aux;
	maxEnvelopes = svRot/stipBala;	
	
	printf("%d\n", maxEnvelopes);
	
	return 0;
	
}
