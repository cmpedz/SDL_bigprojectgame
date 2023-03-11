#ifndef common_function
#define common_function
 common_function;
#endif // moving_right
void movingright(){
        if(right_1){
          character1_frame++;
          if(character1_frame/20>=4){
          character1_frame=0;
          right_1=false;
          }
        }
     }
