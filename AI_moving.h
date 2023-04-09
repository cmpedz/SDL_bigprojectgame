#ifndef AI_MOVING_H_INCLUDED
#define AI_MOVING_H_INCLUDED
#include"texture.h"
#include<SDL.h>
#include"gravity.h"
// set for AI
  bool right_AI=false;
  bool left_AI=false;
  long long start_time=0;
  int chance_to_teleport=0;
  int time_watting_teleport=0;
  int time_appearing_of_skill1_from_AI=0;
  long long saving_time_running_of_AI=0;
  long long saving_time_skill1_of_AI=0;
  double saving_time_jumping_when_stopping_game2=0;

    bool can_character2_jump=false;
  double set_time_in_the_air_of_character2=0;
  double v_of_character2=12;
  int chance_to_jump_of_AI=0;

#endif // AI_MOVING_H_INCLUDED
void reset_skill1_and_moving_of_ch2(){
     right_AI=false;
     left_AI=false;
     start_time=0;
     chance_to_teleport=0;
     time_watting_teleport=0;
     time_appearing_of_skill1_from_AI=0;
     saving_time_running_of_AI=0;
     saving_time_skill1_of_AI=0;
     saving_time_jumping_when_stopping_game2=0;

        can_character2_jump=false;
        set_time_in_the_air_of_character2=0;
        v_of_character2=12;
        chance_to_jump_of_AI=100;

}

  //set AI moving and follow player
void set_AI_move(int mtdx_character1, int mtdy_character1,bool mcharacter2_can_not_move,
                 bool& mright_AI,bool& mleft_AI,int &mtdx_character2,int mtdy_character2,long long mtime_in_game,long long &mstart_time,
                 const int mwidth_of_screen,int &mcharacter2_frame,int &mtime_appearing_of_skill1_from_AI,
                 bool &mdid_character1_get_hit,long long saving_time_running_of_AI,bool stopping_time,
                 long long saving_time_skill1_of_AI){


           if(mtdx_character2-mtdx_character1<-30 && !mcharacter2_can_not_move){
             mright_AI=true;
             mleft_AI=false;
           mtdx_character2=mtdx_character2+(SDL_GetTicks()-mtime_in_game-mstart_time+saving_time_running_of_AI)/1000;
           if((SDL_GetTicks()-mtime_in_game-mstart_time+saving_time_running_of_AI)/1000>4){ mstart_time=SDL_GetTicks()-mtime_in_game+saving_time_running_of_AI;}
           if(mtdx_character2>mwidth_of_screen){ mtdx_character2=mwidth_of_screen;}

           if(!stopping_time) {mcharacter2_frame++;}

           if(mcharacter2_frame/20>=2){
             mcharacter2_frame=0;
           }
        }


         if(mtdx_character2-mtdx_character1>30 && !mcharacter2_can_not_move){
            mleft_AI=true;
            mright_AI=false;
           mtdx_character2=mtdx_character2-(SDL_GetTicks()-mtime_in_game-mstart_time+saving_time_running_of_AI)/1000;
           if((SDL_GetTicks()-mtime_in_game-mstart_time+saving_time_running_of_AI)/1000>4){ mstart_time=SDL_GetTicks()-mtime_in_game+saving_time_running_of_AI;}
           if(mtdx_character2<0){ mtdx_character2=0;}

           if(!stopping_time) {mcharacter2_frame++;}

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


             if((SDL_GetTicks()-mtime_in_game-mtime_appearing_of_skill1_from_AI+saving_time_skill1_of_AI)/200>=1){
                mdid_character1_get_hit=true;
              }
              else{ mdid_character1_get_hit=false; }

              //
              if((SDL_GetTicks()-mtime_in_game-mtime_appearing_of_skill1_from_AI+saving_time_skill1_of_AI)/200>=7){
                  mtime_appearing_of_skill1_from_AI=SDL_GetTicks()-mtime_in_game+saving_time_skill1_of_AI;
             }

              //


         }
         else{
             mtime_appearing_of_skill1_from_AI=SDL_GetTicks()-mtime_in_game+saving_time_skill1_of_AI;
         }

}



void set_AI_dodge(int _quatities_of_bone,bool _is_ingradient_of_skill2_from_character1_actived[],
                  int &_tdx_character2,int _tdx_character1,int _tdx_for_ingradient_of_skill2_character1[],int &_chance_to_jump_of_AI,
                  bool &_can_character2_jump,double &_set_time_in_the_air_of_character2,int &_tdy_character2,
                  const int _tdy_of_ground,int _v_of_character2,bool _does_skill1_of_character1_active,
                  int &_chance_to_teleport,int &_time_watting_teleport,bool _character2_can_not_move,
                  bool &_key_active_effect_miss,double saving_time_jumping_when_stopping_game2,bool &stopping_time){

      //set AI dodges skill1
       if((_does_skill1_of_character1_active) && _chance_to_teleport==0
          && _time_watting_teleport==0 && !_character2_can_not_move){
             if(_tdx_character1-_tdx_character2<0){
                _tdx_character2=_tdx_character2-50;
                if(_tdx_character2<0){ _tdx_character2=0;}
             }

             if(_tdx_character1-_tdx_character2>0){
                _tdx_character2=_tdx_character2+50;
                if(_tdx_character2>1000){ _tdx_character2=1000;}
            }
            _key_active_effect_miss=true;
            _chance_to_teleport=-1;

        }

     if(_time_watting_teleport>0 && !stopping_time){
      _time_watting_teleport--;
     }









     // AI dodges skill2
                for(int i=0;i<_quatities_of_bone;i++){
                  if(_is_ingradient_of_skill2_from_character1_actived[i]){
                    if(abs(_tdx_character2<=_tdx_for_ingradient_of_skill2_character1[i])<10 ){
                          if(_chance_to_jump_of_AI==0){
                             if(!stopping_time){
                                 saving_time_jumping_when_stopping_game2=0;
                             }
                            _can_character2_jump=true;
                            _set_time_in_the_air_of_character2=SDL_GetTicks();
                            _chance_to_jump_of_AI=100;
                          }
                    }

                  }
                }

                if((_tdy_character2<_tdy_of_ground || _can_character2_jump) && !stopping_time){
                        _tdy_character2=tdy_character2-set_gravity(_v_of_character2,_set_time_in_the_air_of_character2,saving_time_jumping_when_stopping_game2);
                        if(_tdy_character2>=_tdy_of_ground){
                            _tdy_character2=_tdy_of_ground;

                         }
                         else{
                             _can_character2_jump=false;
                         }

                 }

                if(_chance_to_jump_of_AI!=0 && !stopping_time){
                   _chance_to_jump_of_AI--;
                }



                //set AI jump
                if(tdy_character1<tdy_character2 && tdx_character2-tdx_character1<=30 && tdx_character2-tdx_character1>=-30){
                        if(chance_to_jump_of_AI==0 && !stopping_time){
                            can_character2_jump=true;
                            set_time_in_the_air_of_character2=SDL_GetTicks();
                            chance_to_jump_of_AI=100;
                          }
                }




}



