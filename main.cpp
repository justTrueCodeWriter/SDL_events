#include <stdio.h>
#include "SDL.h"

int WIDTH = 1000, HEIGHT = 600;
SDL_Window* win;
SDL_Renderer* ren;

#include "task_links.h"

int main(int argc, char* argv[]) {

	short userChoice = 0;

	while (true) {

		do {
		printf("Number of task:\ntask 1,\ntask 2,\ntask 3,\ntask 4,\nexit(5)\n>>");	scanf_s("%hu", &userChoice);
		}while((userChoice<0) && (userChoice>6));
		Init(ren, win, WIDTH, HEIGHT);
		switch (userChoice) {
			case 1: color_saver(ren, WIDTH, HEIGHT);
					break;
			case 2: break;
			case 3: task3(ren, WIDTH, HEIGHT); break;
			case 4: break;
			case 5: exit(1);
					break;
			default: printf("Incorrect number of task!\n");
		}
		DeInit(ren, win);
	}

}
