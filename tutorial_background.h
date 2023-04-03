#ifndef TUTORIAL_BACKGROUND_H_INCLUDED
#define TUTORIAL_BACKGROUND_H_INCLUDED
#include"texture.h"
bool does_tutorial_menu_appear=false;
Ltexture background_of_tutorial_menu;
Ltexture tutorial_menu;
Ltexture sprite_button_1;
const int quality_of_sprite_button_1=2;
SDL_Rect sprite_button_1_clip[quality_of_sprite_button_1];
int sprite_button_1_frame=0;

Ltexture sprite_button_2;
const int quality_of_sprite_button_2=2;
SDL_Rect sprite_button_2_clip[quality_of_sprite_button_2];
int sprite_button_2_frame=0;

Ltexture sprite_button_3;
const int quality_of_sprite_button_3=2;
SDL_Rect sprite_button_3_clip[quality_of_sprite_button_3];
int sprite_button_3_frame=0;

Ltexture sprite_button_up;
const int quality_of_sprite_button_up=2;
SDL_Rect sprite_button_up_clip[quality_of_sprite_button_up];
int sprite_button_up_frame=0;

Ltexture sprite_button_left;
const int quality_of_sprite_button_left=2;
SDL_Rect sprite_button_left_clip[quality_of_sprite_button_left];
int sprite_button_left_frame=0;

Ltexture sprite_button_right;
const int quality_of_sprite_button_right=2;
SDL_Rect sprite_button_right_clip[quality_of_sprite_button_right];
int sprite_button_right_frame=0;
int choose_sprite_button_1_2_or_3=1;
bool choose_sprite_button_left_or_right=false;


Ltexture sans_sleep;
const int quality_of_word_z=3;
Ltexture the_word_Z[quality_of_word_z];
int the_word_Z_frame=0;





#endif // TUTORIAL_BACKGROUND_H_INCLUDED

void set_value_for_background_of_tutorial_menu(){

        background_of_tutorial_menu.loadtexture("sans_sleep_bg.bmp");
        background_of_tutorial_menu.setheight(680);
        background_of_tutorial_menu.setwidth(1080);
        background_of_tutorial_menu.settdx(0);
        background_of_tutorial_menu.settdy(0);

        sans_sleep.loadtexture("sans_sleep_ch.bmp");
        sans_sleep.settdx(width_of_screen/3*2);
        sans_sleep.settdy(height_of_screen/3);
        sans_sleep.setheight(430);
        sans_sleep.setwidth(400);

        for(int i=0;i<quality_of_word_z;i++){
            the_word_Z[i].loadtexture("z.bmp");
            the_word_Z[i].settdx(sans_sleep.gettdx()-50*i+100);
            the_word_Z[i].settdy(sans_sleep.gettdy()-50*i-50);
            the_word_Z[i].setheight(46);
            the_word_Z[i].setwidth(32);
        }


        tutorial_menu.loadtexture("tutorial_menu.bmp");
        tutorial_menu.setheight(height_of_screen);
        tutorial_menu.setwidth(width_of_screen);
        tutorial_menu.settdx(0);
        tutorial_menu.settdy(0);



	    sprite_button_1.loadtexture("button_1.bmp");
	    sprite_button_1.settdx(20);
	    sprite_button_1.settdy(172);
	    sprite_button_1.setheight(50);
	    sprite_button_1.setwidth(50);

	    sprite_button_2.loadtexture("button_2.bmp");
	    sprite_button_2.settdx(sprite_button_1.gettdx()+sprite_button_1.getheight()+20);
	    sprite_button_2.settdy(sprite_button_1.gettdy());
	    sprite_button_2.setheight(50);
	    sprite_button_2.setwidth(50);

	    sprite_button_3.loadtexture("button_3.bmp");
	    sprite_button_3.settdx(sprite_button_2.gettdx()+sprite_button_2.getheight()+20);
	    sprite_button_3.settdy(sprite_button_1.gettdy());
	    sprite_button_3.setheight(50);
	    sprite_button_3.setwidth(50);

	    sprite_button_up.loadtexture("button_up.bmp");
	    sprite_button_up.settdx(89);
	    sprite_button_up.settdy(452);
	    sprite_button_up.setheight(50);
	    sprite_button_up.setwidth(50);

	    sprite_button_left.loadtexture("button_left.bmp");
	    sprite_button_left.settdx(42);
	    sprite_button_left.settdy(306);
	    sprite_button_left.setheight(50);
	    sprite_button_left.setwidth(50);

	    sprite_button_right.loadtexture("button_right.bmp");
	    sprite_button_right.settdx(sprite_button_1.gettdx()+sprite_button_1.getwidth()+42);
	    sprite_button_right.settdy(sprite_button_left.gettdy());
	    sprite_button_right.setheight(50);
	    sprite_button_right.setwidth(50);

	    for(int i=0;i<quality_of_sprite_button_1;i++){
            sprite_button_1_clip[i].x=0+(83+139)*i;
            sprite_button_1_clip[i].y=0;
            sprite_button_1_clip[i].h=146;
            sprite_button_1_clip[i].w=139;

	    }

	    for(int i=0;i<quality_of_sprite_button_2;i++){
            sprite_button_2_clip[i].x=0+(83+139)*i;
            sprite_button_2_clip[i].y=0;
            sprite_button_2_clip[i].h=146;
            sprite_button_2_clip[i].w=139;

	    }

	    for(int i=0;i<quality_of_sprite_button_3;i++){
            sprite_button_3_clip[i].x=0+(83+139)*i;
            sprite_button_3_clip[i].y=0;
            sprite_button_3_clip[i].h=146;
            sprite_button_3_clip[i].w=139;

	    }

	    for(int i=0;i<quality_of_sprite_button_left;i++){
            sprite_button_left_clip[i].x=0+(83+139)*i;
            sprite_button_left_clip[i].y=0;
            sprite_button_left_clip[i].h=146;
            sprite_button_left_clip[i].w=139;

	    }

	     for(int i=0;i<quality_of_sprite_button_right;i++){
            sprite_button_right_clip[i].x=0+(83+139)*i;
            sprite_button_right_clip[i].y=0;
            sprite_button_right_clip[i].h=146;
            sprite_button_right_clip[i].w=139;

	    }

	     for(int i=0;i<quality_of_sprite_button_up;i++){
            sprite_button_up_clip[i].x=0+(83+139)*i;
            sprite_button_up_clip[i].y=0;
            sprite_button_up_clip[i].h=146;
            sprite_button_up_clip[i].w=139;

	    }




}


 // set tutorial menu active

    void set_tutorial_menu_active(){
                    background_of_tutorial_menu.render(NULL);
                    tutorial_menu.render(NULL);
                    sans_sleep.render(NULL);

                    for(int i=0;i<the_word_Z_frame/50;i++){
                        the_word_Z[i].render(NULL);
                    }
                    the_word_Z_frame++;
                    if(the_word_Z_frame/50>=4){
                       the_word_Z_frame=0;
                    }

                    sprite_button_1.render(&sprite_button_1_clip[sprite_button_1_frame/30]);
                    sprite_button_2.render(&sprite_button_2_clip[sprite_button_2_frame/30]);
                    sprite_button_3.render(&sprite_button_3_clip[sprite_button_3_frame/30]);

                    sprite_button_left.render(&sprite_button_left_clip[sprite_button_left_frame/50]);
                    sprite_button_right.render(&sprite_button_right_clip[sprite_button_right_frame/50]);

                    sprite_button_up.render(&sprite_button_up_clip[sprite_button_up_frame/100]);
                    sprite_button_up_frame++;
                    if(sprite_button_up_frame/100>=2){
                        sprite_button_up_frame=0;
                    }

                    if(choose_sprite_button_1_2_or_3==1){
                        if(sprite_button_1_frame/30>=2){
                            sprite_button_1_frame=0;
                            choose_sprite_button_1_2_or_3=2;
                        }
                          sprite_button_1_frame++;
                    }


                    if(choose_sprite_button_1_2_or_3==2){
                          if(sprite_button_2_frame/30>=2){
                            sprite_button_2_frame=0;
                            choose_sprite_button_1_2_or_3=3;
                          }

                          sprite_button_2_frame++;
                    }

                    if(choose_sprite_button_1_2_or_3==3){

                      if(sprite_button_3_frame/30>=2){
                         sprite_button_3_frame=0;
                         choose_sprite_button_1_2_or_3=1;
                      }
                        sprite_button_3_frame++;
                    }


                    if(choose_sprite_button_left_or_right){
                       sprite_button_right_frame++;
                       if(sprite_button_right_frame/50>=2){
                          sprite_button_right_frame=0;
                          choose_sprite_button_left_or_right=false;
                       }
                    }
                    else{
                         sprite_button_left_frame++;
                         if(sprite_button_left_frame/50>=2){
                            sprite_button_left_frame=0;
                            choose_sprite_button_left_or_right=true;
                         }

                    }


        }


