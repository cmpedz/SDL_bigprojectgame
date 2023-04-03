#ifndef texture
#define texture
texture
#endif // texture
const int quatity_of_frame_skill1_from_character1=3;
SDL_Rect skill1_of_character1_clip[quatity_of_frame_skill1_from_character1];
void set_skill1_of_character1(int tdx_skill1_of_character1,int tdy_skill1_of_character1,
                              int height_of_beam, int width_of_beam,int tdx_beam,int tdy_beam,
                              int &time_watting_for_skill1_of_character1){
      skill1_of_character1.loadtexture("gb.bmp");
      effect_for_skill1_of_character1.loadtexture("gb_beam.bmp");
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

      if(time_watting_for_skill1_of_character1>0){
              time_watting_for_skill1_of_character1--;
           }



}
void set_skill1_of_character1_active(int tdy_character2,int &tdx_beam,
                                     int &tdx_skill1_of_character1,int tdy_skill1_of_character1
                                     ,int &height_of_beam,int &width_of_beam,int &tdy_beam,
                                     int &time_watting_for_skill1_of_character1,bool &did_character2_get_hit){
       height_of_beam=height_of_beam-tdy_character2+tdy_of_ground;
       if(does_skill1_of_character1_active){
          time_watting_for_skill1_of_character1=50;
          if(skill1_of_character1_frame/30>=3){
             skill1_of_character1_frame=0;
             does_skill1_of_character1_active=false;
             width_of_beam=0;
             tdx_beam=tdx_skill1_of_character1;
             height_of_beam=height_of_screen/4;
          }
          skill1_of_character1.render(&skill1_of_character1_clip[skill1_of_character1_frame/30]);
          if(skill1_of_character1_frame/30>=1){
            effect_for_skill1_of_character1.render(NULL);
            if(width_of_beam<60){
               width_of_beam=width_of_beam+2;
               tdx_beam--;
            }

          }
          skill1_of_character1_frame++;
       }

       if(tdx_character2<=tdx_beam+20 && tdx_character2>=tdx_beam-20 && tdy_character2>=tdy_beam){
              did_character2_get_hit=true;
           }
           else{did_character2_get_hit=false;}



}


