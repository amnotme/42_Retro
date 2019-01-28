/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:49:55 by hasmith           #+#    #+#             */
/*   Updated: 2019/01/26 16:00:55 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <string>
# include <iostream>
# include <ncurses.h>
# include <curses.h>
# include <iostream>
# include <thread>
# include <chrono>
# include <ctime>

class Game {
    public:
		// Game(std::string n);
		Game(void);
		~Game(void);
		Game(Game const & src);
		Game &operator=(Game const & rhs);

		int getMapX(void) const;
		int getMapY(void) const;
		void init_ncurses(void);
	private:
		int mapx;
		int mapy;

};

void 	init_ncurses(void);
#endif
