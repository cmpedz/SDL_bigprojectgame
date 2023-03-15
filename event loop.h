
#ifndef event_loop
#define event_loop

#endif // event_loop
#define RIGHT 1
#define LEFT 2
void eventloop(){

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
      set_value_for_ingradient_of_skill2_of_character1();
      set_effect_miss();
      while(!quit){
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

                          for(int i=0;i<quatities_of_skill2_for_character1;i++){
                              is_ingradient_of_skill2_from_character1_actived[i]=true;
                          }
                          if(quatities_of_skill2_for_character1>=4){
                             quatities_of_skill2_for_character1=3;
                          }
                          reset_tdx_and_tdy_of_skill2_from_character1=false;
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

           SDL_RenderClear(renderer);
           if(!game_over && !game_win){

           back_ground();
           movingright();
           movingleft();
           //*************************************************//
           //set character1 jump
           if(can_character1_jump){
              tdy_character1=tdy_character1-set_gravity(v_of_character1,set_time_in_the_air_of_character1);
                if(tdy_character1>=tdy_of_ground){
                  tdy_character1=tdy_of_ground;
                  can_character1_jump=false;
                }
                for(int i=0;i<quatities_of_bone;i++){
                    if(!is_ingradient_of_skill2_from_character1_actived[i]){
                       tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
                       tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
                    }
                }
           }


           //set moving right for character 1

            if(choose_right_1 && (SDL_GetTicks()-time_run_of_character1)/1000<=1){ // SDL_GetTicks()-time_run_of_character1)/1000<=1 day la dk để di chuyển theo thời gian :))
              tdx_character1=tdx_character1+3;
              if(tdx_character1>=1000){
                 tdx_character1=1000;
              }
            }
            //set moving left for character1
            if(choose_left_1 && (SDL_GetTicks()-time_run_of_character1)/1000<=1){
              tdx_character1=tdx_character1-3;
              if(tdx_character1<0){
                 tdx_character1=0;
              }
            }



           /*************************************************************************/
           //
           character_1(tdx_character1,tdy_character1,character1_frame,choose_right_1,choose_left_1);
           set_skill1_of_character1(tdx_skill1_of_character1,tdy_skill1_of_character1,height_of_beam,width_of_beam,tdx_beam,tdy_beam);
           /**************************************************************************/
           //
           if(tdx_character2-tdx_character1<-30 && !character2_can_not_move){
             right_AI=true;
             left_AI=false;
           tdx_character2=tdx_character2+(SDL_GetTicks()-start_time)/1000;
           if((SDL_GetTicks()-start_time)/1000>1){ start_time=SDL_GetTicks();}
           if(tdx_character2>width_of_screen){ tdx_character2=width_of_screen;}
           character2_frame++;
           if(character2_frame/20>=2){
             character2_frame=0;
           }
        }
         if(tdx_character2-tdx_character1>30 && !character2_can_not_move){
            left_AI=true;
            right_AI=false;
           tdx_character2=tdx_character2-(SDL_GetTicks()-start_time)/1000;
           if((SDL_GetTicks()-start_time)/1000>5){ start_time=SDL_GetTicks();}
           if(tdx_character2>width_of_screen){ tdx_character2=width_of_screen;}
           character2_frame++;
           if(character2_frame/20>=2){
             character2_frame=0;
           }
         }

         //****************************************//
           if(tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30 && tdy_character2 == tdy_character1){
              //
              if(tdx_character2-tdx_character1<0){
                right_AI=true;
                left_AI=false;
              }
           //
              if(tdx_character2-tdx_character1>0){
                right_AI=false;
                left_AI=true;
              }
            character2_frame=0;
            // health_bar_of_character1 is decreased when AI attack directly
             if((SDL_GetTicks()-time_appearing_of_skill1_from_AI)/200>=1){
                did_character1_get_hit=true;
              }
              if(did_character1_get_hit && health_bar_2_of_character1 >0){
                 health_bar_2_of_character1=health_bar_2_of_character1-5;
                 health_bar_2_for_character1.settdx(health_bar_1_for_character1.gettdx()-5);
                 key_active_effect_of_losing_health1=true;
                 set_lose_health_1_appear(tdx_character1,tdy_character1);
                 did_character1_get_hit=false;
              }
              else{
                  key_active_effect_of_losing_health1=false;
              }
              //
             if((SDL_GetTicks()-time_appearing_of_skill1_from_AI)/200>=7){
                  time_appearing_of_skill1_from_AI=SDL_GetTicks();
             }
              //
             AI_skill1((SDL_GetTicks()-time_appearing_of_skill1_from_AI)/200);
             skill1_of_AI.render(&skill1_of_AI_clip[(SDL_GetTicks()-time_appearing_of_skill1_from_AI)/200]);
             start_time=SDL_GetTicks();
         }
         /****************************************************************/



        // set skill1 of character 1 appearing and making damage on AI
        if(does_skill1_of_character1_active){ set_skill1_of_character1_active(tdy_character2,tdx_beam,tdx_skill1_of_character1,tdy_skill1_of_character1,height_of_beam,width_of_beam,tdy_beam,time_watting_for_skill1_of_character1);}
           if(tdx_character2<=tdx_beam+20 && tdx_character2>=tdx_beam-20 && tdy_character2>=tdy_beam){
              did_character2_get_hit=true;
           }
           else{did_character2_get_hit=false;}
           if(did_character2_get_hit){
              health_bar_2_of_character2=health_bar_2_of_character2-1;
              tdx_health_bar_2_of_character2=tdx_health_bar_2_of_character2+1;
              key_active_effect_of_losing_health2=true;
              set_lose_health_2_appear(tdx_character2,tdy_character2);
              if(health_bar_2_of_character2<0){ health_bar_2_of_character2=0; }
           }
           else{
               key_active_effect_of_losing_health2=false;
           }


       //AI dodges skill1_of_player
       if(does_skill1_of_character1_active && chance_to_teleport!=0 && !character2_can_not_move){
             if(tdx_character1-tdx_character2<0){
                tdx_character2=tdx_character2-50;
                if(tdx_character2<0){ tdx_character2=0;}
             }

             if(tdx_character1-tdx_character2>0){
                tdx_character2=tdx_character2+50;
                if(tdx_character2>1000){ tdx_character2=1000;}
            }
            key_active_effect_miss=true;
            chance_to_teleport=0;
        }




        // set skill2 of character 1 appearing and making damage on AI

              for(int i=0;i<quatities_of_skill2_for_character1;i++){
                  set_skill2_of_character1_actived(quatities_of_skill2_for_character1,tdx_for_ingradient_of_skill2_character1,tdy_for_ingradient_of_skill2_character1,is_ingradient_of_skill2_from_character1_actived,time_watting_of_skill2_from_character1);
                  if(left_for_skill2_of_character1 && vector_for_ingradient_of_character1[i]==0 && is_ingradient_of_skill2_from_character1_actived[i]){
                     vector_for_ingradient_of_character1[i]=LEFT;
                  }
                   if(right_for_skill2_of_character1 && vector_for_ingradient_of_character1[i]==0 && is_ingradient_of_skill2_from_character1_actived[i]){
                     vector_for_ingradient_of_character1[i]=RIGHT;
                   }
                    if(vector_for_ingradient_of_character1[i]==1){ tdx_for_ingradient_of_skill2_character1[i]=tdx_for_ingradient_of_skill2_character1[i]+10;}
                    if(vector_for_ingradient_of_character1[i]==2){ tdx_for_ingradient_of_skill2_character1[i]=tdx_for_ingradient_of_skill2_character1[i]-10;}

                   if(tdx_for_ingradient_of_skill2_character1[i]>=tdx_character2-5 &&
                     tdx_for_ingradient_of_skill2_character1[i]<=tdx_character2+5 &&
                     tdy_for_ingradient_of_skill2_character1[i]+2>=tdy_character2 &&
                     tdy_for_ingradient_of_skill2_character1[i]-2<=tdy_character2){
                     did_character2_get_hit=true;
                  }
                  else{
                      did_character2_get_hit=false;
                  }
                   if(did_character2_get_hit){
                      health_bar_2_of_character2=health_bar_2_of_character2-5;
                      tdx_health_bar_2_of_character2=tdx_health_bar_2_of_character2+5;
                      key_active_effect_of_losing_health2=true;
                      set_lose_health_2_appear(tdx_character2,tdy_character2);
                       if(health_bar_2_of_character2<0){ health_bar_2_of_character2=0; }
                   }
                   else{
                       key_active_effect_of_losing_health2=false;
                   }

              }

//**********************set AI jump****************************//

    // AI follow player

    if(tdy_character1<tdy_character2 && tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30){
                        if(chance_to_jump_of_AI==0){
                            can_character2_jump=true;
                            set_time_in_the_air_of_character2=SDL_GetTicks();
                            chance_to_jump_of_AI=100;
                          }
    }


    // AI dodges skill2
                for(int i=0;i<quatities_of_bone;i++){
                  if(is_ingradient_of_skill2_from_character1_actived[i]){
                    if(abs(tdx_character2<=tdx_for_ingradient_of_skill2_character1[i])<10 ){
                          if(chance_to_jump_of_AI==0){
                            can_character2_jump=true;
                            set_time_in_the_air_of_character2=SDL_GetTicks();
                            chance_to_jump_of_AI=100;
                          }
                    }

                  }
                }

                if(tdy_character2<tdy_of_ground || can_character2_jump){
                        tdy_character2=tdy_character2-set_gravity(v_of_character2,set_time_in_the_air_of_character2);
                        if(tdy_character2>tdy_of_ground){
                            tdy_character2=tdy_of_ground;
                            can_character2_jump=false;
                         }
                 }

                if(chance_to_jump_of_AI!=0){
                   chance_to_jump_of_AI--;
                }



//*************************************************************//


            //set skill 3 for character1 and cause damage on AI
            if(does_skill3_of_character1_active){
                 time_watting_of_skill3_from_character1=200;
                 set_skill3_of_character1(tdx_character2,time_appearing_of_skill3_from_character1,height_of_bone);
                 character2_can_not_move=true;
                 if(time_appearing_of_skill3_from_character1==0){
                    does_skill3_of_character1_active=false;
                    time_appearing_of_skill3_from_character1=50;
                 }
                 if(tdx_character2>=skill3_of_character1.gettdx() && skill3_of_character1.gettdx()+150>=tdx_character2 && skill3_of_character1.gettdy()-tdy_character2<=0){
                 did_character2_get_hit=true;
              }
              else{
                  did_character2_get_hit=false;
              }
              if(did_character2_get_hit){
                 health_bar_2_of_character2=health_bar_2_of_character2-1;
                 tdx_health_bar_2_of_character2=tdx_health_bar_2_of_character2+1;
                 key_active_effect_of_losing_health2=true;
                 set_lose_health_2_appear(tdx_character2,tdy_character2);
                 if(health_bar_2_of_character2<0){ health_bar_2_of_character2=0; }
              }
              else{
                  key_active_effect_of_losing_health2=false;
              }
            }
              else{
                  character2_can_not_move=false;
              }

         // set skill2_of_AI_actived
          if(abs(character2.gettdx()-character1.gettdx()) >=100 && abs(character2.gettdx()-character1.gettdx())<=400 && time_watting_for_skill2_of_AI ==0)
          {
             is_skill2_of_character2_actived=true;

          }
          if(is_skill2_of_character2_actived){
             skill2_active(tdx_of_skill2_character2,tdy_of_skill2_character2,right_AI,left_AI);
             if(left_AI){
                tdx_of_skill2_character2=tdx_of_skill2_character2-20;
             }
             if(right_AI){tdx_of_skill2_character2=tdx_of_skill2_character2+20;}



             // heal_bar_of_character1_is_damaged_by_skill2_of_AI
            if(tdx_of_skill2_character2>=tdx_character1-10 && tdx_of_skill2_character2<=tdx_character1+10){
             did_character1_get_hit=true;
             if(did_character1_get_hit && health_bar_2_of_character1 >0 && tdy_of_skill2_character2-5<=tdy_character1 && tdy_of_skill2_character2+5>=tdy_character1){
                 health_bar_2_of_character1=health_bar_2_of_character1-50;
                 health_bar_2_for_character1.settdx(health_bar_1_for_character1.gettdx()-50);
                 key_active_effect_of_losing_health1=true;
                 set_lose_health_1_appear(tdx_character1,tdy_character1);
                 did_character1_get_hit=false;
                 time_watting_for_skill2_of_AI=100;
              }
              else{
                key_active_effect_of_losing_health1=false;
              }
          }
          }


          // set skill3 of Ai active
          set_skill3_of_character2_active();
          // set skill3 of AI make damage on player

          // first damage
          if((tdx_for_ingradient_of_skill3_character2[0]+5>=tdx_character1 &&
             tdx_for_ingradient_of_skill3_character2[0]-5<=tdx_character1 &&
             tdy_for_ingradient_of_skill3_character2[0]+5 >= tdy_character1 &&
             tdy_for_ingradient_of_skill3_character2[0]-5 <= tdy_character1)||

             (tdx_for_ingradient_of_skill3_character2[1]+5>=tdx_character1 &&
             tdx_for_ingradient_of_skill3_character2[1]-5<=tdx_character1 &&
             tdy_for_ingradient_of_skill3_character2[1]+5 >= tdy_character1 &&
             tdy_for_ingradient_of_skill3_character2[1]-5 <= tdy_character1)){
             did_character1_get_hit=true;
          }
          else{ did_character1_get_hit=false; }
           if(did_character1_get_hit && health_bar_2_of_character1 >0){
                 health_bar_2_of_character1=health_bar_2_of_character1-10;
                 health_bar_2_for_character1.settdx(health_bar_1_for_character1.gettdx()-10);
                 key_active_effect_of_losing_health1=true;
                 set_lose_health_1_appear(tdx_character1,tdy_character1);
                 did_character1_get_hit=false;
              }
              else{
                  key_active_effect_of_losing_health1=false;
              }
          //second damage
          if((is_effect_for_ingrident_of_skill3_of_AI_actived[0] &&
             tdy_character1 <= tdy_for_ingradient_of_skill3_character2[0]+2 &&
             tdy_character1 >= tdy_for_ingradient_of_skill3_character2[0]-2) ||
             (is_effect_for_ingrident_of_skill3_of_AI_actived[1] &&
             tdx_character1 <= tdx_of_effect_of_skill3_of_AI_copy+5 &&
             tdx_character1 >= tdx_of_effect_of_skill3_of_AI_copy-5 )){
             did_character1_get_hit=true;
          }
          else{
              did_character1_get_hit=false;
          }


          if(did_character1_get_hit && health_bar_2_of_character1 >0){
                 health_bar_2_of_character1=health_bar_2_of_character1-5;
                 health_bar_2_for_character1.settdx(health_bar_1_for_character1.gettdx()-5);
                 key_active_effect_of_losing_health1=true;
                 set_lose_health_1_appear(tdx_character1,tdy_character1);
                 did_character1_get_hit=false;

          }
          else{ key_active_effect_of_losing_health1=false;}


          //set effect miss for AI
          set_effect_miss_active();

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
           }



    }
         else{
             if(game_over){
                game_over_system();
             }
             if(game_win){
                set_winner_system();
             }
         }
         SDL_RenderPresent(renderer);
           time_watting_for_skill2_of_AI--;
           if(time_watting_for_skill2_of_AI<0){
              time_watting_for_skill2_of_AI=0;
           }
           //
           if(character2_skill2.gettdx()<=0 || character2_skill2.gettdx()>=1080 ){
             is_skill2_of_character2_actived=false;
             tdx_of_skill2_character2=tdx_character2;
             tdy_of_skill2_character2=tdy_character2;
           }
           // set time watting for skill2 of character1
            if(time_watting_of_skill2_from_character1!=0){
              time_watting_of_skill2_from_character1--;
              for(int i=0;i<quatities_of_bone;i++){
                     tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
              }
              quatities_of_skill2_for_character1=0;
           }
           // set tdx and tdy again for skill2 of character 1
           if(reset_tdx_and_tdy_of_skill2_from_character1){
              for(int i=0;i<quatities_of_bone;i++){
                  tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
              }
           }
           if(time_watting_of_skill3_from_character1>0){
              time_watting_of_skill3_from_character1--;
           }
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
  }
}
}

