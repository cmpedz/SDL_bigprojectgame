#ifndef PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
#define PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
#include"texture.h"
#include"button.h"
Ltexture image_pause;
button pause_button;
Ltexture pause_system;
Ltexture heart_icon_in_pause_interface;
bool stopping_menu_active=false;

button continue_button_in_stopping_menu;
Ltexture image_of_continue_button_in_stopping_menu;
const int quatities_of_continue_button_frame_in_stopping_menu=2;
int continue_button_frame_in_stopping_menu;
SDL_Rect continue_button_sprites_in_stopping_menu[quatities_of_continue_button_frame_in_stopping_menu];

button quit_button_in_stopping_menu;
Ltexture image_of_quit_button_in_stopping_menu;
const int quatities_of_quit_button_frame_in_stopping_menu=2;
int quit_button_frame_in_stopping_menu;
SDL_Rect quit_button_sprites_in_stopping_menu[quatities_of_continue_button_frame_in_stopping_menu];

bool appearing_current_image_when_stopping_time=false;





#endif // PAUSE_AND_MUSIC_BUTTON_H_INCLUDED
void set_icon_pause_button(){
     image_pause.loadtexture("image/pause.bmp");
     image_pause.settdx(490);
     image_pause.settdy(0);
     image_pause.setheight(100);
     image_pause.setwidth(100);


     pause_button.setPosition(image_pause.gettdx(),image_pause.gettdy());



}

void set_button_in_stopping_menu(){

     heart_icon_in_pause_interface.loadtexture("image/heart_icon.bmp");
     heart_icon_in_pause_interface.settdx(0);
     heart_icon_in_pause_interface.settdy(0);
     heart_icon_in_pause_interface.setheight(71);
     heart_icon_in_pause_interface.setwidth(71);

     image_of_continue_button_in_stopping_menu.loadtexture("image/stop_interface1.bmp");
     image_of_continue_button_in_stopping_menu.settdx(360);
     image_of_continue_button_in_stopping_menu.settdy(136);
     image_of_continue_button_in_stopping_menu.setheight(136);
     image_of_continue_button_in_stopping_menu.setwidth(360);

     for(int i=0;i<quatities_of_continue_button_frame_in_stopping_menu;i++){
         continue_button_sprites_in_stopping_menu[i].x=0+(338+134)*i;
         continue_button_sprites_in_stopping_menu[i].y=0;
         continue_button_sprites_in_stopping_menu[i].w=338;
         continue_button_sprites_in_stopping_menu[i].h=127;
     }

     continue_button_in_stopping_menu.setPosition(image_of_continue_button_in_stopping_menu.gettdx(),image_of_continue_button_in_stopping_menu.gettdy());




     image_of_quit_button_in_stopping_menu.loadtexture("image/stop_interface2.bmp");
     image_of_quit_button_in_stopping_menu.settdx(image_of_continue_button_in_stopping_menu.gettdx());
     image_of_quit_button_in_stopping_menu.settdy(image_of_continue_button_in_stopping_menu.gettdy()+image_of_continue_button_in_stopping_menu.getheight()+136);
     image_of_quit_button_in_stopping_menu.setheight(136);
     image_of_quit_button_in_stopping_menu.setwidth(360);

     for(int i=0;i<quatities_of_quit_button_frame_in_stopping_menu;i++){
         quit_button_sprites_in_stopping_menu[i].x=0+(338+128)*i;
         quit_button_sprites_in_stopping_menu[i].y=0;
         quit_button_sprites_in_stopping_menu[i].w=338+4*i;
         quit_button_sprites_in_stopping_menu[i].h=134;
     }

     quit_button_in_stopping_menu.setPosition(image_of_quit_button_in_stopping_menu.gettdx(),image_of_quit_button_in_stopping_menu.gettdy());

}


void set_icon_pause_button_active(int x_mouse,int y_mouse,int &click,SDL_Event _e,bool &stopping_time,
                                  long long & time_in_game,long long &saving_time_when_stopping_game,
                                  double &saving_time_running_right_of_ch1,double &saving_time_running_left_of_ch1,
                                  double &time_run_of_character1,double &set_time_in_the_air_of_character1,
                                  double &set_time_in_the_air_of_character2,double& saving_time_jumping_when_stopping_game1,
                                  double &saving_time_jumping_when_stopping_game2,long long& start_time,
                                  long long &saving_time_running_of_AI,long long & saving_time_skill1_of_AI,
                                  int &time_appearing_of_skill1_from_AI,long long saving_time_effect_of_skill3_of_AI[],
                                  long long time_appearing_of_effect_of_skill3_from_AI[],long long saving_time_skill3_of_AI_active,
                                  bool &quit,bool &thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,bool &reset_everything_in_main_interface,
                                  long long &time_appearing_of_anti_void,long long &saving_time_appearing_of_anti_void,
                                  long long &time_appearing_of_ink_sans,long long &saving_time_appearing_of_ink_sans,
                                  long long &saving_time_appearing_bonus){

     if(!stopping_time){
        image_pause.render(NULL);




     SDL_GetMouseState(&x_mouse,&y_mouse);
     if(x_mouse>=pause_button.gettdx() && x_mouse<= pause_button.gettdx()+image_pause.getwidth()&&
        y_mouse>=pause_button.gettdy()&& y_mouse<=pause_button.gettdy()+image_pause.getheight()
        && !stopping_time){
            SDL_PollEvent(&_e);
        if(_e.type==SDL_QUIT){ quit=true;}
        if(_e.type==SDL_MOUSEBUTTONUP){

          stopping_menu_active=true;
           stopping_time=true;
           appearing_current_image_when_stopping_time=false;


          // saving main time for game
          saving_time_when_stopping_game=SDL_GetTicks()-time_in_game+saving_time_when_stopping_game;


          //saving time for player
          saving_time_jumping_when_stopping_game1=SDL_GetTicks()-set_time_in_the_air_of_character1+saving_time_jumping_when_stopping_game1;
          saving_time_running_left_of_ch1=SDL_GetTicks()-time_run_of_character1+saving_time_running_left_of_ch1;
          saving_time_running_right_of_ch1=SDL_GetTicks()-time_run_of_character1+saving_time_running_right_of_ch1;


          // saving time for AI
          saving_time_running_of_AI=SDL_GetTicks()-time_in_game-start_time+saving_time_running_of_AI;
          saving_time_skill1_of_AI=SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI+saving_time_skill1_of_AI;
          saving_time_jumping_when_stopping_game2=SDL_GetTicks()-set_time_in_the_air_of_character2+saving_time_jumping_when_stopping_game2;
          saving_time_effect_of_skill3_of_AI[0]=SDL_GetTicks()-time_appearing_of_effect_of_skill3_from_AI[0]+ saving_time_effect_of_skill3_of_AI[0];
          saving_time_effect_of_skill3_of_AI[1]=SDL_GetTicks()-time_appearing_of_effect_of_skill3_from_AI[1]+saving_time_effect_of_skill3_of_AI[1];
          saving_time_skill3_of_AI_active=SDL_GetTicks()-time_in_game+saving_time_skill3_of_AI_active;

          //saving time of anti void appearing and ink sans appearing

          saving_time_appearing_of_anti_void=SDL_GetTicks()-time_appearing_of_anti_void+saving_time_appearing_of_anti_void;
          saving_time_appearing_of_ink_sans=SDL_GetTicks()-time_appearing_of_ink_sans+saving_time_appearing_of_ink_sans;
          saving_time_appearing_bonus=SDL_GetTicks()-time_in_game+saving_time_appearing_bonus;







        }
     }
     }
     else{
      if(stopping_menu_active){

            SDL_GetMouseState(&x_mouse,&y_mouse);

             SDL_PollEvent(&_e);
            if(_e.type==SDL_QUIT){ quit=true;}

           image_of_continue_button_in_stopping_menu.render(&continue_button_sprites_in_stopping_menu[continue_button_frame_in_stopping_menu]);
           if(x_mouse>=continue_button_in_stopping_menu.gettdx() && x_mouse<= continue_button_in_stopping_menu.gettdx()+image_of_continue_button_in_stopping_menu.getwidth()&&
              y_mouse>=continue_button_in_stopping_menu.gettdy()&& y_mouse<=continue_button_in_stopping_menu.gettdy()+image_of_continue_button_in_stopping_menu.getheight()){


                if(_e.type==SDL_MOUSEBUTTONUP){
                   stopping_time=false;
                   stopping_menu_active=false;
                    time_in_game=SDL_GetTicks();
                    time_run_of_character1=SDL_GetTicks();
                    set_time_in_the_air_of_character1=SDL_GetTicks();
                    set_time_in_the_air_of_character2=SDL_GetTicks();
                    start_time=SDL_GetTicks()-time_in_game;
                    time_appearing_of_skill1_from_AI=SDL_GetTicks()-time_in_game;
                    time_appearing_of_effect_of_skill3_from_AI[1]=SDL_GetTicks();
                    time_appearing_of_effect_of_skill3_from_AI[0]=SDL_GetTicks();
                    time_appearing_of_anti_void=SDL_GetTicks();
                    time_appearing_of_ink_sans=SDL_GetTicks();

                }
                continue_button_frame_in_stopping_menu=1;
                heart_icon_in_pause_interface.settdx(continue_button_in_stopping_menu.gettdx()+10);
                heart_icon_in_pause_interface.settdy(continue_button_in_stopping_menu.gettdy()+(image_of_continue_button_in_stopping_menu.getheight()-71)/2);
                heart_icon_in_pause_interface.render(NULL);

            }
             else{
                    continue_button_frame_in_stopping_menu=0;
                }







           image_of_quit_button_in_stopping_menu.render(&quit_button_sprites_in_stopping_menu[quit_button_frame_in_stopping_menu]);
            if(x_mouse>=quit_button_in_stopping_menu.gettdx() && x_mouse<= quit_button_in_stopping_menu.gettdx()+image_of_quit_button_in_stopping_menu.getwidth()&&
              y_mouse>=quit_button_in_stopping_menu.gettdy()&& y_mouse<=quit_button_in_stopping_menu.gettdy()+image_of_quit_button_in_stopping_menu.getheight()){

                if(_e.type==SDL_MOUSEBUTTONUP){
                   stopping_menu_active=false;
                   stopping_time=false;
                   reset_everything_in_main_interface=true;
                   thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                }
                quit_button_frame_in_stopping_menu=1;
                heart_icon_in_pause_interface.settdx(quit_button_in_stopping_menu.gettdx()+10);
                heart_icon_in_pause_interface.settdy(quit_button_in_stopping_menu.gettdy()+(image_of_quit_button_in_stopping_menu.getheight()-71)/2);
                heart_icon_in_pause_interface.render(NULL);

            }
             else{
                    quit_button_frame_in_stopping_menu=0;
                }






        }
     }


}
