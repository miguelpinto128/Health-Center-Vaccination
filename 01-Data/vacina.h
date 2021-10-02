#define DESIGNACAO 40

typedef struct sVacina
{
    int codigoVacina;
    char designacaoVacina[DESIGNACAO];
    int numDoses;
    int mesesEntreDoses;
    int vacinaID;
    int activo;
    int numUtentes;
} Vacina;

Vacina criarVacina(int vacinID);