// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Marine.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:02:35 by exam              #+#    #+#             //
//   Updated: 2015/01/09 20:24:44 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Marine.class.hpp"

Marine::Marine(void) : Unit("Marine", 0, 0, 6, 40, 40)
{
	std::cout << "Unit #" << this->_index << ": You want a piece of me, boy ?" << std::endl;
	return ;
}

Marine::Marine(Marine &src) : Unit()
{
	*this = src;
	std::cout << "Unit #" << this->_index << ": You want a piece of me, boy ?" << std::endl;
	return ;
}

Marine::Marine(int x, int y) : Unit("Marine", x, y, 6, 40, 40)
{
	std::cout << "Unit #" << this->_index << ": You want a piece of me, boy ?" << std::endl;
	return ;
}

Marine::~Marine(void)
{
	return ;
}

Marine	&Marine::operator=(Marine &rhs)
{
	this->_type = rhs._type;
	this->_xPos = rhs._xPos;
	this->_yPos = rhs._yPos;
	this->_damage = rhs._damage;
	this->_healthPoints= rhs._healthPoints;
	this->_maxHealthPoints = rhs._maxHealthPoints;
	return (*this);
}

void	Marine::die(void)
{
	Unit::die();
	std::cout << "Unit #" << this->_index << ": Aaaargh..." << std::endl;
}

void	Marine::move(int x, int y)
{
	Unit::move(x, y);
	std::cout << "Unit #" << this->_index << ": Rock'n'roll !!!" << std::endl;
}

void	Marine::stimpack(void)
{
	this->_damage *= 2;
	if (this->_healthPoints - 10 >= 1)
		this->_healthPoints -= 10;
	else
		this->_healthPoints = 1;

	std::cout << "Unit #" << this->_index << ": Ho yeah..." << std::endl;
}
