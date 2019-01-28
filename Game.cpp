/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:50 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/27 22:45:58 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void) :
mapx(100),
mapy(100)
{
    srand(time(0));
}
Game::~Game(void)
{
    return;
}

Game::Game(Game const & src)
{
	(*this) = src;
}
Game		&Game::operator=(Game const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->mapx = rhs.getMapX();
	this->mapy = rhs.getMapY();
	return (*this);
}
int 		Game::getMapX(void) const
{
	return (this->mapx);
}
int 		Game::getMapY(void) const
{
	return (this->mapy);
}
//non-member function
void  	Game::init_ncurses(void) {
	int col = 0;
	int row = 0;
	int c = 0;

	getmaxyx(stdscr, col, row);
	this->mapx = row;
	this->mapy = col;
	keypad(stdscr, TRUE);// Keys on numberpad
	nodelay(stdscr, TRUE);//

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	refresh();

	// Draw box/start screen
	attron(COLOR_PAIR(4));
	mvaddch(0, 0, c);
	attroff(COLOR_PAIR(4));
	box(stdscr, 0, 0);
	refresh();
}
