#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_PILHA 10



typedef struct autor{ // Lista encadeada simples ordenada - AUTOR
	int codigoAutor;
	char nomeAutor[25];
	struct autor *prox;
}autor;


typedef struct editora{ // Lista duplamente encadeada ordenada - EDITORA
	int codigoEditora;
	char nomeEditora[25];
	struct editora *prox;
	struct editora *ant;
}editora;




typedef struct livro{ // Pilha - LIVRO
	char isbn[25];
	char titulo[25];
	struct autor *p_autor;
	struct editora *p_editora;
	struct livro *bot;
}livro;

int pilhaPos = 0;

// Lista encadeada simples - AUTOR
autor* criarAutor(autor *novo);
void mostrarAutor(autor *p);
void liberarAutor(autor *p);
autor* localizarAutor(autor *p, char nomeAutor[]);
autor* localizarAutorPorCodigo(autor *inicio, int codigoAutor);
autor* cadastrarAutor(autor *inicio,int codigoAutor, char nomeAutor[]);
autor* pesquisaUltimoMenor(autor *inicio, autor *novo);
autor* removerAutor(autor *inicio, char nomeAutor[]);

// Lista duplamente encadeada - EDITORA
editora* criarEditora(editora *nova);
editora* cadastrarEditora(editora* li,int codigoEditora, char nomeEditora[]);
void mostrarEditora(editora *inicio);
editora* localizarEditora(editora *li, char nomeEditora[]);
editora* localizarEditoraPorCodigo(editora *li, int codigoEditora);
editora* removerEditora(editora *li, char nomeEditora[]);

// Pilha - LIVRO
livro* criarLivro();
livro* cadastrarLivro(livro *top,char isbnt[],char titulo[],autor *autor,editora *editora);
livro* empilharLivro(livro *top, livro *novo);
livro* desempilharLivro(livro *liv);
livro* excluirLivro(livro *top);
void mostrarLivro(livro *top);
livro* localizarLivroPorAutor(livro *pi,int codigoAutor);
livro* localizarLivroPorEditora(livro *pi,int codigoEditora);


void menu(autor *inicio, editora *liEdit, livro *top);
void lerTexto(char texto[], int tamanho);
char corfirma(char texto[]);
int lerIntPositivo(int *valor);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// ----------------------------autores ---------------------------------//
	
	autor *inicio=NULL;
	int i;
	
	inicio = cadastrarAutor(inicio, 1, "Jose de Alencar");
	inicio = cadastrarAutor(inicio, 6, "S");
	inicio = cadastrarAutor(inicio, 2, "Eça de Queiroz");
	inicio = cadastrarAutor(inicio, 3, "Monteiro Lobato");
	inicio = cadastrarAutor(inicio, 4, "Machado de Assis");
	inicio = cadastrarAutor(inicio, 5, "Jose Lins do Rego");	
	inicio = cadastrarAutor(inicio, 7, "A");

	//mostrarAutor(inicio);
	
	//inicio = removerAutor(inicio, "Jose de Alencar");
	
	//printf("\n\n");
	
	//mostrarAutor(inicio);
	
	//liberarAutor(inicio);
	
	// ---------------------------Editoras -----------------------//
	
	editora *liEdit=NULL;
	
	liEdit = cadastrarEditora(liEdit,1, "FTD");
	liEdit = cadastrarEditora(liEdit,2, "SOLL");
	liEdit = cadastrarEditora(liEdit,3, "SARAIVA");
	//liEdit = cadastrarEditora(liEdit,4, "FTD");
	
	//mostrarEditora(liEdit);
	
	//printf("\n\n");
	
	//liEdit = removerEditora(liEdit, "FTD");
	//mostrarEditora(liEdit);
	
	// ------------------------------Livros --------------------------//
	
	livro *top = NULL;
	//printf("\n\n");
	//top = cadastrarLivro(top, "999999900-0", "Topicos da Fisica", localizarAutor(inicio, "Jose Lins do Rego"), localizarEditora(liEdit, "SOLL" ));
	//top = cadastrarLivro(top, "999999900-0", "Topicos da Fisica", localizarAutor(inicio, "Jose Lins do Rego"), localizarEditora(liEdit, "SOLL" ));
	//top = cadastrarLivro(top, "999999900-0", "Topicos da Fisica", localizarAutor(inicio, "Jose Lins do Rego"), localizarEditora(liEdit, "SOLL" ));
	//top = cadastrarLivro(top, "123456789-1", "Matematica Elementar", localizarAutor(inicio, "Eça de Queiroz"), localizarEditora(liEdit, "SARAIVA" ));
	//top = cadastrarLivro(top, "999999900-0", "Topicos da Fisica", localizarAutor(inicio, "Jose Lins do Rego"), localizarEditora(liEdit, "SOLL" ));
	//top = cadastrarLivro(top, "999999900-0", "OS 3 Porquinhos", localizarAutor(inicio, "Monteiro Lobato"), localizarEditora(liEdit, "SOLL" ));

	//mostrarLivro(top);

	menu(inicio, liEdit, top);
	
	return 0;
}

void lerTexto(char texto[], int tamanho){
	
	int pos = 0;
	char c;

	c = getch();
	
	while (c != 13){
		printf("%c", c);
		texto[pos] = c;
		pos++;
		c = getch();
	}
	texto[pos] = '\0';
}



int lerIntPositivo(int *valor){
	
    int MAX=5, vetInt[MAX], pos=-1, v=0 ,i=0, mult=0, total=0;
    char c;
    
    c = getch();
    
    while ((c != 13) && (pos < MAX)){
    	
    	printf("%c", c);
    	
    	v = (c-48); 
    	
    	if (c == 8){ // backspace
    		pos--;
    		printf("%s%c", " ", c);
		}
		
		if (pos < -1){
			pos = -1;
		}
		
    	if ((v>=0) && (v<=9)){
    		vetInt[pos+1] = v;
    		pos++;
		}
		
		c = getch();
		
	}
	
	for(i=pos;i>=0;i--){
		
		if (mult == 0){
			total = vetInt[i];
			mult = 1;
		}
		else{
			total += (vetInt[i] * mult);
		}
		
		mult *= 10;
	}
	
	*valor = total;
}


void menu(autor *inicio, editora *liEdit, livro *top){
	
	int codigoAutor, codigoEditora;
	char nomeAutor[25], confirma[1], nomeEditora[25], isbn[25], titulo[25];

	autor *pAutor=NULL;
	editora *pEditora=NULL;
	
	int opcao=-1;
	
	while (opcao){
		
		system("cls");
		
		printf("\\============= Grenciamento de pilha de livros ==============\n\n");
		printf("\n 1 - Incluir Autor");
		printf("\n 2 - Excluir Autor");
		printf("\n 3 - Listar Autores");
		printf("\n 4 - Incluir Editora");
		printf("\n 5 - Excluir Editora");
		printf("\n 6 - Listar Editoras");
		printf("\n 7 - Incluir Livro");
		printf("\n 8 - Excluir Livro");
		printf("\n 9 - Listar Pilha de Livros");
		printf("\n 10 - Listar Todos");
		printf("\n 0 - Sair");
		
		printf("\n\nDigite uma opcao: ");
		scanf("%i", &opcao);
				
		if ((opcao<0) || (opcao>10)){
			printf(" \nOpcao inválida...\n");
			system("pause");
		}
		else{
			
			system("cls");
			
			switch (opcao){
				case 1:		
					printf("\n\n ====== Incluir Autor =======");
					printf("\n\n Digite o codigo: ");
					scanf("%i", &codigoAutor);
					printf("\n Digite o Nome: ");
					lerTexto(nomeAutor,25);
				    
					if (localizarAutorPorCodigo(inicio, codigoAutor) || localizarAutor(inicio, nomeAutor)){
						printf("\n\n Autor ja cadastrado...");
						system("pause");
					}
					else{
						inicio = cadastrarAutor(inicio, codigoAutor, nomeAutor);
						opcao = -1;
					}
					
					break;
				case 2:
					printf("\n\n ====== Exluir Autor =======");
					printf("\n\n Digite o codigo: ");
					scanf("%i", &codigoAutor);
					
	
							    
				    if (localizarLivroPorAutor(top, codigoAutor)){
				    	printf("Existe livro cadastrado com o autor! Exclusao nao permitida...");
						printf("\n");
						system("pause");
					}
					else{
						
						pAutor = localizarAutorPorCodigo(inicio, codigoAutor);
						
						if (!pAutor){
							printf("\n\n Autor nao cadastrado...");
							system("pause");
						}
						else{
							
							printf("\n\nDeseja excluir o autor: ( %s ) -  (s/n): ",pAutor->nomeAutor);
							scanf("%s",&confirma);
							if (!((strcmp(confirma,"s")!=0) && (strcmp(confirma,"S")!=0))){
								inicio = removerAutor(inicio, pAutor->nomeAutor);
								printf("\n\nAutor excluido com sucesso...\n\n");
								system("pause");
							}	
							opcao = -1;
						}
					}


					break;
				case 3:
					mostrarAutor(inicio);
					printf("\n\n");
					system("pause");
					break;
				case 4:
					printf("\n\n ====== Incluir Editora =======");
					printf("\n\n Digite o codigo: ");
					scanf("%i", &codigoEditora);
					printf("\n Digite o Nome: ");
					lerTexto(nomeEditora,25);
				    
					if (localizarEditoraPorCodigo(liEdit, codigoEditora) || localizarEditora(liEdit, nomeEditora)){
						printf("\n\n Editora ja cadastrada...");
						system("pause");
					}
					else{
						liEdit = cadastrarEditora(liEdit,codigoEditora, nomeEditora);
						opcao = -1;
					}
					break;
				case 5:
					printf("\n\n ====== Exluir Editora =======");
					printf("\n\n Digite o codigo: ");
					scanf("%i", &codigoEditora);
				    
				    
				    if (localizarLivroPorEditora(top, codigoEditora)){
				    	printf("Existe livro cadastrado com a Editora! Exclusao nao permitida...");
						printf("\n");
						system("pause");
						break;
					}
					
				    pEditora = localizarEditoraPorCodigo(liEdit, codigoEditora);
				    
					if (!pEditora){
						printf("\n\n Editora nao cadastrada...");
						system("pause");
					}
					else{
						printf("\n\nDeseja excluir a Editora: ( %s ) -  (s/n): ",pEditora->nomeEditora);
						scanf("%s",&confirma);
						if (!((strcmp(confirma,"s")!=0) && (strcmp(confirma,"S")!=0))){
							liEdit = removerEditora(liEdit, pEditora->nomeEditora);
							printf("\n\nEditora excluida com sucesso...\n\n");
							system("pause");
						}	
						opcao = -1;
					}

					break;
				case 6:
					mostrarEditora(liEdit);
					printf("\n\n");
					system("pause");
					break;
				case 7:
					
					if (pilhaPos >= MAX_PILHA){
						printf("\n\n ====== Incluir Livro =======");
						printf("\n\n A Pilha está cheia... nao e possivel incluir livro!!!\n");
						system("pause");
						break;
					}
					
					if (inicio==NULL){
						printf("\n\n ====== Incluir Livro =======");
						printf("A Lista de Autores está vazia... Não e possivel cadastrar livro...!!");
						system("pause");
						break;
					}
					
					if (liEdit==NULL){
						printf("\n\n ====== Incluir Livro =======");
						printf("A Lista de Editoras  está vazia... Não e possivel cadastrar livro...!!");
						system("pause");
						break;
					}
					
					mostrarAutor(inicio);
					printf("\n\n");
					
					mostrarEditora(liEdit);
					printf("\n\n");
					
					printf("\n\n ====== Incluir Livro =======");
					
					printf("\n\n Digite o ISBN ............: ");
					scanf("%s", &isbn);
					
					printf(" Digite o Titulo ..........: ");
					lerTexto(titulo,25);
					
					printf("\n Digite o codigo do Autor .: ");
					lerIntPositivo(&codigoAutor);
					
					while (!localizarAutorPorCodigo(inicio, codigoAutor)){
						printf("\n Autor não cadastradd");
						printf("\n Digite o codigo do Autor .: ");
						lerIntPositivo(&codigoAutor);
					}

					printf(" - %s", localizarAutorPorCodigo(inicio, codigoAutor)->nomeAutor);
					
					printf("\n Digite o codigo da Editora: ");
					lerIntPositivo(&codigoEditora);
					
					while (!localizarEditoraPorCodigo(liEdit, codigoEditora)){
						printf("\n\n Editora não cadastrada");
						printf("\n\n Digite o codigo da Editora: ");
						lerIntPositivo(&codigoEditora);
					}
					
					printf(" - %s", localizarEditoraPorCodigo(liEdit, codigoEditora)->nomeEditora);
					
					printf("\n\n Confirma a inclusao do livro (s/n): ");
					scanf("%s",&confirma);
					
					if (((strcmp(confirma,"s")==0) || (strcmp(confirma,"S")==0))){
						top = cadastrarLivro(top, isbn, titulo, localizarAutorPorCodigo(inicio, codigoAutor), localizarEditoraPorCodigo(liEdit, codigoEditora));
						if (top){
							printf("\n\nLivro incluido na Pilha com sucesso...\n\n");
						}
						else{
							printf("\n\nAtencao !!! Erro na inclusao do livro...\n\n");
						}
					}
					system("pause");
					break;
				case 8:
					if (pilhaPos == 0){
						printf("\nPilha Vazia... não existe livro para excluir!!!\n");
						system("pause");
					}
					else{
						printf("\n\n ====== Exluir Livro =======");
						printf(" \n\n Dados do Livro:\n");
						printf("\n ISBN   : %s", top->isbn);
						printf("\n Titulo : %s", top->titulo);
						printf("\n Autor  : %s", top->p_autor->nomeAutor);
						printf("\n Editora: %s", top->p_editora->nomeEditora);
						printf("\n\nDeseja excluir o Livro da posicao %d da Pilha (s/n): ",pilhaPos);
						scanf("%s",&confirma);
						if (!((strcmp(confirma,"s")!=0) && (strcmp(confirma,"S")!=0))){
							top = excluirLivro(top);
							printf("\n\nLivro excluido com sucesso...\n\n");
							system("pause");
						}	
					}
					
					break;
				case 9:
					mostrarLivro(top);
					printf("\n\n");
					system("pause");
					break;
				case 10:
					mostrarAutor(inicio);
					printf("\n\n");
					mostrarEditora(liEdit);
					printf("\n\n");
					mostrarLivro(top);
					printf("\n\n");
					system("pause");
					break;
			}
		}
	}	
	
	system("cls");
	
}

autor* criarAutor(autor *novo){
	novo =  (autor*) malloc(sizeof(autor));
	if (!novo){
		printf("Erro de alocacao de memoria...");
		system("pause");
	}
	return novo;
}			

autor* cadastrarAutor(autor *inicio, int codigoAutor, char nomeAutor[]){
	
	autor *novo=NULL, *menor=NULL, *link=NULL;
	novo = criarAutor(novo);
	
	novo->codigoAutor = codigoAutor;
	strcpy(novo->nomeAutor, nomeAutor);
 	novo->prox=NULL;
	
	if (inicio==NULL){  // se lista vazio
		inicio = novo;
	}
	else{	
		if (localizarAutor(inicio, novo->nomeAutor)==NULL){
			menor = pesquisaUltimoMenor(inicio, novo);
			if (menor==NULL){  // insere no inicio
					novo->prox = inicio;
					inicio = novo;
			}		
			else{
				if  (menor->prox==NULL)	{ // insere no final
					menor->prox = novo;	
				}
				else{ // insere no meio
					link = menor->prox;
					menor->prox = novo;
					novo->prox = link;
				}
				
			}
	
		}
	}
	
	return inicio;
}

void mostrarAutor(autor *li){
	printf("\n===============  Autores - Lista ligada simples e ordenada por Nome =================\n\n");
		printf("<<INICIO>> ");
	while(li){
		printf("%i-%s -> ",li->codigoAutor, li->nomeAutor);
		li = li->prox;
	} 
	printf("<<FIM>>");
}

void liberarAutorp(autor *p){ // não recursiva
	autor *atual=NULL, *prox=NULL;
	atual = p;
	while (atual){
		prox = atual->prox;
		free(atual);
		atual = prox;
	}
		
}

void liberarAutor(autor *p){ // recursiva
	if (p){
		liberarAutor(p->prox);
		free(p);
	}		
}

autor* localizarAutor(autor *inicio, char nomeAutor[]){
	
	if (inicio==NULL){
		return NULL;
	}
	
	autor *aux=NULL;
	aux = inicio;
	
	while ((strcmp(aux->nomeAutor, nomeAutor)!=0) && (aux->prox!=NULL)){
		aux = aux->prox;
	}
	
	if ((aux->prox==NULL) && (strcmp(aux->nomeAutor, nomeAutor)!=0)) return NULL;
	
	return aux;	
}

autor* localizarAutorPorCodigo(autor *inicio, int codigoAutor){
	
	if (inicio==NULL){
		return NULL;
	}
	
	autor *aux=NULL;
	aux = inicio;
	
	while ((aux->codigoAutor!=codigoAutor) && (aux->prox!=NULL)){
		aux = aux->prox;
	}
	
	if ((aux->prox==NULL) && (aux->codigoAutor!=codigoAutor)) return NULL;
	
	return aux;	
}

autor* pesquisaUltimoMenor(autor *inicio, autor *novo){	

	if (inicio==NULL){
		return NULL;
	}

    autor *anterior=NULL, *atual=NULL, *prox=NULL;
    
    atual = inicio;
    prox = inicio->prox;
    
    while (strcmp(novo->nomeAutor, atual->nomeAutor)>0){
    	if (prox==NULL) return atual;
    	anterior = atual;
		atual = prox;
    	prox = prox->prox;
    	    
	}
	
	return anterior;
}

autor* removerAutor(autor *li, char nomeAutor[]){
	
	autor *atual=NULL, *menor=NULL;
	
	if (li==NULL){ // lista vazia
	    printf("Lista Vazia, autor não cadastrado...");
	    system("pause");
	    return li;
	}
	
	atual = localizarAutor(li, nomeAutor);
	
	if ( atual != NULL){ // existe
		
		menor  = pesquisaUltimoMenor(li, atual);
		
		if (menor==NULL){ // é o primeiro
			li = li->prox;
		}else{
			if (atual->prox==NULL){ // é o ultimo
				menor->prox = NULL;
			}
			else{
				menor->prox = atual->prox;
			}
		}
		
		free(atual);
	}
	

	
	return li;
}

//-----------------------------------------------------------------------Editora

editora* criarEditora(editora *nova){	
	nova = (editora*) malloc(sizeof(editora));
	if (!nova){
		printf("Erro de alocacao de memoria...");
		system("pause");
	}
	return nova;
}

editora* cadastrarEditora(editora* li, int codigoEditora, char nomeEditora[]){
	
	editora *nova=NULL, *inicio=NULL, *aux=NULL;
	
	
	if (li!=NULL){
		if (localizarEditora(li, nomeEditora)!=NULL){
			printf("\nA Editora %s, ja está cadastrada...", nomeEditora);
			system("pause");
			return li; // já está cdastrado
		}		
	}
		 
	inicio = li;
	 
	nova = criarEditora(nova);
	 
	if (nova!=NULL){
	 	
	 	nova->codigoEditora = codigoEditora;
	 	strcpy(nova->nomeEditora, nomeEditora);
	 	nova->ant = NULL;
	 	nova->prox = NULL;
	 	
 
		
		if (inicio==NULL){ // é vazia
		    return nova;
		}
		else{
			
			while ((strcmp(nova->nomeEditora, li->nomeEditora) > 0) && (li->prox!=NULL)){
 				li = li->prox;
			}
			
			if ((li==inicio) && (strcmp(nova->nomeEditora, li->nomeEditora) < 0)) { // no inicio
				inicio->ant = nova;
				nova->prox = inicio;
				return nova;			
			}
			else{
				if ((li->prox==NULL) && (strcmp(nova->nomeEditora, li->nomeEditora) > 0)) { // no fim
					li->prox = nova;
					nova->ant = li;
					return inicio;
				}
				else{ // no meio
				    aux = li->ant;
				    aux->prox = nova;
				    nova->ant = li->ant;
					nova->prox = li;			
					li->ant = nova;
					return inicio;
				}
			}
		}
	 }
}

void mostrarEditora(editora *li){
	printf("\n=============  Editoras - Lista Duplamente ligada e ordenada por Nome ===============\n\n");
	printf("<<INICIO>> ");
	while(li){
		printf("%i-%s <-> ",li->codigoEditora, li->nomeEditora);
		li = li->prox;
	} 
	printf("<<FIM>>");
}

int mostrarEditoraR(editora *li){ // recursiva --- inverte a ordem de apresentação

	if (li){
		mostrarEditora(li->prox);
		printf(" { %s } ",li->nomeEditora);
	}

	return 0;
}

editora* localizarEditora(editora *li, char nomeEditora[]){
	
	if (li==NULL){
		return NULL;
	}
	
	while((strcmp(li->nomeEditora, nomeEditora) != 0) && (li->prox!=NULL)){
		li = li->prox;
	}
	
	if (strcmp(li->nomeEditora, nomeEditora) == 0){
		return li;
	}
	
	return NULL;
}

editora* localizarEditoraPorCodigo(editora *li, int codigoEditora){
	
	if (li==NULL){
		return NULL;
	}
	
	while((li->codigoEditora != codigoEditora) && (li->prox!=NULL)){
		li = li->prox;
	}
	
	if (li->codigoEditora == codigoEditora){
		return li;
	}
	
	return NULL;
}

editora* removerEditora(editora *li, char nomeEditora[]){
	
	editora *aux=NULL, *ant=NULL, *pos=NULL;
	
	aux = localizarEditora(li,nomeEditora);
	
	if (aux==NULL){		
		printf("\nA Editora ( %s ), não está cadastrada...", nomeEditora);
		system("pause"); 	
	}
	else{
		
		if (aux->ant == NULL){ // inicio
			if (aux->prox == NULL){
				free(aux);
				li = NULL;
			}
			else{
				aux = aux->prox;
				free(aux->ant);
				aux->ant = NULL;
				li = aux;
			}

		}
		else{
			if (aux->prox == NULL){ // final
				aux = aux->ant;
				free(aux->prox);
				aux->prox = NULL;	
			}
			else{ // meio
			    ant = aux->ant;
			    pos = aux->prox;
			    free(aux);
				ant->prox = pos;
				pos->ant = ant;								
			}
		}
	}
	
	return li;
	
}

//-----------------------------------------------------------------------Livros

livro* criarLivro(livro *novo){	
	novo = (livro*) malloc(sizeof(livro));
	if (!novo){
		printf("Erro de alocacao de memoria...");
		system("pause");
	}
	return novo;
}

livro* cadastrarLivro(livro* top,char isbn[13],char titulo[],autor* autor,editora* editora){
	
	livro *novo=NULL;
	
	novo = criarLivro(novo);
	
	strcpy(novo->isbn, isbn);
	strcpy(novo->titulo, titulo);
	novo->p_autor = autor;
	novo->p_editora = editora;	

	top = empilharLivro(top, novo);
    
	return top;
}

livro* empilharLivro(livro *top, livro *novo){
	
	if (pilhaPos == MAX_PILHA){
		printf("\n Pilha cheia... não é mais possivel empilhar!!!\n");
		system("pause");
		return top;
	}
	
	novo->bot = top;
	top = novo;
	pilhaPos++;
	
	return top;
}

void mostrarLivro(livro *top){
	
	char isbn[13];
	int ordem;
	
	printf("\n===============================  Livros - Pilha =====================================\n\n");
	printf("                          >>>>>>>>TOPO DA PILHA<<<<<<<<\n");
	printf("\n%-7s %-13s   %-20s   %-20s     %-20s", "Ordem",  "nISBN", "Titulo", "Autor", "Editora");
	ordem = pilhaPos;
	while (top){
		strcpy(isbn, top->isbn);
		printf("\n  %-5d %-13s   %-20s   %d-%-20s   %d-%-20s", ordem--, top->isbn, top->titulo, top->p_autor->codigoAutor ,top->p_autor->nomeAutor, top->p_editora->codigoEditora ,top->p_editora->nomeEditora);
		top = top->bot;
	}
}

livro* localizarLivroPorAutor(livro *pi,int codigoAutor){
	
	if (pi==NULL){
		return NULL;
	}
	
	while ((pi->p_autor->codigoAutor!=codigoAutor) && (pi->bot!=NULL)){
		pi = pi->bot;
	}
	
	if (pi->p_autor->codigoAutor==codigoAutor){
		return pi;
	}
	
	return NULL;
}

livro* localizarLivroPorEditora(livro *pi,int codigoEditora){
	
	if (pi==NULL){
		return NULL;
	}
	
	while ((pi->p_editora->codigoEditora!=codigoEditora) && (pi->bot!=NULL)){
		pi = pi->bot;
	}
	
	if (pi->p_editora->codigoEditora==codigoEditora){
		return pi;
	}
	
	return NULL;
}

livro* excluirLivro(livro *top){
	livro *aux=NULL;
	aux = top;
	top = top->bot;
	free(aux);
	pilhaPos--;
	return top;
}


