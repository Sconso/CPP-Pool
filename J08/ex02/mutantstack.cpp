// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/16 00:27:44 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 02:19:15 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "mutantstack.hpp"

/* CORE */
template <typename T>
MutantStack<T>::MutantStack(void) {
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) {
	*this = src;
	return ;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
	return ;
}

/* Operator Overload */
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &rhs) {
	std::stack<T>::operator=(rhs);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	T* p;
	unsigned int i;

	p = &(this->top());
	for (i = 1; i < this->size(); ++i)
		--p;

	return (MutantStack<T>::iterator(p));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	T* p;

	p = &(this->top());
	++p;
	return (MutantStack<T>::iterator(p));
}
