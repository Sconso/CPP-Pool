// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scv.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:39:16 by exam              #+#    #+#             //
//   Updated: 2015/01/09 22:09:04 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCV_CLASS_HPP
# define SCV_CLASS_HPP

# include <iostream>
# include "Unit.class.hpp"
# include "IBuilder.interface.hpp"
# include "Ressource.class.hpp"
# include "CommandCenter.class.hpp"
# include "Building.class.hpp"

class Scv : public Unit, public IBuilder {

public:

	Scv(void);
	Scv(Scv &src);
	Scv(int x, int y);
	~Scv(void);

	Scv &operator=(Scv &rhs);

	void die(void);
	void move(int x, int y);

	void gatherRessources( Ressource & ressource );
	void returnRessources( CommandCenter & cc );

	Building * createBuilding( building_e building, int x, int y );
	Building * _buildCommandCenter( int x, int y );
	Building * _buildBarrack( int x, int y );
	Building * _buildSupplyDepot( int x, int y );
	Building * _buildBunker( int x, int y );

protected:

	int					_ressourceNb;
	Ressource::type_e	_ressourceType;
};

//Building *(Scv::*buildings[4])(int x, int y);

#endif
