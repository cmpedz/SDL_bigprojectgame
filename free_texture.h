#ifndef FREE_TEXTURE_H_INCLUDED
#define FREE_TEXTURE_H_INCLUDED
#include"texture.h"

#endif // FREE_TEXTURE_H_INCLUDED
void free_texture(Ltexture character1,Ltexture character2,Ltexture skill1_of_AI,Ltexture background,
                  Ltexture character1_face,Ltexture character2_face,Ltexture health_bar_1_for_character1,
                  Ltexture health_bar_1_for_character2,Ltexture health_bar_2_for_character1,
                  Ltexture health_bar_2_for_character2,Ltexture character2_skill2,
                  Ltexture game_over_class,Ltexture get_dunked_on,Ltexture skill1_of_character1,
                  Ltexture skill3_of_character1,Ltexture effect_miss_of_AI,Ltexture no_effect_of_player,
                  Ltexture skill1_of_ink,Ltexture effect_for_skill1_of_ink){
          character1.free();
           character2.free();
           skill1_of_AI.free(); // need to be added in your code
           background.free();
           character1_face.free();
           character2_face.free();
           health_bar_1_for_character1.free();
           health_bar_1_for_character2.free();
           health_bar_2_for_character1.free();
           health_bar_2_for_character2.free();
           character2_skill2.free();
           game_over_class.free();
           get_dunked_on.free();
           skill1_of_character1.free();
           skill3_of_character1.free();
           effect_miss_of_AI.free();
          no_effect_of_player.free();

          skill1_of_ink.free();
          effect_for_skill1_of_ink.free();
          ink_sans.free();
          anti_void.free();





}

void free_font_texture(Ltexture Tilte_of_bg_tutorial_Menu){
     Tilte_of_bg_tutorial_Menu.free();

}
