/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:22:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/18 17:40:35 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.h"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	
	++rit;
	--rit;
	
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::stack<int> s(mstack);
	return 0;
}