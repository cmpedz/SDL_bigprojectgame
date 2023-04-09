#include"gravity.h"
#include<SDL.h>
double set_gravity(double v,double time_end,double saving_time_jumping_when_stopping_game){
       double gravity=v*(-time_end+SDL_GetTicks()+saving_time_jumping_when_stopping_game)/300
       -10*(-time_end+SDL_GetTicks()+saving_time_jumping_when_stopping_game)*(-time_end+SDL_GetTicks()+saving_time_jumping_when_stopping_game)/(2*300*300);

       return gravity;
}
