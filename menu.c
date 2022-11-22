//
// Created by lepou on 15/11/2022.
//

#include "menu.h"
#include"plateau.h"


void dessinerMenu(ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2){
    al_draw_bitmap(imagemenu,0,0,0);
    al_draw_filled_rectangle(0, 700, 200, 750, al_map_rgb(100, 100, 100));
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 40, 700, 0, "JOUER");
    al_draw_filled_rectangle(0, 20, 150, 70, al_map_rgb(100, 100, 100));
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 10, 25, 0, "REGLES");





    al_flip_display();
}
void regles(Fonts fonts){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 200, 25, 0, "BIENVENU DANS LES REGLES DU JEU\n");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 80, 65, 0,"Le but est de construire la plus grande ville possible. ");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 80, 105, 0,"Pour cela vous devrez construire des infrastructures : ");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 80, 145, 0," des batiment(habitations, centrale electrique...)");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 120, 185, 0,"ainsi que des routes pour relié nos infrastructures");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 100, 225, 0,"Pour construire une habitations il faut qu'elle ait");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 40, 265, 0,"un acces a la route, et assez d'eau et d'electricter pour");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 40, 305, 0,"ces habitants. Vous devrez gerer votre budjet entre vos ");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 40, 345, 0,"recettes (impots) et vos depenses pour la construiction");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 440, 385, 0," d'habitation!");

    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 200, 425, 0,"Maintenant il me reste qu'à vous souhaiter  ");
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 380, 465, 0,"BONNE CHANCE ! ");


    al_draw_filled_rectangle(400, 700, 600, 750, al_map_rgb(100, 100, 100));
    al_draw_textf(fonts.font, al_map_rgb(255, 255, 255), 440, 700, 0, "JOUER");
}

void choixDebut(int x, int y,bool *etatDebut,bool *etatRegles, ALLEGRO_TIMER* timermenu){
    if (((x > 0 && x < 200) && (y >700 && y < 750))||((x>400&&x<600)&&(y>700&&y<750))){
        *etatDebut=false;
        *etatRegles=false;
        al_start_timer(timermenu);
    }
    if ((x > 0 && x < 150) && (y > 20 && y < 150+20)){
        *etatDebut=false;
        *etatRegles=true;
    }
}