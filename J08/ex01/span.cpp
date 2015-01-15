// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 17:45:08 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/15 19:52:25 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

/* CORE */
Span::Span(void) : _n(0), _index(0) {
	return ;
}
Span::Span(Span const &src) {
	*this = src;
	return ;
}
Span::Span(unsigned int n) : _n(n), _index(0)
{
	this->_vector.reserve(n);
	return ;
}
Span::~Span(void) {
	return ;
}

/* Operator Overload */
Span &Span::operator=(Span const &rhs) {
	this->_n = rhs._n;
	this->_index = rhs._index;
	this->_vector = rhs._vector;
	return (*this);
}

/* Accessors */
unsigned int Span::getN(void) const {
	return (this->_n);
}

/* Functions */

void Span::dump(void) const
{
	unsigned int i;

	for (i = 0; i < this->_index; ++i)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
}

void Span::addNumber(int nb)
{
	if (this->_index >= this->_n)
		throw std::exception();
	else
	{
		this->_vector.push_back(nb);
		this->_index++;
	}
}

int Span::shortestSpan(void)
{
	std::vector<int> vtmp(this->_vector);
	unsigned int i = 0;
	unsigned int diff = this->longestSpan();
	unsigned int tmp = 0;

	if (this->_index < 2)
		throw std::exception();

	std::sort(vtmp.begin(), vtmp.begin() + this->_index);
	for (i = 0; i < this->_index - 1; ++i)
	{
		tmp = std::abs(vtmp[i + 1] - vtmp[i]);
		if ( tmp < diff )
			diff = tmp;
	}

	return (diff);
}

int Span::longestSpan(void)
{
	std::vector<int> vtmp(this->_vector);

	if ( this->_index < 2 )
		throw std::exception();

	std::sort(vtmp.begin(), vtmp.begin() + this->_index);
	return (vtmp[this->_index - 1] - vtmp[0]);
}
