/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnhdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:37:35 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:41 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_internal.h"

/**
 * @brief Returns the header of the binary-safe string `s`.
 *
 * @param s The string to be checked.
 * @return The header of the string.
 */
struct s_string_header	*ft_stnhdr(const t_string s)
{
	return ((struct s_string_header *)(s - sizeof(struct s_string_header)));
}
