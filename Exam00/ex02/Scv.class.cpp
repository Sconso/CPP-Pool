// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scv.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:39:09 by exam              #+#    #+#             //
//   Updated: 2015/01/09 22:28:52 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Scv.class.hpp"

Scv::Scv(void) : Unit("SCV T-280", 0, 0, 5, 60, 60)
{
	std::cout << "Unit #" << this->_index << ": SCV good to go, sir." << std::endl;
	return ;
}

Scv::Scv(Scv &src) : Unit()
{
	*this = src;

	std::cout << "Unit #" << this->_index << ": SCV good to go, sir." << std::endl;
	return ;
}

Scv::Scv(int x, int y) : Unit("SCV T-280", x, y, 5, 60, 60)
{
	std::cout << "Unit #" << this->_index << ": SCV good to go, sir." << std::endl;
	return ;
}

Scv::~Scv(void)
{
	return ;
}

Scv	&Scv::operator=(Scv &rhs)
{
	this->_type = rhs._type;
	this->_xPos = rhs._xPos;
	this->_yPos = rhs._yPos;
	this->_damage = rhs._damage;
	this->_healthPoints= rhs._healthPoints;
	this->_maxHealthPoints = rhs._maxHealthPoints;
	return (*this);
}

void Scv::die(void)
{
	Unit::die();
	std::cout << "Unit #" << this->_index << ": * noise of an exploding SCV *." << std::endl;
}

void	Scv::move(int x, int y)
{
	Unit::move(x, y);
	std::cout << "Unit #" << this->_index << ": Affirmative." << std::endl;
}

void Scv::gatherRessources( Ressource & ressource )
{
	if (this->_xPos != ressource.getX() || this->_yPos != ressource.getY())
		Unit::move(ressource.getX(), ressource.getY());

	if (!ressource.isDepleted() && this->_ressourceNb == 0)
	{
		this->_ressourceType = (Ressource::type_e)ressource.type;
		this->_ressourceNb = ressource.gather();
		std::cout << "Unit #" << this->_index << " (" << this->_type << ") gathered " << this->_ressourceNb << " " << ((this->_ressourceType == 1) ? "minerals" : "gas")  << "." << std::endl;
	}
}

void Scv::returnRessources( CommandCenter & cc )
{
	if (this->_xPos != cc.getX() || this->_yPos != cc.getY())
		Unit::move(cc.getX(), cc.getY());

	cc.acceptRessources(this->_ressourceType, this->_ressourceNb);
	std::cout << "Unit #" << this->_index << " (" << this->_type << ") returned " << this->_ressourceNb << " " << ((this->_ressourceType == 1) ? "minerals" : "gas") << "." << std::endl;
	this->_ressourceNb = 0;
}

Building * (Scv::*buildings[4])(int x, int y) = { &Scv::_buildCommandCenter,
												&Scv::_buildBarrack,
												&Scv::_buildSupplyDepot,
												&Scv::_buildBunker };

Building * Scv::createBuilding( building_e building, int x, int y )
{
	Building *build;

	if (this->_xPos != x || this->_yPos != y)
		this->move(x, y);

	if (building > IBuilder::BUNKER)
	{
		std::cout << "Unit #" << this->_index << ": No such building, sir." << std::endl;
		return (NULL);
	}
	else
	{
		build = (this->* buildings[((int)building) - 1]) (x, y);
		return (build);
	}

}

Building * Scv::_buildCommandCenter( int x, int y )
{
	Building *building;

	std::cout << "Unit #" << this->_index << ": Command center finished, sir." << std::endl;
	building = new Building("Command Center", x, y, 1500, 1500);
	return (building);
}

Building * Scv::_buildBarrack( int x, int y )
{
	Building *building;

	std::cout << "Unit #" << this->_index << ": Barrack finished, sir." << std::endl;
	building = new Building("Barracks", x, y, 1000, 1000);
	return (building);
}

Building * Scv::_buildSupplyDepot( int x, int y )
{
	Building *building;

	std::cout << "Unit #" << this->_index << ": Supply depot finished, sir." << std::endl;
	building = new Building("SupplyDepot", x, y, 500, 500);
	return (building);
}

Building * Scv::_buildBunker( int x, int y )
{
	Building *building;

	std::cout << "Unit #" << this->_index << ": Bunker finished, sir." << std::endl;
	building = new Building("Bunker", x, y, 350, 350);
	return (building);
}
