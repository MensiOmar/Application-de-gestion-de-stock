#include <stdio.h>
#include <stdlib.h>
#include"struct.h"
#include<conio.h>
void main()
{
int choix,h;
char ch[100],his[100];
 while(choix != 8)
 {
 /********** Affichage du menu **********/
 do
 {
   system("cls");
  system("COLOR 6");
  printf("    \t\t  ********************\n");
printf("    \t\t  * GESTION DE STOCK *\n");
printf("     \t\t  ********************\n");
   printf("*********************************************************");
   printf("\n*********\t\tBienvenue\t\t*********");
   printf("\n*********************************************************");
   printf("\t\n* Veuillez Choisir une option:\t\t\t\t*");
   printf("\t\n*  1- Ajouter un produit dans le stock\t\t\t*");
   printf("\t\n*  2- Modifier les coordonnees d'un produit\t\t*");
   printf("\t\n*  3- Supprimer un produit\t\t\t\t*");
   printf("\t\n*  4- Rechercher un produit\t\t\t\t*");
   printf("\t\n*  5- Afficher tous les produits\t\t\t*");
   printf("\t\n*  6- Historique selon mois\t\t\t\t*");
   printf("\t\n*  7- Historique selon jours\t\t\t\t*");
   printf("\t\n*  8- Quitter le programme\t\t\t\t*");
   printf("\t\n>>>>> tapez votre choix:");
   fflush(stdin);
   scanf("%s",ch);
   choix=atoi(ch);
  } while( (choix<1)||(choix>8) );
      
  switch(choix)
  {
        case 1 :
        {
        system("cls");
		printf("\nAJOUT D'UN PRODUIT\n\n");
		ajout_produit();
        printf("\nOPERATION D'AJOUT EFFECTUEE !\n\n");
        printf("=====appuiez sur un boutton pour retourner au menu principal :");
        scanf("%s");
        break;
    	}
        case 2 :
        {    
        	system("cls");
			printf("\nMODIFICATION D'UN PRODUIT\n\n");
        	ModifierProduit();
			printf("=====appuiez sur un boutton pour retourner au menu principal :");
        	scanf("%s");
            break;
		}
    	case 3 :
          {
            system("cls");
            printf("\nSUPPRESSION D'UN PRODUIT\n\n"); 
            supprimerproduit();
			printf("=====appuiez sur un boutton pour retourner au menu principal :");
            scanf("%s");
            break;
          }
        case 4 :
          {
            system("cls");
            printf(" RECHERCHE D'UN PRODUIT\n\n");
            recherche_affichage();
			printf("=====appuiez sur un boutton pour retourner au menu principal :");
            scanf("%s");
            break;
          }
		  case 5 :
		  {
			system("cls");
			printf(" VOS PRODUITS DISPONIBLES\n\n");
			affichage();
			printf("=====VOS PRODUIT SONT AFFICHE\n\n");
			printf("=====appuiez sur un boutton pour retourner au menu principal :");
			scanf("%s");
			break;
		  }
		  case 6 :
		  {
   			system("cls");
			printf(" HISTORIQUE\n\n");
			recherche_historique_mois();
			printf("=====appuiez sur un boutton pour retourner au menu principal :");
			scanf("%s");
			break;
		  }
		  case 7 :
		  {
			system("cls");
			printf(" HISTORIQUE\n\n");
			recherche_historique();
			printf("=====appuiez sur un boutton pour retourner au menu principal :");
			scanf("%s");
			break;
		  }		   		
	}
  }

}





