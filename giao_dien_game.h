#ifndef GIAO_DIEN_GAME_H_INCLUDED
#define GIAO_DIEN_GAME_H_INCLUDED
#include"texture.h"
#include"button.h"
// create handmade button

int start_button_frame=0;
const int quatities_of_start_button_frame=2;
SDL_Rect start_button_clip[quatities_of_start_button_frame];
bool inside_start_button=false;

int tutorial_button_frame=0;
const int quatities_of_tutorial_button_frame=2;
SDL_Rect tutorial_button_clip[quatities_of_tutorial_button_frame];
bool inside_tutorial_button=false;

int quit_button_frame=0;
const int quatities_of_quit_button_frame=2;
SDL_Rect quit_button_clip[quatities_of_quit_button_frame];
bool inside_quit_button=false;


//create music
Mix_Music *music_in_menu_game=NULL;
bool does_music_in_menu_game_appear=true;




// lớp con chuột
Ltexture image_start;
Ltexture image_tutorial;
Ltexture image_quit;



const int quatities_of_menu_background_sprite=2;
int menu_background_frame=0;
SDL_Rect menu_background_clip[quatities_of_menu_background_sprite];
Ltexture menu_background;



Ltexture sans_in_bg;
bool repeat_moving_of_sans=false;
Ltexture soul_of_sans_in_bg;
bool repeat_moving_of_soul_of_sans=false;
bool can_soul_of_sans_appear=false;



Ltexture chara_in_bg;
bool repeat_moving_of_chara=false;
Ltexture soul_of_chara_in_bg;
bool repeat_moving_of_soul_of_chara=false;
bool can_soul_of_chara_appear=false;



const int quatities_of_bonus_sprite1=3;
SDL_Rect bonus_sprite1_for_button_clip[quatities_of_bonus_sprite1];
int bonus_sprite1_for_button_frame=0;
Ltexture bonus_sprite1_for_button;

bool is_bonus_sprite1_for_start_button_active=false;
int time_appearing_of_bonus_spr1_for_start_button=0;

bool is_bonus_sprite1_for_tutorial_button_active=false;
int time_appearing_of_bonus_spr1_for_tutorial_button=0;

bool is_bonus_sprite1_for_end_button_active=false;


Ltexture bonus_sprite2_for_button;
bool is_bonus_sprite2_for_start_button_active=false;
bool is_bonus_sprite2_for_tutorial_button_active=false;

int time_in_interface_of_game=0;


button start_button_in_game_menu;
button tutorial_button_in_game_menu;
button quit_button_in_game_menu;

Mix_Chunk *music_gb=NULL;
Mix_Chunk *music_select=NULL;








#endif // GIAO_DIEN_GAME_H_INCLUDED
void free_music_in_menu_game()
{
    Mix_FreeMusic( music_in_menu_game );
    music_in_menu_game = NULL;
    Mix_FreeChunk( music_gb);
    music_gb = NULL;
    Mix_FreeChunk( music_select);
    music_select = NULL;
}



void set_value_for_menu_of_game()
{


    music_in_menu_game=Mix_LoadMUS("music/hope and dream.mp3");
    if( music_in_menu_game == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );

    }

    music_gb=Mix_LoadWAV("music/gb_sound.mp3");
    if( music_gb == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );

    }

    music_select=Mix_LoadWAV("music/select_sound.mp3");
    if( music_select == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );

    }




    menu_background_clip[0].h=454;
    menu_background_clip[0].w=811;
    menu_background_clip[0].x=0;
    menu_background_clip[0].y=0;

    menu_background_clip[1].h=454;
    menu_background_clip[1].w=811;
    menu_background_clip[1].x=811;
    menu_background_clip[1].y=0;

    image_start.loadtexture("image/start_button_status.bmp");
    start_button_clip[0].h=365;
    start_button_clip[0].w=975;
    start_button_clip[0].x=0;
    start_button_clip[0].y=0;

    start_button_clip[1].h=365;
    start_button_clip[1].w=975;
    start_button_clip[1].x=0;
    start_button_clip[1].y=365+270;



    start_button_in_game_menu.setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2);
    image_start.settdx(-start_button_in_game_menu.gettdx());
    image_start.settdy(start_button_in_game_menu.gettdy());
    image_start.setheight(button_height);
    image_start.setwidth(button_width);

    image_tutorial.loadtexture("image/tutorial_button_status.bmp");
    tutorial_button_clip[0].h=365;
    tutorial_button_clip[0].w=975;
    tutorial_button_clip[0].x=0;
    tutorial_button_clip[0].y=0;

    tutorial_button_clip[1].h=365;
    tutorial_button_clip[1].w=975;
    tutorial_button_clip[1].x=0;
    tutorial_button_clip[1].y=365+270;

    tutorial_button_in_game_menu.setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+150);
    image_tutorial.settdx(-tutorial_button_in_game_menu.gettdx());
    image_tutorial.settdy(tutorial_button_in_game_menu.gettdy());
    image_tutorial.setheight(button_height);
    image_tutorial.setwidth(button_width);


    image_quit.loadtexture("image/quit_button_status.bmp");
    quit_button_clip[0].h=365;
    quit_button_clip[0].w=975;
    quit_button_clip[0].x=0;
    quit_button_clip[0].y=0;

    quit_button_clip[1].h=365;
    quit_button_clip[1].w=975;
    quit_button_clip[1].x=0;
    quit_button_clip[1].y=365+270;



    quit_button_in_game_menu.setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+300);
    image_quit.settdx(-quit_button_in_game_menu.gettdx());
    image_quit.settdy(quit_button_in_game_menu.gettdy());
    image_quit.setheight(button_height);
    image_quit.setwidth(button_width);



    // back ground

    menu_background.loadtexture("image/background_of_menu.bmp");
    menu_background.setheight(height_of_screen);
    menu_background.setwidth(width_of_screen);
    menu_background.settdx(0);
    menu_background.settdy(0);

    sans_in_bg.loadtexture("image/sans_in_bg.bmp");
    sans_in_bg.setheight(640);
    sans_in_bg.setwidth(640);
    sans_in_bg.settdx(0-640);
    sans_in_bg.settdy(height_of_screen);

    soul_of_sans_in_bg.loadtexture("image/soul_of_sans.bmp");
    soul_of_sans_in_bg.setheight(640);
    soul_of_sans_in_bg.setwidth(640);
    soul_of_sans_in_bg.settdx(sans_in_bg.gettdx()+20);
    soul_of_sans_in_bg.settdy(sans_in_bg.gettdy()-100);


    chara_in_bg.loadtexture("image/chara_in_bg.bmp");
    chara_in_bg.setheight(286);
    chara_in_bg.setwidth(442);
    chara_in_bg.settdx(width_of_screen);
    chara_in_bg.settdy(0-286);

    soul_of_chara_in_bg.loadtexture("image/soul_of_chara.bmp");
    soul_of_chara_in_bg.setheight(640);
    soul_of_chara_in_bg.setwidth(640);
    soul_of_chara_in_bg.settdx(chara_in_bg.gettdx()-100);
    soul_of_chara_in_bg.settdy(chara_in_bg.gettdy()+100);

    bonus_sprite1_for_button.loadtexture("image/bonus_for_button.bmp");
    bonus_sprite1_for_button.setheight(45);
    bonus_sprite1_for_button.setwidth(57);

    bonus_sprite2_for_button.loadtexture("image/bonus_for_button_2.bmp");
    bonus_sprite2_for_button.setheight(45);
    bonus_sprite2_for_button.setwidth(20);

    for(int i=0; i<quatities_of_bonus_sprite1; i++)
    {
        bonus_sprite1_for_button_clip[i].h=90;
        bonus_sprite1_for_button_clip[i].w=114;
        bonus_sprite1_for_button_clip[i].x=0;
        bonus_sprite1_for_button_clip[i].y=180-90*i;
    }




}

// chèn hoạt ảnh khi di chuyển các nút vào 3 nút lựa chọn
void set_bonus_sprite_active_when_mouse_inside_button()
{
    if(is_bonus_sprite1_for_end_button_active && !is_bonus_sprite2_for_start_button_active &&
            !is_bonus_sprite2_for_tutorial_button_active )
    {
        bonus_sprite1_for_button.settdx(quit_button_in_game_menu.gettdx()-114/2);
        bonus_sprite1_for_button.settdy(quit_button_in_game_menu.gettdy()+(button_height-45)/2);
        bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame]);

    }
    if(is_bonus_sprite1_for_start_button_active&& !is_bonus_sprite2_for_start_button_active &&
            !is_bonus_sprite2_for_tutorial_button_active )
    {
        bonus_sprite1_for_button.settdx(start_button_in_game_menu.gettdx()-114/2);
        bonus_sprite1_for_button.settdy(start_button_in_game_menu.gettdy()+(button_height-45)/2);
        bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame]);
        time_appearing_of_bonus_spr1_for_start_button=SDL_GetTicks();

    }
    if(is_bonus_sprite1_for_tutorial_button_active&& !is_bonus_sprite2_for_start_button_active &&
            !is_bonus_sprite2_for_tutorial_button_active )
    {
        bonus_sprite1_for_button.settdx(tutorial_button_in_game_menu.gettdx()-114/2);
        bonus_sprite1_for_button.settdy(tutorial_button_in_game_menu.gettdy()+(button_height-45)/2);
        bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame]);
        time_appearing_of_bonus_spr1_for_tutorial_button=SDL_GetTicks();
    }



}


// set hoạt ảnh chuyển động khi ấn vào 2 nút start hoặc tutorial
void set_bonus_sprite_active_when_mouse_up_or_down(bool &condition,bool &does_choice_menu_appear)
{
    if(is_bonus_sprite2_for_start_button_active )
    {

        bonus_sprite2_for_button.settdx(bonus_sprite1_for_button.gettdx()+50);
        bonus_sprite2_for_button.settdy(bonus_sprite1_for_button.gettdy());
        bonus_sprite1_for_button.settdx(bonus_sprite1_for_button.gettdx()-(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_start_button)/100);
        if(bonus_sprite1_for_button_frame/10>=1)
        {
            bonus_sprite2_for_button.setwidth(bonus_sprite2_for_button.getwidth()+(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_start_button)/20);
            bonus_sprite2_for_button.render(NULL);
        }
        bonus_sprite1_for_button.settdy(start_button_in_game_menu.gettdy()+(button_height-45)/2);
        if(bonus_sprite1_for_button_frame/10>=3)
        {
            bonus_sprite1_for_button_frame=20;
        }
        bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame/10]);
        bonus_sprite1_for_button_frame++;
        if(bonus_sprite1_for_button.gettdx()<=0)
        {
            is_bonus_sprite2_for_start_button_active=false;
            does_choice_menu_appear=true;
            time_watting_change_interface=0;
            bonus_sprite1_for_button_frame=0;
            bonus_sprite2_for_button.setwidth(20);
            bonus_sprite1_for_button.settdx(start_button_in_game_menu.gettdx()-114/2);
            bonus_sprite1_for_button.settdy(start_button_in_game_menu.gettdy()+(button_height-45)/2);
        }
    }

    if(is_bonus_sprite2_for_tutorial_button_active )
    {
        bonus_sprite2_for_button.settdx(bonus_sprite1_for_button.gettdx()+50);
        bonus_sprite2_for_button.settdy(bonus_sprite1_for_button.gettdy());
        bonus_sprite1_for_button.settdx(bonus_sprite1_for_button.gettdx()-(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_tutorial_button)/100);
        if(bonus_sprite1_for_button_frame/10>=1)
        {
            bonus_sprite2_for_button.setwidth(bonus_sprite2_for_button.getwidth()+(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_tutorial_button)/20);
            bonus_sprite2_for_button.render(NULL);
        }
        bonus_sprite1_for_button.settdy(tutorial_button_in_game_menu.gettdy()+(button_height-45)/2);
        if(bonus_sprite1_for_button_frame/10>=3)
        {
            bonus_sprite1_for_button_frame=20;
        }
        bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame/10]);
        bonus_sprite1_for_button_frame++;
        if(bonus_sprite1_for_button.gettdx()<=0)
        {
            is_bonus_sprite2_for_tutorial_button_active=false;
            condition=true;
            bonus_sprite1_for_button_frame=0;
            bonus_sprite2_for_button.setwidth(20);
            bonus_sprite1_for_button.settdx(tutorial_button_in_game_menu.gettdx()-114/2);
            bonus_sprite1_for_button.settdy(tutorial_button_in_game_menu.gettdy()+(button_height-45)/2);
        }
    }


}
void reset_everything_in_main_interface_active()
{
    start_button_in_game_menu.setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2);
    image_start.settdx(-start_button_in_game_menu.gettdx());
    image_start.settdy(start_button_in_game_menu.gettdy());

    tutorial_button_in_game_menu.setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+150);
    image_tutorial.settdx(-tutorial_button_in_game_menu.gettdx());
    image_tutorial.settdy(tutorial_button_in_game_menu.gettdy());

    quit_button_in_game_menu.setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+300);
    image_quit.settdx(-quit_button_in_game_menu.gettdx());
    image_quit.settdy(quit_button_in_game_menu.gettdy());

    sans_in_bg.setheight(640);
    sans_in_bg.setwidth(640);
    sans_in_bg.settdx(0-640);
    sans_in_bg.settdy(height_of_screen);


    soul_of_sans_in_bg.setheight(640);
    soul_of_sans_in_bg.setwidth(640);
    soul_of_sans_in_bg.settdx(sans_in_bg.gettdx()+20);
    soul_of_sans_in_bg.settdy(sans_in_bg.gettdy()-100);

    chara_in_bg.setheight(286);
    chara_in_bg.setwidth(442);
    chara_in_bg.settdx(width_of_screen);
    chara_in_bg.settdy(0-286);

    soul_of_chara_in_bg.setheight(640);
    soul_of_chara_in_bg.setwidth(640);
    soul_of_chara_in_bg.settdx(chara_in_bg.gettdx()-100);
    soul_of_chara_in_bg.settdy(chara_in_bg.gettdy()+100);

    repeat_moving_of_chara=false;
    repeat_moving_of_sans=false;
    repeat_moving_of_soul_of_chara=false;
    repeat_moving_of_soul_of_sans=false;

    is_bonus_sprite1_for_end_button_active=false;
    is_bonus_sprite1_for_start_button_active=false;
    is_bonus_sprite1_for_tutorial_button_active=false;
    is_bonus_sprite2_for_start_button_active=false;
    is_bonus_sprite2_for_tutorial_button_active=false;
    bonus_sprite1_for_button_frame=0;
    time_in_interface_of_game=SDL_GetTicks();

}



void set_interface_menu_game(SDL_Event e,bool&quit,bool& does_tutorial_menu_appear,bool &does_choice_menu_appear)
{


    menu_background.render(&menu_background_clip[menu_background_frame]);
    if(((SDL_GetTicks()-time_in_interface_of_game)/1000%5==0||(SDL_GetTicks()-time_in_interface_of_game)/1000%5==1) && (SDL_GetTicks()-time_in_interface_of_game)>0)
    {
        can_soul_of_chara_appear=true;
        can_soul_of_sans_appear=true;
        menu_background_frame=1;
        menu_background.render(&menu_background_clip[menu_background_frame]);
    }
    else
    {
        can_soul_of_chara_appear=false;
        can_soul_of_sans_appear=false;
        menu_background_frame=0;
    }
    sans_in_bg.render(NULL);
    if(can_soul_of_sans_appear)
    {
        soul_of_sans_in_bg.render(NULL);
    }
    chara_in_bg.render(NULL);
    if(can_soul_of_chara_appear)
    {
        soul_of_chara_in_bg.render(NULL);
    }

    while( SDL_PollEvent( &e ) != 0 )
    {

        if( e.type == SDL_QUIT )
        {
            quit = true;
        }
        if(e.key.keysym.sym==SDLK_ESCAPE)
        {
            does_tutorial_menu_appear=false;
        }
        if((e.type==SDL_MOUSEBUTTONDOWN||e.type==SDL_MOUSEBUTTONUP||e.type==SDL_MOUSEMOTION) &&
                !(image_quit.gettdx()<width_of_screen/2-button_width/2 ||
                  image_start.gettdx()<width_of_screen/2-button_width/2||
                  image_tutorial.gettdx()<width_of_screen/2-button_width/2) &&
                !does_tutorial_menu_appear)
        {

            SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);


            if(tdx_of_my_mouse>=start_button_in_game_menu.gettdx() && start_button_in_game_menu.gettdx()+button_width>=tdx_of_my_mouse && start_button_in_game_menu.gettdy()<=tdy_of_my_mouse && start_button_in_game_menu.gettdy()+button_height>=tdy_of_my_mouse)
            {
                inside_start_button=true;
            }
            else
            {
                inside_start_button=false;
            }
            if(tdx_of_my_mouse>=tutorial_button_in_game_menu.gettdx() && tutorial_button_in_game_menu.gettdx()+button_width>=tdx_of_my_mouse && tutorial_button_in_game_menu.gettdy()<=tdy_of_my_mouse && tutorial_button_in_game_menu.gettdy()+button_height>=tdy_of_my_mouse)
            {
                inside_tutorial_button=true;
            }
            else
            {
                inside_tutorial_button=false;
            }
            if(tdx_of_my_mouse>=quit_button_in_game_menu.gettdx() &&
                    quit_button_in_game_menu.gettdx()+button_width>=tdx_of_my_mouse
                    && quit_button_in_game_menu.gettdy()<=tdy_of_my_mouse
                    && quit_button_in_game_menu.gettdy()+button_height>=tdy_of_my_mouse)
            {
                inside_quit_button=true;
            }
            else
            {
                inside_quit_button=false;
            }


            if( inside_start_button )
            {
                is_bonus_sprite1_for_start_button_active=true;




                switch( e.type )
                {
                case SDL_MOUSEMOTION:
                    start_button_frame=1;
                    break;
                case SDL_MOUSEBUTTONUP :
                    if(Mix_Playing(3)==0)
                    {
                        Mix_PlayChannel( 3, music_select, 0 );
                    }
                    is_bonus_sprite2_for_start_button_active=true;
                    Mix_PlayChannel( 2, music_gb, 0 );

                    break;


                }

            }
            else
            {
                is_bonus_sprite1_for_start_button_active=false;
                start_button_frame=0;
            }



            if( inside_tutorial_button )
            {




                is_bonus_sprite1_for_tutorial_button_active=true;
                switch( e.type )
                {
                case SDL_MOUSEMOTION:
                    tutorial_button_frame=1;

                    break;
                case SDL_MOUSEBUTTONUP:


                    if(Mix_Playing(3)==0)
                    {
                        Mix_PlayChannel( 3, music_select, 0 );
                    }
                    is_bonus_sprite2_for_tutorial_button_active=true;
                    Mix_PlayChannel( 2, music_gb, 0 );
                    break;


                }
            }
            else
            {
                is_bonus_sprite1_for_tutorial_button_active=false;
                tutorial_button_frame=0;
            }
            //Mouse is inside button



            if( inside_quit_button )
            {
                is_bonus_sprite1_for_end_button_active=true;



                switch( e.type )
                {
                case SDL_MOUSEMOTION:
                    quit_button_frame=1;
                    break;
                case SDL_MOUSEBUTTONUP:
                    quit=true;
                    if(Mix_Playing(3)==0)
                    {
                        Mix_PlayChannel( 3, music_select, 0 );
                    }
                    break;


                }
            }
            else
            {
                is_bonus_sprite1_for_end_button_active=false;
                quit_button_frame=0;

            }


        }



    }







    //set 3 button start,tutorial,quit moving

    if((SDL_GetTicks()-time_in_interface_of_game)/1000>=2)
    {
        if(image_quit.gettdx()<width_of_screen/2-button_width/2 ||
                image_start.gettdx()<width_of_screen/2-button_width/2||
                image_tutorial.gettdx()<width_of_screen/2-button_width/2)
        {
            image_start.settdx(image_start.gettdx()+15);
            image_tutorial.settdx(image_tutorial.gettdx()+15);
            image_quit.settdx(image_quit.gettdx()+15);

        }


        image_start.render(&start_button_clip[start_button_frame]);
        image_tutorial.render(&tutorial_button_clip[tutorial_button_frame]);
        image_quit.render(&quit_button_clip[quit_button_frame]);
    }
    else
    {
        image_quit.settdx(-quit_button_in_game_menu.gettdx());
        image_start.settdx(-start_button_in_game_menu.gettdx());
        image_tutorial.settdx(-tutorial_button_in_game_menu.gettdx());
    }



    // set bonus sprite active when mouse inside button
    set_bonus_sprite_active_when_mouse_inside_button();


    // set bonus sprite active when mouse up or down
    set_bonus_sprite_active_when_mouse_up_or_down(does_tutorial_menu_appear,does_choice_menu_appear);

    //sans in bg moving
    if(!repeat_moving_of_sans)
    {
        if(!(sans_in_bg.gettdx()>=0-20))
        {
            sans_in_bg.settdx(sans_in_bg.gettdx()+5);
            sans_in_bg.settdy(sans_in_bg.gettdy()-5);


        }
        else
        {
            repeat_moving_of_sans=true;
            sans_in_bg.settdx(-20);

        }
    }



    else
    {
        if(SDL_GetTicks()/1000%2==0)
        {
            sans_in_bg.settdx(sans_in_bg.gettdx()-1);
            sans_in_bg.settdy(sans_in_bg.gettdy()+1);

        }
        else
        {
            sans_in_bg.settdx(sans_in_bg.gettdx()+1);
            sans_in_bg.settdy(sans_in_bg.gettdy()-1);
        }

    }


    // soul of sans  moving


    if(!repeat_moving_of_soul_of_sans)
    {
        if(!(soul_of_sans_in_bg.gettdx()>=0+20-15 ))
        {
            soul_of_sans_in_bg.settdx(soul_of_sans_in_bg.gettdx()+5);
            soul_of_sans_in_bg.settdy(soul_of_sans_in_bg.gettdy()-5);

        }
        else
        {
            repeat_moving_of_soul_of_sans=true;
            soul_of_sans_in_bg.settdx(5);

        }
    }


    else
    {
        if(SDL_GetTicks()/1000%2==0)
        {
            soul_of_sans_in_bg.settdx(soul_of_sans_in_bg.gettdx()-1);
            soul_of_sans_in_bg.settdy(soul_of_sans_in_bg.gettdy()+1);

        }
        else
        {
            soul_of_sans_in_bg.settdx(soul_of_sans_in_bg.gettdx()+1);
            soul_of_sans_in_bg.settdy(soul_of_sans_in_bg.gettdy()-1);
        }

    }






    // chara in bg moving

    if(!repeat_moving_of_chara)
    {
        if(!(chara_in_bg.gettdx()<=width_of_screen-442+50) )
        {
            chara_in_bg.settdx(chara_in_bg.gettdx()-442/100+50/100);
            chara_in_bg.settdy(chara_in_bg.gettdy()+286/100);

        }
        else
        {
            repeat_moving_of_chara=true;
            chara_in_bg.settdy(0-50);
            chara_in_bg.settdx(width_of_screen-442+50);

        }
    }


    else
    {
        if(SDL_GetTicks()/1000%2==0)
        {
            chara_in_bg.settdx(chara_in_bg.gettdx()-1);
            chara_in_bg.settdy(chara_in_bg.gettdy()+1);

        }
        else
        {
            chara_in_bg.settdx(chara_in_bg.gettdx()+1);
            chara_in_bg.settdy(chara_in_bg.gettdy()-1);
        }

    }




    //soul of chara moving
    if(!repeat_moving_of_soul_of_chara)
    {
        if(!(soul_of_chara_in_bg.gettdx()<=width_of_screen-442-100 ) )
        {
            soul_of_chara_in_bg.settdx(soul_of_chara_in_bg.gettdx()-442/100);
            soul_of_chara_in_bg.settdy(soul_of_chara_in_bg.gettdy()+286/100);

        }
        else
        {
            repeat_moving_of_soul_of_chara=true;
            soul_of_chara_in_bg.settdx(width_of_screen-442-100);

        }
    }


    else
    {
        if(SDL_GetTicks()/1000%2==0)
        {
            soul_of_chara_in_bg.settdx(soul_of_chara_in_bg.gettdx()-1);
            soul_of_chara_in_bg.settdy(soul_of_chara_in_bg.gettdy()+1);

        }
        else
        {
            soul_of_chara_in_bg.settdx(soul_of_chara_in_bg.gettdx()+1);
            soul_of_chara_in_bg.settdy(soul_of_chara_in_bg.gettdy()-1);
        }

    }
}





