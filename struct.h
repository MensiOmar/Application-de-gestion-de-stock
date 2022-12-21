#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
typedef struct date{
    int jj ;//jour//
    int mm ;//moi//
    int aa ;//annee//
}date;

typedef struct heure{

    int mm ;//minute//
    int hh; //heure//
}heure;

typedef struct action{
    int type; //1 ou 2//
    int quant; //quantite entree ou sortie//
    char prod[100];  //nom du produit//
    date date_act; //date d'action//
    heure heure_act; //heure de l'action//
    //char depot //nom du depot//
}action;

typedef struct produit{
    int pa; //prix d'achat//
    int pv; //prix de vente//
    char nom[100];  //nom du produit//
    date delai; //date d'expiration//
    //char depot //nom du depot//
    int quant; //quantite totale du produit//
    int fragilite; // 1:fragile ou 2:non fragile//
    int id; //id du produit//
    int importance; //1: tres important, 2: importance moyenne, 3: non important//


}produit;
//liste chainé du produit
typedef struct noeud{
produit produit ;
struct noeud * suiv;
}noeudprod;
//liste chainé action
typedef struct noeudact{
produit produit ;
struct noeud * suiv;
}noeudact;
// Initialisation de la liste vide
void initialiser_liste_produit (noeudprod * L);
void initialiser_liste_action (noeudact * L);


heure saisie_heure(heure heure);
date saisie_date(date date);
//void saisie_depot(depot depot);
produit saisie_produit(produit produit);
action saisie_action(action act);
void print_date(date date);
void print_produit( produit prod);
void print_heure(heure heure);
void print_action(action act);
#endif // STRUCT_H_INCLUDED
