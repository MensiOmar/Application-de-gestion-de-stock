#include <stdio.h>
#include <stdlib.h>
#include"struct.h"
int nombre_de_produit(){
   //calclule le nombre de produit
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
return nbl-1;

}
void import_produit_fichier(){
produit p;
int n;


      FILE *f;
      f = fopen("stock.txt", "r");

         if(f==NULL){
             printf("Erreur lors de l'ouverture d'un fichier");
                              exit(1);
            }
            n=nombre_de_produit();
             // lire les donn�es � partie de fichier
             for(int j=0;j<n-1;j++){
fscanf(f, "Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", &p.nom, &p.id, &p.pa, &p.pv, &p.quant, &p.fragilite, &p.importance, &p.delai.jj, &p.delai.mm, &p.delai.aa);


            // afficher les donn�es charg�es
          printf("Nom : %s\tID : %d\tprixachat : %d\tprixvente : %d\tquantite : %d\tfrag : %d\timpor : %d\tdate d'expiration : %d/%d/%d\n", p.nom, p.id,p.pa,p.pv,p.quant,p.fragilite,p.importance,p.delai.jj,p.delai.mm,p.delai.aa);

            }

                     fclose(f);
}

