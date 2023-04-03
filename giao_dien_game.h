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


button start_button_system[button_total];
button tutorial_button_system[button_total];
button quit_button_system[button_total];








#endif // GIAO_DIEN_GAME_H_INCLUDED



void set_value_for_menu_of_game(){

        menu_background_clip[0].h=454;
	    menu_background_clip[0].w=811;
	    menu_background_clip[0].x=0;
	    menu_background_clip[0].y=0;

        menu_background_clip[1].h=454;
	    menu_background_clip[1].w=811;
	    menu_background_clip[1].x=811;
	    menu_background_clip[1].y=0;

        image_start.loadtexture("start_button_status.bmp");
	    start_button_clip[0].h=365;
	    start_button_clip[0].w=975;
	    start_button_clip[0].x=0;
	    start_button_clip[0].y=0;

	    start_button_clip[1].h=365;
	    start_button_clip[1].w=975;
	    start_button_clip[1].x=0;
	    start_button_clip[1].y=365+270;



		start_button_system[0].setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2);
		image_start.settdx(-start_button_system[0].gettdx());
		image_start.settdy(start_button_system[0].gettdy());
		image_start.setheight(button_height);
		image_start.setwidth(button_width);

		image_tutorial.loadtexture("tutorial_button_status.bmp");
        tutorial_button_clip[0].h=365;
	    tutorial_button_clip[0].w=975;
	    tutorial_button_clip[0].x=0;
	    tutorial_button_clip[0].y=0;

	    tutorial_button_clip[1].h=365;
	    tutorial_button_clip[1].w=975;
	    tutorial_button_clip[1].x=0;
	    tutorial_button_clip[1].y=365+270;

	    tutorial_button_system[0].setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+150);
		image_tutorial.settdx(-tutorial_button_system[0].gettdx());
		image_tutorial.settdy(tutorial_button_system[0].gettdy());
		image_tutorial.setheight(button_height);
		image_tutorial.setwidth(button_width);


	    image_quit.loadtexture("quit_button_status.bmp");
        quit_button_clip[0].h=365;
        quit_button_clip[0].w=975;
	    quit_button_clip[0].x=0;
	    quit_button_clip[0].y=0;

	    quit_button_clip[1].h=365;
	    quit_button_clip[1].w=975;
	    quit_button_clip[1].x=0;
	    quit_button_clip[1].y=365+270;



		quit_button_system[0].setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+300);
		image_quit.settdx(-quit_button_system[0].gettdx());
		image_quit.settdy(quit_button_system[0].gettdy());
		image_quit.setheight(button_height);
		image_quit.setwidth(button_width);



       // back ground

		menu_background.loadtexture("background_of_menu.bmp");
		menu_background.setheight(height_of_screen);
		menu_background.setwidth(width_of_screen);
		menu_background.settdx(0);
		menu_background.settdy(0);

        sans_in_bg.loadtexture("sans_in_bg.bmp");
        sans_in_bg.setheight(640);
		sans_in_bg.setwidth(640);
        sans_in_bg.settdx(0-640);
		sans_in_bg.settdy(height_of_screen);

        soul_of_sans_in_bg.loadtexture("soul_of_sans.bmp");
        soul_of_sans_in_bg.setheight(640);
		soul_of_sans_in_bg.setwidth(640);
        soul_of_sans_in_bg.settdx(sans_in_bg.gettdx()+20);
		soul_of_sans_in_bg.settdy(sans_in_bg.gettdy()-100);


        chara_in_bg.loadtexture("chara_in_bg.bmp");
        chara_in_bg.setheight(286);
		chara_in_bg.setwidth(442);
        chara_in_bg.settdx(width_of_screen);
		chara_in_bg.settdy(0-286);

        soul_of_chara_in_bg.loadtexture("soul_of_chara.bmp");
        soul_of_chara_in_bg.setheight(640);
		soul_of_chara_in_bg.setwidth(640);
        soul_of_chara_in_bg.settdx(chara_in_bg.gettdx()-100);
		soul_of_chara_in_bg.settdy(chara_in_bg.gettdy()+100);

		bonus_sprite1_for_button.loadtexture("bonus_for_button.bmp");
		bonus_sprite1_for_button.setheight(45);
		bonus_sprite1_for_button.setwidth(57);

		bonus_sprite2_for_button.loadtexture("bonus_for_button_2.bmp");
		bonus_sprite2_for_button.setheight(45);
		bonus_sprite2_for_button.setwidth(20);

		for(int i=0;i<quatities_of_bonus_sprite1;i++){
            bonus_sprite1_for_button_clip[i].h=90;
            bonus_sprite1_for_button_clip[i].w=114;
            bonus_sprite1_for_button_clip[i].x=0;
            bonus_sprite1_for_button_clip[i].y=180-90*i;
		}




}

void set_bonus_sprite_active_when_mouse_inside_button(){
     if(is_bonus_sprite1_for_end_button_active && !is_bonus_sprite2_for_start_button_active &&
                   !is_bonus_sprite2_for_tutorial_button_active ){
                    bonus_sprite1_for_button.settdx(quit_button_system[0].gettdx()-114/2);
                    bonus_sprite1_for_button.settdy(quit_button_system[0].gettdy()+(button_height-45)/2);
                    bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame]);

                }
                if(is_bonus_sprite1_for_start_button_active&& !is_bonus_sprite2_for_start_button_active &&
                   !is_bonus_sprite2_for_tutorial_button_active ){
                    bonus_sprite1_for_button.settdx(start_button_system[0].gettdx()-114/2);
                    bonus_sprite1_for_button.settdy(start_button_system[0].gettdy()+(button_height-45)/2);
                    bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame]);
                    time_appearing_of_bonus_spr1_for_start_button=SDL_GetTicks();

                }
                if(is_bonus_sprite1_for_tutorial_button_active&& !is_bonus_sprite2_for_start_button_active &&
                   !is_bonus_sprite2_for_tutorial_button_active ){
                    bonus_sprite1_for_button.settdx(tutorial_button_system[0].gettdx()-114/2);
                    bonus_sprite1_for_button.settdy(tutorial_button_system[0].gettdy()+(button_height-45)/2);
                    bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame]);
                    time_appearing_of_bonus_spr1_for_tutorial_button=SDL_GetTicks();
                }



}


void set_bonus_sprite_active_when_mouse_up_or_down(bool &condition){
     if(is_bonus_sprite2_for_start_button_active ){
                    bonus_sprite2_for_button.settdx(bonus_sprite1_for_button.gettdx()+50);
                    bonus_sprite2_for_button.settdy(bonus_sprite1_for_button.gettdy());
                    bonus_sprite1_for_button.settdx(bonus_sprite1_for_button.gettdx()-(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_start_button)/100);
                    if(bonus_sprite1_for_button_frame/10>=1){
                        bonus_sprite2_for_button.setwidth(bonus_sprite2_for_button.getwidth()+(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_start_button)/20);
                        bonus_sprite2_for_button.render(NULL);
                    }
                    bonus_sprite1_for_button.settdy(start_button_system[0].gettdy()+(button_height-45)/2);
                    if(bonus_sprite1_for_button_frame/10>=3){
                       bonus_sprite1_for_button_frame=20;
                    }
                    bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame/10]);
                    bonus_sprite1_for_button_frame++;
                    if(bonus_sprite1_for_button.gettdx()<=0){
                       is_bonus_sprite2_for_start_button_active=false;
                       reset_everything_in_game=true;
                       time_watting_change_interface=0;
                       bonus_sprite1_for_button_frame=0;
                       bonus_sprite2_for_button.setwidth(20);
                       bonus_sprite1_for_button.settdx(start_button_system[0].gettdx()-114/2);
                       bonus_sprite1_for_button.settdy(start_button_system[0].gettdy()+(button_height-45)/2);
                    }
                }

                 if(is_bonus_sprite2_for_tutorial_button_active ){
                    bonus_sprite2_for_button.settdx(bonus_sprite1_for_button.gettdx()+50);
                    bonus_sprite2_for_button.settdy(bonus_sprite1_for_button.gettdy());
                    bonus_sprite1_for_button.settdx(bonus_sprite1_for_button.gettdx()-(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_tutorial_button)/100);
                    if(bonus_sprite1_for_button_frame/10>=1){
                        bonus_sprite2_for_button.setwidth(bonus_sprite2_for_button.getwidth()+(SDL_GetTicks()-time_appearing_of_bonus_spr1_for_tutorial_button)/20);
                        bonus_sprite2_for_button.render(NULL);
                    }
                    bonus_sprite1_for_button.settdy(tutorial_button_system[0].gettdy()+(button_height-45)/2);
                    if(bonus_sprite1_for_button_frame/10>=3){
                       bonus_sprite1_for_button_frame=20;
                    }
                    bonus_sprite1_for_button.render(&bonus_sprite1_for_button_clip[bonus_sprite1_for_button_frame/10]);
                    bonus_sprite1_for_button_frame++;
                    if(bonus_sprite1_for_button.gettdx()<=0){
                       is_bonus_sprite2_for_tutorial_button_active=false;
                       condition=true;
                       bonus_sprite1_for_button_frame=0;
                       bonus_sprite2_for_button.setwidth(20);
                       bonus_sprite1_for_button.settdx(tutorial_button_system[0].gettdx()-114/2);
                       bonus_sprite1_for_button.settdy(tutorial_button_system[0].gettdy()+(button_height-45)/2);
                    }
                }


}
void reset_everything_in_main_interface_active(){
        start_button_system[0].setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2);
		image_start.settdx(-start_button_system[0].gettdx());
		image_start.settdy(start_button_system[0].gettdy());

	    tutorial_button_system[0].setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+150);
		image_tutorial.settdx(-tutorial_button_system[0].gettdx());
		image_tutorial.settdy(tutorial_button_system[0].gettdy());

		quit_button_system[0].setPosition(width_of_screen/2-button_width/2,height_of_screen/2-button_height/2+300);
		image_quit.settdx(-quit_button_system[0].gettdx());
		image_quit.settdy(quit_button_system[0].gettdy());

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





