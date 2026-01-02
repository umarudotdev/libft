/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 03:37:15 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:41 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator.h"
#include "ft_string.h"
#include "ft_string_internal.h"

/**
 * @brief Frees the binary-safe string pointed to by `s`.
 *
 * @param s A pointer to the string to be freed.
 */
void	ft_stnfree(t_string s)
{
	struct s_string_header	*hdr;

	if (!s)
		return ;
	hdr = ft_stnhdr(s);
	ft_free(hdr->allocator, hdr);
}
