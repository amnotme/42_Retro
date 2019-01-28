/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:48 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/26 17:23:49 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Enemy_HPP
# define Enemy_HPP
# include "Game.hpp"
# include "Junk.hpp"
# include <unistd.h>

class Enemy : public Junk
{
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(Enemy const & src);
		Enemy &operator=(Enemy const & rhs);
		//methods for movements
		void 		moveDown(void);
		//methods for game mechanics using ncursus
		void 		drawEnemy(void);
		void 		clearEnemy(void);
		void 		killEnemy(void);
	private:
		int 	wait;

};
int 		win(Enemy *enemies, Game *game, int number);

#endif
