/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddcontent_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:33:17 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/22 22:57:30 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"
#include <stdlib.h>

/**
 * @brief Adds a new node with `content` at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param content The content to create the new node with.
 * @return The new node. NULL if the allocation fails.
 */
t_list	*ft_lstaddcontent_front(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (NULL);
	ft_lstadd_front(lst, new);
	return (new);
}
