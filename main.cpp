#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"../library/gravity.h"
#include"../library/common function.h"
#include"../library/loadmedia.h"
#include"../library/texture.h"
#include"../library/font_in_game.h"
#include"../library/timer.h"
#include"../library/button.h"
#include"../library/giao_dien_game.h"
#include"../library/choice_menu.h"
#include"../library/choose_skin_interface.h"
#include"../library/choose_map.h"
#include"../library/choose_level.h"
#include"../library/tutorial_background.h"
#include"../library/background.h"
#include"../library/time_watting_skill_of_player_icon.h"
#include"../library/pause_button_icon.h"
#include"../library/error_sans_bonus.h"
#include"../library/character.h"
#include"../library/character2.h"
#include"../library/miss_effect.h"
#include"../library/no_effect.h"
#include"../library/character2_skill2.h"
#include"../library/character2_skill3.h"
#include"../library/AI_moving.h"
#include"../library/moving_right.h"
#include"../library/moving_left.h"
#include"../library/health_bar.h"
#include"../library/skill1_of_character1.h"
#include"../library/skill2_of_character1.h"
#include"../library/skill3_of_character1.h"
#include"../library/game_over.h"
#include"../library/winner.h"
#include"../library/free_texture.h"
#include"../library/stopping_setting.h"
#include"../library/event loop.h"
#define RIGHT 1
#define LEFT 2

int main(int arcg,char*argv[])
{ int level_of_player=0;
  //SDL_OpenURL("https://www.youtube.com/");
  ifstream ip_point("point_of_player.txt");
  ip_point>>level_of_player;
  ofstream op_point("point_of_player.txt");
  eventloop(level_of_player);
  close();
  free_music_in_menu_game();
  free_music_in_game();
  free_music_game_over();
  free_music_game_win();
  free_music_taken_dam();
  free_music_slash();
  free_music_exploding();
  op_point<<level_of_player;
  cout<<level_of_player<<endl;

  cout<<"thanks for playing"<<endl;

  return 0;
}
