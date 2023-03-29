#ifndef moving_left
#define moving_left
#include<SDL.h>
#include"common function.h"
#endif // moving_left
   void movingleft(bool &mleft_1,int &mcharacter1_frame,bool mchoose_left_1,int mtime_run_of_character1,
                   int &mtdx_character1){

         //set moving left for character1
        if(mchoose_left_1 && (SDL_GetTicks()-mtime_run_of_character1)/1000<=1){
           mtdx_character1=mtdx_character1-3;
           if(mtdx_character1<0){
                 mtdx_character1=0;
              }
        }

        if(mleft_1){
          mcharacter1_frame++;
          if(mcharacter1_frame/20>=4){
          mcharacter1_frame=0;
          mleft_1=false;
          }
        }
     }
