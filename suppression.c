#include <stdio.h>
#include <stdlib.h>
#include"struct.h"
#include<conio.h>
void supprimerproduit(){
action act;
produit p;
int n ,choix ;
int idrech;
FILE *F,*Fich,*l;
printf("donner l'idendifiant de produit a supprimer:");
scanf("%d",&idrech);
if(rech(idrech)==1){
    printf("\n Voulez Vous Vraimment Supprimer 1:oui/2:non\n ?");
    printf("choix: ");
    scanf("%d",&choix);
    fflush(stdin);
    if(choix==1){
        F=fopen("stock.txt","r");
        Fich=fopen("tempstock.txt","a");
        n=nombre_de_produit();
        printf("donner la date de la suppression de ce produit: \n");
        act.date_act=saisie_date(act.date_act);
        printf("donner l'heure de la suppression de ce produit: \n");
        act.heure_act=saisie_heure(act.heure_act);
        for(int j=0;j<n;j++){
           fscanf(F, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", &p.nom, &p.id, &p.pa, &p.pv, &p.quant, &p.fragilite, &p.importance, &p.delai.jj, &p.delai.mm, &p.delai.aa);
        if(idrech==p.id){
            l=fopen("historique.txt","a");
            fprintf(l,"type: %d\tquantite: %d nom du produit: %s\t date d'action: %d/%d/%d\t heure d'action: %d:%d\n",2,p.quant,p.nom,act.date_act.jj,act.date_act.mm,act.date_act.aa,act.heure_act.hh,act.heure_act.mm);   
            fclose(l);
        }
        if(idrech!=p.id){
                fprintf(Fich, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", p.nom, p.id, p.pa, p.pv, p.quant, p.fragilite, p.importance, p.delai.jj, p.delai.mm, p.delai.aa);
          
}
}
    }
    else{
        printf("supression annule");
        }

}
else{
    printf("\n ce produit n'existe pas");
}
fclose(Fich);
fclose(F);
remove("stock.txt");
rename("tempstock.txt","stock.txt");
printf("suppression Effectue avec Succees");
}







