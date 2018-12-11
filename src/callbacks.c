#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <stdlib.h>

#include "admin.c"




void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)

{       GtkWidget *nom;
	GtkWidget *prenom;
        GtkWidget *password;
	GtkWidget *taille;
	GtkWidget *poids;
	GtkWidget *message;
	GtkWidget *num;
	GtkWidget *cin;
	char Cin2[20];
	
	personnel P;
	FILE* f1;
	int a;

password=lookup_widget (GTK_WIDGET(button), "entry7");
nom=lookup_widget (GTK_WIDGET(button), "entry1");
prenom=lookup_widget (GTK_WIDGET(button), "entry2");
cin=lookup_widget (GTK_WIDGET(button), "entry3");
taille=lookup_widget (GTK_WIDGET(button), "entry4");
poids=lookup_widget (GTK_WIDGET(button), "entry5");
num=lookup_widget (GTK_WIDGET(button), "entry6");

strcpy(Cin2, gtk_entry_get_text (GTK_ENTRY (password)));
f1=fopen("personnel.txt","a+");
if (f1!=NULL)
{ 
	while(fscanf(f1,"%s %s %s %s %s %s\n",P.nom,P.prenom,P.cin,P.taille,P.poids,P.num)!=EOF)
	{	
		if (strcmp(Cin2,P.cin)==0)
	{
	gtk_entry_set_text (GTK_ENTRY (nom),P.nom);
	gtk_entry_set_text (GTK_ENTRY (prenom),P.prenom);
	gtk_entry_set_text (GTK_ENTRY (cin),P.cin);
	gtk_entry_set_text (GTK_ENTRY (taille),P.taille);
	gtk_entry_set_text (GTK_ENTRY (poids),P.poids);
        gtk_entry_set_text (GTK_ENTRY (num),P.num);
        a=supprimer_personnel(&P,Cin2);

	}
	}
}

fclose(f1);
enum
{
	NOM_PERSONNEL,
	PRENOM_PERSONNEL,
	CIN_PERSONNEL,
	TAILLE_PERSONNEL,
	POIDS_PERSONNEL,

	NUM_PERSONNEL,
	
	COLUMNS
};
void afficher_personnels(GtkWidget *treeview)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[20];
	char taille[20];
	char poids[5];

	char num[5];
	

	FILE *f;

store=gtk_list_store_new (10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("personnel.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else
	{                                         
	
		while(fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,cin,taille,poids,num)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,NOM_PERSONNEL,nom,PRENOM_PERSONNEL,prenom,CIN_PERSONNEL,cin,TAILLE_PERSONNEL,taille,POIDS_PERSONNEL,poids,NUM_PERSONNEL,num,-1);
		}
		
		fclose(f);
		
	}

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM_PERSONNEL, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM_PERSONNEL, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer,"text",CIN_PERSONNEL, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);	
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("taille", renderer,"text",TAILLE_PERSONNEL, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("poids", renderer,"text",POIDS_PERSONNEL, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("num", renderer,"text",NUM_PERSONNEL, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	

	
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
	
}

}







void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{       GtkWidget *message;
      GtkWidget *combobox2;
      GtkWidget *choix;
	
combobox2=lookup_widget(GTK_WIDGET(button),"combobox2");
message=lookup_widget(GTK_WIDGET(button),"label18");

if ((gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))!=NULL))
{FILE*  f=fopen("choix.txt","a");
char choix [20];
strcpy (choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
if (f != NULL ){
fprintf(f,"%s\n",choix);
gtk_label_set_text(GTK_LABEL(message),"ajout réussi");
}
fclose(f);
}
else 
gtk_label_set_text(GTK_LABEL(message),"veuillez entrer un choix");
}

void
on_button4_clicked                     (GtkButton       *object_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{       GtkWidget *nom;
	GtkWidget *prenom;
        GtkWidget *password;
	GtkWidget *taille;
	GtkWidget *poids;
        GtkWidget *num;
	GtkWidget *cin;
	GtkWidget *message;
	char Cin1[20];
	personnel P;
char id1[20];
char id2[20];
char id3[20];
int b;
password=lookup_widget (GTK_WIDGET(button), "entry7");
nom=lookup_widget (GTK_WIDGET(button), "entry1");
prenom=lookup_widget (GTK_WIDGET(button), "entry2");
cin=lookup_widget (GTK_WIDGET(button), "entry3");
taille=lookup_widget (GTK_WIDGET(button), "entry4");
poids=lookup_widget (GTK_WIDGET(button), "entry5");
num=lookup_widget (GTK_WIDGET(button), "entry6");
message=lookup_widget(GTK_WIDGET(button),"label7");
strcpy(Cin1, gtk_entry_get_text (GTK_ENTRY (password)));


strcpy (P.nom, gtk_entry_get_text (GTK_ENTRY (nom)));
strcpy (P.prenom, gtk_entry_get_text (GTK_ENTRY (prenom)));
strcpy (P.cin, gtk_entry_get_text (GTK_ENTRY (cin)));
strcpy (P.taille, gtk_entry_get_text (GTK_ENTRY (taille)));
strcpy (P.poids ,gtk_entry_get_text (GTK_ENTRY (poids)));

strcpy (P.num, gtk_entry_get_text (GTK_ENTRY (num)));
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(taille)));
strcpy(id2,gtk_entry_get_text(GTK_ENTRY(poids)));
strcpy(id3,gtk_entry_get_text(GTK_ENTRY(num)));
if(strtol(id1,NULL,10)>=strtol("a",NULL,10) && strtol(id1,NULL,10)<=strtol("z",NULL,10)&& strtol(id1,NULL,10)>=strtol("A",NULL,10) && strtol(id1,NULL,10)<=strtol("Z",NULL,10)  ||  strtol(id2,NULL,10)>=strtol("a",NULL,10) && strtol(id2,NULL,10)<=strtol("z",NULL,10)&& strtol(id2,NULL,10)>=strtol("A",NULL,10) && strtol(id2,NULL,10)<=strtol("Z",NULL,10)   || strtol(id3,NULL,10)>=strtol("a",NULL,10) && strtol(id3,NULL,10)<=strtol("z",NULL,10)&& strtol(id3,NULL,10)>=strtol("A",NULL,10) && strtol(id3,NULL,10)<=strtol("Z",NULL,10)){
gtk_label_set_text(GTK_LABEL(message),"veuillez entrez une information  valide\n");}

else if(modifier_personnel(&P,Cin1)==1){


	
		gtk_label_set_text (GTK_LABEL (message), "données modifiées");
		
		

gtk_entry_set_text (GTK_ENTRY (nom),"");
gtk_entry_set_text (GTK_ENTRY (prenom),"");
gtk_entry_set_text (GTK_ENTRY (cin),"");
gtk_entry_set_text (GTK_ENTRY (taille),"");
gtk_entry_set_text (GTK_ENTRY (poids),"");
gtk_entry_set_text (GTK_ENTRY (num),"");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(taille)));
//strcpy(id2,gtk_entry_get_text(GTK_ENTRY(entry5)));
//strcpy(id3,gtk_entry_get_text(GTK_ENTRY(entryid)));
//strcpy(id4,gtk_entry_get_text(GTK_ENTRY(entryid)));
}
}





void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *nom;
	GtkWidget *prenom;
        GtkWidget *password;
        GtkWidget *num;
	GtkWidget *cin;
	GtkWidget *Message;

	char Cin1[20];
	acteurs A;
int b;
password=lookup_widget (GTK_WIDGET(button), "entry8");
nom=lookup_widget (GTK_WIDGET(button), "entry9");
prenom=lookup_widget (GTK_WIDGET(button), "entry10");
cin=lookup_widget (GTK_WIDGET(button), "entry11");
num=lookup_widget (GTK_WIDGET(button), "entry12");
Message=lookup_widget(GTK_WIDGET(button),"label30");

strcpy(Cin1, gtk_entry_get_text (GTK_ENTRY (password)));


strcpy (A.nom, gtk_entry_get_text (GTK_ENTRY (nom)));
strcpy (A.prenom, gtk_entry_get_text (GTK_ENTRY (prenom)));
strcpy (A.cin, gtk_entry_get_text (GTK_ENTRY (cin)));
strcpy (A.num, gtk_entry_get_text (GTK_ENTRY (num)));





b=modifier_acteurs(&A,Cin1);
if (b=1)
	{
		gtk_label_set_text (GTK_LABEL (Message), "données modifiées");
		
	}

gtk_entry_set_text (GTK_ENTRY (nom),"");
gtk_entry_set_text (GTK_ENTRY (prenom),"");
gtk_entry_set_text (GTK_ENTRY (cin),"");

gtk_entry_set_text (GTK_ENTRY (num),"");


}



void
on_button7_clicked                     (GtkButton       *object_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)

{       GtkWidget *nom;
	GtkWidget *prenom;
        GtkWidget *password;
	GtkWidget *num;
	GtkWidget *cin;
GtkWidget *menho;

	char Cin2[20];
	acteurs A;
	FILE* f2;
int a;
password=lookup_widget (GTK_WIDGET(button), "entry8");
nom=lookup_widget (GTK_WIDGET(button), "entry9");
prenom=lookup_widget (GTK_WIDGET(button), "entry10");
cin=lookup_widget (GTK_WIDGET(button), "entry11");
num=lookup_widget (GTK_WIDGET(button), "entry12");
menho=lookup_widget (GTK_WIDGET(button), "label29");
strcpy(Cin2, gtk_entry_get_text (GTK_ENTRY (password)));
f2=fopen("acteurs.txt","a+");
if (f2!=NULL)
{
	while(fscanf(f2,"%s %s %s %s %s\n",A.nom,A.prenom,A.cin,A.num,A.menho)!=EOF)
	{	
		if (strcmp(Cin2,A.cin)==0)
	{
	gtk_entry_set_text (GTK_ENTRY (nom),A.nom);
	gtk_entry_set_text (GTK_ENTRY (prenom),A.prenom);
	gtk_entry_set_text (GTK_ENTRY (cin),A.cin);

	gtk_entry_set_text (GTK_ENTRY (num),A.num);
	gtk_label_set_text (GTK_LABEL (menho),A.menho);
        a=supprimer_acteurs(&A,Cin2);
	}
	}
}

fclose(f2);

enum
{
	NOM_ACTEURS,
	PRENOM_ACTEURS,
	CIN_ACTEURS,
	NUM_ACTEURS,
        MENHO_ACTEURS,
	
	COLUMNS
};
void afficher_acteurs(GtkWidget *treeview)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[20];
	char num[5];
	char menho[50];
	

	FILE *f;

store=gtk_list_store_new (10, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("acteurs.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else
	{                                         
	
		while(fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,cin,num,menho)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,NOM_ACTEURS,nom,PRENOM_ACTEURS,prenom,CIN_ACTEURS,cin,NUM_ACTEURS,num,MENHO_ACTEURS,menho,-1);
		}
		
		fclose(f);
		
	}

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM_ACTEURS, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM_ACTEURS, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer,"text",CIN_ACTEURS, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);	
	
	
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("num", renderer,"text",NUM_ACTEURS, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("menho", renderer,"text",MENHO_ACTEURS, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
	

	
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
	
}
}




void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *combobox1;
GtkWidget *message;
message=lookup_widget(GTK_WIDGET(button),"label11");
int x;
char ch1[20];
char choix[20];

combobox1=lookup_widget(GTK_WIDGET(button),"combobox1");
if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))!=NULL)
{
FILE* f =fopen("choix.txt","r");
FILE* f1 =fopen("copie.txt","w");
strcpy (ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
if ( f !=NULL){
while ( fscanf (f," %s\n",choix)!=EOF)
{ 

if (strcmp(choix,ch1)!=0)
{fprintf(f1,"%s\n",choix);
}
}
}
fclose(f);
fclose(f1);
f= fopen ("choix.txt","w");
f1=fopen("copie.txt","r");
if (f1 != NULL )
{
while (fscanf (f1,"%s\n",choix)!=EOF)
{fprintf(f,"%s\n",choix);
}
}
fclose(f1);
x=remove("copie.txt");
gtk_list_store_clear (GTK_LIST_STORE(gtk_combo_box_get_model(combobox1)));
if (f != NULL){
while (fscanf (f, "%s\n",choix)!=EOF)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(combobox1),_(choix));
}
}
fclose(f);
gtk_label_set_text(GTK_LABEL(message),"suppression termineé");
}
}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *combobox1;
FILE* f= fopen ("choix.txt","r");
char ch[20];
char choix[20];
combobox1=lookup_widget(GTK_WIDGET(button),"combobox1");
gtk_list_store_clear (GTK_LIST_STORE(gtk_combo_box_get_model(combobox1)));
gtk_combo_box_get_active(GTK_COMBO_BOX(combobox1));
if (f!=NULL){
while (fscanf(f,"%s\n",choix)!=EOF)
{
strcpy(ch,choix);
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1),_(ch));
}
fclose(f);
}
}




