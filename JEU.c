//
// Created by lepou on 15/11/2022.
//

#include "JEU.h"

#include "menu.h"
#include "plateau.h"
#include "stdio.h"


void dessinerTout(bool *etatdebut, ALLEGRO_BITMAP *imagemenu, Fonts fonts, ALLEGRO_TIMER *timer2, bool *etatregle,
                  Maire *maire, ALLEGRO_BITMAP *imagefond, ALLEGRO_BITMAP *imageville, ALLEGRO_BITMAP *imageeau,
                  bool *etage0, bool *etage_1, bool *etage_2, int x1, int x2, int y1, int y2,
                  ALLEGRO_BITMAP *imageRoutes40x40, ALLEGRO_EVENT event, ALLEGRO_BITMAP *imageRoutes, int etage,
                  ALLEGRO_BITMAP *imageelec, ALLEGRO_BITMAP *imageMaison, ALLEGRO_BITMAP *imageCentrale,
                  ALLEGRO_BITMAP *imageChateaudeau, ALLEGRO_BITMAP *imagecurseur, Cases cases[35][45], bool *curseur,
                  bool *routes, ALLEGRO_BITMAP *imageroutes, bool *jeu, ALLEGRO_BITMAP *imagemaisonplateau,
                  bool *habitations, bool *centrale, bool *chateaudeau, ALLEGRO_BITMAP *imagecentralegrande,
                  ALLEGRO_BITMAP *imagechateaudeaugrand) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (*etatdebut) {
        dessinerMenu(imagemenu, fonts, timer2);
    } else if (*etatregle) {
        regles(fonts);
    } else {
        al_clear_to_color(al_map_rgb(0, 100, 140));
        if (*etage0) { // horizon etage niveau 0




            dessinerfond(imagefond);


            dessinerLigne();
            affichageroute(cases, imageRoutes);
            affichageMaison(cases, imagemaisonplateau);
            affichageCentrale(cases, imagecentralegrande);
            affichageChateaudeau(cases,imagechateaudeaugrand);




            if (*curseur) {
                al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));




            }
            if (*routes) {
                al_draw_bitmap(imageroutes, x1, y1, 0);



            }
            if (*habitations) {
                al_draw_bitmap(imagemaisonplateau, x1, y1, 0);


            }
            if (*centrale) {
                al_draw_bitmap(imagecentralegrande, x1, y1, 0);

            }
            if (*chateaudeau) {
                al_draw_bitmap(imagechateaudeaugrand, x1, y1, 0);

            }


        } else if (*etage_1) {// niveau -1

                al_draw_filled_rectangle(124, 0, 1024, 700, al_map_rgb(0, 0, 0));

                affichageeau(cases);
                dessinerplateau();
                al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(150, 150, 150));

        } else { // niveau-2

                al_draw_filled_rectangle(124, 0, 1024, 700, al_map_rgb(0, 0, 50));
                affichageelectricite(cases);
                dessinerplateau();

                al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(150, 150, 150));



        }

        affichageressources(maire, fonts);
        affichagetimer(fonts, timer2);


        dessinerBoutons(fonts, imageville, imageeau, imageRoutes40x40, imageelec, imageMaison, imageCentrale,
                        imageChateaudeau, imagecurseur);


    }al_flip_display();


}

void initialisationresource(Maire *maire) {
    maire->argent = 500000;
    maire->capacites = 0;
    maire->habitants = 1;


}

void affichageressources(Maire *maire, Fonts fonts) {
    al_draw_filled_rectangle(0, 0, 123, 130, al_map_rgb(0, 100, 140));
    al_draw_textf(fonts.font4, al_map_rgb(255, 0, 0), 0, 30, 0, "Argent :");
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 0, 50, 0, "%d", maire->argent);
    al_draw_textf(fonts.font4, al_map_rgb(255, 0, 0), 0, 60, 0, "Habitants : ");
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 0, 80, 0, "%d", maire->habitants);
    al_draw_textf(fonts.font4, al_map_rgb(255, 0, 0), 0, 90, 0, "Capacités :");
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 0, 110, 0, "%d", maire->capacites);

}


void
dessinerBoutons(Fonts fonts, ALLEGRO_BITMAP *imageville, ALLEGRO_BITMAP *imageeau, ALLEGRO_BITMAP *imageRoutes40x40,
                ALLEGRO_BITMAP *imageelec, ALLEGRO_BITMAP *imageMaison, ALLEGRO_BITMAP *imageCentrale,
                ALLEGRO_BITMAP *imageChateaudeau, ALLEGRO_BITMAP *imagecurseur) {
    al_draw_bitmap(imageville, 10, 210, 0);
    al_draw_bitmap(imageeau, 10, 290, 0);
    al_draw_bitmap(imageelec, 10, 330, 0);

    al_draw_bitmap(imagecurseur, 0, 430, 0);
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 55, 450, 0, "Curseur");
    al_draw_bitmap(imageRoutes40x40, 5, 470, 0);
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 50, 480, 0, "Routes");
    al_draw_bitmap(imageMaison, 0, 520, 0);
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 50, 535, 0, "Habitations ");

    al_draw_bitmap(imageCentrale, 0, 570, 0);
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 55, 590, 0, "Centrale");
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 60, 605, 0, "Electrique");


    al_draw_bitmap(imageChateaudeau, 0, 620, 0);
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 55, 630, 0, "Chateau");
    al_draw_textf(fonts.font2, al_map_rgb(0, 0, 0), 60, 645, 0, "D'Eau");


}

void changementetage(ALLEGRO_EVENT event, bool *etage0, bool *etage_1, bool *etage_2, int etage) {

    if (event.mouse.x > 10 && event.mouse.x < 70 && event.mouse.y > 210 && event.mouse.y < 280) {
        etage = 0;
    }
    if (event.mouse.x > 10 && event.mouse.x < 70 && event.mouse.y > 285 && event.mouse.y < 330) {
        etage = -1;
    }
    if ((event.mouse.x > 10 && event.mouse.x < 70) && (event.mouse.y > 330 && event.mouse.y < 390)) {
        etage = -2;
    }
    if (etage == 0) {
        *etage0 = true;
        *etage_1 = false;
        *etage_2 = false;
    }
    if (etage == -1) {
        *etage0 = false;
        *etage_1 = true;
        *etage_2 = false;
    }
    if (etage == -2) {
        *etage0 = false;
        *etage_1 = false;
        *etage_2 = true;
    }

}

void detectionboutons(ALLEGRO_EVENT event, bool *curseur, bool *routes, bool *habitations, bool *centrales,
                      bool *chateaudeau, int bouton) {

    if (event.mouse.x > 0 && event.mouse.x < 40 && event.mouse.y > 430 && event.mouse.y < 470) {//bouton curseur
        bouton = 0;
        *curseur = true;
        *routes = false;
        *habitations = false;
        *centrales = false;
        *chateaudeau = false;

    }
    if (event.mouse.x > 0 && event.mouse.x < 60 && event.mouse.y > 470 && event.mouse.y < 510) {//bouton routes

        *routes = true;
        *curseur = false;
        *habitations = false;
        *centrales = false;
        *chateaudeau = false;
    }
    if (event.mouse.x > 4 && event.mouse.x < 60 && event.mouse.y > 524 && event.mouse.y < 570) {// bouton maison

        *habitations = true;
        *curseur = false;
        *routes = false;
        *centrales = false;
        *chateaudeau = false;

    }
    if (event.mouse.x > 5 && event.mouse.x < 45 && event.mouse.y > 570 && event.mouse.y < 615) {//bouton centrale

        *centrales = true;
        *curseur = false;
        *routes = false;
        *habitations = false;
        *chateaudeau = false;

    }
    if (event.mouse.x > 0 && event.mouse.x < 40 && event.mouse.y > 620 && event.mouse.y < 670) {//bouton Chateaudeau

        *chateaudeau = true;
        *curseur = false;
        *routes = false;
        *habitations = false;
        *centrales = false;

    }


}

void definirRoutes(ALLEGRO_EVENT event, bool routes, Cases cases[35][45], Maire *maire) {

    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 45; ++j) {


            if (event.mouse.x >= XDepart + (j * 20) && event.mouse.x <= XDepart + 20 + (j * 20) &&
                event.mouse.y >= (i * 20) &&
                event.mouse.y <= 20 + (i * 20)) {






                /* if ( cases[i][j].routes == 0 && cases[i][j].maison == 0 &&
                     cases[i][j].cabane == 0 && cases[i][j].immeuble == 0 && cases[i][j].gratteciel == 0 &&
                     cases[i][j].centrale == 0 && cases[i][j].chateaudeau == 0) */if(routes==true){

                    cases[i][j].routes = 1;
                    cases[i][j].constructions = 1;

                    maire->argent -= 10;

                }

            }

        }
    }
}


void affichageroute(Cases cases[35][45], ALLEGRO_BITMAP *imagesroute) {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].routes == 1) {
                al_draw_bitmap(imagesroute, XDepart + (j * 20), YDepart + (i * 20), 0);

            }

        }

    }
}


void definirMaison(ALLEGRO_EVENT event, bool habitations, Cases cases[35][45], Maire *maire) {

    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 45; ++j) {


            if (event.mouse.x >= XDepart + (j * 20) && event.mouse.x <= XDepart + 20 + (j * 20) &&
                event.mouse.y >= (i * 20) &&
                event.mouse.y <= 20 + (i * 20)) {


                if (habitations==true && cases[i][j].routes == 0 && cases[i][j].maison == 0 &&
                    cases[i][j].cabane == 0 && cases[i][j].immeuble == 0 && cases[i][j].gratteciel == 0 &&
                    cases[i][j].centrale == 0 && cases[i][j].chateaudeau == 0) {

                    cases[i][j].maison = 1;
                    for (int k = j; k < 2; ++k) {
                        for (int l = i; l < 2; ++l) {
                            cases[k][l].constructions = 1;

                        }

                    }


                    maire->argent -= 1000;

                }

            }

        }
    }
}


void affichageMaison(Cases cases[35][45], ALLEGRO_BITMAP *imagesmaisonplateau) {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].maison == 1) {
                al_draw_bitmap(imagesmaisonplateau, XDepart + (j * 20), YDepart + (i * 20), 0);


            }

        }

    }
}

void affichageeau(Cases cases[35][45]) {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].routes == 1) {
                al_draw_filled_rectangle(XDepart + (j * 20), YDepart + (i * 20), XDepart + 20 + (j * 20),
                                         YDepart + 20 + (i * 20), al_map_rgb(0, 0, 255));
            }

        }
    }
}

void affichageelectricite(Cases cases[35][45]) {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].routes == 1) {
                al_draw_filled_rectangle(XDepart + (j * 20), YDepart + (i * 20), XDepart + 20 + (j * 20),
                                         YDepart + 20 + (i * 20), al_map_rgb(255, 255, 0));
            }

        }
    }
}


void verificationcases(Cases cases[35][45]) {
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].constructions == 1) {
                al_draw_filled_rectangle(XDepart + (j * 20), YDepart + (i * 20), XDepart + 20 + (j * 20),
                                         YDepart + 20 + (i * 20), al_map_rgb(255, 0, 0));

            }


        }
    }


}



void definircentrale(ALLEGRO_EVENT event, bool centrale, Cases cases[35][45], Maire *maire) {

    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 45; ++j) {


            if (event.mouse.x >= XDepart + (j * 20) && event.mouse.x <= XDepart + 20 + (j * 20) &&
                event.mouse.y >= (i * 20) &&
                event.mouse.y <= 20 + (i * 20)) {


                if (centrale==true && cases[i][j].routes == 0 && cases[i][j].maison == 0 &&
                    cases[i][j].cabane == 0 && cases[i][j].immeuble == 0 && cases[i][j].gratteciel == 0 &&
                    cases[i][j].centrale == 0 && cases[i][j].chateaudeau == 0) {

                    cases[i][j].centrale = 1;
                    for (int k = j; k < 3; ++k) {
                        for (int l = i; l < 2; ++l) {
                            cases[k][l].constructions = 1;

                        }

                    }


                    maire->argent -= 1000; // prix a verifier

                }

            }

        }
    }
}


void definirChateaudeau(ALLEGRO_EVENT event, bool chateaudeau, Cases cases[35][45], Maire *maire) {

    for (int i = 0; i < 35; ++i) {
        for (int j = 0; j < 45; ++j) {


            if (event.mouse.x >= XDepart + (j * 20) && event.mouse.x <= XDepart + 20 + (j * 20) &&
                event.mouse.y >= (i * 20) &&
                event.mouse.y <= 20 + (i * 20)) {


                if (chateaudeau==true && cases[i][j].routes == 0 && cases[i][j].maison == 0 &&
                    cases[i][j].cabane == 0 && cases[i][j].immeuble == 0 && cases[i][j].gratteciel == 0 &&
                    cases[i][j].centrale == 0 && cases[i][j].chateaudeau == 0) {

                    cases[i][j].chateaudeau = 1;
                    for (int k = j; k < 3; ++k) {
                        for (int l = i; l < 2; ++l) {
                            cases[k][l].constructions = 1;

                        }

                    }


                    maire->argent -= 1000;

                }

            }

        }
    }
}


void affichageCentrale(Cases cases[35][45], ALLEGRO_BITMAP *imagesCentralegrande) {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].centrale == 1) {
                al_draw_bitmap(imagesCentralegrande, XDepart + (j * 20), YDepart + (i * 20), 0);


            }

        }

    }
}


void affichageChateaudeau(Cases cases[35][45], ALLEGRO_BITMAP *imagechateaudeau) {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 45; j++) {
            if (cases[i][j].chateaudeau == 1) {
                al_draw_bitmap(imagechateaudeau, XDepart + (j * 20), YDepart + (i * 20), 0);


            }

        }

    }
}