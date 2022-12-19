#include <stdio.h>
#include "struct.h"
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
        printf("moi: ");
        scanf("%d",&date.mm);
    }while(date.mm>12||date.mm<1);

    do{
        printf("jour: ");
        scanf("%d",&date.jj);
    }while((((date.mm==1)||(date.mm==3)||(date.mm==5)||(date.mm==7)||(date.mm==8)||(date.mm==10)||(date.mm==12))&&date.jj>31)||(((date.mm==4)||(date.mm==6)||(date.mm==9)||(date.mm==11)||(date.mm==8))&&date.jj>30)||((date.mm==2)&&date.jj>29)||date.jj<1);

    return date;
}

/*void saisie_depot(depot depot)
{
        printf("nom du depot: ");
        scanf("%s",depot.nom);
        printf("adresse du depot: ");
        scanf("%s",depot.adresse);
}*/

produit saisie_produit(produit produit)
{
        int choix;
        printf("nom du produit: ");
        scanf("%s",produit.nom);


        /*printf("nom du depot de stockage");
        scanf("%s",&produit.depot);
        if(check_in(T,produit.depot)==-1){
            printf("ce depot n'est pas enregistre\n");
            printf("1-ajouter un nouveau depot\n");
            printf("2-resseyer\n");
            do{
            printf("choix: \n");
            scanf("%d",&choix);
        }while(choix!=1||choix!=2);
        if(choix==1){
            saisie_depot(depot);
            ajout_depot(depot);
        }
        else if(choix==1)


        }*/

    do{
        printf("prix d'achat: ");
        scanf("%d",&produit.pa);
    }while(produit.pa<0);

    do{
        printf("prix de vente: ");
        scanf("%d",&produit.pv);
    }while(produit.pv<0);

    do{
        printf("quantit�: ");
        scanf("%d",&produit.quant);
    }while(produit.quant<0);

    do{
        printf("id du produit: ");
        scanf("%d",&produit.id);
    }while(produit.id<0);

    printf("fragilit�:\t ");
    printf("1:fragile\t");
    printf("2:non fragile\n");

    do{

        printf("choix: ");
        scanf("%d",&produit.fragilite);
    }while(produit.fragilite!=1&&produit.fragilite!=2);

    printf("importance:\t ");
    printf("A: tres important\t");
    printf("B: importance moyenne\t");
    printf("C: non important\n");

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

    do{
        printf("produit non existant,resseyer: ");
        gets(act.prod);
    }while(check_nom_prod(liste_des_prods,act.prod)==-1);

    printf("date d'action: ");
    act.date_act=saisie_date(act.date_act);

    printf("date d'action: ");
    act.heure_act=saisie_heure(act.heure_act);
    printf("quantite: ");

    if(act.type==1||act.type==2)
    {
        scanf("%d",&act.quant);
    }

    else if(act.type==2)
    {
        do{
            printf("quantite non resonnable:");
            printf("quantite: ");
            scanf("%d",&act.quant);
        }while(recherche_prod(liste_des_produits,act.prod).quant<act.quant);
    }

    return act;
}
