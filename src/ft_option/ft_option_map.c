/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Maps an Option<T> to Option<U> by applying a function to the contained
 * value.
 *
 * This function transforms the value inside an Option by applying the given
 * function to it. If the Option is None, it remains None. If it's Some(value),
 * it becomes Some(f(value)). This enables functional programming patterns.
 *
 * @param option The Option to map over
 * @param f The function to apply to the contained value (must not be `NULL`)
 * @return A new Option containing the transformed value, or None if input was
 * None
 */
t_option	ft_option_map(t_option option, const void *(*f)(const void *))
{
	if (!f)
		return (ft_option_none());
	if (option._is_some)
		return (ft_option_some(f(option._value)));
	return (ft_option_none());
}
