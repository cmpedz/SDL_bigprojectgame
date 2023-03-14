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
