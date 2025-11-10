/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_opt.c                                   :+:      :+:    :+:   */
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
 * @brief Joins two strings, returning an Option.
 *
 * This is a safe wrapper around ft_strjoin that returns an Option type
 * for better error handling.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return A Some(joined_string) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_strjoin_opt("hello", " world");
 *   char *result = ft_option_expect(opt, "join failed");
 */
t_option	ft_strjoin_opt(char const *s1, char const *s2)
{
	return (ft_option_from_ptr(ft_strjoin(s1, s2)));
}
