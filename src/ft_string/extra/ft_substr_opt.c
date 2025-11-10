/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"

/**
 * @brief Extracts a substring, returning an Option.
 *
 * This is a safe wrapper around ft_substr that returns an Option type
 * for better error handling.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return A Some(substring) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_substr_opt("hello world", 0, 5);
 *   char *sub = ft_option_unwrap_or(opt, "");
 */
t_option	ft_substr_opt(char const *s, unsigned int start, size_t len)
{
	return (ft_option_from_ptr(ft_substr(s, start, len)));
}
