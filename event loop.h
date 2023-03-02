
#ifndef event_loop
#define event_loop

#endif // event_loop
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
      while(!quit){
           while(SDL_PollEvent(&e)!=0){
                if(e.type==SDL_QUIT){
                  quit=true;
                }
                if(e.type==SDL_KEYDOWN){
                   switch(e.key.keysym.sym){
                   case SDLK_RIGHT :
                        tdx_character1=tdx_character1+5;
                        if(tdx_character1>width_of_screen){ tdx_character1=width_of_screen;}
                        right_1=true;
                        choose_right_1=true;
                        choose_left_1=false;
                        break;
                   case SDLK_LEFT :
                        tdx_character1=tdx_character1-5;
                        if(tdx_character1<0){ tdx_character1 =0;}
                        left_1=true;
                        choose_left_1=true;
                        choose_right_1=false;
                        break;
                   }
                }
            }

           SDL_RenderClear(renderer);
           back_ground();
           movingright();
           movingleft();
           if(tdx_character2-tdx_character1<0 && AI_stop_moving==0){
             right_AI=true;
             left_AI=false;
           tdx_character2=tdx_character2+(SDL_GetTicks()-start_time)/1000;
           if(tdx_character2>width_of_screen){ tdx_character2=width_of_screen;}
           character2_frame++;
           if(character2_frame/20>=2){
             character2_frame=0;
           }
        }
         if(tdx_character2-tdx_character1>0 && AI_stop_moving==0){
            left_AI=true;
            right_AI=false;
           tdx_character2=tdx_character2-(SDL_GetTicks()-start_time)/1000;
           if(tdx_character2>width_of_screen){ tdx_character2=width_of_screen;}
           character2_frame++;
           if(character2_frame/20>=2){
             character2_frame=0;
           }
         }
         if(tdx_character2-tdx_character1==0){
            right_AI=true;
            left_AI=false;
            character2_frame=0;
             AI_stop_moving=10;
             start_time=SDL_GetTicks();
         }
           character_1(tdx_character1,tdy_character1,character1_frame,choose_right_1,choose_left_1);
           AI(tdx_character2,tdx_character1,tdy_character2,tdy_character1,character2_frame,right_AI,left_AI);
           SDL_RenderPresent(renderer);
           if(AI_stop_moving!=0){
             AI_stop_moving--;
           }
           if(AI_stop_moving<0){
             AI_stop_moving=0;
           }
      }
       }
  }
}
