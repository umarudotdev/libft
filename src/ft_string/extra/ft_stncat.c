/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stncat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:46:16 by yuuko             #+#    #+#             */
/*   Updated: 2024/04/01 05:58:05 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

/**
 * @brief Appends the characters from the binary-safe string `src` to
 * `dst`.
 *
 * @param dst The string to append to.
 * @param src The string to be appended.
 * @return The destination string. NULL if the allocation fails.
 */
t_string	ft_stncat(t_string dst, const char *src)
{
	return (ft_stncat_size(dst, src, ft_strlen(src)));
}
