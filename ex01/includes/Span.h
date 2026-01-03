/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:18:10 by nluchini          #+#    #+#             */
/*   Updated: 2026/01/03 20:53:21 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H
#define __SPAN_H

#include <exception>
#include <iostream>
#include <vector>
#include <initializer_list>

class Span
{
private:
	const unsigned int	_capacity;
	std::vector<int> _data;

public:
	Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	
	Span(unsigned int n);
	Span(std::initializer_list<int> init);

	void addNumber(int number);
	
	template <typename T>
	void addNumber(T it, T end)
	{

		auto count = std::distance(it, end);
		if (count < 0 || _data.size() + static_cast<size_t>(count) > _capacity)
		{
			throw SpanOverflowException();
		}
		
		for(; it != end; ++it)
		{
			_data.push_back(*it);
		}
	}

	int shortestSpan() const;
	int longestSpan() const;


	class SpanOnelementException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Span contains one or no elements";
		};
	};

	class SpanOverflowException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Span capacity overflow";
		};
	};
};

#endif