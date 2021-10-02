#include <stdio.h>
#include <string.h>
#include "../01-Data/utente.h"

Utente criarUtente(int utenteID)
{
    Utente u;
    int centro;
    int vacina;
    char temp[20];

    printf("Nome do Utente: ");
    do
    {
        fgets(u.nomeUtente, NOME, stdin);
    } while (u.nomeUtente[0] == '\n' && u.nomeUtente[1] == '\0');
    u.nomeUtente[strlen(u.nomeUtente) - 1] = '\0';
    printf("Numero do Utente: ");
    do
    {
        fgets(temp, sizeof(temp), stdin);
    } while (temp[0] == '\n' && temp[1] == '\0');
    sscanf(temp, "%d", &u.numeroUtente);
    printf("Idade do Utente: ");
    do
    {
        fgets(temp, sizeof(temp), stdin);
    } while (temp[0] == '\n' && temp[1] == '\0');
    sscanf(temp, "%d", &u.idade);
    printf("Contacto do Utente: ");
    do
    {
        fgets(u.contacto, CONTACTO, stdin);
    } while (strlen(u.contacto) != 10);
    u.contacto[strlen(u.contacto) - 1] = '\0';
    u.utenteID = utenteID;
    return u;
}