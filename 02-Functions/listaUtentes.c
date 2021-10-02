#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../01-Data/listaUtentes.h"

void acrescentaUtente(ListaUtentes *lu, Utente u)
{
    lu->utentes[lu->numeroUtentes++] = u;
}

void gravarDadosListaUtentes(ListaUtentes lu)
{
    FILE *file = fopen("listaUtentes.dat", "wb");
    rewind(file);
    fwrite(&lu, sizeof(ListaUtentes), 1, file);
    fclose(file);
}

void carregarDadosListaUtentes(ListaUtentes *lu)
{
    FILE *file;
    file = fopen("listaUtentes.dat", "rb");

    if (file == NULL)
    {
        printf("File not found!\n");
        return;
    }

    fread(lu, sizeof(ListaUtentes), 1, file);

    fclose(file);
}

void listarUtentes(ListaUtentes lu)
{
    for (int i = 0; i < lu.numeroUtentes; i++)
    {
        printf("%d -> %s\n", lu.utentes[i].utenteID, lu.utentes[i].nomeUtente);
    }
}

void editaUtente(ListaUtentes *lu, int numUtente)
{
    int opcao;
    char temp[20];
    int status;

    listarUtentes(*lu);
    printf("Escolha o utente a editar: \n");
    while ((status = scanf("%d", &numUtente)) != EOF)
    {
        if (status == 0)
        {
            printf(">\t Escolha o utente a editar -> ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    system("@cls||clear");
    printf("Escolheu o utente: %s\n", lu->utentes[numUtente - 1].nomeUtente);
    printf("O que deseja alterar?\n");
    printf("1 -> Numero de Utente\n");
    printf("2 -> Nome do Utente\n");
    printf("3 -> Idade do Utente\n");
    printf("4 -> Contacto do Utente\n");
    printf("0 -> Sair\n");
    printf("> Introduza a sua opcao: ");
    while ((status = scanf("%d", &opcao)) != EOF)
    {
        if (status == 0)
        {
            printf(">\t Digite a sua opcao -> ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    switch (opcao)
    {
    case 1:
        printf("Numero de utente original: %d\n", lu->utentes[numUtente - 1].numeroUtente);
        printf("Novo numero de utente: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(temp, sizeof(temp), stdin);
        } while (temp[0] == '\n' && temp[1] == '\0');
        sscanf(temp, "%d", &lu->utentes[numUtente - 1].numeroUtente);
        break;
    case 2:
        printf("Nome de utente original: %s\n", lu->utentes[numUtente - 1].nomeUtente);
        printf("Novo nome de utente: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(lu->utentes[numUtente - 1].nomeUtente, NOME, stdin);
        } while (lu->utentes[numUtente - 1].nomeUtente[0] == '\n' && lu->utentes[numUtente - 1].nomeUtente[1] == '\0');
        break;
    case 3:
        printf("Idade original: %d\n", lu->utentes[numUtente - 1].idade);
        printf("Nova idade: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(temp, sizeof(temp), stdin);
        } while (temp[0] == '\n' && temp[1] == '\0');
        sscanf(temp, "%d", &lu->utentes[numUtente - 1].idade);
        break;
    case 4:
        printf("Contacto original: %s\n", lu->utentes[numUtente - 1].contacto);
        printf("Novo contacto: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(lu->utentes[numUtente - 1].contacto, CONTACTO, stdin);
        } while (strlen(lu->utentes[numUtente - 1].contacto) != 10);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

float mediaIdades(ListaUtentes lu)
{
    int temp = 0;
    if (lu.numeroUtentes != 0)
    {
        for (int i = 0; i < lu.numeroUtentes; i++)
        {
            temp += lu.utentes[i].idade;
        }
        float media = temp / lu.numeroUtentes;
        return media;
    }
    else
    {
        return 0;
    }
}