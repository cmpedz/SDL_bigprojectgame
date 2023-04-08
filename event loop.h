
#ifndef event_loop
#define event_loop
#include"texture.h"
#include"common function.h"
SDL_Event e1;
bool stopping_time=false;

long long time_in_game=0;
long long saving_time_when_stopping_game=0;




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

     LTimer fpsTimer;
     LTimer capTimer;
     int countedFrames = 0;
     fpsTimer.start();
     	int frameTicks = capTimer.getTicks();
     	countedFrames++;
				if( frameTicks < SCREEN_TICKS_PER_FRAME )
				{
					//Wait remaining time
					SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
				}



      set_skill3_of_character2();
      set_lose_health_1();
      set_lose_health_2();
      set_value_for_menu_of_game();
      set_value_for_ingradient_of_skill2_of_character1();
      set_value_for_background_of_tutorial_menu();
      set_icon_skill_of_player();
      set_icon_pause_button();
      set_button_in_stopping_menu();

      set_value_for_skill2_of_AI(character2);

      while(!quit){
               //set fps in game
				capTimer.start();
				float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
				if( avgFPS > 2000000 )
				{
					avgFPS = 0;
				}
				countedFrames++;
				int frameTicks = capTimer.getTicks();
				if( frameTicks < SCREEN_TICKS_PER_FRAME )
				{

					SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
				}



       SDL_RenderClear(renderer);




         if(reset_everything_in_game &&!stopping_time){

            // create free function

          SCREEN_FPS = 60;
          SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;





           saving_time_when_stopping_game=0;



           reset_skill1_of_ch1(skill1_of_character1);
           reset_skill2_of_ch1(tdx_character1,tdy_character1);
           reset_skill3_of_ch1();
           reset_effect_miss();
           reset_skill1_and_moving_of_ch2();
           reset_skill2_of_AI();
           reset_skill3_of_AI(quatities_of_knifes);
           reset_moving_left_of_ch1();
           reset_moving_right_of_ch1();
           reset_ch1();
           reset_ch2();
           free_memory_about_time();
           reset_game_over();
           reset_game_win();

           reset_health_bar(tdx_of_losing_effect1,tdy_of_losing_effect1,key_active_effect_of_losing_health1,key_active_effect_of_losing_health2,
                            tdx_of_losing_effect2,tdy_of_losing_effect2);


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
             if(!stopping_time){ time_watting_change_interface=5;}
         }





        if(thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game && !stopping_time){


       /**************************************giao dien man hinh game************************************/
           while(SDL_PollEvent(&e)!=0){
                if(e.type==SDL_QUIT){
                   quit=true;
                }
                if(e.type==SDL_KEYDOWN){
                   switch(e.key.keysym.sym){
                   case SDLK_RIGHT :
                        time_run_of_character1=SDL_GetTicks();
                        saving_time_running_right_of_ch1=0;

                        right_1=true;
                        choose_right_1=true;
                        choose_left_1=false;
                        left_for_skill2_of_character1=false;
                        right_for_skill2_of_character1=true;
                        break;
                   case SDLK_LEFT :
                        time_run_of_character1=SDL_GetTicks();
                        saving_time_running_left_of_ch1=0;
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
                           saving_time_jumping_when_stopping_game1=0;
                        }
                        break;
                   case SDLK_ESCAPE :
                        quit=true;
                        break;
                   }
                }
            }


           if(!game_over && !game_win){


          SCREEN_FPS = 5000;
          SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;



           back_ground(background,height_of_screen,width_of_screen);
           set_icon_appear_and_active(time_watting_for_skill1_of_character1,
                                      time_watting_of_skill2_from_character1,
                                      time_watting_of_skill3_from_character1,
                                      time_watting_teleport,time_watting_for_skill2_of_AI);

            SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);
            skill1_of_character1.render(&skill1_of_character1_clip[skill1_of_character1_frame/30]);


           //*************************************************//
           //set character1 jump

          set_chr1_jump(can_character1_jump,tdy_character1,tdy_of_ground,set_time_in_the_air_of_character1,v_of_character1,saving_time_jumping_when_stopping_game1,stopping_time);


           //set moving right and left for character 1
           movingright(right_1,character1_frame,choose_right_1,time_run_of_character1,tdx_character1,saving_time_running_right_of_ch1);

           movingleft(left_1,character1_frame,choose_left_1,time_run_of_character1,tdx_character1,saving_time_running_left_of_ch1);




           /*************************************************************************/

           character_1(tdx_character1,tdy_character1,character1_frame,choose_right_1,choose_left_1);



           set_skill1_of_character1(tdx_skill1_of_character1,tdy_skill1_of_character1,height_of_beam,width_of_beam,tdx_beam,tdy_beam,time_watting_for_skill1_of_character1,stopping_time,
                                    skill1_of_character1,effect_for_skill1_of_character1,does_skill1_of_character1_active,skill1_of_character1_frame);


              // set skill1 of character 1 appearing and making damage on AI
        if(does_skill1_of_character1_active){
           set_skill1_of_character1_active(tdy_character2,tdx_beam,tdx_skill1_of_character1,
                                           tdy_skill1_of_character1,height_of_beam,width_of_beam,tdy_beam,
                                           time_watting_for_skill1_of_character1,did_character2_get_hit,stopping_time,
                                           skill1_of_character1,effect_for_skill1_of_character1,skill1_of_character1_frame);


           if(did_character2_get_hit && health_bar_2_of_character2>0){
              losing_health_of_ch2=1;
              set_ch2_loses_health(health_bar_2_of_character2,health_bar_2_for_character2,losing_health_of_ch2,
                                      key_active_effect_of_losing_health2,tdx_character2,tdy_character2,
                                      did_character2_get_hit,tdx_health_bar_2_of_character2,stopping_time);
           }
           else{
                did_character2_get_hit=false;
               losing_health_of_ch2=0;
               key_active_effect_of_losing_health2=false;
           }
        }


           /**************************************************************************/



           // set AI moving and hit player when he/she stands near AI
           set_AI_move(tdx_character1, tdy_character1,character2_can_not_move,right_AI,left_AI,
                       tdx_character2,tdy_character2,time_in_game,start_time,width_of_screen,character2_frame,
                       time_appearing_of_skill1_from_AI,did_character1_get_hit,saving_time_running_of_AI,stopping_time,saving_time_skill1_of_AI);


      if(tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30 && tdy_character2 == tdy_character1){

           if(did_character1_get_hit && health_bar_2_of_character1 >0){
                 losing_health_of_ch1=5;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit,stopping_time);

              }
              else{
                  losing_health_of_ch1=0;
                  key_active_effect_of_losing_health1=false;
              }



              // set AI skill1 appear
             AI_skill1((SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI+saving_time_skill1_of_AI)/200,skill1_of_AI,character1,
                       skill1_of_AI_clip,time_appearing_of_skill1_from_AI,saving_time_skill1_of_AI,time_in_game);


      }












        // set skill2 of character 1 appearing and making damage on AI


                  set_skill2_of_character1_actived(quatities_of_skill2_for_character1,tdx_for_ingradient_of_skill2_character1,
                                                   tdy_for_ingradient_of_skill2_character1,
                                                   is_ingradient_of_skill2_from_character1_actived,
                                                   time_watting_of_skill2_from_character1,
                                                   did_character2_get_hit,quatities_of_bone,stopping_time);


            for(int i=0;i<quatities_of_skill2_for_character1;i++){

                   if(did_character2_get_hit_by_skill2[i] && health_bar_2_of_character2>0){
                        losing_health_of_ch2=10;
                        set_ch2_loses_health(health_bar_2_of_character2,health_bar_2_for_character2,losing_health_of_ch2,
                                      key_active_effect_of_losing_health2,tdx_character2,tdy_character2,
                                      did_character2_get_hit_by_skill2[i],tdx_health_bar_2_of_character2,stopping_time);
                    }
                    else{
                        did_character2_get_hit_by_skill2[i]=false;
                        losing_health_of_ch2=0;
                        key_active_effect_of_losing_health2=false;
                    }


            }






        // set AI dodge and jump skill2 and skill1

              set_AI_dodge(quatities_of_bone,is_ingradient_of_skill2_from_character1_actived,
                  tdx_character2,tdx_character1,tdx_for_ingradient_of_skill2_character1,chance_to_jump_of_AI,
                  can_character2_jump,set_time_in_the_air_of_character2,tdy_character2,
                  tdy_of_ground,v_of_character2,does_skill1_of_character1_active,chance_to_teleport,time_watting_teleport,
                  character2_can_not_move,key_active_effect_miss,saving_time_jumping_when_stopping_game2,stopping_time);

             set_effect_miss(key_active_effect_miss,time_appearing_of_effect_miss,saving_time_miss_effect_of_AI);






//*************************************************************//


            //set skill 3 for character1 and cause damage on AI


            set_skill3_of_ch1_active(does_skill3_of_character1_active,time_watting_of_skill3_from_character1,
                                    tdx_character2,tdy_character2, height_of_bone,
                                    character2_can_not_move,time_appearing_of_skill3_from_character1,
                                    skill3_of_character1,did_character2_get_hit,stopping_time);
          if(does_skill3_of_character1_active){
            if(did_character2_get_hit && health_bar_2_of_character2>0){
                 losing_health_of_ch2=1;
                 set_ch2_loses_health(health_bar_2_of_character2,health_bar_2_for_character2,losing_health_of_ch2,
                                      key_active_effect_of_losing_health2,tdx_character2,tdy_character2,
                                      did_character2_get_hit,tdx_health_bar_2_of_character2,stopping_time);
              }
              else{
                  did_character2_get_hit=false;
                  key_active_effect_of_losing_health2=false;
                  losing_health_of_ch2=0;
              }
          }



         // set skill2_of_AI_actived


         set_skill2_of_AI_active(right_AI,left_AI,character1,character2,time_watting_for_skill2_of_AI,
                               is_skill2_of_character2_actived, tdx_character2, tdy_character2,
                               tdx_of_skill2_character2,tdy_of_skill2_character2,
                               left_for_skill2_of_character2,right_for_skill2_of_character2,
                               tdx_character1,tdx_character1,stopping_time);

            if(is_skill2_of_character2_actived){
             skill2_active(tdx_of_skill2_character2,tdy_of_skill2_character2,right_for_skill2_of_character2,
                           left_for_skill2_of_character2,tdx_character1,tdy_character1,did_character1_get_hit,stopping_time);
          }


             // heal_bar_of_character1_is_damaged_by_skill2_of_AI
           if(is_skill2_of_character2_actived){

             if(did_character1_get_hit && health_bar_2_of_character1 >0 ){
                 losing_health_of_ch1=50;

                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit,
                                      stopping_time);
                 is_skill2_of_character2_actived=false;
                 time_watting_for_skill2_of_AI=100;
              }
              else{
                  losing_health_of_ch1=0;
                  key_active_effect_of_losing_health1=false;
              }
           }






          // set skill3 of Ai active
          set_skill3_of_AI_active(time_in_game,did_character1_get_hit_by_skill3,tdx_character1,tdy_character1,
                                          saving_time_effect_of_skill3_of_AI,time_appearing_of_effect_of_skill3_from_AI);
          // set skill3 of AI make damage on player

          // first damage


           if(did_character1_get_hit_by_skill3[0] && health_bar_2_of_character1 >0){

                 losing_health_of_ch1=10;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit_by_skill3[0],stopping_time);

              }
              else{
                  key_active_effect_of_losing_health1=false;
              }



         //second damage

          if(did_character1_get_hit_by_skill3[1] && health_bar_2_of_character1 >0){

                 losing_health_of_ch1=5;
                 set_ch1_loses_health(health_bar_2_of_character1,health_bar_2_for_character1,losing_health_of_ch1,
                                      key_active_effect_of_losing_health1,tdx_character1,tdy_character1,did_character1_get_hit_by_skill3[1],stopping_time);


          }
          else{ key_active_effect_of_losing_health1=false;}



          //set effect miss for AI
          set_effect_miss_active(key_active_effect_miss,chance_to_teleport,time_appearing_of_effect_miss,time_watting_teleport,
                                 effect_miss_of_AI,stopping_time);

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

             set_icon_pause_button_active(tdx_of_my_mouse,tdy_of_my_mouse,quality_of_click,e1,stopping_time,time_in_game,
                                          saving_time_when_stopping_game,saving_time_running_right_of_ch1,
                                          saving_time_running_left_of_ch1,time_run_of_character1,set_time_in_the_air_of_character1,
                                          set_time_in_the_air_of_character2,saving_time_jumping_when_stopping_game1,
                                          saving_time_jumping_when_stopping_game2,start_time,saving_time_running_of_AI,
                                          saving_time_skill1_of_AI,time_appearing_of_skill1_from_AI,
                                          saving_time_effect_of_skill3_of_AI,time_appearing_of_effect_of_skill3_from_AI,
                                          saving_time_skill3_of_AI_active,quit,thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,reset_everything_in_main_interface);


           }

         else{

        /**********set game over***********************/

          SCREEN_FPS = 60;
          SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
             if(game_over){
                game_over_system();
                set_game_over_active( e,quit,thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                                    game_over,game_win,reset_everything_in_main_interface);




             }

//*************************set game win******************************************/

             if(game_win){
                set_winner_system();
                set_game_win_active( e,quit,thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                                    game_over,game_win,reset_everything_in_main_interface);

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











           free_texture(character1,character2,skill1_of_AI,background,
                    character1_face,character2_face,health_bar_1_for_character1,
                    health_bar_1_for_character2, health_bar_2_for_character1,
                    health_bar_2_for_character2, character2_skill2,
                    game_over_class, get_dunked_on, skill1_of_character1,
                    skill3_of_character1,effect_miss_of_AI);



       }

       else{






         SCREEN_FPS = 60;
          SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;



       /**************************************giao dien man hinh chinh************************************/
       //set man hinh chinh tro lai trang thai ban dau khi thoat man hinh huong dan

    if(!stopping_time){

        if(reset_everything_in_main_interface){
		   reset_everything_in_main_interface_active();

        }

        set_interface_menu_game(e,quit,does_tutorial_menu_appear);
         if(does_tutorial_menu_appear){
                    set_tutorial_menu_active();
                    reset_everything_in_main_interface=true;
         }
         else{ reset_everything_in_main_interface=false;}

       }
       else{






               // set interface when stopping time



            if(tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30 && tdy_character2 == tdy_character1){


                AI_skill1((SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI+saving_time_skill1_of_AI)/200,skill1_of_AI,character1,
                       skill1_of_AI_clip,time_appearing_of_skill1_from_AI,saving_time_skill1_of_AI,time_in_game);


            }

           set_everything_in_game_stop( character1, character2, skill1_of_AI, background,
                   character1_face, character2_face, health_bar_1_for_character1,
                   health_bar_1_for_character2, health_bar_2_for_character1,
                   health_bar_2_for_character2, character2_skill2, skill1_of_character1,
                  skill3_of_character1,choose_right_1,
                   choose_left_1, left_AI, right_AI, right_for_skill2_of_character2,
                   left_for_skill2_of_character2, is_skill2_of_character2_actived,
                   is_ingradient_of_skill3_from_character2_actived, skill3_of_character2,
                   is_effect_for_ingrident_of_skill3_of_AI_actived, effect_for_skill3_of_character2,
                   does_skill1_of_character1_active, effect_for_skill1_of_character1,
                   is_ingradient_of_skill2_from_character1_actived, skill2_of_character1,
                   does_skill3_of_character1_active,skill1_of_character1_frame,skill1_of_character1_clip);





      set_icon_appear_and_active(time_watting_for_skill1_of_character1,
                                      time_watting_of_skill2_from_character1,
                                      time_watting_of_skill3_from_character1,
                                      time_watting_teleport,time_watting_for_skill2_of_AI);




          set_icon_pause_button_active(tdx_of_my_mouse,tdy_of_my_mouse,quality_of_click,e1,stopping_time,time_in_game,
                                          saving_time_when_stopping_game,saving_time_running_right_of_ch1,
                                          saving_time_running_left_of_ch1,time_run_of_character1,set_time_in_the_air_of_character1,
                                          set_time_in_the_air_of_character2,saving_time_jumping_when_stopping_game1,
                                          saving_time_jumping_when_stopping_game2,start_time,saving_time_running_of_AI,saving_time_skill1_of_AI,time_appearing_of_skill1_from_AI,
                                          saving_time_effect_of_skill3_of_AI,time_appearing_of_effect_of_skill3_from_AI,saving_time_skill3_of_AI_active,quit,
                                          thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,reset_everything_in_main_interface);



         free_texture(character1,character2,skill1_of_AI,background,
                    character1_face,character2_face,health_bar_1_for_character1,
                    health_bar_1_for_character2, health_bar_2_for_character1,
                    health_bar_2_for_character2, character2_skill2,
                    game_over_class, get_dunked_on, skill1_of_character1,
                    skill3_of_character1,effect_miss_of_AI);










       }




       }







            SDL_RenderPresent( renderer );


      }
  }
}
  }


