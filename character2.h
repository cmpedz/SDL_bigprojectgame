#ifndef mcharacter2
#define mcharacter2
#include"texture.h"
 const int quatity_of_frame_character2=8;
 SDL_Rect character2_clip[quatity_of_frame_character2];
 Ltexture character2;
 int character2_frame=0;
 int character2_frame_jump=0;

 int tdx_character2=1000;
 int tdy_character2=height_of_screen/4*3;
 const int quatity_of_frame_skill1_AI=7;
 int skill_attack_directly_of_AI_frame=0;
 SDL_Rect skill1_of_AI_clip[ quatity_of_frame_skill1_AI];
 Ltexture skill1_of_AI;

 const int AI_get_hit_sprites=3;
 int AI_get_hit_frame=0;
 bool is_AI_hit_by_skill1_of_Player=false;
 bool is_AI_hit_by_skill2_of_Player=false;
 bool is_AI_hit_by_skill3_of_Player=false;


 const int AI_use_skilll3_sprites=6;
 int AI_use_skilll3_frame=0;
 bool Does_AI_use_skill3=false;


 bool delay_skill_of_AI=false;
 bool does_AI_miss=false;
 bool Does_AI_use_skill2=false;
 int character2_frame_miss=0;
 int character2_frame_skill2=0;

#endif // character
void reset_ch2(){


  character2_frame=0;
  tdx_character2=1000;
  tdy_character2=height_of_screen/4*3;
  skill_attack_directly_of_AI_frame=0;
  character2_frame_jump=0;
  character2_frame_miss=0;
  delay_skill_of_AI=false;
  does_AI_miss=false;
    Does_AI_use_skill2=false;
    character2_frame_skill2=0;
    is_AI_hit_by_skill1_of_Player=false;
    is_AI_hit_by_skill2_of_Player=false;
    is_AI_hit_by_skill3_of_Player=false;
    AI_get_hit_frame=0;
     AI_use_skilll3_frame=0;
     Does_AI_use_skill3=false;


}


void AI(int tdx_character2, int tdy_character2,int character2_frame,bool r,bool l,bool can_character2_jump,
        const int tdy_of_ground){


        character2.settdx(tdx_character2);
        character2.settdy(tdy_character2);
        character2.setheight(60);
        character2.setwidth(36);

    if(!(can_character2_jump || tdy_character2 < tdy_of_ground) && !does_AI_miss && !Does_AI_use_skill2 &&
       !(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player)&&
       !Does_AI_use_skill3){
    //set AI move r or l
        if(r){
         character2_clip[0].h=68;
         character2_clip[0].w=41;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=68;
         character2_clip[1].w=36;
         character2_clip[1].x=41+52;
         character2_clip[1].y=0;

         character2_clip[2].h=68;
         character2_clip[2].w=36;
         character2_clip[2].x=41+52*2+36;
         character2_clip[2].y=0;

         character2_clip[3].h=68;
         character2_clip[3].w=38;
         character2_clip[3].x=41+52*2+36*2+50;
         character2_clip[3].y=0;

         character2_clip[4].h=68;
         character2_clip[4].w=40;
         character2_clip[4].x=41+52*2+36*2+50+38+48;
         character2_clip[4].y=0;

         character2_clip[5].h=68;
         character2_clip[5].w=36;
         character2_clip[5].x=41+52*2+36*2+50+38+48+40+52;
         character2_clip[5].y=0;

         character2_clip[6].h=68;
         character2_clip[6].w=36;
         character2_clip[6].x=41+52*2+36*2+50+38+48+40+52+36+52;
         character2_clip[6].y=0;

         character2_clip[7].h=68;
         character2_clip[7].w=38;
         character2_clip[7].x=41+52*2+36*2+50+38+48+40+52+36+52+36+50;
         character2_clip[7].y=0;

           character2.loadtexture("image/chara_moving_right.bmp",255,255,255);

        }





        if(l){

            character2_clip[0].h=68;
            character2_clip[0].w=41;
            character2_clip[0].x=39+50+36+52+36+52+40+48+38+50+36+52+36+52;
            character2_clip[0].y=0;

            character2_clip[1].h=68;
            character2_clip[1].w=36;
            character2_clip[1].x=39+50+36+52+36+52+40+48+38+50+36+52;
            character2_clip[1].y=0;

            character2_clip[2].h=68;
            character2_clip[2].w=36;
            character2_clip[2].x=39+50+36+52+36+52+40+48+38+50;
            character2_clip[2].y=0;

            character2_clip[3].h=68;
            character2_clip[3].w=38;
            character2_clip[3].x=39+50+36+52+36+52+40+48;
            character2_clip[3].y=0;

            character2_clip[4].h=68;
            character2_clip[4].w=40;
            character2_clip[4].x=39+50+36+52+36+52;
            character2_clip[4].y=0;

            character2_clip[5].h=68;
            character2_clip[5].w=36;
            character2_clip[5].x=39+50+36+52;
            character2_clip[5].y=0;

            character2_clip[6].h=68;
            character2_clip[6].w=36;
            character2_clip[6].x=39+50;
            character2_clip[6].y=0;

            character2_clip[7].h=68;
            character2_clip[7].w=39;
            character2_clip[7].x=0;
            character2_clip[7].y=0;
            character2.loadtexture("image/chara_moving_left.bmp",255,255,255);
        }



        character2.render(&character2_clip[character2_frame/10]);
    }
    else{


        if(!does_AI_miss && !Does_AI_use_skill2
           && !(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player)
           && !Does_AI_use_skill3){
        //set sprite jumping for AI
         if(r){
         character2_clip[0].h=79;
         character2_clip[0].w=60;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=79;
         character2_clip[1].w=38;
         character2_clip[1].x=60+33;
         character2_clip[1].y=0;

         character2_clip[2].h=79;
         character2_clip[2].w=36;
         character2_clip[2].x=60+33+38+52;
         character2_clip[2].y=0;

         character2_clip[3].h=79;
         character2_clip[3].w=36;
         character2_clip[3].x=60+33+38+52+36+50;
         character2_clip[3].y=0;

         character2_clip[4].h=79;
         character2_clip[4].w=42;
         character2_clip[4].x=60+33+38+52+36+50+36+50;
         character2_clip[4].y=0;

         character2_clip[5].h=79;
         character2_clip[5].w=40;
         character2_clip[5].x=60+33+38+52+36+50+36+50+42+48;
         character2_clip[5].y=0;

         character2_clip[6].h=79;
         character2_clip[6].w=40;
         character2_clip[6].x=60+33+38+52+36+50+36+50+42+48+40+48;
         character2_clip[6].y=0;



           character2.loadtexture("image/chara_jump_right.bmp",255,255,255);

        }


        if(l){
         character2_clip[0].h=79;
         character2_clip[0].w=60;
         character2_clip[0].x=40+48+40+48+42+50+36+50+36+52+38+33;
         character2_clip[0].y=0;

         character2_clip[1].h=79;
         character2_clip[1].w=38;
         character2_clip[1].x=40+48+40+48+42+50+36+50+36+52;
         character2_clip[1].y=0;

         character2_clip[2].h=79;
         character2_clip[2].w=36;
         character2_clip[2].x=40+48+40+48+42+50+36+50;
         character2_clip[2].y=0;

         character2_clip[3].h=79;
         character2_clip[3].w=36;
         character2_clip[3].x=40+48+40+48+42+50;
         character2_clip[3].y=0;

         character2_clip[4].h=79;
         character2_clip[4].w=42;
         character2_clip[4].x=40+48+40+48;
         character2_clip[4].y=0;

         character2_clip[5].h=79;
         character2_clip[5].w=40;
         character2_clip[5].x=40+48;
         character2_clip[5].y=0;

         character2_clip[6].h=79;
         character2_clip[6].w=40;
         character2_clip[6].x=0;
         character2_clip[6].y=0;



           character2.loadtexture("image/chara_jump_left.bmp",255,255,255);

        }

        if(character2_frame_jump/10==0){
            character2.setheight(60);
            character2.setwidth(58);
        }
        character2.render(&character2_clip[character2_frame_jump/10]);

    }
    else{



    if(!Does_AI_use_skill2 && !Does_AI_use_skill3 &&
       !(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player)){
        //set sprite miss for AI
        character2.setwidth(60);
        character2.setheight(55);
          if(r){
         character2_clip[0].h=66;
         character2_clip[0].w=68;
         character2_clip[0].x=62+18+68+38+44+40+70+12;
         character2_clip[0].y=0;

         character2_clip[1].h=66;
         character2_clip[1].w=70;
         character2_clip[1].x=62+18+68+38+44+40;
         character2_clip[1].y=0;

         character2_clip[2].h=66;
         character2_clip[2].w=44;
         character2_clip[2].x=62+18+68+38;
         character2_clip[2].y=0;

         character2_clip[3].h=66;
         character2_clip[3].w=68;
         character2_clip[3].x=62+18;
         character2_clip[3].y=0;

         character2_clip[4].h=66;
         character2_clip[4].w=62;
         character2_clip[4].x=0;
         character2_clip[4].y=0;




           character2.loadtexture("image/chara_tele_right.bmp",255,255,255);

        }



         if(l){

         character2_clip[4].h=66;
         character2_clip[4].w=62;
         character2_clip[4].x=69+12+70+40+44+38+68+18;
         character2_clip[4].y=0;

         character2_clip[3].h=66;
         character2_clip[3].w=68;
         character2_clip[3].x=69+12+70+40+44+38;
         character2_clip[3].y=0;

         character2_clip[2].h=66;
         character2_clip[2].w=44;
         character2_clip[2].x=69+12+70+40;
         character2_clip[2].y=0;

         character2_clip[1].h=66;
         character2_clip[1].w=70;
         character2_clip[1].x=69+12;
         character2_clip[1].y=0;

         character2_clip[0].h=66;
         character2_clip[0].w=69;
         character2_clip[0].x=0;
         character2_clip[0].y=0;






           character2.loadtexture("image/chara_tele_left.bmp",255,255,255);

        }

        character2.render(&character2_clip[character2_frame_miss/10]);


        }
        else{

         if(!(is_AI_hit_by_skill1_of_Player || is_AI_hit_by_skill2_of_Player || is_AI_hit_by_skill3_of_Player) &&
            !Does_AI_use_skill3){
            //set sprite skill2 for AI

            if(r){
         character2_clip[0].h=96;
         character2_clip[0].w=84;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=96;
         character2_clip[1].w=78;
         character2_clip[1].x=84+78;
         character2_clip[1].y=0;

         character2_clip[2].h=96;
         character2_clip[2].w=69;
         character2_clip[2].x=84+78*2+90;
         character2_clip[2].y=0;

         character2_clip[3].h=96;
         character2_clip[3].w=108;
         character2_clip[3].x=84+78*2+90+69+90;
         character2_clip[3].y=0;

         character2_clip[4].h=96;
         character2_clip[4].w=98;
         character2_clip[4].x=84+78*2+90+69+90+108+60;
         character2_clip[4].y=0;

         character2_clip[5].h=96;
         character2_clip[5].w=98;
         character2_clip[5].x=84+78*2+90+69+90+108+60+98+60;
         character2_clip[5].y=0;

         character2_clip[6].h=96;
         character2_clip[6].w=50;
         character2_clip[6].x=84+78*2+90+69+90+108+60+98+60+98+62;
         character2_clip[6].y=0;

         character2_clip[7].h=96;
         character2_clip[7].w=38;
         character2_clip[7].x=84+78*2+90+69+90+108+60+98+60+98+62+50+112;
         character2_clip[7].y=0;

           character2.loadtexture("image/chara_use_skill2_r.bmp",255,255,255);

        }


        if(l){
         character2_clip[0].h=96;
         character2_clip[0].w=84;
         character2_clip[0].x=38+112+50+62+98+60+98+60+108+90+69+90+78+78;
         character2_clip[0].y=0;

         character2_clip[1].h=96;
         character2_clip[1].w=78;
         character2_clip[1].x=38+112+50+62+98+60+98+60+108+90+69+90;
         character2_clip[1].y=0;

         character2_clip[2].h=96;
         character2_clip[2].w=69;
         character2_clip[2].x=38+112+50+62+98+60+98+60+108+90;
         character2_clip[2].y=0;

         character2_clip[3].h=96;
         character2_clip[3].w=108;
         character2_clip[3].x=38+112+50+62+98+60+98+60;
         character2_clip[3].y=0;

         character2_clip[4].h=96;
         character2_clip[4].w=98;
         character2_clip[4].x=38+112+50+62+98+60;
         character2_clip[4].y=0;

         character2_clip[5].h=96;
         character2_clip[5].w=98;
         character2_clip[5].x=38+112+50+62;
         character2_clip[5].y=0;

         character2_clip[6].h=96;
         character2_clip[6].w=50;
         character2_clip[6].x=38+112;
         character2_clip[6].y=0;

         character2_clip[7].h=96;
         character2_clip[7].w=38;
         character2_clip[7].x=0;             //84+78*2+90+69+90+108+60+98+60+98+62+50+112
         character2_clip[7].y=0;

           character2.loadtexture("image/chara_use_skill2_l.bmp",255,255,255);

        }

                character2.setheight(80);
                character2.setwidth(70);

             if(character2_frame_skill2/5>=3 && character2_frame_skill2/5<=5){
                character2.setheight(80);
                character2.setwidth(80);
             }
            character2.render(&character2_clip[character2_frame_skill2/5]);

        }
        else{

        if(!Does_AI_use_skill3){
           //set sprites for AI when he/she is hit
        if(r){

         character2_clip[0].h=70;
         character2_clip[0].w=52;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=70;
         character2_clip[1].w=56;
         character2_clip[1].x=52+34;
         character2_clip[1].y=0;

         character2_clip[2].h=70;
         character2_clip[2].w=44;
         character2_clip[2].x=52+34+56+25;
         character2_clip[2].y=0;

         character2.loadtexture("image/chara_get_hit_right.bmp",255,255,255);







        }

        if(l){

         character2_clip[0].h=70;
         character2_clip[0].w=52;
         character2_clip[0].x=44+25+56+34;
         character2_clip[0].y=0;

         character2_clip[1].h=70;
         character2_clip[1].w=56;
         character2_clip[1].x=44+25;
         character2_clip[1].y=0;

         character2_clip[2].h=70;
         character2_clip[2].w=44;
         character2_clip[2].x=0;
         character2_clip[2].y=0;

           character2.loadtexture("image/chara_get_hit_left.bmp",255,255,255);





        }



             character2.setheight(60);
             character2.setwidth(58);
             character2.render(&character2_clip[AI_get_hit_frame/5]);

        }
        else{
            //set sprites AI use skill 3

            if(r){
         character2_clip[0].h=81;
         character2_clip[0].w=48;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=81;
         character2_clip[1].w=78;
         character2_clip[1].x=48+43;
         character2_clip[1].y=0;

         character2_clip[2].h=81;
         character2_clip[2].w=70;
         character2_clip[2].x=48+43+78+20;
         character2_clip[2].y=0;

         character2_clip[3].h=81;
         character2_clip[3].w=78;
         character2_clip[3].x=48+43+78+20+70+33;
         character2_clip[3].y=0;

         character2_clip[4].h=81;
         character2_clip[4].w=74;
         character2_clip[4].x=48+43+78+20+70+33+78+43;
         character2_clip[4].y=0;

         character2_clip[5].h=81;
         character2_clip[5].w=52;
         character2_clip[5].x=48+43+78+20+70+33+78+43+74+33;
         character2_clip[5].y=0;





           character2.loadtexture("image/chara_use_skill3_r.bmp",255,255,255);

        }


        if(l){
         character2_clip[0].h=81;
         character2_clip[0].w=48;
         character2_clip[0].x=43+78+20+70+33+78+43+74+33+52;
         character2_clip[0].y=0;

         character2_clip[1].h=81;
         character2_clip[1].w=78;
         character2_clip[1].x=20+70+33+78+43+74+33+52;
         character2_clip[1].y=0;

         character2_clip[2].h=81;
         character2_clip[2].w=70;
         character2_clip[2].x=33+78+43+74+33+52;
         character2_clip[2].y=0;

         character2_clip[3].h=81;
         character2_clip[3].w=78;
         character2_clip[3].x=52+43+74+33;
         character2_clip[3].y=0;

         character2_clip[4].h=81;
         character2_clip[4].w=74;
         character2_clip[4].x=52+33;
         character2_clip[4].y=0;

         character2_clip[5].h=81;
         character2_clip[5].w=52;
         character2_clip[5].x=0;
         character2_clip[5].y=0;





           character2.loadtexture("image/chara_use_skill3_l.bmp",255,255,255);

        }

        if(AI_use_skilll3_frame/5 == 0 && AI_use_skilll3_frame/5 ==5){
          character2.setheight(70);
          character2.setwidth(46);
        }
        else{
            character2.setheight(70);
          character2.setwidth(67);
        }

        character2.render(&character2_clip[AI_use_skilll3_frame/5]);


        }


        }

        }

    }




    }


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

