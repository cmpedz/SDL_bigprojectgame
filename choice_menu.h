#ifndef CHOICE_MENU_H_INCLUDED
#define CHOICE_MENU_H_INCLUDED
#include"texture.h"
#include"button.h"
Ltexture choice_menu;
Ltexture white_bg;

Ltexture choose_map;
button choose_map_button;

Ltexture choose_skin;
button choose_skin_button;

Ltexture choose_level;
button choose_level_button;

TTF_Font* Font_Title_of_choose_menu = NULL;
SDL_Color choose_menu_text_color ={237,28,36};
Ltexture SKIN;
Ltexture MAP;
Ltexture LEVEL;


Ltexture quit_choice_menu;
const int quit_choice_menu_quatities=2;
int quit_choice_menu_frame=0;
SDL_Rect quit_choice_menu_clip[quit_choice_menu_quatities];
button button_quit_choice_menu;

Ltexture continue_choice_menu;
const int continue_choice_menu_quatities=2;
int continue_choice_menu_frame=0;
SDL_Rect continue_choice_menu_clip[continue_choice_menu_quatities];
button button_continue_choice_menu;

#endif // CHOICE_MENU_H_INCLUDED

void set_value_for_choice_menu(){

       Font_Title_of_choose_menu = TTF_OpenFont( "font/title.ttf", 50);

     quit_choice_menu.free();
     continue_choice_menu.free();
     choice_menu.free();
     white_bg.free();
     choose_map.free();
     choose_level.free();
     choose_skin.free();

     white_bg.loadtexture("image/it_is_just_white.bmp");
     white_bg.setheight(420);
     white_bg.setwidth(320);
     white_bg.settdx(0);
     white_bg.settdy(0);



     choice_menu.loadtexture("image/bg_choice_menu.bmp");
     choice_menu.settdx(0);
     choice_menu.settdy(0);
     choice_menu.setheight(680);
     choice_menu.setwidth(1080);

     choose_map.loadtexture("image/map.bmp");
     choose_map.settdx(45);
     choose_map.settdy(100);
     choose_map.setheight(400);
     choose_map.setwidth(300);
     choose_map_button.setPosition(choose_map.gettdx(),choose_map.gettdy());
      MAP.loadFromRenderedText("MAP",choose_menu_text_color,Font_Title_of_choose_menu);

     choose_skin.loadtexture("image/choose_skin.bmp");
     choose_skin.settdx(45+choose_map.gettdx()+choose_map.getwidth());
     choose_skin.settdy(100);
     choose_skin.setheight(400);
     choose_skin.setwidth(300);
     choose_skin_button.setPosition(choose_skin.gettdx(),choose_skin.gettdy());
     SKIN.loadFromRenderedText("SKIN",choose_menu_text_color,Font_Title_of_choose_menu);


     choose_level.loadtexture("image/level.bmp");
     choose_level.settdx(45+choose_skin.gettdx()+choose_skin.getwidth());
     choose_level.settdy(100);
     choose_level.setheight(400);
     choose_level.setwidth(300);
     choose_level_button.setPosition(choose_level.gettdx(),choose_level.gettdy());
      LEVEL.loadFromRenderedText("LEVEL",choose_menu_text_color,Font_Title_of_choose_menu);

     quit_choice_menu.setheight(100);
     quit_choice_menu.setwidth(300);
     quit_choice_menu.loadtexture("image/demo_quit.bmp");
     button_quit_choice_menu.setPosition(0,680-quit_choice_menu.getheight()-20);
     quit_choice_menu.settdx(button_quit_choice_menu.gettdx());
     quit_choice_menu.settdy(button_quit_choice_menu.gettdy());

     for(int i=0;i<quit_choice_menu_quatities;i++){
         quit_choice_menu_clip[i].h=134;
         quit_choice_menu_clip[i].w=338+4*i;
         quit_choice_menu_clip[i].y=0;
         quit_choice_menu_clip[i].x=0+(338+128)*i;
     }



     continue_choice_menu.setheight(100);
     continue_choice_menu.setwidth(300);
     continue_choice_menu.loadtexture("image/demo_continue.bmp");
     button_continue_choice_menu.setPosition(1080-continue_choice_menu.getwidth()-20,680-continue_choice_menu.getheight()-20);
     continue_choice_menu.settdx(button_continue_choice_menu.gettdx());
     continue_choice_menu.settdy(button_continue_choice_menu.gettdy());

      for(int i=0;i<continue_choice_menu_quatities;i++){
        continue_choice_menu_clip[i].h=127;
        continue_choice_menu_clip[i].w=338;
        continue_choice_menu_clip[i].y=0;
        continue_choice_menu_clip[i].x=0+(338+134)*i;
     }






}


void set_choice_menu_active(bool &does_choice_menu_appear,SDL_Event &e,int& tdx_of_my_mouse,
                            int & tdy_of_my_mouse,bool& reset_everything_in_main_interface,bool &reset_everything_in_game,bool &quit,
                            bool &thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game,
                            TTF_Font* Font_Title_of_choose_menu,SDL_Color choose_menu_text_color,bool &does_choose_skin_interface_appear,
                            bool &does_choose_map_appear){

     choice_menu.render(NULL);

     quit_choice_menu.render(&quit_choice_menu_clip[quit_choice_menu_frame]);
     continue_choice_menu.render(&continue_choice_menu_clip[continue_choice_menu_frame]);

     set_value_for_choice_menu();
     SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);



     SDL_PollEvent(&e);

             if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

            //set button quit for choice menu

           if(tdx_of_my_mouse>=button_quit_choice_menu.gettdx() &&
              tdx_of_my_mouse <=button_quit_choice_menu.gettdx()+quit_choice_menu.getwidth()&&
              tdy_of_my_mouse>=button_quit_choice_menu.gettdy() &&
              tdy_of_my_mouse <=button_quit_choice_menu.gettdy()+quit_choice_menu.getheight()){
                 quit_choice_menu_frame=1;



                 if(e.type==SDL_MOUSEBUTTONUP){

                    does_choice_menu_appear=false;
                    thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
                    reset_everything_in_main_interface=true;
                 }

              }
            else{
                quit_choice_menu_frame=0;
            }


             //set button continue for choice menu
             if(tdx_of_my_mouse>=button_continue_choice_menu.gettdx() &&
              tdx_of_my_mouse <=button_continue_choice_menu.gettdx()+continue_choice_menu.getwidth()&&
              tdy_of_my_mouse>=button_continue_choice_menu.gettdy() &&
              tdy_of_my_mouse <=button_continue_choice_menu.gettdy()+continue_choice_menu.getheight()){
                 continue_choice_menu_frame=1;
                 if(e.type==SDL_MOUSEBUTTONUP){
                    does_choice_menu_appear=false;
                    thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=true;
                    reset_everything_in_game=true;
                 }

              }
            else{
                continue_choice_menu_frame=0;
            }


        if(tdx_of_my_mouse>=choose_skin_button.gettdx() &&
              tdx_of_my_mouse <=choose_skin_button.gettdx()+choose_skin.getwidth()&&
              tdy_of_my_mouse>=choose_skin_button.gettdy() &&
              tdy_of_my_mouse <=choose_skin_button.gettdy()+choose_skin.getheight()){


               if(e.type==SDL_MOUSEBUTTONUP){
                    does_choose_skin_interface_appear=true;
                    does_choice_menu_appear=false;
               }


            }








            //set button choose map active
            if(tdx_of_my_mouse>=choose_map_button.gettdx() &&
              tdx_of_my_mouse <=choose_map_button.gettdx()+choose_map.getwidth()&&
              tdy_of_my_mouse>=choose_map_button.gettdy() &&
              tdy_of_my_mouse <=choose_map_button.gettdy()+choose_map.getheight()){

               white_bg.settdx(choose_map_button.gettdx()-10);
               white_bg.settdy(choose_map_button.gettdy()-10);
               white_bg.render(NULL);


               MAP.settdx(choose_map_button.gettdx()+(choose_map.getwidth()-MAP.getwidth())/2);
               MAP.settdy(choose_map_button.gettdy()-10-MAP.getheight());
               MAP.render(NULL);

               if(e.type==SDL_MOUSEBUTTONUP){
                    does_choose_map_appear=true;
                    does_choice_menu_appear=false;
               }

            }


            // set choose skin button active
            if(tdx_of_my_mouse>=choose_skin_button.gettdx() &&
              tdx_of_my_mouse <=choose_skin_button.gettdx()+choose_skin.getwidth()&&
              tdy_of_my_mouse>=choose_skin_button.gettdy() &&
              tdy_of_my_mouse <=choose_skin_button.gettdy()+choose_skin.getheight()){

               white_bg.settdx(choose_skin_button.gettdx()-10);
               white_bg.settdy(choose_skin_button.gettdy()-10);
               white_bg.render(NULL);


               SKIN.settdx(choose_skin_button.gettdx()+(choose_skin.getwidth()-SKIN.getwidth())/2);
               SKIN.settdy(choose_skin_button.gettdy()-10-SKIN.getheight());
               SKIN.render(NULL);


            }


            if(tdx_of_my_mouse>=choose_level_button.gettdx() &&
              tdx_of_my_mouse <=choose_level_button.gettdx()+choose_map.getwidth()&&
              tdy_of_my_mouse>=choose_level_button.gettdy() &&
              tdy_of_my_mouse <=choose_level_button.gettdy()+choose_map.getheight()){

               white_bg.settdx(choose_level_button.gettdx()-10);
               white_bg.settdy(choose_level_button.gettdy()-10);
               white_bg.render(NULL);


               LEVEL.settdx(choose_level_button.gettdx()+(choose_level.getwidth()-LEVEL.getwidth())/2);
               LEVEL.settdy(choose_level_button.gettdy()-10-LEVEL.getheight());
               LEVEL.render(NULL);

            }


            choose_map.render(NULL);
            choose_level.render(NULL);
            choose_skin.render(NULL);
                            }




