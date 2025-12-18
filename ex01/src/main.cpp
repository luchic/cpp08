/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:22:35 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/18 15:42:45 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.h"

#include <random>

void print_span(const Span& sp)
{
	static unsigned int calls;

	std::cout << "======== Print span: " << calls << " =============" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	calls++;
}

static void randomSpanAndPrint(unsigned int n, unsigned int seed,
                               int minValue = -1000000, int maxValue = 1000000)
{
    Span sp(n);

    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (unsigned int i = 0; i < n; ++i)
        sp.addNumber(dist(rng));

    print_span(sp);
}

int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
		
	print_span(sp);

	Span sp1 = Span({3, 1, 4, 5, 73, 32, 2, 45, 2, 6});
	print_span(sp);
	
	randomSpanAndPrint(1000, 0xFFAFDEF);
	randomSpanAndPrint(10000, 0xF0AF7EF);
	randomSpanAndPrint(1000, 0x8FAFDEF);
	randomSpanAndPrint(10000, 0xF0AF4EF);
	randomSpanAndPrint(1000, 0x12AFDEF);
	randomSpanAndPrint(10000, 0xF0AF7EF);
	randomSpanAndPrint(1000, 0x23AAAEF);
	randomSpanAndPrint(10000, 0xF0AF1EF);

	return 0;
}