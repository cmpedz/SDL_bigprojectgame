
#ifndef mback_ground
#define mback_ground
#include"texture.h"
Ltexture background;
#endif // background

    void back_ground(Ltexture background,const int height_of_screen,const int width_of_screen,
                     bool choose_map1,bool choose_map2){
         background.settdx(0);
         background.settdy(0);
         background.setheight(height_of_screen);
         background.setwidth(width_of_screen);

         if(choose_map1){
            background.loadtexture("image/map1.bmp");//
         }

         if(choose_map2){
            background.loadtexture("image/map2.bmp");//
         }

         background.render(NULL);
     }
