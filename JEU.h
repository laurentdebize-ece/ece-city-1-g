//
// Created by lepou on 15/11/2022.
//

#ifndef ECE_CITY_1_G1_JEU_H
#define ECE_CITY_1_G1_JEU_H
#include "menu.h"

void initialisationresource(Maire* maire);
void affichageressources(Maire* maire, Fonts fonts);
void dessinerplateau();
void dessinerBoutons(Fonts fonts,ALLEGRO_BITMAP* imageville,ALLEGRO_BITMAP* imageeau,ALLEGRO_BITMAP* imageRoutes40x40, ALLEGRO_BITMAP* imageelec);
void choixfleches(ALLEGRO_EVENT event,bool* etage0,bool* etage_1,bool* etage_2);
void dessinerTout(bool * etatdebut,ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2, bool* etatregle,Maire* maire, ALLEGRO_BITMAP* imagefond, ALLEGRO_BITMAP* imageflechehaut,ALLEGRO_BITMAP* imageflechebas,bool* etage0,bool* etage_1,bool* etage_2,int x1,int x2,int y1,int y2, ALLEGRO_BITMAP*imageRoutes40x40,ALLEGRO_EVENT event, ALLEGRO_BITMAP*imageRoutes,int etage, ALLEGRO_BITMAP* imageelec ) ;
void changementetage(ALLEGRO_EVENT event,bool* etage0,bool* etage_1,bool* etage_2,int etage);
void choixBoutons(ALLEGRO_EVENT event,int x1,int x2,int y1,int y2,ALLEGRO_BITMAP* imageRoutes);
#endif //ECE_CITY_1_G1_JEU_H
