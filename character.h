#ifndef character
#define character
#include"texture.h"
#include"gravity.h"
const int quatity_of_frame_character1=4;
SDL_Rect character1_clip[quatity_of_frame_character1];
int character1_frame=0;
int tdx_character1=0;
int tdy_character1=height_of_screen/4*3;
Ltexture character1;
double saving_time_jumping_when_stopping_game1=0;

  bool can_character1_jump=false;
  double set_time_in_the_air_of_character1=0;
  double v_of_character1=0;


#endif // character
void reset_ch1(){
    character1_frame=0;
    tdx_character1=0;
    tdy_character1=height_of_screen/4*3;

    saving_time_jumping_when_stopping_game1=0;

     can_character1_jump=false;
        set_time_in_the_air_of_character1=0;
        v_of_character1=0;


}
void character_1(int tdx_character1,int tdy_character1,int character1_frame,bool r,bool l,bool choose_skin1,
                 bool choose_skin2){
       if(choose_skin1){
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
        character1.loadtexture("image/sans_moving_right.bmp");
        if(r){
           character1.loadtexture("image/sans_moving_right.bmp");

        }
        if(l){
          character1.loadtexture("image/sans_moving_left.bmp");
        }
        character1.render(&character1_clip[character1_frame/20]);
        }
        if(choose_skin2){

          character1_clip[1].h=30;
         character1_clip[1].w=22;
         character1_clip[1].x=0;
         character1_clip[1].y=0;

         character1_clip[0].h=30;
         character1_clip[0].w=22;
         character1_clip[0].x=22+10;
         character1_clip[0].y=0;

         character1_clip[2].h=30;
         character1_clip[2].w=22;
         character1_clip[2].x=(22+10)*2;
         character1_clip[2].y=0;

          character1_clip[3].h=30;
         character1_clip[3].w=22;
         character1_clip[3].x=22+10;
         character1_clip[3].y=0;

        character1.settdx(tdx_character1);
        character1.settdy(tdy_character1);
        character1.setheight(60);
        character1.setwidth(36);
        character1.loadtexture("image/error_sans_mvr.bmp");
        if(r){
           character1.loadtexture("image/error_sans_mvr.bmp");

        }
        if(l){
          character1.loadtexture("image/error_sans_mvl.bmp");
        }
        character1.render(&character1_clip[character1_frame/10]);


        }


                 }


void set_chr1_jump(bool &_can_character1_jump,int &_tdy_character1,const int _tdy_of_ground,
                   double _set_time_in_the_air_of_character1,double _v_of_character1,double &saving_time_jumping_when_stopping_game1
                   ,bool &stopping_time){

     if(_can_character1_jump && !stopping_time){
              _tdy_character1=_tdy_character1-set_gravity(_v_of_character1,_set_time_in_the_air_of_character1,saving_time_jumping_when_stopping_game1);
                if(_tdy_character1>=_tdy_of_ground){
                  _tdy_character1=_tdy_of_ground;
                  _can_character1_jump=false;
                }

     }


}
