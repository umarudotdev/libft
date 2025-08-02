/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_ok_or.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_result.h"

/**
 * @brief Transforms an Option<T> into a Result<T, E>.
 *
 * This function converts an Option to a Result. If the Option is Some(value),
 * it becomes Ok(value). If the Option is None, it becomes Err(error).
 * This allows bridging between Option and Result types.
 *
 * @param option The Option to convert
 * @param error The error value to use if Option is None
 * @return Ok(value) if Option is Some, Err(error) if Option is None
 */
t_result	ft_option_ok_or(t_option option, const void *error)
{
	if (option._is_some)
		return (ft_result_ok(option._value));
	return (ft_result_err(error));
}
