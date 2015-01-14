// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   whatever.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 15:16:35 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/14 20:14:53 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

class Test {

public:
	Test(void) : _val(0) { }
	Test(int val) : _val(val) { }
	Test(Test const &src) { *this = src; }
	~Test(void) {}

	int getVal(void) const { return (this->_val); }
	Test &operator=(Test const &rhs) { this->_val = rhs._val; return (*this); }

private:
	int _val;
};

std::ostream &	operator<<(std::ostream &o, Test const &rhs) { return ( o << rhs.getVal() ); }
bool 			operator<(Test const &lhs, Test const& rhs) { return ( lhs.getVal() < rhs.getVal() ); }
bool 			operator>(Test const &lhs, Test const& rhs) { return ( lhs.getVal() > rhs.getVal() ); }

// ************************************************************************** //

template< typename T >
void swap(T &val1, T &val2)
{
	T tmp;

	tmp = val1;
	val1 = val2;
	val2 = tmp;
}

template< typename T >
T const & min(T const &val1, T const &val2)
{
	return ( (val1 < val2) ? val1 : val2 );
}

template < typename T >
T const & max(T const &val1, T const &val2)
{
	return ( (val1 > val2) ? val1 : val2 );
}

int main()
{
	int a = 3;
	int b = 3;

	std::string c = "chaine1";
	std::string d = "chaine2";

	char e = 'e';
	char f = 'f';

	float g = 4.2f;
	float h = 8.23f;

	Test t1(42);
	Test t2(24);

// ************************************************************************** //

	std::cout << "====== INIT ======" << std::endl;

	std::cout << "INT" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

	std::cout << "STRING" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

	std::cout << "CHAR" << std::endl;
	std::cout << "e = '" << e << "', f = '" << f << "'" << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl << std::endl << std::endl;

// ************************************************************************** //

	std::cout << "====== LET'S SWAP ! ======" << std::endl;

	::swap(a, b);
	::swap(c, d);
	::swap(e, f);
	::swap(g, h);
	::swap(t1, t2);

	std::cout << "INT" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

	std::cout << "STRING" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

	std::cout << "CHAR" << std::endl;
	std::cout << "e = '" << e << "', f = '" << f << "'" << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl << std::endl << std::endl;

// ************************************************************************** //

	std::cout << "====== MIN ======" << std::endl;

	std::cout << "INT" << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b)  << std::endl << std::endl;

	std::cout << "STRING" << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d)  << std::endl << std::endl;

	std::cout << "CHAR" << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f)  << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	std::cout << "min(g, h) = " << ::min(g, h)  << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	std::cout << "min(t1, t2) = " << ::min(t1, t2)  << std::endl << std::endl;

// ************************************************************************** //

	std::cout << "====== MAX ======" << std::endl;

	std::cout << "INT" << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b)  << std::endl << std::endl;

	std::cout << "STRING" << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d)  << std::endl << std::endl;

	std::cout << "CHAR" << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f)  << std::endl << std::endl;

	std::cout << "FLOAT" << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h)  << std::endl << std::endl;

	std::cout << "TEST" << std::endl;
	std::cout << "max(t1, t2) = " << ::max(t1, t2)  << std::endl;

	return (0);
}
