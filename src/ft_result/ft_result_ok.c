/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Creates a Result in the Ok state with the given value.
 *
 * This function constructs a successful Result that contains a value. The value
 * can be any pointer type, including `NULL` for functions that don't return
 * meaningful values but can still fail.
 *
 * @param value The value to wrap in a successful Result
 * @return A Result in the Ok state containing the value
 */
t_result	ft_result_ok(const void *value)
{
	return ((t_result){
		._is_ok = true,
		._ok_value = value,
	});
}
