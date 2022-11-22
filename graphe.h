//
// Created by lepou on 22/11/2022.
//

#ifndef MAIN_C_GRAPHE_H
#define MAIN_C_GRAPHE_H

typedef int typage;


struct _cellule {
    typage element;
    struct _cellule *suivant;
};

typedef struct _cellule* Cellule;

/* Structure d'un arc*/
struct Arc
{
    int sommet; // numero de sommet d'un arc adjacent au sommet initial
    int valeur;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc;
    int valeur;
    char couleur;
    int date;

};

typedef struct Sommet* pSommet;

typedef struct Graphe
{
    int taille;
    int orientation;
    int ordre;

    pSommet* pSommet;
} Graphe;


struct _file {
    int longueur;
    Cellule tete;
    Cellule queue;
};

typedef struct _file* File;


#endif //MAIN_C_GRAPHE_H
