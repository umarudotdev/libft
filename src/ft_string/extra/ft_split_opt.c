/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_opt.c                                     :+:      :+:    :+:   */
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
 * @brief Splits a string by delimiter, returning an Option.
 *
 * This is a safe wrapper around ft_split that returns an Option type
 * for better error handling.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return A Some(array_of_strings) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_split_opt("hello world foo", ' ');
 *   if (ft_option_is_some(opt)) {
 *       char **words = ft_option_unwrap(opt);
 *       // use words
 *       ft_freesplit(words);
 *   }
 */
t_option	ft_split_opt(char const *s, char c)
{
	return (ft_option_from_ptr(ft_split(s, c)));
}
