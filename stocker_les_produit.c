#include <stdlib.h>
#include <stdio.h>
#include"struct.h"




void ajout_produit( ){

    produit pt;
    int choix;

    

            FILE *f;
    produit p;
    f = fopen("stock.txt", "a");
     if(f==NULL){
         printf("Erreur lors de l'ouverture d'un fichier");
                exit(1);
                     }
        printf("\nDonner un produit :\n ");
        pt=saisie_produit(pt);
        fprintf(f, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", pt.nom, pt.id,pt.pa,pt.pv,pt.quant,pt.fragilite,pt.importance,pt.delai.jj,pt.delai.mm,pt.delai.aa);

       // fprintf(f,"\n");
        fclose(f);
       



}













