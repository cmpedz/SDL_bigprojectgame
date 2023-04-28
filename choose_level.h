#ifndef CHOOSE_LEVEL_H_INCLUDED
#define CHOOSE_LEVEL_H_INCLUDED
#include"texture.h"
Ltexture bg_of_choose_level;
Ltexture effect_choose_level;
Ltexture level1_text;
bool choose_level1=true;
Ltexture level2_text;
bool choose_level2=false;


TTF_Font* Font_Title_of_choose_level = NULL;
SDL_Color easy_text_color ={34,177,76};
SDL_Color hard_text_color ={237,28,36};
SDL_Color choose_level_text_color ={0,162,232};

Ltexture your_choice_level;
TTF_Font* Font_choice_level = NULL;

Ltexture level1;
button level1_button;

Ltexture level2;
button level2_button;

Ltexture quit_choose_level;
const int quit_choose_level_quatities=2;
int quit_choose_level_frame;
SDL_Rect quit_choose_level_clip[quit_choose_level_quatities];
button  button_quit_choose_level;


#endif // CHOOSE_LEVEL_H_INCLUDED





void set_value_for_bg_of_choosing_level(){




    Font_Title_of_choose_level = TTF_OpenFont( "font/title.ttf", 50);

    Font_choice_level = TTF_OpenFont( "font/title.ttf", 30);

    your_choice_level.loadFromRenderedText("YOUR CHOICE",choose_level_text_color,Font_choice_level);
    level1_text.loadFromRenderedText("EASY",easy_text_color,Font_Title_of_choose_level);
    level2_text.loadFromRenderedText("HARD",hard_text_color,Font_Title_of_choose_level);



     bg_of_choose_level.loadtexture("image/bg_choice_menu.bmp");
     bg_of_choose_level.settdx(0);
     bg_of_choose_level.settdy(0);
     bg_of_choose_level.setheight(680);
     bg_of_choose_level.setwidth(1080);

     level1.loadtexture("image/easymode.bmp");
     level1.settdx(93);
     level1.settdy(100);
     level1.setwidth(400);
     level1.setheight(400);
     level1_button.setPosition(level1.gettdx(),level1.gettdy());

     level2.loadtexture("image/hardmode.bmp");
     level2.settdx(93+level1.gettdx()+level1.getwidth());
     level2.settdy(100);
     level2.setwidth(400);
     level2.setheight(400);
     level2_button.setPosition(level2.gettdx(),level2.gettdy());


     effect_choose_level.loadtexture("image/it_is_just_white.bmp");
     effect_choose_level.setheight(420);
     effect_choose_level.setwidth(420);
     effect_choose_level.settdx(0);
     effect_choose_level.settdy(0);



     quit_choose_level.setheight(100);
     quit_choose_level.setwidth(300);
     quit_choose_level.loadtexture("image/demo_quit.bmp");
    button_quit_choose_level.setPosition(0,680- quit_choose_level.getheight()-20);
      quit_choose_level.settdx(button_quit_choose_level.gettdx());
      quit_choose_level.settdy(button_quit_choose_level.gettdy());

     for(int i=0;i<quit_choose_level_quatities;i++){
          quit_choose_level_clip[i].h=134;
         quit_choose_level_clip[i].w=338+4*i;
          quit_choose_level_clip[i].y=0;
          quit_choose_level_clip[i].x=0+(338+128)*i;
     }





}



void set_choose_level_active(int &tdx_of_my_mouse, int &tdy_of_my_mouse,SDL_Event e,
                            bool &does_choice_menu_appear,bool& does_choose_level,
                            bool &quit){
     bg_of_choose_level.render(NULL);
     quit_choose_level.render(&quit_choose_level_clip[quit_choose_level_frame]);


     SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);
     SDL_PollEvent(&e);

     if(e.type==SDL_QUIT){
        quit=true;
     }

     //set quit button in choose level active

           if(tdx_of_my_mouse>=button_quit_choose_level.gettdx() &&
              tdx_of_my_mouse <=button_quit_choose_level.gettdx()+ quit_choose_level.getwidth()&&
              tdy_of_my_mouse>=button_quit_choose_level.gettdy() &&
              tdy_of_my_mouse <=button_quit_choose_level.gettdy()+quit_choose_level.getheight()){
                  quit_choose_level_frame=1;


                  if(e.type==SDL_MOUSEBUTTONUP){
                     does_choose_level=false;
                     does_choice_menu_appear=true;
                      if(Mix_Playing(3)==0){
                     Mix_PlayChannel( 3, music_select, 0 );
                  }

                  }
            }
            else{
                 quit_choose_level_frame=0;
            }

    //set effect choosing level1 and level2

    if(tdx_of_my_mouse>=  level1_button.gettdx() &&
              tdx_of_my_mouse <=level1_button.gettdx()+ level1.getwidth()&&
              tdy_of_my_mouse>=level1_button.gettdy() &&
              tdy_of_my_mouse <=level1_button.gettdy()+level1.getheight()){





                  effect_choose_level.settdx(level1.gettdx()-10);
                  effect_choose_level.settdy(level1.gettdy()-10);
                  effect_choose_level.render(NULL);

               level1_text.settdx(level1_button.gettdx()+(level1.getwidth()-level1_text.getwidth())/2);
               level1_text.settdy(level1_button.gettdy()-10-level1_text.getheight());
               level1_text.render(NULL);

               if(e.type==SDL_MOUSEBUTTONUP){
                  choose_level1=true;
                  choose_level2=false;
                   if(Mix_Playing(3)==0){
                     Mix_PlayChannel( 3, music_select, 0 );
                  }

               }
            }





     if(tdx_of_my_mouse>=  level2_button.gettdx() &&
              tdx_of_my_mouse <=level2_button.gettdx()+ level2.getwidth()&&
              tdy_of_my_mouse>=level2_button.gettdy() &&
              tdy_of_my_mouse <=level2_button.gettdy()+level2.getheight()){



                  effect_choose_level.settdx(level2.gettdx()-10);
                  effect_choose_level.settdy(level2.gettdy()-10);
                  effect_choose_level.render(NULL);


              level2_text.settdx(level2_button.gettdx()+(level2.getwidth()-level2_text.getwidth())/2);
               level2_text.settdy(level2_button.gettdy()-10-level2_text.getheight());
               level2_text.render(NULL);

                 if(e.type==SDL_MOUSEBUTTONUP){
                     if(Mix_Playing(3)==0){
                     Mix_PlayChannel( 3, music_select, 0 );
                  }
                  choose_level2=true;
                  choose_level1=false;
                  your_choice_level.settdx(level2.gettdx()+(level2.getheight()-your_choice_level.getheight())/2);
                  your_choice_level.render(NULL);

               }
            }



     level1.render(NULL);
     level2.render(NULL);

     //check the choice of player

            if(choose_level1){
                your_choice_level.settdx(level1.gettdx()+(level1.getwidth()-your_choice_level.getwidth())/2);
                your_choice_level.settdy(level1.gettdy()+(level1.getheight()-your_choice_level.getheight())/2);
                your_choice_level.render(NULL);

            }

            if(choose_level2){
                your_choice_level.settdx(level2.gettdx()+(level2.getwidth()-your_choice_level.getwidth())/2);
                your_choice_level.settdy(level2.gettdy()+(level2.getheight()-your_choice_level.getheight())/2);
                your_choice_level.render(NULL);

            }



}

