#include "centroVacinacao.h"

typedef struct sListaCentros
{
    CentroVacinacao listaCentros[1000];
    int numeroCentros;
} ListaCentros;

int listarCentros(ListaCentros lc);
void adicionarCentro(ListaCentros *lc);
void carregarDadosListaCentros(ListaCentros *lc);
void gravarDadosListaCentros(ListaCentros lc);
void getCentroById(int centroID, ListaCentros lc);
void menuCentro(ListaCentros *lc);
void inativarCentro(ListaCentros *lc, int numCentro);
void listarCentrosGeral(ListaCentros lc);
void ativarCentro(ListaCentros *lc, int numCentro);
void listarCentrosInativos(ListaCentros lc);
void editaCentro(ListaCentros *lc, int numCentro);