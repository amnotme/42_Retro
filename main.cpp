/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:54:34 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/27 23:34:47 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int	main(void) 
{
	int c = 0;
	int startX; // initial x value for the enemies
	int x;
	int y;
	int number; // number of enemies to spawn

	startX = 10;
	x = 10;
	y = 2;
	number = 30;
	srand(time(NULL));

	initscr();//creates std screen
	cbreak();//enter raw modal
	noecho();
	curs_set(0);

	Game *game = new Game(); // creates an instance of game

	mvprintw(game->getMapY()/4 - 9, (game->getMapX()/2) - 14,  "      `/hdho` +dho+dddy \n");
	mvprintw(game->getMapY()/4 - 8, (game->getMapX()/2) - 14,  "    `+dMNh:   oh: +MMMd \n");
	mvprintw(game->getMapY()/4 - 7, (game->getMapX()/2) - 14,  "  .+mMNy-     ` `:dMMd/ \n");
	mvprintw(game->getMapY()/4 - 6, (game->getMapX()/2) - 14,  ".omMNy-`      `/dMMh/`  \n");
	mvprintw(game->getMapY()/4 - 5, (game->getMapX()/2) - 14,  "dMMMNdddddddo oMMMh` -o \n");
	mvprintw(game->getMapY()/4 - 4, (game->getMapX()/2) - 14,  "hdddddddNMMMy sMMMy:hNd \n");
	mvprintw(game->getMapY()/4 - 3, (game->getMapX()/2) - 14,  "````````sMMMy .---..--. \n");
	mvprintw(game->getMapY()/4 - 2, (game->getMapX()/2) - 14,  "        +dddo           \n");
	mvprintw(game->getMapY()/4 - 1, (game->getMapX()/2) - 14,  "                        \n");

	getch();
	clear();

	game->init_ncurses();
	Player *player = new Player();  // creates the movable player
	Enemy *enemies = new Enemy[number]; // number of enemies on the stack.

	player->setGame(game);
	player->drawPlayer();
	int i = 0;
	int clock = 0;
	int lastEnemy = 0;
	int kills = 0;
	int winNum = 10;
	int trys = 0;
	int lives = 3;
	while (1)
	{
		// Top left of screen to print lives left
		std::string s = "You have: " + std::to_string(lives - (trys/6)) + " lives left  ";
		//\n " + std::to_string(kills) + " more kills to win!  ";
		mvwprintw(stdscr, 1, 1, s.c_str());
		if (clock - lastEnemy > 100)
		{
			for (int i = 0; i < number; i++)
			{
				if (enemies[i].getN() == 0)
				{
					enemies[i].setY(2); //spawns enemies at varying x + 5 offsets
					enemies[i].setX((rand() % (game->getMapX()-4))+2); //spawns enemies at varying x + 5 offsets
					enemies[i].setN(1);
					lastEnemy = clock;
					break;
				}
			}
		}
		if ((c = getch()) != ERR)
		{
			player->getInput(c, game);
		}
		while (i < number)
		{
			if (player->missilesCollisions(enemies[i].getX(), enemies[i].getY()))
			{
				enemies[i].killEnemy();
				// kills++;
			} 
			// Enemy collides with player
			if (enemies[i].getX() == player->getX() && enemies[i].getY() == player->getY())
				exit(1);
			enemies[i++].drawEnemy(); //loop that crreates all the enemies
		}
		player->drawMissiles();
		player->drawPlayer();
		usleep(5000);
		i = 0;
		if (win(enemies, game, number))
		{
			trys++;
			if (trys / 6 >= lives)
				exit(0);
		}
		if (kills == winNum)
			exit(0);
		clock++;
	}
	endwin();
	delete player; //delete player on the heap
	delete game; // delete the game on the heap
	return (0);
}
