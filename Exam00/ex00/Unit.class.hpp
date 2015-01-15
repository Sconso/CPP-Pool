// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 18:47:55 by exam              #+#    #+#             //
//   Updated: 2015/01/09 20:25:25 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

# include <iostream>

class Unit {

public:
	Unit(void);
	Unit(Unit &src);
	Unit(std::string type, int xPos, int yPos, int damage, int healthPoints, int maxHealthPoints);
	~Unit(void);

	Unit &operator=(Unit &rhs);
	int &operator+=(int value);
	int &operator-=(int value);

	int getIndex( void ) const;
	std::string const & getType( void ) const;
	int getX( void ) const;
	int getY( void ) const;
	int getDam( void ) const;
	int getCHP( void ) const;
	int getMHP( void ) const;

	void die(void);
	void move(int x, int y);
	void attack( Unit & target ) const;

protected:
	int				_index;
	std::string		_type;
	int				_xPos;
	int				_yPos;
	int				_damage;
	int				_healthPoints;
	int				_maxHealthPoints;

	static int		_instanceNb;
};

std::ostream& operator<<(std::ostream&, Unit &rhs);

#endif
