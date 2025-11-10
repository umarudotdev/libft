/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_error.h"
#include "ft_result.h"
#include "ft_stdlib.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

#define BASE 10

static int	*create_int(int value);

/**
 * @brief Parses an integer from string, returning a Result.
 *
 * This is a safer version of ft_atoi that returns a Result type for
 * better error handling. It detects:
 * - NULL pointer
 * - Empty string or no digits
 * - Overflow (value > INT_MAX or < INT_MIN)
 *
 * @param nptr The string to parse.
 * @return Ok(int*) on success, Err(error_msg) on failure.
 *
 * @example
 *   t_result res = ft_atoi_result("123");
 *   if (ft_result_is_ok(res)) {
 *       int *num = ft_result_unwrap(res);
 *       printf("%d\n", *num);
 *       free(num);
 *   }
 */
t_result	ft_atoi_result(const char *nptr)
{
	long long	res;
	int			sign;
	size_t		i;

	if (!nptr)
		return (ft_result_err_error(FT_ERROR_NULL("ft_atoi_result")));
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		sign = (nptr[i++] == '-') ? -1 : 1;
	if (!ft_isdigit(nptr[i]))
		return (ft_result_err_error(FT_ERROR_PARSE("No digits found in input")));
	res = 0;
	while (ft_isdigit(nptr[i]))
	{
		res = res * BASE + (nptr[i++] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
			return (ft_result_err_error(FT_ERROR_OVERFLOW("Integer value")));
	}
	return (ft_result_ok(create_int(res * sign)));
}

static int	*create_int(int value)
{
	int	*result;

	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	*result = value;
	return (result);
}
