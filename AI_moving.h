#ifndef AI_MOVING_H_INCLUDED
#define AI_MOVING_H_INCLUDED
#include"texture.h"
#include<SDL.h>
#endif // AI_MOVING_H_INCLUDED


  //set AI moving and follow player
void set_AI_move(int mtdx_character1, int mtdy_character1,bool mcharacter2_can_not_move,
                 bool& mright_AI,bool& mleft_AI,int &mtdx_character2,int mtdy_character2,int mtime_in_game,int &mstart_time,
                 const int mwidth_of_screen,int &mcharacter2_frame,int &mtime_appearing_of_skill1_from_AI,
                 bool &mdid_character1_get_hit){


           if(mtdx_character2-mtdx_character1<-30 && !mcharacter2_can_not_move){
             mright_AI=true;
             mleft_AI=false;
           mtdx_character2=mtdx_character2+(SDL_GetTicks()-mtime_in_game-mstart_time)/1000;
           if((SDL_GetTicks()-mtime_in_game-mstart_time)/1000>4){ mstart_time=SDL_GetTicks()-mtime_in_game;}
           if(mtdx_character2>mwidth_of_screen){ mtdx_character2=mwidth_of_screen;}
           mcharacter2_frame++;
           if(mcharacter2_frame/20>=2){
             mcharacter2_frame=0;
           }
        }


         if(mtdx_character2-mtdx_character1>30 && !mcharacter2_can_not_move){
            mleft_AI=true;
            mright_AI=false;
           mtdx_character2=mtdx_character2-(SDL_GetTicks()-mtime_in_game-mstart_time)/1000;
           if((SDL_GetTicks()-mtime_in_game-mstart_time)/1000>4){ mstart_time=SDL_GetTicks()-mtime_in_game;}
           if(mtdx_character2<0){ mtdx_character2=0;}
           mcharacter2_frame++;
           if(mcharacter2_frame/20>=2){
             mcharacter2_frame=0;
           }
         }



         //****************************************//
           if(mtdx_character2-mtdx_character1<=30 && mtdx_character2-mtdx_character1>=-30 && mtdy_character2 == mtdy_character1){
              //
              if(mtdx_character2-mtdx_character1<0){
                mright_AI=true;
                mleft_AI=false;
              }
           //
              if(mtdx_character2-mtdx_character1>0){
                mright_AI=false;
                mleft_AI=true;
              }
            mcharacter2_frame=0;
            // health_bar_of_character1 is decreased when AI attack directly


             if((SDL_GetTicks()-mtime_in_game-mtime_appearing_of_skill1_from_AI)/200>=1){
                mdid_character1_get_hit=true;
              }
              else{ mdid_character1_get_hit=false; }

              //
              if((SDL_GetTicks()-mtime_in_game-mtime_appearing_of_skill1_from_AI)/200>=7){
                  mtime_appearing_of_skill1_from_AI=SDL_GetTicks()-mtime_in_game;
             }

              //


         }
         else{
             mtime_appearing_of_skill1_from_AI=SDL_GetTicks()-mtime_in_game;
         }

}

