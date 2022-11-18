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
                  ALLEGRO_BITMAP *imageChateaudeau, ALLEGRO_BITMAP *imagecurseur, Cases cases [45][35],bool* curseur, bool* routes,ALLEGRO_BITMAP*imageroutes);

void changementetage(ALLEGRO_EVENT event,bool* etage0,bool* etage_1,bool* etage_2,int etage);
void choixBoutons(ALLEGRO_EVENT event,int x1,int x2,int y1,int y2,ALLEGRO_BITMAP* imageRoutes, bool* etage0,bool* etage_1,bool* etage_2) ;
void affichageroute(Cases cases[45][35],ALLEGRO_BITMAP* imagesroute);

void detectionboutons(ALLEGRO_EVENT event,bool* curseur,bool* routes,bool* habitations,bool*centrales,bool*chateaudeau,int bouton);

void definirRoutes(ALLEGRO_EVENT event, bool routes, Cases cases[45][35], Maire maire);

#endif //ECE_CITY_1_G1_JEU_H
