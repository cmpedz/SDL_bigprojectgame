
#ifndef common_function // nếu common_function chưa đc định nghĩa thì thực hiện lệnh trong nó
#define common_function// định nghĩa common_function
SDL_Window*window=NULL;
SDL_Renderer*renderer=NULL;
const int height_of_screen=680;
const int width_of_screen=1080;
  int character1_frame=0;
  int tdx_character1=0;
  int tdy_character1=680/4*3;

  int character2_frame=0;
  int tdx_character2=1000;
  int tdy_character2=680/4*3;

  bool choose_right_1=true;
   bool choose_left_1=false;
   bool right_1=false;
   bool left_1=false;

  bool right_AI=false;
  bool left_AI=false;
  int AI_stop_moving=0;
  int start_time=0;




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
