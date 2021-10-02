#include "utente.h"

typedef struct sListaUtentes
{
    Utente utentes[3000];
    int numeroUtentes;
} ListaUtentes;

void carregarDadosListaUtentes(ListaUtentes *lu);
void gravarDadosListaUtentes(ListaUtentes lu);
void acrescentaUtente(ListaUtentes *lu, Utente u);
void listarUtentes(ListaUtentes lu);
void editaUtente(ListaUtentes *lu, int numUtente);
float mediaIdades(ListaUtentes lu);