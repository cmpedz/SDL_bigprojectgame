#ifndef texture
#define texture
texture;
#endif // character
void AI(int tdx_character2,int tdx_character1, int tdy_character2,int tdy_character1,int character2_frame,bool r,bool l){
         const int quatity_of_frame_character2=2;
         SDL_Rect character2_clip[quatity_of_frame_character2];
         character2_clip[0].h=29;
         character2_clip[0].w=21;
         character2_clip[0].x=0;
         character2_clip[0].y=0;

         character2_clip[1].h=29;
         character2_clip[1].w=21;
         character2_clip[1].x=21;
         character2_clip[1].y=0;
        character2.settdx(tdx_character2);
        character2.settdy(tdy_character2);
        character2.setheight(60);
        character2.setwidth(36);
        if(r){
           character2.loadtexture("chara_moving_right.bmp");

        }
        if(l){
          character2.loadtexture("chara_moving_left.bmp");
        }

        character2.render(&character2_clip[character2_frame/20]);


      }
 void AI_skill1(){
     skill1_of_AI_clip[0].h=460;
        skill1_of_AI_clip[0].w=15;
        skill1_of_AI_clip[0].x=374;
        skill1_of_AI_clip[0].y=389;

        skill1_of_AI_clip[1].h=460;
        skill1_of_AI_clip[1].w=30;
        skill1_of_AI_clip[1].x=374+15+30;
        skill1_of_AI_clip[1].y=389;

        skill1_of_AI_clip[2].h=460;
        skill1_of_AI_clip[2].w=30;
        skill1_of_AI_clip[2].x=374+15+30+30+20;
        skill1_of_AI_clip[2].y=389;

        skill1_of_AI_clip[3].h=460;
        skill1_of_AI_clip[3].w=46;
        skill1_of_AI_clip[3].x=374+15+30+30+20+59;
        skill1_of_AI_clip[3].y=389;


        skill1_of_AI_clip[4].h=460;
        skill1_of_AI_clip[4].w=59;
        skill1_of_AI_clip[4].x=374+15+30+30+20+59+46+85;
        skill1_of_AI_clip[4].y=389;

        skill1_of_AI_clip[5].h=460;
        skill1_of_AI_clip[5].w=106;
        skill1_of_AI_clip[5].x=374+15+30+30+20+59+46+85+59+139;
        skill1_of_AI_clip[5].y=389;

        skill1_of_AI_clip[6].h=460;
        skill1_of_AI_clip[6].w=104;
        skill1_of_AI_clip[6].x=374+15+30+30+20+59+46+85+59+139+106+99;
        skill1_of_AI_clip[6].y=389;

        skill1_of_AI.loadtexture("chara_hit_directly.bmp");
        skill1_of_AI.settdx(500);
        skill1_of_AI.settdy(340);
        skill1_of_AI.setheight(60);
        skill1_of_AI.setwidth(36);

 }

