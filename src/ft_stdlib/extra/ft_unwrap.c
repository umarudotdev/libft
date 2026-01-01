/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unwrap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/**
 * @brief Returns the pointer if not `NULL`, panics otherwise.
 *
 * This function returns the pointer if it is not `NULL`. If the pointer is
 * `NULL`, it calls `ft_panic` to terminate the program. This should only be
 * used when you are certain the pointer is not `NULL`, or when a panic is
 * acceptable.
 *
 * @param ptr The pointer to unwrap.
 * @return The pointer if it is not `NULL`.
 * @note This function will panic if the pointer is `NULL`.
 */
void	*ft_unwrap(void *ptr)
{
	if (!ptr)
		ft_panic("called `ft_unwrap` on a NULL pointer");
	return (ptr);
}
