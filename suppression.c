#include <stdio.h>
#include <stdlib.h>
#include"struct.h"
#include<conio.h>


void supprimerproduit(){
produit p;
int n;
char rep ;
int idrech;
printf("donner l'idendifiant de produit a supprimer:");
scanf("%d",&idrech);
if(rech(idrech)==1){
   // printf("\n Voulez Vous Vraimment Supprimer o/n ?");
    //scanf("%c",&rep);
    //fflush(stdin);

        FILE *F,*Fich;
        F=fopen("stock.txt","r");
        Fich=fopen("tempstock.txt","a");
         n=nombre_de_produit();
        for(int j=0;j<n;j++){
           fscanf(F, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", &p.nom, &p.id, &p.pa, &p.pv, &p.quant, &p.fragilite, &p.importance, &p.delai.jj, &p.delai.mm, &p.delai.aa);
        if(idrech!=p.id){
                fprintf(Fich, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", p.nom, p.id, p.pa, p.pv, p.quant, p.fragilite, p.importance, p.delai.jj, p.delai.mm, p.delai.aa);

        }
}fclose(Fich);
fclose(F);
remove("stock.txt");
rename("tempstock.txt","stock.txt");
printf("suppression Effectue avec Succees");
}



else{
    printf("\n ce produit n'existe pas");
}
}




