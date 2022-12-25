#include <stdio.h>
#include <conio.h>
#include "struct.h"
int main()
{
int choix,op,num,n ;
produit l;


printf("1)ajouter un produit\n");
printf("2)afficher la description d'un produit\n ");
printf("3)supprimer un produit\n");
printf("4)modifier un produit \n");
printf("5)rechercher un produit dans le stock\n");
printf("0)retour au menu principal\n\n\n " );
printf("choisissez l'operation souhaitee  : ");
do
{
scanf ("%d",&op);
switch (op)
{
case 1 :
         l=saisie_produit(l);
		 ajout_produit(noeudprod,l);
         printf("un nouveau produit est ajoute au stock\n");
         break;
case 2 :
		printf("entrer le numero de serie de produit: ");
		scanf("%d",n);
		if(recherche_produit(noeudprod,n))
   		{   
			
			print_prod();
			
 		}
 		else{
		 	
			printf("le produit que vous souhaitez de le modifier n'existe pas ou le numero de serie est incorrect\n");
			printf("ressayer de nouveau\n");
			}
        
		break;
case 3 :
		printf("entrer le numero de serie de produit ");
		scanf("%d",&n);
		if(recherche_produit(noeudprod,n))
   		{
			print_produit();
			printf("voulez-vous supprimer ce produit?\n");
		 	printf("taper votre choix: 1 :oui / 2:non\n");
         	scanf("%d",&choix);
         	if(choix==1)
			{
 			    suppr_prod(noeudprod ,n);
				printf("le produit de numero de serie %d est supprrime\n",n);
				break;
		 	}
 			else{break;}	
		}    
case 4 :
		printf("entrer le numero de serie de produit ");
		scanf("%d",n);
		if(recherche_produit(noeudprod,n))
   		{
			print_produit();
    	}
    	else{
			printf("le produit que vous souhaitez de le modifier n'existe pas ou le numero de serie est incorrect\n");
			printf("ressayer de nouveau\n");
			}
         break;
case 5 :
		printf("entrer le numero de serie de produit ");
		scanf("%d",n);
		if(recherche_prod(n)){
			prtint_produit();
		}
		else{printf("ce produit n'est pas existant");}
        break;
case 0 :
        break;
}
}while(op>=0&&op<=5);
        
        
getch();
return 0;
}

