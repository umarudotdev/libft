/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/08/02 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESULT_H
# define FT_RESULT_H

# include <stdbool.h>

typedef struct s_option	t_option;

typedef struct s_result
{
	bool				_is_ok;
	union
	{
		const void		*_ok_value;
		const void		*_err_value;
	};
}						t_result;

t_result				ft_result_ok(const void *value);
t_result				ft_result_err(const void *error);
bool					ft_result_is_ok(t_result result);
bool					ft_result_is_err(t_result result);
t_result				ft_result_and_then(t_result result,
							t_result (*f)(const void *));
t_result				ft_result_map(t_result result,
							const void *(*f)(const void *));
t_result				ft_result_map_err(t_result result,
							const void *(*f)(const void *));
t_option				ft_result_ok_option(t_result result);
t_result				ft_result_or_else(t_result result,
							t_result (*f)(const void *));
void					*ft_result_expect(t_result result, const char *message);
void					*ft_result_unwrap(t_result result);
void					*ft_result_unwrap_or(t_result result,
							const void *default_value);
void					*ft_result_unwrap_err(t_result result);
t_result				ft_result_from_ptr(const void *ptr);

#endif
