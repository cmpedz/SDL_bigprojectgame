#ifndef texture
#define texture
texture;
#endif // MISS_EFFECT_H_INCLUDED
Ltexture effect_miss_of_AI;
//int tdx_of_effect_miss=0;
//int tdy_of_effect_miss=0;
bool key_active_effect_miss=false;
int time_appearing_of_effect_miss=0;
void set_effect_miss(){
     effect_miss_of_AI.loadtexture("miss.bmp");
     effect_miss_of_AI.settdx(tdx_character2);
     effect_miss_of_AI.settdy(tdy_character2);
     effect_miss_of_AI.setheight(48);
     effect_miss_of_AI.setwidth(48);
}
void set_effect_miss_active(){
     if(key_active_effect_miss){
        if((SDL_GetTicks()-time_appearing_of_effect_miss)/100<=2){
           effect_miss_of_AI.render(NULL);
        }
        else{
             key_active_effect_miss=false;
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
