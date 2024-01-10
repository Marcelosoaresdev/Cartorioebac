#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string  (string � um conjunto de variaveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por criar o valor das strings (est� puxando do CPF para o arquivo)
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abriu e criou o arquivo ( "w" � para escrever no arquivo ) 
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abriu e Atualizou o arquivo ( "a" � para atualizar o arquivo )
	fprintf(file,", Nome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Sobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40]; //string s�o um conjunto de vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //solicita o CPF a ser deletado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)  //se o arquivo (file) for nulo...
	{
		printf("\nCPF de usu�rio n�o encontrado!.\n\n"); //informa que o cpf nao foi encontrado
		system("pause");
	}
		
	else // se o arquivo ( file) n�o for nulo...
	{
		remove(cpf); //remove o CPF informado
		printf("\nCPF de usu�rio deletado com sucesso!.\n\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //Definindo as vari�veis	
	int laco=1; //Definindo a variavel para laco
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: "); 
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;) //Para laco volta para laco (como se fosse um loop eterno, vai pra um e volta pro outro, que no caso � o mesmo)
		{
	
			system("cls");	//responsavel por limpar a tela
	
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n"); 
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d", &opcao); //Armazena a escolha do usu�rio //%d armazena vari�veis de numeros inteiros
	
			system("cls");//responsavel por limpar a tela
	
			switch(opcao) //iniio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es 
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
		
			}		
		}
	
	}
	else
		printf("Senha incorreta!");	
}    

