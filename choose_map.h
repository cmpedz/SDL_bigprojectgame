#ifndef CHOOSE_MAP_H_INCLUDED
#define CHOOSE_MAP_H_INCLUDED
#include"texture.h"
#include"button.h"

Ltexture bg_of_choose_map;
Ltexture effect_choose_map;
bool choose_map1=true;
bool choose_map2=false;

SDL_Color choose_map_text_color ={237,28,36};
Ltexture your_choose_map;
TTF_Font* Font_choose_map = NULL;

Ltexture map1;
button map1_button;

Ltexture map2;
button map2_button;

Ltexture quit_choose_map;
const int quit_choose_map_quatities=2;
int quit_choose_map_frame=0;
SDL_Rect quit_choose_map_clip[quit_choose_map_quatities];
button  button_quit_choose_map;




#endif // CHOOSE_MAP_H_INCLUDED


void set_value_for_bg_of_choosing_map(){






    Font_choose_map = TTF_OpenFont( "font/title.ttf", 30);
    your_choose_map.loadFromRenderedText("YOUR CHOICE",choose_map_text_color,Font_choose_map);


     bg_of_choose_map.loadtexture("image/bg_choice_menu.bmp");
     bg_of_choose_map.settdx(0);
     bg_of_choose_map.settdy(0);
     bg_of_choose_map.setheight(680);
     bg_of_choose_map.setwidth(1080);

     map1.loadtexture("image/map1.bmp");
     map1.settdx(93);
     map1.settdy(100);
     map1.setwidth(400);
     map1.setheight(400);
     map1_button.setPosition(map1.gettdx(),map1.gettdy());

     map2.loadtexture("image/map2.bmp");
     map2.settdx(93+map1.gettdx()+map1.getwidth());
     map2.settdy(100);
     map2.setwidth(400);
     map2.setheight(400);
     map2_button.setPosition(map2.gettdx(),map2.gettdy());


     effect_choose_map.loadtexture("image/it_is_just_white.bmp");
     effect_choose_map.setheight(420);
     effect_choose_map.setwidth(420);
     effect_choose_map.settdx(0);
     effect_choose_map.settdy(0);



     quit_choose_map.setheight(100);
     quit_choose_map.setwidth(300);
     quit_choose_map.loadtexture("image/demo_quit.bmp");
    button_quit_choose_map.setPosition(0,680- quit_choose_map.getheight()-20);
      quit_choose_map.settdx(button_quit_choose_map.gettdx());
      quit_choose_map.settdy(button_quit_choose_map.gettdy());

     for(int i=0;i<quit_choose_map_quatities;i++){
          quit_choose_map_clip[i].h=134;
         quit_choose_map_clip[i].w=338+4*i;
          quit_choose_map_clip[i].y=0;
          quit_choose_map_clip[i].x=0+(338+128)*i;
     }





}














void set_choose_map_active(int &tdx_of_my_mouse, int &tdy_of_my_mouse,SDL_Event e,
                            bool &does_choice_menu_appear,bool& does_choose_map_appear,
                            bool &quit){
     bg_of_choose_map.render(NULL);
     quit_choose_map.render(&quit_choose_map_clip[quit_choose_map_frame]);



     SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);
     SDL_PollEvent(&e);

     if(e.type==SDL_QUIT){
        quit=true;
     }

     //set quit button in choose map active

           if(tdx_of_my_mouse>=button_quit_choose_map.gettdx() &&
              tdx_of_my_mouse <=button_quit_choose_map.gettdx()+ quit_choose_map.getwidth()&&
              tdy_of_my_mouse>=button_quit_choose_map.gettdy() &&
              tdy_of_my_mouse <=button_quit_choose_map.gettdy()+quit_choose_map.getheight()){
                  quit_choose_map_frame=1;


                  if(e.type==SDL_MOUSEBUTTONUP){
                     does_choose_map_appear=false;
                     does_choice_menu_appear=true;
                      if(Mix_Playing(3)==0){
                        Mix_PlayChannel( 3, music_select, 0 );
                        }

                  }
            }
            else{
                 quit_choose_map_frame=0;
            }

    //set effect choosing map1 and map2

    if(tdx_of_my_mouse>=  map1_button.gettdx() &&
              tdx_of_my_mouse <=map1_button.gettdx()+ map1.getwidth()&&
              tdy_of_my_mouse>=map1_button.gettdy() &&
              tdy_of_my_mouse <=map1_button.gettdy()+map1.getheight()){

                  effect_choose_map.settdx(map1.gettdx()-10);
                  effect_choose_map.settdy(map1.gettdy()-10);
                  effect_choose_map.render(NULL);




               if(e.type==SDL_MOUSEBUTTONUP){

                 if(Mix_Playing(3)==0){
                     Mix_PlayChannel( 3, music_select, 0 );
                  }
                 choose_map1=true;
                  choose_map2=false;

               }
            }





     if(tdx_of_my_mouse>=  map2_button.gettdx() &&
              tdx_of_my_mouse <=map2_button.gettdx()+ map2.getwidth()&&
              tdy_of_my_mouse>=map2_button.gettdy() &&
              tdy_of_my_mouse <=map2_button.gettdy()+map2.getheight()){

                  effect_choose_map.settdx(map2.gettdx()-10);
                  effect_choose_map.settdy(map2.gettdy()-10);
                  effect_choose_map.render(NULL);



                 if(e.type==SDL_MOUSEBUTTONUP){
                   if(Mix_Playing(3)==0){
                     Mix_PlayChannel( 3, music_select, 0 );
                  }
                  choose_map2=true;
                  choose_map1=false;
                  your_choose_map.settdx(map2.gettdx()+(map2.getheight()-your_choose_map.getheight())/2);
                  your_choose_map.render(NULL);

               }
            }



     map1.render(NULL);
    map2.render(NULL);

     //check the choice of player

            if(choose_map1){
                your_choose_map.settdx(map1.gettdx()+(map1.getwidth()-your_choose_map.getwidth())/2);
                your_choose_map.settdy(map1.gettdy()+(map1.getheight()-your_choose_map.getheight())/2);
                your_choose_map.render(NULL);

            }

            if(choose_map2){
                your_choose_map.settdx(map2.gettdx()+(map2.getwidth()-your_choose_map.getwidth())/2);
                your_choose_map.settdy(map2.gettdy()+(map2.getheight()-your_choose_map.getheight())/2);
                your_choose_map.render(NULL);

            }



}


