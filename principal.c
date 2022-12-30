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
   printf("\nGESTION DE STOCK\n");
   printf("\n* 1 *\tAjouter un produit dans le stock");
   printf("\n* 2 *\tModifier les coordonnees d'un produit");
   printf("\n* 3 *\tSupprimer un produit");
   printf("\n* 4 *\tRechercher un produit");
   printf("\n* 5 *\tAfficher tous les produits");
   printf("\n* 6 *\tHistorique selon mois");
   printf("\n* 7 *\tHistorique selon jours");
   printf("\n* 8 *\tQuitter le programme"); 
   printf("\n\n\t>>\tTapez votre choix : ");
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
        printf("\nOPERATION D'AJOUT EFFECTUEE !");
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





