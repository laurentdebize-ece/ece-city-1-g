//
// Created by lepou on 15/11/2022.
//

#include "plateau.h"


#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define LASTART 124


//124 longueur bonus
// 68 largeur bonus

void dessinerLigne() {
    for (int i = 124; i < LO_FENETRE; i = i + (LO_FENETRE - 124) / 44) {
        al_draw_line(i, 0, i, (LA_FENETRE - 68), al_map_rgb(0, 0, 0), 1);
    }
    for (int i = 0; i < LA_FENETRE - 68; i = i + (LA_FENETRE - 68) / 34) {
        al_draw_line(124, i, LO_FENETRE, i, al_map_rgb(0, 0, 0), 1);
    }

}

void dessinerplateau(){// fonction similaire a dessinerligne
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++){
            al_draw_rectangle(XDepart + (j*20), YDepart + (i*20), XDepart+ 20 + (j*20), YDepart + 20 + (i*20),
                              al_map_rgb(100,100,100),1);

        }
    }
}

void inisitialisationcases(Cases cases[35][45]){
    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 45; ++j) {
            cases[i][j].obstacle=0;
            cases[i][j].ruines=0;
            cases[i][j].terrainvague=0;
            cases[i][j].cabane=0;
            cases[i][j].maison=0;
            cases[i][j].immeuble=0;
            cases[i][j].gratteciel=0;
            cases[i][j].routes=0;
            cases[i][j].centrale=0;
            cases[i][j].chateaudeau=0;


        }

    }



}

void dessinerfond(ALLEGRO_BITMAP *imagefond){
    for (int i = 124; i < LO_FENETRE; i=i+(LO_FENETRE-124)/44) {
        for (int j = 0; j < LA_FENETRE-68; j=j+(LA_FENETRE-68)/34) {
            al_draw_bitmap(imagefond,i,j,0);

        }


    }
}


void affichagetimer(Fonts fonts,ALLEGRO_TIMER* timer2){
    al_draw_textf(fonts.font3, al_map_rgb(0,0,0),0,0,0,"Timer : %d",al_get_timer_count(timer2));
}


void detectioncaseSouris(ALLEGRO_EVENT event, int *x1, int *y1, int *x2, int *y2) {
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {

            if (event.mouse.x >= XDepart + (j * 20) && event.mouse.x <= 1024 && event.mouse.y >= (i*20) && event.mouse.y <= 20 + (i * 20)) {
                *x1 = XDepart + (j * 20);
                *x2 = XDepart + 20 + (j * 20);
                *y1 = (i * 20);
                *y2 = 20 + (i * 20);

            }

        }

    }
    if (event.mouse.x <= 124 || event.mouse.x >= 1024 || event.mouse.y <= 0 || event.mouse.y >= 700) {
        *x1 = 1100000;
        *x2 = 1100000;
        *y1 = 1100000;
        *y2 = 1100000;
    }
}









