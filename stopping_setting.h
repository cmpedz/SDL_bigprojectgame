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
                  bool is_ingradient_of_skill2_from_character1_actived,Ltexture skill2_of_character1[],
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


          // set everything in game stop when we pause game

            background.render(NULL);



         if(choose_skin1){







        character1.settdx(tdx_character1);
        character1.settdy(tdy_character1);
        character1.setheight(60); //60
        character1.setwidth(36);  //36
        character1.loadtexture("image/dust_sans_mvr.bmp");
        character1_face.loadtexture("image/sans_face.bmp");
          skill1_of_character1.loadtexture("image/gb.bmp");
            effect_for_skill1_of_character1.loadtexture("image/gb_beam.bmp");

             skill3_of_character1.loadtexture("image/sans_bone_zone.bmp");

        //set sprite for charater jump
        if((can_character1_jump || tdy_character1 < tdy_of_ground) && !(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI
            || sprite_for_ch_get_dam_by_skill3_of_AI) && can_character1_run_after_using_skill1 &&
           can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){


            if(choose_right_1){



                 character1.loadtexture("image/dust_sans_jump_r.bmp");
            }


            if(choose_left_1){


                 character1.loadtexture("image/dust_sans_jump_l.bmp");
            }


             character1.render(&character1_clip[character_frame_jump/10]);

        }

        else{


        //set sprite for ch mv right or left

        if(!(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI || sprite_for_ch_get_dam_by_skill3_of_AI) &&
           can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){
        if(choose_right_1){



           character1.loadtexture("image/dust_sans_mvr.bmp");

        }
        if(choose_left_1){




          character1.loadtexture("image/dust_sans_mvl.bmp");
        }


         character1.render(&character1_clip[character1_frame/5]);



        }




        else{


        //set sprite when character is damaged
        if(can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2
           && can_character1_run_after_using_skill3){
        character1.setheight(60);
        character1.setwidth(48);

        if(choose_right_1){



          character1.loadtexture("image/dust_sans_is_damaged_r.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }

         if(choose_left_1){

          character1.loadtexture("image/dust_sans_is_damaged_l.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }



        }





        else{

            if(can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill1
            if(choose_right_1){

                character1.loadtexture("image/dust_sans_use_skill1_r.bmp");

            }


             if(choose_left_1){

                character1.loadtexture("image/dust_sans_use_skill1_l.bmp");



            }

            if(character_frame_use_skill1/5==2){
                character1.setheight(60);
                character1.setwidth(58);

            }

            character1.render(&character1_clip[character_frame_use_skill1/5]);



        }

        else{


        if(can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill2
             if(choose_right_1){

                character1.loadtexture("image/dust_sans_use_skill2_r.bmp");
             }

              if(choose_left_1){

                character1.loadtexture("image/dust_sans_use_skill2_l.bmp");
             }

                if(character_frame_use_skill2/5>=1 && character_frame_use_skill2/5<2){
                    character1.setheight(55);
                   character1.setwidth(53);

                }
                character1.render(&character1_clip[character_frame_use_skill2/5]);

        }

        else{
             //set sprite for ch when player use skill3
              if(choose_right_1){


                character1.loadtexture("image/dust_sans_use_skill3_r.bmp");
             }

             if(choose_left_1){

                character1.loadtexture("image/dust_sans_use_skill3_l.bmp");
             }



             character1.render(&character1_clip[character_frame_use_skill3/5]);



        }




        }



        }


        }




















        }






        }














        if(choose_skin2){







        character1.settdx(tdx_character1);
        character1.settdy(tdy_character1);
        character1.setheight(60); //60
        character1.setwidth(36);  //36
        character1.loadtexture("image/error_sans_mvr.bmp");
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


        //set sprite for charater jump
        if((can_character1_jump || tdy_character1 < tdy_of_ground) && !(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI
            || sprite_for_ch_get_dam_by_skill3_of_AI) && can_character1_run_after_using_skill1 &&
           can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){


            if(choose_right_1){

                 character1.loadtexture("image/error_sans_jump_r.bmp");
            }


            if(choose_left_1){

                 character1.loadtexture("image/error_sans_jump_l.bmp");
            }


             character1.render(&character1_clip[character_frame_jump/10]);

        }

        else{


        //set sprite for ch mv right or left

        if(!(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI || sprite_for_ch_get_dam_by_skill3_of_AI) &&
           can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){
        if(choose_right_1){

           character1.loadtexture("image/error_sans_mvr.bmp");

        }
        if(choose_left_1){


          character1.loadtexture("image/error_sans_mvl.bmp");
        }


         character1.render(&character1_clip[character1_frame/5]);



        }




        else{


        //set sprite when character is damaged
        if(can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2
           && can_character1_run_after_using_skill3){
        character1.setheight(60);
        character1.setwidth(48);

        if(choose_right_1){


          character1.loadtexture("image/error_sans_is_damaged_r.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }

         if(choose_left_1){

          character1.loadtexture("image/error_sans_is_damaged_l.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }



        }





        else{

            if(can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill1
            if(choose_right_1){

                character1.loadtexture("image/error_sans_skill1_r.bmp");

            }


             if(choose_left_1){

                character1.loadtexture("image/error_sans_skill1_l.bmp");



            }

            if(character_frame_use_skill1/5==2){
                character1.setheight(60);
                character1.setwidth(58);

            }

            character1.render(&character1_clip[character_frame_use_skill1/5]);



        }

        else{


        if(can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill2
             if(choose_right_1){

                character1.loadtexture("image/error_sans_skill2_r.bmp");
             }

              if(choose_left_1){

                character1.loadtexture("image/error_sans_skill2_l.bmp");
             }

                if(character_frame_use_skill2/5==1){
                    character1.setheight(60);
                   character1.setwidth(58);

                }
                character1.render(&character1_clip[character_frame_use_skill2/5]);

        }

        else{
             //set sprite for ch when player use skill3
              if(choose_right_1){

                character1.loadtexture("image/error_sans_skill3_r.bmp");
             }

             if(choose_left_1){

                character1.loadtexture("image/error_sans_skill3_l.bmp");
             }



             character1.render(&character1_clip[character_frame_use_skill3/5]);



        }




        }



        }


        }




















        }






        }



            if(right_for_skill2_of_character2){character2_skill2.loadtexture("image/slash_chara_right.bmp",255,255,255);}
            if(left_for_skill2_of_character2){character2_skill2.loadtexture("image/slash_chara_left.bmp",255,255,255);}








             health_bar_1_for_character1.loadtexture("image/health_bar_1.bmp");
            health_bar_1_for_character2.loadtexture("image/health_bar_1.bmp");
            health_bar_2_for_character1.loadtexture("image/health_bar_2.bmp");
            health_bar_2_for_character2.loadtexture("image/health_bar_2.bmp");
            character2_face.loadtexture("image/chara_face.bmp");










           if(!(can_character2_jump || tdy_character2 < tdy_of_ground) && !does_AI_miss && !Does_AI_use_skill2 &&
       !(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player)&&
       !Does_AI_use_skill3){
    //set AI move r or l
        if(right_AI){

           character2.loadtexture("image/chara_moving_right.bmp",255,255,255);

        }





        if(left_AI){


            character2.loadtexture("image/chara_moving_left.bmp",255,255,255);
        }



        character2.render(&character2_clip[character2_frame/10]);
    }
    else{


        if(!does_AI_miss && !Does_AI_use_skill2
           && !(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player)
           && !Does_AI_use_skill3){
        //set sprite jumping for AI
         if(right_AI){

           character2.loadtexture("image/chara_jump_right.bmp",255,255,255);

        }


        if(left_AI){

           character2.loadtexture("image/chara_jump_left.bmp",255,255,255);

        }

        if(character2_frame_jump/10==0){
            character2.setheight(60);
            character2.setwidth(58);
        }
        character2.render(&character2_clip[character2_frame_jump/10]);

    }
    else{



    if(!Does_AI_use_skill2 && !Does_AI_use_skill3 &&
       !(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player)){
        //set sprite miss for AI
        character2.setwidth(60);
        character2.setheight(55);
          if(right_AI){

           character2.loadtexture("image/chara_tele_right.bmp",255,255,255);

        }



         if(left_AI){

           character2.loadtexture("image/chara_tele_left.bmp",255,255,255);

        }

        character2.render(&character2_clip[character2_frame_miss/10]);


        }
        else{

         if(!(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player) &&
            !Does_AI_use_skill3){
            //set sprite skill2 for AI

            if(right_AI){

           character2.loadtexture("image/chara_use_skill2_r.bmp",255,255,255);

        }


        if(left_AI){

           character2.loadtexture("image/chara_use_skill2_l.bmp",255,255,255);

        }

                character2.setheight(80);
                character2.setwidth(70);

             if(character2_frame_skill2/5>=3 && character2_frame_skill2/5<=5){
                character2.setheight(80);
                character2.setwidth(80);
             }
            character2.render(&character2_clip[character2_frame_skill2/5]);

        }
        else{

        if(!Does_AI_use_skill3){
           //set sprites for AI when he/she is hit
        if(right_AI){


         character2.loadtexture("image/chara_get_hit_right.bmp",255,255,255);







        }

        if(left_AI){



           character2.loadtexture("image/chara_get_hit_left.bmp",255,255,255);





        }



             character2.setheight(60);
             character2.setwidth(58);
             character2.render(&character2_clip[AI_get_hit_frame/5]);

        }
        else{
            //set sprites AI use skill 3

            if(right_AI){

           character2.loadtexture("image/chara_use_skill3_r.bmp",255,255,255);

        }


        if(left_AI){

           character2.loadtexture("image/chara_use_skill3_l.bmp",255,255,255);

        }

        if(AI_use_skilll3_frame/5 == 0 && AI_use_skilll3_frame/5 ==5){
          character2.setheight(70);
          character2.setwidth(46);
        }
        else{
            character2.setheight(70);
          character2.setwidth(67);
        }

        character2.render(&character2_clip[AI_use_skilll3_frame/5]);


        }


        }

        }

    }




    }



             if(is_skill2_of_character2_actived){


                 character2_skill2.render(&skill2_of_AI_clip[skill2_of_AI_frame/5]);

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

    if(is_ingradient_of_skill2_from_character1_actived){
      for(int i=0;i<quatities_of_bone;i++){


                skill2_of_character1[i].settdx(tdx_for_ingradient_of_skill2_character1[i]);
                skill2_of_character1[i].settdy(tdy_for_ingradient_of_skill2_character1[i]);
                 skill2_of_character1[i].render(&quatities_of_bone_clip[quatities_of_bone_frame/5]);

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
