//
// Created by lepou on 15/11/2022.
//

#ifndef ECE_CITY_1_G1_PLATEAU_H
#define ECE_CITY_1_G1_PLATEAU_H

#define XDepart 124
#define YDepart 0

#include "menu.h"


void dessinerLigne();
void inisitialisationcases(Cases cases[35][45]);

void affichagetimer(Fonts fonts,ALLEGRO_TIMER* timer2);

void detectioncaseSouris(ALLEGRO_EVENT event, int* x1, int* y1, int* x2, int* y2);
void affichageElmentSouris(ALLEGRO_EVENT event, int x1, int y1, int x2, int y2, bool curseur, bool routes, ALLEGRO_BITMAP* imageroutes);

#endif //ECE_CITY_1_G1_PLATEAU_H
