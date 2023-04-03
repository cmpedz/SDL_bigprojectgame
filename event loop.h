
#ifndef event_loop
#define event_loop
#include"texture.h"
#include"common function.h"
SDL_Event e1;
bool stopping_time=false;
#endif // event_loop

void eventloop(int &p){

    if(!init()){
     cout<<"failed to load SDL"<<endl;
  }
  else{
      if(!loadedmedia(true)){
         cout<<"failed to load media"<<endl;
      }
  else{
      SDL_Event e;
      bool quit=false;
      set_skill3_of_character2();
      set_lose_health_1();
      set_lose_health_2();
      set_value_for_menu_of_game();
      set_value_for_ingradient_of_skill2_of_character1();
      set_value_for_background_of_tutorial_menu();
      set_icon_skill_of_player();
      set_icon_pause_button();
      set_button_in_stopping_menu();
      set_effect_miss();

      while(!quit){
         SDL_RenderClear(renderer);
         if(reset_everything_in_game){

            // create free function
           character1.free();
           character2.free();
           skill1_of_AI.free(); // need to be added in your code
           background.free();
           character1_face.free();
           character2_face.free();
           health_bar_1_for_character1.free();
           health_bar_1_for_character2.free();
           health_bar_2_for_character1.free();
           health_bar_2_for_character2.free();
           character2_skill2.free();
           game_over_class.free();
           get_dunked_on.free();
           skill1_of_character1.free();
           skill3_of_character1.free();

           free_memory_about_value_of_ch1_and_chr2();
           for(int i=0;i<quatities_of_bone;i++){
              tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
              tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
           }

            is_ingradient_of_skill3_from_character2_actived[0]=false;
            is_ingradient_of_skill3_from_character2_actived[1]=false;
            tdx_for_ingradient_of_skill3_character2[0]=1080;
            tdy_for_ingradient_of_skill3_character2[0]=tdy_character2;
            skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
            skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);


             tdx_for_ingradient_of_skill3_character2[1]=tdx_character1;
             tdy_for_ingradient_of_skill3_character2[1]=0;
             skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
             skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);

            tdx_of_losing_effect1=tdx_character1+5;
            tdy_of_losing_effect1=height_of_screen/4*3;
            key_active_effect_of_losing_health1=false;

            tdx_of_losing_effect2=tdx_character2+5;
            tdy_of_losing_effect2=height_of_screen/4*3;
            key_active_effect_of_losing_health2=false;


            if(!time_watting_change_interface){
              time_in_game=SDL_GetTicks();
              thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=true;
              game_over=false;
              game_win=false;
              SDL_RenderClear(renderer);
              reset_everything_in_game=false;
            }
            if(time_watting_change_interface>0){
               time_watting_change_interface--;
            }



         }
         else{
             time_watting_change_interface=5;
         }






        if(thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game){
          if(!stopping_time){

       /**************************************giao dien man hinh game************************************/
           while(SDL_PollEvent(&e)!=0){
                if(e.type==SDL_QUIT){
                   quit=true;
                }
                if(e.type==SDL_KEYDOWN){
                   switch(e.key.keysym.sym){
                   case SDLK_RIGHT :
                        time_run_of_character1=SDL_GetTicks();

                        right_1=true;
                        choose_right_1=true;
                        choose_left_1=false;
                        left_for_skill2_of_character1=false;
                        right_for_skill2_of_character1=true;
                        break;
                   case SDLK_LEFT :
                        time_run_of_character1=SDL_GetTicks();
                        left_1=true;
                        choose_left_1=true;
                        choose_right_1=false;
                        left_for_skill2_of_character1=true;
                        right_for_skill2_of_character1=false;
                        break;
                   case SDLK_1 :
                        if(time_watting_for_skill1_of_character1==0){
                          does_skill1_of_character1_active=true;
                          tdx_skill1_of_character1=character2.gettdx();
                          tdy_skill1_of_character1=character2.gettdy()-100;
                          tdx_beam=tdx_skill1_of_character1+30;
                          tdy_beam=tdy_skill1_of_character1+50;
                        }
                        break;
                   case SDLK_2 :
                        if(time_watting_of_skill2_from_character1==0){
                          set_skill2_of_character1();
                          quatities_of_skill2_for_character1++;


                           if(quatities_of_skill2_for_character1 >=4){
                             quatities_of_skill2_for_character1=3;

                           }



                          if(quatities_of_skill2_for_character1>=1){
                            is_ingradient_of_skill2_from_character1_actived[quatities_of_skill2_for_character1-1]=true;
                          }


                        }
                        break;
                   case SDLK_3 :
                        if(time_watting_of_skill3_from_character1==0){
                          does_skill3_of_character1_active=true;
                          height_of_bone=0;
                        }
                        break;
                   case SDLK_UP :
                        if(!can_character1_jump){
                           v_of_character1=12; //pixel/s
                           set_time_in_the_air_of_character1=SDL_GetTicks();
                           can_character1_jump=true;
                        }
                        break;
                   case SDLK_ESCAPE :
                        quit=true;
                        break;
                   }
                }
            }


           if(!game_over && !game_win){


           back_ground();
           set_icon_appear_and_active(time_watting_for_skill1_of_character1,
                                      time_watting_of_skill2_from_character1,
                                      time_watting_of_skill3_from_character1,
                                      time_watting_teleport);

            SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);

            set_icon_pause_button_active(tdx_of_my_mouse,tdy_of_my_mouse,quality_of_click,e1);

           //*************************************************//
           //set character1 jump

          set_chr1_jump(can_character1_jump,tdy_character1,tdy_of_ground,set_time_in_the_air_of_character1,v_of_character1);


           //set moving right and left for character 1
           movingright(right_1,character1_frame,choose_right_1,time_run_of_character1,tdx_character1);

           movingleft(left_1,character1_frame,choose_left_1,time_run_of_character1,tdx_character1);




           /*************************************************************************/

           character_1(tdx_character1,tdy_character1,character1_frame,choose_right_1,choose_left_1);


           set_skill1_of_character1(tdx_skill1_of_character1,tdy_skill1_of_character1,height_of_beam,width_of_beam,tdx_beam,tdy_beam,time_watting_for_skill1_of_character1);


           /**************************************************************************/



           // set AI moving and hit player when he/she stands near AI
           set_AI_move(tdx_character1, tdy_character1,character2_can_not_move,right_AI,left_AI,
                       tdx_character2,tdy_character2,time_in_game,start_time,width_of_screen,character2_frame,
                       time_appearing_of_skill1_from_AI,did_character1_get_hit);


      if(tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30 && tdy_character2 == tdy_character1){

           if(did_character1_get_hit && health_bar_2_of_character1 >0){
                 losing_health_of_ch1=5;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit);

              }
              else{
                  losing_health_of_ch1=0;
                  key_active_effect_of_losing_health1=false;
              }

              // set AI skill1 appear
             AI_skill1((SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI)/200);
             skill1_of_AI.render(&skill1_of_AI_clip[(SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI)/200]);

      }




        // set skill1 of character 1 appearing and making damage on AI
        if(does_skill1_of_character1_active){
           set_skill1_of_character1_active(tdy_character2,tdx_beam,tdx_skill1_of_character1,
                                           tdy_skill1_of_character1,height_of_beam,width_of_beam,tdy_beam,
                                           time_watting_for_skill1_of_character1,did_character2_get_hit);

           if(did_character2_get_hit && health_bar_2_of_character2>0){
              losing_health_of_ch2=1;
              set_ch2_loses_health(health_bar_2_of_character2,health_bar_2_for_character2,losing_health_of_ch2,
                                      key_active_effect_of_losing_health2,tdx_character2,tdy_character2,
                                      did_character2_get_hit,tdx_health_bar_2_of_character2);
           }
           else{
               losing_health_of_ch2=0;
               key_active_effect_of_losing_health2=false;
           }
        }







        // set skill2 of character 1 appearing and making damage on AI


                  set_skill2_of_character1_actived(quatities_of_skill2_for_character1,tdx_for_ingradient_of_skill2_character1,
                                                   tdy_for_ingradient_of_skill2_character1,
                                                   is_ingradient_of_skill2_from_character1_actived,
                                                   time_watting_of_skill2_from_character1,
                                                   did_character2_get_hit,quatities_of_bone);


            for(int i=0;i<quatities_of_skill2_for_character1;i++){

                   if(did_character2_get_hit_by_skill2[i] && health_bar_2_of_character2>0){
                        losing_health_of_ch2=10;
                        set_ch2_loses_health(health_bar_2_of_character2,health_bar_2_for_character2,losing_health_of_ch2,
                                      key_active_effect_of_losing_health2,tdx_character2,tdy_character2,
                                      did_character2_get_hit_by_skill2[i],tdx_health_bar_2_of_character2);
                    }
                    else{
                        losing_health_of_ch2=0;
                        key_active_effect_of_losing_health2=false;
                    }


            }






        // set AI dodge and jump skill2 and skill1

              set_AI_dodge(quatities_of_bone,is_ingradient_of_skill2_from_character1_actived,
                  tdx_character2,tdx_character1,tdx_for_ingradient_of_skill2_character1,chance_to_jump_of_AI,
                  can_character2_jump,set_time_in_the_air_of_character2,tdy_character2,
                  tdy_of_ground,v_of_character2,does_skill1_of_character1_active,chance_to_teleport,time_watting_teleport,
                  character2_can_not_move,key_active_effect_miss);






//*************************************************************//


            //set skill 3 for character1 and cause damage on AI


            set_skill3_of_ch1_active(does_skill3_of_character1_active,time_watting_of_skill3_from_character1,
                                    tdx_character2,tdy_character2, height_of_bone,
                                    character2_can_not_move,time_appearing_of_skill3_from_character1,
                                    skill3_of_character1,did_character2_get_hit);
          if(does_skill3_of_character1_active){
            if(did_character2_get_hit && health_bar_2_of_character2>0){
                 losing_health_of_ch2=1;
                 set_ch2_loses_health(health_bar_2_of_character2,health_bar_2_for_character2,losing_health_of_ch2,
                                      key_active_effect_of_losing_health2,tdx_character2,tdy_character2,
                                      did_character2_get_hit,tdx_health_bar_2_of_character2);
              }
              else{
                  key_active_effect_of_losing_health2=false;
                  losing_health_of_ch2=0;
              }
          }



         // set skill2_of_AI_actived
         set_skill2_of_AI_active(character1, character2,time_watting_for_skill2_of_AI,
                               is_skill2_of_character2_actived, tdx_character2, tdy_character2,
                               tdx_of_skill2_character2,tdy_of_skill2_character2,
                               left_AI,left_for_skill2_of_character2,right_for_skill2_of_character2,
                               tdx_character1,tdy_character1,did_character1_get_hit);

             // heal_bar_of_character1_is_damaged_by_skill2_of_AI
           if(is_skill2_of_character2_actived){
             if(did_character1_get_hit && health_bar_2_of_character1 >0 ){
                 losing_health_of_ch1=50;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit);
                 is_skill2_of_character2_actived=false;
                 time_watting_for_skill2_of_AI=100;
              }
              else{
                  losing_health_of_ch1=0;
                  key_active_effect_of_losing_health1=false;
              }
           }






          // set skill3 of Ai active
          set_skill3_of_character2_active(time_in_game,did_character1_get_hit_by_skill3,tdx_character1,tdy_character1);
          // set skill3 of AI make damage on player

          // first damage


           if(did_character1_get_hit_by_skill3[0] && health_bar_2_of_character1 >0){

                 losing_health_of_ch1=10;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit_by_skill3[0]);

              }
              else{
                  key_active_effect_of_losing_health1=false;
              }



         //second damage

          if(did_character1_get_hit_by_skill3[1] && health_bar_2_of_character1 >0){

                 losing_health_of_ch1=5;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit_by_skill3[1]);


          }
          else{ key_active_effect_of_losing_health1=false;}



          //set effect miss for AI
          set_effect_miss_active(key_active_effect_miss);

          //
          set_health_bar_for_character1(health_bar_2_of_character1);
          set_health_bar_for_character2(health_bar_2_of_character2,tdx_health_bar_2_of_character2);
           //
           AI(tdx_character2,tdy_character2,character2_frame,right_AI,left_AI);
           if(health_bar_2_of_character1<=0){
              game_over=true;
           }
           if(health_bar_2_of_character2<=0){
              game_win=true;
              p=p+100;
           }



           }

         else{

        /**********set game over***********************/
             if(game_over){
                game_over_system();


                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    if(e.type==SDL_MOUSEBUTTONDOWN||e.type==SDL_MOUSEBUTTONUP||e.type==SDL_MOUSEMOTION ){
                        SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);

                        if(tdx_of_my_mouse>=button_quit_in_game_over.gettdx() && button_quit_in_game_over.gettdx()+width_of_button_quit_and_continue_in_game_over>=tdx_of_my_mouse &&
                           button_quit_in_game_over.gettdy()<=tdy_of_my_mouse && button_quit_in_game_over.gettdy()+height_of_button_quit_and_continue_in_game_over>=tdy_of_my_mouse){
                            inside_button_quit_in_the_game_over=true;
                        }
                        else{inside_button_quit_in_the_game_over=false;}


                        if(tdx_of_my_mouse>=button_continue_in_game_over.gettdx() && button_continue_in_game_over.gettdx()+width_of_button_quit_and_continue_in_game_over>=tdx_of_my_mouse &&
                           button_continue_in_game_over.gettdy()<=tdy_of_my_mouse && button_continue_in_game_over.gettdy()+height_of_button_quit_and_continue_in_game_over>=tdy_of_my_mouse){
                            inside_button_continue_in_the_game_over=true;
                        }
                        else{inside_button_continue_in_the_game_over=false;}



                        if( inside_button_quit_in_the_game_over )
                        {

                               switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                button_quit_frame_in_game_over=1;
                                break;
                                case SDL_MOUSEBUTTONUP :
                                thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                                reset_everything_in_main_interface=true;
                                 game_over=false;
                                 game_win=false;
                                break;


                                }

                        }
                        else{
                             button_quit_frame_in_game_over=0;
                        }




                        if( inside_button_continue_in_the_game_over )
                        {

                               switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                button_continue_frame_in_game_over=1;
                                break;
                                case SDL_MOUSEBUTTONUP :
                                reset_everything_in_game=true;
                                break;


                                }

                        }
                        else{
                             button_continue_frame_in_game_over=0;
                        }


                }



                     }
             }



//*************************set game win******************************************/

             if(game_win){
                set_winner_system();
                  while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    if(e.type==SDL_MOUSEBUTTONDOWN||e.type==SDL_MOUSEBUTTONUP||e.type==SDL_MOUSEMOTION ){

                        SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);


                        if(tdx_of_my_mouse>=button_quit_in_game_win.gettdx() &&
                           button_quit_in_game_win.gettdx()+width_of_button_quit_and_continue_in_game_win>=tdx_of_my_mouse &&
                           button_quit_in_game_win.gettdy()<=tdy_of_my_mouse &&
                           button_quit_in_game_win.gettdy()+height_of_button_quit_and_continue_in_game_win>=tdy_of_my_mouse){
                            inside_button_quit_in_the_game_win=true;
                        }
                        else{inside_button_quit_in_the_game_win=false;}


                        if(tdx_of_my_mouse>=button_continue_in_game_win.gettdx() &&
                           button_continue_in_game_win.gettdx()+width_of_button_quit_and_continue_in_game_win>=tdx_of_my_mouse &&
                           button_continue_in_game_win.gettdy()<=tdy_of_my_mouse &&
                           button_continue_in_game_win.gettdy()+height_of_button_quit_and_continue_in_game_win>=tdy_of_my_mouse){
                            inside_button_continue_in_the_game_win=true;
                        }
                        else{inside_button_continue_in_the_game_win=false;}



                        if( inside_button_quit_in_the_game_win )
                        {

                               switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                button_quit_frame_in_game_win=1;
                                break;
                                case SDL_MOUSEBUTTONUP :
                                thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                                reset_everything_in_main_interface=true;
                                 game_over=false;
                                 game_win=false;
                                break;


                                }

                        }
                        else{
                             button_quit_frame_in_game_win=0;
                        }




                        if( inside_button_continue_in_the_game_win )
                        {

                               switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                button_continue_frame_in_game_win=1;
                                break;
                                case SDL_MOUSEBUTTONUP :
                                reset_everything_in_game=true;
                                break;


                                }

                        }
                        else{
                             button_continue_frame_in_game_win=0;
                        }
             }
         }







             }



         }











         //*************** set time wait or reset tdx,tdy *********************//

           //
           time_watting_for_skill2_of_AI--;
           if(time_watting_for_skill2_of_AI<0){
              time_watting_for_skill2_of_AI=0;
           }
           if((character2_skill2.gettdx()<=0 || character2_skill2.gettdx()>=1080) && is_skill2_of_character2_actived ){
             is_skill2_of_character2_actived=false;
           }

           if(time_watting_of_skill3_from_character1>0){
              time_watting_of_skill3_from_character1--;
           }




        }

        /*else{
            did_character1_get_hit=false;
            did_character2_get_hit=false;
            back_ground();

            set_icon_appear_and_active(time_watting_for_skill1_of_character1,
                                      time_watting_of_skill2_from_character1,
                                      time_watting_of_skill3_from_character1,
                                      time_watting_teleport);


            set_icon_pause_button_active(tdx_of_my_mouse,tdy_of_my_mouse,quality_of_click,e1);

            set_health_bar_for_character1(health_bar_2_of_character1);

            set_health_bar_for_character2(health_bar_2_of_character2,tdx_health_bar_2_of_character2);

            movingright(right_1,character1_frame,choose_right_1,time_run_of_character1,tdx_character1);

            movingleft(left_1,character1_frame,choose_left_1,time_run_of_character1,tdx_character1);

            character_1(tdx_character1,tdy_character1,character1_frame,choose_right_1,choose_left_1);

            set_skill1_of_character1(tdx_skill1_of_character1,tdy_skill1_of_character1,height_of_beam,width_of_beam,tdx_beam,tdy_beam);

             if(tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30 && tdy_character2 == tdy_character1){


              // set AI skill1 appear
             AI_skill1((SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI)/200);
             skill1_of_AI.render(&skill1_of_AI_clip[(SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI)/200]);

              }

               if(does_skill1_of_character1_active){ set_skill1_of_character1_active(tdy_character2,tdx_beam,tdx_skill1_of_character1,tdy_skill1_of_character1,height_of_beam,width_of_beam,tdy_beam,time_watting_for_skill1_of_character1);}




        }*/

          character1.free();
           character2.free();
           skill1_of_AI.free(); // need to be added in your code
           background.free();
           character1_face.free();
           character2_face.free();
           health_bar_1_for_character1.free();
           health_bar_1_for_character2.free();
           health_bar_2_for_character1.free();
           health_bar_2_for_character2.free();
           character2_skill2.free();
           game_over_class.free();
           get_dunked_on.free();
           skill1_of_character1.free();
           skill3_of_character1.free();




       }

       else{


       /**************************************giao dien man hinh chinh************************************/
       //set man hinh chinh tro lai trang thai ban dau khi thoat man hinh huong dan

        if(reset_everything_in_main_interface){
		   reset_everything_in_main_interface_active();


       }
             menu_background.render(&menu_background_clip[menu_background_frame]);
                if(((SDL_GetTicks()-time_in_interface_of_game)/1000%5==0||(SDL_GetTicks()-time_in_interface_of_game)/1000%5==1) && (SDL_GetTicks()-time_in_interface_of_game)>0){
                   can_soul_of_chara_appear=true;
                   can_soul_of_sans_appear=true;
                   menu_background_frame=1;
                   menu_background.render(&menu_background_clip[menu_background_frame]);
                }
                else{
                     can_soul_of_chara_appear=false;
                     can_soul_of_sans_appear=false;
                    menu_background_frame=0;
                }
                sans_in_bg.render(NULL);
                if(can_soul_of_sans_appear){soul_of_sans_in_bg.render(NULL);}
                chara_in_bg.render(NULL);
                if(can_soul_of_chara_appear){soul_of_chara_in_bg.render(NULL);}
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    if(e.key.keysym.sym==SDLK_ESCAPE){ does_tutorial_menu_appear=false; }
                     if((e.type==SDL_MOUSEBUTTONDOWN||e.type==SDL_MOUSEBUTTONUP||e.type==SDL_MOUSEMOTION) &&
                        !(image_quit.gettdx()<width_of_screen/2-button_width/2 ||
                        image_start.gettdx()<width_of_screen/2-button_width/2||
                        image_tutorial.gettdx()<width_of_screen/2-button_width/2) &&
                        !does_tutorial_menu_appear){

                        SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);
      //Mouse is left of the button
                        if(tdx_of_my_mouse>=start_button_system->gettdx() && start_button_system->gettdx()+button_width>=tdx_of_my_mouse && start_button_system->gettdy()<=tdy_of_my_mouse && start_button_system->gettdy()+button_height>=tdy_of_my_mouse){
                            inside_start_button=true;
                        }
                        else{inside_start_button=false;}
                         if(tdx_of_my_mouse>=tutorial_button_system->gettdx() && tutorial_button_system->gettdx()+button_width>=tdx_of_my_mouse && tutorial_button_system->gettdy()<=tdy_of_my_mouse && tutorial_button_system->gettdy()+button_height>=tdy_of_my_mouse){
                            inside_tutorial_button=true;
                        }
                        else{inside_tutorial_button=false;}
                        if(tdx_of_my_mouse>=quit_button_system->gettdx() &&
                           quit_button_system->gettdx()+button_width>=tdx_of_my_mouse
                           && quit_button_system->gettdy()<=tdy_of_my_mouse
                           && quit_button_system->gettdy()+button_height>=tdy_of_my_mouse){
                            inside_quit_button=true;
                        }
                        else{inside_quit_button=false;}
        //Mouse is outside button
                        if( inside_start_button )
                        {      is_bonus_sprite1_for_start_button_active=true;

                               switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                start_button_frame=1;
                                break;
                                case SDL_MOUSEBUTTONUP :
                                is_bonus_sprite2_for_start_button_active=true;

                                break;


                                }

                        }
                        else{
                            is_bonus_sprite1_for_start_button_active=false;
                            start_button_frame=0;
                        }
        //Mouse is inside button


                          if( inside_tutorial_button )
                        {

                               is_bonus_sprite1_for_tutorial_button_active=true;
                            switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                tutorial_button_frame=1;
                                break;
                                case SDL_MOUSEBUTTONUP:
                                is_bonus_sprite2_for_tutorial_button_active=true;
                                break;


                                }
                        }
                        else{
                             is_bonus_sprite1_for_tutorial_button_active=false;
                             tutorial_button_frame=0;
                        }
        //Mouse is inside button



                        if( inside_quit_button )
                        {   is_bonus_sprite1_for_end_button_active=true;

                            switch( e.type )
                                {
                                case SDL_MOUSEMOTION:
                                quit_button_frame=1;
                                break;
                                case SDL_MOUSEBUTTONUP:
                                quit=true;
                                break;


                        }
                        }
                        else{
                             is_bonus_sprite1_for_end_button_active=false;
                             quit_button_frame=0;
                        }


                }



                     }







                //set 3 button start,tutorial,quit moving

                if((SDL_GetTicks()-time_in_interface_of_game)/1000>=2){
                  if(image_quit.gettdx()<width_of_screen/2-button_width/2 ||
                     image_start.gettdx()<width_of_screen/2-button_width/2||
                     image_tutorial.gettdx()<width_of_screen/2-button_width/2){
                     image_start.settdx(image_start.gettdx()+15);
                     image_tutorial.settdx(image_tutorial.gettdx()+15);
                     image_quit.settdx(image_quit.gettdx()+15);

                  }


                    image_start.render(&start_button_clip[start_button_frame]);
                    image_tutorial.render(&tutorial_button_clip[tutorial_button_frame]);
                    image_quit.render(&quit_button_clip[quit_button_frame]);
                }
                else{
                     image_quit.settdx(-quit_button_system[0].gettdx());
                     image_start.settdx(-start_button_system[0].gettdx());
                     image_tutorial.settdx(-tutorial_button_system[0].gettdx());
                }



                // set bonus sprite active when mouse inside button
                set_bonus_sprite_active_when_mouse_inside_button();


                // set bonus sprite active when mouse up or down
                 set_bonus_sprite_active_when_mouse_up_or_down(does_tutorial_menu_appear);

                //sans in br moving
                if(!repeat_moving_of_sans){
                  if(!(sans_in_bg.gettdx()>=0-20 || sans_in_bg.gettdy()<=height_of_screen-640+15) ){
                        sans_in_bg.settdx(sans_in_bg.gettdx()+5);
                        sans_in_bg.settdy(sans_in_bg.gettdy()-5);

                  }
                  else{
                      repeat_moving_of_sans=true;

                  }
                }



                else{
                    if(SDL_GetTicks()/1000%2==0){
                        sans_in_bg.settdx(sans_in_bg.gettdx()-1);
                        sans_in_bg.settdy(sans_in_bg.gettdy()+1);

                    }
                    else{
                         sans_in_bg.settdx(sans_in_bg.gettdx()+1);
                         sans_in_bg.settdy(sans_in_bg.gettdy()-1);
                    }

                }


                // soul of sans  moving


               if(!repeat_moving_of_soul_of_sans){
                  if(!(soul_of_sans_in_bg.gettdx()>=0+20-15 || soul_of_sans_in_bg.gettdy()<=height_of_screen-640-100+15) ){
                        soul_of_sans_in_bg.settdx(soul_of_sans_in_bg.gettdx()+5);
                        soul_of_sans_in_bg.settdy(soul_of_sans_in_bg.gettdy()-5);

                  }
                  else{
                      repeat_moving_of_soul_of_sans=true;

                  }
                }


                else{
                    if(SDL_GetTicks()/1000%2==0){
                        soul_of_sans_in_bg.settdx(soul_of_sans_in_bg.gettdx()-1);
                        soul_of_sans_in_bg.settdy(soul_of_sans_in_bg.gettdy()+1);

                    }
                    else{
                         soul_of_sans_in_bg.settdx(soul_of_sans_in_bg.gettdx()+1);
                         soul_of_sans_in_bg.settdy(soul_of_sans_in_bg.gettdy()-1);
                    }

                }






                 // chara in br moving

                if(!repeat_moving_of_chara){
                  if(!(chara_in_bg.gettdx()<=width_of_screen-442+50 || chara_in_bg.gettdy()>=0) ){
                        chara_in_bg.settdx(chara_in_bg.gettdx()-442/100+50/100);
                        chara_in_bg.settdy(chara_in_bg.gettdy()+286/100);

                  }
                  else{
                      repeat_moving_of_chara=true;
                      chara_in_bg.settdy(0-50);

                  }
                }


                else{
                    if(SDL_GetTicks()/1000%2==0){
                        chara_in_bg.settdx(chara_in_bg.gettdx()-1);
                        chara_in_bg.settdy(chara_in_bg.gettdy()+1);

                    }
                    else{
                         chara_in_bg.settdx(chara_in_bg.gettdx()+1);
                         chara_in_bg.settdy(chara_in_bg.gettdy()-1);
                    }

                }




                //soul of chara moving
                if(!repeat_moving_of_soul_of_chara){
                    if(!(soul_of_chara_in_bg.gettdx()<=width_of_screen-442-100 || soul_of_chara_in_bg.gettdy()>=100) ){
                        soul_of_chara_in_bg.settdx(soul_of_chara_in_bg.gettdx()-442/100);
                        soul_of_chara_in_bg.settdy(soul_of_chara_in_bg.gettdy()+286/100);

                    }
                    else{
                        repeat_moving_of_soul_of_chara=true;

                    }
                }


                else{
                    if(SDL_GetTicks()/1000%2==0){
                        soul_of_chara_in_bg.settdx(soul_of_chara_in_bg.gettdx()-1);
                        soul_of_chara_in_bg.settdy(soul_of_chara_in_bg.gettdy()+1);

                    }
                    else{
                         soul_of_chara_in_bg.settdx(soul_of_chara_in_bg.gettdx()+1);
                         soul_of_chara_in_bg.settdy(soul_of_chara_in_bg.gettdy()-1);
                    }

                }


                 if(does_tutorial_menu_appear){
                    set_tutorial_menu_active();
                    reset_everything_in_main_interface=true;
                 }
                 else{ reset_everything_in_main_interface=false;}




       }








            SDL_RenderPresent( renderer );


      }
  }
}
  }


