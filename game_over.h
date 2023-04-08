#ifndef gameover
#define gameover
#include"texture.h"
#include"button.h"
Ltexture game_over_class;

bool game_over=false;
const int height_of_button_quit_and_continue_in_game_over=127;
const int width_of_button_quit_and_continue_in_game_over=338;

button button_quit_in_game_over;
Ltexture button_quit_image_in_game_over;
const int quality_of_button_quit_in_game_over=2;
int button_quit_frame_in_game_over=0;
SDL_Rect button_quit_clip_in_game_over[quality_of_button_quit_in_game_over];
bool inside_button_quit_in_the_game_over=false;


button button_continue_in_game_over;
Ltexture button_continue_image_in_game_over;
const int quality_of_button_continue_in_game_over=2;
int button_continue_frame_in_game_over=0;
SDL_Rect button_continue_clip_in_game_over[quality_of_button_continue_in_game_over];
bool inside_button_continue_in_the_game_over=false;

Ltexture heart_icon_in_over_interface;

#endif // texture
void reset_game_over(){

     game_over=false;
     button_continue_image_in_game_over.free();
    button_quit_image_in_game_over.free();
    heart_icon_in_over_interface.free();
    game_over_class.free();


}
void game_over_system(){
    //free memory
    button_continue_image_in_game_over.free();
    button_quit_image_in_game_over.free();
    heart_icon_in_over_interface.free();
    game_over_class.free();


    //set quit button
     button_continue_in_game_over.setPosition(134,height_of_screen/4*3);
     button_continue_image_in_game_over.loadtexture("demo_continue.bmp");
     button_continue_image_in_game_over.settdx(button_continue_in_game_over.gettdx());
     button_continue_image_in_game_over.settdy(button_continue_in_game_over.gettdy());
     button_continue_image_in_game_over.setheight(height_of_button_quit_and_continue_in_game_over);
     button_continue_image_in_game_over.setwidth(width_of_button_quit_and_continue_in_game_over);


    for(int i=0;i<quality_of_button_continue_in_game_over;i++){
         button_continue_clip_in_game_over[i].h=127;
         button_continue_clip_in_game_over[i].w=338;
         button_continue_clip_in_game_over[i].y=0;
         button_continue_clip_in_game_over[i].x=0+(338+134)*i;
     }





     //set continue button
     button_quit_in_game_over.setPosition(134+width_of_button_quit_and_continue_in_game_over+button_continue_in_game_over.gettdx(),button_continue_in_game_over.gettdy());
     button_quit_image_in_game_over.loadtexture("demo_quit.bmp");
     button_quit_image_in_game_over.settdx(button_quit_in_game_over.gettdx());
     button_quit_image_in_game_over.settdy(button_quit_in_game_over.gettdy());
     button_quit_image_in_game_over.setheight(height_of_button_quit_and_continue_in_game_over);
     button_quit_image_in_game_over.setwidth(width_of_button_quit_and_continue_in_game_over);

     for(int i=0;i<quality_of_button_quit_in_game_over;i++){
         button_quit_clip_in_game_over[i].h=134;
         button_quit_clip_in_game_over[i].w=338+4*i;
         button_quit_clip_in_game_over[i].y=0;
         button_quit_clip_in_game_over[i].x=0+(338+128)*i;
     }

     heart_icon_in_over_interface.loadtexture("heart_icon.bmp");
     heart_icon_in_over_interface.settdx(0);
     heart_icon_in_over_interface.settdy(0);
     heart_icon_in_over_interface.setheight(71);
     heart_icon_in_over_interface.setwidth(71);






     game_over_class.setheight(680);
     game_over_class.setwidth(1080);
     game_over_class.loadtexture("gameover.bmp");
     game_over_class.settdx(0);
     game_over_class.settdy(0);
     game_over_class.render(NULL);
     button_continue_image_in_game_over.render(&button_continue_clip_in_game_over[button_continue_frame_in_game_over]);
     button_quit_image_in_game_over.render(&button_quit_clip_in_game_over[button_quit_frame_in_game_over]);



}

void set_game_over_active(SDL_Event e,bool& quit,bool&thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                          bool &game_over,bool &game_win,bool &reset_everything_in_main_interface){


                 if(tdx_of_my_mouse>=button_quit_in_game_over.gettdx() && button_quit_in_game_over.gettdx()+width_of_button_quit_and_continue_in_game_over>=tdx_of_my_mouse &&
                           button_quit_in_game_over.gettdy()<=tdy_of_my_mouse && button_quit_in_game_over.gettdy()+height_of_button_quit_and_continue_in_game_over>=tdy_of_my_mouse){



                                button_quit_frame_in_game_over=1;
                                heart_icon_in_over_interface.settdx(button_quit_in_game_over.gettdx()+10);
                                heart_icon_in_over_interface.settdy(button_quit_in_game_over.gettdy()+(button_quit_image_in_game_over.getheight()-heart_icon_in_over_interface.getheight())/2);
                                heart_icon_in_over_interface.render(NULL);

                }
                else{
                    button_quit_frame_in_game_over=0;
                }



                        if(tdx_of_my_mouse>=button_continue_in_game_over.gettdx() && button_continue_in_game_over.gettdx()+width_of_button_quit_and_continue_in_game_over>=tdx_of_my_mouse &&
                           button_continue_in_game_over.gettdy()<=tdy_of_my_mouse && button_continue_in_game_over.gettdy()+height_of_button_quit_and_continue_in_game_over>=tdy_of_my_mouse){


                              button_continue_frame_in_game_over=1;
                                heart_icon_in_over_interface.settdx(button_continue_in_game_over.gettdx()+10);
                                heart_icon_in_over_interface.settdy(button_continue_in_game_over.gettdy()+(button_continue_image_in_game_over.getheight()-heart_icon_in_over_interface.getheight())/2);

                                 heart_icon_in_over_interface.render(NULL);
                        }
                        else{
                             button_continue_frame_in_game_over=0;
                        }


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

                                case SDL_MOUSEBUTTONUP :
                                thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                                reset_everything_in_main_interface=true;
                                 game_over=false;
                                 game_win=false;
                                break;


                                }


                        }




                        if( inside_button_continue_in_the_game_over )
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
