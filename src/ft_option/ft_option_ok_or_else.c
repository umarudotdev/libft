/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_or_else.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option_int.h"
#include "ft_result_int.h"

/**
 * @brief Returns the option if it contains a value, otherwise calls f and
 * returns the result.
 *
 * This function provides a way to recover from None values by computing
 * an alternative Option. It's useful for providing fallback behavior
 * when an operation doesn't produce a value.
 *
 * @param option The Option to check
 * @param f The function to call if Option is None (must not be NULL)
 * @return The original Option if Some, or the result of f() if None
 */
t_result	ft_option_ok_or_else(t_option option, void *(*f)(void))
{
	if (!f)
		return (ft_result_err("null function pointer"));
	if (option.is_some)
		return (ft_result_ok(option.value));
	return (ft_result_err(f()));
}
