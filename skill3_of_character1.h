#ifndef skill3_of_ch1
#define skill1_of_ch1
#include"texture.h"
Ltexture skill3_of_character1;
int height_of_bone=0;
 bool does_skill3_of_character1_active=false;
  int time_appearing_of_skill3_from_character1=50;
  int time_watting_of_skill3_from_character1=0;
  bool character2_can_not_move=false;




#endif // texture
void reset_skill3_of_ch1(){

     does_skill3_of_character1_active=false;
        time_appearing_of_skill3_from_character1=50;
        time_watting_of_skill3_from_character1=0;
        character2_can_not_move=false;


}
void set_skill3_of_character1(int tdx_character2, int &time_appearing_of_skill3_from_character1,
                              int &height_of_bone,bool stopping_time){
     skill3_of_character1.settdx(tdx_character2-75);
     skill3_of_character1.settdy(680/4*3+59-height_of_bone);
     skill3_of_character1.setheight(height_of_bone);
     skill3_of_character1.setwidth(150);
     skill3_of_character1.loadtexture("sans_bone_zone.bmp");
     skill3_of_character1.render(NULL);

     if(!stopping_time){
        time_appearing_of_skill3_from_character1--;
     }

     if(time_appearing_of_skill3_from_character1<=0){
        time_appearing_of_skill3_from_character1=0;
     }
     if(height_of_bone<=58 && !stopping_time){
        height_of_bone=height_of_bone+10;
     }
}

void set_skill3_of_ch1_active(bool &does_skill3_of_character1_active,int &time_watting_of_skill3_from_character1,
                              int tdx_character2,int tdy_character2,int &height_of_bone,
                              bool &character2_can_not_move,int &time_appearing_of_skill3_from_character1,
                              Ltexture skill3_of_character1,bool &did_character2_get_hit,bool stopping_time){

     if(does_skill3_of_character1_active ){

            if(!stopping_time){  time_watting_of_skill3_from_character1=200;}
                 set_skill3_of_character1(tdx_character2,time_appearing_of_skill3_from_character1,height_of_bone,stopping_time);
                 character2_can_not_move=true;
                 if(time_appearing_of_skill3_from_character1==0){
                    does_skill3_of_character1_active=false;
                    time_appearing_of_skill3_from_character1=50;
                 }
                 if(tdx_character2>=skill3_of_character1.gettdx() &&
                    skill3_of_character1.gettdx()+150>=tdx_character2
                    && skill3_of_character1.gettdy()-tdy_character2<=0){
                 did_character2_get_hit=true;
              }
              else{
                  did_character2_get_hit=false;
              }





            }
              else{
                  character2_can_not_move=false;
              }

}
