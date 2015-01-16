// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 17:42:44 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 02:56:32 by sconso           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <ctime>
# include <cstdlib>

class Span {

private:
	Span(void);

	int _getRandomValue(void) const;

	unsigned int _n;
	unsigned int _index;
	std::vector<int> _vector;

public:
	typedef std::vector<int>::iterator iterator;

	Span(const Span &src);
	Span(unsigned int n);
	~Span(void);

	/* Operator Overload */
	Span &operator=(Span const &rhs);

	/* Accessors */
	unsigned int getN(void) const;

	/* Functions */
	void dump(void) const;
	void addNumber(int nb);
	void addRange(iterator begin, iterator end);
	int shortestSpan(void);
	int longestSpan(void);

	iterator begin(void);
	iterator end(void);


	class TooHighException : public std::exception
	{
	public:
		TooHighException() throw();
		TooHighException(const TooHighException&) throw();
		TooHighException& operator= (const TooHighException&) throw();
		virtual ~TooHighException() throw();
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		NoSpanException() throw();
		NoSpanException(const NoSpanException&) throw();
		NoSpanException& operator= (const NoSpanException&) throw();
		virtual ~NoSpanException() throw();
		virtual const char* what() const throw();
	};


};

#endif
