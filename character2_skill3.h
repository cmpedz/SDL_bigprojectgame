#ifndef texture
#define texture
texture;
#endif // CHARACTER2_SKILL3_H_INCLUDED

const int quatities_of_knifes=2;
Ltexture skill3_of_character2[quatities_of_knifes];
int tdx_for_ingradient_of_skill3_character2[quatities_of_knifes];
int tdy_for_ingradient_of_skill3_character2[quatities_of_knifes];
bool is_ingradient_of_skill3_from_character2_actived[quatities_of_knifes];

void set_skill3_of_character2(){

         tdx_for_ingradient_of_skill3_character2[0]=tdx_character2;
         tdy_for_ingradient_of_skill3_character2[0]=tdy_character2;
         is_ingradient_of_skill3_from_character2_actived[0]=false;
         skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
         skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);
         skill3_of_character2[0].setheight(15);
         skill3_of_character2[0].setwidth(40);
         skill3_of_character2[0].loadtexture("skill3_of_character2_left.bmp");

         skill3_of_character2[1].loadtexture("skill3_of_character2_up.bmp");
         tdx_for_ingradient_of_skill3_character2[1]=tdx_character1;
         tdy_for_ingradient_of_skill3_character2[1]=0;
         is_ingradient_of_skill3_from_character2_actived[0]=false;
         skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
         skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);
         skill3_of_character2[1].setheight(40);
         skill3_of_character2[1].setwidth(15);



};


void set_skill3_of_character2_active(){
     if(SDL_GetTicks()/1000 % 5==0 && SDL_GetTicks()/1000 !=0 ){
        is_ingradient_of_skill3_from_character2_actived[0]=true;
        is_ingradient_of_skill3_from_character2_actived[1]=true;

     }

     if(is_ingradient_of_skill3_from_character2_actived[0]){
        if(tdx_for_ingradient_of_skill3_character2[0] < 0){
           tdx_for_ingradient_of_skill3_character2[0]=tdx_character2;
           skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
           skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);
           is_ingradient_of_skill3_from_character2_actived[0]=false;
        }
        else{
             tdx_for_ingradient_of_skill3_character2[0]=tdx_for_ingradient_of_skill3_character2[0]-5;
             skill3_of_character2[0].settdx(tdx_for_ingradient_of_skill3_character2[0]);
             skill3_of_character2[0].settdy(tdy_for_ingradient_of_skill3_character2[0]);

        }
         skill3_of_character2[0].render(NULL);
     }
     if(is_ingradient_of_skill3_from_character2_actived[1]){
        if(tdy_for_ingradient_of_skill3_character2[1] >680 ){
           tdy_for_ingradient_of_skill3_character2[1]=0;
           tdx_for_ingradient_of_skill3_character2[1]=tdx_character1;
           skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
           skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);
           is_ingradient_of_skill3_from_character2_actived[1]=false;
        }
        else{
            tdy_for_ingradient_of_skill3_character2[1]=tdy_for_ingradient_of_skill3_character2[1]+5;
            skill3_of_character2[1].settdx(tdx_for_ingradient_of_skill3_character2[1]);
            skill3_of_character2[1].settdy(tdy_for_ingradient_of_skill3_character2[1]);

        }
         skill3_of_character2[1].render(NULL);
     }

}


