/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_is_ok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Checks if a Result is in the Ok state.
 *
 * This function tests whether a Result contains a successful value. It's the
 * primary way to determine if an operation succeeded before attempting to
 * extract the value.
 *
 * @param result The Result to check
 * @return `true` if the Result is Ok, `false` if it's Err
 */
bool	ft_result_is_ok(t_result result)
{
	return (result._is_ok);
}
