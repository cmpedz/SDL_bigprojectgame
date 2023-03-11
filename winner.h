#ifndef texture
#define texture
texture
#endif // texture
Ltexture get_dunked_on;
void set_winner_system(){
      get_dunked_on.setheight(680);
      get_dunked_on.setwidth(1080);
      get_dunked_on.settdx(0);
      get_dunked_on.settdy(0);
      get_dunked_on.loadtexture("get dunked on.bmp");
      get_dunked_on.render(NULL);
}
