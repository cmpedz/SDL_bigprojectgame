#ifndef moving_right
#define moving_right
#include<SDL.h>
#include"common function.h"
#endif // moving_right
void movingright(bool &mright_1,int &mcharacter1_frame,bool mchoose_right_1,double mtime_run_of_character1,
                 int &mtdx_character1){

        if(mchoose_right_1 && (SDL_GetTicks()-mtime_run_of_character1)/1000<=1){ // SDL_GetTicks()-time_run_of_character1)/1000<=1 day la dk để di chuyển theo thời gian :))
              mtdx_character1=mtdx_character1+3;
              if(mtdx_character1>=1000){
                 mtdx_character1=1000;
              }
            }

        if(mright_1){
          mcharacter1_frame++;
          if(mcharacter1_frame/20>=4){
          mcharacter1_frame=0;
          mright_1=false;
          }
        }
}
