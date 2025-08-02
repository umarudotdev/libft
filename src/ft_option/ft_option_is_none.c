/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_is_none.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Checks if an Option contains no value (is None).
 *
 * This function tests whether an Option is empty. It's useful for control flow
 * and validation logic.
 *
 * @param option The Option to check
 * @return `true` if the Option is None, `false` if it's Some
 */
bool	ft_option_is_none(t_option option)
{
	return (!option._is_some);
}
