//
// Created by lepou on 15/11/2022.
//

#include "JEU.h"

#include "menu.h"
#include "plateau.h"
#include "stdio.h"




void dessinerTout(bool * etatdebut,ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2, bool* etatregle,Maire* maire, ALLEGRO_BITMAP* imagefond, ALLEGRO_BITMAP* imageflechehaut,ALLEGRO_BITMAP* imageflechebas,bool* etage0,bool* etage_1,bool* etage_2,int x1,int x2,int y1,int y2 ) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (*etatdebut) {
        dessinerMenu(imagemenu, fonts, timer2);
    } else if (*etatregle) {
        regles(fonts);
    } else {
        al_clear_to_color(al_map_rgb(150,255,0));
        if(*etage0){ // horizon etage niveau 0

            dessinerfond(imagefond);
        }
        if(*etage_1){ // niveau -1
            al_clear_to_color(al_map_rgb(0,0,0));
        }

        if (*etage_2){ // niveau-2
            al_clear_to_color(al_map_rgb(255,0,0));

        }

        affichageressources(maire,fonts);
        affichagetimer(fonts,timer2);

        dessinerplateau();
        dessinerfleche(imageflechehaut,imageflechebas);
        al_draw_filled_rectangle(x1,y1,x2,y2, al_map_rgb(0,0,0));



    }

    al_flip_display();
}
void initialisationresource(Maire* maire){
    maire->argent=500000;
    maire->capacites=0;
    maire->habitants=1;
}

void affichageressources(Maire* maire, Fonts fonts){
    al_draw_filled_rectangle(0,0,123,130, al_map_rgb(0,100,140));
    al_draw_textf(fonts.font4, al_map_rgb(255,0,0),0,30,0,"Argent :");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),0,50,0,"%d",maire->argent);
    al_draw_textf(fonts.font4, al_map_rgb(255,0,0),0,60,0,"Habitants : ");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),0,80,0,"%d",maire->habitants);
    al_draw_textf(fonts.font4, al_map_rgb(255,0,0),0,90,0,"Capacités :");
    al_draw_textf(fonts.font2, al_map_rgb(0,0,0),0,110,0,"%d",maire->capacites);

}


void dessinerfleche(ALLEGRO_BITMAP* imagefleche1,ALLEGRO_BITMAP* imagefleche2){
    al_draw_rotated_bitmap(imagefleche1,10,280,30,460,0,0);
    al_draw_rotated_bitmap(imagefleche2,10,280,30,530,0,0);
}

void choixfleches(int x, int y,bool* etage0,bool* etage_1,bool* etage_2) {
    int etage=0;
    if((x>20&&x<80)&&(y>140&&y<240)){
        etage= etage+1;
    }
    if((x>20&&x<80)&&(y>240&&y<300)){
        etage=etage-1;
    }
    if(etage>=0){*etage0=true;*etage_1=false;*etage_2=false;}
    if(etage==-1){*etage0=false;*etage_1=true;*etage_2=false;}
    if(etage<=-2){*etage0=false;*etage_1=false;*etage_2=true;}
}