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
string conversion_int_into_string(const int &number){
       vector<char> opposite_ans;
       string ans="";
       int number_=number;
       while(number_!=0){
             opposite_ans.push_back(number_%10+48);
             number_=number_/10;

       }
       for(int i=0;i<(int)opposite_ans.size();i++){
           ans=ans+'h';
       }
       for(int i=0;i<(int)opposite_ans.size();i++){
           ans[i]=opposite_ans[(int)opposite_ans.size()-1-i];

       }

       return ans;
}


void set_tutorial_font(Ltexture Tilte_of_bg_tutorial_Menu,TTF_Font* Font_Title_of_tutorial_menu){
     Font_Title_of_tutorial_menu = TTF_OpenFont( "game_font_title.ttf", 50);
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


     Font_of_tilte_in_main_interface=TTF_OpenFont( "game_font_title.ttf", 70);
     	if( Font_of_tilte_in_main_interface == NULL  )
	{
		printf( "Failed to load SANS font! SDL_ttf Error: %s\n", TTF_GetError() );

	}
	else{

       SANS.loadFromRenderedText("SANS",SANS_AND_V_text_Color,Font_of_tilte_in_main_interface);
       SANS.settdx(1080/2+150);
       SANS.settdy(680/2-125/3);





       CHARA.loadFromRenderedText("CHARA",CHARA_AND_S_text_color,Font_of_tilte_in_main_interface);
       CHARA.settdx(100);
       CHARA.settdy(100);


       V.loadFromRenderedText("V",SANS_AND_V_text_Color,Font_of_tilte_in_main_interface);
       V.settdx(CHARA.gettdx()+CHARA.getwidth());
       V.settdy(CHARA.gettdy()+CHARA.getheight());

        S.loadFromRenderedText("S",CHARA_AND_S_text_color,Font_of_tilte_in_main_interface);
        S.settdx(V.gettdx()+V.getwidth()+30);
        S.settdy(V.gettdy()+30);


        if(does_tilte_in_main_interface_appear){

          SANS.render(NULL);
          V.render(NULL);
          S.render(NULL);
          CHARA.render(NULL);

       }




   }
}
void free_title_for_main_interface_of_game(){
      SANS.free();
     CHARA.free();
     V.free();
     S.free();
}


