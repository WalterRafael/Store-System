/*construa um sistema educacional que controle os alunos, professores, cursos e disciplinas.
O sistema permitira as ações de cadastrar, consultar, alterar e excluir
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<io.h>
#include<dos.h>


using namespace std;   //para usar comandos C++ junto com o C

//declaração das estruturas de registros das base de dados

struct dadosAluno
       {
       char CodMatrA[20];    //Aluno.CodMatrA
       char NomeA[20];    //Aluno.NomeA
       int idadeA;        //Aluno.idadeA
       char CPFA[15];      //Aluno.CPFA
       char CursoA[30];    //Aluno.CursoA
	   int CodCurso;   //Aluno.CodCurso
       }Aluno;
       
       
 struct dadosProfessor
       {
    char CodProf[20];
 	char NomeP[20];  //string nomeP[];
 	int IdadeP;
 	char CPFP[15];
 	char CursoP[30]; 	
 	float Salario;
    char CodCurso[30];
    char CodDisc[30];
	 }Professor;
      
	      
 //Construir a estrutura de campos das tabelas Curso e Disciplina       
       
          
       //declarar os Arquivos(FILE) e seus auxiliares

       FILE *fAlunos;    // file  - Arquivo    * - Ponteiro dinÂmico
       FILE *fProfessores;
       FILE *fCursos;
       FILE *fDisciplinas;
       
       FILE *fAuxAlunos;
       FILE *fAuxProfessores;
       FILE *fAuxCursos;
       FILE *fAuxDisciplinas;
       
       int opc;//variável opção global para no programa principal e na rotina menu optarmos pela função a ser executada conforme seleção pelo usuário
//criar as funções de criação dos arquivos

/*Modos de abertura de arquivo texto
modo opera¸c˜oes indicador de posi¸c˜ao come¸ca

r leitura in´icio do arquivo
r+ leitura e escrita in´icio do arquivo
w escrita in´icio do arquivo
w+ escrita e leitura in´icio do arquivo
a (append) escrita final do arquivo*/



void cria_arqAlunos()
{//inicia o escopo da rotina cria arquivo de Alunos
     if ((fAlunos = fopen("Alunos.dat","a"))==NULL) //criando e abrindo o arquivo Alunos
     {
     	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de criacao do arquivo Alunos");
	return;
     }
     printf("\n Arquivo Alunos Criado com Sucesso!!!");
     fclose(fAlunos); //Fechando o arquivo Alunos
}//finaliza o escopo da rotina cria arquivo de Alunos


void cria_arqAuxAlunos(){
	 if((fAuxAlunos = fopen("AuxAlunos.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de criacao de arquivo AuxAlunos");  //cout<<"Erro de criacao de arquivo";
	return;
	}
	printf("\n Arquivo Alunos Auxiliar Criado com Sucesso!!!");
	fclose(fAuxAlunos);
}


//Construir a funçoes de criação dos demais arquivos principais e auxiliares
// Professor,Curso e Disciplina       



//Iniciar as operações com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Operações do arquivo Alunos

void cadastraAlunos() //cadastro do arquivo Alunos
{ char op; //variável opção
  system("cls");  //limpa tela
  int tamanho=0; // declaração da variáveltamanho para capturar a qtdide de registros cadastrdas
  fAlunos = fopen("Alunos.dat","r+");
  rewind(fAlunos);  //joga para o primeiro registro do arquivo - posição 0
  do{ //laço de repetição para contar a qtidade de registros do arquivo
  fread(&Aluno,sizeof(Aluno),1,fAlunos);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fAlunos)); //faça até o final do arquivo

  fseek(fAlunos,sizeof(Aluno),tamanho); //aponta para a posição do arquivo correspondente ao tamanho
  do
  {  system("cls");//limpa tela clearscreen
     //printf("\n Digite o nome do aluno:");// mostra na tela
     cout<<"\n Digite a matricula do Aluno:";//cout Comando de saída output
	 cin>>Aluno.CodMatrA; //cin  C - comando in  - input  - Comando de entrada
     cout<<"\n Digite o nome do Aluno:";
	 cin>>Aluno.NomeA; //cin  C - comando in  - input  - Comando de entrada
     printf("\n Digite a idade:");
     cin>>Aluno.idadeA;
     printf("\n Digite o CPF do aluno:");
     cin>>Aluno.CPFA;
     printf("\n Digite o codigo do Curso do Aluno:");
     cin>>Aluno.CodCurso;
     printf("\n Digite o Curso do Aluno:");
     cin>>Aluno.CursoA;
    
     tamanho=tamanho+fwrite(&Aluno,sizeof(struct dadosAluno),1,fAlunos); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o próximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a opção 
     op = toupper(op); //comando que coloca o caracter em maíusculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fAlunos);// fecha o arquivo Alunos
}

void cadastraProfessor() //cadastro do arquivo Alunos
{ char op; //variável opção
  system("cls");  //limpa tela clearScreen
  int tamanho=0; // declaração da variável tamanho para capturar a qtdide de registros cadastrdas
  fProfessores = fopen("Professores.dat","r+");//parametro r+ - read(ler) + write(escrever - gravar) 
  rewind(fProfessores);  //joga para o primeiro registro do arquivo - posição 0
  do{ //laço de repetição para contar a qtidade de registros do arquivo
  fread(&Professor,sizeof(Professor),1,fProfessores);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fProfessores)); //faça até o final do arquivo

  fseek(fProfessores,sizeof(Professor),tamanho); //aponta para a posição do arquivo correspondente ao tamanho(livre para gravação)
  do
  { 
   	 system("cls");//limpa tela clearscreen
     //printf("\n Digite o codigo do Professor:");// mostra na tela
     cout<<"\n Digite o código do Professor:";//cout Comando de saída output
	 cin>>Professor.CodProf; //cin  C - comando in  - input  - Comando de entrada
     cout<<"\n Digite o nome do Professor:";
	 cin>>Professor.NomeP; //cin  C - comando in  - input  - Comando de entrada
     printf("\n Digite a idade do Prof:");
     cin>>Professor.IdadeP;
     printf("\n Digite o CPF do Prof:");
     cin>>Professor.CPFP;
     printf("\n Digite o Curso do Prof:");
     cin>>Professor.CursoP;
     printf("\n Digite o Salario do Prof:");
     cin>>Professor.Salario;
     printf("\n Digite o Cod Curso do Prof:");
     cin>>Professor.CodCurso;
     printf("\n Digite o Cod da disciplina do Prof:");
     cin>>Professor.CodDisc;
        
     tamanho=tamanho+fwrite(&Professor,sizeof(struct dadosProfessor),1,fProfessores); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o próximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a opção 
     op = toupper(op); //comando que coloca o caracter em maíusculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fProfessores);// fecha o arquivo Professores
}

//Construir a funçoes de cadastro dos demais arquivos principais
// Curso e Disciplina       

//********************************************************

void consultaAlunos() //lista todos os registros do arquivo Alunos
{
     system("cls");//limpa a tela
     fAlunos=fopen("Alunos.dat","r"); //r - read  - Abrir o arquivo clientes para leitura - Consulta
     fseek(fAlunos,sizeof(struct dadosAluno),0);//aponta para o registro 0 do arquivo de Alunos

     while(fread(&Aluno,sizeof(Aluno),1,fAlunos)==1)
      {
     system("cls");//limpa a tela 	
     cout<<"\n Matricula do Aluno:"<<Aluno.CodMatrA;//cout Comando de saída output
	 cout<<"\n O Nome do Aluno:"<<Aluno.NomeA;
	 printf("\n Idade do aluno: %s ",Aluno.idadeA);
     printf("\n O CPF do aluno: %s",Aluno.CPFA);
     printf("\n O codigo do Curso do Aluno: %s",Aluno.CodCurso);
     printf("\n O Curso do Aluno: %s",Aluno.CursoA);
     printf("\n Digite enter para continuar\n");
	 getch();//pedi para teclar algo  - enter
      }
     printf("\n fim do arquivo");
     fclose(fAlunos); //fecha arquivo Alunos
     getch(); //espera ser teclado algo para continuar
}

void consulta_nomeAluno(){  //lista o registro selecionado pelo usuário do arquivo Alunos
     char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;  //variável com sinlizador(flag) para indicar que achou o cliente e pode listar os dados e parar a pesquisa no arquivo
     char op; //variável opção
	 	 
	system("cls"); //limpa a tela
	fAlunos=fopen("Alunos.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fAlunos,sizeof(struct dadosAluno),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Nome p/ Procura : "); //Pergunta ao usuário qual aluno deseja buscar na consulta
	cin>> nom_pro;//Usário Digita o nome do aluno a ser procurado
	       while(fread(&Aluno,sizeof(Aluno),1,fAlunos)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o aluno desejado
		    achou=strcmp(Aluno.NomeA,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do aluno do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do aluno do registro (Aluno.NomeA)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do Aluno para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
			 if(achou==0){ //nomes são iguais então achou o cliente desejado
		       system("cls");//limpa a tela 	
             cout<<"\n Matricula do Aluno:"<<Aluno.CodMatrA;//cout Comando de saída output
	         cout<<"\n O Nome do Aluno:"<<Aluno.NomeA;
             printf("\n Idade do aluno: %s ",Aluno.idadeA);
             printf("\n O CPF do aluno: %s",Aluno.CPFA);
             printf("\n O codigo do Curso do Aluno: %s",Aluno.CodCurso);
             printf("\n O Curso do Aluno: %s",Aluno.CursoA);
             printf("\n Digite enter para continuar\n");
        	 getch();//pedi para teclar algo  - enter
		       }}

		if(achou==1){ //varreu todo o arquivo e não encontrou o nome do Aluno para ser consultado
		    printf("\n Aluno não Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Aluno <S> ou <N>:");//lista na tela para pedir se o usuário deseja cadastrar este Aluno não encontrado
		    cin>>op;//lê a opção do usuário em cadastrar ou não
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
		    if (op=='S'){ //compara o valor da variável op para cadastrar ou não o novo Aluno
		    cadastraAlunos();//chama a função para cadstrar o novo Aluno
		    getch();}}}//espera algo a ser teclado e saia da função de consulta Aluno pelo nome


//Construir a funçoes de Consulta dos demais arquivos principais
// Professor, Curso e Disciplina 

/********************************************************************/


void alteraAluno(){ //Procura o registro selecionado pelo usuário do arquivo cliente para alteração
     char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a alteração e parar a pesquisa no arquivo
     int pos=0;//variável para incrementar a posição do registro dentro do arquivo Aluno
	system("cls");//limpa a tela
	fAlunos=fopen("Alunos.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fAlunos,sizeof(struct dadosAluno),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Nome do aluno p/ Procura : ");//Pergunta ao usuário qual Aluno deseja buscar na consulta
	cin>> nom_pro;//Usário Digita o nome do Aluno a ser procurado
	       while(fread(&Aluno,sizeof(Aluno),1,fAlunos)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o aluno desejado
		     achou=strcmp(Aluno.NomeA,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do aluno do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (aluno.NomeA)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do aluno para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
		    pos++;//incrementa a variável pos 1 a 1 para posicionar o próximo registro dentro do arquivo cliente
		   if(achou==0){ //nomes são iguais então achou o cliente desejado
		     cout<<"\n Matricula do Aluno:"<<Aluno.CodMatrA;//cout Comando de saída output
	         cout<<"\n O Nome do Aluno:"<<Aluno.NomeA;
             printf("\n Idade do aluno: %s ",Aluno.idadeA);
             printf("\n O CPF do aluno: %s",Aluno.CPFA);
             printf("\n O codigo do Curso do Aluno: %s",Aluno.CodCurso);
             printf("\n O Curso do Aluno: %s",Aluno.CursoA);
		   printf("_____________________________________________\n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Começa a pedir para o usuário os novos dados a ser alterados
		   cout<<"\n Digite a matricula do Aluno:";//cout Comando de saída output
		 cin>>Aluno.CodMatrA; //cin  C - comando in  - input  - Comando de entrada
     	 cout<<"\n Digite o nome do Aluno:";
	 	 cin>>Aluno.NomeA; //cin  C - comando in  - input  - Comando de entrada
     	 printf("\n Digite a idade:");
     	 cin>>Aluno.idadeA;
     	 printf("\n Digite o CPF do aluno:");
     	 cin>>Aluno.CPFA;
     	 printf("\n Digite o codigo do Curso do Aluno:");
     	 cin>>Aluno.CodCurso;
     	 printf("\n Digite o Curso do Aluno:");
     	 cin>>Aluno.CursoA;
	     fseek(fAlunos,pos*sizeof(struct dadosAluno),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posição pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Aluno,sizeof(struct dadosAluno),1,fAlunos);//Grava os dados alterados no registro certo dentro do arquivo
		    getch();}} //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    
		if(achou==1){ //varreu todo o arquivo e não encontrou o nome do Aluno para ser consultado
		    printf("\n Aluno não Cadastrado\n"); }//lista na tela  
		    
		fclose(fAlunos);}//fecha o arquivo Alunos e sai da função altera

//Construir a funçoes de Altera dos demais arquivos principais
// Professor, Curso e Disciplina 

/********************************************************************/


void excluiAluno() //Procura o registro selecionado pelo usuário do arquivo Aluno para exclusão
{
     char nom_pro[20];//variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclusão e parar a pesquisa no arquivo
	 int tamanhoaux=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de Alunos
	 int tamanhoAluno=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo de Alunos 
	
	system("cls");//linpa tela 
	fAlunos=fopen("Alunos.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fAlunos,sizeof(struct dadosAluno),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxAlunos();//chama a função para criar o arquivo auxiliar de Alunos
	fAuxAlunos=fopen("AuxAlunos.dat","r+");//abre o arquivo auxiliar de Alunos para leitura e escrita
	fseek(fAuxAlunos,sizeof(struct dadosAluno),0);//aponta por seguração ao registro 0(inicial) do arquivo auxiliar de alunos
    //começa a procura do registro a ser excluído no arquivo principal de alunos
	printf("\n Digite o Nome do Aluno p/ Procura : ");//Pergunta ao usuário qual aluno deseja buscar na consulta para ser excluído
	cin>> nom_pro;//Usário Digita o nome do aluno a ser procurado para exclusão
	      while(fread(&Aluno,sizeof(Aluno),1,fAlunos)==1){//laço de repetição para ler registro a registro do arquivo Alunos até encontrar o desejado
		     achou=strcmp(Aluno.NomeA,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do Aluno do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
	         if(achou==0){ //nomes são iguais então achou o cliente desejado
		      cout<<"\n Matricula do Aluno:"<<Aluno.CodMatrA;//cout Comando de saída output
	         cout<<"\n O Nome do Aluno:"<<Aluno.NomeA;
             printf("\n Idade do aluno: %s ",Aluno.idadeA);
             printf("\n O CPF do aluno: %s",Aluno.CPFA);
             printf("\n O codigo do Curso do Aluno: %s",Aluno.CodCurso);
             printf("\n O Curso do Aluno: %s",Aluno.CursoA);
		     printf("_____________________________________________\n");
		   getch(); //espera algo a ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{ //caso não entre no achou==0 então vai para esta parte do senão para transferir uma cópia do registro que não é o desejado a excluir 
		    //do arquivo clientes para o arquivo auxiliar do cliente
	         tamanhoaux=tamanhoaux+fwrite(&Aluno,sizeof(struct dadosAluno),1,fAuxAlunos);}}//grava o registro do arquivo cliente no arquivo aux Aluno um a um
             //cada registro gravado no aux a função fwrite gera 1 que é incerementado na variável tamanhoaux para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	        fclose(fAuxAlunos);//fecha arquivo AuxAluno
	        fclose(fAlunos);//fecha arquivo Alunos
	        remove("Alunos.dat");//remove o arquivo inicial de alunos totalmente pois já trasnferimos aqueles registros com excessão do a ser excluído
	        cria_arqAlunos();//chama a função para criar novamente o arquivo Alunos zerado
	        fAlunos=fopen("Alunos","r+");//Abre o novo arquivo Alunos para ler e gravar dados
	        fseek(fAlunos,sizeof(struct dadosAluno),0);//Aponta por segurança para o registro 0(inicial) do arquivo Alunos
	        fAuxAlunos=fopen("auxAlunos.dat","r+");//abre o arquivo AuxAlunos para transferir de volta os registros dos Alunos que não eram para ser excluídos
	        fseek(fAuxAlunos,sizeof(struct dadosAluno),0);//Aponta por segurança para o registro 0(inicial) do arquivo AuxAlunos
	while(fread(&Aluno,sizeof(Aluno),1,fAuxAlunos)==1) {//laço de repetição para trasnferir registros 1 a 1 do arquivo AuxAlunos para o arquivo Alunos principal
	  tamanhoAluno=tamanhoAluno+fwrite(&Aluno,sizeof(struct dadosAluno),1,fAlunos);}//grava o registro do arquivo AuxAlunos  no arquivo Alunos um a um
             //cada registro gravado no Alunos a função fwrite gera 1 que é incerementado na variável tamanhoAluno para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	fclose(fAuxAlunos);//fecha arquivo auxalunos
	remove("auxAlunos.dat");//remove completamente o arquivo auxAlunos pois já trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi excluído
	fclose(fAlunos);//fecha arqruivo Alunos.
	
	}//fecha a função de exclusão de registro de Alunos.

/*Construir a funçoes de Exclusão por registro dos demais arquivos principais
// Professor, Curso e Disciplina 

/********************************************************************/
	
	
void excl_arqAlunos(){//função para excluir completamente todo o arquivo de Alunos de uma vez só
    char op;//variável de segurança para optar em excluir mesmo ou não o arquivo de Alunos
    printf("\n Deleta Arquivo <S> ou <N>? ");//informação na tela para o usuário 
    cin>>op;//leitura da opção de deletar S ou não N o arquivo Alunos inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
	if (op=='S')//compara o valor da variável op para Apagar ou não arquivo Alunos
    {
      remove("Alunos.dat");//remove completamente o arquivo inteiro de Alunos
      printf("arquivo deletado");}//informa na tela para o usuário que deletou o arquivo
	  
   else{//senão optou por Não - N
      printf("\n Arquivo não foi deletado por sua opção");//informa na tela para o usuário que naõ deletou o arquivo
    getch();}}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a função de exclusão total do arquivo Alunos

/*Construir a funçoes de Exclusão arquivo inteiro dos demais arquivos principais
// Professor, Curso e Disciplina 

/********************************************************************/
void menu_principal()//criação da função Menu principal 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu Principal");//mostra na tela para o usuários as opções de Menu
  printf("\n");//pula linha
  printf("1 - Menu_Alunos \n");
  printf("2 - Menu_Professores  \n");
  printf("3 - Menu_Cursos \n");
  printf("4 - Menu_Disciplinas \n");
  printf("5 - Sair do Programa \n");
  printf("Digite uma opcao \n");//pede a opção via teclado do usuário
  cin>>opc;//lê a variável global opção do menu para chamar a funçao 
  switch(opc)//estrutura de composição de vários if
  {
  case 1:Menu_Alunos();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:Menu_Professores();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:Menu_Cursos();break;
  case 4:Menu_Disciplinas();break;
  case 5:exit(0);
  //função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu_principal


	

void menu_Alunos()//criação da função Menu de opções para os Alunos 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes de alunos");//mostra na tela para o usuários as opções de Menu
  printf("\n");//pula linha
  printf("1 - Cadastrar Alunos\n");
  printf("2 - Consultar Listar todos Alunos  \n");
  printf("3 - Consultar Por Nome de Aluno \n");
  printf("4 - Altera Registro do alunos \n");
  printf("5 - Excluir Registro de Aluno \n");
  printf("6 - Exclui Arquivo total de Alunos\n");
  printf("7 - Voltar ao Menu Principal \n");
  printf("Digite uma opcao \n");//pede a opção via teclado do usuário
  cin>>opc;//lê a variável global opção do menu para chamar a funçao 
  switch(opc)//estrutura de composição de vários if
  {
  case 1:cadastraAlunos();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaAlunos();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeAluno();break;
  case 4:alteraAlunos();break;
  case 5:excluiAlunos();break;
  case 6:excl_arqAlunos();break;
  case 7:menu_principal();break;//função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu

main()//programa prinipal para a chamada de inicial da rotina menu que chama todas as demais
{//inicia o escopo do programa
system("cls");//limpa tela
cria_arqAlunos();//chama a rotina de criação de arquivo Alunos para iniciar o programa

opc = 1;//inicializa a variável global opção do menu
  do//laço de repetição da rotina Menu enquanto não desejo sair do programa
  {
  menu_principal();//chama a rotina Menu_principal 
  }
  while (opc!=5);//Enquanto do laço de repetição até optar por opc igual 5 para sair do programa
}//finaliza o escopo do programa
