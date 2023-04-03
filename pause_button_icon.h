#ifndef PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
#define PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
#include"texture.h"
#include"button.h"
Ltexture image_pause;
button pause_button;
Ltexture pause_system;
bool stopping_menu_active=false;

button continue_button_in_stopping_menu;
Ltexture image_of_continue_button_in_stopping_menu;
const int quatities_of_continue_button_frame_in_stopping_menu=2;
int continue_button_frame_in_stopping_menu;
SDL_Rect continue_button_sprites_in_stopping_menu[quatities_of_continue_button_frame_in_stopping_menu];

button quit_button_in_stopping_menu;
Ltexture image_of_quit_button_in_stopping_menu;
const int quatities_of_quit_button_frame_in_stopping_menu=2;
int quit_button_frame_in_stopping_menu;
SDL_Rect quit_button_sprites_in_stopping_menu[quatities_of_continue_button_frame_in_stopping_menu];





#endif // PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
void set_icon_pause_button(){
     image_pause.loadtexture("pause.bmp");
     image_pause.settdx(490);
     image_pause.settdy(0);
     image_pause.setheight(100);
     image_pause.setwidth(100);


     pause_button.setPosition(image_pause.gettdx(),image_pause.gettdy());



}

void set_button_in_stopping_menu(){

     image_of_continue_button_in_stopping_menu.loadtexture("stop_interface1.bmp");
     image_of_continue_button_in_stopping_menu.settdx(360);
     image_of_continue_button_in_stopping_menu.settdy(136);
     image_of_continue_button_in_stopping_menu.setheight(136);
     image_of_continue_button_in_stopping_menu.setwidth(360);

     for(int i=0;i<quatities_of_continue_button_frame_in_stopping_menu;i++){
         continue_button_sprites_in_stopping_menu[i].x=0+(338+134)*i;
         continue_button_sprites_in_stopping_menu[i].y=0;
         continue_button_sprites_in_stopping_menu[i].w=338;
         continue_button_sprites_in_stopping_menu[i].h=127;
     }




     image_of_quit_button_in_stopping_menu.loadtexture("stop_interface2.bmp");
     image_of_quit_button_in_stopping_menu.settdx(image_of_continue_button_in_stopping_menu.gettdx());
     image_of_quit_button_in_stopping_menu.settdy(image_of_continue_button_in_stopping_menu.gettdy()+image_of_continue_button_in_stopping_menu.getheight()+136);
     image_of_quit_button_in_stopping_menu.setheight(136);
     image_of_quit_button_in_stopping_menu.setwidth(360);

     for(int i=0;i<quatities_of_quit_button_frame_in_stopping_menu;i++){
         quit_button_sprites_in_stopping_menu[i].x=0+(338+134)*i;
         quit_button_sprites_in_stopping_menu[i].y=0;
         quit_button_sprites_in_stopping_menu[i].w=338;
         quit_button_sprites_in_stopping_menu[i].h=127;
     }

}


void set_icon_pause_button_active(int x_mouse,int y_mouse,int &click,SDL_Event _e){


     image_pause.render(NULL);



     SDL_GetMouseState(&x_mouse,&y_mouse);
     if(x_mouse>=pause_button.gettdx() && x_mouse<= pause_button.gettdx()+image_pause.getwidth()&&
        y_mouse>=pause_button.gettdy()&& y_mouse<=pause_button.gettdy()+image_pause.getheight()){
            SDL_PollEvent(&_e);
        if(_e.type==SDL_MOUSEBUTTONUP){
          stopping_menu_active=true;

        }
     }

      if(stopping_menu_active){
           image_of_continue_button_in_stopping_menu.render(&continue_button_sprites_in_stopping_menu[continue_button_frame_in_stopping_menu]);
           image_of_quit_button_in_stopping_menu.render(&quit_button_sprites_in_stopping_menu[quit_button_frame_in_stopping_menu]);

        }



}
