#ifndef texture
#define texture
texture
#endif // texture
Ltexture skill3_of_character1;
int height_of_bone=0;
void set_skill3_of_character1(int tdx_character2, int &time_appearing_of_skill3_from_character1,int &height_of_bone){
     skill3_of_character1.settdx(tdx_character2-75);
     skill3_of_character1.settdy(680/4*3+59-height_of_bone);
     skill3_of_character1.setheight(height_of_bone);
     skill3_of_character1.setwidth(150);
     skill3_of_character1.loadtexture("sans_bone_zone.bmp");
     skill3_of_character1.render(NULL);
     time_appearing_of_skill3_from_character1--;
     if(time_appearing_of_skill3_from_character1<=0){
        time_appearing_of_skill3_from_character1=0;
     }
     if(height_of_bone<=58){
        height_of_bone=height_of_bone+10;
     }
}
