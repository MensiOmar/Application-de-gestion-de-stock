#include <stdio.h>
#include <stdlib.h>
#include"struct.h"
#include<conio.h>
heure saisie_heure(heure heure){
    int hh,mm;
    do{
        printf("heure: ");
        scanf("%d",&hh);
    }while(hh>24||hh<0);
    do{
        printf("minutes: ");
        scanf("%d",&mm);
    }while(mm>59||mm<0);
    heure.hh=hh;
    heure.mm=mm;
    return heure;
    
}
int nombre_de_produit(){
   //calclul du  nombre de produit
int c;
FILE *f;
      f = fopen("stock.txt", "r");
int nbl = 0;
while((c=fgetc(f)) != EOF)
{
	if(c=='\n')
		nbl++; 
}
 fclose(f);
return nbl;

}
int rech(int idrech)
{   produit p;
    FILE *F;
    int n;
    F=fopen("stock.txt","r");
if(F==NULL){
             printf("Erreur lors de l'ouverture d'un fichier");
                              exit(1);
            }
            n=nombre_de_produit();
             // lire les donnees a partir de fichier
             for(int j=0;j<n;j++){
fscanf(F, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", &p.nom, &p.id, &p.pa, &p.pv, &p.quant, &p.fragilite, &p.importance, &p.delai.jj, &p.delai.mm, &p.delai.aa);

if(idrech==p.id){
  fclose(F);
  return 1;
}
            }
      fclose(F);
      return -1;

}
date saisie_date(date date)
{
    do{
        printf("annee: ");
        scanf("%d",&date.aa);
    }while(date.aa>2100||date.aa<1900);

    do{
        printf("mois: ");
        scanf("%d",&date.mm);
    }while(date.mm>12||date.mm<1);

    do{
        printf("jour: ");
        scanf("%d",&date.jj);
    }while((((date.mm==1)||(date.mm==3)||(date.mm==5)||(date.mm==7)||(date.mm==8)||(date.mm==10)||(date.mm==12))&&date.jj>31)||(((date.mm==4)||(date.mm==6)||(date.mm==9)||(date.mm==11)||(date.mm==8))&&date.jj>30)||((date.mm==2)&&date.jj>29)||date.jj<1);

    return date;
}

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

int main(){
    supprimerproduit();
}







