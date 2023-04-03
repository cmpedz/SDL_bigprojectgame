#include"gravity.h"
#include<SDL.h>
double set_gravity(double v,double time_end){
       double gravity=v*(-time_end+SDL_GetTicks())/300-10*(-time_end+SDL_GetTicks())*(-time_end+SDL_GetTicks())/(2*300*300);

       return gravity;
}
