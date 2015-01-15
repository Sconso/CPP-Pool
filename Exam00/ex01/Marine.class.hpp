// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Marine.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:02:45 by exam              #+#    #+#             //
//   Updated: 2015/01/09 20:17:18 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MARINE_CLASS_HPP
# define MARINE_CLASS_HPP

# include <iostream>
# include "Unit.class.hpp"

class Marine : public Unit {

public:
	Marine(void);
	Marine(Marine &src);
	Marine(int x, int y);
	~Marine(void);

	Marine &operator=(Marine &rhs);

	void	die(void);
	void	move(int x, int y);
	void	stimpack(void);
};

#endif
