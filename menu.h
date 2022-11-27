//
// Created by lepou on 15/11/2022.
//

#ifndef ECE_CITY_1_G1_MENU_H
#define ECE_CITY_1_G1_MENU_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

///////////////////ARGENT
#define ECEFLOUZ 500000

#define CENTRALE 100000
#define CHATEAUDEAU 100000
#define ROUTE 10
#define TERRAINVAGUE 100000
#define LO_FENETRE 1024
#define LA_FENETRE 768





////////////////////////HABITANT
#define TERRAINVAGUEHABITANT 0
#define CABANEHBAITANT 10
#define MAISONHABITANT 50
#define IMMEUBLEHABITANT 100
#define GRATTECIELHABITANT 1000


typedef struct{
    int Y,X;
    int ruines, terrainvague, cabane, maison, immeuble, gratteciel,centrale,chateaudeau;
    int obstacle;
    int routes;
    int constructions;
    int niveaubatiment;
    int habitations;
    int habitants;
}Cases;

typedef struct {
    int argent;
    int habitants;
    int capacites;

}Maire;
typedef struct{
    ALLEGRO_FONT *font,*font2,*font3,*font4;
}Fonts;




void dessinerMenu(ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2 );

void regles(Fonts fonts);

void choixDebut(int x, int y,bool *etatDebut,bool *etatRegles, ALLEGRO_TIMER* timermenu);
void dessinerfond(ALLEGRO_BITMAP *imagefond);
#endif //ECE_CITY_1_G1_MENU_H
