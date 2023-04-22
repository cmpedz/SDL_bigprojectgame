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
                            int &time_watting_teleport,Ltexture effect_miss_of_AI,bool stopping_time,
                            int &character2_frame_miss,bool &delay_skill_of_AI,
                            int &tdx_character2,int tdx_character1,bool &does_AI_miss,bool character2_can_not_move){
     if(mkey_active_effect_miss && !character2_can_not_move ){
        delay_skill_of_AI=true;
        if(!stopping_time){
           saving_time_miss_effect_of_AI=0;
        }
        if((SDL_GetTicks()-time_appearing_of_effect_miss+saving_time_miss_effect_of_AI)/200<=1){
           effect_miss_of_AI.render(NULL);

           character2_frame_miss++;
           if(character2_frame_miss/10>=2){
              character2_frame_miss=20;
           }
        }




        if((SDL_GetTicks()-time_appearing_of_effect_miss+saving_time_miss_effect_of_AI)/200>=2 &&
           (SDL_GetTicks()-time_appearing_of_effect_miss+saving_time_miss_effect_of_AI)/200<=3){

            if(tdx_character1-tdx_character2<0){
                tdx_character2=tdx_character2-20;
                if(tdx_character2<0){ tdx_character2=0;}
             }

             if(tdx_character1-tdx_character2>0){
                tdx_character2=tdx_character2+20;
                if(tdx_character2>1000){ tdx_character2=1000;}
            }
            character2_frame_miss++;
            if(character2_frame_miss/10>=4){
                character2_frame_miss=40;
            }



        }

        if((SDL_GetTicks()-time_appearing_of_effect_miss+saving_time_miss_effect_of_AI)/200>=3){
             mkey_active_effect_miss=false;
             chance_to_teleport=0;
             time_watting_teleport=200;
             delay_skill_of_AI=false;
            character2_frame_miss=0;
            does_AI_miss=false;

        }

     }
     else{
         time_appearing_of_effect_miss=SDL_GetTicks();
         effect_miss_of_AI.setheight(48);
         effect_miss_of_AI.setwidth(48);
         effect_miss_of_AI.settdx(tdx_character2);
         effect_miss_of_AI.settdy(tdy_character2);
         character2_frame_miss=0;

     }

}
