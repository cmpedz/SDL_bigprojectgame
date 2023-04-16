#ifndef PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
#define PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
#include"texture.h"
#include"button.h"
Ltexture image_pause;
button pause_button;
Ltexture pause_system;




#endif // PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
void set_icon_for_music_and_pause_button(){
     image_pause.loadtexture("image/pause.bmp");
     image_pause.settdx(490);
     image_pause.settdy(0);
     image_pause.setheight(100);
     image_pause.setwidth(100);


     pause_button.setPosition(image_pause.gettdx(),image_pause.gettdy());



}


void set_icon_music_and_pause_button_active(int x_mouse,int y_mouse,int &click,SDL_Event _e){


     image_pause.render(NULL);



     SDL_GetMouseState(&x_mouse,&y_mouse);
     if(x_mouse>=pause_button.gettdx() && x_mouse<= pause_button.gettdx()+image_pause.getwidth()&&
        y_mouse>=pause_button.gettdy()&& y_mouse<=pause_button.gettdy()+image_pause.getheight()){
            SDL_PollEvent(&_e);
        if(_e.type==SDL_MOUSEBUTTONUP){


        }
     }




}
