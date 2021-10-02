#define NOME 100
#define CONTACTO 11
#define DATA 10
#include <time.h>

typedef struct sUtente
{
    int numeroUtente;
    char nomeUtente[NOME];
    int idade;
    char contacto[CONTACTO];
    int vacinaID;
    int centroID;
    int dosesAdministradas;
    int dayUltimaDose;
    int monthUltimaDose;
    int yearUltimaDose;
    int utenteID;
} Utente;

Utente criarUtente();