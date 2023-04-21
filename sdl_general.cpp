#include <SDL.h>

void DeInit(SDL_Renderer* ren, SDL_Window* win) {

	if (ren != 0) SDL_DestroyRenderer(ren);
	if (win != 0) SDL_DestroyWindow(win);
	SDL_Quit();

}

void Init(SDL_Renderer* ren, SDL_Window* win, int WIDTH, int HEIGHT){

	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Super Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

}