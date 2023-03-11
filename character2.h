#ifndef texture
#define texture
texture;
#endif // character
void AI(int tdx_character2, int tdy_character2,int character2_frame,bool r,bool l){
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
 void AI_skill1(int AI_frame){
        skill1_of_AI.loadtexture("chara_hit_directly.bmp");
        skill1_of_AI.setheight(45);
        skill1_of_AI.setwidth(10);
        skill1_of_AI.settdx(character1.gettdx()+5);
        skill1_of_AI.settdy(character1.gettdy()+5);

        if(AI_frame==0){
           skill1_of_AI.setheight(5);
           skill1_of_AI.setwidth(5);
        }
        skill1_of_AI_clip[0].h=15;
        skill1_of_AI_clip[0].w=15;
        skill1_of_AI_clip[0].x=375;
        skill1_of_AI_clip[0].y=400;

         if(AI_frame==1){
           skill1_of_AI.setheight(6);
           skill1_of_AI.setwidth(12);
        }
        skill1_of_AI_clip[1].h=55;
        skill1_of_AI_clip[1].w=30;
        skill1_of_AI_clip[1].x=375+15+30;
        skill1_of_AI_clip[1].y=400;

        if(AI_frame==2){
           skill1_of_AI.setheight(24);
           skill1_of_AI.setwidth(4);
        }
        skill1_of_AI_clip[2].h=180;
        skill1_of_AI_clip[2].w=30;
        skill1_of_AI_clip[2].x=375+15+30+30+20;
        skill1_of_AI_clip[2].y=400;

         if(AI_frame==3){
           skill1_of_AI.setheight(60);
           skill1_of_AI.setwidth(10);
        }
        skill1_of_AI_clip[3].h=300;
        skill1_of_AI_clip[3].w=45;
        skill1_of_AI_clip[3].x=375+15+30+30+20+30+60;
        skill1_of_AI_clip[3].y=400;

        if(AI_frame==4){
           skill1_of_AI.setheight(60);
           skill1_of_AI.setwidth(30);
        }
        skill1_of_AI_clip[4].h=452;
        skill1_of_AI_clip[4].w=184;
        skill1_of_AI_clip[4].x=375+15+30+30+20+30+60+45+70;
        skill1_of_AI_clip[4].y=400;

        if(AI_frame==5){
           skill1_of_AI.setheight(40);
           skill1_of_AI.setwidth(20);
        }
        skill1_of_AI_clip[5].h=260;
        skill1_of_AI_clip[5].w=106;
        skill1_of_AI_clip[5].x=375+15+30+30+20+30+60+45+70+184;
        skill1_of_AI_clip[5].y=400;

        if(AI_frame==6){
           skill1_of_AI.setheight(10);
           skill1_of_AI.setwidth(20);
        }

        skill1_of_AI_clip[6].h=55;
        skill1_of_AI_clip[6].w=106;
        skill1_of_AI_clip[6].x=375+15+30+30+20+30+60+45+70+184+106+99;
        skill1_of_AI_clip[6].y=400;

 }

