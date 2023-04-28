#ifndef TIME_WATTING_SKILL_OF_PLAYER_ICON_H_INCLUDED
#define TIME_WATTING_SKILL_OF_PLAYER_ICON_H_INCLUDED
#include"texture.h"
Ltexture icon_skill1_of_player;
Ltexture icon_time_watting_skill1;

Ltexture icon_skill2_of_player;
Ltexture icon_time_watting_skill2;

Ltexture icon_skill3_of_player;
Ltexture icon_time_watting_skill3;

Ltexture icon_miss_of_AI;
Ltexture icon_time_watting_miss_of_AI;

Ltexture icon_skill2_of_AI;
Ltexture icon_time_watting_skill2_of_AI;

#endif // TIME_WATTING_SKILL_OF_PLAYER_ICON_H_INCLUDED

void set_icon_skill_of_player(){
     icon_skill1_of_player.loadtexture("image/skill1_watting_sign.bmp");
     icon_skill1_of_player.settdx(50);
     icon_skill1_of_player.settdy(120);
     icon_skill1_of_player.setheight(50);
     icon_skill1_of_player.setwidth(50);

     icon_time_watting_skill1.loadtexture("image/it_is_just_white.bmp");
     icon_time_watting_skill1.settdx(50);
     icon_time_watting_skill1.settdy(120);
     icon_time_watting_skill1.setheight(0);
     icon_time_watting_skill1.setwidth(50);


     icon_skill2_of_player.loadtexture("image/skill2_watting_sign.bmp");
     icon_skill2_of_player.settdx(icon_skill1_of_player.gettdx()+icon_skill1_of_player.getwidth()+50);
     icon_skill2_of_player.settdy(120);
     icon_skill2_of_player.setheight(50);
     icon_skill2_of_player.setwidth(50);

     icon_time_watting_skill2.loadtexture("image/it_is_just_white.bmp");
     icon_time_watting_skill2.settdx(icon_skill1_of_player.gettdx()+icon_skill1_of_player.getwidth()+50);
     icon_time_watting_skill2.settdy(120);
     icon_time_watting_skill2.setheight(0);
     icon_time_watting_skill2.setwidth(50);


     icon_skill3_of_player.loadtexture("image/skill3_watting_sign.bmp");
     icon_skill3_of_player.settdx(icon_skill2_of_player.gettdx()+icon_skill2_of_player.getwidth()+50);
     icon_skill3_of_player.settdy(120);
     icon_skill3_of_player.setheight(50);
     icon_skill3_of_player.setwidth(50);


     icon_time_watting_skill3.loadtexture("image/it_is_just_white.bmp");
     icon_time_watting_skill3.settdx(icon_skill2_of_player.gettdx()+icon_skill2_of_player.getwidth()+50);
     icon_time_watting_skill3.settdy(120);
     icon_time_watting_skill3.setheight(50);
     icon_time_watting_skill3.setwidth(50);

     icon_miss_of_AI.loadtexture("image/miss_status.bmp");
     icon_miss_of_AI.settdx(980);
     icon_miss_of_AI.settdy(120);
     icon_miss_of_AI.setheight(50);
     icon_miss_of_AI.setwidth(100);

     icon_time_watting_miss_of_AI.loadtexture("image/it_is_just_white.bmp");
     icon_time_watting_miss_of_AI.settdx(980);
     icon_time_watting_miss_of_AI.settdy(120+50);
     icon_time_watting_miss_of_AI.setheight(0);
     icon_time_watting_miss_of_AI.setwidth(100);

     icon_skill2_of_AI.loadtexture("image/icon_skill2_of_AI.bmp");
     icon_skill2_of_AI.setheight(50);
     icon_skill2_of_AI.setwidth(50);
     icon_skill2_of_AI.settdy(icon_miss_of_AI.gettdy());
     icon_skill2_of_AI.settdx(icon_miss_of_AI.gettdx()-80);

     icon_time_watting_skill2_of_AI.loadtexture("image/it_is_just_white.bmp");
     icon_time_watting_skill2_of_AI.setheight(0);
     icon_time_watting_skill2_of_AI.setwidth(50);
     icon_time_watting_skill2_of_AI.settdy(icon_miss_of_AI.gettdy()+50);
     icon_time_watting_skill2_of_AI.settdx(icon_miss_of_AI.gettdx()-80);





}

void set_icon_skill_appear_and_active(int mtime_watting_for_skill1_of_character1,
                                int mtime_watting_of_skill2_from_character1,
                                int mtime_watting_of_skill3_from_character1,
                                int mtime_watting_teleport,
                                int time_watting_for_skill2_of_AI){

     icon_skill1_of_player.render(NULL);
     icon_skill2_of_player.render(NULL);
     icon_skill3_of_player.render(NULL);
     icon_miss_of_AI.render(NULL);
     icon_skill2_of_AI.render(NULL);


     icon_time_watting_skill1.setBlendMode(SDL_BLENDMODE_BLEND);
     icon_time_watting_skill1.setAlpha(100);
     icon_time_watting_skill2.setBlendMode(SDL_BLENDMODE_BLEND);
     icon_time_watting_skill2.setAlpha(100);
     icon_time_watting_skill3.setBlendMode(SDL_BLENDMODE_BLEND);
     icon_time_watting_skill3.setAlpha(100);
     icon_time_watting_miss_of_AI.setBlendMode(SDL_BLENDMODE_BLEND);
     icon_time_watting_miss_of_AI.setAlpha(100);
     icon_time_watting_skill2_of_AI.setBlendMode(SDL_BLENDMODE_BLEND);
     icon_time_watting_skill2_of_AI.setAlpha(100);



     icon_time_watting_skill1.render(NULL);
     icon_time_watting_skill2.render(NULL);
     icon_time_watting_skill3.render(NULL);
     icon_time_watting_miss_of_AI.render(NULL);
     icon_time_watting_skill2_of_AI.render(NULL);

     icon_time_watting_skill1.settdy(120+50-mtime_watting_for_skill1_of_character1);
     icon_time_watting_skill1.setheight(mtime_watting_for_skill1_of_character1);

     icon_time_watting_skill2.settdy(120+50-5*mtime_watting_of_skill2_from_character1/3);
     icon_time_watting_skill2.setheight(5*mtime_watting_of_skill2_from_character1/3);

     icon_time_watting_skill3.settdy(120+50-mtime_watting_of_skill3_from_character1/4);
     icon_time_watting_skill3.setheight(mtime_watting_of_skill3_from_character1/4);


     icon_time_watting_miss_of_AI.settdy(120+50-mtime_watting_teleport/4);
     icon_time_watting_miss_of_AI.setheight(mtime_watting_teleport/4);

     icon_time_watting_skill2_of_AI.settdy(120+50-time_watting_for_skill2_of_AI/4);
     icon_time_watting_skill2_of_AI.setheight(time_watting_for_skill2_of_AI/4);



}
