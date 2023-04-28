#ifndef gameover
#define gameover
#include"texture.h"
#include"button.h"
Ltexture game_over_class;

Ltexture game_over_text;
Uint8 alpha_for_game_over_text=0;

Ltexture game_over_line1;
Ltexture game_over_line2;
Ltexture game_over_line3;
Uint8 alpha_for_game_over_line=0;

TTF_Font* Font_game_over_title = NULL;
TTF_Font* Font_game_over_line = NULL;
SDL_Color game_over_color={255,255,255};

long long time_run_game_over_system=0;

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

Mix_Music *music_in_game_over=NULL;

#endif // texture
void reset_game_over(){

     game_over=false;
     button_continue_image_in_game_over.free();
    button_quit_image_in_game_over.free();
    heart_icon_in_over_interface.free();
    game_over_class.free();


}
void reset_font_in_game_over_system(){
     game_over_text.free();
     game_over_line1.free();
     game_over_line2.free();
     game_over_line3.free();

}
void set_word_for_game_over_system(){
    Font_game_over_title=TTF_OpenFont( "font/title.ttf", 100);
    Font_game_over_line=TTF_OpenFont( "font/title.ttf", 50);
    game_over_text.loadFromRenderedText("GAME OVER",game_over_color,Font_game_over_title);
    game_over_line1.loadFromRenderedText("YOU",game_over_color,Font_game_over_line);
    game_over_line2.loadFromRenderedText("CAN NOT",game_over_color,Font_game_over_line);
    game_over_line3.loadFromRenderedText("GIVE UP",game_over_color,Font_game_over_line);

    game_over_text.settdx((width_of_screen-game_over_text.getwidth())/2);
    game_over_text.settdy(50);

    game_over_line1.settdy(game_over_text.gettdy()+300);
    game_over_line2.settdy(game_over_line1.gettdy());
     game_over_line3.settdy(game_over_line1.gettdy());

     game_over_line1.settdx((width_of_screen-game_over_line1.getwidth()-game_over_line2.getwidth()-game_over_line3.getwidth())/4);

     game_over_line2.settdx((width_of_screen-game_over_line1.getwidth()-game_over_line2.getwidth()
                             -game_over_line3.getwidth())/2+game_over_line1.getwidth());

    game_over_line3.settdx((width_of_screen-game_over_line1.getwidth()-game_over_line2.getwidth()
                             -game_over_line3.getwidth())*3/4+game_over_line1.getwidth()+game_over_line2.getwidth());


}

void free_music_game_over(){

     Mix_FreeMusic( music_in_game_over );
     music_in_game_over = NULL;
}

void game_over_system(){


    music_in_game_over=Mix_LoadMUS("music/gameover.mp3");
    if( music_in_game_over == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );

	}


    //free memory


    if((SDL_GetTicks()-time_run_game_over_system)/1000>4){

    button_continue_image_in_game_over.free();
    button_quit_image_in_game_over.free();
    heart_icon_in_over_interface.free();
    game_over_class.free();






    //set quit button
     button_continue_in_game_over.setPosition(134,height_of_screen/4*3);
     button_continue_image_in_game_over.loadtexture("image/demo_continue.bmp");
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
     button_quit_image_in_game_over.loadtexture("image/demo_quit.bmp");
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

     heart_icon_in_over_interface.loadtexture("image/heart_icon.bmp");
     heart_icon_in_over_interface.settdx(0);
     heart_icon_in_over_interface.settdy(0);
     heart_icon_in_over_interface.setheight(71);
     heart_icon_in_over_interface.setwidth(71);






     game_over_class.setheight(680);
     game_over_class.setwidth(1080);
     game_over_class.loadtexture("image/it_is_just_black.bmp");
     game_over_class.settdx(0);
     game_over_class.settdy(0);
     game_over_class.render(NULL);
     button_continue_image_in_game_over.render(&button_continue_clip_in_game_over[button_continue_frame_in_game_over]);
     button_quit_image_in_game_over.render(&button_quit_clip_in_game_over[button_quit_frame_in_game_over]);
    }


   if((SDL_GetTicks()-time_run_game_over_system)/1000>=0){

    game_over_text.setBlendMode(SDL_BLENDMODE_BLEND);
     game_over_text.setAlpha(alpha_for_game_over_text);
    game_over_text.render(NULL);
     if(alpha_for_game_over_text<255){
        alpha_for_game_over_text++;
     }

   }
   if((SDL_GetTicks()-time_run_game_over_system)/1000>2 ){

     game_over_line1.setBlendMode(SDL_BLENDMODE_BLEND);
     game_over_line1.setAlpha(alpha_for_game_over_line);
     game_over_line2.setBlendMode(SDL_BLENDMODE_BLEND);
     game_over_line2.setAlpha(alpha_for_game_over_line);
     game_over_line3.setBlendMode(SDL_BLENDMODE_BLEND);
     game_over_line3.setAlpha(alpha_for_game_over_line);

    game_over_line1.render(NULL);
    game_over_line2.render(NULL);
    game_over_line3.render(NULL);

     if(alpha_for_game_over_line<255){
        alpha_for_game_over_line=alpha_for_game_over_line+3;
     }
   }




}

void set_game_over_active(SDL_Event e,bool& quit,bool&thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                          bool &game_over,bool &game_win,bool &reset_everything_in_main_interface,bool &does_music_in_menu_game_appear){

          if((SDL_GetTicks()-time_run_game_over_system)/1000>4){

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

                                 if(Mix_Playing(3)==0){
                                    Mix_PlayChannel( 3, music_select, 0 );
                                }
                                thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                                reset_everything_in_main_interface=true;
                                Mix_HaltMusic();
                                does_music_in_menu_game_appear=true;
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
                                 if(Mix_Playing(3)==0){
                                    Mix_PlayChannel( 3, music_select, 0 );
                                }
                                reset_everything_in_game=true;
                                Mix_HaltMusic();
                                break;


                                }



                        }



                }




             }

          }

}
