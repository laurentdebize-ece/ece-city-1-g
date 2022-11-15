//
// Created by lepou on 15/11/2022.
//

#include "JEU.h"

#include "menu.h"
#include "plateau.h"
#include "stdio.h"




void dessinerTout(bool * etatdebut,ALLEGRO_BITMAP * imagemenu, Fonts fonts,ALLEGRO_TIMER* timer2, bool* etatregle,Maire* maire, ALLEGRO_BITMAP* imagefond, ALLEGRO_BITMAP* imageflechehaut,ALLEGRO_BITMAP* imageflechebas,bool* etage0,bool* etage_1,bool* etage_2,int x1,int x2,int y1,int y2, ALLEGRO_BITMAP*imageRoutes40x40,ALLEGRO_EVENT event, ALLEGRO_BITMAP*imageRoutes,int etage, ALLEGRO_BITMAP* imageelec ) {
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
        else if(*etage_1){ // niveau -1
            al_draw_filled_rectangle(124,0,1024,700,al_map_rgb(0,0,0));
            dessinerplateau();
        }

        else { // niveau-2
            al_draw_filled_rectangle(124,0,1024,700,al_map_rgb(255,255,255));


        }

        affichageressources(maire,fonts);
        affichagetimer(fonts,timer2);

        dessinerLigne();
        dessinerBoutons(fonts,imageflechehaut,imageflechebas,imageRoutes40x40,imageelec);
        choixBoutons(event,x1,x2,y1,y2,imageRoutes);





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




void choixBoutons(ALLEGRO_EVENT event,int x1,int x2,int y1,int y2,ALLEGRO_BITMAP* imageRoutes) {
    //bouton route
    // il faut : un if pour savoir si il y a une maison ? si oui pas de routes
    if ((event.mouse.x > 10 && event.mouse.x < 50) && (event.mouse.y > 360 && event.mouse.y < 400)) {
        al_draw_bitmap(imageRoutes, x1, y1, 0);
    } else { al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0)); }


}

void dessinerBoutons(Fonts fonts,ALLEGRO_BITMAP* imageville,ALLEGRO_BITMAP* imageeau,ALLEGRO_BITMAP* imageRoutes40x40, ALLEGRO_BITMAP* imageelec){
    al_draw_bitmap(imageville,10,210,0);
    al_draw_bitmap(imageeau,10,290,0);
    al_draw_bitmap(imageelec,10,330,0);

    al_draw_bitmap(imageRoutes40x40,10,430,0) ;
    al_draw_textf(fonts.font4, al_map_rgb(0,0,0),60,440,0,"Routes");

}

void changementetage(ALLEGRO_EVENT event,bool* etage0,bool* etage_1,bool* etage_2,int etage){

    if(event.mouse.x>10 && event.mouse.x<70 && event.mouse.y>210&&event.mouse.y<280){
        etage=0;
    }
    if(event.mouse.x > 10 && event.mouse.x < 70 && event.mouse.y > 285 && event.mouse.y < 330){
        etage=-1;
    }
    if ((event.mouse.x > 10 && event.mouse.x < 70) && (event.mouse.y > 330 && event.mouse.y < 390)){
        etage=-2;
    }
    if(etage==0){*etage0=true;*etage_1=false;*etage_2=false;}
    if(etage==-1){*etage0=false;*etage_1=true;*etage_2=false;}
    if(etage==-2){*etage0=false;*etage_1=false;*etage_2=true;}

}