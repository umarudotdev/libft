/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnrstrip_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:51:35 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:41 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_internal.h"
#include <stddef.h>

/**
 * @brief Strips the binary-safe string `s` from the left side of the characters
 * that satisfy the function `f`.
 *
 * @param s The string to be stripped.
 * @param f The function to check the characters.
 * @return The stripped string.
 */
t_string	ft_stnrstrip_if(t_string s, int (*f)(int))
{
	size_t	len;

	len = ft_stnlen(s);
	while (len > 0 && f(s[len - 1]))
		len--;
	s[len] = '\0';
	ft_stnsetlen(s, len);
	return (s);
}
