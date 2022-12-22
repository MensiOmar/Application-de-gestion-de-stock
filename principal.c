#include <stdio.h>
#include <conio.h>

int choix,op,num,n ;
int main()
{
printf("1)ajouter un produit|n");
printf("2)afficher la description d'un produit|n ");
printf("3)supprimer un produit|n ");
printf("4)modifier un produit |n");
printf("5)rechercher un produit dans le stock|n");
 printf("6)retour au menu principal|n|n|n " );
printf("choisissez l'operation souhaitee  : ");
do
{
scanf ("%d",&op);
switch (op)
{
case '1':
         ajout_prod();
         printf("un nouveau produit est ajoute au stock|n");
         break;
case'2':
		printf("entrer le numero de serie de produit ");
		scanf("%d",n);
		if(recherche_prod(int n))
   		{   
			print_prod(int n);
			
 		}
 		else:
		 	
			printf("le produit que vous souhaitez de le modifier n'existe pas ou le numero de serie est incorrect|n");
			printf("ressayer de nouveau|n");
        
		break;
case'3':printf("entrer le numero de serie de produit ");
		scanf("%d",n);
		if(recherche_prod(int n))
   		{
			print_prod(int n);
			printf("voulez-vous supprimer ce produit?|n");
		 	printf("taper votre choix: 1 :oui / 2:non|n");
         	scanf("%d",&choix);
         	if(choix==1)
			{
 			    suppr_prod(int n);
		 	}
		 	printf("le produit de numero de serie %d est supprrime|n",n);
 		else:
			else:
            	{break;}
			printf("le produit que vous souhaitez de le modifier n'existe pas ou le numero de serie est incorrect|n");
			printf("ressayer de nouveau|n");
        
        
        break;
case'4':printf("entrer le numero de serie de produit ");
		scanf("%d",n);
		if(recherche_prod(int n))
   		{
			print_prod(int n);
    	}
    	else:
			printf("le produit que vous souhaitez de le modifier n'existe pas ou le numero de serie est incorrect|n");
			printf("ressayer de nouveau|n");
         break;
case'5':printf("entrer le numero de serie de produit ");
		scanf("%d",n);
		recherche_prod(int n);
        break;
case'6':
        break;
};while(op>=1&&op<=6)
        
        
getch();
return 0;
}

