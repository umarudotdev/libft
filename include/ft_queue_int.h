/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:33:04 by martins           #+#    #+#             */
/*   Updated: 2024/09/14 20:02:40 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_INT_H
# define FT_QUEUE_INT_H

# include "ft_allocator.h"
# include "ft_linkedlist.h"
# include <stddef.h>

struct			s_queue
{
	t_list		*front;
	t_list		*back;
	size_t		size;
	t_allocator	allocator;
};

#endif
