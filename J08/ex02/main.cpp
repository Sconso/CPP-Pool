// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/16 00:28:21 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/16 02:36:31 by Myrkskog         ###   ########.fr       //
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

		std::cout << "\033[33mNow we iterate from end to begin\033[0m" << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		while (ite != it)
		{
			--ite;
			std::cout << *ite << std::endl;
		}
	}

	std::cout << std::endl;
// ************************************************************************** //

	{
		MutantStack<std::string> mstack;

		std::cout << "\033[33m====== WORK ON MutantStack<std::string> ======\033[0m" << std::endl;
		std::cout << "\033[32mPushing values \"Hey\", \"how\", \"are\" , \"you?\"\033[0m" << std::endl;

		mstack.push("Hey");
		mstack.push("how");
		mstack.push("are");
		mstack.push("you?");

		std::cout << "Top = " << mstack.top() << std::endl;
		std::cout << "Size = " << mstack.size() << std::endl;

		std::cout << "\033[31mPOP !\033[0m" << std::endl;
		mstack.pop();
		std::cout << "\033[32mPushing values \"the\", \"flying\", \"pink\", \"unicorns?\"\033[0m" << std::endl;

		mstack.push("the");
		mstack.push("flying");
		mstack.push("pink");
		mstack.push("unicorns?");

		std::cout << "Top = " << mstack.top() << std::endl;
		std::cout << "Size = " << mstack.size() << std::endl;

		std::cout << std::endl << "\033[33mNow we iterate from begin to end\033[0m" << std::endl;

		{
			MutantStack<std::string>::iterator it = mstack.begin();
			MutantStack<std::string>::iterator ite = mstack.end();

			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}

		std::cout << std::endl << "\033[33mWhat about a copy in mscopy ?\033[0m" << std::endl;
		MutantStack<std::string> mscopy(mstack);

		std::cout << "mscopy Top = " << mscopy.top() << std::endl;
		std::cout << "mscopy Size = " << mscopy.size() << std::endl;

		MutantStack<std::string>::iterator it = mscopy.begin();
		MutantStack<std::string>::iterator ite = mscopy.end();

		std::cout << "\033[33mmscopy: \033[0m" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << std::endl << "\033[32mOk, it seems to be good. What if we modify mstack ?\033[0m" << std::endl;
		std::cout << "\033[31mPOP !\033[0m" << std::endl;
		std::cout << "\033[31mPOP !\033[0m" << std::endl;
		std::cout << "\033[31mPOP !\033[0m" << std::endl;
		mstack.pop();
		mstack.pop();
		mstack.pop();

		std::cout << "\033[32mPushing values \"green\", \"mouses?\"\033[0m" << std::endl;
		mstack.push("green");
		mstack.push("mouses?");

		std::cout << "mstack Top = " << mstack.top() << std::endl;
		std::cout << "mstack Size = " << mstack.size() << std::endl;
		std::cout << "mscopy Top = " << mscopy.top() << std::endl;
		std::cout << "mscopy Size = " << mscopy.size() << std::endl;

		it = mstack.begin();
		ite = mstack.end();

		std::cout << std::endl <<  "\033[33mmstack: \033[0m" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		it = mscopy.begin();
		ite = mscopy.end();

		std::cout << std::endl << "\033[33mmscopy: \033[0m" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << std::endl << "\033[33mLet's be serious and copy that in a real stack:\033[0m" << std::endl;
		std::stack<std::string> s(mstack);

		std::cout << "stack Top = " << s.top() << std::endl;
		std::cout << "stack Size = " << s.size() << std::endl;

		std::cout << "\033[31mSTACK POP !\033[0m" << std::endl;
		std::cout << "\033[32mInsert \"Elephant\" in stack\033[0m" << std::endl;
		std::cout << "\033[32mInsert \"with\", \"beer\" in mstack\033[0m" << std::endl << std::endl;
		s.pop();
		s.push("Elephant");
		mstack.push("with");
		mstack.push("beer");

		std::cout << "mstack Top = " << mstack.top() << std::endl;
		std::cout << "mstack Size = " << mstack.size() << std::endl;
		std::cout << "stack Top = " << s.top() << std::endl;
		std::cout << "stack Size = " << s.size() << std::endl;

		it = mstack.begin();
		ite = mstack.end();

		std::cout << std::endl <<  "\033[33mmstack: \033[0m" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return (0);
}
