#ifndef mskill2_of_character1
#define mskill2_of_character1
#include"texture.h"


const int quatities_of_bone=3;
Ltexture skill2_of_character1[quatities_of_bone];
int tdx_for_ingradient_of_skill2_character1[quatities_of_bone];
int tdy_for_ingradient_of_skill2_character1[quatities_of_bone];
bool is_ingradient_of_skill2_from_character1_actived[quatities_of_bone];
bool did_character2_get_hit_by_skill2[quatities_of_bone];
bool reset_tdx_and_tdy_of_skill2_from_character1=false;
int vector_for_ingradient_of_character1[quatities_of_bone];

 int tdx_skill2_of_character1=0;
  int tdy_skill2_of_character1=0;
  int time_watting_of_skill2_from_character1=0;
  int quatities_of_skill2_for_character1=0;
  bool left_for_skill2_of_character1=false;
  bool right_for_skill2_of_character1=false;

#endif // texture

void reset_skill2_of_ch1(int tdx_character1,int tdy_character1){
          //set skill2 for character1
      tdx_skill2_of_character1=tdx_character1;
      tdy_skill2_of_character1=tdy_character1;
      time_watting_of_skill2_from_character1=0;
      quatities_of_skill2_for_character1=0;
      left_for_skill2_of_character1=false;
      right_for_skill2_of_character1=false;

         for(int i=0;i<quatities_of_bone;i++){
              tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
              tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
           }



}



void set_value_for_ingradient_of_skill2_of_character1(bool choose_skin1,bool choose_skin2){
  if(choose_skin1){
     for(int i=0;i<quatities_of_bone;i++){

        tdx_for_ingradient_of_skill2_character1[i]=tdx_character1+5;
        tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;

        skill2_of_character1[i].loadtexture("image/bone.bmp");

        is_ingradient_of_skill2_from_character1_actived[i]=false;
        vector_for_ingradient_of_character1[i]=0;
        did_character2_get_hit_by_skill2[i]=false;
     }
  }



  if(choose_skin2){
     for(int i=0;i<quatities_of_bone;i++){

        tdx_for_ingradient_of_skill2_character1[i]=tdx_character1+5;
        tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;


        skill2_of_character1[i].loadtexture("image/error_bone.bmp");



        is_ingradient_of_skill2_from_character1_actived[i]=false;
        vector_for_ingradient_of_character1[i]=0;
        did_character2_get_hit_by_skill2[i]=false;
     }
  }

}


void set_skill2_of_character1(){
     for(int i=0;i<quatities_of_bone;i++){
        skill2_of_character1[i].setheight(36);
        skill2_of_character1[i].setwidth(60);
        skill2_of_character1[i].settdx(tdx_for_ingradient_of_skill2_character1[i]);
        skill2_of_character1[i].settdy(tdy_for_ingradient_of_skill2_character1[i]);
     }
}


void set_skill2_of_character1_actived(int &quatities_of_skill2_for_character1,
                                      int tdx_for_ingradient_of_skill2_character1[],
                                      int tdy_for_ingradient_of_skill2_character1[],
                                      bool is_ingradient_of_skill2_from_character1_actived[],
                                      int &time_watting_of_skill2_from_character1,
                                      bool did_character2_get_hit_by_skill2[],const int quatities_of_bone,bool stopping_time){


        for(int i=0;i<quatities_of_bone;i++){
                    if(!is_ingradient_of_skill2_from_character1_actived[i]){
                       tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
                       tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
                    }
        }



      for(int i=0;i<quatities_of_skill2_for_character1;i++){

          if((tdx_for_ingradient_of_skill2_character1[i]>=1080 || tdx_for_ingradient_of_skill2_character1[i]<=0) && !stopping_time){
             is_ingradient_of_skill2_from_character1_actived[i]=false;
             vector_for_ingradient_of_character1[i]=0;
             if(i==2){
                quatities_of_skill2_for_character1=0;
                time_watting_of_skill2_from_character1=30;
             }
          }

          if(is_ingradient_of_skill2_from_character1_actived[i]){
             skill2_of_character1[i].settdx(tdx_for_ingradient_of_skill2_character1[i]);
             skill2_of_character1[i].settdy(tdy_for_ingradient_of_skill2_character1[i]);
             skill2_of_character1[i].render(NULL);

          }
      }


        for(int i=0;i<quatities_of_skill2_for_character1;i++){
                if(left_for_skill2_of_character1 && vector_for_ingradient_of_character1[i]==0 && is_ingradient_of_skill2_from_character1_actived[i] && !stopping_time){
                     vector_for_ingradient_of_character1[i]=2;
                  }
                   if(right_for_skill2_of_character1 && vector_for_ingradient_of_character1[i]==0 && is_ingradient_of_skill2_from_character1_actived[i] && !stopping_time){
                     vector_for_ingradient_of_character1[i]=1;
                   }
                    if(vector_for_ingradient_of_character1[i]==1 && !stopping_time){ tdx_for_ingradient_of_skill2_character1[i]=tdx_for_ingradient_of_skill2_character1[i]+10;}
                    if(vector_for_ingradient_of_character1[i]==2 && !stopping_time){ tdx_for_ingradient_of_skill2_character1[i]=tdx_for_ingradient_of_skill2_character1[i]-10;}

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






           // set time watting for skill2 of character1
            if(time_watting_of_skill2_from_character1>0 && !stopping_time){
              time_watting_of_skill2_from_character1--;
            }
}
