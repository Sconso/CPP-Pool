// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 19:27:25 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 00:25:53 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"
#include <ctime>

int main(void)
{
	{
		Span sp = Span(5);

		try {
			sp.shortestSpan();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(42);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "Min: " << sp.shortestSpan() << std::endl;
		std::cout << "Max: " << sp.longestSpan() << std::endl;
	}

	Span tab(100000);

	try {
		tab.addRange(tab.begin(), tab.end() + 500);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;

	}
	std::cout << "Min span = " << tab.shortestSpan() << std::endl;
	std::cout << "Max span = " << tab.longestSpan() << std::endl;


	return 0;
}
