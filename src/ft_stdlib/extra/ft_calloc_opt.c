/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_stdlib.h"

/**
 * @brief Allocates and zeros memory, returning an Option.
 *
 * This is a safe wrapper around ft_calloc that returns an Option type
 * for better error handling.
 *
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return A Some(pointer) if successful, None if allocation fails or overflow.
 *
 * @example
 *   t_option opt = ft_calloc_opt(10, sizeof(int));
 *   int *arr = ft_option_expect(opt, "allocation failed");
 */
t_option	ft_calloc_opt(size_t nmemb, size_t size)
{
	return (ft_option_from_ptr(ft_calloc(nmemb, size)));
}
