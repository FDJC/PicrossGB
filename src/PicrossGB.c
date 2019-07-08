#include <gb/gb.h>

void init();
void checkInput();
void updateSwitches();

const UINT8 TILESET[] = {
    // Tile 00: Blank
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // Tile 01: Block
    0x00,0xFF,0x7E,0x81,0x7E,0x81,0x7E,0x81,
    0x7E,0x81,0x7E,0x81,0x7E,0x81,0x00,0xFF,
    // Tile 02: Curseur
    0xE7, 0xE7, 0x81, 0x81, 0x81, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x81, 0x81, 0x81, 0x81, 0xE7, 0xE7,
    // Tile 03: Cherry
    0x04, 0x04, 0x04, 0x04, 0x0a, 0x0a, 0x12, 0x12,
    0x66, 0x00, 0x99, 0x77, 0x99, 0x77, 0x66, 0x66,
};

UINT8 TILEMAP[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

// const UINT8 TILEMAP2[] = {
    // 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 2, 2, 2, 0, 0, 3, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 2, 2, 2, 0, 0, 3, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// };


const UINT8 sprites[] =
{
    0xE7, 0xE7, 0x81, 0x81, 0x81, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x81, 0x81, 0x81, 0x81, 0xE7, 0xE7
};


UINT8 player[2]; //emplacement du joueur

UINT8 prev_keys = 0;
UINT8 keys;


void main() {

	init();
	
	while(1) {
		
		checkInput();				// Check for user input (and act on it)
		updateSwitches();			// Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
		wait_vbl_done();			// Wait until VBLANK to avoid corrupting memory
	}
	
}


//initialisation des différents éléments
void init() {
	
	DISPLAY_ON;						// Turn on the display
    set_bkg_data(0, 5, TILESET);
	
	// Use the 'helloWorld' array to write background tiles starting at 0,6 (tile positions)
	//  and write for 10 tiles in width and 2 tiles in height
    set_bkg_tiles(0, 0, 20, 18, TILEMAP);
	
	set_sprite_data(0, 1, sprites);
	set_sprite_tile(0,0);
	player[0] = 8;
	player[1] = 16;

}

//mise à jour des différents éléments
void updateSwitches() {
	
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	
}



void checkInput() {


		keys = joypad();


        if (!(keys & J_UP) && prev_keys & J_UP) {
			//move_sprite(0, player[0], player[1]-8);
            player[1]-=8;
        }

        if (!(keys & J_DOWN) && prev_keys & J_DOWN) {
			//move_sprite(0, player[0], player[1]+8);
            player[1]+=8;
        }
		if (!(keys & J_LEFT) && prev_keys & J_LEFT) {
			//move_sprite(0, player[0]-8, player[1]);
            player[0]-=8;
        }
		if (!(keys & J_RIGHT) && prev_keys & J_RIGHT) {
			//move_sprite(0, player[0]+8, player[1]);
            player[0]+=8;
        }
		if (!(keys & J_A) && prev_keys & J_A) {
			//move_sprite(0, player[0]+8, player[1]);
            if ( TILEMAP[(((player[1]/8)-2)*20)+((player[0]/8)-1)]==0){
				TILEMAP[(((player[1]/8)-2)*20)+((player[0]/8)-1)]=1;
			} 
			else{
				TILEMAP[(((player[1]/8)-2)*20)+((player[0]/8)-1)]=0;
			}
			set_bkg_tiles(0, 0, 20, 18, TILEMAP);
        }

        prev_keys = keys;




	// Move the sprite in the first movable sprite list (0)
	//  the the position of X (player[0]) and y (player[1])
	move_sprite(0, player[0], player[1]);
	//delay(10);

}



