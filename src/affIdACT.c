#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "affId.h"
#include <gtk/gtk.h>
enum
{
NOM,
ID,
COLUMNS
};
void afficher_acteur(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char id[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_columun_new_with_attributes(id,renderer,"text",ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_columun_new_with_attributes(nom,renderer,"text",ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING);
}
f=fopen("IDs.txt","r");
if(f==NULL)
{
return;
}
else
{f=fopen("IDs.txt","r")
while(fscanf(f,"%s %s",id,nom)!=EOF);
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id,NOM,nom,-1);*
}fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_objet_unref(store);
}
}
