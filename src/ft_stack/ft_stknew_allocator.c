/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknew_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/31 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_stack_internal.h"
#include <stddef.h>

/**
 * @brief Allocates and returns a new stack using the given allocator.
 *
 * @param alloc The allocator to use.
 * @return The new stack.
 */
t_stack	*ft_stknew_allocator(t_allocator a)
{
	t_stack	*stk;

	stk = ft_alloc(a, sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->top = NULL;
	stk->size = 0;
	stk->allocator = a;
	return (stk);
}
