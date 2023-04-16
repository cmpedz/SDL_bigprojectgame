
#ifndef texture
#define texture
#include<SDL.h>
#include<iostream>
class Ltexture{
public :
       Ltexture();
       ~Ltexture();
       void free();
       bool loadtexture(std::string s);
       void render(SDL_Rect*clip);
       int gettdx();
       int gettdy();
       int getwidth();
       int getheight();
       void settdx(int x);
       void settdy(int y);
       void setheight(int h);
       void setwidth(int w);
       //Set blending
       void setBlendMode( SDL_BlendMode blending );


        //Set alpha modulation
       void setAlpha( Uint8 alpha );
       bool loadFromRenderedText( std::string textureText, SDL_Color textColor,TTF_Font*F );
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
bool Ltexture::loadtexture(std::string s){
     bool success=true;
     SDL_Surface*loadedimage=SDL_LoadBMP(s.c_str());
     if(loadedimage==NULL){
        std::cout<<"failed to load image"<<std::endl<<"error1 :"<<SDL_GetError();
        success=false;
     }
     else{
         SDL_SetColorKey(loadedimage,SDL_TRUE,SDL_MapRGB(loadedimage->format,255,0,0));
         image=SDL_CreateTextureFromSurface(renderer,loadedimage);
         if(image==NULL){
            std::cout<<"failed to load image texture"<<std::endl<<"error2 :"<<SDL_GetError();
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

void Ltexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( image, blending );
}

void Ltexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( image, alpha );
}
bool Ltexture::loadFromRenderedText( std::string textureText, SDL_Color textColor,TTF_Font*F )
{

    free();

    SDL_Surface* textSurface = TTF_RenderText_Solid( F, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        image = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( image == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return image;
}








#endif // texture

