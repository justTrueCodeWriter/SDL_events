#include "Afanasyev.h"

void FillArray(SDL_Rect* Array_rects)
{
	Array_rects[0].x = 25;
	Array_rects[0].y = 25;
	Array_rects[0].w = 25;
	Array_rects[0].h = 25;
	Array_rects[1].x = 25;
	Array_rects[1].y = 25;
	Array_rects[1].w = 25;
	Array_rects[1].h = 25;

}
bool mouse_with_trail(SDL_Renderer* ren)
{
	static SDL_Point mouse_coordinates;
	static SDL_Event event;
	static int amount_rects = 2;
	static bool check = true;
	static bool pause = false;
	static SDL_Rect* Array_rects = (SDL_Rect*)malloc(sizeof(SDL_Rect) * amount_rects);

	if (check)
	{
		FillArray(Array_rects);
		check = false;
	}

	SDL_SetRenderDrawColor(ren, 50, 200, 200, 255);
	SDL_RenderClear(ren);

	while (pause)
	{
		SDL_PollEvent(&event);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		SDL_RenderPresent(ren);
		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_ESCAPE:
				free(Array_rects);
				return 0;
				break;

			default:
				pause = false;
				break;
			}
		if (event.type == SDL_QUIT)
		{
			free(Array_rects);
			return 0;
			break;
		}
	}

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{
		case SDL_QUIT:
			pause = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_ESCAPE:
				pause = true;
				break;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				if (amount_rects < 30)
				{
					amount_rects++;
					Array_rects = (SDL_Rect*)realloc(Array_rects, sizeof(SDL_Rect) * amount_rects);
				}
				break;
			case SDL_BUTTON_RIGHT:
				if (amount_rects > 2)
				{
					amount_rects--;
					Array_rects = (SDL_Rect*)realloc(Array_rects, sizeof(SDL_Rect) * amount_rects);
				}
				break;
			}
			break;
		}
	}

	for (int i = amount_rects - 1; i > 0; i--)
		Array_rects[i] = Array_rects[i - 1];

	SDL_GetMouseState(&mouse_coordinates.x, &mouse_coordinates.y);
	Array_rects[0].x = mouse_coordinates.x;
	Array_rects[0].y = mouse_coordinates.y;

	for (int i = 0, alpha_canal = 255; i < amount_rects; i++, alpha_canal -= 255 / amount_rects)
	{
		SDL_SetRenderDrawColor(ren, 255, 200, 150, alpha_canal);
		SDL_RenderFillRect(ren, &Array_rects[i]);
	}

	SDL_RenderPresent(ren);

	return 1;
}