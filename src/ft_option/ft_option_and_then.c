/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_and_then.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Returns None if the option is None, otherwise calls `f` with the
 * wrapped value and returns the result.
 *
 * This function enables monadic chaining of operations that return Options.
 * It's useful for composing multiple operations that might fail, allowing for
 * clean error propagation without nested conditionals.
 *
 * @param option The Option to chain from
 * @param f The function to apply if Option is Some (must not be `NULL`)
 * @return The result of f(value) if Some, None if None or `f` is `NULL`
 */
t_option	ft_option_and_then(t_option option, t_option (*f)(const void *))
{
	if (!f)
		return (ft_option_none());
	if (option._is_some)
		return (f(option._value));
	return (ft_option_none());
}
