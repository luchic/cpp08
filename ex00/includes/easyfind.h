/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:04:57 by nluchini          #+#    #+#             */
/*   Updated: 2025/12/12 11:25:13 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

template <typename T, typename U>
typename T::iterator easyfind(T *data, U value);

#include "../src/easyfind.tpp"

#endif