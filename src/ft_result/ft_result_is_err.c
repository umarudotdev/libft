/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_is_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"

/**
 * @brief Checks if a Result is in the Err state.
 *
 * This function tests whether a Result contains an error value. It's useful for
 * error handling and control flow decisions.
 *
 * @param result The Result to check
 * @return `true` if the Result is Err, `false` if it's Ok
 */
bool	ft_result_is_err(t_result result)
{
	return (!result._is_ok);
}
