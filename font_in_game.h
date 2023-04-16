#ifndef FONT_IN_GAME_H_INCLUDED
#define FONT_IN_GAME_H_INCLUDED
#include"texture.h"
#include <string>
#include<vector>
#include<algorithm>
TTF_Font* Font_Title_of_tutorial_menu = NULL;
TTF_Font* Font_word = NULL;
Ltexture Tilte_of_bg_tutorial_Menu;

TTF_Font* Font_of_tilte_in_main_interface=NULL;
Ltexture SANS;
Ltexture V;
Ltexture S;
Ltexture CHARA;
SDL_Color SANS_AND_V_text_Color = { 255, 242, 50 };
SDL_Color CHARA_AND_S_text_color ={255,242,0};
bool does_tilte_in_main_interface_appear=false;




#endif // FONT_IN_GAME_H_INCLUDED

void set_tutorial_font(Ltexture Tilte_of_bg_tutorial_Menu,TTF_Font* Font_Title_of_tutorial_menu){
     Font_Title_of_tutorial_menu = TTF_OpenFont( "font/title.ttf", 50);
     	if( Font_Title_of_tutorial_menu == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );

	}
	else{
       SDL_Color tutorial_text_Color = { 34, 177, 76 };
       Tilte_of_bg_tutorial_Menu.loadFromRenderedText("TUTORIAL",tutorial_text_Color,Font_Title_of_tutorial_menu);
       Tilte_of_bg_tutorial_Menu.settdx(352);
       Tilte_of_bg_tutorial_Menu.settdy(32);
       Tilte_of_bg_tutorial_Menu.render(NULL);
	}

}

void set_title_for_main_interface_of_game(bool does_tilte_in_main_interface_appear,SDL_Color SANS_AND_V_text_Color,
                                          SDL_Color CHARA_AND_S_text_color){


     Font_of_tilte_in_main_interface=TTF_OpenFont( "font/title.ttf", 70);
     	if( Font_of_tilte_in_main_interface == NULL  )
	{
		printf( "Failed to load SANS font! SDL_ttf Error: %s\n", TTF_GetError() );

	}
	else{



         SANS.loadFromRenderedText("SANS",SANS_AND_V_text_Color,Font_of_tilte_in_main_interface);
         CHARA.loadFromRenderedText("CHARA",CHARA_AND_S_text_color,Font_of_tilte_in_main_interface);
           S.loadFromRenderedText("S",CHARA_AND_S_text_color,Font_of_tilte_in_main_interface);

        V.loadFromRenderedText("V",SANS_AND_V_text_Color,Font_of_tilte_in_main_interface);




        if(does_tilte_in_main_interface_appear){

          if(SANS.gettdx()<=1080/2+150){
             SANS.settdx(1080/2+150);
          }
         else{
            SANS.settdx(SANS.gettdx()-10);

          }


          if(CHARA.gettdx()>=100){
             CHARA.settdx(100);
          }
         else{
            CHARA.settdx(CHARA.gettdx()+10);
          }



          if(S.gettdx()<=200+CHARA.getwidth()){
             S.settdx(200+CHARA.getwidth());
          }
         else{

            S.settdx(S.gettdx()-20);
          }

          if(V.gettdx()>=100+CHARA.getwidth()){
             V.settdx(100+CHARA.getwidth());
          }
         else{
            V.settdx(V.gettdx()+20);
          }

          SANS.render(NULL);
          V.render(NULL);
          S.render(NULL);
          CHARA.render(NULL);



       }
       else{

       SANS.settdx(1080);
       SANS.settdy(680/2-125/3);




       CHARA.settdx(0);
       CHARA.settdy(100);


       V.settdx(0);
       V.settdy(CHARA.gettdy()+CHARA.getheight());


        S.settdx(1080);
        S.settdy(V.gettdy()+30);



       }




   }
}


