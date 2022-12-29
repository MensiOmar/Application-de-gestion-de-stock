#include <stdio.h>
#include "struct.h"
//fonctions de saisie
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

produit saisie_produit(produit produit)
{
        int choix;
        printf("nom du produit: ");
        scanf("%s",&produit.nom);

    do{
        printf("prix d'achat: ");
        scanf("%d",&produit.pa);
    }while(produit.pa<0);

    do{
        printf("prix de vente: ");
        scanf("%d",&produit.pv);
    }while(produit.pv<0);

    do{
        printf("quantite: ");
        scanf("%d",&produit.quant);
    }while(produit.quant<0);

    do{
        printf("id du produit: ");
        scanf("%d",&produit.id);
        if(rech(produit.id==1)){
            printf("ce id existe deja !\n");
        }
    }while(produit.id<0||rech(produit.id==1));

    printf("fragilite:\t ");
    printf("1:fragile\t");
    printf("2:non fragile\n");

    do{

        printf("choix: ");
        scanf("%d",&produit.fragilite);
    }while(produit.fragilite!=1&&produit.fragilite!=2);

    printf("importance:\t ");
    printf("1: tres important\t");
    printf("2: importance moyenne\t");
    printf("3: non important\n");

    do{

        printf("choix: ");
        scanf("%d",&produit.importance);
    }while(produit.importance!=1&&produit.importance!=2&&produit.importance!=3);

    printf("date d'expiration:\n ");
    produit.delai=saisie_date(produit.delai);

    return produit;
}

action saisie_action(action act)
{
    printf("type d'action:\n ");
    printf("1:entree d'un produit\t");
    printf("2:sortie d'un produit\t");

    do{
        printf("choix: ");
        scanf("%d",&act.type);
    }while(act.type!=1&&act.type!=2);

    printf("nom du produit: ");
    scanf("%s",act.prod);

    /*do{
        printf("produit non existant,resseyer: ");
        gets(act.prod);
    }while(check_nom_prod(liste_des_prods,act.prod)==-1);*/

    printf("date d'action: ");
    act.date_act=saisie_date(act.date_act);

    printf("date d'action: ");
    act.heure_act=saisie_heure(act.heure_act);
    printf("quantite: ");

    if(act.type==1||act.type==2)
    {
        scanf("%d",&act.quant);
    }

    /*else if(act.type==2)
    {
        do{
            printf("quantite non resonnable:");
            printf("quantite: ");
            scanf("%d",&act.quant);
        }while(recherche_prod(liste_des_produits,act.prod).quant<act.quant);
    }*/

    return act;
}
//procedures d'affichage 
void print_produit( produit prod){
    printf("***********************Nom: %s**********************\n",prod.nom);
    printf("***************************ID: %d*************************\n",prod.id);
    if(prod.importance==1){
        printf("**************Importance: %s**************\n","TRES IMPORTANT");
        }
    else if(prod.importance==2){
       printf("**************Importance: %s**************\n","Importance moyenne"); 
    }
    else{
        printf("**************Importance: %s**************\n","Importance moyenne");
    }
    if(prod.fragilite==1){
        printf("**************!!!!%s!!!!**************\n","FRAGILE");
        }
    else if(prod.fragilite==2){
       printf("**************~~~~%s~~~~**************\n","non fragile"); 
    }
    printf("\t\t Quanite: %d\n",prod.quant);
    printf("\t\t Prix de vente: %d\n",prod.pv);
    printf("\t\t Prix d'achat: %d\n",prod.pa);
    printf("\t\t Date d'expiration: ");
    print_date(prod.delai);
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void print_date(date date){
printf("%d/%d/%d",date.jj,date.mm,date.aa);
}
void print_heure(heure heure){
printf("%d:%d",heure.hh,heure.mm);
}
void print_action(action act){
   if(act.type==1){
        printf("**************~~~~%s~~~~**************\n","ENTREE D'UN PRODUIT");
        }
    else if (act.type==2){
       printf("**************~~~~%s~~~~**************\n","SORTIE D'UN PRODUIT"); 
    } 
    printf("\t\t Nom du produit: %s\n",act.prod);
    printf("\t\t Quanite: %d\n",act.quant);
    printf("\t\t Date d'action: ");
    print_date(act.date_act);
    printf("\n");
    printf("\t\t Heure d'action: ");
    print_date(act.date_act);
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
//supp
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

//rech
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
return nbl-1;

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
//modif
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
//ajout
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
void recherche_historique()
{ action act;
date d;
produit pt;
int n;
        FILE *l;
printf("donner la date de recherche dans l'historique :\n");
d=saisie_date(d);
  l = fopen("historique.txt", "r");
  if(l==NULL){
             printf("Erreur lors de l'ouverture d'un fichier");
                              exit(1);
            }
  n=nombre_de_produit();
  for(int i=0;i<n;i++){
  fscanf(l,"type: %d\tquantite: %d nom du produit: %s\t date d'action: %d/%d/%d\t heure d'action: %d:%d\n",&act.type,&act.quant,&pt.nom,&act.date_act.jj,&act.date_act.mm,&act.date_act.aa,&act.heure_act.hh,&act.heure_act.mm);
      if(d.aa==act.date_act.aa&&d.mm==act.date_act.mm&&d.jj==act.date_act.jj){ printf("type: %d\tquantite: %d nom du produit: %s\t date d'action: %d/%d/%d\t heure d'action: %d:%d\n",act.type,act.quant,pt.nom,act.date_act.jj,act.date_act.mm,act.date_act.aa,act.heure_act.hh,act.heure_act.mm);
      }
  }
        fclose(l);
}  