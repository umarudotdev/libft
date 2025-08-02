/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_H
# define FT_OPTION_H

# include <stdbool.h>

typedef struct s_result	t_result;

typedef struct s_option
{
	bool				_is_some;
	const void			*_value;
}						t_option;

t_option				ft_option_none(void);
t_option				ft_option_some(const void *value);
bool					ft_option_is_none(t_option option);
bool					ft_option_is_some(t_option option);
t_option				ft_option_and_then(t_option option,
							t_option (*f)(const void *));
t_option				ft_option_map(t_option option,
							const void *(*f)(const void *));
t_option				ft_option_filter(t_option option,
							bool (*predicate)(const void *));
t_result				ft_option_ok_or(t_option option, const void *error);
void					*ft_option_expect(t_option option, const char *message);
void					*ft_option_unwrap(t_option option);
void					*ft_option_unwrap_or(t_option option,
							const void *default_value);
t_option				ft_option_from_ptr(const void *ptr);

#endif
