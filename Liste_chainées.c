#include <stdlib.h>
#include <stdio.h>
#include"struct.h"
typedef struct Noeud Noeud;
struct Noeud
{
    produit prod;
    struct Noeud *suivant;
};
typedef Noeud* Liste;
Liste ajout_queue(produit produit, Liste L){
    Liste p,Q;
    p = malloc(sizeof(produit));
    p->suivant=NULL;
    p->prod=produit;
    Q=L;
    while(Q->suivant){
        Q=Q->suivant;
    }
    Q->suivant = p;
    return L;
}
Liste ajout_tete(produit produit, Liste L){

    Liste p;
    p = malloc(sizeof(produit));
    p->suivant=L;
    p->prod=produit;
    L=p;
    return L;
}


Liste ajout_produit_Liste( Liste L){

    produit pt;
    int choix;
    L=NULL;
    

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
        L=ajout_tete(pt,L);

    //fprintf(f, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", (L->prod).nom, (L->prod).id,(L->prod).pa,(L->prod).pv,(L->prod).quant,(L->prod).fragilite,(L->prod).importance,(L->prod).delai.jj,(L->prod).delai.mm,(L->prod).delai.aa);

       // fprintf(f,"\n");
        //fclose(f);
       // printf("\nVoulez vous ajouter un nouveau produit (tapez \'1\' pour ajouter)");
        //scanf("%d",&choix);
   
    return L;
}













