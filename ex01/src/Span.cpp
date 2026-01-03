/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:30:48 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/30 12:09:03 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.h"
#include <iostream>
#include <algorithm>

Span::Span() :
	_capacity(0)
{	
}

Span::Span(unsigned int n) :
	_capacity(n)
{
}

Span::Span(std::initializer_list<int> init) :
	_capacity(static_cast<unsigned int>(init.size())),
	_data(init)
{
}

Span::Span(const Span &other) :
	_capacity(other._capacity)
{
	for (unsigned int i = 0; i < other._data.size(); i++)
	{
		_data[i] = other._data[i];
	}
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		if (_capacity != other._capacity)
		{
			throw std::logic_error(
				"Span: cannot assign spans with different capacity");
		}
		for (unsigned int i = 0; i < other._capacity; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_data.size() >= _capacity)
		throw Span::SpanOverflowException();
	_data.push_back(number);
}

Span::~Span()
{
	
}

int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw Span::SpanOnelementException();

	auto minit = std::min_element(_data.begin(), _data.end());
	auto maxit = std::max_element(_data.begin(), _data.end());
	return *maxit - *minit;
}

int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw Span::SpanOnelementException();
	
	std::vector<int> tmp(_data);
	std::vector<int> diff(_data.size() - 1);
	std::sort(tmp.begin(), tmp.end());

	std::transform(tmp.begin() + 1, tmp.end(),
		tmp.begin(), diff.begin(), std::minus<int>());
	
	auto shortest = std::min_element(diff.begin(), diff.end());
	return *shortest;
}