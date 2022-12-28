#include <stdlib.h>
#include <stdio.h>
#include"struct.h"
void ajout_produit( ){
    produit pt;
    int choix;
    action act;
        FILE *f,*l;
    produit p;
    f = fopen("stock.txt", "a+");
    l = fopen("historique.txt", "a+");
     if(f==NULL){
         printf("Erreur lors de l'ouverture d'un fichier");
                exit(1);
                     }
        printf("\nDonner un produit :\n ");
        pt=saisie_produit(pt);
        fprintf(f, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", pt.nom, pt.id,pt.pa,pt.pv,pt.quant,pt.fragilite,pt.importance,pt.delai.jj,pt.delai.mm,pt.delai.aa);
        act.type=1;
        act.quant=pt.quant;
        
        printf("donner la date de l'ajout de ce produit: \n");
        act.date_act=saisie_date(act.date_act);
        printf("donner l'heure de l'ajout de ce produit: \n");
        act.heure_act=saisie_heure(act.heure_act);

        fprintf(l,"type: %d\tquantite: %d nom du produit: %s\t date d'action: %d/%d/%d\t heure d'action: %d:%d\n",act.type,act.quant,pt.nom,act.date_act.jj,act.date_act.mm,act.date_act.aa,act.heure_act.hh,act.heure_act.mm);
       
        fclose(f);
        fclose(l);
}












