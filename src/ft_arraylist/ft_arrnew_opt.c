/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_option.h"

/**
 * @brief Creates a new array list, returning an Option.
 *
 * This is a safe wrapper around ft_arrnew that returns an Option type
 * for better error handling.
 *
 * @param size The size of each element in bytes.
 * @return A Some(array) if successful, None if allocation fails.
 *
 * @example
 *   t_option opt = ft_arrnew_opt(sizeof(int));
 *   t_array *arr = ft_option_expect(opt, "failed to create array");
 */
t_option	ft_arrnew_opt(size_t size)
{
	return (ft_option_from_ptr(ft_arrnew(size)));
}
