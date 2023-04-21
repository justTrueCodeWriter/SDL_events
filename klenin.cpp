#include <stdlib.h>
#include <SDL.h>

void task3(SDL_Renderer* ren, int WIDTH, int HEIGHT) {
    int quit = 0;
	bool blackWindow = false;
	bool buttons[SDL_NUM_SCANCODES];
    SDL_Event event;
    int leftMouseButton = 0;
    SDL_Point mousePos;
    SDL_Point offset;
    SDL_Rect rect1 = { 260, 208, 100, 100 };
    SDL_Rect rect2 = { 50, 50, 100, 80 };
    SDL_Rect rect3 = { 10, 300, 50, 80 };
    SDL_Rect* selectedRect = 0;
    while (quit == 0)
    {
        SDL_Delay(10);
        SDL_PollEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                blackWindow = true;
                break;
          
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: blackWindow = true; break;
                }
                
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    leftMouseButton = 1;

                   
                        if (SDL_PointInRect(&mousePos, &rect1))
                        {
                            selectedRect = &rect1;
                            offset.x = mousePos.x - selectedRect->x;
                            offset.y = mousePos.y - selectedRect->y;

                            break;
                        }
                        if (SDL_PointInRect(&mousePos, &rect2))
                        {
                            selectedRect = &rect2;
                            offset.x = mousePos.x - selectedRect->x;
                            offset.y = mousePos.y - selectedRect->y;
                            break;
                        }
                        if (SDL_PointInRect(&mousePos, &rect3))
                        {
                            selectedRect = &rect3;
                            offset.x = mousePos.x - selectedRect->x;
                            offset.y = mousePos.y - selectedRect->y;
                            break;
                        }
                }
                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    
                    selectedRect = 0;
                }
                break;
            case SDL_MOUSEMOTION:
            {
                mousePos = { event.motion.x, event.motion.y };

                if (leftMouseButton and selectedRect != 0)
                {
                    selectedRect->x = mousePos.x - offset.x;
                    selectedRect->y = mousePos.y - offset.y;
                }
            }
            break;
            }
            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
            SDL_RenderFillRect(ren, &rect1);
            SDL_SetRenderDrawColor(ren, 255, 0, 255, 255);
            SDL_RenderFillRect(ren, &rect2);
            SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
            SDL_RenderFillRect(ren, &rect3);
            SDL_RenderPresent(ren);

            if (blackWindow == true) {
					SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
					SDL_RenderClear(ren);
					SDL_RenderPresent(ren);
				}
				while (blackWindow == true) {
					while (SDL_PollEvent(&event) != 0) {
						switch (event.type) {
						case SDL_QUIT:
							return;
							break;
						case SDL_KEYDOWN:
							if (buttons[event.key.keysym.scancode]) {
								blackWindow = false;
							}
							switch (event.key.keysym.scancode) {
							case SDL_SCANCODE_ESCAPE:
								return;
								break;
							}
						}
					}
				}
    }
	

}