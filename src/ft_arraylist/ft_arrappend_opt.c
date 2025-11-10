/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrappend_opt.c                                 :+:      :+:    :+:   */
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
 * @brief Appends an element to the array, returning an Option.
 *
 * This is a safe wrapper around ft_arrappend that returns an Option type
 * for better error handling.
 *
 * @param arr A pointer to the array to add the element to.
 * @param new The element to be added to the array.
 * @return A Some(element_ptr) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_arrappend_opt(arr, &value);
 *   if (ft_option_is_none(opt))
 *       handle_error();
 */
t_option	ft_arrappend_opt(t_array *arr, const void *new)
{
	return (ft_option_from_ptr(ft_arrappend(arr, new)));
}
