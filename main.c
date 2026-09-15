#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TRI 31

struct Problemas {
    int aceito;
    int num_tent;
    int tempo;
};


struct Equipes {
    char nome_eqp[TRI];
    char nome_inst[TRI];
    char nome_aluno1[MAX];
    char nome_aluno2[MAX];
    char nome_aluno3[MAX];
    
    struct Problemas questoes[13];
    
    int total_feito;
    int total_tempo;
    
};

//função para tirar o \n do fgets

void remov_n(char *string){
    
    int tam = strlen(string);
    if(tam > 0 && string[tam - 1] == '\n'){
        string[tam - 1] = '\0';
    }
}


//funções para verificar se os nomes da equipe e da instituicao sao validos

int ver_nome_eqpeinst(char *nome){
    if(strlen(nome) <= 30) return 1;
    else{
        
        printf("O nome da equipe deve conter apenas 30 caracteres!\n");
        return 0;
    }
}

// função para validar tamanho do nome, caracteres e sobrenome
int validar_nome_aluno(char nome[]) {
    int tam = strlen(nome);

    if (tam < 4 || tam > 100) {
        printf("O nome deve ter entre 4 e 100 caracteres!\n");
        return 0;
    }

    int tem_espaco = 0;

    for (int i = 0; i < tam; i++) {
        char c = nome[i];

        if (c == ' ') tem_espaco = 1;

        if (!(isalpha(c) || c == ' ' || c == '-' || c == '\'')) {
            printf("O nome contém caracteres inválidos!\n");
            return 0;
        }
    }

    if (!tem_espaco) {
        printf("O nome deve conter sobrenome!\n");
        return 0;
    }

    return 1;
}

int comparar_eqp(char *s1, char *s2); 
int buscar_equipe(struct Equipes dados[], int qtd, char nome[]); 

int buscar_equipe(struct Equipes dados[], int qtd, char nome[]) {
    for (int i = 0; i < qtd; i++) {
        if (comparar_eqp(dados[i].nome_eqp, nome) == 0) {
            return i; 
        }
    }
    return -1; 
}

void registro_de_sub(struct Equipes dados[], int qtd){
    if (qtd == 0) {
        printf("\nNenhuma equipe cadastrada para registrar submissao.\n");
        return;
    }
    
    printf("\n===== Registro de Submissao =====\n");
    
    char nome[TRI];
    int busca;
    
    printf("Informe o nome da equipe: ");
    fgets(nome, TRI, stdin);
    remov_n(nome);
    
    busca = buscar_equipe(dados, qtd, nome);
    
    if(busca == -1){
        printf("\n\nEquipe não encontrada!\n");
        
        return;
    }
    
    char letra;
    
    printf("Digite a letra do problema correspondente: ");
    scanf(" %c", &letra);
    getchar();
    
    letra = toupper(letra);
    
    int bussola = letra - 'A';
    
    if(bussola < 0 || bussola > 12){
        printf("ERRO... Digite uma letra de A a M.\n\n");
        return;
    }
    
    if(dados[busca].questoes[bussola].aceito == 1){
        printf("Problema já resolvido!\n");
        return;
    }
    
    int tempo;
    
    char result[10];
    
    printf("Tempo de submissão: (em minutos, ex: 13): ");
    scanf("%d", &tempo);
    getchar();
    
    printf("Veredito: ");
    fgets(result, 10, stdin);
    remov_n(result);
    
    for(int i = 0; i < strlen(result); i++){
        result[i] = toupper(result[i]);
    }
    
    if(strcmp(result, "AC") == 0 || strcmp(result, "PE") == 0){
        dados[busca].questoes[bussola].aceito = 1;
        
        printf("Parabéns!!! Problema aceito!\n\n");
        
        dados[busca].questoes[bussola].tempo = tempo;
        dados[busca].total_feito++;
        
        int erros = dados[busca].questoes[bussola].num_tent * 5;
        
        dados[busca].total_tempo += (tempo + erros);
        
    }
    
    else{
        
        printf("Submissão '%s' rejeitada! Erro contabilizado!\n", result);
        dados[busca].questoes[bussola].num_tent++;
    }
    
    
}

struct Equipes cadastrarEquipe() {  // funcao p cadastrar equipe
    struct Equipes equipe;  // iniciando uma variavel p guardar os dados da eqp 
    


    
    while(1){
    printf("Nome da instituicao: ");
    fgets(equipe.nome_inst, TRI, stdin);
    remov_n(equipe.nome_inst);
    if(ver_nome_eqpeinst(equipe.nome_inst) == 1) break;
    }

    while (1) {
    printf("Nome do aluno 1: ");
    fgets(equipe.nome_aluno1, MAX, stdin);
    remov_n(equipe.nome_aluno1);

    if (validar_nome_aluno(equipe.nome_aluno1)) break;
}

    while (1) {
    printf("Nome do aluno 2: ");
    fgets(equipe.nome_aluno2, MAX, stdin);
    remov_n(equipe.nome_aluno2);

    if (validar_nome_aluno(equipe.nome_aluno2)) break;
}

    while (1) {
    printf("Nome do aluno 3: ");
    fgets(equipe.nome_aluno3, MAX, stdin);
    remov_n(equipe.nome_aluno3);

    if (validar_nome_aluno(equipe.nome_aluno3)) break;
}


    printf("\nCadastro realizado!\n");
    
    
    equipe.total_tempo = 0;
    equipe.total_feito = 0;
    
    for(int i = 0; i < 13; i++){
        equipe.questoes[i].aceito = 0;
        equipe.questoes[i].num_tent = 0;
        equipe.questoes[i].tempo = 0;
    }

    return equipe;
}

int comparar_eqp(char *s1, char *s2)
{
    char t1[TRI], t2[TRI];
    
    strcpy(t1, s1);
    strcpy(t2, s2);
    
    for(int i = 0; i < strlen(t1); i++){
        t1[i] = tolower(t1[i]);
    }
    for(int i = 0; i < strlen(t2); i++){
        t2[i] = tolower(t2[i]);
    }
    
    return strcmp(t1, t2);
}

void procurar_eqp(struct Equipes dados[], int qtd){
    printf("Digite o nome da instituição que deseja buscar: ");
    char pesquisa[TRI];
    fgets(pesquisa, TRI, stdin);
    remov_n(pesquisa);
    
    int encontrado = 0;
    
    struct Equipes rascunho[1000];
    
    for(int pos = 0; pos < qtd; pos++){
        if(comparar_eqp(dados[pos].nome_inst, pesquisa) == 0){
            
            rascunho[encontrado] = dados[pos];
            encontrado++;
        }
    }
    if(encontrado == 0){
        printf("Erro! instituição não encontrada...\n");
        return;
    }
    
    for(int i = encontrado - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(comparar_eqp(rascunho[j].nome_eqp, rascunho[j + 1].nome_eqp) > 0){
                struct Equipes temp = rascunho[j];
                rascunho[j] = rascunho[j+1];
                rascunho[j + 1] = temp;
            }
        }
    }
    printf("\nEquipes da %s\n", pesquisa);
    for(int i = 0; i < encontrado; i++){
    printf("\n_________________________________\n");
    printf("Equipe %s:\n", rascunho[i].nome_eqp);
    printf("Integrantes: %s, %s, %s.\n", 
               rascunho[i].nome_aluno1,
               rascunho[i].nome_aluno2, 
               rascunho[i].nome_aluno3);
    }
    printf("_________________________________\n");
}

//funçao do placar 
void mostrar_placar(struct Equipes dados[], int qtd) {

    if (qtd == 0) {
        printf("\nNenhuma equipe cadastrada para exibir placar.\n");
        return;
    }

    //ordenar sem alterar o original
    struct Equipes copia[1000];
    for (int i = 0; i < qtd; i++) {
        copia[i] = dados[i];
    }

    // ordenação
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            int troca = 0;

            // mais problemas resolvidos
            if (copia[j].total_feito < copia[j + 1].total_feito) {
                troca = 1;
            }
            //  menor tempo
            else if (copia[j].total_feito == copia[j + 1].total_feito &&
                     copia[j].total_tempo > copia[j + 1].total_tempo) {
                troca = 1;
            }

            if (troca) {
                struct Equipes aux = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = aux;
            }
        }
    }

printf("\n========== PLACAR ATUAL ==========\n");

    
    printf("Pos | Equipe | Feitos | Tempo | ");
    
 
    for(int k=0; k<13; k++) {
        printf("%c ", 'A'+k); 
    }
    printf("\n----------------------------------------------------\n");

    for (int i = 0; i < qtd; i++) {
        
        printf("%d | %s | %d | %d | ",
               i + 1,
               copia[i].nome_eqp,
               copia[i].total_feito,
               copia[i].total_tempo);
        for(int k=0; k<13; k++) {
            
            if(copia[i].questoes[k].aceito == 1) {
                printf("A "); 
            } 
            else if(copia[i].questoes[k].num_tent > 0) {
                printf("X "); 
            } 
            else {
                printf("- "); 
            }
        }
        printf("\n");
    }

    printf("===================================\n\n");
}


//exibir o menu 
int ver_menu() {
    printf("\nEscolha uma das opções abaixo:\n1- Cadastro de equipe\n");
    printf("2- Busca por instituição\n3- Registro de submissão\n");
    printf("4- Placar atual\n5- Sair\n\n");
    
    int menu;
    scanf("%d", &menu);
    getchar();
    
    return menu;
}

//realizar a opção do menu
void opcoes(struct Equipes dados[], int *qnt){
    do{
        int opcao = ver_menu();
        
        switch(opcao){
                            case 1: {
            char nome_temp[TRI];
        
            printf("\n===== Cadastro da equipe =====\n");
        
            // testa o Nome
            while (1) {
                printf("Nome da equipe: ");
                fgets(nome_temp, TRI, stdin);
                remov_n(nome_temp);
                
                if (ver_nome_eqpeinst(nome_temp)) break;
            }
                
            int indice = buscar_equipe(dados, *qnt, nome_temp);
             
            if (indice != -1) {
                char resp;
                printf("\nEquipe já cadastrada. Deseja atualizar os dados? (S/N): ");
                scanf(" %c", &resp);
                getchar();
        
                if (resp == 'S' || resp == 's') {
                    struct Equipes nova = cadastrarEquipe();
                    strcpy(nova.nome_eqp, nome_temp);
                    dados[indice] = nova;
                    printf("Equipe atualizada com sucesso!\n");
                } else {
                    printf("Atualização cancelada.\n");
                }
            }
            else {
                struct Equipes nova = cadastrarEquipe();
                strcpy(nova.nome_eqp, nome_temp);
        
                dados[*qnt] = nova;
                (*qnt)++;
                printf("Equipe cadastrada com sucesso!\n");
            }
        
            break;
        }

            
            case 2:
            procurar_eqp(dados, *qnt);
            break;
            
            case 3:
            registro_de_sub(dados, *qnt);
            break;
            
            case 4:
            mostrar_placar(dados, *qnt);
            break;
            
            case 5:
            return;
            break;
        }
    } while(1);
}

int main()
{
    struct Equipes dados[1000];
    int quantidade = 0;
    
    printf("Bem vindo ao sistema da Maratona de Programação da ABC!\n");
    
    opcoes(dados, &quantidade);
}


