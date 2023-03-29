#ifndef character
#define character
#include"texture.h"
const int quatity_of_frame_character1=4;
SDL_Rect character1_clip[quatity_of_frame_character1];
#endif // character
void character_1(int tdx_character1,int tdy_character1,int character1_frame,bool r,bool l){

         character1_clip[0].h=299;
         character1_clip[0].w=177;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

         character1_clip[1].h=299;
         character1_clip[1].w=177;
         character1_clip[1].x=177;
         character1_clip[1].y=0;

         character1_clip[2].h=299;
         character1_clip[2].w=177;
         character1_clip[2].x=177*2;
         character1_clip[2].y=0;
         character1_clip[3].h=299;
         character1_clip[3].w=177;
         character1_clip[3].x=177*3;
         character1_clip[3].y=0;
        character1.settdx(tdx_character1);
        character1.settdy(tdy_character1);
        character1.setheight(60);
        character1.setwidth(36);
        character1.loadtexture("sans_moving_right.bmp");
        if(r){
           character1.loadtexture("sans_moving_right.bmp");

        }
        if(l){
          character1.loadtexture("sans_moving_left.bmp");
        }
        character1.render(&character1_clip[character1_frame/20]);
        }
