/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Junk.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:05:10 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 15:05:11 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef JUNK_HPP
# define JUNK_HPP

class Junk
{
	public:
		Junk(void);
		~Junk(void);
		Junk(Junk const & src);
		Junk &operator=(Junk const & rhs);

		int 			getX(void) const;
		int			getY(void) const;
		int 			getN(void) const;

		void 		setN(int N);
		void 		setX(int x);
		void 		setY(int y);

	protected:
		int			x;
		int			y;
		int 			N;
};
#endif
