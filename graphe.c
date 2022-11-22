//
// Created by lepou on 22/11/2022.
//
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "graphe.h"
/*void afficher_successeurs(pSommet *sommet, int num) {

    printf(" sommet %d :\n", num);

    pArc arc = sommet[num]->arc;

    while (arc != NULL) {
        printf("%d ", arc->sommet);
        arc = arc->arc_suivant;
    }

}

// Ajouter l'arete entre les sommets s1 et s2 du graphe
pSommet *CreerArete(pSommet *sommet, int s1, int s2, int poids) {
    if (sommet[s1]->arc == NULL) {
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->valeur = poids;
        Newarc->arc_suivant = NULL;
        sommet[s1]->arc = Newarc;
        return sommet;
    } else {
        pArc temp = sommet[s1]->arc;
        while (!(temp->arc_suivant == NULL)) {
            temp = temp->arc_suivant;
        }
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->valeur = poids;
        Newarc->arc_suivant = NULL;

        if (temp->sommet > s2) {
            Newarc->arc_suivant = temp->arc_suivant;
            Newarc->sommet = temp->sommet;
            temp->sommet = s2;
            Newarc->valeur = poids;
            temp->arc_suivant = Newarc;
            return sommet;
        }

        temp->arc_suivant = Newarc;
        return sommet;
    }
}

// creer le graphe
Graphe *CreerGraphe(int ordre, int poids) {
    Graphe *Newgraphe = (Graphe *) malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet *) malloc(ordre * sizeof(pSommet));


    for (int i = 0; i < ordre; i++) {
        Newgraphe->pSommet[i] = (pSommet) malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->valeur = i;
        Newgraphe->pSommet[i]->arc = NULL;
    }
    return Newgraphe;
}
void affichage(Graphe *graphe, int *preds) {

    for (int i = 0; i < graphe->ordre; ++i) {
        if (preds[i] != -1) {
            int k = i;
            printf("%d", k);
            while (preds[k] != -1) {
                printf("<--%d", preds[k]);
                k = preds[k];
            }
            printf("\n");
        }


    }
}

*/
/*affichage du graphe avec les successeurs de chaque sommet */
/*
void graphe_afficher(Graphe *graphe) {
    printf("graphe\n");

    if (graphe->orientation)
        printf("oriente\n");
    else
        printf("non oriente\n");

    printf("ordre = %d\n", graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i = 0; i < graphe->ordre; i++) {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}




//fonction donnee a titre d'exemple d'utilisation de file
File exemple_remplir_file() {
    //initialisation
    File file = fileVide();
    //on remplit avec les entiers de 1 à 10
    int i;
    printf("Etat de la file : ");
    afficherFile(file);
    for (i = 1; i < 10; i++) {
        enfiler(file, i);
        printf("Etat de la file : ");
        afficherFile(file);
    }
    return file;
}

//fonction donnee a titre d'exemple d'utilisation de file
void exemple_vider_file(File file) {
    //tant que la file n'est pas vide, on défile
    while (!fileEstVide(file)) {
        int element = defiler(file);
        printf("element defile : %d\n", element);
        printf("Etat de la file : ");
        afficherFile(file);
    }
}



void algoDijkstra (Graphe *graphe, int sommetDebut, int sommetFin){
    int* preds = (int*)malloc(graphe->ordre * sizeof (int));
    int distance[graphe->ordre];
    int fin = 0;
    pArc arc = graphe->pSommet[sommetDebut]->arc;
    distance[sommetDebut] = 0;
    graphe->pSommet[sommetDebut]->couleur = 1;



    for (int i = 0; i<graphe->ordre; i++)graphe->pSommet[i]->couleur = 0;

    for (int i = 0; i<graphe->ordre; i++){
        preds[i] = distance[i] = 1000;
    }
    while (arc != NULL){
        distance[arc->sommet]+=arc->valeur;
        preds[arc->sommet]=sommetDebut;
        arc = arc->arc_suivant;
    }

    while(fin == 0){
        int poidsChemin = 1000;
        int tmp = -1;
        for(int i = 0; i<graphe->ordre;++i) {
            if (distance[i]<poidsChemin && graphe->pSommet[i]->couleur == 0 && distance[i]!= 10000){
                poidsChemin = distance[i];
                tmp = 1;
            }
        }
        graphe->pSommet[tmp]->couleur = 1;
        arc = graphe->pSommet[tmp]->arc;
        while(arc!=NULL){
            if(arc->valeur + poidsChemin<distance[arc->sommet] && graphe->pSommet[arc->sommet]->couleur == 0){
                distance[arc->sommet]=arc->valeur+poidsChemin;
                preds[arc->sommet]=tmp;
            }
            arc = arc->arc_suivant;
        }
        fin = 1;
        int k = sommetFin;
        printf("\nChemin : %d", k);
        while (preds[k]!=1000){
            printf("<--%d", preds[k]);
            k = preds[k];
        }
        printf("\n longueur chemin : %d", distance[sommetFin]);
    }
}

void bfs(Graphe *graphe, typage element) {

//initial
    for (int i = 0; i < graphe->ordre; i++)
        graphe->pSommet[i]->couleur = 0;

    int *preds = (int *) malloc(graphe->ordre * sizeof(int));
    for (int i = 0; i < graphe->ordre; i++) preds[i] = -1;


    File file = fileVide();
    enfiler(file, element);
    graphe->pSommet[element]->couleur = 1;
    while (file->tete != NULL) {
        int num = defiler(file);
        struct Arc *temp = graphe->pSommet[num]->arc;
        while (temp != NULL) {
            int num2 = temp->sommet;
            if (graphe->pSommet[num2]->couleur == 0) {
                enfiler(file, num2);
                graphe->pSommet[num2]->couleur = 1;
                preds[num2] = num;

            }
            temp = temp->arc_suivant;


        }


    }
    affichage(graphe, preds);


}*/