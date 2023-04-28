
#ifndef common_function // nếu common_function chưa đc định nghĩa thì thực hiện lệnh trong nó
#define common_function// định nghĩa common_function
#include<iostream>
using namespace std;
SDL_Window*window=NULL;
SDL_Renderer*renderer=NULL;
const int height_of_screen=680;
const int width_of_screen=1080;
int SCREEN_FPS = 60;
int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
double time_run_of_character1=0;
const int tdy_of_ground=height_of_screen/4*3;

  bool thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
  bool reset_everything_in_main_interface=false;
  bool reset_everything_in_game=false;
  int time_watting_change_interface=5;
  int quality_of_click=0;

bool init(){
     bool success=true;
      //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO  ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
     else{

          if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}


         window=SDL_CreateWindow(" Sans vs Chara (by cmpedz) ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width_of_screen,height_of_screen,SDL_WINDOW_SHOWN);
         if(window==NULL){
            cout<<"failed to load window"<<endl;
            success=false;
         }
         else{
             renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
             	if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}

				 //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }

         }
     }
     return success;
}

void close(){
     SDL_DestroyRenderer(renderer);
     renderer=NULL;
     SDL_DestroyWindow(window);
     window=NULL;
     SDL_Quit();
     Mix_Quit();
}

void free_memory_about_time(){

     time_run_of_character1=0;

     quality_of_click=0;


}
#endif // common
