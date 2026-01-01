/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 02:44:32 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"
#include "ft_stack.h"
#include "ft_stack_int.h"
#include <stdbool.h>

/**
 * @brief Pushes an element to the stack.
 *
 * @param stk A pointer to the stack to push to.
 * @param content The element to push.
 * @return `true` if the push was successful. `false` otherwise.
 */
bool	ft_stkpush(t_stack *stk, void *content)
{
	t_list	*node;

	node = ft_lstnew_allocator(stk->allocator, content);
	if (!node)
		return (false);
	ft_lstadd_front(&stk->top, node);
	stk->size++;
	return (true);
}
