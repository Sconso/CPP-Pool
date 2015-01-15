// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 18:47:41 by exam              #+#    #+#             //
//   Updated: 2015/01/09 19:54:04 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Unit.class.hpp"

Unit::Unit(void) : _index(Unit::_instanceNb), _type("Unit"), _xPos(0), _yPos(0),
				   _damage(0), _healthPoints(0), _maxHealthPoints(0)
{
	std::cout << "[CREATED] Unit #" << this->_index << ": " << this->_type << " in " << this->_xPos << "/" << this->_yPos << " with ";
	std::cout << this->_healthPoints << "/" << this->_maxHealthPoints << "HP damaging at " << this->_damage << "." << std::endl;
	Unit::_instanceNb++;
	return ;
}

Unit::Unit(Unit &src)
{
	*this = src;
	this->_index = Unit::_instanceNb;

	std::cout << "[CREATED] Unit #" << this->_index << ": " << this->_type << " in " << this->_xPos << "/" << this->_yPos << " with ";
	std::cout << this->_healthPoints << "/" << this->_maxHealthPoints << "HP damaging at " << this->_damage << "." << std::endl;
	
	Unit::_instanceNb++;
	return ;
}

Unit::Unit(std::string type, int xPos, int yPos, int damage, int healthPoints, int maxHealthPoints) : _index(Unit::_instanceNb),
																									  _type(type), _xPos(xPos), _yPos(yPos),
																									  _damage(damage), _healthPoints(healthPoints),
																									  _maxHealthPoints(maxHealthPoints)
{
	std::cout << "[CREATED] Unit #" << this->_index << ": " << this->_type << " in " << this->_xPos << "/" << this->_yPos << " with ";
	std::cout << this->_healthPoints << "/" << this->_maxHealthPoints << "HP damaging at " << this->_damage << "." << std::endl;

	Unit::_instanceNb++;
	return ;
}

Unit::~Unit(void) {
	std::cout << "[DESTRUCTED] Unit #" << this->_index << ": " << this->_type << " in " << this->_xPos << "/" << this->_yPos << " with ";
	std::cout << this->_healthPoints << "/" << this->_maxHealthPoints << "HP damaging at " << this->_damage << "." << std::endl;

	return ;
}

Unit	&Unit::operator=(Unit &rhs)
{
	this->_type = rhs._type;
	this->_xPos = rhs._xPos;
	this->_yPos = rhs._yPos;
	this->_damage = rhs._damage;
	this->_healthPoints= rhs._healthPoints;
	this->_maxHealthPoints = rhs._maxHealthPoints;
	return (*this);
}

int		&Unit::operator+=(int value)
{
	if (this->_healthPoints + value <= this->_maxHealthPoints)
		this->_healthPoints += value;
	else
		this->_healthPoints = this->_maxHealthPoints;
	return (this->_healthPoints);
}

int		&Unit::operator-=(int value)
{
	if (this->_healthPoints - value > 0)
		this->_healthPoints -= value;
	else
		this->die();
	return (this->_healthPoints);
}

int Unit::getIndex( void ) const {
	return (this->_index);
}

std::string const & Unit::getType( void ) const {
	return (this->_type);
}

int Unit::getX( void ) const {
	return (this->_xPos);
}

int Unit::getY( void ) const {
	return (this->_yPos);
}

int Unit::getDam( void ) const {
	return (this->_damage);
}

int Unit::getCHP( void ) const {
	return (this->_healthPoints);
}

int Unit::getMHP( void ) const {
	return (this->_maxHealthPoints);
}


void Unit::die(void)
{
	if (this->_healthPoints > 0)
	{
		std::cout << "Unit #" << this->_index << " (" << this->_type << ") died." << std::endl;
		this->_healthPoints = 0;
	}
}

void Unit::move(int x, int y)
{
	if (this->_healthPoints > 0)
	{
		std::cout << "Unit #" << this->_index << " (" << this->_type << ") is moving from " << this->_xPos << "/" << this->_yPos << " to " << x << "/" << y << "." << std::endl;
		this->_xPos = x;
		this->_yPos = y;
	}

	return ;
}

void Unit::attack( Unit & target ) const
{
	if (this->_healthPoints > 0)
	{
		std::cout << "Unit #" << this->_index << " (" << this->_type << ") damaged unit #" << target.getIndex() << " (" << target.getType() << ")." << std::endl;
		target -= this->_damage;
	}
}

int		Unit::_instanceNb = 0;

std::ostream &operator<<(std::ostream& stream, Unit &rhs)
{
	return (stream << "Unit #" << rhs.getIndex() << ": " << rhs.getType() << " in " << rhs.getX() << "/" << rhs.getY() << " with " << rhs.getCHP() << "/" << rhs.getMHP() << "HP damaging at " << rhs.getDam() << ".");
}
