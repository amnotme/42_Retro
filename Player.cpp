/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:42 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/28 00:43:17 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
# include <ncurses.h>
# include <curses.h>
# include <iostream>
# include <thread>
# include <chrono>

Player::Player(void) :
numberOfMissiles(100)
{
	// std::cout << "You have: " << numberOfMissiles << " missiles" << std::endl;
	this->missile = new Missile[100];
	this->currMissile = 0;
	return ;
}
Player::~Player(void)
{
	std::cout << "Player Destroyed" << std::endl;
}
Player::Player(Player const & src)
{
	*this = src;
}
Player 		&Player::operator=(Player const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	return (*this);
}

void 		Player::moveRight(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() + 1, getX() + 1, ' ');
	mvaddch(getY() + 1, getX() - 1, ' ');
	this->setX(x + 2);

}
void 		Player::moveLeft(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() + 1, getX() + 1, ' ');
	mvaddch(getY() + 1, getX() - 1, ' ');
	this->setX(x - 2);
}
void 		Player::drawPlayer(void)
{
	attron(COLOR_PAIR(1));
	mvaddch(this->getY(), this->getX(), '^');
	mvaddch(this->getY() + 1, getX() + 1, '^');
	mvaddch(this->getY() + 1, getX() - 1, '^');
	attroff(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	refresh();
}
int 		Player::missilesCollisions(int ex, int ey)
{
	for (int i = 0; i < this->numberOfMissiles; i++)
	{
		if (this->missile[i].missileCollision(ex, ey))
			return 1;
	}
	return 0;
}
void		Player::setGame(Game *game)
{
	this->game = game;
	this->setX(this->game->getMapX()/2);
	this->setY(this->game->getMapY()-4);

}
void 		Player::drawMissiles(void)
{
	for (int i = 0; i < this->numberOfMissiles; i++){
		if (this->missile[i].getN() > 0)
		{
			this->missile[i].drawMissile(this->game);
		}
	}
}
void 		Player::getInput(char c, Game *game)
{
	if (c == 27)
		exit(0);
	if ((c == '4') && (this->getX() > 2))
		moveLeft();
	else if ((c == '6') && (this->getX() < game->getMapX() - 4))
		moveRight();
	else if (c == ' ')
	{
		this->missile[currMissile].setX(this->getX());
		this->missile[currMissile].setY(this->getY());
		this->missile[currMissile].setN(1);//set health
		currMissile++;
		currMissile %= this->numberOfMissiles;
	}
	drawPlayer();
}
