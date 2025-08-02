/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_from_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

/**
 * @brief Creates an Option from a nullable pointer.
 *
 * This function converts a traditional C pointer that may be `NULL`
 * into an Option type. If the pointer is non-`NULL`, it creates a Some Option.
 * If the pointer is `NULL`, it creates a None Option.
 *
 * @param ptr The pointer to convert to an Option
 * @return Some(ptr) if `ptr` is non-`NULL`, None if `ptr` is `NULL`
 */
t_option	ft_option_from_ptr(const void *ptr)
{
	if (ptr)
		return (ft_option_some(ptr));
	return (ft_option_none());
}
