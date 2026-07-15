#include "estruturas.h"

//====================================================
// LISTA DUPLAMENTE ENCADEADA
//====================================================

void inicializarLista(ListaDupla *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserirFinal(ListaDupla *lista, Musica musica)
{
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));

    if(novo == NULL)
    {
        printf("Erro de memoria!\n");
        return;
    }

    novo->musica = musica;
    novo->prox = NULL;

    if(lista->inicio == NULL)
    {
        novo->ant = NULL;

        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        novo->ant = lista->fim;

        lista->fim->prox = novo;

        lista->fim = novo;
    }
}

void listarMusicas(ListaDupla *lista)
{
    Nodo *aux = lista->inicio;

    if(aux == NULL)
    {
        printf("\nNenhuma musica cadastrada.\n");
        return;
    }

    while(aux != NULL)
    {
        printf("\nTitulo : %s", aux->musica.titulo);
        printf("\nArtista: %s", aux->musica.artista);
        printf("\nDuracao: %d segundos", aux->musica.duracao);
        printf("\n--------------------------\n");

        aux = aux->prox;
    }
}

Nodo* buscarMusica(ListaDupla *lista, char titulo[])
{
    Nodo *aux = lista->inicio;

    while(aux != NULL)
    {
        if(strcmp(aux->musica.titulo, titulo) == 0)
        {
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}

void removerMusica(ListaDupla *lista, char titulo[])
{
    Nodo *remover = buscarMusica(lista, titulo);

    if(remover == NULL)
    {
        printf("\nMusica nao encontrada!\n");
        return;
    }

    // unico elemento
    if(remover == lista->inicio &&
       remover == lista->fim)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }

    // primeiro
    else if(remover == lista->inicio)
    {
        lista->inicio = remover->prox;

        lista->inicio->ant = NULL;
    }

    // ultimo
    else if(remover == lista->fim)
    {
        lista->fim = remover->ant;

        lista->fim->prox = NULL;
    }

    // meio
    else
    {
        remover->ant->prox =
            remover->prox;

        remover->prox->ant =
            remover->ant;
    }

    free(remover);

    printf("\nMusica removida com sucesso!\n");
}

int contarMusicas(ListaDupla *lista)
{
    int contador = 0;

    Nodo *aux = lista->inicio;

    while(aux != NULL)
    {
        contador++;

        aux = aux->prox;
    }

    return contador;
}

void liberarLista(ListaDupla *lista)
{
    Nodo *aux = lista->inicio;

    while(aux != NULL)
    {
        Nodo *temp = aux;

        aux = aux->prox;

        free(temp);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
}

//====================================================
// PILHA
//====================================================

void inicializarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

int isEmptyPilha(Pilha *pilha)
{
    return pilha->topo == NULL;
}

void push(Pilha *pilha, Musica musica)
{
    NodoPilha *novo =
        (NodoPilha*) malloc(sizeof(NodoPilha));

    if(novo == NULL)
        return;

    novo->musica = musica;

    novo->prox = pilha->topo;

    pilha->topo = novo;
}

Musica pop(Pilha *pilha)
{
    Musica vazia = {"","",0};

    if(isEmptyPilha(pilha))
        return vazia;

    NodoPilha *remover = pilha->topo;

    Musica musica = remover->musica;

    pilha->topo = remover->prox;

    free(remover);

    return musica;
}

Musica peekPilha(Pilha *pilha)
{
    Musica vazia = {"","",0};

    if(isEmptyPilha(pilha))
        return vazia;

    return pilha->topo->musica;
}

void mostrarHistorico(Pilha *pilha)
{
    NodoPilha *aux = pilha->topo;

    if(aux == NULL)
    {
        printf("\nHistorico vazio!\n");
        return;
    }

    printf("\n===== HISTORICO =====\n");

    while(aux != NULL)
    {
        printf("%s\n",
               aux->musica.titulo);

        aux = aux->prox;
    }
}

void liberarPilha(Pilha *pilha)
{
    while(!isEmptyPilha(pilha))
    {
        pop(pilha);
    }
}


//====================================================
// FILA
//====================================================

void inicializarFila(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

int isEmptyFila(Fila *fila)
{
    return fila->inicio == NULL;
}

void enqueue(Fila *fila, Musica musica)
{
    NodoFila *novo =
        (NodoFila*) malloc(sizeof(NodoFila));

    if(novo == NULL)
        return;

    novo->musica = musica;
    novo->prox = NULL;

    if(fila->fim == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->prox = novo;

        fila->fim = novo;
    }
}

Musica dequeue(Fila *fila)
{
    Musica vazia = {"","",0};

    if(isEmptyFila(fila))
        return vazia;

    NodoFila *remover =
        fila->inicio;

    Musica musica =
        remover->musica;

    fila->inicio =
        remover->prox;

    if(fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(remover);

    return musica;
}

Musica peekFila(Fila *fila)
{
    Musica vazia = {"","",0};

    if(isEmptyFila(fila))
        return vazia;

    return fila->inicio->musica;
}

void mostrarFila(Fila *fila)
{
    NodoFila *aux = fila->inicio;

    if(aux == NULL)
    {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\n===== FILA =====\n");

    while(aux != NULL)
    {
        printf("%s\n",
               aux->musica.titulo);

        aux = aux->prox;
    }
}

void liberarFila(Fila *fila)
{
    while(!isEmptyFila(fila))
    {
        dequeue(fila);
    }
}


//====================================================
// PLAYER
//====================================================

void inicializarPlayer(MusicPlayer *player)
{
    inicializarLista(
        &player->biblioteca);

    inicializarLista(
        &player->playlist);

    inicializarPilha(
        &player->historico);

    inicializarFila(
        &player->filaReproducao);

    player->musicaAtual = NULL;

    player->pausado = 0;
}

void cadastrarMusica(MusicPlayer *player)
{
    Musica musica;

    getchar();

    printf("Titulo: ");
    fgets(musica.titulo,
          TAM,
          stdin);

    musica.titulo[
        strcspn(
            musica.titulo,
            "\n")
    ] = '\0';

    printf("Artista: ");
    fgets(musica.artista,
          TAM,
          stdin);

    musica.artista[
        strcspn(
            musica.artista,
            "\n")
    ] = '\0';

    printf("Duracao: ");
    scanf("%d",
          &musica.duracao);

    inserirFinal(
        &player->biblioteca,
        musica);

    printf("\nMusica cadastrada!\n");
}

void adicionarNaPlaylist(MusicPlayer *player)
{
    char titulo[TAM];

    getchar();

    printf("Titulo da musica: ");

    fgets(titulo,
          TAM,
          stdin);

    titulo[
        strcspn(
            titulo,
            "\n")
    ] = '\0';

    Nodo *musica =
        buscarMusica(
            &player->biblioteca,
            titulo);

    if(musica == NULL)
    {
        printf("\nNao encontrada!\n");
        return;
    }

    inserirFinal(
        &player->playlist,
        musica->musica);

    printf(
        "\nAdicionada na playlist!\n");
}

void exibirPlaylist(MusicPlayer *player)
{
    listarMusicas(
        &player->playlist);
}

void reproduzirMusica(MusicPlayer *player)
{
    if(player->playlist.inicio == NULL)
    {
        printf("\nPlaylist vazia!\n");
        return;
    }

    if(player->musicaAtual == NULL)
    {
        player->musicaAtual =
            player->playlist.inicio;
    }

    printf("\nReproduzindo: %s\n",
           player->musicaAtual->musica.titulo);

    push(
        &player->historico,
        player->musicaAtual->musica
    );
}

void proximaMusica(MusicPlayer *player)
{
    if(player->musicaAtual == NULL)
    {
        printf("\nNenhuma musica em reproducao!\n");
        return;
    }

    if(player->musicaAtual->prox == NULL)
    {
        printf("\nFim da playlist!\n");
        return;
    }

    player->musicaAtual =
        player->musicaAtual->prox;

    printf("\nTocando agora: %s\n",
           player->musicaAtual->musica.titulo);

    push(
        &player->historico,
        player->musicaAtual->musica
    );
}

void musicaAnterior(MusicPlayer *player)
{
    if(player->musicaAtual == NULL)
    {
        printf("\nNenhuma musica em reproducao!\n");
        return;
    }

    if(player->musicaAtual->ant == NULL)
    {
        printf("\nInicio da playlist!\n");
        return;
    }

    player->musicaAtual =
        player->musicaAtual->ant;

    printf("\nTocando agora: %s\n",
           player->musicaAtual->musica.titulo);

    push(
        &player->historico,
        player->musicaAtual->musica
    );
}

void pausar(MusicPlayer *player)
{
    player->pausado = 1;

    printf("\nMusica pausada.\n");
}

void retomar(MusicPlayer *player)
{
    player->pausado = 0;

    printf("\nReproducao retomada.\n");
}

void shuffle(MusicPlayer *player)
{
    int total =
        contarMusicas(
            &player->playlist);

    if(total == 0)
    {
        printf("\nPlaylist vazia!\n");
        return;
    }

    int sorteio =
        rand() % total;

    Nodo *aux =
        player->playlist.inicio;

    for(int i = 0; i < sorteio; i++)
    {
        aux = aux->prox;
    }

    player->musicaAtual = aux;

    printf(
        "\nShuffle selecionou: %s\n",
        aux->musica.titulo
    );

    push(
        &player->historico,
        aux->musica
    );
}

void adicionarNaFila(MusicPlayer *player)
{
    char titulo[TAM];

    getchar();

    printf("Titulo da musica: ");

    fgets(
        titulo,
        TAM,
        stdin
    );

    titulo[
        strcspn(
            titulo,
            "\n"
        )
    ] = '\0';

    Nodo *musica =
        buscarMusica(
            &player->biblioteca,
            titulo
        );

    if(musica == NULL)
    {
        printf(
            "\nMusica nao encontrada!\n"
        );
        return;
    }

    enqueue(
        &player->filaReproducao,
        musica->musica
    );

    printf(
        "\nAdicionada na fila!\n"
    );
}

void tocarDaFila(MusicPlayer *player)
{
    if(
        isEmptyFila(
            &player->filaReproducao
        )
    )
    {
        printf(
            "\nFila vazia!\n"
        );

        return;
    }

    Musica musica =
        dequeue(
            &player->filaReproducao
        );

    printf(
        "\nReproduzindo da fila: %s\n",
        musica.titulo
    );

    push(
        &player->historico,
        musica
    );
}

void liberarPlayer(MusicPlayer *player)
{
    liberarLista(
        &player->biblioteca);

    liberarLista(
        &player->playlist);

    liberarPilha(
        &player->historico);

    liberarFila(
        &player->filaReproducao);
}