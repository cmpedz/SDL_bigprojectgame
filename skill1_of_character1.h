#ifndef skill1_of_ch1
#define skill1_of_ch1
#include"texture.h"
//set skill1 for character 1
  int skill1_of_character1_frame=0;
  int time_appearing_of_skill1_from_character1=0;
  bool does_skill1_of_character1_active=false;
  int tdx_skill1_of_character1=1000;
  int tdy_skill1_of_character1=height_of_screen/4*3-100;
  int height_of_beam=0;
  int width_of_beam=0;
  int tdx_beam=0;
  int tdy_beam=tdy_skill1_of_character1;
  int time_watting_for_skill1_of_character1=0;

  const int quatity_of_frame_skill1_from_character1=3;
SDL_Rect skill1_of_character1_clip[quatity_of_frame_skill1_from_character1];
  Ltexture skill1_of_character1;
  Ltexture effect_for_skill1_of_character1;
  bool did_character2_get_hit_by_skill1=false;
#endif // texture

void set_skill1_of_character1(int tdx_skill1_of_character1,int tdy_skill1_of_character1,
                              int height_of_beam, int width_of_beam,int tdx_beam,int tdy_beam,
                              int &time_watting_for_skill1_of_character1,bool stopping_time,Ltexture skill1_of_character1,
                              Ltexture effect_for_skill1_of_character1,bool does_skill1_of_character1_active,
                              int skill1_of_character1_frame,bool choose_skin1,bool choose_skin2){
    if(choose_skin1){
      skill1_of_character1.loadtexture("image/gb.bmp");
      effect_for_skill1_of_character1.loadtexture("image/gb_beam.bmp");
         skill1_of_character1_clip[0].w=90;
         skill1_of_character1_clip[0].h=114;
         skill1_of_character1_clip[0].x=0;
         skill1_of_character1_clip[0].y=0;

         skill1_of_character1_clip[1].w=90;
         skill1_of_character1_clip[1].h=114;
         skill1_of_character1_clip[1].x=90;
         skill1_of_character1_clip[1].y=0;

         skill1_of_character1_clip[2].w=90;
         skill1_of_character1_clip[2].h=114;
         skill1_of_character1_clip[2].x=180;
         skill1_of_character1_clip[2].y=0;

      skill1_of_character1.settdx(tdx_skill1_of_character1);
      skill1_of_character1.settdy(tdy_skill1_of_character1);
      skill1_of_character1.setheight(44);
      skill1_of_character1.setwidth(60);

      effect_for_skill1_of_character1.settdx(tdx_beam);
      effect_for_skill1_of_character1.settdy(tdy_beam);
      effect_for_skill1_of_character1.setheight(height_of_beam);
      effect_for_skill1_of_character1.setwidth(width_of_beam);


      if(does_skill1_of_character1_active){

         skill1_of_character1.render(&skill1_of_character1_clip[skill1_of_character1_frame/30]);

           if(skill1_of_character1_frame/30>=1){

            effect_for_skill1_of_character1.render(NULL);

           }


      }

      if(time_watting_for_skill1_of_character1>0 && !stopping_time){
              time_watting_for_skill1_of_character1--;
           }
    }


    if(choose_skin2){
        skill1_of_character1.loadtexture("image/error_blaster.bmp");
      effect_for_skill1_of_character1.loadtexture("image/error_gb_beam.bmp");
         skill1_of_character1_clip[0].w=132;
         skill1_of_character1_clip[0].h=192;
         skill1_of_character1_clip[0].x=0;
         skill1_of_character1_clip[0].y=0;

         skill1_of_character1_clip[1].w=152;
         skill1_of_character1_clip[1].h=192;
         skill1_of_character1_clip[1].x=132+13;
         skill1_of_character1_clip[1].y=0;

         skill1_of_character1_clip[2].w=147;
         skill1_of_character1_clip[2].h=192;
         skill1_of_character1_clip[2].x=132+13+152+15;
         skill1_of_character1_clip[2].y=0;

      skill1_of_character1.settdx(tdx_skill1_of_character1);
      skill1_of_character1.settdy(tdy_skill1_of_character1);
      skill1_of_character1.setheight(44);
      skill1_of_character1.setwidth(60);

      effect_for_skill1_of_character1.settdx(tdx_beam);
      effect_for_skill1_of_character1.settdy(tdy_beam);
      effect_for_skill1_of_character1.setheight(height_of_beam);
      effect_for_skill1_of_character1.setwidth(width_of_beam);


      if(does_skill1_of_character1_active){

         skill1_of_character1.render(&skill1_of_character1_clip[skill1_of_character1_frame/30]);

           if(skill1_of_character1_frame/30>=1){

            effect_for_skill1_of_character1.render(NULL);

           }


      }

      if(time_watting_for_skill1_of_character1>0 && !stopping_time){
              time_watting_for_skill1_of_character1--;
           }


    }


}
void set_skill1_of_character1_active(int tdy_character2,int &tdx_beam,
                                     int &tdx_skill1_of_character1,int tdy_skill1_of_character1
                                     ,int &height_of_beam,int &width_of_beam,int &tdy_beam,
                                     int &time_watting_for_skill1_of_character1,bool &did_character2_get_hit_by_skill1,
                                     bool stopping_time,Ltexture skill1_of_character1,Ltexture effect_for_skill1_of_character1,
                                     int &skill1_of_character1_frame){
       if(!stopping_time) {height_of_beam=height_of_beam-tdy_character2+tdy_of_ground;}
       if(does_skill1_of_character1_active){
          time_watting_for_skill1_of_character1=50;
          if(skill1_of_character1_frame/30>=3){
             skill1_of_character1_frame=0;
             does_skill1_of_character1_active=false;
             width_of_beam=0;
             height_of_beam=0;
             tdy_beam=tdy_skill1_of_character1;
             tdx_beam=tdx_skill1_of_character1;

          }


          if(skill1_of_character1_frame/30>=1){


            if(width_of_beam<60 && !stopping_time ){
               width_of_beam=width_of_beam+2;
               tdx_beam--;
            }
            if(height_of_beam<=height_of_screen/4){
               height_of_beam+=10;
            }

             if(tdx_character2<=tdx_beam+width_of_beam && tdx_character2>=tdx_beam && tdy_character2<=tdy_beam+height_of_beam){
                did_character2_get_hit_by_skill1=true;

            }
            else{did_character2_get_hit_by_skill1=false;}


          }
           if(!stopping_time) {skill1_of_character1_frame++;}
       }





}


void reset_skill1_of_ch1(Ltexture skill1_of_character1){
       //set skill1 for character 1
     skill1_of_character1_frame=0;
     time_appearing_of_skill1_from_character1=0;
     does_skill1_of_character1_active=false;
     tdx_skill1_of_character1=1000;
     tdy_skill1_of_character1=height_of_screen/4*3-100;
     height_of_beam=height_of_screen/4;
     width_of_beam=0;
     tdx_beam=0;
     tdy_beam=0;
     time_watting_for_skill1_of_character1=0;




}


