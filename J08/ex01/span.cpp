// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 17:45:08 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 02:56:18 by sconso           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

# define MAX_NB (25000000)

/* CORE */
Span::Span(void) : _n(0), _index(0) {
	std::srand(time(NULL));
	return ;
}
Span::Span(Span const &src) {
	std::srand(time(NULL));
	*this = src;
	return ;
}
Span::Span(unsigned int n) : _n(n), _index(0)
{
	std::srand(std::time(NULL));
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

	std::cout << "================" << std::endl;

	std::cout << "Current Index = " << this->_index << std::endl;
	std::cout << "Max Size = " << this->_n << std::endl;

	for (i = 0; i < this->_index; ++i)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl << "================" << std::endl;
}

void Span::addNumber(int nb)
{
	if (this->_index >= this->_n)
		throw TooHighException();
	else
	{
		this->_vector.push_back(nb);
		this->_index++;
	}
}

void Span::addRange(Span::iterator begin, Span::iterator end)
{
	Span::iterator it;

	if ( begin > (this->_vector.begin() + this->_index) )
		throw TooHighException();
	if (begin > end)
	{
		Span::iterator tmp = begin;
		begin = end;
		end = tmp;
	}

	for (it = begin; it < end; it++)
	{
		if (it < this->begin() + this->_index)
			*it = this->_getRandomValue();
		else
			this->addNumber(this->_getRandomValue());
	}
}

int Span::shortestSpan(void)
{
	std::vector<int> vtmp(this->_vector);
	unsigned int i = 0;
	unsigned int diff = this->longestSpan();
	unsigned int tmp = 0;

	if (this->_index < 2)
		throw NoSpanException();

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
		throw NoSpanException();

	std::sort(vtmp.begin(), vtmp.begin() + this->_index);
	return (std::abs(vtmp[this->_index - 1] - vtmp[0]));
}

Span::iterator Span::begin(void) { return (this->_vector.begin()); }
Span::iterator Span::end(void) { return ( this->_vector.begin() + this->_n ); }

int Span::_getRandomValue(void) const
{
	int val;

	val = (std::rand() % MAX_NB * 2) - MAX_NB;
	return (val);
}

// ************************************************************************** //
//                                                                            //
//                                 EXCEPTIONS                                 //
//                                                                            //
// ************************************************************************** //

Span::TooHighException::TooHighException(void) throw() { return ; }
Span::TooHighException::TooHighException(const Span::TooHighException& src) throw() { *this = src; }
Span::TooHighException::~TooHighException() throw() { return ; }

Span::TooHighException& Span::TooHighException::operator= (const Span::TooHighException& rhs) throw() {
	static_cast<void>(rhs);
	return (*this);
}
const char* Span::TooHighException::what() const throw() {
	return ("Container is full.");
}

Span::NoSpanException::NoSpanException(void) throw() { return ; }
Span::NoSpanException::NoSpanException(const Span::NoSpanException& src) throw() { *this = src; }
Span::NoSpanException::~NoSpanException() throw() { return ; }

Span::NoSpanException& Span::NoSpanException::operator= (const Span::NoSpanException& rhs) throw() {
	static_cast<void>(rhs);
	return (*this);
}
const char* Span::NoSpanException::what() const throw() {
	return ("Not enough elements to get a span.");
}
