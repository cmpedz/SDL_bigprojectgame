#ifndef texture
#define texture
texture
#endif // texture

const int quatities_of_bone=3;
Ltexture skill2_of_character1[quatities_of_bone];
int tdx_for_ingradient_of_skill2_character1[quatities_of_bone];
int tdy_for_ingradient_of_skill2_character1[quatities_of_bone];
bool is_ingradient_of_skill2_from_character1_actived[quatities_of_bone];
bool reset_tdx_and_tdy_of_skill2_from_character1=false;
int vector_for_ingradient_of_character1[quatities_of_bone];


void set_value_for_ingradient_of_skill2_of_character1(){
     for(int i=0;i<quatities_of_bone;i++){
        tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
        tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
        skill2_of_character1[i].loadtexture("bone.bmp");
        is_ingradient_of_skill2_from_character1_actived[i]=false;
        vector_for_ingradient_of_character1[i]=0;
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


void set_skill2_of_character1_actived(int quatities_of_skill2_for_character1,int tdx_for_ingradient_of_skill2_character1[],int tdy_for_ingradient_of_skill2_character1[],bool is_ingradient_of_skill2_from_character1_actived[],int &time_watting_of_skill2_from_character1){
      for(int i=0;i<quatities_of_skill2_for_character1;i++){
          if(tdx_for_ingradient_of_skill2_character1[2]>=1080 || tdx_for_ingradient_of_skill2_character1[2]<=0){
             time_watting_of_skill2_from_character1=30;
             reset_tdx_and_tdy_of_skill2_from_character1=true;
          }
          if(tdx_for_ingradient_of_skill2_character1[i]>=1080 || tdx_for_ingradient_of_skill2_character1[i]<=0){
             //tdx_for_ingradient_of_skill2_character1[i]=tdx_character1;
             //tdy_for_ingradient_of_skill2_character1[i]=tdy_character1;
             is_ingradient_of_skill2_from_character1_actived[i]=false;
             vector_for_ingradient_of_character1[i]=0;
          }
          if(is_ingradient_of_skill2_from_character1_actived[i]){
             skill2_of_character1[i].settdx(tdx_for_ingradient_of_skill2_character1[i]);
             skill2_of_character1[i].settdy(tdy_for_ingradient_of_skill2_character1[i]);
             skill2_of_character1[i].render(NULL);
          }
      }
}
