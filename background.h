
#ifndef mback_ground
#define mback_ground
#include"texture.h"
Ltexture background;
#endif // background

    void back_ground(Ltexture background,const int height_of_screen,const int width_of_screen){
         background.settdx(0);
         background.settdy(0);
         background.setheight(height_of_screen);
         background.setwidth(width_of_screen);
         background.loadtexture("background.bmp");//
         background.render(NULL);
     }
