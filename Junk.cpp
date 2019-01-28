/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:04:57 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 22:46:29 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Junk.hpp"

Junk::Junk(void) :
x(25),
y(25),
N(100)
{
	return ;
}
Junk::~Junk(void)
{
	std::cout << "Junk Destroyed" << std::endl;
}
Junk::Junk(Junk const & src)
{
	*this = src;
}
Junk 		&Junk::operator=(Junk const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->N = rhs.getN();
	return (*this);
}
int			Junk::getX(void) const
{
	return (this->x);
}
int 			Junk::getY(void) const
{
	return (this->y);
}
int			Junk::getN(void) const
{
	return (this->N);
}
void 		Junk::setX(int x)
{
	this->x = x;
}
void 		Junk::setY(int y)
{
	this->y = y;
}
void 		Junk::setN(int N)
{
	this->N = N;
}
