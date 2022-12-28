#include <stdio.h>
#include <stdlib.h>
#include"struct.h"
#include<conio.h>
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
void recherche_affichage(){
      produit p;
    FILE *F;
    int n,idrech;

    F=fopen("stock.txt","r");
    printf("donner l'id du produit a recherche");
    scanf("%d",&idrech);
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
  printf(F, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", p.nom, p.id,p.pa,p.pv,p.quant,p.fragilite,p.importance,p.delai.jj,p.delai.mm,p.delai.aa);

}
            }
      fclose(F);
      printf("produit non existant");

}
