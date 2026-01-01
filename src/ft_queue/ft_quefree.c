/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quefree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:54:55 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_queue_int.h"

static void	que_lstclear(t_queue *que, void (*del)(void *));

/**
 * @brief Deletes and frees the queue and its elements using the function `del`.
 *
 * @param que A pointer to the queue to be freed.
 * @param del The function to delete the content of each node.
 */
void	ft_quefree(t_queue *que, void (*del)(void *))
{
	if (!que)
		return ;
	que_lstclear(que, del);
	ft_free(que->allocator, que);
}

static void	que_lstclear(t_queue *que, void (*del)(void *))
{
	t_list	*tmp;

	while (que->front)
	{
		tmp = que->front;
		que->front = que->front->next;
		if (del)
			del(tmp->content);
		ft_free(que->allocator, tmp);
	}
}
