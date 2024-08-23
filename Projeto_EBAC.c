#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de string

int registrar() //Respons�vel por cadastrar usu�rios no sistema
{
	//inicio de cria��o de vari�veis.
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da cria��ode vari�veis.
    
    printf("CPF a ser cadastrado: \n"); // coleta informa��es do usu�rio
    scanf("%s", cpf); //armazena as informa��es coletadas.
    
    strcpy(arquivo, cpf); // copia os valores das strings
    FILE *file; // cria o arquivo
    
    file = fopen(arquivo, "w"); //abre o arquivo com a fun��o escrever
    fprintf(file, "CPF: %s\n", cpf); //sistema grava a palavra CPF junto com a string do usu�rio no nome cpf.
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado:\n ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "Nome: %s\n", nome);
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:\n");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "Sobrenome: %s\n", sobrenome);
    fclose(file);
    
    printf("Digite o Cargo do usu�rio:\n");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "Cargo: %s\n", cargo);
    fclose(file);
    
    system("pause");
}

int consultar() {
    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file; //acessa o arquivo
    file = fopen(cpf, "r"); //abre o arquivo com a fun��o ler.
    
    if (file == NULL) //se o nome do arquivo for nulo, apresenta a mensagem a baixo
	 {
        printf("Cadastro n�o localizado\n");
     }
	else //se o nome do arquivo for encontrado exibe as informa��es dele
		{
        printf("Informa��es do Usu�rio:\n");
        
        while (fgets(conteudo, 200, file) != NULL) //enquanto o conte�do do arquivo for diferente de nulo, mostra a string de conte�do.
		{
            printf("%s", conteudo);
        }
        fclose(file);
    }
    
    system("pause");
}

int excluir() 
{
	char cpf[40];
	
	printf ("Digite o CPF do usu�rio a ser deletado: \n");
	scanf ("%s", cpf);
	
	remove (cpf); //deleta o cpf digitado.
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("Usu�rio deletado ou n�o cadastrado. \n");	
		system ("pause");
	} 
}

int main() {
    int opcao = 0;
    int x = 1;
    for (x = 1; x == 1;) {
        system("cls");
        
        setlocale(LC_ALL, "Portuguese");
        
        printf("\t\t\tLista de alunos EBAC\t\n \n");
        printf("Selecione a op��o desejada\n\n");
        printf("\t1 - Registrar novo");
        printf("\t2 - Consultar aluno");
        printf("\t3 - Excluir cadastro\n\n\n");
        printf("\t4 - Fechar programa\n\n");
        printf("Op��o: ");
        
        scanf("%d", &opcao);
        
        system("cls"); //limpa a tela
        
        switch(opcao) {
            case 1:
                registrar(); // chama fun��es.
                break;
        
            case 2:
                consultar();
                break;
        
            case 3:
                excluir();
                break;
                
            case 4:
            	printf ("Obrigado por Utilizar nosso sotware.\n\n\n");
            	printf ("Software por Lucas Gazineu.");
            	return 0;
            	break;
        
            default:
                printf("Op��o n�o dispon�vel\n");
                system("pause");
                break;
        }
    }
}

