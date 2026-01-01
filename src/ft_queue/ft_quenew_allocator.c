/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quenew_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_queue_internal.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new queue using the given allocator.
 *
 * @param alloc The allocator to use.
 * @return The new queue.
 */
t_queue	*ft_quenew_allocator(t_allocator a)
{
	t_queue	*que;

	que = ft_alloc(a, sizeof(t_queue));
	if (!que)
		return (NULL);
	que->front = NULL;
	que->back = NULL;
	que->size = 0;
	que->allocator = a;
	return (que);
}
