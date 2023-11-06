#include <stdio.h> //biblioteca com comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string



int registro ()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fprintf(file, sobrenome);
	fclose(file);
	
	printf("Dgite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fprintf(file,cargo);
	fclose(file);
	system("pause");

}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("não foi possivel abrir o arquivo, não localizado !. \n");
	}
	
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
		
		system("pause");
	}
	
	
}

int deletar()
{
	printf("Voce escolheu deletar os nomes\n");
		system("pause");
}

int main ()
{
	int opcao=0; //Definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
		printf("### Cartiorio da EBAC###)\n\n"); //inicio do menu
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
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
				printf("Essa opção não está disponivel!\n");//fim da seleção
			system("pause");
			break;

	
	}
	
	
}

}
