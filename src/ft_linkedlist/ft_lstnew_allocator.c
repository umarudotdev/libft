/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new node using the given allocator.
 *
 * The variable `content` is initialized with the value of the parameter
 * `content`. The variable `next` is initialized to NULL.
 *
 * @param alloc The allocator to use.
 * @param content The content to create the new node with.
 * @return The new node.
 */
t_list	*ft_lstnew_allocator(t_allocator a, void *content)
{
	t_list	*node;

	node = ft_alloc(a, sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
