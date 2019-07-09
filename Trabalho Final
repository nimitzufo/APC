#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define MAX 100
#define MAXSIGLA 10
#define NUM 100


/*Síntese
Objetivo: Registrar cursos oferecidos à população carente do DF.
Entrada: Dados relacionados aos cursos e entradas para navegação do programa.
Saída: Menu de navegação e resposta às entradas do usuário. */

//Cadastro de registros nas structs de seu TF com validação
//funcionando corretamente;
//Listar todos os registros nas structs.

//Modificar os dados das structs.
//Apagar os dados das structs.
//Selecionar os dados específicos das structs.


//Definição do apelido REGISTRO
typedef struct Cadastro {
    int CNIC;
    char modCurso;
    char nomeCurso[NUM];
    char siglaEsc[MAXSIGLA];
    char modCursoExt[MAX];
} REGISTRO;

//Protótipo das funções
void menu_ui();
void regristraCursos();
void alteraCursos();
void listaCursos();
void consultaCursos();
void removeCursos();
int validaCNIC();
int validaModCurso();
int validaNomeCurso();

// cursosProfissionais.bin NOME DO ARQUIVO

//principal
int main(int argc, char const* argv[]) {
    setlocale(LC_ALL, "Portuguese");
    if (setlocale(LC_ALL, "Portuguese") == NULL) {
        puts("Unable to set locale");
    }
    FILE* cadastros;
    int opUI = 7;
    while (opUI) {
        menu_ui(&opUI);
        switch (opUI) {
        case 1:
            regristraCursos(&cadastros);
            break;
        case 2:
            alteraCursos();
            break;
        case 3:
        	listaCursos();
            break;
        case 4:
            consultaCursos();
            break;
        case 5:
            removeCursos(&cadastros);
            break;
        case 0:
            printf("Encerrando.\n");
            Sleep(2);
            break;
        default:
            printf("Valor inválido.\n");
            fflush(stdin);
            Sleep(1);
            break;
        }
    }
    //system("CLS");
    //imprimeDados();
    return 0;
}

//menu interativo
void menu_ui(int* opUI) {
    printf("Digite 1 para novo curso.\n");
    printf("Digite 2 para alterar dados do curso.\n");
    printf("Digite 3 para listar dados do(s) curso(s).\n");
    printf("Digite 4 para consultar dados dos cursos de uma modalidade específica.\n");
    printf("Digite 5 para remover dados de todos os cursos.\n");
    printf("Digite 0 para sair.\n");
    scanf(" %d", opUI);
}

//Sintese
//Objetivo: função validaCNIC(), faz a validação da entrada CNIC
//Parametros:
//Retorno: inteiro
int validaCNIC(int *CNIC){
	if (*CNIC < 100) {
		printf("CNIC deve ser maior que 100.\n");
		return 0;
    }
	int aux=0;
	int cursosCadastrados;
	int cnicARQ;
	REGISTRO cursoARQ[NUM];
	FILE* arquivo;
	
    arquivo = fopen("cursosProfissionais.bin", "rb");
	if(arquivo == NULL){
		printf("Não foi possível abrir o arquivo\n");
		return;
	}
	
	cursosCadastrados = fread(cursoARQ, sizeof(REGISTRO), NUM, arquivo);

	if(cursosCadastrados != 0){
        for (aux=0; aux<=cursosCadastrados; aux++){
            if(*CNIC == (cursoARQ+aux)->CNIC){
                printf("CNIC já cadastrado, por favor, digite outro\n");
                if(fclose(arquivo)){
			    	printf("Erro ao tentar fechar o arquivo\n");
					return;
				}
                return 0;
            }
        }
    }

    if(fclose(arquivo)){
    	printf("Erro ao tentar fechar o arquivo\n");
		return;
	}
    
    return 1;
}

//Sintese
//Objetivo: função validaModCurso(), faz a validação da entrada modCurso
//Parametros:
//Retorno: inteiro
int validaModCurso(REGISTRO *curso, char *modalidade){
	if (*modalidade == 'P' || *modalidade == 'p'){
		printf("Modalidade do curso: Presencial\n");
		strcpy((curso->modCursoExt), "Presencial");
		return 1;
	}
	if (*modalidade == 'D' || *modalidade == 'd'){
		printf("Modalidade do curso: Distância\n");
		strcpy((curso->modCursoExt), "Distância");
		return 1;
	}
	else{
		printf("Entrada inválida\n");
		return 0;
	}
}

//Sintese
//Objetivo: função validaNomeCurso(), faz a validação da entrada nomeCurso
//Parametros:
//Retorno: inteiro
int validaNomeCurso(char *nomeCurso){
	if (strlen(nomeCurso) < 5) {
        printf("Nome do curso é muito curto, deve ter mais de 5 caractéres.\n");
        return 0;
    }
    else
        return 1;
}

//Sintese
//Objetivo: função removeCursos(), apaga os dados dos cursos cadastrados.
//Parametros: arquivo
//Retorno: nenhum
void removeCursos(FILE* cadastros) {
    int exit = 1; 
	char conf;
    fflush(stdin);
    printf("Deseja apagar todos os dados cadastrados?(S/N)\n");
    scanf(" %c", &conf);
    while (exit) {
        if (conf == 's' || conf == 'S') {
            printf("Apagando cadastros do arquivo\n");
            Sleep(1);
            cadastros = fopen("cursosProfissionais.bin", "wb");
            if(cadastros == NULL){
				printf("Não foi possível abrir o arquivo\n");
				return;
			}
            if (fclose(cadastros)) {
                printf("Erro ao tentar fechar o arquivo");
            }
            exit = 0;
        }
        else if (conf == 'n' || conf == 'N') {
            exit = 0;
        }
    }
}

//Sintese
//Objetivo: função regristraCursos(), faz o cadastro dos cursos e salva no arquivo.
//Parametros: arquivo 'cadastros'
//Retorno: nenhum
void regristraCursos(FILE* cadastros){
	int cond = 1;
	REGISTRO curso;
	system("CLS");
    printf("Cadastro de um novo curso:\n");
    fflush(stdin);
    while (cond) {
        printf("Código Numérico de Identificação do Curso(CNIC):\n");
        scanf("%d", &(curso.CNIC));
        if(validaCNIC(&curso.CNIC)){
            cond = 0;
		}
    }
    cond = 1;
    fflush(stdin);
	while(cond){
		printf("Modalidade do curso. Presencial(P) ou Distância(D):\n");
		scanf(" %c", &(curso.modCurso));
		if(validaModCurso(&curso, &curso.modCurso)){
			cond = 0;
		}
	}
	int i;
	cond = 1;
    fflush(stdin);
	while(cond){
		printf("Nome do curso:\n");
        fgets(curso.nomeCurso, NUM, stdin);
        for (i = 0; i < strlen(curso.nomeCurso); i++) {
            if (curso.nomeCurso[i] == '\n') {
                curso.nomeCurso[i] = '\0';
            }
        }
		if(validaNomeCurso(curso.nomeCurso)){
			cond = 0;
		}
	}
	printf("Sigla da Escola:\n");
    fgets(curso.siglaEsc, MAXSIGLA, stdin);
    for (i = 0; i < strlen(curso.siglaEsc); i++) {
            if (curso.siglaEsc[i] == '\n') {
                curso.siglaEsc[i] = '\0';
            }
        }
    //abertura do arquivo
	cadastros = fopen("cursosProfissionais.bin", "a+b");
	if(cadastros == NULL){
		printf("Não foi possível abrir o arquivo\n");
		return;
	}    
    //escrita dos dados do curso no arquivo
    fwrite(&curso, sizeof(REGISTRO), 1, cadastros);
    if(fclose(cadastros)){
    	printf("Erro ao tentar fechar o arquivo\n");
		return;
	}
	system("CLS");
	printf("Cadastro realizado com sucesso!\n\n");
	cadastros = fopen("cursosProfissionais.bin", "rb");
	if(cadastros == NULL){
		printf("Não foi possível abrir o arquivo\n");
		return;
	}
	fseek(cadastros, sizeof(REGISTRO), SEEK_END);
	fread(&curso, sizeof(REGISTRO), 1, cadastros);
	printf("CNIC:                %d\n", curso.CNIC);
	printf("Nome do curso:       %s\n", curso.nomeCurso);
	printf("Sigla da escola:     %s\n", curso.siglaEsc);
	printf("Modalidade do curso: %s\n\n", curso.modCursoExt);
	if(fclose(cadastros)){
    	printf("Erro ao tentar fechar o arquivo\n");
		return;
	}
}

//Sintese
//Objetivo: função listaCursos(), faz a ordenação dos cursos cadastrados em ordem alfabética crescente ou decrescente.
//Parametros: none
//Retorno: nenhum
void listaCursos() {
	FILE* arquivo;
	REGISTRO cursoCadastradosARQ[NUM];
	REGISTRO swap;
	int cursosCadastrados;
	int exit = 1, aux = 0, aux2 = 0;
	char vOrder;
	fflush(stdin);
	//abertura do arquivo
    arquivo = fopen("cursosProfissionais.bin", "rb");
	if(arquivo == NULL){
		printf("Não foi possível abrir o arquivo\n");
		return;
	}
	//leitura do arquivo
	cursosCadastrados = fread(cursoCadastradosARQ, sizeof(REGISTRO), NUM, arquivo);
	
	while (exit) {
		printf("Ordem alfabética crescente(C) ou decrescente(D)?\n");
		scanf(" %c", &vOrder);
		if (vOrder == 'c' || vOrder == 'C') {
			for (aux = 0; aux < cursosCadastrados - 1; aux++) {
				for (aux2 = 0; aux2 < cursosCadastrados - aux - 1; aux2++) {
					if (strncmp(cursoCadastradosARQ[aux2].nomeCurso, cursoCadastradosARQ[(aux2)+1].nomeCurso, 3) > 0) {
						memcpy(&swap, &cursoCadastradosARQ[aux2], sizeof(cursoCadastradosARQ[aux2]));
						memcpy(&cursoCadastradosARQ[aux2], &cursoCadastradosARQ[aux2 + 1], sizeof(cursoCadastradosARQ[aux2 + 1]));
						memcpy(&cursoCadastradosARQ[aux2 + 1], &swap, sizeof(swap));
					}
				}
			}
			exit = 0;
		}
		else if (vOrder == 'd' || vOrder == 'D') {
			for (aux = 0; aux < cursosCadastrados - 1; aux++) {
				for (aux2 = 0; aux2 < cursosCadastrados - aux - 1; aux2++) {
					if (strncmp(cursoCadastradosARQ[aux2].nomeCurso, cursoCadastradosARQ[(aux2)+1].nomeCurso, 3) < 0) {
						memcpy(&swap, &cursoCadastradosARQ[aux2], sizeof(cursoCadastradosARQ[aux2]));
						memcpy(&cursoCadastradosARQ[aux2], &cursoCadastradosARQ[aux2 + 1], sizeof(cursoCadastradosARQ[aux2 + 1]));
						memcpy(&cursoCadastradosARQ[aux2 + 1], &swap, sizeof(swap));
					}
				}
			}
			exit = 0;
		}
	}
	
	system("CLS");
	int i = 0;
	printf("CNIC\tModalidade do curso\tNome do curso\t\tSigla da Escola\n");
	for (i = 0; i < cursosCadastrados; i++){
		printf("%d\t%s\t\t%s\t\t%s\n", cursoCadastradosARQ[i].CNIC,
	cursoCadastradosARQ[i].modCursoExt, cursoCadastradosARQ[i].nomeCurso, cursoCadastradosARQ[i].siglaEsc);
	}
	
	
	//fechamento do arquivo
	if(fclose(arquivo)){
    	printf("Erro ao tentar fechar o arquivo\n");
		return;
	}
}

//Sintese
//Objetivo: função consultaDados(), faz a listagem dos cursos cadastrados de certa modalidade em ordem alfabética crescente de sigla da escola.
//Parametros: ninguno
//Retorno: nenhum
void consultaCursos() {
	FILE* arquivo;
	REGISTRO cursoCadastradosARQ[NUM];
	REGISTRO swap;
	int cursosCadastrados;
	int exit = 1, aux = 0, aux2 = 0, aux3 = 0;
	char vOrder;
	char modC;
	int i = 0;
	fflush(stdin);
	
	//abertura do arquivo
    arquivo = fopen("cursosProfissionais.bin", "rb");
	if(arquivo == NULL){
		printf("Não foi possível abrir o arquivo\n");
		return;
	}
	
	//leitura do arquivo
	cursosCadastrados = fread(cursoCadastradosARQ, sizeof(REGISTRO), NUM, arquivo);
	
	//ordenação alfabética por sigla da escola
	for (aux = 0; aux < cursosCadastrados - 1; aux++) {
		for (aux2 = 0; aux2 < cursosCadastrados - aux - 1; aux2++) {
			if (strncmp(cursoCadastradosARQ[aux2].siglaEsc, cursoCadastradosARQ[(aux2)+1].siglaEsc, 1) > 0) {
				memcpy(&swap, &cursoCadastradosARQ[aux2], sizeof(cursoCadastradosARQ[aux2]));
				memcpy(&cursoCadastradosARQ[aux2], &cursoCadastradosARQ[aux2 + 1], sizeof(cursoCadastradosARQ[aux2 + 1]));
				memcpy(&cursoCadastradosARQ[aux2 + 1], &swap, sizeof(swap));
			}
		}
	}
		
	while (exit) {
		fflush(stdin);
		printf("Informe a modalidade que deseja pesquisar, Presencial(P) ou Distância(D)\n");
		scanf(" %c", &modC);
		system("CLS");
		if(modC == 'p' || modC == 'P') {
			printf("CNIC\tModalidade do curso\tNome do curso\t\tSigla da Escola\n");
			for (i = 0; i < cursosCadastrados; i++){
				if (cursoCadastradosARQ[i].modCurso == 'P' || cursoCadastradosARQ[i].modCurso == 'p'){
					printf("%d\t%s\t\t%s\t\t%s\n", cursoCadastradosARQ[i].CNIC,
			cursoCadastradosARQ[i].modCursoExt, cursoCadastradosARQ[i].nomeCurso, cursoCadastradosARQ[i].siglaEsc);
				}
			}
		}
		else if(modC == 'd' || modC == 'D') {
			printf("CNIC\tModalidade do curso\tNome do curso\t\tSigla da Escola\n");
			for (i = 0; i < cursosCadastrados; i++){
				if (cursoCadastradosARQ[i].modCurso == 'D' || cursoCadastradosARQ[i].modCurso == 'd'){
					printf("%d\t%s\t\t%s\t\t%s\n", cursoCadastradosARQ[i].CNIC,
			cursoCadastradosARQ[i].modCursoExt, cursoCadastradosARQ[i].nomeCurso, cursoCadastradosARQ[i].siglaEsc);
				}
			}
		}
		
		//fechamento do arquivo
		if(fclose(arquivo)){
	    	printf("Erro ao tentar fechar o arquivo\n");
	    	return;
		}
		exit = 0;
	}
}

//Sintese
//Objetivo: função alteraCursos(), faz a alteração de dados em cursos já cadastrados.
//Parametros: none
//Retorno: nenhum
void alteraCursos(){
	FILE* arquivo;
	int posicao, opt;
	REGISTRO cursoCadastradosARQ[NUM];
	int cursosCadastrados, cnic, aux, cond = 1;	
	REGISTRO curso;
	system("CLS");
	
	//abertura do arquivo
	arquivo = fopen("cursosProfissionais.bin", "r+b");
	if(arquivo == NULL){
		printf("Não foi possível abrir o arquivo\n");
		return;
	}
	
	//leitura do arquivo
	cursosCadastrados = fread(cursoCadastradosARQ, sizeof(REGISTRO), NUM, arquivo);
	if(!cursosCadastrados){
		printf("Não há cursos registrados no arquivo\n");
		return;
	}
	
	printf("\nDigite o CNIC do registro para alteração:\n");
	scanf("%d",&cnic);


    for (aux=0; aux<cursosCadastrados; aux++){
        if(cnic == cursoCadastradosARQ[aux].CNIC){
        	memcpy(&curso, cursoCadastradosARQ+aux, sizeof(REGISTRO));
        	posicao = aux;
        }
    }
	
	printf("CNIC\tModalidade do curso\tNome do curso\t\tSigla da Escola\n");
	printf("%d\t%s\t\t%s\t\t%s\n", curso.CNIC,
			curso.modCursoExt, curso.nomeCurso, curso.siglaEsc);
			
	int optAlt;		
	printf("Deseja alterar ou apagar o registro?\n(1)Alterar\n(2)Apagar\n");
	scanf(" %d", &optAlt);
	if(optAlt==1){
		printf("O que deseja alterar? \nModalidade do curso(1) \nNome do curso(2) \nSigla da Escola(3)\n");
		scanf("%d", &opt);		
		fflush(stdin);
		if(opt==1){
			while(cond){
			printf("Modalidade do curso. Presencial(P) ou Distância(D):\n");
			scanf(" %c", &(curso.modCurso));
			if(validaModCurso(&curso, &curso.modCurso)){
				cond = 0;
			}
			fseek(arquivo, posicao*sizeof(REGISTRO), SEEK_SET);
			fwrite(&curso, sizeof(REGISTRO), 1, arquivo);
			}
		}
		int i;
		cond = 1;
	    fflush(stdin);
	    if(opt==2){
	    	while(cond){
			printf("\nDigite o novo nome do curso:\n ");
	        fgets(curso.nomeCurso, NUM, stdin);
	        for (i = 0; i < strlen(curso.nomeCurso); i++) {
	            if (curso.nomeCurso[i] == '\n') {
	                curso.nomeCurso[i] = '\0';
	            }
	        }
			if(validaNomeCurso(curso.nomeCurso)){
				cond = 0;
			}
			fseek(arquivo, posicao*sizeof(REGISTRO), SEEK_SET);
			fwrite(&curso, sizeof(REGISTRO), 1, arquivo);
		}	
		}
		if(opt==3){
			printf("Nova sigla da Escola:\n");
		    fgets(curso.siglaEsc, MAXSIGLA, stdin);
		    for (i = 0; i < strlen(curso.siglaEsc); i++) {
		        if (curso.siglaEsc[i] == '\n') {
		            curso.siglaEsc[i] = '\0';
		        }
		    }
		    fseek(arquivo, posicao*sizeof(REGISTRO), SEEK_SET);
			fwrite(&curso, sizeof(REGISTRO), 1, arquivo);
		}
			
	    system("CLS");
		printf("Cadastro alterado com sucesso!\n\n");
	    //fechamento do arquivo
		if(fclose(arquivo)){
	    	printf("Erro ao tentar fechar o arquivo\n");
			return;
		}
	}		
	if(optAlt==2){
		//fechando o arquivo
		if(fclose(arquivo)){
	    	printf("Erro ao tentar fechar o arquivo\n");
			return;
		}
		for (aux=0; aux<cursosCadastrados; aux++){
			if(aux>=posicao){
				memcpy((cursoCadastradosARQ+aux), cursoCadastradosARQ+aux+1, sizeof(REGISTRO));
			}
		}
		arquivo = fopen("cursosProfissionais.bin", "wb");
		if(arquivo == NULL){
			printf("Não foi possível abrir o arquivo\n");
			return;
		}
		for(aux = 0; aux<cursosCadastrados-1;aux++){
			fwrite(cursoCadastradosARQ+aux, sizeof(REGISTRO), 1, arquivo);
		}
	    system("CLS");
		printf("Curso removido com sucesso!\n\n");
	    //fechamento do arquivo
		if(fclose(arquivo)){
	    	printf("Erro ao tentar fechar o arquivo\n");
			return;
		}
	}
}
