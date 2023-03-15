#ifndef texture
#define texture
texture
#endif // texture

       void set_health_bar_for_character1(double health_bar_2_of_character1){
         character1_face.loadtexture("sans_face.bmp");
         character1_face.settdx(0);
         character1_face.settdy(0);
         character1_face.setheight(120);
         character1_face.setwidth(128);

         health_bar_2_for_character1.setheight(120);
         health_bar_2_for_character1.setwidth(health_bar_2_of_character1);
         health_bar_2_for_character1.settdx(0);
         health_bar_2_for_character1.settdy(0);
         health_bar_2_for_character1.loadtexture("health_bar_2.bmp");

         health_bar_2_for_character1.render(NULL);
         character1_face.render(NULL);
      }

       void set_health_bar_for_character2(double health_bar_2_of_character2,double tdx_health_bar_2_of_character2){
         character2_face.loadtexture("chara_face.bmp");
         character2_face.settdx(1080-128);
         character2_face.settdy(0);
         character2_face.setheight(120);
         character2_face.setwidth(128);


         health_bar_2_for_character2.setheight(120);
         health_bar_2_for_character2.setwidth(health_bar_2_of_character2);
         health_bar_2_for_character2.settdx(tdx_health_bar_2_of_character2);
         health_bar_2_for_character2.settdy(0);
         health_bar_2_for_character2.loadtexture("health_bar_2.bmp");

         health_bar_2_for_character2.render(NULL);
         character2_face.render(NULL);

      }



      Ltexture lose_health_1;
      int tdx_of_losing_effect1=0;
      int tdy_of_losing_effect1=0;
      bool key_active_effect_of_losing_health1=false;

      Ltexture lose_health_2;
      int tdx_of_losing_effect2=0;
      int tdy_of_losing_effect2=0;
      bool key_active_effect_of_losing_health2=false;


      void set_lose_health_1(){
           tdx_of_losing_effect1=tdx_character1+5;
           tdy_of_losing_effect1=height_of_screen/4*3;
           lose_health_1.loadtexture("health_effect_-1.bmp");
           lose_health_1.setheight(12);
           lose_health_1.setwidth(12);
           lose_health_1.settdx(tdx_of_losing_effect1);
           lose_health_1.settdy(tdy_of_losing_effect1);
      }
         void set_lose_health_2(){
           tdx_of_losing_effect2=tdx_character2+5;
           tdy_of_losing_effect2=height_of_screen/4*3;
           lose_health_2.loadtexture("health_effect_-1.bmp");
           lose_health_2.setheight(12);
           lose_health_2.setwidth(12);
           lose_health_2.settdx(tdx_of_losing_effect2);
           lose_health_2.settdy(tdy_of_losing_effect2);
      }




      void set_lose_health_1_appear(int x,int y){
          if(key_active_effect_of_losing_health1){
           tdx_of_losing_effect1=x+5;
           lose_health_1.setheight(36);
           lose_health_1.setwidth(36);
           lose_health_1.settdx(tdx_of_losing_effect1);
           lose_health_1.settdy(tdy_of_losing_effect1);
           lose_health_1.render(NULL);
           tdy_of_losing_effect1=tdy_of_losing_effect1-1;
          }
          else{
              tdy_of_losing_effect1=height_of_screen/4*3;
          }

      }


       void set_lose_health_2_appear(int x,int y){
          if(key_active_effect_of_losing_health2){
           tdx_of_losing_effect2=x+5;
           lose_health_2.setheight(36);
           lose_health_2.setwidth(36);
           lose_health_2.settdx(tdx_of_losing_effect2);
           lose_health_2.settdy(tdy_of_losing_effect2);
           lose_health_2.render(NULL);
           tdy_of_losing_effect2=tdy_of_losing_effect2-1;
          }
          else{
              tdy_of_losing_effect2=height_of_screen/4*3;
          }

      }
