/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:33:43 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 23:06:24 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <math.h>

Enemy::Enemy(void)
:
wait(0)
{
	this->setN(0);
	this->setX(-1);
	this->setY(-1);
	return ;
}
Enemy::~Enemy(void)
{
	std::cout << "Enemy Destroyed" << std::endl;
}
Enemy::Enemy(Enemy const & src)
{
	*this = src;
}
Enemy 		&Enemy::operator=(Enemy const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->N = rhs.getN();
	return (*this);
}
void 		Enemy::clearEnemy(void)
{
	mvaddch(getY(), getX(), ' ');
	mvaddch(getY() - 1, getX() + 1, ' ');
	mvaddch(getY() - 1, getX() - 1, ' ');
	refresh();
}
void 		Enemy::killEnemy(void)
{
	this->clearEnemy();
	this->setN(0);
	this->setX(-1);
	this->setY(-1);
}
void 		Enemy::moveDown(void)
{
	wait+=1;
	if (wait % 6 == 0)
	{
		this->clearEnemy();
		mvaddch(getY(), getX(), ' ');
		mvaddch(getY() - 1, getX() + 1, ' ');
		mvaddch(getY() - 1, getX() - 1, ' ');
		this->setY(getY() + 1);
		wait = 0;
	}
}
void 		Enemy::drawEnemy(void)//game instance is passed to know the map size;
{
	moveDown();
	attron(COLOR_PAIR(2));
	mvaddch(this->getY() - 1, getX() + 1, '#');
	mvaddch(this->getY() - 1, getX() - 1, '#');
	mvaddch(this->getY(), this->getX(), '#');
	attroff(COLOR_PAIR(2));
	box(stdscr, 0, 0);
	refresh();
	usleep(700); // creates small delay for the enemies as they move left to right and back.
}

int 		win(Enemy *enemies, Game *game, int number)
{
	int i = 0;
	while (i < number)
	{
		if (enemies[i++].getY() == game->getMapY() - 3)
			return (1);
	}
	return (0);
}
