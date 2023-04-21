#include <stdio.h>
#include <SDL.h>
#pragma comment(lib, "winmm.lib")
#include <windows.h>

#include "sdl_gen.h"

#include "task_links.h"
#include "SimonSays.h"

int main(int argc, char* argv[]) {
	PlaySound(L"TopMusic.wav", NULL, SND_ASYNC | SND_LOOP);
	short userChoice = 0;

	while (true) {

		do {
		printf("Number of task:\ntask 1,\ntask 2,\ntask 3,\ntask 4,\nexit(5)\n>>");	scanf_s("%hu", &userChoice);
		}while((userChoice<0) && (userChoice>6));
		Init();
		switch (userChoice) {
			case 1: color_saver(ren, WIDTH, HEIGHT);
					break;
			case 2: SimonSays(ren, WIDTH, HEIGHT); break;
			case 3: task3(ren, WIDTH, HEIGHT); break;
			case 4: while (mouse_with_trail(ren)) SDL_Delay(16); break;
			case 5: exit(1);
					break;
			default: printf("Incorrect number of task!\n");
		}
		DeInit();
	}

}
