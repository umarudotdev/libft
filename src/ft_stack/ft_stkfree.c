/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:07:03 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_stack_int.h"

static void	stk_lstclear(t_stack *stk, void (*del)(void *));

/**
 * @brief Deletes and frees the stack and its elements using the function `del`.
 *
 * @param stk A pointer to the stack to be freed.
 * @param del The function to delete the content of each node.
 */
void	ft_stkfree(t_stack *stk, void (*del)(void *))
{
	if (!stk)
		return ;
	stk_lstclear(stk, del);
	ft_free(stk->allocator, stk);
}

static void	stk_lstclear(t_stack *stk, void (*del)(void *))
{
	t_list	*tmp;

	while (stk->top)
	{
		tmp = stk->top;
		stk->top = stk->top->next;
		if (del)
			del(tmp->content);
		ft_free(stk->allocator, tmp);
	}
}
