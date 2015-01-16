// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/16 00:28:21 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 01:34:04 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "mutantstack.cpp"

int main()
{
	{
		MutantStack<int> mstack;

		std::cout << "\033[33m====== WORK ON MutantStack<int> ======\033[0m" << std::endl;
		std::cout << "\033[32mPushing values 5, 17, 2, 90\033[0m" << std::endl;

		mstack.push(5);
		mstack.push(17);
		mstack.push(2);
		mstack.push(90);

		std::cout << "Top = " << mstack.top() << std::endl;
		std::cout << "Size = " << mstack.size() << std::endl;

		std::cout << "\033[31mPOP !\033[0m" << std::endl;
		mstack.pop();
		std::cout << "\033[32mPushing values 3, 5, 737, 89\033[0m" << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(89);

		std::cout << "Top = " << mstack.top() << std::endl;
		std::cout << "Size = " << mstack.size() << std::endl;

		std::cout << "\033[33mNow we iterate from begin to end\033[0m" << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{

	}

	return 0;
}
