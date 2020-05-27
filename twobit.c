#include <gb/gb.h>

#include "credit.c"
#include "credit_map.c"
#include "start.c"
#include "start_map.c"
#include "fort.c"
#include "fort_map.c"
#include "owl.c"
#include "owl_map.c"
#include "magnet.c"
#include "magnet_map.c"


UINT8 scene;
extern UINT8 button;            //import from bank1
extern void koalascene();       
extern void policescene();      
extern void calcscene();
extern void hyenascene();

void bleep (){
    NR10_REG = 0x16;
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;
}

void startscene(){
    HIDE_BKG;
    set_bkg_data(0,95,startData);
    set_bkg_tiles(0,0,20,18,startMapData);
    SHOW_BKG;
    button = 1;
}


void fortscene(){
    HIDE_BKG;
    set_bkg_data(0,125,fortData);
    set_bkg_tiles(0,0,20,18,fortMapData);
    SHOW_BKG;
    button = 0;  
}

void owlscene(){
    HIDE_BKG;
    set_bkg_data(0,93,owlData);
    set_bkg_tiles(0,0,20,18,owlMapData);
    SHOW_BKG;
    button = 0;
}

void magnetscene(){
    HIDE_BKG;
    set_bkg_data(0,69,magnetData);
    set_bkg_tiles(0,0,20,18,magnetMapData);
    SHOW_BKG;
    button = 0;
}



void main(){
    UINT8 keys;
    button = 0; // waiting for button to be pressed
    
    NR52_REG = 0x80; // sound on
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    set_bkg_data(0,85,creditData);
    set_bkg_tiles(0,0,20,18,creditMapData);
    SHOW_BKG;
    DISPLAY_ON;
    delay(3000);
    HIDE_BKG;
    startscene();
    SHOW_BKG;
    waitpad(J_START);
    bleep();
    scene = 0;
    
    while(1){
    keys = joypad();

        if (scene == -1 && button == 1){
            scene = 6;
        }

        if (scene == 7 && button == 1){
            scene = 0;
        }

        if (scene == 0 && button == 1){
            SWITCH_ROM_MBC1(0);
            fortscene();
        }

        if (scene == 1 && button == 1){
            SWITCH_ROM_MBC1(0);
            owlscene();
        }

        if (scene == 2 && button == 1){
            magnetscene();
        }

        if (scene == 3 && button == 1){
            SWITCH_ROM_MBC1(1);
            koalascene();
        }

        if (scene == 4 && button == 1){
            SWITCH_ROM_MBC1(1);
            policescene();
        }

        if (scene == 5 && button == 1){
            SWITCH_ROM_MBC1(1);
            hyenascene();
        }

        if (scene == 6 && button ==1){
            SWITCH_ROM_MBC1(1);
            calcscene();
        }



        wait_vbl_done();

        if (keys == J_RIGHT){
            waitpadup();
            scene ++;
            button = 1; // button has been pressed
        } 

        if (keys == J_LEFT){
            waitpadup();
            scene --;
            button = 1; //button has been pressed
        }
    }

}