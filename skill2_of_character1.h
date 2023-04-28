#ifndef mskill2_of_character1
#define mskill2_of_character1
#include"texture.h"


const int quatities_of_bone_sprites=4;
int quatities_of_bone_frame=0;
SDL_Rect quatities_of_bone_clip[quatities_of_bone_sprites];


const int quatities_of_bone=3;
Ltexture skill2_of_character1[quatities_of_bone];
int tdx_for_ingradient_of_skill2_character1[quatities_of_bone];
int tdy_for_ingradient_of_skill2_character1[quatities_of_bone];
bool Is_skill2_from_character1_actived=false;;
bool did_character2_get_hit_by_skill2[quatities_of_bone];
bool reset_tdx_and_tdy_of_skill2_from_character1=false;

 int tdx_skill2_of_character1=0;
  int tdy_skill2_of_character1=0;
  int time_watting_of_skill2_from_character1=0;

  bool left_for_skill2_of_character1=false;
  bool Right_for_skill2_of_character1=false;


#endif // texture

void reset_skill2_of_ch1(int tdx_character1,int tdy_character1){
          //set skill2 for character1
      tdx_skill2_of_character1=tdx_character1;
      tdy_skill2_of_character1=tdy_character1;
      time_watting_of_skill2_from_character1=0;

      left_for_skill2_of_character1=false;
      Right_for_skill2_of_character1=false;

         for(int i=0;i<quatities_of_bone;i++){
              tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
              tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
              did_character2_get_hit_by_skill2[i]=false;

           }





}



void set_value_for_ingradient_of_skill2_of_character1(bool choose_skin1,bool choose_skin2){

    quatities_of_bone_clip[0].x=0;
    quatities_of_bone_clip[0].y=0;
    quatities_of_bone_clip[0].h=60;
    quatities_of_bone_clip[0].w=47;

    quatities_of_bone_clip[1].x=47+22;
    quatities_of_bone_clip[1].y=0;
    quatities_of_bone_clip[1].h=60;
    quatities_of_bone_clip[1].w=48;

    quatities_of_bone_clip[2].x=47+22+48+14;
    quatities_of_bone_clip[2].y=0;
    quatities_of_bone_clip[2].h=60;
    quatities_of_bone_clip[2].w=54;

    quatities_of_bone_clip[3].x=47+22+48+14+54+14;
    quatities_of_bone_clip[3].y=0;
    quatities_of_bone_clip[3].h=60;
    quatities_of_bone_clip[3].w=50;



  if(choose_skin1){
     for(int i=0;i<quatities_of_bone;i++){

        tdx_for_ingradient_of_skill2_character1[i]=tdx_character1+5;
        tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;

        skill2_of_character1[i].loadtexture("image/bone.bmp");

        did_character2_get_hit_by_skill2[i]=false;
     }

  }



  if(choose_skin2){
     for(int i=0;i<quatities_of_bone;i++){

        tdx_for_ingradient_of_skill2_character1[i]=tdx_character1+5;
        tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;


        skill2_of_character1[i].loadtexture("image/error_bone.bmp");

        did_character2_get_hit_by_skill2[i]=false;
     }


  }

}


void set_skill2_of_character1(bool choose_right_1,bool choose_left_1){
     for(int i=0;i<quatities_of_bone;i++){
        skill2_of_character1[i].setheight(50);
        skill2_of_character1[i].setwidth(60);
        tdx_for_ingradient_of_skill2_character1[i]=tdx_character1-100+60*i;
        if(tdx_for_ingradient_of_skill2_character1[i]<=10){
            tdx_for_ingradient_of_skill2_character1[i]=10+60*i;
        }
        tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
     }


     if(choose_right_1){
        Right_for_skill2_of_character1=true;
        left_for_skill2_of_character1=false;

    };

     if(choose_left_1){
        left_for_skill2_of_character1=true;
        Right_for_skill2_of_character1=false;
    };


}


void set_skill2_of_character1_actived(int tdx_for_ingradient_of_skill2_character1[],
                                      int tdy_for_ingradient_of_skill2_character1[],
                                      bool &Is_skill2_from_character1_actived,
                                      int &time_watting_of_skill2_from_character1,
                                      bool did_character2_get_hit_by_skill2[],const int quatities_of_bone,bool stopping_time,
                                      int &character_frame_use_skill2,bool &can_character1_run_after_using_skill2){




      for(int i=0;i<quatities_of_bone;i++){

        if(Is_skill2_from_character1_actived){

           quatities_of_bone_frame++;
          if(quatities_of_bone_frame/5>=4){
             quatities_of_bone_frame=0;
          }


            if((tdx_for_ingradient_of_skill2_character1[0]>=1080 || tdx_for_ingradient_of_skill2_character1[0]<=0) && !stopping_time){
                Is_skill2_from_character1_actived=false;
                can_character1_run_after_using_skill2=true;


            }


            if(Right_for_skill2_of_character1){
             tdx_for_ingradient_of_skill2_character1[i]=tdx_for_ingradient_of_skill2_character1[i]+10;
            }
            else{
                tdx_for_ingradient_of_skill2_character1[i]=tdx_for_ingradient_of_skill2_character1[i]-10;
            }


             skill2_of_character1[i].settdx(tdx_for_ingradient_of_skill2_character1[i]);
             skill2_of_character1[i].settdy(tdy_for_ingradient_of_skill2_character1[i]);
             skill2_of_character1[i].render(&quatities_of_bone_clip[quatities_of_bone_frame/5]);




                   if(tdx_for_ingradient_of_skill2_character1[i]>=tdx_character2-5 &&
                     tdx_for_ingradient_of_skill2_character1[i]<=tdx_character2+5 &&
                     tdy_for_ingradient_of_skill2_character1[i]+2>=tdy_character2 &&
                     tdy_for_ingradient_of_skill2_character1[i]-2<=tdy_character2){
                     did_character2_get_hit_by_skill2[i]=true;
                  }
                  else{
                      did_character2_get_hit_by_skill2[i]=false;
                  }



          }
      }








           // set time watting for skill2 of character1
            if(time_watting_of_skill2_from_character1>0 && !stopping_time && !Is_skill2_from_character1_actived){
              time_watting_of_skill2_from_character1--;
            }


            //set sprite skill2 for player
           if(Is_skill2_from_character1_actived && !can_character1_run_after_using_skill2 && !stopping_time){
              character_frame_use_skill2++;
              if(character_frame_use_skill2/5>=3){
                 can_character1_run_after_using_skill2=true;
                 character_frame_use_skill2=10;
              }
              else{
                  can_character1_run_after_using_skill2=false;

              }

           }
           else{
                character_frame_use_skill2=0;
           }
}
