#define MORADA 20
#define UTENTE 3000
#define VACINA 200
#define NOME 100
#define CENTROS 2000

typedef struct sCentroVacinacao
{
    int codigoCentro;
    char nomeCentro[NOME];
    char morada[MORADA];
    int centroID;
    int activo;
} CentroVacinacao;

CentroVacinacao criarCentro(int centroID);
