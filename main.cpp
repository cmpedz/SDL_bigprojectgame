#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;
#include<SDL.h>
#include"gravity.h"
#include"common function.h"
#include"loadmedia.h"
#include"texture.h"
#include"timer.h"
#include"button.h"
#include"giao_dien_game.h"
#include"tutorial_background.h"
#include"background.h"
#include"time_watting_skill_of_player_icon.h"
#include"pause_button_icon.h"
#include"character.h"
#include"character2.h"
#include"miss_effect.h"
#include"character2_skill2.h"
#include"character2_skill3.h"
#include"AI_moving.h"
#include"moving_right.h"
#include"moving_left.h"
#include"health_bar.h"
#include"skill1_of_character1.h"
#include"skill2_of_character1.h"
#include"skill3_of_character1.h"
#include"game_over.h"
#include"winner.h"
#include"free_texture.h"
#include"stopping_setting.h"
#include"event loop.h"
#define RIGHT 1
#define LEFT 2

int main(int arcg,char*argv[])
{ int point_of_player=0;
  ifstream ip_point("point_of_player.txt");
  ip_point>>point_of_player;
  ofstream op_point("point_of_player.txt");
  eventloop(point_of_player);
  close();
  op_point<<point_of_player;
  cout<<"****************tong ket*******************"<<endl;
  cout<<endl;
  cout<<"diem tich luy cua ban la :"<<point_of_player<<endl;
  cout<<endl;
  cout<<"nap vip de mo skin hoac la tich luy 1000000000000000 diem"<<endl;
  cout<<endl;
  cout<<"thanks for playing"<<endl;

  return 0;
}
