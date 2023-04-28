#ifndef winner
#define winner
#include"texture.h"
Ltexture get_dunked_on;
bool game_win=false;

int symbol_for_winning_frame=0;
int time_loop_activity_of_symbol_for_winning=0;
const int symbol_for_winning_quatities=20;
Ltexture symbol_for_winning;
SDL_Rect symbol_for_winning_clip[symbol_for_winning_quatities];

Ltexture game_win_text;
Uint8 alpha_for_game_win_text=0;

Ltexture game_win_line1;
Ltexture game_win_line2;
const int quatity_of_word_N=10;
int count_of_word_N=0;
Ltexture game_win_line3[quatity_of_word_N];
Uint8 alpha_for_game_win_line=0;

TTF_Font* Font_game_win_title = NULL;
TTF_Font* Font_game_win_line = NULL;
SDL_Color game_win_color={0,0,0};

long long time_run_game_win_system=0;



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

Mix_Music *music_in_game_win=NULL;

#endif // texture
void reset_game_win(){
    button_continue_image_in_game_win.free();
    button_quit_image_in_game_win.free();
    heart_icon_in_win_interface.free();
    get_dunked_on.free();


}







void set_word_for_game_win_system(){
    Font_game_win_title=TTF_OpenFont( "font/title.ttf", 100);
    Font_game_win_line=TTF_OpenFont( "font/title.ttf", 50);
    game_win_text.loadFromRenderedText("WIN",game_win_color,Font_game_win_title);
    game_win_line1.loadFromRenderedText("GET",game_win_color,Font_game_win_line);
    game_win_line2.loadFromRenderedText("DUNK ON",game_win_color,Font_game_win_line);



    game_win_text.settdx((width_of_screen-game_win_text.getwidth())/2);
    game_win_text.settdy(50);

    game_win_line1.settdy(game_win_text.gettdy()+150);
    game_win_line2.settdy(game_win_line1.gettdy()+50);

     game_win_line1.settdx(200);

     game_win_line2.settdx(game_win_line1.gettdx());


     for(int i=0;i<quatity_of_word_N;i++){
        game_win_line3[i].loadFromRenderedText("N",game_win_color,Font_game_win_line);
        game_win_line3[i].settdy(game_win_line2.gettdy());
        game_win_line3[i].settdx(game_win_line2.gettdx()+game_win_line2.getwidth());
    }


}







void free_music_game_win(){

     Mix_FreeMusic( music_in_game_win );
     music_in_game_win = NULL;
}


void set_winner_system(){



     music_in_game_win=Mix_LoadMUS("music/gamewin.mp3");
    if( music_in_game_win == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );

	}


    button_continue_image_in_game_win.free();
    button_quit_image_in_game_win.free();
    heart_icon_in_win_interface.free();
    get_dunked_on.free();



     get_dunked_on.setheight(680);
     get_dunked_on.setwidth(1080);
     get_dunked_on.settdx(0);
     get_dunked_on.settdy(0);
     get_dunked_on.loadtexture("image/get dunked on.bmp");


     button_continue_in_game_win.setPosition(134,height_of_screen/4*3);
     button_continue_image_in_game_win.loadtexture("image/demo_continue.bmp");
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
     button_quit_image_in_game_win.loadtexture("image/demo_quit.bmp");
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
  if((SDL_GetTicks()-time_run_game_win_system)/1000>4){

     button_continue_image_in_game_win.render(&button_continue_clip_in_game_win[button_continue_frame_in_game_win]);
     button_quit_image_in_game_win.render(&button_quit_clip_in_game_win[button_quit_frame_in_game_win]);


     heart_icon_in_win_interface.loadtexture("image/heart_icon.bmp");
     heart_icon_in_win_interface.settdx(0);
     heart_icon_in_win_interface.settdy(0);
     heart_icon_in_win_interface.setheight(71);
     heart_icon_in_win_interface.setwidth(71);

     symbol_for_winning.render(&symbol_for_winning_clip[symbol_for_winning_frame/5]);
     symbol_for_winning_frame++;
     if(symbol_for_winning_frame>=100 && time_loop_activity_of_symbol_for_winning<50){
        symbol_for_winning_frame=99;
        time_loop_activity_of_symbol_for_winning++;
     }
     if(time_loop_activity_of_symbol_for_winning>=50){
        time_loop_activity_of_symbol_for_winning=0;
        symbol_for_winning_frame=0;
     }


    }





      game_win_text.setBlendMode(SDL_BLENDMODE_BLEND);
     game_win_text.setAlpha(alpha_for_game_win_text);

       game_win_text.render(NULL);

     if(alpha_for_game_win_text<250){
        alpha_for_game_win_text=alpha_for_game_win_text+2;
     }


   if((SDL_GetTicks()-time_run_game_win_system)/1000>2){

    game_win_line1.setBlendMode(SDL_BLENDMODE_BLEND);
     game_win_line1.setAlpha(alpha_for_game_win_line);
     game_win_line2.setBlendMode(SDL_BLENDMODE_BLEND);
     game_win_line2.setAlpha(alpha_for_game_win_line);



     game_win_line1.render(NULL);
     game_win_line2.render(NULL);




     if(alpha_for_game_win_line<250){
        alpha_for_game_win_line=alpha_for_game_win_line+3;
     }
   }

    if((SDL_GetTicks()-time_run_game_win_system)/1000>3){
        for(int i=0;i<count_of_word_N/10;i++){

            game_win_line3[i].render(NULL);
             game_win_line3[i].settdy(game_win_line2.gettdy());
            game_win_line3[i].settdx(game_win_line2.gettdx()+game_win_line2.getwidth()+i*5+game_win_line3[0].getwidth()*i);

        }
       count_of_word_N++;
       if(count_of_word_N>=100){
          count_of_word_N=99;
       }
    }




}


void set_symbol_winning(){

     symbol_for_winning.loadtexture("image/win.bmp");
     symbol_for_winning.setheight(124);
     symbol_for_winning.setwidth(84);
     symbol_for_winning.settdy(game_win_line2.gettdy()+50);
     symbol_for_winning.settdx(500);

    symbol_for_winning_clip[0].x=0;
    symbol_for_winning_clip[0].y=0;
    symbol_for_winning_clip[0].h=62;
    symbol_for_winning_clip[0].w=44;

    symbol_for_winning_clip[1].x=58+44;
    symbol_for_winning_clip[1].y=0;
    symbol_for_winning_clip[1].h=62;
    symbol_for_winning_clip[1].w=42;

    symbol_for_winning_clip[2].x=58+44+58+42;
    symbol_for_winning_clip[2].y=0;
    symbol_for_winning_clip[2].h=62;
    symbol_for_winning_clip[2].w=44;

    symbol_for_winning_clip[3].x=58+44+58+42+44+56;
    symbol_for_winning_clip[3].y=0;
    symbol_for_winning_clip[3].h=62;
    symbol_for_winning_clip[3].w=44;

    symbol_for_winning_clip[4].x=58+44+58+42+44+56+44+56;
    symbol_for_winning_clip[4].y=0;
    symbol_for_winning_clip[4].h=62;
    symbol_for_winning_clip[4].w=44;

    symbol_for_winning_clip[5].x=58+44+58+42+44+56+44+56+44+56;
    symbol_for_winning_clip[5].y=0;
    symbol_for_winning_clip[5].h=62;
    symbol_for_winning_clip[5].w=48;

    symbol_for_winning_clip[6].x=58+44+58+42+44+56+44+56+44+56+48+52;
    symbol_for_winning_clip[6].y=0;
    symbol_for_winning_clip[6].h=62;
    symbol_for_winning_clip[6].w=50;

    symbol_for_winning_clip[7].x=58+44+58+42+44+56+44+56+44+56+48+52+50+50;
    symbol_for_winning_clip[7].y=0;
    symbol_for_winning_clip[7].h=62;
    symbol_for_winning_clip[7].w=48;

    for(int i=8;i<14;i++){
        symbol_for_winning_clip[i].x=58+44+58+42+44+56+44+56+44+56+48+52+50+50+(48+52)*(i-7);
        symbol_for_winning_clip[i].y=0;
        symbol_for_winning_clip[i].h=62;
        symbol_for_winning_clip[i].w=48;
    }

        symbol_for_winning_clip[14].x=0;
        symbol_for_winning_clip[14].y=94;
        symbol_for_winning_clip[14].h=62;
        symbol_for_winning_clip[14].w=50;

        symbol_for_winning_clip[15].x=50+52;
        symbol_for_winning_clip[15].y=94;
        symbol_for_winning_clip[15].h=62;
        symbol_for_winning_clip[15].w=48;

        symbol_for_winning_clip[16].x=50+52+48+52;
        symbol_for_winning_clip[16].y=94;
        symbol_for_winning_clip[16].h=62;
        symbol_for_winning_clip[16].w=50;

        symbol_for_winning_clip[17].x=50+52+48+52+50+50;
        symbol_for_winning_clip[17].y=94;
        symbol_for_winning_clip[17].h=62;
        symbol_for_winning_clip[17].w=48;

        symbol_for_winning_clip[18].x=50+52+48+52+50+50+48+52;
        symbol_for_winning_clip[18].y=94;
        symbol_for_winning_clip[18].h=62;
        symbol_for_winning_clip[18].w=44;

        symbol_for_winning_clip[19].x=50+52+48+52+50+50+48+52+44+56;
        symbol_for_winning_clip[19].y=94;
        symbol_for_winning_clip[19].h=62;
        symbol_for_winning_clip[19].w=44;










}

void set_game_win_active(SDL_Event e,bool& quit,bool&thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                          bool &game_over,bool &game_win,bool &reset_everything_in_main_interface,bool &does_music_in_menu_game_appear){
      if((SDL_GetTicks()-time_run_game_win_system)/1000>4){

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





                        if( inside_button_continue_in_the_game_win )
                        {

                               switch( e.type )
                                {

                                case SDL_MOUSEBUTTONUP :
                                reset_everything_in_game=true;
                                 if(Mix_Playing(3)==0){
                                    Mix_PlayChannel( 3, music_select, 0 );
                                }

                                break;


                                }




                        }

             }
         }



      }
}
