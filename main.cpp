#include <iostream>
using namespace std;
#include<SDL.h>
#include"common function.h"
#include"loadmedia.h"
#include"texture.h"
#include"background.h"
#include"character.h"
#include"character2.h"
#include"moving_right.h"
#include"moving_left.h"
#include"event loop.h"
int main(int arcg,char*argv[])
{
  eventloop();
  /*if(!init()){
     cout<<"failed to load SDL"<<endl;
  }
  else{
      if(!loadedmedia(true)){
         cout<<"failed to load media"<<endl;
      }
  else{
   bool quit=false;
   SDL_Event e;
   while(!quit){
           while(SDL_PollEvent(&e)!=0){
                if(e.type==SDL_QUIT){
                  quit=true;
                }
           }

                SDL_RenderClear(renderer);
                AI_skill1();
                if(skill_attack_directly_of_AI_frame/5>=7){
                  skill_attack_directly_of_AI_frame=7;
                }
                skill1_of_AI.render(&skill1_of_AI_clip[skill_attack_directly_of_AI_frame/5]);
                skill_attack_directly_of_AI_frame++;
                cout<<skill_attack_directly_of_AI_frame<<endl;
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
   }
  }
  }*/
  return 0;
}
