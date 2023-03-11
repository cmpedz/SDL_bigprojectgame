
#ifndef texture
#define texture
class Ltexture{
public :
       Ltexture();
       ~Ltexture();
       void free();
       bool loadtexture(string s);
       void render(SDL_Rect*clip);
       int gettdx();
       int gettdy();
       int getwidth();
       int getheight();
       void settdx(int x);
       void settdy(int y);
       void setheight(int h);
       void setwidth(int w);
private :
        SDL_Texture*image;
        int height,width,x,y;

};
Ltexture::Ltexture(){
          image=NULL;
          height=0;
          width=0;
          x=0;
          y=0;
}
void Ltexture::free(){
     SDL_DestroyTexture(image);
}
Ltexture::~Ltexture(){
     free();
}
bool Ltexture::loadtexture(string s){
     bool success=true;
     SDL_Surface*loadedimage=SDL_LoadBMP(s.c_str());
     if(loadedimage==NULL){
        cout<<"failed to load image"<<endl<<"error :"<<SDL_GetError();
        success=false;
     }
     else{
         SDL_SetColorKey(loadedimage,SDL_TRUE,SDL_MapRGB(loadedimage->format,255,0,0));
         image=SDL_CreateTextureFromSurface(renderer,loadedimage);
         if(image==NULL){
            cout<<"failed to load image texture"<<endl<<"error :"<<SDL_GetError();
            success=false;
         }
     }
     SDL_FreeSurface(loadedimage);
     return success;
}
void Ltexture::render(SDL_Rect*clip){
     SDL_Rect size_and_position_of_character;
     size_and_position_of_character.h=height;
     size_and_position_of_character.w=width;
     size_and_position_of_character.x=x;
     size_and_position_of_character.y=y;
     SDL_RenderCopy(renderer,image,clip,&size_and_position_of_character);
}
int Ltexture::gettdx(){
    return x;
};
int Ltexture::gettdy(){
    return y;
};
int Ltexture::getwidth(){
    return width;
};
int Ltexture::getheight(){
    return height;
};
void Ltexture::settdx(int td_x){
     x=td_x;
};
void Ltexture::settdy(int td_y){
     y=td_y;
};
void Ltexture::setheight(int h){
     height=h;
};
void Ltexture::setwidth(int w){
     width=w;
};
Ltexture background;
Ltexture character1;
Ltexture character2;
Ltexture skill1_of_AI;
Ltexture skill1_of_character1;
Ltexture effect_for_skill1_of_character1;
//
Ltexture character1_face;
Ltexture health_bar_1_for_character1;
Ltexture health_bar_2_for_character1;
//
Ltexture character2_face;
Ltexture health_bar_1_for_character2;
Ltexture health_bar_2_for_character2;
//
Ltexture game_over_class;
//
Ltexture character2_skill2;
int tdx_of_skill2_character2=character2.gettdx();
int skill_attack_directly_of_AI_frame=0;
const int quatity_of_frame_skill1_AI=7;
SDL_Rect skill1_of_AI_clip[ quatity_of_frame_skill1_AI];
#endif // texture
