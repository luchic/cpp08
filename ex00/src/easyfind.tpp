/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:11:22 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/12 11:22:57 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.h"
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T *data, T value)
{
	typename T::iterator it = std::find(data->begin(), data->end(), value);
	if (it == data->end())
		throw std::runtime_error("Value not found");
	return it;
}