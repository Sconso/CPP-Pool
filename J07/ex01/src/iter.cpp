// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 15:25:00 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/14 20:56:31 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

// ************************************************************************** //
//                                 TEST CLASS                                 //
// ************************************************************************** //
class Test {

public:
	Test(void) : _val(0) { }
	Test(int val) : _val(val) { }
	Test(Test const &src) { *this = src; }
	~Test(void) {}

	int getVal(void) const { return (this->_val); }
	Test &operator=(Test const &rhs) { this->_val = rhs._val; return (*this); }
	Test &operator*=(int const rhs) { this->_val *= rhs; return (*this); }
	Test &operator*=(Test const &rhs) { this->_val *= rhs.getVal(); return (*this); }

private:
	int _val;
};

std::ostream &	operator<<(std::ostream &o, Test const &rhs) { return ( o << rhs.getVal() ); }

// ************************************************************************** //
//                          SOME FUNCTIONS FOR TESTS                          //
// ************************************************************************** //

template < typename T >
void printElem(T &elem) { std::cout << elem << " "; }

template < typename T >
void doubleElem(T &elem) { elem *= 2; }

template < typename T >
void squareElem(T &elem) { elem *= elem; }

template < typename T >
void printArray(T const *array, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

// ************************************************************************** //
//                         HERE IS THE ITER FUNCTION                          //
// ************************************************************************** //

template < typename T, typename F >
void iter(T * const array, unsigned int const size, F (*func)(T &))
{
	unsigned int i;

	for (i = 0; i < size; i++)
		func(array[i]);
}

int main(void)
{
	char			ctab[15] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'};
	int 			itab[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	float			ftab[15] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f, 11.11f, 12.12f, 13.13f, 14.14f, 15.15f};
	std::string		stab[15] = {"Hello", "this", "is", "a", "very", "long", "sentence", "divided", "in", "words", "into", "a", "fucking", "useless", "array"};
	Test			ttab[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

// ************************************************************************** //

	std::cout << "====== INIT ======" << std::endl;

	std::cout << "CHAR" << std::endl;
	iter(ctab, 15, printElem<char>);
	std::cout << std::endl << std::endl;

	std::cout << "INT" << std::endl;
	iter(itab, 15, printElem<int>);
	std::cout << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	iter(ftab, 15, printElem<float>);
	std::cout << std::endl << std::endl;

	std::cout << "STRING" << std::endl;
	iter(stab, 15, printElem<std::string>);
	std::cout << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	iter(ttab, 15, printElem<Test>);
	std::cout << std::endl << std::endl;

// ************************************************************************** //

	std::cout << "====== LET'S DOUBLE EVERYTHING ! ======" << std::endl;

	std::cout << "INT" << std::endl;
	iter(itab, 15, doubleElem<int>);
	iter(itab, 15, printElem<int>);
	std::cout << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	iter(ftab, 15, doubleElem<float>);
	iter(ftab, 15, printElem<float>);
	std::cout << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	iter(ttab, 15, doubleElem<Test>);
	iter(ttab, 15, printElem<Test>);
	std::cout << std::endl << std::endl;

// ************************************************************************** //

	std::cout << "====== OR SQUARE IT ! ======" << std::endl;

	std::cout << "INT" << std::endl;
	iter(itab, 15, squareElem<int>);
	iter(itab, 15, printElem<int>);
	std::cout << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	iter(ftab, 15, squareElem<float>);
	iter(ftab, 15, printElem<float>);
	std::cout << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	iter(ttab, 15, squareElem<Test>);
	iter(ttab, 15, printElem<Test>);
	std::cout << std::endl;

	return (0);
}
