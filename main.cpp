#include <iostream>
#include<math.h>
using namespace std;
#include<SDL.h>
#include"gravity.h"
#include"common function.h"
#include"loadmedia.h"
#include"texture.h"
#include"background.h"
#include"character.h"
#include"character2.h"
#include"miss_effect.h"
#include"character2_skill2.h"
#include"character2_skill3.h"
#include"moving_right.h"
#include"moving_left.h"
#include"health_bar.h"
#include"skill1_of_character1.h"
#include"skill2_of_character1.h"
#include"skill3_of_character1.h"
#include"game_over.h"
#include"winner.h"
#include"event loop.h"
#define RIGHT 1
#define LEFT 2
int main(int arcg,char*argv[])
{
  eventloop();
  close();
  return 0;
}
