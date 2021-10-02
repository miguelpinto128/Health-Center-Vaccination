#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../01-Data/vacina.h"

Vacina criarVacina(int vacinaID)
{
    Vacina v;
    char temp[20];

    printf("Nome : ");
    do
    {
        fgets(v.designacaoVacina, DESIGNACAO, stdin);
    } while (v.designacaoVacina[0] == '\n' && v.designacaoVacina[1] == '\0');
    v.designacaoVacina[strlen(v.designacaoVacina) - 1] = '\0';
    printf("Codigo : ");
    do
    {
        fgets(temp, sizeof(temp), stdin);
    } while (temp[0] == '\n' && temp[1] == '\0');
    sscanf(temp, "%d", &v.codigoVacina);
    printf("Numero de Doses a tomar por paciente: ");
    do
    {
        fgets(temp, sizeof(temp), stdin);
    } while (temp[0] == '\n' && temp[1] == '\0');
    sscanf(temp, "%d", &v.numDoses);
    printf("Meses entre doses: ");
    do
    {
        fgets(temp, sizeof(temp), stdin);
    } while (temp[0] == '\n' && temp[1] == '\0');
    sscanf(temp, "%d", &v.mesesEntreDoses);
    v.activo = 1;
    v.numUtentes = 0;
    v.vacinaID = vacinaID;

    return v;
}
