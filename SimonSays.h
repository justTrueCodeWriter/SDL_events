#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


int random_number(); void checkCollision(SDL_Rect a, int& left, int& right, int& top, int& bottom);
void change_color(SDL_Renderer* ren, SDL_Rect rect, int red, int green, int blue, int clarity);
void SimonSays(SDL_Renderer* ren, int WIDTH, int HEIGHT);