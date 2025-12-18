/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:46:09 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/18 17:43:41 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANSTACK_H
#define __MUTANSTACK_H

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T, std::deque<T>>()
	{
	}

	MutantStack(const MutantStack& other) : std::stack<T, std::deque<T>>(other)
	{
	}
	
	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T, std::deque<T> >::operator=(other);
		return *this;
	}
	
	~MutantStack() {};

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef
		typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}

	const_iterator end() const
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}

	reverse_iterator rend()
	{
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}
};


#endif