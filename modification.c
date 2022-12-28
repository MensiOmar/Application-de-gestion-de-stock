#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
#include"struct.h"
void ModifierProduit(){
    action act;
    produit p;
    FILE *F,*Fich,*l; 
    int num,i, choix,j;
    printf("\n Entrer l'id du produit a modifier: ");
    scanf("%d",&num);
    fflush(stdin);
    if(rech(num)==1){
        printf("!!!!!voulez vous vraiment modifier: 1:oui/2:non\n");
        printf("choix: ");
        scanf("%d",&choix);
        fflush(stdin);
        if(choix==1){
            F=fopen("stock.txt","r");
            Fich=fopen("tempstock.txt","a");
            
            do{
                fscanf(F, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", &p.nom, &p.id, &p.pa, &p.pv, &p.quant, &p.fragilite, &p.importance, &p.delai.jj, &p.delai.mm, &p.delai.aa);
                
                if(num==p.id){
                    j=p.quant;
                    p.id=num;
                    printf("Nom du produit: %s\n",p.nom);
                    printf("ID du produit: %d\n",p.id);
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
                    if(p.quant>j){
                        act.type=1;
                        act.quant=p.quant-j;
                    }
                    if(p.quant<j){
                        act.type=2;
                        act.quant=j-p.quant;
                    }
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
                    printf("donner la date de la modification de ce produit: \n");
                    act.date_act=saisie_date(act.date_act);
                    printf("donner l'heure de la modification de ce produit: \n");
                    act.heure_act=saisie_heure(act.heure_act);
                    printf("\n le produit a ete modifie \n");
                }
                fprintf(Fich,"Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", p.nom, p.id,p.pa,p.pv,p.quant,p.fragilite,p.importance,p.delai.jj,p.delai.mm,p.delai.aa);
            }while(!feof(F));
            l=fopen("historique.txt","a");
            fprintf(l,"type: %d\tquantite: %d nom du produit: %s\t date d'action: %d/%d/%d\t heure d'action: %d:%d\n",act.type,act.quant,p.nom,act.date_act.jj,act.date_act.mm,act.date_act.aa,act.heure_act.hh,act.heure_act.mm);
            fclose(l);
            fclose(F);
            fclose(Fich);
            remove("stock.txt");
            rename("tempstock.txt","stock.txt");

        }
        else{printf("\n modification annule \n");}
    }
    else{printf("\n id n'exsiste pas \n");}
}
