#ifndef STOPPING_SETTING_H_INCLUDED
#define STOPPING_SETTING_H_INCLUDED
#include"texture.h"


#endif // STOPPING_SETTING_H_INCLUDED

void set_everything_in_game_stop(Ltexture character1,Ltexture character2,Ltexture skill1_of_AI,Ltexture background,
                  Ltexture character1_face,Ltexture character2_face,Ltexture health_bar_1_for_character1,
                  Ltexture health_bar_1_for_character2,Ltexture health_bar_2_for_character1,
                  Ltexture health_bar_2_for_character2,Ltexture character2_skill2,Ltexture skill1_of_character1,
                  Ltexture skill3_of_character1,bool choose_right_1,
                  bool choose_left_1,bool left_AI,bool right_AI,bool right_for_skill2_of_character2,
                  bool left_for_skill2_of_character2,bool is_skill2_of_character2_actived,
                  bool is_ingradient_of_skill3_from_character2_actived[],Ltexture skill3_of_character2[],
                  bool is_effect_for_ingrident_of_skill3_of_AI_actived[],Ltexture effect_for_skill3_of_character2[],
                  bool does_skill1_of_character1_active,Ltexture effect_for_skill1_of_character1,
                  bool is_ingradient_of_skill2_from_character1_actived[],Ltexture skill2_of_character1[],
                  bool does_skill3_of_character1_active,int skill1_of_character1_frame,
                  SDL_Rect skill1_of_character1_clip[]){

               // set interface when stopping time

             background.settdx(0);
             background.settdy(0);
             background.setheight(height_of_screen);
             background.setwidth(width_of_screen);
             background.loadtexture("background.bmp");
            if(choose_right_1){

                character1.loadtexture("sans_moving_right.bmp");

            }
            if(choose_left_1){

                character1.loadtexture("sans_moving_left.bmp");
            }


            if(right_AI){
                character2.loadtexture("chara_moving_right.bmp");

            }
            if(left_AI){
                character2.loadtexture("chara_moving_left.bmp");
            }

            skill1_of_AI.loadtexture("chara_hit_directly.bmp");

            if(right_for_skill2_of_character2){character2_skill2.loadtexture("slash_chara_right.bmp");}
            if(left_for_skill2_of_character2){character2_skill2.loadtexture("slash_chara_left.bmp");}


            skill1_of_character1.loadtexture("gb.bmp");
            effect_for_skill1_of_character1.loadtexture("gb_beam.bmp");

             skill3_of_character1.loadtexture("sans_bone_zone.bmp");


             health_bar_1_for_character1.loadtexture("health_bar_1.bmp");
            health_bar_1_for_character2.loadtexture("health_bar_1.bmp");
            health_bar_2_for_character1.loadtexture("health_bar_2.bmp");
            health_bar_2_for_character2.loadtexture("health_bar_2.bmp");
            character2_face.loadtexture("chara_face.bmp");
            character1_face.loadtexture("sans_face.bmp");






            // set everything in game stop when we pause game

            background.render(NULL);



            character1.render(&character1_clip[character1_frame/20]);




            character2.render(&character2_clip[character2_frame/20]);


             if(is_skill2_of_character2_actived){


                character2_skill2.render(NULL);
            }

            if(is_ingradient_of_skill3_from_character2_actived[0]){
                skill3_of_character2[0].render(NULL);
                if(is_effect_for_ingrident_of_skill3_of_AI_actived[0]){
                    effect_for_skill3_of_character2[0].render(NULL);
                }
            }


            if(is_ingradient_of_skill3_from_character2_actived[1]){
                skill3_of_character2[1].render(NULL);
                if(is_effect_for_ingrident_of_skill3_of_AI_actived[1]){
                    effect_for_skill3_of_character2[1].render(NULL);
                }
            }


      if(does_skill1_of_character1_active){

          skill1_of_character1.settdx(tdx_skill1_of_character1);
      skill1_of_character1.settdy(tdy_skill1_of_character1);
      skill1_of_character1.setheight(44);
      skill1_of_character1.setwidth(60);

      effect_for_skill1_of_character1.settdx(tdx_beam);
      effect_for_skill1_of_character1.settdy(tdy_beam);
      effect_for_skill1_of_character1.setheight(height_of_beam);
      effect_for_skill1_of_character1.setwidth(width_of_beam);

         skill1_of_character1.render(&skill1_of_character1_clip[skill1_of_character1_frame/30]);

           if(skill1_of_character1_frame/30>=1){

            effect_for_skill1_of_character1.render(NULL);

           }


      }


      for(int i=0;i<quatities_of_skill2_for_character1;i++){

            if(is_ingradient_of_skill2_from_character1_actived[i]){
                skill2_of_character1[i].settdx(tdx_for_ingradient_of_skill2_character1[i]);
                skill2_of_character1[i].settdy(tdy_for_ingradient_of_skill2_character1[i]);
                skill2_of_character1[i].render(NULL);

            }
      }

      if(does_skill3_of_character1_active){

        skill3_of_character1.render(NULL);
      }



      health_bar_1_for_character1.render(NULL);
      health_bar_1_for_character2.render(NULL);
      health_bar_2_for_character1.render(NULL);
      health_bar_2_for_character2.render(NULL);
      character1_face.render(NULL);
      character2_face.render(NULL);







}
