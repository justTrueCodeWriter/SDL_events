#include <stdio.h>
#include <math.h>
#include "SDL.h"

#define KEY_1 0
#define KEY_2 1
#define KEY_3 2
#define CTRL_KEY 3


void colored_rect(SDL_Renderer* ren, int r, int g, int b, int xCoordinate, int yCoordinate, int xSize, int ySize);
void saved_color_showcase(SDL_Renderer* ren, int r, int g, int b, int xCoordinate, int yCoordinate, int xSize, int ySize);

void color_saver(SDL_Renderer* ren, int WIDTH, int HEIGHT) {
	int xSize = WIDTH/4, ySize = HEIGHT/4;
	int xCoordinate = (WIDTH/2)-(xSize/2), yCoordinate = (HEIGHT/2)-(ySize/2);

	bool isRunning = true;
	bool blackWindow = false;

	bool buttons[SDL_NUM_SCANCODES];
	bool isKeyPressed[] = {false, false, false, false};

	SDL_Event ev;


	int r = 0, g = 200, b = 50;
	int rTmp=0, gTmp=0, bTmp=0;

	int savedR1=200, savedG1=200, savedB1=200;
	int savedR2=200, savedG2=200, savedB2=200;
	int savedR3=200, savedG3=200, savedB3=200;

	SDL_PollEvent(&ev);		

	while(isRunning) {
		//printf("CORRECT\n");
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		SDL_RenderClear(ren);

		while(SDL_PollEvent(&ev) != 0){
			switch (ev.type) {
				case SDL_QUIT:
					blackWindow = true;	
					break;
				case SDL_KEYDOWN:
					switch (ev.key.keysym.scancode) {
						case SDL_SCANCODE_1: isKeyPressed[KEY_1] = true; break;
						case SDL_SCANCODE_2: isKeyPressed[KEY_2] = true; break;
						case SDL_SCANCODE_3: isKeyPressed[KEY_3] = true; break;
						case SDL_SCANCODE_LCTRL: isKeyPressed[CTRL_KEY] = true; break;
						case SDL_SCANCODE_ESCAPE: blackWindow = true; break;
					}
					break;
				case SDL_KEYUP:
					switch (ev.key.keysym.scancode) {
						case SDL_SCANCODE_1: isKeyPressed[KEY_1] = false; break;
						case SDL_SCANCODE_2: isKeyPressed[KEY_2] = false; break;
						case SDL_SCANCODE_3: isKeyPressed[KEY_3] = false; break;
						case SDL_SCANCODE_LCTRL: isKeyPressed[CTRL_KEY] = false; break;
					}
					break;
			}
				switch (ev.window.event) {
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						WIDTH = ev.window.data1;
						HEIGHT = ev.window.data2;
						xCoordinate = WIDTH / 2 - xSize / 2;
						yCoordinate = HEIGHT / 2 - ySize / 2;
						break;
					}

		}

		colored_rect(ren, rTmp, gTmp, bTmp, xCoordinate, yCoordinate, xSize, ySize);
// SAVE COLOR
		if (isKeyPressed[KEY_1] && !isKeyPressed[KEY_2] && 
				!isKeyPressed[KEY_3] && !isKeyPressed[CTRL_KEY]) {
			savedR1 = rTmp; savedG1 = gTmp; savedB1 = bTmp;
			printf("Color 1 saved\n");
		}
		if (!isKeyPressed[KEY_1] && isKeyPressed[KEY_2] && 
				!isKeyPressed[KEY_3] && !isKeyPressed[CTRL_KEY]) {
			savedR2 = rTmp; savedG2 = gTmp; savedB2 = bTmp;
			printf("Color 2 saved\n");
		}
		if (!isKeyPressed[KEY_1] && !isKeyPressed[KEY_2] && 
				isKeyPressed[KEY_3] && !isKeyPressed[CTRL_KEY]) {
			savedR3 = rTmp; savedG3 = gTmp; savedB3 = bTmp;
			printf("Color 3 saved\n");
		}

// SHOW SAVED COLOR
		if (isKeyPressed[KEY_1] && !isKeyPressed[KEY_2] && 
				!isKeyPressed[KEY_3] && isKeyPressed[CTRL_KEY]) {
			saved_color_showcase(ren, savedR1, savedG1, savedB1, xCoordinate, yCoordinate, xSize, ySize);	
		}
		if (!isKeyPressed[KEY_1] && isKeyPressed[KEY_2] && 
				!isKeyPressed[KEY_3] && isKeyPressed[CTRL_KEY]) {
			saved_color_showcase(ren, savedR2, savedG2, savedB2, xCoordinate, yCoordinate, xSize, ySize);	
		}
		if (!isKeyPressed[KEY_1] && !isKeyPressed[KEY_2] && 
				isKeyPressed[KEY_3] && isKeyPressed[CTRL_KEY]) {
			saved_color_showcase(ren, savedR3, savedG3, savedB3, xCoordinate, yCoordinate, xSize, ySize);	
		}

			

		r--; g--; b--;
		rTmp = abs(r); 	gTmp = abs(g); bTmp = abs(b);

		if (abs(r) == 255)
			r = abs(r);
		if (abs(g) == 255)
			g = abs(g);
		if (abs(b) == 255)
			b = abs(b);

		//printf("%d | %d | %d\n%d | %d | %d\n%d | %d | %d\n--------\n", savedR1, savedG1, savedB1, savedR2, savedG2, savedB2, savedR3, savedG3, savedB3);
		SDL_RenderPresent(ren);

		SDL_Delay(16);

		if (blackWindow == true) {
					SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
					SDL_RenderClear(ren);
					SDL_RenderPresent(ren);
				}
				while (blackWindow == true) {
					while (SDL_PollEvent(&ev) != 0) {
						switch (ev.type) {
						case SDL_QUIT:
							return;
							break;
						case SDL_KEYDOWN:
							if (buttons[ev.key.keysym.scancode]) {
								blackWindow = false;
							}
							switch (ev.key.keysym.scancode) {
							case SDL_SCANCODE_ESCAPE:
								return;
								break;
							}
						}
					}
				}

	}
}

void colored_rect(SDL_Renderer* ren, int r, int g, int b, int xCoordinate, int yCoordinate, int xSize, int ySize) {

	SDL_Rect rect;
	rect = {xCoordinate, yCoordinate, xSize, ySize};

	SDL_SetRenderDrawColor(ren, r, g, b, 255);
	SDL_RenderFillRect(ren, &rect);

}

void saved_color_showcase(SDL_Renderer* ren, int r, int g, int b, int xCoordinate, int yCoordinate, int xSize, int ySize) {

	printf("%d %d %d\n", r, g, b);

	SDL_Rect rect;
	rect = {xCoordinate, yCoordinate, xSize, ySize};

	SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
	SDL_RenderClear(ren);

	SDL_SetRenderDrawColor(ren, r, g, b, 255);
	SDL_RenderFillRect(ren, &rect);

	SDL_RenderPresent(ren);
	SDL_Delay(5000);

}
