#ifndef NO_EFFECT_H_INCLUDED
#define NO_EFFECT_H_INCLUDED
#include"texture.h"
Ltexture no_effect_of_player;
bool key_active_no_effect_ability=false;
double time_appearing_of_no_effect=0;
double saving_time_no_effect=0;
int chance_to_use_no_effect_ability=5;



#endif // NO_EFFECT_H_INCLUDED

void reset_no_effect(){

     key_active_no_effect_ability=false;
     time_appearing_of_no_effect=0;
     saving_time_no_effect=0;
     chance_to_use_no_effect_ability=5;

}


void set_no_effect(bool key_active_no_effect_ability,double time_appearing_of_no_effect,double saving_time_no_effect,
                     int tdx_character1,int tdy_character1){
     no_effect_of_player.loadtexture("image/no_effect.bmp");
     no_effect_of_player.settdx(tdx_character1);
     no_effect_of_player.settdy(tdy_character1-50);
    no_effect_of_player.setheight(12);
     no_effect_of_player.setwidth(100);



}


void set_no_effect_active(bool &mkey_active_no_effect_ability,double &time_appearing_of_no_effect,
                           Ltexture no_effect_of_player,bool stopping_time,int tdx_character1,
                           int tdy_character1,int &chance_to_use_no_effect_ability){
     if(mkey_active_no_effect_ability && chance_to_use_no_effect_ability){
        if(!stopping_time){
           saving_time_no_effect=0;
        }
        if((SDL_GetTicks()-time_appearing_of_no_effect+saving_time_no_effect)/100<=2){
           no_effect_of_player.render(NULL);
        }
        else{
             mkey_active_no_effect_ability=false;
             time_appearing_of_no_effect=SDL_GetTicks();
             if(chance_to_use_no_effect_ability>0){
                chance_to_use_no_effect_ability--;
             }
        }




     }
     else{
         time_appearing_of_no_effect=SDL_GetTicks();
         no_effect_of_player.setheight(12);
         no_effect_of_player.setwidth(100);
         no_effect_of_player.settdx(tdx_character1);
         no_effect_of_player.settdy(tdy_character1);
     }

}
