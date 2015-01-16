// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/16 00:27:20 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 01:25:26 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template< typename T >
class MutantStack : public std::stack<T> {

private:
	T *_begin;

public:
	MutantStack<T>(void);
	MutantStack<T>(const MutantStack<T> &src);
	~MutantStack<T>(void);

	/* Operator Overload */
	MutantStack<T> &operator=(MutantStack<T> const &rhs);

	class iterator : public std::iterator<std::input_iterator_tag, T> {

	private:
		T* _p;

	public:
		iterator(void) { return ; }
		iterator(T* p) : _p(p) { return ; }
		iterator(iterator const &src) : _p(src._p) { return ; }
		~iterator(void) { return ; }

		/* OPERATOR */
		iterator&	operator++(void) {
			++this->_p;
			return (*this);
		}
		iterator	operator++(int) {
			iterator tmp(*this);

			++this->_p;
			return (tmp);
		}
		iterator&	operator--(void) {
			--this->_p;
			return (*this);
		}
		iterator	operator--(int) {
			iterator tmp(*this);

			--this->_p;
			return (tmp);
		}
		bool		operator==(const iterator& rhs) { return (this->_p == rhs._p); }
		bool		operator!=(const iterator& rhs) { return (this->_p != rhs._p); }
		int&		operator*(void) { return ( *(this->_p) ); }
	};

    MutantStack<T>::iterator begin();
	MutantStack<T>::iterator end();
};

#endif
