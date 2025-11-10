/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrat_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_option.h"

/**
 * @brief Gets an element at index, returning an Option.
 *
 * This is a safe wrapper around ft_arrat that returns an Option type
 * for better bounds checking and error handling.
 *
 * @param arr The array to access.
 * @param index The index of the element.
 * @return A Some(element_ptr) if index is valid, None if out of bounds.
 *
 * @example
 *   t_option opt = ft_arrat_opt(arr, 5);
 *   int *value = ft_option_unwrap_or(opt, &default_value);
 */
t_option	ft_arrat_opt(const t_array *arr, size_t index)
{
	if (!arr || index >= ft_arrsize(arr))
		return (ft_option_none());
	return (ft_option_from_ptr(ft_arrat(arr, index)));
}
