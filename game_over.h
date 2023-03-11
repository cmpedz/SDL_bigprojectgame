#ifndef texture
#define texture
texture;
#endif // texture
void game_over_system(){
     game_over_class.setheight(680);
     game_over_class.setwidth(1080);
     game_over_class.loadtexture("gameover.bmp");
     game_over_class.settdx(0);
     game_over_class.settdy(0);
     game_over_class.render(NULL);

}
