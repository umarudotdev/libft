/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Returns None if the option is None, otherwise calls `predicate` with
 * the wrapped value and returns.
 *
 * This function applies a filter to an Option. If the Option is Some and the
 * predicate returns `true` for the contained value, it returns the original
 * Option. Otherwise, it returns None. This is useful for conditional
 * processing.
 *
 * @param option The Option to filter
 * @param predicate The predicate function to test the value
 * (must not be `NULL`)
 * @return The original Option if Some and `predicate` is `true`, None otherwise
 */
t_option	ft_option_filter(t_option option, bool (*predicate)(const void *))
{
	if (!predicate)
		return (ft_option_none());
	if (option._is_some && predicate(option._value))
		return (option);
	return (ft_option_none());
}
