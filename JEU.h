//
// Created by lepou on 15/11/2022.
//

#ifndef ECE_CITY_1_G1_JEU_H
#define ECE_CITY_1_G1_JEU_H
#include "menu.h"

void initialisationresource(Maire* maire);
void affichageressources(Maire* maire, Fonts fonts);
void dessinerplateau();
void dessinerfleche(ALLEGRO_BITMAP* imagefleche1,ALLEGRO_BITMAP* imagefleche2);
void dessinerTout(bool * etatdebut,ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2, bool* etatregle,Maire* maire, ALLEGRO_BITMAP* imagefond, ALLEGRO_BITMAP* imageflechehaut,ALLEGRO_BITMAP* imageflechebas,bool* etage0,bool* etage_1,bool* etage_2,int x1,int x2,int y1,int y2 );        void choixfleches(int x, int y,bool* etage0,bool* etage_1,bool* etage_2);
#endif //ECE_CITY_1_G1_JEU_H
