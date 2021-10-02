#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../01-Data/centroVacinacao.h"

CentroVacinacao criarCentro(int centroID)
{
    CentroVacinacao c;
    char temp[20];
    int status;

    printf("Nome do Centro: ");
    while (getchar() != '\n')
        ;
    do
    {
        fgets(c.nomeCentro, NOME, stdin);
    } while (c.nomeCentro[0] == '\n' && c.nomeCentro[1] == '\0');
    c.nomeCentro[strlen(c.nomeCentro) - 1] = '\0';
    printf("Codigo do Centro: ");
    do
    {
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%d", &c.codigoCentro);
    } while (temp[0] == '\n' && temp[1] == '\0');
    printf("Morada do Centro: ");
    do
    {
        fgets(c.morada, MORADA, stdin);
    } while (c.morada[0] == '\n' && c.morada[1] == '\0');
    c.morada[strlen(c.morada) - 1] = '\0';

    c.activo = 1;
    c.centroID = centroID;

    return c;
}