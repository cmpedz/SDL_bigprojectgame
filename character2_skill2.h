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

