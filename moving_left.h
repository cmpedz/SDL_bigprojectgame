#ifndef common_function
#define common_function
      common_function;
#endif // moving_left
   void movingleft(){
        if(left_1){
          character1_frame++;
          if(character1_frame/20>=4){
          character1_frame=0;
          left_1=false;
          }
        }
     }
