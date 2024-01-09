#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string  (string é um conjunto de variaveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por criar o valor das strings (está puxando do CPF para o arquivo)
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abriu e criou o arquivo ( "w" é para escrever no arquivo ) 
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abriu e Atualizou o arquivo ( "a" é para atualizar o arquivo )
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
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
	char cpf[40]; //string são um conjunto de variáveis
	
	printf("Digite o CPF do usuário a ser deletado: "); //solicita o CPF a ser deletado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)  //se o arquivo (file) for nulo...
	{
		printf("\nCPF de usuário não encontrado!.\n\n"); //informa que o cpf nao foi encontrado
		system("pause");
	}
		
	else // se o arquivo ( file) não for nulo...
	{
		remove(cpf); //remove o CPF informado
		printf("\nCPF de usuário deletado com sucesso!.\n\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //Definindo as variáveis	
	int laco=1; //Definindo a variavel para laco
	
	for(laco=1;laco=1;) //Para laco volta para laco (como se fosse um loop eterno, vai pra um e volta pro outro, que no caso é o mesmo)
	{
	
		system("cls");	//responsavel por limpar a tela
	
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //Armazena a escolha do usuário //%d armazena variáveis de numeros inteiros
	
		system("cls");//responsavel por limpar a tela
	
		switch(opcao) //iniio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		
		}
		

	
	}	
}    
