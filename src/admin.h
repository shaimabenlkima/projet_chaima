#ifndef ADMIN_H
#define ADMIN_H
#include <stdio.h>
#include <string.h>

typedef struct Personnel
{
char nom[20];
char prenom[20];
char cin[20];
char taille[20];
char poids[20];
char choix[50];
char num[20];

}personnel;
typedef struct Acteurs
{
char nom[20];
char prenom[20];
char cin[20];
char num[20];
char menho[20];


}acteurs;
int modifier_personnel(personnel *P,char Cin1[20]);
int supprimer_acteurs(acteurs *A,char Cin2[20]);
int modifier_acteurs(acteurs *A,char Cin1[20]);
int supprimer_personnel(personnel *P,char Cin2[20]);

#endif
