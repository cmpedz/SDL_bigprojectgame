#ifndef texture
#define texture
texture;
#endif // texture
void skill2_active(int tdx_of_skill2_character2,int tdy_of_skill2_character2,bool right_AI,bool left_AI){
     if(right_AI){character2_skill2.loadtexture("slash_chara_right.bmp");}
     if(left_AI){character2_skill2.loadtexture("slash_chara_left.bmp");}
     character2_skill2.setheight(77);
     character2_skill2.setwidth(83);
     character2_skill2.settdx(tdx_of_skill2_character2);
     character2_skill2.settdy(tdy_of_skill2_character2);
     character2_skill2.render(NULL);
}

