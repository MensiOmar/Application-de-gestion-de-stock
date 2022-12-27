#include <stdlib.h>
#include <stdio.h>
#include"struct.h"
void ModifierProduit(){
    produit p;
    FILE*F,*FICH; 
    int num,i, choix;
    printf("\n Entrer l'id du produit a modifier: ");
    scanf("%d",&num);
    fflush(stdin);
    if(rech(num)==1){
        printf("!!!!!voulez vous vraiment modifier: 1:oui/2:non\n");
        scanf("%d",&choix);
        fflush(stdin);
        if(choix==1){
            F=open("stock.txt","r");
            FICH=open("tempstock.txt","a");
            do{
                fscanf(F, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", &p.nom, &p.id, &p.pa, &p.pv, &p.quant, &p.fragilite, &p.importance, &p.delai.jj, &p.delai.mm, &p.delai.aa);
                if(num==p.id){
                    p.id=num;
                    printf("Nom du produit: %s",p.nom);
                    printf("ID du produit: %d",p.id);
                    do{
                        printf("nouveau prix d'achat: ");
                        scanf("%d",&p.pa);
                    }while(p.pa<0);
                    do{
                        printf("nouveau prix de vente: ");
                        scanf("%d",&p.pv);
                    }while(p.pv<0);
                    do{
                        printf("nouvelle quantite: ");
                        scanf("%d",&p.quant);
                    }while(p.quant<0);
                    
                    printf("nouvelle importance:\t ");
                    printf("1: tres important\t");
                    printf("2: importance moyenne\t");
                    printf("3: non important\n");

                    do{

                    printf("choix: ");
                    scanf("%d",&p.importance);
                    }while(p.importance!=1&&p.importance!=2&&p.importance!=3);

                    printf("nouvelle date d'expiration:\n ");
                    p.delai=saisie_date(p.delai);
                    printf("\n le produit a ete modifie \n");
                }
                fprintf(FICH,"Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", p.nom, p.id,p.pa,p.pv,p.quant,p.fragilite,p.importance,p.delai.jj,p.delai.mm,p.delai.aa);
            }while(!feof(F));
            fclose(F);
            fclose(FICH);
            remove("stock.txt");
            rename("tempstock.txt","stock.txt");

        }
        else{printf("\n modification annule \n");}
    }
    else{printf("\n id n'exsiste pas \n");}
}