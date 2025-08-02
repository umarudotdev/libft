/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_from_ptr.c                               :+:      :+:    :+:   */
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
 * @brief Creates a Result from a nullable pointer.
 *
 * This function converts a traditional C pointer that may be `NULL`
 * into a Result type. If the pointer is non-`NULL`, it creates an Ok Result.
 * If the pointer is `NULL`, it creates an Err Result with a generic message.
 *
 * @param ptr The pointer to convert to a Result
 * @return Ok(ptr) if ptr is non-`NULL`, Err(`NULL`) if ptr is `NULL`
 */
t_result	ft_result_from_ptr(const void *ptr)
{
	if (ptr)
		return (ft_result_ok(ptr));
	return (ft_result_err(NULL));
}
