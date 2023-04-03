
#ifndef texture
#define texture
texture;
#endif // background
    void back_ground(){
         background.settdx(0);
         background.settdy(0);
         background.setheight(height_of_screen);
         background.setwidth(width_of_screen);
         background.loadtexture("background.bmp");//
         background.render(NULL);
     }
