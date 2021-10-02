#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina listaVacinas[200];
    int numeroVacinas;
} ListaVacinas;

int listarVacinas(ListaVacinas lv);
void adicionarVacina(ListaVacinas *lv);
void carregarDadosListaVacinas(ListaVacinas *lv);
void gravarDadosListaVacinas(ListaVacinas lv);
void getVacinaByID(int vacinaID, ListaVacinas lv);
void menuVacina();
void listarVacinasGeral(ListaVacinas lv);
void inativarVacina(ListaVacinas *lv, int numVacina);
void ativarVacina(ListaVacinas *lv, int numVacina);
void listarVacinasInativas(ListaVacinas lv);
void editaVacina(ListaVacinas *lv, int numVacina);
void listarVacinasAlfabeticamente(ListaVacinas lv);