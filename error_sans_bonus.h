#ifndef ERROR_SANS_BONUS_H_INCLUDED
#define ERROR_SANS_BONUS_H_INCLUDED
#include"texture.h"

long long saving_time_appearing_bonus=0;
const int anti_void_sprite=3;
int anti_void_frame=0;
SDL_Rect anti_void_clip[anti_void_sprite];
Ltexture anti_void;
long long time_appearing_of_anti_void=0;
long long saving_time_appearing_of_anti_void=0;
bool does_anti_void_appear=false;

Ltexture ink_sans;
const int ink_sans_sprite=4;
int ink_sans_frame=0;
SDL_Rect ink_sans_clip[ink_sans_sprite];
bool ink_sans_mvr=true;
bool did_character2_get_hit_by_ink;



long long time_appearing_of_ink_sans=0;
long long saving_time_appearing_of_ink_sans=0;
bool ink_sans_appear=false;
 int time_watting_for_skill1_of_ink_sans=0;

//set skill for ink sans
  int skill1_of_ink_frame=0;
  int time_appearing_of_skill1_from_ink_sans=0;
  bool does_skill1_of_ink_sans_active=false;
  int tdx_skill1_of_ink_sans=1000;
  int tdy_skill1_of_ink_sans=height_of_screen/4*3-100;
  int height_of_beam_from_ink_gb=0;
  int width_of_beam_from_ink_gb=0;
  int tdx_beam_of_ink_gb=0;
  int tdy_beam_of_ink_gb=tdy_skill1_of_ink_sans;


  const int quatity_of_frame_skill1_from_ink=3;
SDL_Rect skill1_of_ink_clip[quatity_of_frame_skill1_from_ink];
  Ltexture skill1_of_ink;
  Ltexture effect_for_skill1_of_ink;









#endif // ERROR_SANS_BONUS_H_INCLUDED
void reset_bonus(){

     does_anti_void_appear=false;
     ink_sans_frame=0;
     ink_sans_appear=false;
     anti_void_frame=0;
     ink_sans_mvr=true;

}

void set_value_for_anti_void(){


      anti_void.loadtexture("image/anti_void.bmp");
      anti_void.settdx(100);
      anti_void.settdy(height_of_screen/4*3-80);
      anti_void.setheight(170);
      anti_void.setwidth(239);

      anti_void_clip[0].h=340;
      anti_void_clip[0].w=311;
      anti_void_clip[0].x=109;
      anti_void_clip[0].y=0;

      anti_void_clip[1].h=340;
      anti_void_clip[1].w=367;
      anti_void_clip[1].x=109+311+179;
      anti_void_clip[1].y=0;

      anti_void_clip[2].h=340;
      anti_void_clip[2].w=477;
      anti_void_clip[2].x=109+311+179+118+367;
      anti_void_clip[2].y=0;

      if(ink_sans_mvr){
        ink_sans.loadtexture("image/ink_sans.bmp");
      }
      else{
        ink_sans.loadtexture("image/ink_sans_mvl.bmp");
      }
      ink_sans.setheight(60);
      ink_sans.setwidth(36);
      ink_sans.settdx(anti_void.gettdx()+50);
      ink_sans.settdy(height_of_screen/4*3);



         ink_sans_clip[0].h=31;
         ink_sans_clip[0].w=22;
         ink_sans_clip[0].x=22+10;
         ink_sans_clip[0].y=0;

         ink_sans_clip[1].h=31;
         ink_sans_clip[1].w=22;
         ink_sans_clip[1].x=0;
         ink_sans_clip[1].y=0;

         ink_sans_clip[2].h=31;
         ink_sans_clip[2].w=22;
         ink_sans_clip[2].x=22+10;
         ink_sans_clip[2].y=0;

         ink_sans_clip[3].h=31;
         ink_sans_clip[3].w=22;
         ink_sans_clip[3].x=(22+10)*2;
         ink_sans_clip[3].y=0;




}
void set_image_for_ink_sans_and_anti_void(){
     anti_void.loadtexture("image/anti_void.bmp");
     if(ink_sans_mvr){
        ink_sans.loadtexture("image/ink_sans.bmp");
      }
      else{
        ink_sans.loadtexture("image/ink_sans_mvl.bmp");
      }
}

void set_skill1_of_ink(bool stopping_time){

    //set ink gb value
    skill1_of_ink.loadtexture("image/ink_sans_gb.bmp");
      effect_for_skill1_of_ink.loadtexture("image/gb_beam.bmp");
         skill1_of_ink_clip[0].w=90;
         skill1_of_ink_clip[0].h=114;
         skill1_of_ink_clip[0].x=0;
         skill1_of_ink_clip[0].y=0;

         skill1_of_ink_clip[1].w=90;
         skill1_of_ink_clip[1].h=114;
         skill1_of_ink_clip[1].x=90;
         skill1_of_ink_clip[1].y=0;

         skill1_of_ink_clip[2].w=90;
         skill1_of_ink_clip[2].h=114;
         skill1_of_ink_clip[2].x=180;
         skill1_of_ink_clip[2].y=0;

      skill1_of_ink.settdx(tdx_skill1_of_ink_sans);
      skill1_of_ink.settdy(tdy_skill1_of_ink_sans);
      skill1_of_ink.setheight(44);
      skill1_of_ink.setwidth(60);

      effect_for_skill1_of_ink.settdx(tdx_beam_of_ink_gb);
      effect_for_skill1_of_ink.settdy(tdy_beam_of_ink_gb);
      effect_for_skill1_of_ink.setheight(height_of_beam_from_ink_gb);
      effect_for_skill1_of_ink.setwidth(width_of_beam_from_ink_gb);


      if(does_skill1_of_ink_sans_active){

         skill1_of_ink.render(&skill1_of_ink_clip[skill1_of_ink_frame/30]);

           if(skill1_of_ink_frame/30>=1){

            effect_for_skill1_of_ink.render(NULL);

           }


      }


       if(time_watting_for_skill1_of_ink_sans>0 && !stopping_time){
              time_watting_for_skill1_of_ink_sans--;
           }



}



void set_skill1_of_ink_sans_active(int tdx_character2,int tdy_character2,int &tdx_beam_of_ink_gb,
                                     int &tdx_skill1_of_ink_sans,int tdy_skill1_of_ink_sans
                                     ,int &height_of_beam_from_ink_gb,int &width_of_beam_from_ink_gb,int &tdy_beam_of_ink_gb,
                                     bool &did_character2_get_hit,bool stopping_time,int &skill1_of_ink_frame){
       if(!stopping_time) {height_of_beam_from_ink_gb=height_of_beam_from_ink_gb-tdy_character2+tdy_of_ground;}
       if(does_skill1_of_ink_sans_active){
          time_watting_for_skill1_of_ink_sans=30;
          if(skill1_of_ink_frame/30>=3){
             skill1_of_ink_frame=0;
             does_skill1_of_ink_sans_active=false;
             width_of_beam_from_ink_gb=0;
             height_of_beam_from_ink_gb=0;
             tdy_beam_of_ink_gb=tdy_skill1_of_ink_sans;
             tdx_beam_of_ink_gb=tdx_skill1_of_ink_sans;


          }


          if(skill1_of_ink_frame/30>=1){


            if(width_of_beam_from_ink_gb<60 && !stopping_time ){
               width_of_beam_from_ink_gb=width_of_beam_from_ink_gb+2;
               tdx_beam_of_ink_gb--;
            }
            if(height_of_beam_from_ink_gb<=height_of_screen/4){
               height_of_beam_from_ink_gb+=10;
            }

             if(tdx_character2<=tdx_beam_of_ink_gb+width_of_beam_from_ink_gb && tdx_character2>=tdx_beam_of_ink_gb && tdy_character2<=tdy_beam_of_ink_gb+height_of_beam_from_ink_gb){
                did_character2_get_hit=true;

            }
            else{did_character2_get_hit=false;}


          }
           if(!stopping_time) {skill1_of_ink_frame++;}
       }





}


void reset_skill1_of_ink_sans(){

     skill1_of_ink_frame=0;
     does_skill1_of_ink_sans_active=false;
     tdx_skill1_of_ink_sans=1000;
     tdy_skill1_of_ink_sans=height_of_screen/4*3-100;
     height_of_beam_from_ink_gb=height_of_screen/4;
     width_of_beam_from_ink_gb=0;
     tdx_beam_of_ink_gb=0;
     tdy_beam_of_ink_gb=0;
     time_appearing_of_ink_sans=SDL_GetTicks();
     time_appearing_of_anti_void=SDL_GetTicks();
     saving_time_appearing_of_anti_void=0;
     saving_time_appearing_of_ink_sans=0;
     time_watting_for_skill1_of_ink_sans=0;



}


void set_anti_void_appear(long long time_in_game,bool stopping_time,Ltexture character2,int tdx_character2,
                          int tdy_character2,bool &did_character2_get_hit){
     if((SDL_GetTicks()-time_in_game+saving_time_appearing_bonus)/1000%30==0 &&
        (SDL_GetTicks()-time_in_game+saving_time_appearing_bonus)!=0 &&
        !stopping_time){

        does_anti_void_appear=true;
        time_appearing_of_anti_void=SDL_GetTicks();
        saving_time_appearing_of_anti_void=0;

        ink_sans_appear=true;
        time_appearing_of_ink_sans=SDL_GetTicks();
        saving_time_appearing_of_ink_sans=0;
        ink_sans.settdx(anti_void.gettdx());
        ink_sans.settdy(height_of_screen/4*3);
        time_watting_for_skill1_of_ink_sans=0;

     }



     //set anti void appear

     if(does_anti_void_appear && (SDL_GetTicks()-time_appearing_of_anti_void+saving_time_appearing_of_anti_void)/1000<=10 &&
        !stopping_time){

         anti_void.render(&anti_void_clip[anti_void_frame/40]);

            anti_void_frame++;

            if(anti_void_frame/40>2){
                anti_void_frame=0;
            }

     }
     else{
         anti_void_frame=0;
         saving_time_appearing_of_anti_void=0;
         does_anti_void_appear=false;
     }


     //set ink sans appear

     if(ink_sans_appear && (SDL_GetTicks()-time_appearing_of_ink_sans+saving_time_appearing_of_ink_sans)/1000>=1 && !stopping_time){


        ink_sans.render(&ink_sans_clip[ink_sans_frame/10]);


         if(time_watting_for_skill1_of_ink_sans==0){
                          does_skill1_of_ink_sans_active=true;
                          tdx_skill1_of_ink_sans=character2.gettdx();
                          tdy_skill1_of_ink_sans=character2.gettdy()-100;
                          tdx_beam_of_ink_gb=tdx_skill1_of_ink_sans+30;
                          tdy_beam_of_ink_gb=tdy_skill1_of_ink_sans+50;
                          height_of_beam_from_ink_gb=0;
                          width_of_beam_from_ink_gb=0;
                          skill1_of_ink_frame=0;
         }


        set_skill1_of_ink(stopping_time);
         set_skill1_of_ink_sans_active(tdx_character2, tdy_character2,tdx_beam_of_ink_gb,
                                      tdx_skill1_of_ink_sans, tdy_skill1_of_ink_sans
                                     ,height_of_beam_from_ink_gb,width_of_beam_from_ink_gb,tdy_beam_of_ink_gb,
                                     did_character2_get_hit, stopping_time,skill1_of_ink_frame);





        if((SDL_GetTicks()-time_appearing_of_ink_sans+saving_time_appearing_of_ink_sans)/1000>=1 &&
           !stopping_time && (SDL_GetTicks()-time_appearing_of_ink_sans+saving_time_appearing_of_ink_sans)/1000<=8)
        {



            //set ink sans move and stop
            if(ink_sans.gettdx()<=300){
                ink_sans.settdx(ink_sans.gettdx()+5);
                 ink_sans_frame++;
                  if(ink_sans_frame/10>=4){
                    ink_sans_frame=0;
                 }

            }
            else{
                ink_sans_frame=0;
            }




        }


         if(!stopping_time && (SDL_GetTicks()-time_appearing_of_ink_sans+saving_time_appearing_of_ink_sans)/1000>8){
            ink_sans_mvr=false;
            set_image_for_ink_sans_and_anti_void();
            ink_sans.settdx(ink_sans.gettdx()-5);
            ink_sans_frame++;
            if(ink_sans_frame/10>=4){
                ink_sans_frame=0;
            }
            if(ink_sans.gettdx()<=150){
                ink_sans_appear=false;
            }

         }

     }
     else{
         saving_time_appearing_of_ink_sans=0;
         ink_sans_frame=0;
         does_skill1_of_ink_sans_active=false;
         ink_sans_mvr=true;

     }


}
