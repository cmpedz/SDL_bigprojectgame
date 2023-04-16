#ifndef mcharacter2
#define mcharacter2
#include"texture.h"
 const int quatity_of_frame_character2=2;
 SDL_Rect character2_clip[quatity_of_frame_character2];
 Ltexture character2;
 int character2_frame=0;
 int tdx_character2=1000;
 int tdy_character2=height_of_screen/4*3;
 const int quatity_of_frame_skill1_AI=7;
 int skill_attack_directly_of_AI_frame=0;
 SDL_Rect skill1_of_AI_clip[ quatity_of_frame_skill1_AI];
 Ltexture skill1_of_AI;

#endif // character
void reset_ch2(){


  character2_frame=0;
  tdx_character2=1000;
  tdy_character2=height_of_screen/4*3;
  skill_attack_directly_of_AI_frame=0;

}


void AI(int tdx_character2, int tdy_character2,int character2_frame,bool r,bool l){

         character2_clip[0].h=29;
         character2_clip[0].w=21;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=29;
         character2_clip[1].w=21;
         character2_clip[1].x=21;
         character2_clip[1].y=0;
        character2.settdx(tdx_character2);
        character2.settdy(tdy_character2);
        character2.setheight(60);
        character2.setwidth(36);
        if(r){
           character2.loadtexture("image/chara_moving_right.bmp");

        }
        if(l){
          character2.loadtexture("image/chara_moving_left.bmp");
        }

        character2.render(&character2_clip[character2_frame/10]);


      }
 void AI_skill1(long long AI_frame,Ltexture skill1_of_AI,Ltexture character1,SDL_Rect skill1_of_AI_clip[],
                int time_appearing_of_skill1_from_AI,long long saving_time_skill1_of_AI,long long time_in_game){
        skill1_of_AI.loadtexture("image/chara_hit_directly.bmp");
        skill1_of_AI.setheight(45);
        skill1_of_AI.setwidth(10);
        skill1_of_AI.settdx(character1.gettdx()+5);
        skill1_of_AI.settdy(character1.gettdy()+5);

        if(AI_frame==0){
           skill1_of_AI.setheight(5);
           skill1_of_AI.setwidth(5);
        }
        skill1_of_AI_clip[0].h=15;
        skill1_of_AI_clip[0].w=15;
        skill1_of_AI_clip[0].x=375;
        skill1_of_AI_clip[0].y=400;

         if(AI_frame==1){
           skill1_of_AI.setheight(6);
           skill1_of_AI.setwidth(12);
        }
        skill1_of_AI_clip[1].h=55;
        skill1_of_AI_clip[1].w=30;
        skill1_of_AI_clip[1].x=375+15+30;
        skill1_of_AI_clip[1].y=400;

        if(AI_frame==2){
           skill1_of_AI.setheight(24);
           skill1_of_AI.setwidth(4);
        }
        skill1_of_AI_clip[2].h=180;
        skill1_of_AI_clip[2].w=30;
        skill1_of_AI_clip[2].x=375+15+30+30+20;
        skill1_of_AI_clip[2].y=400;

         if(AI_frame==3){
           skill1_of_AI.setheight(60);
           skill1_of_AI.setwidth(10);
        }
        skill1_of_AI_clip[3].h=300;
        skill1_of_AI_clip[3].w=45;
        skill1_of_AI_clip[3].x=375+15+30+30+20+30+60;
        skill1_of_AI_clip[3].y=400;

        if(AI_frame==4){
           skill1_of_AI.setheight(60);
           skill1_of_AI.setwidth(30);
        }
        skill1_of_AI_clip[4].h=452;
        skill1_of_AI_clip[4].w=184;
        skill1_of_AI_clip[4].x=375+15+30+30+20+30+60+45+70;
        skill1_of_AI_clip[4].y=400;

        if(AI_frame==5){
           skill1_of_AI.setheight(40);
           skill1_of_AI.setwidth(20);
        }
        skill1_of_AI_clip[5].h=260;
        skill1_of_AI_clip[5].w=106;
        skill1_of_AI_clip[5].x=375+15+30+30+20+30+60+45+70+184;
        skill1_of_AI_clip[5].y=400;

        if(AI_frame==6){
           skill1_of_AI.setheight(10);
           skill1_of_AI.setwidth(20);
        }

        skill1_of_AI_clip[6].h=55;
        skill1_of_AI_clip[6].w=106;
        skill1_of_AI_clip[6].x=375+15+30+30+20+30+60+45+70+184+106+99;
        skill1_of_AI_clip[6].y=400;



         skill1_of_AI.render(&skill1_of_AI_clip[(SDL_GetTicks()-time_in_game-time_appearing_of_skill1_from_AI+saving_time_skill1_of_AI)/200]);

 }

