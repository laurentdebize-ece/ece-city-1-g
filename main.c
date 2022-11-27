#include <stdio.h>
#include "plateau.h"
#include "menu.h"
#include "JEU.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main() {
    bool jeu = true;
    bool etage0 = true;
    bool etage_1 = false;
    bool etage_2 = false;
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int etage = 0;
    int bouton = 0;
    int compteur = 0;
    int timer = 0;


    bool curseur = true;
    bool routes = false;
    bool habitations = false;
    bool centrale = false;
    bool chateaudeau = false;


    bool fin = false;
    bool etatdebut = true;
    bool etatregles = true;
    bool etatmenu = true;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer1 = NULL;
    ALLEGRO_TIMER *timer2 = NULL;


    ALLEGRO_BITMAP *imagemenu;
    ALLEGRO_BITMAP *imagefond;
    ALLEGRO_BITMAP *imageville;
    ALLEGRO_BITMAP *imageeau;
    ALLEGRO_BITMAP *imageelec;
    ALLEGRO_BITMAP *imageRoutes;
    ALLEGRO_BITMAP *imageRoutes40x40;
    ALLEGRO_BITMAP *imageChateaudeau;
    ALLEGRO_BITMAP *imageCentrale;
    ALLEGRO_BITMAP *imageMaison;
    ALLEGRO_BITMAP *imagecurseur;
    ALLEGRO_BITMAP *imagemaisonplateau;
    ALLEGRO_BITMAP *imageChateaudeauGrande;
    ALLEGRO_BITMAP *imageCentraleGrande;
    ALLEGRO_BITMAP *imageImmeuble;
    ALLEGRO_BITMAP *imageCabane;
    ALLEGRO_BITMAP *imageGratteciel;
    ALLEGRO_BITMAP *imageTerrainvague;


    Fonts fonts;
    bool Souris = false;

    srand(time(NULL));
    assert(al_init());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    assert(al_init_image_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_primitives_addon());


    display = al_create_display(LO_FENETRE, LA_FENETRE);
    al_set_window_position(display, 0, 0);

    assert(display != NULL);
    timer1 = al_create_timer(0.01);
    assert(timer1 != NULL);

    timer2 = al_create_timer(1);
    assert(timer2 != NULL);


    queue = al_create_event_queue();
    assert(queue != NULL);

    Cases cases[35][45] = {0};


    fonts.font = al_load_ttf_font("../Fonts/police.ttf", 45, 0);

    fonts.font2 = al_load_ttf_font("../Fonts/police.ttf", 15, 0);
    fonts.font3 = al_load_ttf_font("../Fonts/police.ttf", 30, 0);
    fonts.font4 = al_load_ttf_font("../Fonts/police.ttf", 20, 0);

    al_set_window_title(display, "Bienvenue sur ECE City");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer1));
    al_register_event_source(queue, al_get_timer_event_source(timer2));

    imagemenu = al_load_bitmap("../images/menusimcity.png");
    imagefond = al_load_bitmap("../images/fond.png");
    imageville = al_load_bitmap("../images/ville.png");
    imageeau = al_load_bitmap("../images/eau.png");
    imageelec = al_load_bitmap("../images/elec.png");
    imageRoutes = al_load_bitmap("../images/textureRoutes.jpg");
    imageRoutes40x40 = al_load_bitmap("../images/textureRoutes40x40.jpg");
    imageMaison = al_load_bitmap("../images/maison.png");
    imageCentrale = al_load_bitmap("../images/centrale.png");
    imageChateaudeau = al_load_bitmap("../images/chateau.png");
    imagecurseur = al_load_bitmap("../images/curseur.png");
    imagemaisonplateau = al_load_bitmap("../images/maisonplateau.png");
    imageCentraleGrande = al_load_bitmap("../images/electricity .png");
    imageChateaudeauGrande = al_load_bitmap("../images/chateaudeau.png");
    imageImmeuble = al_load_bitmap("../images/immeuble.png");
    imageCabane = al_load_bitmap("../images/cabane.png");
    imageGratteciel = al_load_bitmap("../images/gratteciel.png");
    imageTerrainvague = al_load_bitmap("../images/terrainvague.png");


    Maire maire;

    inisitialisationcases(cases);
    initialisationresource(&maire);

    al_start_timer(timer2);
    al_start_timer(timer1);
    while (!fin) {

        ALLEGRO_EVENT event = {0};

        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fin = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN :
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:


                        break;
                }
                break;


            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                Souris = true;
                if (etatdebut || etatregles) {
                    choixDebut(event.mouse.x, event.mouse.y, &etatdebut, &etatregles, timer2);

                }

                changementetage(event, &etage0, &etage_1, &etage_2, etage);
                detectionboutons(event, &curseur, &routes, &habitations, &centrale, &chateaudeau, bouton);
                if (routes) {
                    definirRoutes(event, routes, cases, &maire);
                }
                if (habitations) {
                    definirMaison(event, habitations, cases, &maire);
                }
                if (chateaudeau) {

                    definirChateaudeau(event, chateaudeau, cases, &maire);
                }

                if (centrale) {

                    definircentrale(event, centrale, cases, &maire);
                }


                break;

            case ALLEGRO_EVENT_MOUSE_AXES :

                detectioncaseSouris(event, &x1, &y1, &x2, &y2);


                break;
            case ALLEGRO_EVENT_TIMER :
                compteur += 1;
                if (compteur % 100 == 0) {
                    timer++;
                    if (timer % 5 == 0) {

                        for (int i = 0; i < 35; ++i) {
                            for (int j = 0; j < 45; ++j) {
                                if (cases[i][j].habitations == 1) {
                                    if (cases[i][j].niveaubatiment < 4) {
                                        cases[i][j].niveaubatiment += 1;

                                        switch (cases[i][j].niveaubatiment) {
                                            case 0 :
                                                maire.habitants += 0;
                                                cases[i][j].habitants = 0;
                                                break;
                                            case 1 :
                                                maire.habitants += 10;
                                                cases[i][j].habitants = 10;
                                                maire.argent+= 10 * cases[i][j].habitants;
                                                break;

                                            case 2 :
                                                maire.habitants += 40;
                                                cases[i][j].habitants = 50;
                                                maire.argent+= 10 * cases[i][j].habitants;
                                                break;
                                            case 3 :
                                                maire.habitants += 50;
                                                cases[i][j].habitants = 100;
                                                maire.argent+= 10 * cases[i][j].habitants;
                                                break;
                                            case 4 :
                                                maire.habitants += 900;
                                                cases[i][j].habitants = 1000;
                                                maire.argent+= 10 * cases[i][j].habitants;
                                                break;
                                        }
                                    }
                                }

                            }

                        }
                    }
                }

                dessinerTout(&etatdebut, imagemenu, fonts, timer2, &etatregles, &maire, imagefond, imageville,
                             imageeau, &etage0, &etage_1, &etage_2, x1, x2, y1, y2, imageRoutes40x40, event,
                             imageRoutes, etage, imageelec, imageMaison, imageCentrale, imageChateaudeau, imagecurseur,
                             cases, &curseur, &routes, imageRoutes, &jeu, imagemaisonplateau, &habitations, &centrale,
                             &chateaudeau, imageCentraleGrande, imageChateaudeauGrande, imageCabane, imageTerrainvague,
                             imageImmeuble, imageGratteciel);


                break;
        }
    }


    return 0;

}