#include "estruturas.h"

void menu()
{
    printf("\n");
    printf("===== MUSIC PLAYER =====\n");

    printf("1  - Cadastrar Musica\n");
    printf("2  - Listar Biblioteca\n");
    printf("3  - Buscar Musica\n");
    printf("4  - Adicionar Playlist\n");
    printf("5  - Exibir Playlist\n");
    printf("6  - Reproduzir\n");
    printf("7  - Proxima Musica\n");
    printf("8  - Musica Anterior\n");
    printf("9  - Shuffle\n");
    printf("10 - Mostrar Historico\n");
    printf("11 - Adicionar na Fila\n");
    printf("12 - Mostrar Fila\n");
    printf("13 - Tocar da Fila\n");
    printf("14 - Pausar\n");
    printf("15 - Retomar\n");
    printf("0  - Sair\n");

    printf("\nOpcao: ");
}

int main()
{
    srand(time(NULL));

    MusicPlayer player;

    inicializarPlayer(&player);

    int opcao;

    char titulo[TAM];

    do
    {
        menu();

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                cadastrarMusica(&player);
                break;

            case 2:
                listarMusicas(
                    &player.biblioteca);
                break;

            case 3:
            {
                getchar();

                printf(
                    "Titulo: ");

                fgets(
                    titulo,
                    TAM,
                    stdin);

                titulo[
                    strcspn(
                        titulo,
                        "\n")
                ] = '\0';

                Nodo *musica =
                    buscarMusica(
                        &player.biblioteca,
                        titulo);

                if(musica != NULL)
                {
                    printf(
                        "\nEncontrada!\n");

                    printf(
                        "Titulo: %s\n",
                        musica->musica.titulo);

                    printf(
                        "Artista: %s\n",
                        musica->musica.artista);
                }
                else
                {
                    printf(
                        "\nNao encontrada!\n");
                }

                break;
            }

            case 4:
                adicionarNaPlaylist(
                    &player);
                break;

            case 5:
                exibirPlaylist(
                    &player);
                break;

            case 6:
                reproduzirMusica(
                    &player);
                break;

            case 7:
                proximaMusica(
                    &player);
                break;

            case 8:
                musicaAnterior(
                    &player);
                break;

            case 9:
                shuffle(
                    &player);
                break;

            case 10:
                mostrarHistorico(
                    &player.historico);
                break;

            case 11:
                adicionarNaFila(
                    &player);
                break;

            case 12:
                mostrarFila(
                    &player.filaReproducao);
                break;

            case 13:
                tocarDaFila(
                    &player);
                break;

            case 14:
                pausar(
                    &player);
                break;

            case 15:
                retomar(
                    &player);
                break;

            case 0:
                printf(
                    "\nEncerrando...\n");
                break;

            default:
                printf(
                    "\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    liberarPlayer(
        &player);

    return 0;
}