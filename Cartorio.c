#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela criação de strings

int registro()
{
	
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digitar o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores dos string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser digitado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digitar o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado (apenas números): ");
	scanf("%s", cpf);	
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		fclose(file);
		printf("O usuario a ser deletado não existe. \n");
		system("pause");
	}
	
	else if (file != NULL)
	{
		fclose(file);
		printf("O arquivo foi deletado.\n");
		system("pause");//da tempo de puxar da tomada ainda kkkkkk
		remove (cpf);
	}
	
}

int main()
    {
   	int opcao=0; //Definindo variaveis
   	int laco=1;
    	
    for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	    printf("### Cartório da EABC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registra nomes\n");
	    printf("\t2 - Consutar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("opção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando de escolha do usuário
	
	    system("cls");
	
	    switch(opcao)
        {
	     case 1:
		 registro();
		 break;
		
		 case 2:
		 consulta();
		 break;
		
		 case 3:
		 deletar();
		 break;
		
		 default:
		 printf("essa opçao nao esta disponivel!\n");
		 system("pause");
		 break;
		}
  	}
    }
