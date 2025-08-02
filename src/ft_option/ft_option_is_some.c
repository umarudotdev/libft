/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_is_some.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Checks if an Option contains a value (is Some).
 *
 * This function tests whether an Option contains a value. It's the primary way
 * to determine if an Option has a value before attempting to extract it.
 *
 * @param option The Option to check
 * @return `true` if the Option is Some, `false` if it's None
 */
bool	ft_option_is_some(t_option option)
{
	return (option._is_some);
}
