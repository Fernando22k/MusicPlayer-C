#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 100

//====================================================
// MUSICA
//====================================================

typedef struct
{
    char titulo[TAM];
    char artista[TAM];
    int duracao;

} Musica;

//====================================================
// LISTA DUPLAMENTE ENCADEADA
//====================================================

typedef struct Nodo
{
    Musica musica;

    struct Nodo *ant;
    struct Nodo *prox;

} Nodo;

typedef struct
{
    Nodo *inicio;
    Nodo *fim;

} ListaDupla;

//====================================================
// PILHA
//====================================================

typedef struct NodoPilha
{
    Musica musica;

    struct NodoPilha *prox;

} NodoPilha;

typedef struct
{
    NodoPilha *topo;

} Pilha;

//====================================================
// FILA
//====================================================

typedef struct NodoFila
{
    Musica musica;

    struct NodoFila *prox;

} NodoFila;

typedef struct
{
    NodoFila *inicio;
    NodoFila *fim;

} Fila;

//====================================================
// PLAYER
//====================================================

typedef struct
{
    ListaDupla biblioteca;

    ListaDupla playlist;

    Pilha historico;

    Fila filaReproducao;

    Nodo *musicaAtual;

    int pausado;

} MusicPlayer;

//====================================================
// LISTA
//====================================================

void inicializarLista(ListaDupla *lista);

void inserirFinal(ListaDupla *lista,
                  Musica musica);

void listarMusicas(ListaDupla *lista);

Nodo* buscarMusica(ListaDupla *lista,
                   char titulo[]);

void removerMusica(ListaDupla *lista,
                   char titulo[]);

int contarMusicas(ListaDupla *lista);

void liberarLista(ListaDupla *lista);

//====================================================
// PILHA
//====================================================

void inicializarPilha(Pilha *pilha);

void push(Pilha *pilha,
          Musica musica);

Musica pop(Pilha *pilha);

Musica peekPilha(Pilha *pilha);

int isEmptyPilha(Pilha *pilha);

void mostrarHistorico(Pilha *pilha);

void liberarPilha(Pilha *pilha);

//====================================================
// FILA
//====================================================

void inicializarFila(Fila *fila);

void enqueue(Fila *fila,
             Musica musica);

Musica dequeue(Fila *fila);

Musica peekFila(Fila *fila);

int isEmptyFila(Fila *fila);

void mostrarFila(Fila *fila);

void liberarFila(Fila *fila);

//====================================================
// PLAYER
//====================================================

void inicializarPlayer(MusicPlayer *player);

void cadastrarMusica(MusicPlayer *player);

void adicionarNaPlaylist(MusicPlayer *player);

void exibirPlaylist(MusicPlayer *player);

void reproduzirMusica(MusicPlayer *player);

void proximaMusica(MusicPlayer *player);

void musicaAnterior(MusicPlayer *player);

void pausar(MusicPlayer *player);

void retomar(MusicPlayer *player);

void shuffle(MusicPlayer *player);

void adicionarNaFila(MusicPlayer *player);

void tocarDaFila(MusicPlayer *player);

void liberarPlayer(MusicPlayer *player);

#endif