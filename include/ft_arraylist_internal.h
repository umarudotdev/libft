/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist_int.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:07:28 by martins           #+#    #+#             */
/*   Updated: 2024/11/16 16:01:29 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAYLIST_INTERNAL_H
# define FT_ARRAYLIST_INTERNAL_H

# include "ft_allocator.h"
# include <stddef.h>

# define ARRAY_DEFAULT_CAPACITY 16
# define ARRAY_GROWTH_FACTOR 2

struct			s_array
{
	void		*elements;
	size_t		element_size;
	size_t		size;
	size_t		capacity;
	t_allocator	allocator;
};

#endif
