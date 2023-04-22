#ifndef mcharacter2_skill2
#define mcharacter2_skill2
#include"texture.h"
const int quatity_of_skill2_of_AI=4;
int skill2_of_AI_frame=0;
SDL_Rect skill2_of_AI_clip[quatity_of_skill2_of_AI];

int time_watting_for_skill2_of_AI=100;
bool Is_skill2_of_character2_actived=false;
bool left_for_skill2_of_character2=false;
bool right_for_skill2_of_character2=false;
Ltexture character2_skill2;
int tdx_of_skill2_character2=0;
int tdy_of_skill2_character2=0;

#endif // texture
void set_value_for_skill2_of_AI(Ltexture character2){
     tdx_of_skill2_character2=character2.gettdx();
     tdy_of_skill2_character2=character2.gettdy();

}
void reset_skill2_of_AI(){

     time_watting_for_skill2_of_AI=100;
     Is_skill2_of_character2_actived=false;
     left_for_skill2_of_character2=false;
     right_for_skill2_of_character2=false;

     tdx_of_skill2_character2=0;
     tdy_of_skill2_character2=0;


}
void skill2_active(int &mtdx_of_skill2_character2,int mtdy_of_skill2_character2,bool mright,bool mleft,
                   int mtdx_character1,int mtdy_character1, bool &mdid_character1_get_hit, bool stopping_time,
                   bool &Does_AI_use_skill2,int &character2_frame_skill2){
     if(mright){

        skill2_of_AI_clip[0].h=70;
        skill2_of_AI_clip[0].w=84;
        skill2_of_AI_clip[0].x=0;
        skill2_of_AI_clip[0].y=0;

        skill2_of_AI_clip[1].h=70;
        skill2_of_AI_clip[1].w=78;
        skill2_of_AI_clip[1].x=84+20;
        skill2_of_AI_clip[1].y=0;

        skill2_of_AI_clip[2].h=70;
        skill2_of_AI_clip[2].w=78;
        skill2_of_AI_clip[2].x=84+20+78+18;
        skill2_of_AI_clip[2].y=0;

        skill2_of_AI_clip[3].h=70;
        skill2_of_AI_clip[3].w=78;
        skill2_of_AI_clip[3].x=84+20+78*2+18+16;
        skill2_of_AI_clip[3].y=0;


        character2_skill2.loadtexture("image/slash_chara_right.bmp",255,255,255);
     }







     if(mleft){


        skill2_of_AI_clip[0].h=70;
        skill2_of_AI_clip[0].w=84;
        skill2_of_AI_clip[0].x=78*3+20+18+16;
        skill2_of_AI_clip[0].y=0;

        skill2_of_AI_clip[1].h=70;
        skill2_of_AI_clip[1].w=78;
        skill2_of_AI_clip[1].x=78*2+18+16;
        skill2_of_AI_clip[1].y=0;

        skill2_of_AI_clip[2].h=70;
        skill2_of_AI_clip[2].w=78;
        skill2_of_AI_clip[2].x=78+16;
        skill2_of_AI_clip[2].y=0;

        skill2_of_AI_clip[3].h=70;      //84+20+78*2+18+16
        skill2_of_AI_clip[3].w=78;
        skill2_of_AI_clip[3].x=0;
        skill2_of_AI_clip[3].y=0;


        character2_skill2.loadtexture("image/slash_chara_left.bmp",255,255,255);
     }

     character2_skill2.setheight(77);
     character2_skill2.setwidth(83);
     character2_skill2.settdx(mtdx_of_skill2_character2);
     character2_skill2.settdy(mtdy_of_skill2_character2);
     character2_skill2.render(&skill2_of_AI_clip[skill2_of_AI_frame/5]);


           if(mleft && !stopping_time ){
                mtdx_of_skill2_character2=mtdx_of_skill2_character2-20;


                if(mtdx_of_skill2_character2<=0){
                   mtdx_of_skill2_character2=tdx_character2;
                   mtdx_of_skill2_character2=tdy_character2;
                   Is_skill2_of_character2_actived=false;
                    character2_frame_skill2=0;

                }

                if(mtdx_of_skill2_character2<mtdx_character1+36 &&
                mtdx_of_skill2_character2>mtdx_character1 &&
                mtdy_of_skill2_character2-60<mtdy_character1 &&
                mtdy_of_skill2_character2+77>mtdy_character1){
                mdid_character1_get_hit=true;

                }
                else{mdid_character1_get_hit=false;}
             }
            if(mright && !stopping_time){
                mtdx_of_skill2_character2=mtdx_of_skill2_character2+20;

                 if(mtdx_of_skill2_character2>=1080){
                   mtdx_of_skill2_character2=tdx_character2;
                   mtdx_of_skill2_character2=tdy_character2;
                   Is_skill2_of_character2_actived=false;
                   character2_frame_skill2=0;


                }

                if(mtdx_of_skill2_character2+83<mtdx_character1+36 &&
                mtdx_of_skill2_character2+83>mtdx_character1 &&
                mtdy_of_skill2_character2-60<mtdy_character1 &&
                mtdy_of_skill2_character2+77>mtdy_character1){
                mdid_character1_get_hit=true;



                }
                else{mdid_character1_get_hit=false;}
            }
}


void set_skill2_of_AI_active(bool right_AI,bool left_AI,Ltexture character1,Ltexture character2,
                             int &time_watting_for_skill2_of_AI,
                             bool &Is_skill2_of_character2_actived,int tdx_character2,int tdy_character2,
                             int &tdx_of_skill2_character2,int &tdy_of_skill2_character2,
                             bool &left_for_skill2_of_character2,bool &right_for_skill2_of_character2,
                             int tdx_character1,int tdy_character1,bool stopping_time,bool &Does_AI_use_skill2,
                             int &character2_frame_skill2,bool delay_skill_of_AI){


     if(abs(character2.gettdx()-character1.gettdx()) <=1000 && time_watting_for_skill2_of_AI ==0 &&!stopping_time
        && !delay_skill_of_AI )
          {
             Is_skill2_of_character2_actived=true;
             Does_AI_use_skill2=true;



           if(character2_frame_skill2>=20){
             time_watting_for_skill2_of_AI=200;
             tdx_of_skill2_character2=tdx_character2;
             tdy_of_skill2_character2=tdy_character2;
              if(left_AI){
                 left_for_skill2_of_character2=true;
                 right_for_skill2_of_character2=false;
             }
             if(right_AI){
                 left_for_skill2_of_character2=false;
                 right_for_skill2_of_character2=true;
             }
          }


          }






}

