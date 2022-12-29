#include <stdio.h>
#include <conio.h>
#include "struct.h"
int main()
{
int op;

do{
printf("1)ajouter un produit\n");
printf("2)afficher la description d'un produit\n ");
printf("3)supprimer un produit\n");
printf("4)modifier un produit \n");
printf("0)retour au menu principal\n\n\n " );
printf("choisissez l'operation souhaitee  : ");
do
{
scanf ("%d",&op);
switch (op)
{
case 1 :
         ajout_produit( );
         break;
case 2 :
		recherche_affichage();
		break;
case 3 :
		supprimerproduit();   
case 4 :
		ModifierProduit();
case 5 :
		
}
}while(op>=0&&op<=4);
}while(op!=0);        
      

return 0;
}

