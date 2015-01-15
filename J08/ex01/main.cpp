// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 19:27:25 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/15 19:50:50 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"
#include <ctime>

int main(void)
{
	Span tab(10);
	srand(time(NULL));

	try {
		for (int i = 0; i < 11; ++i)
			tab.addNumber(rand() % 1111);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	tab.dump();
	std::cout << "Min span = " << tab.shortestSpan() << std::endl;
	std::cout << "Max span = " << tab.longestSpan() << std::endl;
	tab.dump();


	return 0;
}
