/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_opt.c                                   :+:      :+:    :+:   */
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
 * @brief Trims characters from string, returning an Option.
 *
 * This is a safe wrapper around ft_strtrim that returns an Option type
 * for better error handling.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return A Some(trimmed_string) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_strtrim_opt("  hello  ", " ");
 *   char *trimmed = ft_option_unwrap_or(opt, "");
 */
t_option	ft_strtrim_opt(char const *s1, char const *set)
{
	return (ft_option_from_ptr(ft_strtrim(s1, set)));
}
