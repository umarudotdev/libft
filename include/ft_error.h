/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <stddef.h>

/**
 * @brief Error categories for libft errors
 */
typedef enum e_error_kind
{
	FT_ERR_NONE = 0,
	FT_ERR_INVALID_INPUT,
	FT_ERR_NULL_POINTER,
	FT_ERR_OUT_OF_MEMORY,
	FT_ERR_OUT_OF_BOUNDS,
	FT_ERR_OVERFLOW,
	FT_ERR_UNDERFLOW,
	FT_ERR_PARSE_ERROR,
	FT_ERR_NOT_FOUND,
	FT_ERR_ALREADY_EXISTS,
	FT_ERR_IO_ERROR,
	FT_ERR_INVALID_STATE,
	FT_ERR_UNKNOWN
}	t_error_kind;

/**
 * @brief Detailed error information structure
 */
typedef struct s_error
{
	t_error_kind	kind;
	const char		*message;
	const char		*context;
	const char		*file;
	int				line;
	int				code;
}	t_error;

t_error		ft_error_new(t_error_kind kind, const char *message);
t_error		ft_error_with_context(t_error_kind kind, const char *message,
				const char *context);
t_error		ft_error_with_location(t_error_kind kind, const char *message,
				const char *file, int line);
const char	*ft_error_message(const t_error *error);
const char	*ft_error_kind_str(t_error_kind kind);
void		ft_error_print(const t_error *error);
void		ft_error_print_fd(const t_error *error, int fd);

# define FT_ERROR(kind, msg) \
	ft_error_with_location(kind, msg, __FILE__, __LINE__)

# define FT_ERROR_NULL(context) \
	ft_error_with_context(FT_ERR_NULL_POINTER, \
		"Null pointer dereference", context)

# define FT_ERROR_NOMEM(context) \
	ft_error_with_context(FT_ERR_OUT_OF_MEMORY, \
		"Memory allocation failed", context)

# define FT_ERROR_BOUNDS(index, size) \
	ft_error_with_context(FT_ERR_OUT_OF_BOUNDS, \
		"Index out of bounds", "")

# define FT_ERROR_OVERFLOW(context) \
	ft_error_with_context(FT_ERR_OVERFLOW, \
		"Arithmetic overflow", context)

# define FT_ERROR_PARSE(details) \
	ft_error_with_context(FT_ERR_PARSE_ERROR, \
		"Parse error", details)

#endif
