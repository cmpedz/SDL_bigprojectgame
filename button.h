#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include"texture.h"
const int button_width=415/3*2;
const int button_height=125/3*2;

int tdx_of_my_mouse=0;
int tdy_of_my_mouse=0;

class button
{
    public:
        // hàm khởi tạo giá trị mặc định
        button();

        // hàm thiết lập vị trí
        void setPosition( int x, int y);
        int gettdx();
        int gettdy();

    private:
        //vị trí của con trỏ chuột
        SDL_Point position;

};
button::button(){
       position.x=0;
       position.y=0;
}
void button::setPosition(int x,int y){
     position.x=x;
     position.y=y;
}

int button :: gettdx(){
    return position.x;
}
int button :: gettdy(){
    return position.y;
}



#endif // BUTTON_H_INCLUDED
