// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: Myrkskog <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 17:24:56 by Myrkskog          #+#    #+#             //
//   Updated: 2015/01/15 17:33:15 by Myrkskog         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template< typename T>
bool easyfind(T  &container, int i)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::exception();
	else
		return (true);
}

#endif // EASYFIND_HPP
