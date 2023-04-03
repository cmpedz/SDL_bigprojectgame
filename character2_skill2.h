#ifndef mcharacter2_skill2
#define mcharacter2_skill2
#include"texture.h"
#endif // texture
void skill2_active(int &mtdx_of_skill2_character2,int mtdy_of_skill2_character2,bool mright,bool mleft,
                   int mtdx_character1,int mtdy_character1, bool &mdid_character1_get_hit){
     if(mright){character2_skill2.loadtexture("slash_chara_right.bmp");}
     if(mleft){character2_skill2.loadtexture("slash_chara_left.bmp");}
     character2_skill2.setheight(77);
     character2_skill2.setwidth(83);
     character2_skill2.settdx(mtdx_of_skill2_character2);
     character2_skill2.settdy(mtdy_of_skill2_character2);
     character2_skill2.render(NULL);


           if(mleft){
                mtdx_of_skill2_character2=mtdx_of_skill2_character2-20;
                if(mtdx_of_skill2_character2<mtdx_character1+36 &&
                mtdx_of_skill2_character2>mtdx_character1 &&
                mtdy_of_skill2_character2-60<mtdy_character1 &&
                mtdy_of_skill2_character2+77>mtdy_character1){
                mdid_character1_get_hit=true;
                }
                else{mdid_character1_get_hit=false;}
             }
            if(mright){
                mtdx_of_skill2_character2=mtdx_of_skill2_character2+20;
                if(mtdx_of_skill2_character2+83<mtdx_character1+36 &&
                mtdx_of_skill2_character2+83>mtdx_character1 &&
                mtdy_of_skill2_character2-60<mtdy_character1 &&
                mtdy_of_skill2_character2+77>mtdy_character1){
                mdid_character1_get_hit=true;
                }
                else{mdid_character1_get_hit=false;}
            }
}


void set_skill2_of_AI_active(Ltexture character1,Ltexture character2,int &time_watting_for_skill2_of_AI,
                             bool &is_skill2_of_character2_actived,int tdx_character2,int tdy_character2,
                             int &tdx_of_skill2_character2,int &tdy_of_skill2_character2,
                             bool left_AI,bool &left_for_skill2_of_character2,bool &right_for_skill2_of_character2,
                             int tdx_character1,int tdy_character1,bool &did_character1_get_hit){


     if(abs(character2.gettdx()-character1.gettdx()) <=400 && time_watting_for_skill2_of_AI ==0)
          {
             is_skill2_of_character2_actived=true;
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
          if(is_skill2_of_character2_actived){
             skill2_active(tdx_of_skill2_character2,tdy_of_skill2_character2,right_for_skill2_of_character2,
                           left_for_skill2_of_character2,tdx_character1,tdy_character1,did_character1_get_hit);
          }



}

