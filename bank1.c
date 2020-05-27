#include <gb/gb.h>
#include "koala.c"
#include "koala_map.c"
#include "police.c"
#include "police_map.c"
#include "hyena.c"
#include "hyena_map.c"
#include "calc.c"
#include "calc_map.c"

UINT8 button;

void koalascene(){
    HIDE_BKG;
    //DISPLAY_OFF;
    set_bkg_data(0,194,koalaData);
    set_bkg_tiles(0,0,20,18,koalaMapData);
    SHOW_BKG;
    button = 0;
    //DISPLAY_ON;
}

void policescene(){
    HIDE_BKG;
    //DISPLAY_OFF;
    set_bkg_data(0,154,policeData);
    set_bkg_tiles(0,0,20,18,policeMapData);
    SHOW_BKG;
    button = 0;
    //DISPLAY_ON;
}

void hyenascene(){
    HIDE_BKG;
    //DISPLAY_OFF;
    set_bkg_data(0,96,hyenaData);
    set_bkg_tiles(0,0,20,18,hyenaMapData);
    SHOW_BKG;
    button = 0;
    //DISPLAY_ON;
}

void calcscene(){
    HIDE_BKG;
    //DISPLAY_OFF;
    set_bkg_data(0,176,calcData);
    set_bkg_tiles(0,0,20,18,calcMapData);
    SHOW_BKG;
    button = 0;
    //DISPLAY_ON;
}