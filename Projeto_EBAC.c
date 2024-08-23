#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de string

int registrar() //Responsável por cadastrar usuários no sistema
{
	//inicio de criação de variáveis.
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criaçãode variáveis.
    
    printf("CPF a ser cadastrado: \n"); // coleta informações do usuário
    scanf("%s", cpf); //armazena as informações coletadas.
    
    strcpy(arquivo, cpf); // copia os valores das strings
    FILE *file; // cria o arquivo
    
    file = fopen(arquivo, "w"); //abre o arquivo com a função escrever
    fprintf(file, "CPF: %s\n", cpf); //sistema grava a palavra CPF junto com a string do usuário no nome cpf.
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
    
    printf("Digite o Cargo do usuário:\n");
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
    file = fopen(cpf, "r"); //abre o arquivo com a função ler.
    
    if (file == NULL) //se o nome do arquivo for nulo, apresenta a mensagem a baixo
	 {
        printf("Cadastro não localizado\n");
     }
	else //se o nome do arquivo for encontrado exibe as informações dele
		{
        printf("Informações do Usuário:\n");
        
        while (fgets(conteudo, 200, file) != NULL) //enquanto o conteúdo do arquivo for diferente de nulo, mostra a string de conteúdo.
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
	
	printf ("Digite o CPF do usuário a ser deletado: \n");
	scanf ("%s", cpf);
	
	remove (cpf); //deleta o cpf digitado.
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("Usuário deletado ou não cadastrado. \n");	
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
        printf("Selecione a opção desejada\n\n");
        printf("\t1 - Registrar novo");
        printf("\t2 - Consultar aluno");
        printf("\t3 - Excluir cadastro\n\n\n");
        printf("\t4 - Fechar programa\n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao);
        
        system("cls"); //limpa a tela
        
        switch(opcao) {
            case 1:
                registrar(); // chama funções.
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
                printf("Opção não disponível\n");
                system("pause");
                break;
        }
    }
}

