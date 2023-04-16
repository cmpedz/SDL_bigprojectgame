#ifndef miss_effect
#define miss_effect
#include"texture.h"
Ltexture effect_miss_of_AI;
bool key_active_effect_miss=false;
double time_appearing_of_effect_miss=0;
double saving_time_miss_effect_of_AI=0;

#endif // MISS_EFFECT_H_INCLUDED

void reset_effect_miss(){
     key_active_effect_miss=false;
     time_appearing_of_effect_miss=0;
     saving_time_miss_effect_of_AI=0;

}


void set_effect_miss(bool key_active_effect_miss,double time_appearing_of_effect_miss,double saving_time_miss_effect_of_AI){
     effect_miss_of_AI.loadtexture("image/miss.bmp");
     effect_miss_of_AI.settdx(tdx_character2+50);
     effect_miss_of_AI.settdy(tdy_character2-50);
     effect_miss_of_AI.setheight(48);
     effect_miss_of_AI.setwidth(48);



}


void set_effect_miss_active(bool &mkey_active_effect_miss,int &chance_to_teleport,double &time_appearing_of_effect_miss,
                            int &time_watting_teleport,Ltexture effect_miss_of_AI,bool stopping_time){
     if(mkey_active_effect_miss){
        if(!stopping_time){
           saving_time_miss_effect_of_AI=0;
        }
        if((SDL_GetTicks()-time_appearing_of_effect_miss+saving_time_miss_effect_of_AI)/100<=2){
           effect_miss_of_AI.render(NULL);
        }
        else{
             mkey_active_effect_miss=false;
             chance_to_teleport=0;
             time_watting_teleport=200;
        }

     }
     else{
         time_appearing_of_effect_miss=SDL_GetTicks();
         effect_miss_of_AI.setheight(48);
         effect_miss_of_AI.setwidth(48);
         effect_miss_of_AI.settdx(tdx_character2);
         effect_miss_of_AI.settdy(tdy_character2);
     }

}
