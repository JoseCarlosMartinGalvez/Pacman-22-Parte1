// Pacman-22-Parte1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>
#define MAP_VERTICAL 27
#define MAP_HORIZONTAL 120
#define PERSONAJE 'O'
enum TYLES { EMPTY = ' ', WALL = '#', POINT = '.' };
TYLES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true;
bool win = false;

enum INPUT {QUIT ,UP , DOWN ,LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN;



int personaje_x;
int personaje_y;
int puntuacion_actual = 0;
int puntuacion_total;

void Setup() {
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;

	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1)
			{
				map[i][j] = TYLES::WALL;
			}
			else
			{
				map[i][j] = TYLES::EMPTY;
			}
		}
	}

	map[12][1] = TYLES::POINT;
	map[13][1] = TYLES::POINT;
	map[14][1] = TYLES::POINT;
	map[15][1] = TYLES::POINT;

	map[12][0] = TYLES::EMPTY;
	map[13][0] = TYLES::EMPTY;
	map[14][0] = TYLES::EMPTY;
	map[15][0] = TYLES::EMPTY;
	
	map[1][50] = TYLES::POINT;
	map[1][51] = TYLES::POINT;
	map[1][52] = TYLES::POINT;
	map[1][53] = TYLES::POINT;
	map[1][54] = TYLES::POINT;
	map[1][55] = TYLES::POINT;
	map[1][56] = TYLES::POINT;
	map[1][57] = TYLES::POINT;

	map[0][50] = TYLES::EMPTY;
	map[0][51] = TYLES::EMPTY;
	map[0][52] = TYLES::EMPTY;
	map[0][53] = TYLES::EMPTY;
	map[0][54] = TYLES::EMPTY;
	map[0][55] = TYLES::EMPTY;
	map[0][56] = TYLES::EMPTY;
	map[0][57] = TYLES::EMPTY;	
	
	map[MAP_VERTICAL - 2][50] = TYLES::POINT;
	map[MAP_VERTICAL - 2][51] = TYLES::POINT;
	map[MAP_VERTICAL - 2][52] = TYLES::POINT;
	map[MAP_VERTICAL - 2][53] = TYLES::POINT;
	map[MAP_VERTICAL - 2][54] = TYLES::POINT;
	map[MAP_VERTICAL - 2][55] = TYLES::POINT;
	map[MAP_VERTICAL - 2][56] = TYLES::POINT;
	map[MAP_VERTICAL - 2][57] = TYLES::POINT;

	map[MAP_VERTICAL - 1][50] = TYLES::EMPTY;
	map[MAP_VERTICAL - 1][51] = TYLES::EMPTY;
	map[MAP_VERTICAL - 1][52] = TYLES::EMPTY;
	map[MAP_VERTICAL - 1][53] = TYLES::EMPTY;	
	map[MAP_VERTICAL - 1][54] = TYLES::EMPTY;
	map[MAP_VERTICAL - 1][55] = TYLES::EMPTY;
	map[MAP_VERTICAL - 1][56] = TYLES::EMPTY;
	map[MAP_VERTICAL - 1][57] = TYLES::EMPTY;

	map[12][MAP_HORIZONTAL -3] = TYLES::POINT;
	map[13][MAP_HORIZONTAL -3] = TYLES::POINT;
	map[14][MAP_HORIZONTAL -3] = TYLES::POINT;
	map[15][MAP_HORIZONTAL -3] = TYLES::POINT;

	map[12][MAP_HORIZONTAL - 1] = TYLES::EMPTY;
	map[13][MAP_HORIZONTAL - 1] = TYLES::EMPTY;
	map[14][MAP_HORIZONTAL - 1] = TYLES::EMPTY;
	map[15][MAP_HORIZONTAL - 1] = TYLES::EMPTY;

	map[12][12] = TYLES::WALL;
	map[13][12] = TYLES::WALL;
	map[14][12] = TYLES::WALL;
	map[15][12] = TYLES::WALL;
	
	map[12][MAP_HORIZONTAL -12] = TYLES::WALL;
	map[13][MAP_HORIZONTAL - 12] = TYLES::WALL;
	map[14][MAP_HORIZONTAL - 12] = TYLES::WALL;
	map[15][MAP_HORIZONTAL - 12] = TYLES::WALL;

	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (map[i][j] == TYLES::POINT) {
				puntuacion_total++;
			}
			
		}
	}
}

void Input() {
	char input;
	std::cin >> input;
	switch (input)
	{
	case 'w':
	case 'W':
		currentInput = INPUT::UP;
		break;
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	case 's':
	case 'S':
		currentInput = INPUT::DOWN;
		break;
	case 'a':
	case 'A':
		currentInput = INPUT::LEFT;
		break;
	case 'd':
	case 'D':
		currentInput = INPUT::RIGHT;
		break;
	}

}

void Logic() {
	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;
	switch(currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case RIGHT:
		personaje_x_new++;
		break;
	}
	if (puntuacion_actual == puntuacion_total) {
		run = false;
		win = true;
	}
	if (personaje_x_new < 0) {
		personaje_x_new = MAP_HORIZONTAL - 1;
	}
	personaje_x_new = personaje_x_new % MAP_HORIZONTAL;

	if (personaje_y_new < 0) {
		personaje_y_new = MAP_VERTICAL - 1;
	}
	personaje_y_new = personaje_y_new % MAP_VERTICAL;

	switch (map[personaje_y_new][personaje_x_new])
	{
	case TYLES::WALL:
		break;
	case TYLES::POINT:
		puntuacion_actual++;
		map[personaje_y_new][personaje_x_new] = TYLES::EMPTY;
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
	}
	
}

void Draw() {
	system("CLS");
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == personaje_y && j == personaje_x) {
				std::cout << PERSONAJE;
			}
			std::cout << (char)map[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << puntuacion_actual<<'/'<< puntuacion_total << std::endl;
	system("color 0e");
	
}


int main()
{
	Setup();
	Draw();
	while (run)
	{
		Input();
		Logic();
		Draw();
	}
	if (win=true)
	{
		std::cout << "Has ganado";
	}
}
