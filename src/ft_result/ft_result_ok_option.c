/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_ok_or.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_result.h"

/**
 * @brief Converts a Result to an Option, discarding error information.
 *
 * This function transforms a Result into an Option by converting Ok(value) to
 * Some(value) and Err(_) to None. This is useful when you only care about
 * whether an operation succeeded, not the specific error.
 *
 * @param result The Result to convert
 * @return Some(value) if Result is Ok, None if Result is Err
 */
t_option	ft_result_ok_option(t_result result)
{
	if (result._is_ok)
		return (ft_option_some(result._ok_value));
	return (ft_option_none());
}
