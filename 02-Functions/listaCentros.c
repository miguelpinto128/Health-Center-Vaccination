#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../01-Data/listaCentros.h"

int listarCentros(ListaCentros lc)
{
    int centroId;
    for (int i = 0; i < lc.numeroCentros; i++)
    {
        if (lc.listaCentros[i].activo == 1)
        {
            printf("%d -> %s \n", lc.listaCentros[i].centroID, lc.listaCentros[i].nomeCentro);
        }
    }
    scanf("%d", &centroId);

    if (centroId >= lc.numeroCentros + 1)
    {
        printf("Centro inexistente. Escolha outr centro!\n");
    }

    return centroId;
}

void listarCentrosGeral(ListaCentros lc)
{
    for (int i = 0; i < lc.numeroCentros; i++)
    {
        if (lc.listaCentros[i].activo == 1)
        {
            printf("%d -> %s\n", lc.listaCentros[i].centroID, lc.listaCentros[i].nomeCentro);
        }
    }
}

void adicionarCentro(ListaCentros *lc)
{
    int a = 0;
    CentroVacinacao c = criarCentro(lc->numeroCentros);
    for (int i = 0; i < lc->numeroCentros; i++)
    {
        if (strcmp(lc->listaCentros[i].nomeCentro, c.nomeCentro) == 0)
        {
            printf("Centro ja existente!\n");
            a = 1;
        }
    }
    if (a == 0)
    {
        lc->listaCentros[lc->numeroCentros] = c;
        lc->numeroCentros++;
    }
}

void carregarDadosListaCentros(ListaCentros *lc)
{
    FILE *file;
    file = fopen("listaCentros.dat", "rb");

    if (file == NULL)
        return;

    fread(lc, sizeof(ListaCentros), 1, file);

    fclose(file);
}

void gravarDadosListaCentros(ListaCentros lc)
{
    FILE *file = fopen("listaCentros.dat", "wb");
    rewind(file);
    fwrite(&lc, sizeof(ListaCentros), 1, file);
    fclose(file);
}

void getCentroById(int centroID, ListaCentros lc)
{
    for (int i = 0; i < lc.numeroCentros; i++)
    {
        if (lc.listaCentros[i].centroID == centroID)
        {
            printf("Codigo : %d\n", lc.listaCentros[i].codigoCentro);
            printf("Nome : %s\n", lc.listaCentros[i].nomeCentro);
            printf("Morada : %s\n", lc.listaCentros[i].morada);
        }
    }
}

void inativarCentro(ListaCentros *lc, int numCentro)
{
    CentroVacinacao c;
    listarCentrosGeral(*lc);

    printf("Escolha o centro a inativar: ");
    scanf("%d", &numCentro);
    if (numCentro >= lc->numeroCentros + 1)
    {
        printf("Impossivel inativar. Centro inexistente.");
    }
    else
    {
        lc->listaCentros[numCentro].activo = 0;
    }
}

void listarCentrosInativos(ListaCentros lc)
{
    for (int i = 0; i < lc.numeroCentros; i++)
    {
        if (lc.listaCentros[i].activo == 0)
        {
            printf("%d -> %s\n", lc.listaCentros[i].centroID, lc.listaCentros[i].nomeCentro);
        }
    }
}

void ativarCentro(ListaCentros *lc, int numCentro)
{
    CentroVacinacao c;
    listarCentrosInativos(*lc);

    printf("Escolha o centro a ativar: ");
    scanf("%d", &numCentro);
    if (numCentro >= lc->numeroCentros + 1)
    {
        printf("Impossivel ativar. Centro inexistente ou ja ativo!");
    }
    else
    {
        lc->listaCentros[numCentro].activo = 1;
    }
}

void editaCentro(ListaCentros *lc, int numCentro)
{
    int opcao;
    char temp[20];
    int status1, status2;
    listarCentrosGeral(*lc);
    printf("Escolha o centro a editar: \n");
    while ((status1 = scanf("%d", &numCentro)) != EOF)
    {
        if (status1 == 0)
        {
            printf("Escolha o centro a editar -> ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    system("@cls||clear");
    printf("Escolheu o centro: %s\n", lc->listaCentros[numCentro - 1].nomeCentro);
    printf("O que deseja alterar?\n");
    printf("1 -> Codigo do Centro\n");
    printf("2 -> Nome do Centro\n");
    printf("3 -> Morada do Centro\n");
    printf("0 -> Sair\n");
    printf("> Introduza a sua opcao: ");
    while ((status2 = scanf("%d", &opcao)) != EOF)
    {
        if (status2 == 0)
        {
            printf("Insira novamente a opcao:");
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
        printf("Codigo original: %d\n", lc->listaCentros[numCentro - 1].codigoCentro);
        printf("Novo codigo: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(temp, sizeof(temp), stdin);
        } while (temp[0] == '\n' && temp[1] == '\0');
        sscanf(temp, "%d", &lc->listaCentros[numCentro - 1].codigoCentro);
        break;

    case 2:
        printf("Nome original: %s\n", lc->listaCentros[numCentro - 1].nomeCentro);
        printf("Novo nome: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(lc->listaCentros[numCentro - 1].nomeCentro, NOME, stdin);
        } while (lc->listaCentros[numCentro - 1].nomeCentro[0] == '\n' && lc->listaCentros[numCentro - 1].nomeCentro[1] == '\0');
        break;
    case 3:
        printf("Morada original: %s\n", lc->listaCentros[numCentro - 1].morada);
        printf("Nova morada: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(lc->listaCentros[numCentro - 1].morada, MORADA, stdin);
        } while (lc->listaCentros[numCentro - 1].morada[0] == '\n' && lc->listaCentros[numCentro - 1].morada[1] == '\0');
    case 0:
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void menuCentro(ListaCentros *lc)
{
    int opcao;
    int numCentro;
    int status;

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#            MENU DE CENTROS            #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#\t 1 - CRIAR CENTRO               #\n");
    printf("#                                       #\n");
    printf("#\t 2 - EDITAR CENTRO              #\n");
    printf("#                                       #\n");
    printf("#\t 3 - INATIVAR CENTRO            #\n");
    printf("#                                       #\n");
    printf("#\t 4 - ATIVAR CENTRO              #\n");
    printf("#                                       #\n");
    printf("#\t 5 - LISTAR CENTROS             #\n");
    printf("#                                       #\n");
    printf("#\t 0 - SAIR                       #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf(">\t Digite a sua opcao -> ");
    while ((status = scanf("%d", &opcao)) != EOF)
    {
        if (status == 0)
        {
            printf("Insira novamente a opcao:");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    system("@cls||clear");

    switch (opcao)
    {
    case 1:
        adicionarCentro(lc);
        gravarDadosListaCentros(*lc);
        system("@cls||clear");
        break;
    case 2:

        editaCentro(lc, numCentro);
        gravarDadosListaCentros(*lc);
        system("@cls||clear");
        break;
    case 3:
        inativarCentro(lc, numCentro);
        gravarDadosListaCentros(*lc);
        system("@cls||clear");
        break;
    case 4:
        ativarCentro(lc, numCentro);
        break;
    case 5:
        listarCentrosGeral(*lc);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}