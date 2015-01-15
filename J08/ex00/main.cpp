// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 17:28:11 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/15 17:41:16 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "easyfind.hpp"


int main(void)
{
	std::vector<int> v;
	std::list<int> l;

	std::cout << "====== VECTOR CONTAINER ======" << std::endl;

	std::cout << "\033[32mvector.push_back(26);\033[0m" << std::endl;
	std::cout << "\033[32mvector.push_back(67);\033[0m" << std::endl;
	std::cout << "\033[32mvector.push_back(42);\033[0m" << std::endl;
	std::cout << "\033[32mvector.push_back(9);\033[0m" << std::endl;
	std::cout << "\033[32mvector.push_back(76);\033[0m" << std::endl << std::endl;

	v.push_back(26);
	v.push_back(67);
	v.push_back(42);
	v.push_back(9);
	v.push_back(76);

	try{
		std::cout << "\033[33mLet's find 42:\033[0m" << std::endl;
		if (easyfind(v, 42))
			std::cout << "\033[32m42 found !\033[0m" << std::endl;

		std::cout << "\033[33mLet's find 24:\033[0m" << std::endl;
		if (easyfind(v, 24))
			std::cout << "\033[32m24 found !\033[0m" << std::endl;
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "====== LIST CONTAINER ======" << std::endl;

	std::cout << "\033[32mlist.push_back(76);\033[0m" << std::endl;
	std::cout << "\033[32mlist.push_back(24);\033[0m" << std::endl;
	std::cout << "\033[32mlist.push_back(46);\033[0m" << std::endl;
	std::cout << "\033[32mlist.push_back(1);\033[0m" << std::endl;
	std::cout << "\033[32mlist.push_back(62);\033[0m" << std::endl << std::endl;

	l.push_back(76);
	l.push_back(24);
	l.push_back(46);
	l.push_back(1);
	l.push_back(62);

	try{
		std::cout << "\033[33mLet's find 24:\033[0m" << std::endl;
		if (easyfind(l, 24))
			std::cout << "\033[32m24 found !\033[0m" << std::endl;

		std::cout << "\033[33mLet's find 42:\033[0m" << std::endl;
		if (easyfind(l, 42))
			std::cout << "\033[32m42 found !\033[0m" << std::endl;
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
