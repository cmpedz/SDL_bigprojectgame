#ifndef CHOOSE_SKIN
#include"texture.h"
#include"button.h"

Ltexture bg_of_choose_skin;
Ltexture effect_choose_skin;
Ltexture skin1_text;
bool choose_skin1=true;
Ltexture skin2_text;
bool choose_skin2=false;
Ltexture point_player;
Ltexture point;

TTF_Font* Font_Title_of_choose_skin = NULL;
SDL_Color choose_skin_text_color ={237,28,36};
SDL_Color point_text_color ={34,177,76};
Ltexture your_choice;
TTF_Font* Font_choice = NULL;

Ltexture skin1;
button skin1_button;

Ltexture skin2;
button skin2_button;

Ltexture quit_choose_skin;
const int quit_choose_skin_quatities=2;
int quit_choose_skin_frame;
SDL_Rect quit_choose_skin_clip[quit_choose_skin_quatities];
button  button_quit_choose_skin;

#endif // CHOOSE_SKIN

string conversion_int_into_string(const int &number){
       vector<char> opposite_ans;
       string ans="";
       int number_=number;
       if(number_==0){
          ans="0";
       }
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


void reset_point(){

    point.free();

}


void set_value_for_bg_of_choosing_skin(){




    Font_Title_of_choose_skin = TTF_OpenFont( "font/title.ttf", 50);

    Font_choice = TTF_OpenFont( "font/title.ttf", 30);

    your_choice.loadFromRenderedText("YOUR CHOICE",choose_skin_text_color,Font_choice);
    skin1_text.loadFromRenderedText("SANS",choose_skin_text_color,Font_Title_of_choose_skin);
    skin2_text.loadFromRenderedText("ERROR SANS",choose_skin_text_color,Font_Title_of_choose_skin);
    point_player.loadFromRenderedText("YOUR POINT :",point_text_color,Font_choice);






     bg_of_choose_skin.loadtexture("image/bg_choice_menu.bmp");
     bg_of_choose_skin.settdx(0);
     bg_of_choose_skin.settdy(0);
     bg_of_choose_skin.setheight(680);
     bg_of_choose_skin.setwidth(1080);

     skin1.loadtexture("image/skin1.bmp");
     skin1.settdx(93);
     skin1.settdy(100);
     skin1.setwidth(400);
     skin1.setheight(400);
     skin1_button.setPosition(skin1.gettdx(),skin1.gettdy());

     skin2.loadtexture("image/skin2.bmp");
     skin2.settdx(93+skin1.gettdx()+skin1.getwidth());
     skin2.settdy(100);
     skin2.setwidth(400);
     skin2.setheight(400);
     skin2_button.setPosition(skin2.gettdx(),skin2.gettdy());


     effect_choose_skin.loadtexture("image/it_is_just_white.bmp");
     effect_choose_skin.setheight(420);
     effect_choose_skin.setwidth(420);
     effect_choose_skin.settdx(0);
     effect_choose_skin.settdy(0);



     quit_choose_skin.setheight(100);
     quit_choose_skin.setwidth(300);
     quit_choose_skin.loadtexture("image/demo_quit.bmp");
    button_quit_choose_skin.setPosition(0,680- quit_choose_skin.getheight()-20);
      quit_choose_skin.settdx(button_quit_choose_skin.gettdx());
      quit_choose_skin.settdy(button_quit_choose_skin.gettdy());

     for(int i=0;i<quit_choice_menu_quatities;i++){
          quit_choose_skin_clip[i].h=134;
         quit_choose_skin_clip[i].w=338+4*i;
          quit_choose_skin_clip[i].y=0;
          quit_choose_skin_clip[i].x=0+(338+128)*i;
     }





}



void set_choose_skin_active(int &tdx_of_my_mouse, int &tdy_of_my_mouse,SDL_Event e,
                            bool &does_choice_menu_appear,bool& does_choose_skin_interface_appear,
                            bool &quit,Ltexture point,int p){
     bg_of_choose_skin.render(NULL);
     quit_choose_skin.render(&quit_choose_skin_clip[quit_choose_skin_frame]);


     point.loadFromRenderedText(conversion_int_into_string(p),point_text_color,Font_choice);


    point_player.settdx(width_of_screen-point_player.getwidth()-50-point.getwidth()-20);
    point_player.settdy(height_of_screen-point_player.getheight()-20);
    point_player.render(NULL);




     point.settdy(point_player.gettdy());
     point.settdx(point_player.gettdx()+20+point_player.getwidth());

     point.render(NULL);





     SDL_GetMouseState(&tdx_of_my_mouse,&tdy_of_my_mouse);
     SDL_PollEvent(&e);

     if(e.type==SDL_QUIT){
        quit=true;
     }

     //set quit button in choose skin active

           if(tdx_of_my_mouse>=button_quit_choose_skin.gettdx() &&
              tdx_of_my_mouse <=button_quit_choose_skin.gettdx()+ quit_choose_skin.getwidth()&&
              tdy_of_my_mouse>=button_quit_choose_skin.gettdy() &&
              tdy_of_my_mouse <=button_quit_choose_skin.gettdy()+quit_choose_skin.getheight()){
                  quit_choose_skin_frame=1;

                  if(e.type==SDL_MOUSEBUTTONUP){
                     does_choose_skin_interface_appear=false;
                     does_choice_menu_appear=true;

                  }
            }
            else{
                 quit_choose_skin_frame=0;
            }

    //set effect choosing skin1 and skin2

    if(tdx_of_my_mouse>=  skin1_button.gettdx() &&
              tdx_of_my_mouse <=skin1_button.gettdx()+ skin1.getwidth()&&
              tdy_of_my_mouse>=skin1_button.gettdy() &&
              tdy_of_my_mouse <=skin1_button.gettdy()+skin1.getheight()){

                  effect_choose_skin.settdx(skin1.gettdx()-10);
                  effect_choose_skin.settdy(skin1.gettdy()-10);
                  effect_choose_skin.render(NULL);

               skin1_text.settdx(skin1_button.gettdx()+(skin1.getwidth()-skin1_text.getwidth())/2);
               skin1_text.settdy(skin1_button.gettdy()-10-skin1_text.getheight());
               skin1_text.render(NULL);

               if(e.type==SDL_MOUSEBUTTONUP){
                  choose_skin1=true;
                  choose_skin2=false;

               }
            }





     if(tdx_of_my_mouse>=  skin2_button.gettdx() &&
              tdx_of_my_mouse <=skin2_button.gettdx()+ skin2.getwidth()&&
              tdy_of_my_mouse>=skin2_button.gettdy() &&
              tdy_of_my_mouse <=skin2_button.gettdy()+skin2.getheight()){

                  effect_choose_skin.settdx(skin2.gettdx()-10);
                  effect_choose_skin.settdy(skin2.gettdy()-10);
                  effect_choose_skin.render(NULL);


              skin2_text.settdx(skin2_button.gettdx()+(skin2.getwidth()-skin2_text.getwidth())/2);
               skin2_text.settdy(skin2_button.gettdy()-10-skin2_text.getheight());
               skin2_text.render(NULL);

                 if(e.type==SDL_MOUSEBUTTONUP){
                  choose_skin2=true;
                  choose_skin1=false;
                  your_choice.settdx(skin2.gettdx()+(skin2.getheight()-your_choice.getheight())/2);
                  your_choice.render(NULL);

               }
            }



     skin1.render(NULL);
     skin2.render(NULL);

     //check the choice of player

            if(choose_skin1){
                your_choice.settdx(skin1.gettdx()+(skin1.getwidth()-your_choice.getwidth())/2);
                your_choice.settdy(skin1.gettdy()+(skin1.getheight()-your_choice.getheight())/2);
                your_choice.render(NULL);

            }

            if(choose_skin2){
                your_choice.settdx(skin2.gettdx()+(skin2.getwidth()-your_choice.getwidth())/2);
                your_choice.settdy(skin2.gettdy()+(skin2.getheight()-your_choice.getheight())/2);
                your_choice.render(NULL);

            }



}
