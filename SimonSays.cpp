#include "SimonSays.h"



/*
void init() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Couldn't init sdl, Error %s", SDL_GetError());
		system("pause");
		de_init(1);
	}

	win = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == NULL) {
		printf("win couldn't init %s", SDL_GetError());
		system("pause");
		SDL_Quit();
		de_init(1);
	}

	ren = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	if (ren == NULL) {
		printf("rener couldn't init %s", SDL_GetError());
		system("pause");
		SDL_Quit();
		de_init(1);
	}
}

void de_init(int error) {
	if (ren != 0) SDL_DestroyRenderer(ren);
	if (win != 0) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}*/

int random_number() {
	return rand() % (5 - 1) + 1;
}

void checkCollision(SDL_Rect a, int& left, int& right, int& top, int& bottom) {
	/*int left;
	int right;
	int top;
	int bottom;*/

	left = a.x;
	right = a.x + a.w;
	top = a.y;
	bottom = a.y + a.h;

	//printf("left %d, right %d, top %d, bottom %d\n", left, right, top, bottom);
}

void change_color(SDL_Renderer* ren, SDL_Rect rect, int red, int green, int blue, int clarity) {
	SDL_SetRenderDrawColor(ren, red, green, blue, clarity);
	SDL_RenderFillRect(ren, &rect);
	SDL_RenderPresent(ren);
	SDL_Delay(300);
}

void SimonSays(SDL_Renderer* ren, int WIDTH, int HEIGHT) {
	srand(time(NULL));
	system("chcp 1251");
	int simonArray[20] =
	{ 0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
	int userArray[20];
	bool isRunning = true;
	bool buttons[SDL_NUM_SCANCODES];
	int shiftX1 = WIDTH / 2 - 150, shiftY1 = HEIGHT / 2 - 150, Xsize = 200, Ysize = 200;
	int shiftX2 = WIDTH / 2 + 150, shiftY2 = HEIGHT / 2 - 150;
	int shiftX3 = WIDTH / 2 - 150, shiftY3 = HEIGHT / 2 + 150;
	int shiftX4 = WIDTH / 2 + 150, shiftY4 = HEIGHT / 2 + 150;
	int Xcoordinate, Ycoordinate;
	int Xcoordinate2, Ycoordinate2;
	int Xcoordinate3, Ycoordinate3;
	int Xcoordinate4, Ycoordinate4;
	int mouseX = 0, mouseY = 0;
	int index;
	int score = 0, bestScore = 0;
	SDL_Event ev;
	bool blackWindow = false;
	int counter = 0;
	Xcoordinate = shiftX1 - Xsize / 2, Ycoordinate = shiftY1 - Ysize / 2;
	Xcoordinate2 = shiftX2 - Xsize / 2, Ycoordinate2 = shiftY2 - Ysize / 2;
	Xcoordinate3 = shiftX3 - Xsize / 2, Ycoordinate3 = shiftY3 - Ysize / 2;
	Xcoordinate4 = shiftX4 - Xsize / 2, Ycoordinate4 = shiftY4 - Ysize / 2;
	SDL_Rect r = { Xcoordinate, Ycoordinate, Xsize, Ysize };
	SDL_Rect r2 = { Xcoordinate2, Ycoordinate2, Xsize, Ysize };
	SDL_Rect r3 = { Xcoordinate3, Ycoordinate3, Xsize, Ysize };
	SDL_Rect r4 = { Xcoordinate4, Ycoordinate4, Xsize, Ysize };
	int left1 = 250, right1 = 450, top1 = 50, bottom1 = 250;
	int left2 = 550, right2 = 750, top2 = 50, bottom2 = 250;
	int left3 = 250, right3 = 450, top3 = 350, bottom3 = 550;
	int left4 = 550, right4 = 750, top4 = 350, bottom4 = 550;
	bool fault = false;
	bool click = false;
	for (int i = 0; i < sizeof(simonArray) / sizeof(int); i++) {
		simonArray[i] = random_number();
		//printf("%d ", simonArray[i]);
	}
	SDL_PollEvent(&ev);
	printf("\n");
	while (isRunning) {
		int userArray[20]{};
		if (counter <= 20) {
			for (int i = 0; i < counter; i++) {
				if (simonArray[i] == 1) {
					change_color(ren, r, 0, 220, 0, 0);
					change_color(ren, r, 0, 120, 0, 0);
				}
				if (simonArray[i] == 2) {
					change_color(ren, r2, 220, 0, 0, 0);
					change_color(ren, r2, 120, 0, 0, 0);
				}
				if (simonArray[i] == 3) {
					change_color(ren, r3, 220, 220, 0, 0);
					change_color(ren, r3, 120, 120, 0, 0);
				}
				if (simonArray[i] == 4) {
					change_color(ren, r4, 0, 0, 220, 0);
					change_color(ren, r4, 0, 0, 120, 0);
				}
			}
		}
		for (int i = 0; i < counter; i++) {
			int Return = true;
			while (Return and fault == false) {
				r = { Xcoordinate, Ycoordinate, Xsize, Ysize };
				r2 = { Xcoordinate2, Ycoordinate2, Xsize, Ysize };
				r3 = { Xcoordinate3, Ycoordinate3, Xsize, Ysize };
				r4 = { Xcoordinate4, Ycoordinate4, Xsize, Ysize };
				checkCollision(r, left1, right1, top1, bottom1);
				checkCollision(r2, left2, right2, top2, bottom2);
				checkCollision(r3, left3, right3, top3, bottom3);
				checkCollision(r4, left4, right4, top4, bottom4);
				while (SDL_PollEvent(&ev) != NULL) {

					switch (ev.type) {
					case SDL_QUIT:
						blackWindow = true;
						break;
					case SDL_KEYDOWN:
						switch (ev.key.keysym.scancode) {
						case SDL_SCANCODE_ESCAPE: blackWindow = true; break;
							break;
						}
					case SDL_MOUSEBUTTONDOWN:
						if (ev.button.button == SDL_BUTTON_LEFT) {
							int x, y;
							SDL_GetMouseState(&x, &y);
							mouseX = x; mouseY = y;
							if (mouseX >= left1 and mouseX <= right1 and mouseY >= top1 and mouseY <= bottom1) {
								index = 1;
								userArray[i] = index;
								change_color(ren, r, 0, 220, 0, 0);
								change_color(ren, r, 0, 120, 0, 0);
								Return = false;
							}
							else if (mouseX >= left2 and mouseX <= right2 and mouseY >= top2 and mouseY <= bottom2) {
								//printf("Есть пробитие по красному\n");
								index = 2;
								userArray[i] = index;
								change_color(ren, r2, 220, 0, 0, 0);
								change_color(ren, r2, 120, 0, 0, 0);
								Return = false;
							}
							else if (mouseX >= left3 and mouseX <= right3 and mouseY >= top3 and mouseY <= bottom3) {
								//printf("Есть пробитие по желтому\n");
								index = 3;
								userArray[i] = index;
								change_color(ren, r3, 220, 220, 0, 0);
								change_color(ren, r3, 120, 120, 0, 0);
								Return = false;
							}
							else if (mouseX >= left4 and mouseX <= right4 and mouseY >= top4 and mouseY <= bottom4) {
								//printf("Есть пробитие по синему\n");
								index = 4;
								userArray[i] = index;
								change_color(ren, r4, 0, 0, 220, 0);
								change_color(ren, r4, 0, 0, 120, 0);
								Return = false;
							}
						}
					}
					switch (ev.window.event) {
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						WIDTH = ev.window.data1;
						HEIGHT = ev.window.data2;
						Xcoordinate = WIDTH / 2 - 150 - Xsize / 2;
						Ycoordinate = HEIGHT / 2 - 150 - Ysize / 2;
						Xcoordinate2 = WIDTH / 2 + 150 - Xsize / 2;
						Ycoordinate2 = HEIGHT / 2 - 150 - Ysize / 2;
						Xcoordinate3 = WIDTH / 2 - 150 - Xsize / 2;
						Ycoordinate3 = HEIGHT / 2 + 150 - Ysize / 2;
						Xcoordinate4 = WIDTH / 2 + 150 - Xsize / 2;
						Ycoordinate4 = HEIGHT / 2 + 150 - Ysize / 2;
						break;
					}

				}
				SDL_SetRenderDrawColor(ren, 200, 200, 200, 0);
				SDL_RenderClear(ren);

				SDL_SetRenderDrawColor(ren, 0, 120, 0, 0);
				SDL_RenderFillRect(ren, &r);
				SDL_SetRenderDrawColor(ren, 120, 0, 0, 0);
				SDL_RenderFillRect(ren, &r2);
				SDL_SetRenderDrawColor(ren, 120, 120, 0, 0);
				SDL_RenderFillRect(ren, &r3);
				SDL_SetRenderDrawColor(ren, 0, 0, 120, 0);
				SDL_RenderFillRect(ren, &r4);

				SDL_RenderPresent(ren);
				SDL_Delay(16);

				if (blackWindow == true) {
					SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
					SDL_RenderClear(ren);
					SDL_RenderPresent(ren);
				}
				while (blackWindow == true) {
					while (SDL_PollEvent(&ev) != NULL) {
						switch (ev.type) {
						case SDL_QUIT:
							printf("Ваш лучший результат %d\n", bestScore);
							return;
							break;
						case SDL_KEYDOWN:
							if (buttons[ev.key.keysym.scancode]) {
								blackWindow = false;
							}
							switch (ev.key.keysym.scancode) {
							case SDL_SCANCODE_ESCAPE:
								printf("Ваш лучший результат %d\n", bestScore);
								return;
								break;
							}
						}
					}
				}
			}
			if (simonArray[i] == userArray[i]) {
				fault = false;
			}
			if (simonArray[i] != userArray[i]) {
				fault = true;
			}
		}

		SDL_SetRenderDrawColor(ren, 200, 200, 200, 0);
		SDL_RenderClear(ren);

		SDL_SetRenderDrawColor(ren, 0, 120, 0, 0);
		SDL_RenderFillRect(ren, &r);
		SDL_SetRenderDrawColor(ren, 120, 0, 0, 0);
		SDL_RenderFillRect(ren, &r2);
		SDL_SetRenderDrawColor(ren, 120, 120, 0, 0);
		SDL_RenderFillRect(ren, &r3);
		SDL_SetRenderDrawColor(ren, 0, 0, 120, 0);
		SDL_RenderFillRect(ren, &r4);

		if (counter <= 20 and fault == false) {
			counter++;
			if (counter >= 2) {
				score++;
				printf("Ваши очки %d\n", score);
			}
			if (score > bestScore)
				bestScore = score;
		}
		if (counter == 10 + 1 and fault == false) {
			printf("Игра окончена\n");
			printf("Ваш лучший результат %d\n", bestScore);
		}
		if (fault == true) {
			printf("Была допущена ошибка\nОчки были вычтены\n");
			score--;
			printf("Ваши очки %d\n", score);
		}
		fault = false;
		SDL_RenderPresent(ren);
		SDL_Delay(16);

	}
}