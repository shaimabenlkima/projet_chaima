#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
int modifier_personnel(personnel *P,char Cin1[20])
{
FILE* f1;


f1=fopen("personnel.txt","a+");
if( (f1!=NULL))
{
fprintf(f1,"%s %s %s %s %s %s\n",P->nom,P->prenom,P->cin,P->taille,P->poids,P->num); 
fclose(f1);

return(1);
}
}
int modifier_acteurs(acteurs *A,char Cin1[20])
{
FILE* f1;


f1=fopen("acteurs.txt","a+");
if( (f1!=NULL))
{
fprintf(f1,"%s %s %s %s %s\n",A->nom,A->prenom,A->cin,A->num,A->menho); 
fclose(f1);

return(1);
}
}
int supprimer_personnel(personnel *P,char Cin2[20])
{
    FILE *f1;
    FILE *f2;
   int a=(-1);
    f1=fopen("personnel.txt","r");
    f2=fopen("personnel_temp.txt","a+");
   
    if (f1!=NULL)
    { 

while (fscanf(f1,"%s %s %s %s %s %s\n",P->nom,P->prenom,P->cin,P->taille,P->poids,P->num)!=EOF)
        {
            if (strcmp(P->cin,Cin2)!=0)
            {  
              fprintf(f2,"%s %s %s %s %s %s\n",P->nom,P->prenom,P->cin,P->taille,P->poids,P->num);
              
            }
            else if (strcmp(P->cin,Cin2)==0)
            {
                a=1;
            } 
          
        }
        
    }
         
    fclose(f1);
    fclose(f2);
   
    remove("personnel.txt");
    rename("personnel_temp.txt","personnel.txt");
 
return(a);
}
int supprimer_acteurs(acteurs *A,char Cin2[20])
{
    FILE *f1;
    FILE *f2;
   int a=(-1);
    f1=fopen("acteurs.txt","r");
    f2=fopen("acteurs_temp.txt","a+");
   
    if (f1!=NULL)
    { 

while (fscanf(f1,"%s %s %s %s %s\n",A->nom,A->prenom,A->cin,A->num,A->menho)!=EOF)
        {
            if (strcmp(A->cin,Cin2)!=0)
            {  
              fprintf(f2,"%s %s %s %s %s\n",A->nom,A->prenom,A->cin,A->num,A->menho);
              
            }
            else if (strcmp(A->cin,Cin2)==0)
            {
                a=1;
            } 
          
        }
        
    }
         
    fclose(f1);
    fclose(f2);
   
    remove("acteurs.txt");
    rename("acteurs_temp.txt","acteurs.txt");
 
return(a);
}
