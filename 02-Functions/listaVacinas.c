#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../01-Data/listaVacinas.h"

int listarVacinas(ListaVacinas lv)
{
    int vacinaId;
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        if (lv.listaVacinas[i].activo == 1)
        {
            printf("%d -> %s \n", lv.listaVacinas[i].vacinaID, lv.listaVacinas[i].designacaoVacina);
        }
    }
    int status;
    while ((status = scanf("%d", &vacinaId)) != EOF)
    {
        if (status == 0)
        {
            printf("Escolha a vacina: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }

    if (vacinaId >= lv.numeroVacinas + 1)
    {
        printf("Vacina inexistente. Escolha outra vacina!\n");
    }
    return vacinaId;
}

void listarVacinasGeral(ListaVacinas lv)
{
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        if (lv.listaVacinas[i].activo == 1)
        {
            printf("%d -> %s\n", lv.listaVacinas[i].vacinaID, lv.listaVacinas[i].designacaoVacina);
        }
    }
}

void listarVacinasAlfabeticamente(ListaVacinas lv)
{
    char temp[200];
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        for (int j = i + 1; j < lv.numeroVacinas; j++)
        {
            if (strcmp(lv.listaVacinas[i].designacaoVacina, lv.listaVacinas[j].designacaoVacina) > 0)
            {
                strcpy(temp, lv.listaVacinas[i].designacaoVacina);
                strcpy(lv.listaVacinas[i].designacaoVacina, lv.listaVacinas[j].designacaoVacina);
                strcpy(lv.listaVacinas[j].designacaoVacina, temp);
            }
        }
    }
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        printf("%s\n", lv.listaVacinas[i].designacaoVacina);
    }
}
void adicionarVacina(ListaVacinas *lv)
{
    int a = 0;
    Vacina v = criarVacina(lv->numeroVacinas);
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (strcmp(lv->listaVacinas[i].designacaoVacina, v.designacaoVacina) == 0)
        {
            printf("Vacina ja existente!\n");
            a = 1;
        }
    }
    if (a == 0)
    {
        lv->listaVacinas[lv->numeroVacinas++] = v;
    }
}

void carregarDadosListaVacinas(ListaVacinas *lv)
{
    FILE *file;
    file = fopen("listaVacinas.dat", "rb");

    if (file == NULL)
        return;

    fread(lv, sizeof(ListaVacinas), 1, file);

    fclose(file);
}

void gravarDadosListaVacinas(ListaVacinas lv)
{
    FILE *file = fopen("listaVacinas.dat", "wb");
    rewind(file);
    fwrite(&lv, sizeof(ListaVacinas), 1, file);
    fclose(file);
}

void getVacinaByID(int vacinaID, ListaVacinas lv)
{
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        if (lv.listaVacinas[i].vacinaID == vacinaID)
        {
            printf("Codigo : %d\n", lv.listaVacinas[i].codigoVacina);
            printf("Designacao : %s\n", lv.listaVacinas[i].designacaoVacina);
            printf("Numero Doses : %d\n", lv.listaVacinas[i].numDoses);
            printf("Tempo entre Doses : %d meses\n", lv.listaVacinas[i].mesesEntreDoses);
        }
    }
}

void inativarVacina(ListaVacinas *lv, int numVacina)
{
    Vacina v;
    listarVacinasGeral(*lv);

    printf("Escolha a vacina a inativar: ");
    int status;
    while ((status = scanf("%d", &numVacina)) != EOF)
    {
        if (status == 0)
        {
            printf("Escolha a vacina a inativar: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    if (numVacina >= lv->numeroVacinas + 1)
    {
        printf("Impossivel inativar. Vacina inexistente.");
    }
    else
    {
        lv->listaVacinas[numVacina].activo = 0;
    }
}

void listarVacinasInativas(ListaVacinas lv)
{
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        if (lv.listaVacinas[i].activo == 0)
        {
            printf("%d -> %s\n", lv.listaVacinas[i].vacinaID, lv.listaVacinas[i].designacaoVacina);
        }
    }
}

void ativarVacina(ListaVacinas *lv, int numVacina)
{
    Vacina v;
    listarVacinasInativas(*lv);

    printf("Escolha a vacina a ativar: ");
    int status;
    while ((status = scanf("%d", &numVacina)) != EOF)
    {
        if (status == 0)
        {
            printf("Escolha a vacina a ativar: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    if (numVacina >= lv->numeroVacinas + 1)
    {
        printf("Impossivel ativar. Vacina inexistente ou ja ativa!");
    }
    else
    {
        lv->listaVacinas[numVacina].activo = 1;
    }
}

void editaVacina(ListaVacinas *lv, int numVacina)
{
    int opcao;
    char temp[20];
    int status;

    listarVacinasGeral(*lv);
    printf("Escolha a vacina a editar: \n");
    scanf("%d", &numVacina);
    while ((status = scanf("%d", &numVacina)) != EOF)
    {
        if (status == 0)
        {
            printf(">\t Escolha a vacina a editar -> ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
    system("@cls||clear");
    printf("Escolheu a vacina: %s\n", lv->listaVacinas[numVacina - 1].designacaoVacina);
    printf("O que deseja alterar?\n");
    printf("1 -> Nome da vacina \n");
    printf("2 -> Codigo da vacina\n");
    printf("3 -> Numero de doses da vacina\n");
    printf("4 -> Espera entre doses \n");
    printf("0 -> Sair \n");
    printf("> Introduza a sua opcao: ");
    while ((status = scanf("%d", &opcao)) != EOF)
    {
        if (status == 0)
        {
            printf(">\t Introduza a sua opcao -> ");
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
        printf("Nome original: %s\n", lv->listaVacinas[numVacina - 1].designacaoVacina);
        printf("Novo nome: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(lv->listaVacinas[numVacina - 1].designacaoVacina, DESIGNACAO, stdin);
        } while (lv->listaVacinas[numVacina - 1].designacaoVacina[0] == '\n' && lv->listaVacinas[numVacina - 1].designacaoVacina[1] == '\0');
        break;
    case 2:
        printf("Codigo original: %d\n", lv->listaVacinas[numVacina - 1].codigoVacina);
        printf("Novo codigo: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(temp, sizeof(temp), stdin);
        } while (temp[0] == '\n' && temp[1] == '\0');
        sscanf(temp, "%d", &lv->listaVacinas[numVacina - 1].codigoVacina);
        break;
    case 3:
        printf("Numero de doses original: %d\n", lv->listaVacinas[numVacina - 1].numDoses);
        printf("Novo numero de doses: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(temp, sizeof(temp), stdin);
        } while (temp[0] == '\n' && temp[1] == '\0');
        sscanf(temp, "%d", &lv->listaVacinas[numVacina - 1].numDoses);
        break;
    case 4:
        printf("Espera entre doses original: %d\n", lv->listaVacinas[numVacina - 1].mesesEntreDoses);
        printf("Nova espera entre doses: \n");
        while (getchar() != '\n')
            ;
        do
        {
            fgets(temp, sizeof(temp), stdin);
        } while (temp[0] == '\n' && temp[1] == '\0');
        sscanf(temp, "%d", &lv->listaVacinas[numVacina - 1].mesesEntreDoses);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void menuVacina(ListaVacinas *lv)
{
    int opcao;
    int numVacina;

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#            MENU DE VACINAS            #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#\t 1 - CRIAR VACINA               #\n");
    printf("#                                       #\n");
    printf("#\t 2 - EDITAR VACINA              #\n");
    printf("#                                       #\n");
    printf("#\t 3 - INATIVAR VACINA            #\n");
    printf("#                                       #\n");
    printf("#\t 4 - ATIVAR VACINAS             #\n");
    printf("#                                       #\n");
    printf("#\t 5 - LISTAR VACINAS             #\n");
    printf("#                                       #\n");
    printf("#\t 6 - VACINAS ALFABETICAMENTE    #\n");
    printf("#                                       #\n");
    printf("#\t 0 - SAIR                       #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf(">\t Digite a sua opcao -> ");
    int status;
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
    system("@cls||clear");

    switch (opcao)
    {
    case 1:
        adicionarVacina(lv);
        gravarDadosListaVacinas(*lv);
        system("@cls||clear");
        break;
    case 2:
        editaVacina(lv, numVacina);
        gravarDadosListaVacinas(*lv);
        system("@cls||clear");
        break;
    case 3:
        inativarVacina(lv, numVacina);
        gravarDadosListaVacinas(*lv);
        system("@cls||clear");
        break;
    case 4:
        ativarVacina(lv, numVacina);
        gravarDadosListaVacinas(*lv);
        break;
    case 5:
        listarVacinasGeral(*lv);
        break;
    case 6:
        listarVacinasAlfabeticamente(*lv);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}
