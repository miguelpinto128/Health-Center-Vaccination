#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "./01-Data/listaUtentes.h"
#include "./01-Data/listaVacinas.h"
#include "./01-Data/listaCentros.h"

void menuUtente(ListaUtentes *lu, ListaCentros lc, ListaVacinas lv)
{
    char dateAux[10];
    int a = 0;
    Utente u = criarUtente(lu->utentes[lu->numeroUtentes - 1].utenteID + 1);
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->utentes[i].numeroUtente == u.numeroUtente)
        {
            printf("Numero de utente ja existente!\n");
            a = 1;
        }
    }
    if (a == 0)
    {
        printf("Introduza o centro:\n");
        u.centroID = listarCentros(lc);
        printf("Introduza a vacina:\n");
        u.vacinaID = listarVacinas(lv);
        for (int i = 0; i < lv.numeroVacinas; i++)
        {
            if (lv.listaVacinas[i].vacinaID == u.vacinaID)
            {
                lv.listaVacinas[i].numUtentes++;
                gravarDadosListaVacinas(lv);
            }
        }
        for (int i = 0; i < lv.numeroVacinas; i++)
        {
            if (lv.listaVacinas[i].vacinaID == u.vacinaID)
            {
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                int month = (tm.tm_mon + 1) + lv.listaVacinas[i].mesesEntreDoses;
                int year = tm.tm_year + 1900;
                if (month >= 12)
                {
                    int month_ = (12 - month) * -1;
                    month = month_;
                    year = year + 1;
                }
                u.dayUltimaDose = tm.tm_mday;
                u.monthUltimaDose = month;
                u.yearUltimaDose = year;
            }
        }
        acrescentaUtente(lu, u);
    }
}

void removerUtente(ListaUtentes *lu, int numUtente)
{
    Utente u;
    listarUtentes(*lu);
    printf("Escolha o utente a remover: ");
    scanf("%d", &numUtente);
    if (numUtente >= lu->numeroUtentes + 1)
    {
        printf("Impossivel apagar. Utente inexistente.");
    }
    else
    {
        int i;
        for (i = 0; i < lu->numeroUtentes; i++)
        {
            if (lu->utentes[i].utenteID == numUtente)
                break;
        }
        for (int j = i + 1; j < lu->numeroUtentes; j++)
        {
            lu->utentes[j - 1] = lu->utentes[j];
        }
        lu->numeroUtentes = lu->numeroUtentes - 1;
    }
}

void utentesPorVacina(ListaUtentes lu, ListaVacinas lv)
{
    int numVacina;
    listarVacinasGeral(lv);
    printf("Escolha a sua opcao: ");
    scanf("%d", &numVacina);
    for (int i = 0; i < lu.numeroUtentes; i++)
    {
        if (lu.utentes[i].vacinaID == numVacina)
        {
            printf("%d -> %s (%s)\n", lu.utentes[i].utenteID, lu.utentes[i].nomeUtente, lv.listaVacinas[numVacina].designacaoVacina);
        }
    }
}

void utentesPorCentro(ListaUtentes lu, ListaCentros lc)
{
    int numCentro;
    listarCentrosGeral(lc);
    printf("Escolha a sua opcao: ");
    scanf("%d", &numCentro);
    for (int i = 0; i < lu.numeroUtentes; i++)
    {
        if (lu.utentes[i].centroID == numCentro)
        {
            printf("%d -> %s (%s)\n", lu.utentes[i].utenteID, lu.utentes[i].nomeUtente, lc.listaCentros[numCentro].nomeCentro);
        }
    }
}

void seacrhUtente(ListaUtentes lu)
{
    int numUtente;

    listarUtentes(lu);
    printf("Insira um utente: ");
    scanf("%d", &numUtente);
    printf("%s -> %d/%d/%d\n", lu.utentes[numUtente - 1].nomeUtente, lu.utentes[numUtente - 1].dayUltimaDose, lu.utentes[numUtente - 1].monthUltimaDose, lu.utentes[numUtente - 1].yearUltimaDose);
}

void seacrhUtenteDate(ListaUtentes lu)
{
    int day, month, year;

    listarUtentes(lu);
    printf("Insira o dia: ");
    scanf("%d", &day);
    printf("Insira o mes: ");
    scanf("%d", &month);
    printf("Insira o ano: ");
    scanf("%d", &year);

    for (int i = 0; i < lu.numeroUtentes; i++)
    {
        if (lu.utentes[i].dayUltimaDose == day && lu.utentes[i].monthUltimaDose == month && lu.utentes[i].yearUltimaDose == year)
        {
            printf("%s -> %d/%d/%d\n", lu.utentes[i].nomeUtente, lu.utentes[i].dayUltimaDose, lu.utentes[i].monthUltimaDose, lu.utentes[i].yearUltimaDose);
        }
    }
}

void menuUtentes(ListaUtentes *lu, ListaVacinas *lv, ListaCentros *lc)
{
    int opcao;
    int numUtente;

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#            MENU DE UTENTES            #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#\t 1 - CRIAR NOVO UTENTE          #\n");
    printf("#                                       #\n");
    printf("#\t 2 - EDITAR UTENTE              #\n");
    printf("#                                       #\n");
    printf("#\t 3 - REMOVER UTENTE             #\n");
    printf("#                                       #\n");
    printf("#\t 4 - LISTAR UTENTES             #\n");
    printf("#                                       #\n");
    printf("#\t 5 - UTENTE POR VACINA          #\n");
    printf("#                                       #\n");
    printf("#\t 6 - UTENTE POR CENTRO          #\n");
    printf("#                                       #\n");
    printf("#\t 7 - PROXIMA VACINA UTENTE      #\n");
    printf("#                                       #\n");
    printf("#\t 8 - PESQUISAR POR DATA PROXIMA #\n");
    printf("#\t VACINA                         #\n");
    printf("#                                       #\n");
    printf("#\t 0 - SAIR                       #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf(">\t Digite a sua opcao -> ");
    scanf("%d", &opcao);
    system("@cls||clear");

    switch (opcao)
    {
    case 1:
        menuUtente(lu, *lc, *lv);
        gravarDadosListaUtentes(*lu);
        system("@cls||clear");
        break;
    case 2:
        editaUtente(lu, numUtente);
        gravarDadosListaUtentes(*lu);
        system("@cls||clear");
        break;
    case 3:
        removerUtente(lu, numUtente);
        gravarDadosListaUtentes(*lu);
        system("@cls||clear");
        break;
    case 4:
        listarUtentes(*lu);
        break;
    case 5:
        utentesPorVacina(*lu, *lv);
        break;
    case 6:
        utentesPorCentro(*lu, *lc);
        break;
    case 7:
        seacrhUtente(*lu);
        break;
    case 8:
        seacrhUtenteDate(*lu);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void menuInicial(ListaCentros *lc, ListaUtentes *lu, ListaVacinas *lv)
{
    int opcao;
    float media = mediaIdades(*lu);
    system("pause");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#               DASHBOARD               #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("\n");
    printf("Quantidade vacinas administradas: %d\n", lv->numeroVacinas);
    printf("Media de idades dos utentes vacinados: %.2f\n", media);
    printf("Quantidade de utentes vacinados por vacina:\n");
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        printf("%s -> %d\n", lv->listaVacinas[i].designacaoVacina, lv->listaVacinas[i].numUtentes);
    }
    printf("\n");
    printf("\n");

    printf("########################################\n");
    printf("#                                      #\n");
    printf("#             MENU INICIAL             #\n");
    printf("#                                      #\n");
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#\t 1 - CENTROS DE VACINACAO      #\n");
    printf("#                                      #\n");
    printf("#\t 2 - UTENTES                   #\n");
    printf("#                                      #\n");
    printf("#\t 3 - VACINAS                   #\n");
    printf("#                                      #\n");
    printf("#\t 0 - SAIR                      #\n");
    printf("#                                      #\n");
    printf("########################################\n");
    printf(">\t Digite a sua opcao -> ");
    scanf("%d", &opcao);
    system("@cls||clear");

    switch (opcao)
    {
    case 1:
        menuCentro(lc);
        break;
    case 2:
        menuUtentes(lu, lv, lc);
        break;
    case 3:
        menuVacina(lv);
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

int main(int argc, char const *argv[])
{
    system("@cls||clear");
    //Definicao de SNS

    ListaCentros lc;
    ListaVacinas lv;
    ListaUtentes lu;

    lc.numeroCentros = 0;
    lv.numeroVacinas = 0;
    lu.numeroUtentes = 0;

    carregarDadosListaCentros(&lc);
    carregarDadosListaUtentes(&lu);
    int opcao = -1;
    int temp = 0;

    while (opcao != 0)
    {
        carregarDadosListaVacinas(&lv);
        menuInicial(&lc, &lu, &lv);
    }
}