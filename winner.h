#ifndef winner
#define winner
#include"texture.h"
Ltexture get_dunked_on;
bool game_win=false;

const int height_of_button_quit_and_continue_in_game_win=137;
const int width_of_button_quit_and_continue_in_game_win=338;

button button_quit_in_game_win;
Ltexture button_quit_image_in_game_win;
const int quality_of_button_quit_in_game_win=2;
int button_quit_frame_in_game_win=0;
SDL_Rect button_quit_clip_in_game_win[quality_of_button_quit_in_game_win];
bool inside_button_quit_in_the_game_win=false;


button button_continue_in_game_win;
Ltexture button_continue_image_in_game_win;
const int quality_of_button_continue_in_game_win=2;
int button_continue_frame_in_game_win=0;
SDL_Rect button_continue_clip_in_game_win[quality_of_button_continue_in_game_win];
bool inside_button_continue_in_the_game_win=false;

Ltexture heart_icon_in_win_interface;

#endif // texture
void reset_game_win(){
    button_continue_image_in_game_win.free();
    button_quit_image_in_game_win.free();
    heart_icon_in_win_interface.free();
    get_dunked_on.free();


}

void set_winner_system(){


    button_continue_image_in_game_win.free();
    button_quit_image_in_game_win.free();
    heart_icon_in_win_interface.free();
    get_dunked_on.free();



     get_dunked_on.setheight(680);
     get_dunked_on.setwidth(1080);
     get_dunked_on.settdx(0);
     get_dunked_on.settdy(0);
     get_dunked_on.loadtexture("get dunked on.bmp");


     button_continue_in_game_win.setPosition(134,height_of_screen/4*3);
     button_continue_image_in_game_win.loadtexture("demo_continue.bmp");
     button_continue_image_in_game_win.settdx(button_continue_in_game_win.gettdx());
     button_continue_image_in_game_win.settdy(button_continue_in_game_win.gettdy());
     button_continue_image_in_game_win.setheight(height_of_button_quit_and_continue_in_game_win);
     button_continue_image_in_game_win.setwidth(width_of_button_quit_and_continue_in_game_win);


    for(int i=0;i<quality_of_button_continue_in_game_win;i++){
         button_continue_clip_in_game_win[i].h=127;
         button_continue_clip_in_game_win[i].w=338;
         button_continue_clip_in_game_win[i].y=0;
         button_continue_clip_in_game_win[i].x=0+(338+134)*i;
     }





     //set continue button
     button_quit_in_game_win.setPosition(134+width_of_button_quit_and_continue_in_game_win+button_continue_in_game_win.gettdx(),button_continue_in_game_win.gettdy());
     button_quit_image_in_game_win.loadtexture("demo_quit.bmp");
     button_quit_image_in_game_win.settdx(button_quit_in_game_win.gettdx());
     button_quit_image_in_game_win.settdy(button_quit_in_game_win.gettdy());
     button_quit_image_in_game_win.setheight(height_of_button_quit_and_continue_in_game_win);
     button_quit_image_in_game_win.setwidth(width_of_button_quit_and_continue_in_game_win);

     for(int i=0;i<quality_of_button_quit_in_game_win;i++){
         button_quit_clip_in_game_win[i].h=134;
         button_quit_clip_in_game_win[i].w=338+4*i;
         button_quit_clip_in_game_win[i].y=0;
         button_quit_clip_in_game_win[i].x=0+(338+128)*i;
     }

     get_dunked_on.render(NULL);
     button_continue_image_in_game_win.render(&button_continue_clip_in_game_win[button_continue_frame_in_game_win]);
     button_quit_image_in_game_win.render(&button_quit_clip_in_game_win[button_quit_frame_in_game_win]);


     heart_icon_in_win_interface.loadtexture("heart_icon.bmp");
     heart_icon_in_win_interface.settdx(0);
     heart_icon_in_win_interface.settdy(0);
     heart_icon_in_win_interface.setheight(71);
     heart_icon_in_win_interface.setwidth(71);


}

void set_game_win_active(SDL_Event e,bool& quit,bool&thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                          bool &game_over,bool &game_win,bool &reset_everything_in_main_interface){


                     if(tdx_of_my_mouse>=button_quit_in_game_win.gettdx() &&
                           button_quit_in_game_win.gettdx()+width_of_button_quit_and_continue_in_game_win>=tdx_of_my_mouse &&
                           button_quit_in_game_win.gettdy()<=tdy_of_my_mouse &&
                           button_quit_in_game_win.gettdy()+height_of_button_quit_and_continue_in_game_win>=tdy_of_my_mouse){

                             button_quit_frame_in_game_win=1;
                                heart_icon_in_win_interface.settdx(button_quit_in_game_win.gettdx()+10);
                                heart_icon_in_win_interface.settdy(button_quit_in_game_win.gettdy()+(button_quit_image_in_game_win.getheight()-heart_icon_in_win_interface.getheight())/2);


                                heart_icon_in_win_interface.render(NULL);
                           }

                            else{
                            button_quit_frame_in_game_win=0;
                        }





                           if(tdx_of_my_mouse>=button_continue_in_game_win.gettdx() &&
                           button_continue_in_game_win.gettdx()+width_of_button_quit_and_continue_in_game_win>=tdx_of_my_mouse &&
                           button_continue_in_game_win.gettdy()<=tdy_of_my_mouse &&
                           button_continue_in_game_win.gettdy()+height_of_button_quit_and_continue_in_game_win>=tdy_of_my_mouse){

                                button_continue_frame_in_game_win=1;
                                heart_icon_in_win_interface.settdx(button_continue_in_game_win.gettdx()+10);
                                heart_icon_in_win_interface.settdy(button_continue_in_game_win.gettdy()+(button_continue_image_in_game_win.getheight()-heart_icon_in_win_interface.getheight())/2);

                                heart_icon_in_win_interface.render(NULL);}
                        else{
                            button_continue_frame_in_game_win=0;
                        }







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

                                case SDL_MOUSEBUTTONUP :
                                thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                                reset_everything_in_main_interface=true;
                                 game_over=false;
                                 game_win=false;
                                break;


                                }




                        }





                        if( inside_button_continue_in_the_game_win )
                        {

                               switch( e.type )
                                {

                                case SDL_MOUSEBUTTONUP :
                                reset_everything_in_game=true;
                                break;


                                }




                        }

             }
         }




}
