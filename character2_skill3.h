#ifndef texture
#define texture
texture;
#endif // CHARACTER2_SKILL3_H_INCLUDED

const int quatities_of_knifes=2;
Ltexture skill3_of_character2[quatities_of_knifes];
Ltexture effect_for_skill3_of_character2[quatities_of_knifes];
int tdx_for_ingradient_of_skill3_character2[quatities_of_knifes];
int tdy_for_ingradient_of_skill3_character2[quatities_of_knifes];
bool is_ingradient_of_skill3_from_character2_actived[quatities_of_knifes];
bool is_effect_for_ingrident_of_skill3_of_AI_actived[quatities_of_knifes];
int time_appearing_of_effect_of_skill3_from_AI[quatities_of_knifes];
int tdx_of_effect_of_skill3_of_AI_copy=0;
void set_skill3_of_character2(){

         tdx_for_ingradient_of_skill3_character2[0]=1080;
         tdy_for_ingradient_of_skill3_character2[0]=tdy_character2;
         is_ingradient_of_skill3_from_character2_actived[0]=false;
         is_effect_for_ingrident_of_skill3_of_AI_actived[0]=false;
         skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
         skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);
         skill3_of_character2[0].setheight(15);
         skill3_of_character2[0].setwidth(40);
         skill3_of_character2[0].loadtexture("skill3_of_character2_left.bmp");

         effect_for_skill3_of_character2[0].loadtexture("effect_of_skill3_of_AI.bmp");
         effect_for_skill3_of_character2[0].setheight(30);
         effect_for_skill3_of_character2[0].setwidth(1080);
         effect_for_skill3_of_character2[0].settdx(0);
         effect_for_skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);

         skill3_of_character2[1].loadtexture("skill3_of_character2_up.bmp");
         tdx_for_ingradient_of_skill3_character2[1]=tdx_character1;
         tdx_of_effect_of_skill3_of_AI_copy=tdx_for_ingradient_of_skill3_character2[1];
         tdy_for_ingradient_of_skill3_character2[1]=0;
         is_ingradient_of_skill3_from_character2_actived[0]=false;
         is_effect_for_ingrident_of_skill3_of_AI_actived[0]=false;
         skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
         skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);
         skill3_of_character2[1].setheight(40);
         skill3_of_character2[1].setwidth(15);

         effect_for_skill3_of_character2[1].loadtexture("effect_of_skill3_of_AI.bmp");
         effect_for_skill3_of_character2[1].setheight(680);
         effect_for_skill3_of_character2[1].setwidth(30);
         effect_for_skill3_of_character2[1].settdx(tdx_of_effect_of_skill3_of_AI_copy);
         effect_for_skill3_of_character2[1].settdy(0);




};


void set_skill3_of_character2_active(){
     if(SDL_GetTicks()/1000 % 5==0 && SDL_GetTicks()/1000 !=0 ){
        is_ingradient_of_skill3_from_character2_actived[0]=true;
        is_ingradient_of_skill3_from_character2_actived[1]=true;

     }

     if(is_ingradient_of_skill3_from_character2_actived[0] && !is_effect_for_ingrident_of_skill3_of_AI_actived[0]){
        if(tdx_for_ingradient_of_skill3_character2[0] < 0 ){
           tdx_for_ingradient_of_skill3_character2[0]=1080;
           skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
           skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);
           is_ingradient_of_skill3_from_character2_actived[0]=false;
           is_effect_for_ingrident_of_skill3_of_AI_actived[0]=true;
           time_appearing_of_effect_of_skill3_from_AI[0]=SDL_GetTicks();


        }
        else{
             tdx_for_ingradient_of_skill3_character2[0]=tdx_for_ingradient_of_skill3_character2[0]-5;
             skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
             skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);

        }

         skill3_of_character2[0].render(NULL);
     }

     if(is_effect_for_ingrident_of_skill3_of_AI_actived[0] &&
                (SDL_GetTicks()-time_appearing_of_effect_of_skill3_from_AI[0])/200<=1){
                effect_for_skill3_of_character2[0].settdx(0);
                effect_for_skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);
                effect_for_skill3_of_character2[0].render(NULL);
             }
            else{
                is_effect_for_ingrident_of_skill3_of_AI_actived[0]=false;
            }

     if(is_ingradient_of_skill3_from_character2_actived[1] && !is_effect_for_ingrident_of_skill3_of_AI_actived[1]){
        if(tdy_for_ingradient_of_skill3_character2[1] >680){
           tdy_for_ingradient_of_skill3_character2[1]=0;
           tdx_of_effect_of_skill3_of_AI_copy=tdx_for_ingradient_of_skill3_character2[1];
           tdx_for_ingradient_of_skill3_character2[1]=tdx_character1;
           skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
           skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);
           is_ingradient_of_skill3_from_character2_actived[1]=false;
           is_effect_for_ingrident_of_skill3_of_AI_actived[1]=true;
           time_appearing_of_effect_of_skill3_from_AI[1]=SDL_GetTicks();

        }

        else{
            tdy_for_ingradient_of_skill3_character2[1]=tdy_for_ingradient_of_skill3_character2[1]+5;
            skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
            skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);

        }



         skill3_of_character2[1].render(NULL);
     }

     if(is_effect_for_ingrident_of_skill3_of_AI_actived[1] &&
             (SDL_GetTicks()-time_appearing_of_effect_of_skill3_from_AI[1])/200<=1){
                effect_for_skill3_of_character2[1].settdx(tdx_of_effect_of_skill3_of_AI_copy);
                effect_for_skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);
                effect_for_skill3_of_character2[1].render(NULL);
            }
            else{
                is_effect_for_ingrident_of_skill3_of_AI_actived[1]=false;

            }


}


