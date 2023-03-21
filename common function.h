
#ifndef common_function // nếu common_function chưa đc định nghĩa thì thực hiện lệnh trong nó
#define common_function// định nghĩa common_function
#include<iostream>
using namespace std;
SDL_Window*window=NULL;
SDL_Renderer*renderer=NULL;
const int height_of_screen=680;
const int width_of_screen=1080;
const int tdy_of_ground=height_of_screen/4*3;
  int character1_frame=0;
  int tdx_character1=0;
  int tdy_character1=height_of_screen/4*3;

  int character2_frame=0;
  int tdx_character2=1000;
  int tdy_character2=height_of_screen/4*3;
 // set vector right or left for character 1
  double time_run_of_character1=0;
  bool choose_right_1=false;
   bool choose_left_1=false;
   bool right_1=true;
   bool left_1=false;

// set for AI
  bool right_AI=false;
  bool left_AI=false;
  int start_time=0;
  int chance_to_teleport=1;
  int time_appearing_of_skill1_from_AI=0;

  bool did_character1_get_hit=false;
  bool did_character2_get_hit=false;
  bool game_over=false;
  bool game_win=false;
  double health_bar_2_of_character1=400;
  double health_bar_2_of_character2=400;
  double tdx_health_bar_2_of_character2=1080-400;
  //
  int time_watting_for_skill2_of_AI=100;
  bool is_skill2_of_character2_actived=false;



  //set skill1 for character 1
  int skill1_of_character1_frame=0;
  int time_appearing_of_skill1_from_character1=0;
  bool does_skill1_of_character1_active=false;
  int tdx_skill1_of_character1=1000;
  int tdy_skill1_of_character1=height_of_screen/4*3-100;
  int height_of_beam=height_of_screen/4;
  int width_of_beam=0;
  int tdx_beam=0;
  int tdy_beam=0;
  int time_watting_for_skill1_of_character1=0;


  //set skill2 for character1
  int tdx_skill2_of_character1=tdx_character1;
  int tdy_skill2_of_character1=0;
  int time_watting_of_skill2_from_character1=0;
  int quatities_of_skill2_for_character1=0;
  bool left_for_skill2_of_character1=false;
  bool right_for_skill2_of_character1=false;


  // set skill3 for character 1
  bool does_skill3_of_character1_active=false;
  int time_appearing_of_skill3_from_character1=50;
  int time_watting_of_skill3_from_character1=0;
  bool character2_can_not_move=false;


  //set gravity for character1
  bool can_character1_jump=false;
  double set_time_in_the_air_of_character1=0;
  double v_of_character1=0;

  //set gravity for character2
  bool can_character2_jump=false;
  double set_time_in_the_air_of_character2=0;
  double v_of_character2=12;
  int chance_to_jump_of_AI=0;

  bool thay_doi_giao_dien_tu_man_hinh_chinh_sang_giao_dien_game=false;
  int time_in_game=0;
bool init(){
     bool success=true;
     if(SDL_Init(SDL_INIT_VIDEO)<0){
        cout<<"failed to load SDL"<<endl;
        success=false;
     }
     else{
         window=SDL_CreateWindow("sans vs chara new update",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width_of_screen,height_of_screen,SDL_WINDOW_SHOWN);
         if(window==NULL){
            cout<<"failed to load window"<<endl;
            success=false;
         }
         else{
             renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
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
}
#endif // common
