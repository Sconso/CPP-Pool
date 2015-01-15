// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.tpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 20:57:41 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/15 01:17:17 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <sstream>

template < typename T >
class Array {

private:
	T *_array;
	unsigned int _size;

public:
	Array<T>(void) : _array(NULL), _size(0) {
		this->_array = new T[0];
	}
	Array<T>(unsigned int const n) : _array(NULL), _size(n) {
		this->_array = new T[n];
	}
	Array<T>(Array const &src) : _array(NULL) {
		*this = src;
	}
	~Array<T>(void) {
		if (this->_array) { delete [] this->_array; }
	}

	unsigned int size(void) const { return (this->_size); }

	void dump(std::string const &name = "") const {
		unsigned int i;

		std::cout << "=== DUMPING " << name << " ===" << std::endl;
		for (i = 0; i < this->_size; i++)
			std::cout << this->_array[i] << std::endl;
		std::cout << "=== END ===" << std::endl << std::endl;
	}

	T&		operator[](int i);
	Array&	operator=(Array const &rhs);

	class IndexTooLowException : public std::exception
	{
	private:
		int _index;
	public:
		IndexTooLowException() throw() { return ; }
		IndexTooLowException(int index) throw() : _index(index) { return ; }
		IndexTooLowException(const IndexTooLowException& src) throw() { *this = src; }
		virtual ~IndexTooLowException() throw() { return ; }

		IndexTooLowException& operator= (const IndexTooLowException& rhs) throw() { this->_index = rhs._index; return (*this); }
		virtual const char* what() const throw() {
			std::stringstream ss;
			std::string str;

			ss << "\033[31mIndex too low (index = " << this->_index << ").\033[0m";
			str = ss.str();

			return (str.c_str());
		}
	};

	class IndexTooHighException : public std::exception
	{
	private:
		int _index;
	public:
		IndexTooHighException() throw() { return ; }
		IndexTooHighException(int index) throw() : _index(index) { return ; }
		IndexTooHighException(const IndexTooHighException& src) throw() { *this = src; }
		virtual ~IndexTooHighException() throw() { return ; }

		IndexTooHighException& operator= (const IndexTooHighException& rhs) throw() { this->_index = rhs._index; return (*this); }
		virtual const char* what() const throw() {
			std::stringstream ss;
			std::string str;

			ss << "\033[31mIndex too high (index = " << this->_index << ").\033[0m";
			str = ss.str();

			return (str.c_str());
		}
	};
};

template< typename T >
T &Array<T>::operator[](int i) {

	if (i < 0)
		throw Array<T>::IndexTooLowException(i);
	else if (static_cast<unsigned int>(i) >= this->_size)
		throw Array<T>::IndexTooHighException(i);
	return (this->_array[i]);
}

template< typename T >
Array<T> &Array<T>::operator=(Array<T> const &rhs) {
	unsigned int i;

	if (this != &rhs)
	{
		if (this->_array)
			delete [] this->_array;

		this->_array = new T[rhs._size];

		for (i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
		this->_size = rhs._size;
	}

	return (*this);
}

#endif // ARRAY_TPP
