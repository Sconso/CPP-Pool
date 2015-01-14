// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 15:43:26 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/14 22:10:31 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Array.tpp"

// ************************************************************************** //
//                                 TEST CLASS                                 //
// ************************************************************************** //
class Test {

public:
	Test(void) : _val(0) { }
	Test(int val) : _val(val) { }
	Test(Test const &src) { *this = src; }
	~Test(void) {}

	int getVal(void) const { return (this->_val); }
	Test &operator=(Test const &rhs) { this->_val = rhs._val; return (*this); }
	Test &operator*=(int const rhs) { this->_val *= rhs; return (*this); }
	Test &operator*=(Test const &rhs) { this->_val *= rhs.getVal(); return (*this); }

private:
	int _val;
};

std::ostream &	operator<<(std::ostream &o, Test const &rhs) { return ( o << rhs.getVal() ); }


// ************************************************************************** //
//                                    MAIN                                    //
// ************************************************************************** //
int main(void)
{
	Array<int> iArray(15);
	Array<int> iArray2(7);
	Array<float> fArray(3);
	Array<std::string> sArray(4);
	Array<Test> tArray(5);

	unsigned int i;
	int j;

// ************************************************************************** //
	std::cout << "========= INIT =========" << std::endl;

	iArray.dump("intArray1");
	iArray2.dump("intArray2");
	fArray.dump("floatArray");
	sArray.dump("stringArray");
	tArray.dump("classArray");

// ************************************************************************** //
	std::cout << "========= LET'S DO SOME MANIPS... =========" << std::endl;

// intArray1 affectations
	std::cout << "\033[32m";
	std::cout << "for (i = 0; i < intArray1.size(); i++)" << std::endl;
	std::cout << "    intArray1[i] = i;" << std::endl;
	std::cout << "\033[0m" << std::endl;

	for (i = 0; i < iArray.size(); i++)
		iArray[i] = static_cast<int>(i);
	iArray.dump("intArray1");

// Array copy
	std::cout << "\033[32m";
	std::cout << "int Array 2 = int Array 1: " << std::endl;
	std::cout << "\033[0m" << std::endl;
	iArray2 = iArray;

	iArray.dump("intArray1");
	iArray2.dump("intArray2");

// intArray1 affectation
	std::cout << "\033[32m";
	std::cout << "for (i = 0, j = intArray1.size() - 1; j >= 0; j--, i++)" << std::endl;
	std::cout << "    intArray1[i] = j;" << std::endl;
	std::cout << "\033[0m" << std::endl;

	for (i = 0, j = static_cast<int>(iArray.size()) - 1; j >= 0; j--, i++)
		iArray[i] = j;
	iArray.dump("intArray1");
	iArray2.dump("intArray2");

// floatArray affectation
	std::cout << "\033[32m";
	std::cout << "for (i = 0; i < floatArray.size(); i++)" << std::endl;
	std::cout << "    floatArray1[i] = intArray[i];" << std::endl;
	std::cout << "\033[0m" << std::endl;

	for (i = 0; i < fArray.size(); i++)
		fArray[i] = static_cast<float>(iArray[i]);
	fArray.dump("floarArray");

// stringArray affectation
	std::cout << "\033[32m";
	std::cout << "stringArray[0] = \"Hey !\";" << std::endl;
	std::cout << "stringArray[1] = \"Yo !\";" << std::endl;
	std::cout << "stringArray[2] = \"Wesh !\";" << std::endl;
	std::cout << "stringArray[3] = \"Hello !\";" << std::endl;
	std::cout << "stringArray[4] = \"Zbra !\";" << std::endl;
	std::cout << "\033[0m" << std::endl;

	try {
		sArray[0] = "Hey !";
		sArray[1] = "Yo !";
		sArray[2] = "Wesh !";
		sArray[3] = "Hello !";
		sArray[4] = "Zbra !";
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sArray.dump("stringArray");

// classArray affectation
	std::cout << "\033[32m";
	std::cout << "classArray[-1] = 0;" << std::endl;
	std::cout << "classArray[0] = 5;" << std::endl;
	std::cout << "classArray[1] = 10;" << std::endl;
	std::cout << "classArray[2] = 21;" << std::endl;
	std::cout << "classArray[3] = 42;" << std::endl;
	std::cout << "classArray[4] = 84;" << std::endl;
	std::cout << "\033[0m" << std::endl;

	try {
		tArray[0] = 5;
		tArray[1] = 10;
		tArray[2] = 21;
		tArray[3] = 42;
		tArray[4] = 84;
		tArray[-1] = 0;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	tArray.dump("classArray");

	return (0);
}
