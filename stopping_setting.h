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
                  SDL_Rect skill1_of_character1_clip[],bool choose_skin1,bool choose_skin2,
                  Ltexture anti_void,SDL_Rect anti_void_clip[],int anti_void_frame,bool does_anti_void_appear,
                  Ltexture ink_sans,SDL_Rect ink_sans_clip[],int ink_sans_frame,
                  Ltexture skill1_of_ink,SDL_Rect skill1_of_ink_clip[],int skill1_of_ink_frame,bool does_skill1_of_ink_sans_active,
                  Ltexture effect_for_skill1_of_ink ,bool ink_sans_mvr,bool choose_map1,bool choose_map2){

               // set interface when stopping time

             background.settdx(0);
             background.settdy(0);
             background.setheight(height_of_screen);
             background.setwidth(width_of_screen);
        if(choose_map1){
            background.loadtexture("image/map1.bmp");//
         }

         if(choose_map2){
            background.loadtexture("image/map2.bmp");//
         }



        if(choose_skin1){
            if(choose_right_1){

                character1.loadtexture("image/sans_moving_right.bmp");

            }
            if(choose_left_1){

                character1.loadtexture("image/sans_moving_left.bmp");
            }

             character1_face.loadtexture("image/sans_face.bmp");


            skill1_of_character1.loadtexture("image/gb.bmp");
            effect_for_skill1_of_character1.loadtexture("image/gb_beam.bmp");

             skill3_of_character1.loadtexture("image/sans_bone_zone.bmp");
        }




        if(choose_skin2){
            if(choose_right_1){

                character1.loadtexture("image/error_sans_mvr.bmp");

            }
            if(choose_left_1){

                character1.loadtexture("image/error_sans_mvl.bmp");
            }

             character1_face.loadtexture("image/error_sans_face.bmp");
            skill1_of_character1.loadtexture("image/error_blaster.bmp");
            effect_for_skill1_of_character1.loadtexture("image/error_gb_beam.bmp");

            skill1_of_ink.loadtexture("image/ink_sans_gb.bmp");
            effect_for_skill1_of_ink.loadtexture("image/gb_beam.bmp");

             skill3_of_character1.loadtexture("image/error_sans_bone_zone.bmp");
             anti_void.loadtexture("image/anti_void.bmp");

             if(ink_sans_mvr){
                ink_sans.loadtexture("image/ink_sans.bmp");
            }
            else{
                ink_sans.loadtexture("image/ink_sans_mvl.bmp");
            }





        }




            if(right_AI){
                character2.loadtexture("image/chara_moving_right.bmp");

            }
            if(left_AI){
                character2.loadtexture("image/chara_moving_left.bmp");
            }

            skill1_of_AI.loadtexture("image/chara_hit_directly.bmp");

            if(right_for_skill2_of_character2){character2_skill2.loadtexture("image/slash_chara_right.bmp");}
            if(left_for_skill2_of_character2){character2_skill2.loadtexture("image/slash_chara_left.bmp");}








             health_bar_1_for_character1.loadtexture("image/health_bar_1.bmp");
            health_bar_1_for_character2.loadtexture("image/health_bar_1.bmp");
            health_bar_2_for_character1.loadtexture("image/health_bar_2.bmp");
            health_bar_2_for_character2.loadtexture("image/health_bar_2.bmp");
            character2_face.loadtexture("image/chara_face.bmp");






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


       //set anti void appear and ink sans is coming

             if(choose_skin2 && does_anti_void_appear){
                anti_void.render(&anti_void_clip[anti_void_frame/40]);
                if(ink_sans_appear){
                    ink_sans.render(&ink_sans_clip[ink_sans_frame/20]);
                }



                 //set skill of ink sans active

           if(does_skill1_of_ink_sans_active){



                skill1_of_ink.settdx(tdx_skill1_of_ink_sans);
                skill1_of_ink.settdy(tdy_skill1_of_ink_sans);
                skill1_of_ink.setheight(44);
                skill1_of_ink.setwidth(60);

                effect_for_skill1_of_ink.settdx(tdx_beam_of_ink_gb);
                effect_for_skill1_of_ink.settdy(tdy_beam_of_ink_gb);
                effect_for_skill1_of_ink.setheight(height_of_beam_from_ink_gb);
                effect_for_skill1_of_ink.setwidth(width_of_beam_from_ink_gb);

            skill1_of_ink.render(&skill1_of_ink_clip[skill1_of_ink_frame/30]);

            if(skill1_of_ink_frame/30>=1){

                effect_for_skill1_of_ink.render(NULL);

           }
           }


             }










}
