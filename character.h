#ifndef character
#define character
#include"texture.h"
#include"gravity.h"
const int quatity_of_frame_character1=8;
const int quatity_of_frame_character1_get_damage=2;
const int quatity_of_frame_character1_use_skill1=6;
const int quatity_of_frame_character1_use_skill2=3;
const int quatity_of_frame_character1_use_skill3=4;

SDL_Rect character1_clip[quatity_of_frame_character1];
int character1_frame=0;
int character_frame_jump=0;

int character_frame_get_dam=0;
bool sprite_for_ch_get_dam_by_skill1_of_AI=false;
bool sprite_for_ch_get_dam_by_skill2_of_AI=false;
bool sprite_for_ch_get_dam_by_skill3_of_AI=false;

int character_frame_use_skill1=0;
bool can_character1_run_after_using_skill1=true;

int character_frame_use_skill2=0;
bool can_character1_run_after_using_skill2=true;

int character_frame_use_skill3=0;
bool can_character1_run_after_using_skill3=true;

int tdx_character1=0;
int tdy_character1=height_of_screen/4*3;
Ltexture character1;
double saving_time_jumping_when_stopping_game1=0;

  bool can_character1_jump=false;
  double set_time_in_the_air_of_character1=0;
  double v_of_character1=0;

bool delay_skill_of_player=false;


#endif // character
void reset_ch1(){
    character1_frame=0;
    tdx_character1=0;
    tdy_character1=height_of_screen/4*3;

    saving_time_jumping_when_stopping_game1=0;

     can_character1_jump=false;
        set_time_in_the_air_of_character1=0;
        v_of_character1=0;
        delay_skill_of_player=false;

         character1_frame=0;
        character_frame_jump=0;

        character_frame_get_dam=0;
        sprite_for_ch_get_dam_by_skill1_of_AI=false;
        sprite_for_ch_get_dam_by_skill2_of_AI=false;
        sprite_for_ch_get_dam_by_skill3_of_AI=false;

        character_frame_use_skill1=0;
        can_character1_run_after_using_skill1=true;

        character_frame_use_skill2=0;
        can_character1_run_after_using_skill2=true;

        character_frame_use_skill3=0;
        can_character1_run_after_using_skill3=true;


}
void character_1(int tdx_character1,int tdy_character1,int character1_frame,bool r,bool l,bool choose_skin1,
                 bool choose_skin2,bool can_character1_jump,const int tdy_of_ground,bool sprite_for_ch_get_dam_by_skill1_of_AI,
                 bool sprite_for_ch_get_dam_by_skill2_of_AI,bool sprite_for_ch_get_dam_by_skill3_of_AI,
                 bool can_character1_run_after_using_skill1,bool can_character1_run_after_using_skill2,
                 bool can_character1_run_after_using_skill3){



          if(choose_skin1){







        character1.settdx(tdx_character1);
        character1.settdy(tdy_character1);
        character1.setheight(60); //60
        character1.setwidth(36);  //36
        character1.loadtexture("image/dust_sans_mvr.bmp");

        //set sprite for charater jump
        if((can_character1_jump || tdy_character1 < tdy_of_ground) && !(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI
            || sprite_for_ch_get_dam_by_skill3_of_AI) && can_character1_run_after_using_skill1 &&
           can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){


            if(r){

         character1_clip[0].h=41;
         character1_clip[0].w=21;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

         character1_clip[1].h=41;
         character1_clip[1].w=21;
         character1_clip[1].x=21+7;
         character1_clip[1].y=0;

         character1_clip[2].h=41;
         character1_clip[2].w=22;
         character1_clip[2].x=21*2+7+8;
         character1_clip[2].y=0;

          character1_clip[3].h=41;
         character1_clip[3].w=20;
         character1_clip[3].x=21*2+22+7+8+6;
         character1_clip[3].y=0;


          character1_clip[4].h=41;
         character1_clip[4].w=20;
         character1_clip[4].x=21*2+20+22+7+8+6+9;
         character1_clip[4].y=0;

          character1_clip[5].h=41;
         character1_clip[5].w=20;
         character1_clip[5].x=21*2+20*2+22+7+8+6+9+12;
         character1_clip[5].y=0;

          character1_clip[6].h=41;
         character1_clip[6].w=21;
         character1_clip[6].x=21*2+20*3+22+7+8+6+9+12+14;
         character1_clip[6].y=0;

          character1_clip[7].h=41;
         character1_clip[7].w=21;
         character1_clip[7].x=21*3+20*3+22+7+8+6+9+12+14+9;
         character1_clip[7].y=0;




                 character1.loadtexture("image/dust_sans_jump_r.bmp");
            }


            if(l){


         character1_clip[7].h=41;
         character1_clip[7].w=21;
         character1_clip[7].x=0;
         character1_clip[7].y=0;

         character1_clip[6].h=41;
         character1_clip[6].w=21;
         character1_clip[6].x=21+8;
         character1_clip[6].y=0;

         character1_clip[5].h=41;
         character1_clip[5].w=20;
         character1_clip[5].x=21*2+8+14;
         character1_clip[5].y=0;

          character1_clip[4].h=41;
         character1_clip[4].w=20;
         character1_clip[4].x=21*2+20+8+14+12;
         character1_clip[4].y=0;


          character1_clip[3].h=41;
         character1_clip[3].w=20;
         character1_clip[3].x=21*2+20*2+8+14+12+9;
         character1_clip[3].y=0;

          character1_clip[2].h=41;
         character1_clip[2].w=22;
         character1_clip[2].x=21*2+20*3+8+14+12+9+6;
         character1_clip[2].y=0;

          character1_clip[1].h=41;
         character1_clip[1].w=21;
         character1_clip[1].x=21*2+20*3+22+8+14+12+9+6+8;
         character1_clip[1].y=0;

          character1_clip[0].h=41;
         character1_clip[0].w=21;
         character1_clip[0].x=21*3+20*3+22+8+14+12+9+6+8+7;
         character1_clip[0].y=0;







                 character1.loadtexture("image/dust_sans_jump_l.bmp");
            }


             character1.render(&character1_clip[character_frame_jump/10]);

        }

        else{


        //set sprite for ch mv right or left

        if(!(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI || sprite_for_ch_get_dam_by_skill3_of_AI) &&
           can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){
        if(r){

         character1_clip[0].h=40;
         character1_clip[0].w=20;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

         character1_clip[1].h=40;
         character1_clip[1].w=20;
         character1_clip[1].x=20+9;
         character1_clip[1].y=0;

         character1_clip[2].h=40;
         character1_clip[2].w=20;
         character1_clip[2].x=20*2+9+8;
         character1_clip[2].y=0;

          character1_clip[3].h=40;
         character1_clip[3].w=20;
         character1_clip[3].x=20*3+9+8+11;
         character1_clip[3].y=0;


          character1_clip[4].h=40;
         character1_clip[4].w=20;
         character1_clip[4].x=20*4+9+8+11+6;
         character1_clip[4].y=0;

          character1_clip[5].h=40;
         character1_clip[5].w=20;
         character1_clip[5].x=20*5+9+8+11+6+9;
         character1_clip[5].y=0;

          character1_clip[6].h=40;
         character1_clip[6].w=20;
         character1_clip[6].x=20*6+9+8+11+6+9+10;
         character1_clip[6].y=0;

          character1_clip[7].h=40;
         character1_clip[7].w=20;
         character1_clip[7].x=20*7+9+8+11+6+9+10+9;
         character1_clip[7].y=0;



           character1.loadtexture("image/dust_sans_mvr.bmp");

        }
        if(l){



         character1_clip[0].h=40;
         character1_clip[0].w=20;
         character1_clip[0].x=20*6+21+13+12+9+7+11+9+17;
         character1_clip[0].y=0;

         character1_clip[1].h=40;
         character1_clip[1].w=21;
         character1_clip[1].x=20*6+13+12+9+7+11+9;
         character1_clip[1].y=0;

         character1_clip[2].h=40;
         character1_clip[2].w=20;
         character1_clip[2].x=20*5+13+12+9+7+11;
         character1_clip[2].y=0;

          character1_clip[3].h=40;
         character1_clip[3].w=20;
         character1_clip[3].x=20*4+13+12+9+7;
         character1_clip[3].y=0;


          character1_clip[4].h=40;
         character1_clip[4].w=20;
         character1_clip[4].x=20*3+13+12+9;
         character1_clip[4].y=0;

          character1_clip[5].h=40;
         character1_clip[5].w=20;
         character1_clip[5].x=20*2+13+12;
         character1_clip[5].y=0;

          character1_clip[6].h=40;
         character1_clip[6].w=20;
         character1_clip[6].x=20+13;
         character1_clip[6].y=0;

          character1_clip[7].h=40;
         character1_clip[7].w=20;
         character1_clip[7].x=0;
         character1_clip[7].y=0;





          character1.loadtexture("image/dust_sans_mvl.bmp");
        }


         character1.render(&character1_clip[character1_frame/5]);



        }




        else{


        //set sprite when character is damaged
        if(can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2
           && can_character1_run_after_using_skill3){
        character1.setheight(60);
        character1.setwidth(48);

        if(r){


         character1_clip[1].h=35;
         character1_clip[1].w=28;
         character1_clip[1].x=0;
         character1_clip[1].y=0;

          character1_clip[0].h=35;
         character1_clip[0].w=30;
         character1_clip[0].x=28+14;
         character1_clip[0].y=0;





          character1.loadtexture("image/dust_sans_is_damaged_r.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }

         if(l){
         character1_clip[0].h=35;
         character1_clip[0].w=30;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

          character1_clip[1].h=35;
         character1_clip[1].w=28;
         character1_clip[1].x=30+14;
         character1_clip[1].y=0;




          character1.loadtexture("image/dust_sans_is_damaged_l.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }



        }





        else{

            if(can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill1
            if(r){
                character1_clip[0].h=40;
                character1_clip[0].w=22;
                character1_clip[0].x=0;
                character1_clip[0].y=0;

                character1_clip[1].h=40;
                character1_clip[1].w=21;
                character1_clip[1].x=22+14;
                character1_clip[1].y=0;


                character1_clip[2].h=40;
                character1_clip[2].w=27;
                character1_clip[2].x=22+14+21+10;
                character1_clip[2].y=0;

                character1_clip[3].h=40;
                character1_clip[3].w=34;
                character1_clip[3].x=22+14+21+10+27+4;
                character1_clip[3].y=0;

                character1_clip[4].h=40;
                character1_clip[4].w=29;
                character1_clip[4].x=22+14+21+10+27+4+34+3;
                character1_clip[4].y=0;

                character1_clip[5].h=40;
                character1_clip[5].w=22;
                character1_clip[5].x=22+14+21+10+27+4+34+3+29+10;
                character1_clip[5].y=0;


                character1.loadtexture("image/dust_sans_use_skill1_r.bmp");

            }


             if(l){
               character1_clip[0].h=40;
                character1_clip[0].w=22;
                character1_clip[0].x=22+10+29+3+34+4+27+10+21+14;
                character1_clip[0].y=0;

                character1_clip[1].h=40;
                character1_clip[1].w=21;
                character1_clip[1].x=22+10+29+3+34+4+27+10;
                character1_clip[1].y=0;


                character1_clip[2].h=40;
                character1_clip[2].w=27;
                character1_clip[2].x=22+10+29+3+34+4;
                character1_clip[2].y=0;

                character1_clip[3].h=40;
                character1_clip[3].w=34;
                character1_clip[3].x=22+10+29+3;
                character1_clip[3].y=0;

                character1_clip[4].h=40;
                character1_clip[4].w=29;
                character1_clip[4].x=22+10;
                character1_clip[4].y=0;

                character1_clip[5].h=40;
                character1_clip[5].w=22;
                character1_clip[5].x=0;          //22+14+21+10+27+4+34+3+29+10
                character1_clip[5].y=0;

                character1.loadtexture("image/dust_sans_use_skill1_l.bmp");



            }

            if(character_frame_use_skill1/5==2){
                character1.setheight(60);
                character1.setwidth(58);

            }

            character1.render(&character1_clip[character_frame_use_skill1/5]);



        }

        else{


        if(can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill2
             if(r){
                character1_clip[2].h=40;
                character1_clip[2].w=28;
                character1_clip[2].x=25+5+35+5;
                character1_clip[2].y=0;

                character1_clip[1].h=40;
                character1_clip[1].w=35;
                character1_clip[1].x=25+5;
                character1_clip[1].y=0;

                character1_clip[0].h=40;
                character1_clip[0].w=25;
                character1_clip[0].x=0;
                character1_clip[0].y=0;


                character1.loadtexture("image/dust_sans_use_skill2_r.bmp");
             }

              if(l){
                character1_clip[2].h=40;
                character1_clip[2].w=28;
                character1_clip[2].x=0;
                character1_clip[2].y=0;

                character1_clip[1].h=40;
                character1_clip[1].w=35;
                character1_clip[1].x=28+6;
                character1_clip[1].y=0;

                character1_clip[0].h=40;
                character1_clip[0].w=25;
                character1_clip[0].x=28+6+35+5;
                character1_clip[0].y=0;


                character1.loadtexture("image/dust_sans_use_skill2_l.bmp");
             }

                if(character_frame_use_skill2/5>=1 && character_frame_use_skill2/5<2){
                    character1.setheight(55);
                   character1.setwidth(53);

                }
                character1.render(&character1_clip[character_frame_use_skill2/5]);

        }

        else{
             //set sprite for ch when player use skill3
              if(r){
                character1_clip[3].h=41;
                character1_clip[3].w=23;
                character1_clip[3].x=0;
                character1_clip[3].y=0;

                 character1_clip[2].h=41;
                character1_clip[2].w=26;
                character1_clip[2].x=23+8;
                character1_clip[2].y=0;


                character1_clip[1].h=41;
                character1_clip[1].w=21;
                character1_clip[1].x=23+8+26+10;
                character1_clip[1].y=0;

                character1_clip[0].h=41;
                character1_clip[0].w=22;
                character1_clip[0].x=23+8+26+10+21+6;
                character1_clip[0].y=0;


                character1.loadtexture("image/dust_sans_use_skill3_r.bmp");
             }

             if(l){
                character1_clip[3].h=41;
                character1_clip[3].w=23;
                character1_clip[3].x=22+6+21+10+26+8;
                character1_clip[3].y=0;

                 character1_clip[2].h=41;
                character1_clip[2].w=26;
                character1_clip[2].x=22+6+21+10;
                character1_clip[2].y=0;


                character1_clip[1].h=41;
                character1_clip[1].w=21;
                character1_clip[1].x=22+6;
                character1_clip[1].y=0;

                character1_clip[0].h=41;
                character1_clip[0].w=22;
                character1_clip[0].x=0;      //23+8+26+10+21+6
                character1_clip[0].y=0;



                character1.loadtexture("image/dust_sans_use_skill3_l.bmp");
             }



             character1.render(&character1_clip[character_frame_use_skill3/5]);



        }




        }



        }


        }




















        }






        }














        if(choose_skin2){







        character1.settdx(tdx_character1);
        character1.settdy(tdy_character1);
        character1.setheight(60); //60
        character1.setwidth(36);  //36
        character1.loadtexture("image/error_sans_mvr.bmp");

        //set sprite for charater jump
        if((can_character1_jump || tdy_character1 < tdy_of_ground) && !(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI
            || sprite_for_ch_get_dam_by_skill3_of_AI) && can_character1_run_after_using_skill1 &&
           can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){


            if(r){

         character1_clip[0].h=39;
         character1_clip[0].w=21;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

         character1_clip[1].h=39;
         character1_clip[1].w=21;
         character1_clip[1].x=21+7;
         character1_clip[1].y=0;

         character1_clip[2].h=39;
         character1_clip[2].w=22;
         character1_clip[2].x=21*2+7+8;
         character1_clip[2].y=0;

          character1_clip[3].h=39;
         character1_clip[3].w=20;
         character1_clip[3].x=21*2+22+7+8+6;
         character1_clip[3].y=0;


          character1_clip[4].h=39;
         character1_clip[4].w=20;
         character1_clip[4].x=21*2+20+22+7+8+6+9;
         character1_clip[4].y=0;

          character1_clip[5].h=39;
         character1_clip[5].w=20;
         character1_clip[5].x=21*2+20*2+22+7+8+6+9+12;
         character1_clip[5].y=0;

          character1_clip[6].h=39;
         character1_clip[6].w=21;
         character1_clip[6].x=21*2+20*3+22+7+8+6+9+12+14;
         character1_clip[6].y=0;

          character1_clip[7].h=39;
         character1_clip[7].w=21;
         character1_clip[7].x=21*3+20*3+22+7+8+6+9+12+14+8;
         character1_clip[7].y=0;




                 character1.loadtexture("image/error_sans_jump_r.bmp");
            }


            if(l){


         character1_clip[7].h=39;
         character1_clip[7].w=21;
         character1_clip[7].x=0;
         character1_clip[7].y=0;

         character1_clip[6].h=39;
         character1_clip[6].w=21;
         character1_clip[6].x=21+9;
         character1_clip[6].y=0;

         character1_clip[5].h=39;
         character1_clip[5].w=20;
         character1_clip[5].x=21*2+9+14;
         character1_clip[5].y=0;

          character1_clip[4].h=39;
         character1_clip[4].w=20;
         character1_clip[4].x=21*2+20+9+14+12;
         character1_clip[4].y=0;


          character1_clip[3].h=39;
         character1_clip[3].w=20;
         character1_clip[3].x=21*2+20*2+9+14+9+12;
         character1_clip[3].y=0;

          character1_clip[2].h=39;
         character1_clip[2].w=22;
         character1_clip[2].x=21*2+20*3+9+14+9+6+12;
         character1_clip[2].y=0;

          character1_clip[1].h=39;
         character1_clip[1].w=21;
         character1_clip[1].x=21*2+20*3+9+14+9+6+22+8+12;
         character1_clip[1].y=0;

          character1_clip[0].h=39;
         character1_clip[0].w=21;
         character1_clip[0].x=21*3+20*3+9+14+9+6+22+8+7+12;
         character1_clip[0].y=0;







                 character1.loadtexture("image/error_sans_jump_l.bmp");
            }


             character1.render(&character1_clip[character_frame_jump/10]);

        }

        else{


        //set sprite for ch mv right or left

        if(!(sprite_for_ch_get_dam_by_skill1_of_AI || sprite_for_ch_get_dam_by_skill2_of_AI || sprite_for_ch_get_dam_by_skill3_of_AI) &&
           can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){
        if(r){

         character1_clip[0].h=38;
         character1_clip[0].w=20;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

         character1_clip[1].h=38;
         character1_clip[1].w=20;
         character1_clip[1].x=20+9;
         character1_clip[1].y=0;

         character1_clip[2].h=38;
         character1_clip[2].w=20;
         character1_clip[2].x=20*2+9+8;
         character1_clip[2].y=0;

          character1_clip[3].h=38;
         character1_clip[3].w=20;
         character1_clip[3].x=20*3+9+8+11;
         character1_clip[3].y=0;


          character1_clip[4].h=38;
         character1_clip[4].w=20;
         character1_clip[4].x=20*4+9+8+11+6;
         character1_clip[4].y=0;

          character1_clip[5].h=38;
         character1_clip[5].w=20;
         character1_clip[5].x=20*5+9+8+11+6+9;
         character1_clip[5].y=0;

          character1_clip[6].h=38;
         character1_clip[6].w=20;
         character1_clip[6].x=20*6+9+8+11+6+9+10;
         character1_clip[6].y=0;

          character1_clip[7].h=38;
         character1_clip[7].w=20;
         character1_clip[7].x=20*7+9+8+11+6+9+10+9;
         character1_clip[7].y=0;



           character1.loadtexture("image/error_sans_mvr.bmp");

        }
        if(l){



                character1_clip[7].h=38;
         character1_clip[7].w=20;
         character1_clip[7].x=0;
         character1_clip[7].y=0;

         character1_clip[6].h=38;
         character1_clip[6].w=20;
         character1_clip[6].x=20+9;
         character1_clip[6].y=0;

         character1_clip[5].h=38;
         character1_clip[5].w=20;
         character1_clip[5].x=20*2+9+10;
         character1_clip[5].y=0;

          character1_clip[4].h=38;
         character1_clip[4].w=20;
         character1_clip[4].x=20*3+9+10+9;
         character1_clip[4].y=0;


          character1_clip[3].h=38;
         character1_clip[3].w=20;
         character1_clip[3].x=20*4+9+10+9+6;
         character1_clip[3].y=0;

          character1_clip[2].h=38;
         character1_clip[2].w=20;
         character1_clip[2].x=20*5+9+10+9+6+11;
         character1_clip[2].y=0;

          character1_clip[1].h=38;
         character1_clip[1].w=20;
         character1_clip[1].x=20*6+9+10+9+6+11+8;
         character1_clip[1].y=0;

          character1_clip[0].h=38;
         character1_clip[0].w=20;
         character1_clip[0].x=20*7+9+10+9+6+11+8+9;
         character1_clip[0].y=0;




          character1.loadtexture("image/error_sans_mvl.bmp");
        }


         character1.render(&character1_clip[character1_frame/5]);



        }




        else{


        //set sprite when character is damaged
        if(can_character1_run_after_using_skill1 && can_character1_run_after_using_skill2
           && can_character1_run_after_using_skill3){
        character1.setheight(60);
        character1.setwidth(48);

        if(r){
         character1_clip[1].h=35;
         character1_clip[1].w=28;
         character1_clip[1].x=0;
         character1_clip[1].y=0;

          character1_clip[0].h=35;
         character1_clip[0].w=30;
         character1_clip[0].x=28+14;
         character1_clip[0].y=0;




          character1.loadtexture("image/error_sans_is_damaged_r.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }

         if(l){
         character1_clip[0].h=35;
         character1_clip[0].w=30;
         character1_clip[0].x=0;
         character1_clip[0].y=0;

          character1_clip[1].h=35;
         character1_clip[1].w=28;
         character1_clip[1].x=30+14;
         character1_clip[1].y=0;




          character1.loadtexture("image/error_sans_is_damaged_l.bmp");

          character1.render(&character1_clip[character_frame_get_dam/5]);
        }



        }





        else{

            if(can_character1_run_after_using_skill2 && can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill1
            if(r){
                character1_clip[0].h=39;
                character1_clip[0].w=21;
                character1_clip[0].x=0;
                character1_clip[0].y=0;

                character1_clip[1].h=39;
                character1_clip[1].w=21;
                character1_clip[1].x=21+11;
                character1_clip[1].y=0;


                character1_clip[2].h=39;
                character1_clip[2].w=29;
                character1_clip[2].x=21*2+11+7;
                character1_clip[2].y=0;

                character1_clip[3].h=39;
                character1_clip[3].w=34;
                character1_clip[3].x=21*2+29+11+7+7;
                character1_clip[3].y=0;

                character1_clip[4].h=39;
                character1_clip[4].w=25;
                character1_clip[4].x=21*2+29+34+11+7+7+6;
                character1_clip[4].y=0;

                character1_clip[5].h=39;
                character1_clip[5].w=20;
                character1_clip[5].x=21*2+29+34+25+11+7+7+6+12;
                character1_clip[5].y=0;


                character1.loadtexture("image/error_sans_skill1_r.bmp");

            }


             if(l){
                character1_clip[5].h=39;
                character1_clip[5].w=21;
                character1_clip[5].x=20+12+25+6+7+34+29+7+21+11;
                character1_clip[5].y=0;

                character1_clip[4].h=39;
                character1_clip[4].w=21;
                character1_clip[4].x=20+12+25+6+7+34+29+7;
                character1_clip[4].y=0;


                character1_clip[3].h=39;
                character1_clip[3].w=29;
                character1_clip[3].x=20+12+25+6+7+34;
                character1_clip[3].y=0;

                character1_clip[2].h=39;
                character1_clip[2].w=34;
                character1_clip[2].x=20+12+25+6;
                character1_clip[2].y=0;

                character1_clip[1].h=39;
                character1_clip[1].w=25;
                character1_clip[1].x=20+12;
                character1_clip[1].y=0;

                character1_clip[0].h=39;
                character1_clip[0].w=20;
                character1_clip[0].x=0;
                character1_clip[0].y=0;


                character1.loadtexture("image/error_sans_skill1_l.bmp");



            }

            if(character_frame_use_skill1/5==2){
                character1.setheight(60);
                character1.setwidth(58);

            }

            character1.render(&character1_clip[character_frame_use_skill1/5]);



        }

        else{


        if(can_character1_run_after_using_skill3){

             //set sprite for ch when player use skill2
             if(r){
                character1_clip[2].h=37;
                character1_clip[2].w=28;
                character1_clip[2].x=25+5+35+5;
                character1_clip[2].y=0;

                character1_clip[1].h=37;
                character1_clip[1].w=35;
                character1_clip[1].x=25+5;
                character1_clip[1].y=0;

                character1_clip[0].h=37;
                character1_clip[0].w=25;
                character1_clip[0].x=0;
                character1_clip[0].y=0;


                character1.loadtexture("image/error_sans_skill2_r.bmp");
             }

              if(l){
                character1_clip[2].h=37;
                character1_clip[2].w=28;
                character1_clip[2].x=0;
                character1_clip[2].y=0;

                character1_clip[1].h=37;
                character1_clip[1].w=35;
                character1_clip[1].x=28+5;
                character1_clip[1].y=0;

                character1_clip[0].h=37;
                character1_clip[0].w=25;
                character1_clip[0].x=28+5+35+5;
                character1_clip[0].y=0;


                character1.loadtexture("image/error_sans_skill2_l.bmp");
             }

                if(character_frame_use_skill2/5==1){
                    character1.setheight(60);
                   character1.setwidth(58);

                }
                character1.render(&character1_clip[character_frame_use_skill2/5]);

        }

        else{
             //set sprite for ch when player use skill3
              if(r){
                character1_clip[3].h=39;
                character1_clip[3].w=22;
                character1_clip[3].x=0;
                character1_clip[3].y=0;

                 character1_clip[2].h=39;
                character1_clip[2].w=25;
                character1_clip[2].x=22+9;
                character1_clip[2].y=0;


                character1_clip[1].h=37;
                character1_clip[1].w=20;
                character1_clip[1].x=22+9+25+11;
                character1_clip[1].y=0;

                character1_clip[0].h=37;
                character1_clip[0].w=21;
                character1_clip[0].x=22+9+25+11+20+7;
                character1_clip[0].y=0;


                character1.loadtexture("image/error_sans_skill3_r.bmp");
             }

             if(l){
                character1_clip[3].h=39;
                character1_clip[3].w=21;
                character1_clip[3].x=0;
                character1_clip[3].y=0;

                 character1_clip[2].h=39;
                character1_clip[2].w=20;
                character1_clip[2].x=21+7;
                character1_clip[2].y=0;


                character1_clip[1].h=37;
                character1_clip[1].w=25;
                character1_clip[1].x=21+7+20+11;
                character1_clip[1].y=0;

                character1_clip[0].h=37;
                character1_clip[0].w=22;
                character1_clip[0].x=21+7+20+11+25+9;
                character1_clip[0].y=0;


                character1.loadtexture("image/error_sans_skill3_l.bmp");
             }



             character1.render(&character1_clip[character_frame_use_skill3/5]);



        }




        }



        }


        }




















        }






        }


                 }


void set_chr1_jump(bool &_can_character1_jump,int &_tdy_character1,const int _tdy_of_ground,
                   double _set_time_in_the_air_of_character1,double _v_of_character1,double &saving_time_jumping_when_stopping_game1
                   ,bool &stopping_time,int &character_frame_jump){

     if(_can_character1_jump && !stopping_time){
              _tdy_character1=_tdy_character1-set_gravity(_v_of_character1,_set_time_in_the_air_of_character1,saving_time_jumping_when_stopping_game1);
                if(_tdy_character1>=_tdy_of_ground){
                  _tdy_character1=_tdy_of_ground;
                  _can_character1_jump=false;
                }


        //set sprite for ch when player jump


            character_frame_jump++;
            if(character_frame_jump/10>=6){
                   character_frame_jump=50;
            }





     }
     else{
         character_frame_jump=0;
     }


}
