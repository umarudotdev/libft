/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_opt.c                                    :+:      :+:    :+:   */
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
 * @brief Duplicates a string, returning an Option.
 *
 * This is a safe wrapper around ft_strdup that returns an Option type
 * for better error handling.
 *
 * @param s The string to be duplicated.
 * @return A Some(duplicated_string) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_strdup_opt("hello");
 *   char *str = ft_option_expect(opt, "strdup failed");
 */
t_option	ft_strdup_opt(const char *s)
{
	return (ft_option_from_ptr(ft_strdup(s)));
}
