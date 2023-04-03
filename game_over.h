#ifndef gameover
#define gameover
#include"texture.h"
#include"button.h"
const int height_of_button_quit_and_continue_in_game_over=60;
const int width_of_button_quit_and_continue_in_game_over=200;

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

#endif // texture
void game_over_system(){
    //set quit button
     button_continue_in_game_over.setPosition(226,height_of_screen/4*3);
     button_continue_image_in_game_over.loadtexture("demo_continue.bmp");
     button_continue_image_in_game_over.settdx(button_continue_in_game_over.gettdx());
     button_continue_image_in_game_over.settdy(button_continue_in_game_over.gettdy());
     button_continue_image_in_game_over.setheight(height_of_button_quit_and_continue_in_game_over);
     button_continue_image_in_game_over.setwidth(width_of_button_quit_and_continue_in_game_over);


    for(int i=0;i<quality_of_button_continue_in_game_over;i++){
         button_continue_clip_in_game_over[i].h=141;
         button_continue_clip_in_game_over[i].w=432;
         button_continue_clip_in_game_over[i].x=0;
         button_continue_clip_in_game_over[i].y=0+(141+70)*i;
     }





     //set continue button
     button_quit_in_game_over.setPosition(226+width_of_button_quit_and_continue_in_game_over+button_continue_in_game_over.gettdx(),button_continue_in_game_over.gettdy());
     button_quit_image_in_game_over.loadtexture("demo_quit.bmp");
     button_quit_image_in_game_over.settdx(button_quit_in_game_over.gettdx());
     button_quit_image_in_game_over.settdy(button_quit_in_game_over.gettdy());
     button_quit_image_in_game_over.setheight(height_of_button_quit_and_continue_in_game_over);
     button_quit_image_in_game_over.setwidth(width_of_button_quit_and_continue_in_game_over);

     for(int i=0;i<quality_of_button_quit_in_game_over;i++){
         button_quit_clip_in_game_over[i].h=141;
         button_quit_clip_in_game_over[i].w=432;
         button_quit_clip_in_game_over[i].x=0;
         button_quit_clip_in_game_over[i].y=0+(141+70)*i;
     }






     game_over_class.setheight(680);
     game_over_class.setwidth(1080);
     game_over_class.loadtexture("gameover.bmp");
     game_over_class.settdx(0);
     game_over_class.settdy(0);
     game_over_class.render(NULL);
     button_continue_image_in_game_over.render(&button_continue_clip_in_game_over[button_continue_frame_in_game_over]);
     button_quit_image_in_game_over.render(&button_quit_clip_in_game_over[button_quit_frame_in_game_over]);

}
