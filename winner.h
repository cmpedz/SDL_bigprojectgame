#ifndef texture
#define texture
texture
#endif // texture
Ltexture get_dunked_on;

const int height_of_button_quit_and_continue_in_game_win=60;
const int width_of_button_quit_and_continue_in_game_win=200;

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


void set_winner_system(){


     get_dunked_on.setheight(680);
     get_dunked_on.setwidth(1080);
     get_dunked_on.settdx(0);
     get_dunked_on.settdy(0);
     get_dunked_on.loadtexture("get dunked on.bmp");
     get_dunked_on.render(NULL);

     button_continue_in_game_win.setPosition(226,height_of_screen/4*3);
     button_continue_image_in_game_win.loadtexture("demo_continue.bmp");
     button_continue_image_in_game_win.settdx(button_continue_in_game_win.gettdx());
     button_continue_image_in_game_win.settdy(button_continue_in_game_win.gettdy());
     button_continue_image_in_game_win.setheight(height_of_button_quit_and_continue_in_game_win);
     button_continue_image_in_game_win.setwidth(width_of_button_quit_and_continue_in_game_win);


    for(int i=0;i<quality_of_button_continue_in_game_win;i++){
         button_continue_clip_in_game_win[i].h=141;
         button_continue_clip_in_game_win[i].w=432;
         button_continue_clip_in_game_win[i].x=0;
         button_continue_clip_in_game_win[i].y=0+(141+70)*i;
     }





     //set continue button
     button_quit_in_game_win.setPosition(226+width_of_button_quit_and_continue_in_game_win+button_continue_in_game_win.gettdx(),button_continue_in_game_win.gettdy());
     button_quit_image_in_game_win.loadtexture("demo_quit.bmp");
     button_quit_image_in_game_win.settdx(button_quit_in_game_win.gettdx());
     button_quit_image_in_game_win.settdy(button_quit_in_game_win.gettdy());
     button_quit_image_in_game_win.setheight(height_of_button_quit_and_continue_in_game_win);
     button_quit_image_in_game_win.setwidth(width_of_button_quit_and_continue_in_game_win);

     for(int i=0;i<quality_of_button_quit_in_game_win;i++){
         button_quit_clip_in_game_win[i].h=141;
         button_quit_clip_in_game_win[i].w=432;
         button_quit_clip_in_game_win[i].x=0;
         button_quit_clip_in_game_win[i].y=0+(141+70)*i;
     }

     button_continue_image_in_game_win.render(&button_continue_clip_in_game_win[button_continue_frame_in_game_win]);
     button_quit_image_in_game_win.render(&button_quit_clip_in_game_win[button_quit_frame_in_game_win]);


}
