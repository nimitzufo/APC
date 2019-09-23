#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NRO_FUNC 500

/*Síntese
Objetivo: montar e mostrar ficha cadastral de funcionários, com bonificação para os jurássicos da empresa.
Entrada: nome, salário, tempo de serviço, departamento onde trabalha.
Saída: 	dados do funcionário(com bonificação ou não).
*/
 
typedef struct ficha {
	char nome[100];
	float sal;
	int tempo;
	char dep[100];
} CADASTRO;

void mostraCadastro(CADASTRO *func, int bonus, int count){
	char seguir;
	printf("Nome:         %s\n", func[count].nome);
	printf("Salario:      %.2f\n", func[count].sal);
	printf("Departamento: %s\n", func[count].dep);
	printf("Tempo:        %d\n", func[count].tempo);
	if(bonus)
		printf("O funcionario deve receber bonificacao de 10%% do salario pelo tempo na empresa.\n");
	printf("Aperte qualquer tecla para continuar\nAperte '0' para sair.");
	scanf(" %c", &seguir);
	if(seguir==0)
		exit(1);		
}


int main(void){
	CADASTRO func[NRO_FUNC];
	int aux=0, bonus=0;
	
	for(aux=0;aux<NRO_FUNC;aux++){
		printf("Cadastro nro %d\n", (aux+1));
		printf("Nome: ");
		scanf("%[^\n]", func[aux].nome);
		getchar();
		printf("Salario: ");
		scanf("%f", &func[aux].sal);
		getchar();
		printf("Departamento: ");
		scanf("%[^\n]", func[aux].dep);
		getchar();
		printf("Tempo na empresa(em anos): ");
		scanf("%d", &func[aux].tempo);
		if(func[aux].tempo>=10)
			bonus++;
		system("cls");
		mostraCadastro(func, bonus, aux);
		bonus=0;
	}
	return 0;
}
