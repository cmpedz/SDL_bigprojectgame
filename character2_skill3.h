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

bool did_character1_get_hit_by_skill3[quatities_of_knifes];

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


void set_skill3_of_character2_active(int time_in_game,bool did_character1_get_hit_by_skill3[],
                                     int tdx_character1,int tdy_character1){
     if((SDL_GetTicks()-time_in_game)/1000 % 5==0 && (SDL_GetTicks()-time_in_game)/1000 !=0 ){
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




       //first damage

      if((tdx_for_ingradient_of_skill3_character2[0]+5>=tdx_character1 &&
             tdx_for_ingradient_of_skill3_character2[0]-5<=tdx_character1 &&
             tdy_for_ingradient_of_skill3_character2[0]+5 >= tdy_character1 &&
             tdy_for_ingradient_of_skill3_character2[0]-5 <= tdy_character1)||

             (tdx_for_ingradient_of_skill3_character2[1]+5>=tdx_character1 &&
             tdx_for_ingradient_of_skill3_character2[1]-5<=tdx_character1 &&
             tdy_for_ingradient_of_skill3_character2[1]+5 >= tdy_character1 &&
             tdy_for_ingradient_of_skill3_character2[1]-5 <= tdy_character1)){
             did_character1_get_hit_by_skill3[0]=true;
          }
          else{ did_character1_get_hit_by_skill3[0]=false; }









           //second damage
          if((is_effect_for_ingrident_of_skill3_of_AI_actived[0] &&
             tdy_character1 <= tdy_for_ingradient_of_skill3_character2[0]+2 &&
             tdy_character1 >= tdy_for_ingradient_of_skill3_character2[0]-2) ||
             (is_effect_for_ingrident_of_skill3_of_AI_actived[1] &&
             tdx_character1 <= tdx_of_effect_of_skill3_of_AI_copy+5 &&
             tdx_character1 >= tdx_of_effect_of_skill3_of_AI_copy-5 )){
             did_character1_get_hit_by_skill3[1]=true;
          }
          else{
              did_character1_get_hit_by_skill3[1]=false;
          }


}


