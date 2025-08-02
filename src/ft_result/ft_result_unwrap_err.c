/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_unwrap_err.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_result.h"
#include "ft_stdlib.h"

/**
 * @brief Extracts the error value from an Err Result, panics if Ok.
 *
 * This function returns the contained Err value. If the Result is Ok, it calls
 * `ft_panic` to terminate the program. This is useful for extracting error
 * information when you know the operation failed.
 *
 * @param result The Result to unwrap the error from
 * @return The contained Err value
 * @note This function will panic if the Result is Ok
 */
void	*ft_result_unwrap_err(t_result result)
{
	if (result._is_ok)
		ft_panic("called `ft_result_unwrap_err` on an Ok value");
	return ((void *)result._err_value);
}
