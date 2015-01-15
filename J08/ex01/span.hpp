// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 17:42:44 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/15 19:33:27 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {

private:
	Span(void);

	unsigned int _n;
	unsigned int _index;
	std::vector<int> _vector;

public:
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
	int shortestSpan(void);
	int longestSpan(void);
};

#endif
