#ifndef moving_left
#define moving_left
#include<SDL.h>
#include"common function.h"
      bool left_1=false;
      bool choose_left_1=false;
      double saving_time_running_left_of_ch1=0;
#endif // moving_left
   void reset_moving_left_of_ch1(){
        left_1=false;
        choose_left_1=false;
        saving_time_running_left_of_ch1=0;
   }


   void movingleft(bool &mleft_1,int &mcharacter1_frame,bool mchoose_left_1,double mtime_run_of_character1,
                   int &mtdx_character1,double saving_time_running_left_of_ch1){

         //set moving left for character1
        if(mchoose_left_1 && (SDL_GetTicks()-mtime_run_of_character1+saving_time_running_left_of_ch1)/1000<=1){
           mtdx_character1=mtdx_character1-4;
           if(mtdx_character1<0){
                 mtdx_character1=0;
              }
        }

        if(mleft_1){
          mcharacter1_frame++;
          if(mcharacter1_frame/10>=4){
          mcharacter1_frame=0;
          mleft_1=false;
          }
        }
     }
