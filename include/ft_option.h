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

typedef struct s_option	t_option;

t_option				ft_option_none(void);
t_option				ft_option_some(void *value);
bool					ft_option_is_none(t_option option);
bool					ft_option_is_some(t_option option);
void					*ft_option_unwrap(t_option option);
void					*ft_option_unwrap_or(t_option option,
							void *default_value);
t_option				ft_option_map(t_option option, void *(*f)(void *));
t_option				ft_option_and_then(t_option option,
							t_option (*f)(void *));
t_result				ft_option_ok_or(t_option option, void *error);
t_result				ft_option_ok_or_else(t_option option, void *(*f)(void));
t_option				ft_option_filter(t_option option,
							bool (*predicate)(void *));
void					*ft_option_expect(t_option option, const char *message);
t_option				ft_option_from_ptr(void *ptr);

#endif
