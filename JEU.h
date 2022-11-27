//
// Created by lepou on 15/11/2022.
//

#ifndef ECE_CITY_1_G1_JEU_H
#define ECE_CITY_1_G1_JEU_H
#include "menu.h"

void initialisationresource(Maire* maire);
void affichageressources(Maire* maire, Fonts fonts);
void dessinerplateau();
void dessinerBoutons(Fonts fonts,ALLEGRO_BITMAP* imageville,ALLEGRO_BITMAP* imageeau,ALLEGRO_BITMAP* imageRoutes40x40, ALLEGRO_BITMAP* imageelec,ALLEGRO_BITMAP* imageMaison,ALLEGRO_BITMAP* imageCentrale, ALLEGRO_BITMAP* imageChateaudeau,ALLEGRO_BITMAP* imagecurseur);

void dessinerTout(bool *etatdebut, ALLEGRO_BITMAP *imagemenu, Fonts fonts, ALLEGRO_TIMER *timer2, bool *etatregle,
                  Maire *maire, ALLEGRO_BITMAP *imagefond, ALLEGRO_BITMAP *imageville, ALLEGRO_BITMAP *imageeau,
                  bool *etage0, bool *etage_1, bool *etage_2, int x1, int x2, int y1, int y2,
                  ALLEGRO_BITMAP *imageRoutes40x40, ALLEGRO_EVENT event, ALLEGRO_BITMAP *imageRoutes, int etage,
                  ALLEGRO_BITMAP *imageelec, ALLEGRO_BITMAP *imageMaison, ALLEGRO_BITMAP *imageCentrale,
                  ALLEGRO_BITMAP *imageChateaudeau, ALLEGRO_BITMAP *imagecurseur, Cases cases[35][45], bool *curseur,
                  bool *routes, ALLEGRO_BITMAP *imageroutes, bool *jeu, ALLEGRO_BITMAP *imagemaisonplateau,
                  bool *habitations, bool *centrale, bool *chateaudeau, ALLEGRO_BITMAP *imagecentralegrande,
                  ALLEGRO_BITMAP *imagechateaudeaugrand, ALLEGRO_BITMAP* imagecabane, ALLEGRO_BITMAP* imageterrainvague, ALLEGRO_BITMAP* imageimmeuble, ALLEGRO_BITMAP* imagegratteciel);

        void changementetage(ALLEGRO_EVENT event,bool* etage0,bool* etage_1,bool* etage_2,int etage);
void choixBoutons(ALLEGRO_EVENT event,int x1,int x2,int y1,int y2,ALLEGRO_BITMAP* imageRoutes, bool* etage0,bool* etage_1,bool* etage_2) ;
void affichageroute(Cases cases[35][45],ALLEGRO_BITMAP* imagesroute);

void detectionboutons(ALLEGRO_EVENT event,bool* curseur,bool* routes,bool* habitations,bool*centrales,bool*chateaudeau,int bouton);

void definirRoutes(ALLEGRO_EVENT event,bool routes, Cases cases[35][45], Maire* maire) ;
void affichageMaison(Cases cases[35][45],ALLEGRO_BITMAP* imagesmaisonplateau);
void definirMaison(ALLEGRO_EVENT event,bool habitations, Cases cases[35][45], Maire* maire) ;

void affichageelectricite(Cases cases [35][45]);
void affichageeau(Cases cases [35][45]);
void verificationcases(Cases cases[35][45]);

void definirChateaudeau(ALLEGRO_EVENT event, bool chateaudeau, Cases cases[35][45], Maire *maire) ;
void definircentrale(ALLEGRO_EVENT event, bool centrale, Cases cases[35][45], Maire *maire) ;
void affichageCentrale(Cases cases[35][45], ALLEGRO_BITMAP *imagesCentralegrande) ;
void affichageChateaudeau(Cases cases[35][45], ALLEGRO_BITMAP *imagechateaudeau) ;


void affichageImmeuble(Cases cases [35][45],ALLEGRO_BITMAP* imagesimmeuble);
void affichageCabane(Cases cases [35][45],ALLEGRO_BITMAP* imagescabane);
void affichageGratteciel(Cases cases [35][45],ALLEGRO_BITMAP* imagesgratteciel);
void affichageTerrainvague(Cases cases [35][45],ALLEGRO_BITMAP* iamgesterrainvague);
void changementhabitations(ALLEGRO_TIMER* timer3,Cases cases [35][45],ALLEGRO_BITMAP* imagescabane,ALLEGRO_BITMAP*imageterrainvague, ALLEGRO_BITMAP*imagemaison, ALLEGRO_BITMAP*imageimmeuble, ALLEGRO_BITMAP* imagegratteciel);

void affichagehabitations(Cases cases[35][45], ALLEGRO_BITMAP *imagesmaisonplateau,ALLEGRO_BITMAP* imagescabane,ALLEGRO_BITMAP* imagesterrainvague,ALLEGRO_BITMAP* imagesimmeuble,ALLEGRO_BITMAP* imagesgratteciel,Maire* maire) ;


#endif //ECE_CITY_1_G1_JEU_H
