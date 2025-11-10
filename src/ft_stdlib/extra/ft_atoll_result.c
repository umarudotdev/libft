/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_result.h"
#include "ft_stdlib.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

#define BASE 10

static long long	*create_llong(long long value);
static t_result		check_overflow(unsigned long long res, int sign, char next);

/**
 * @brief Parses a long long from string, returning a Result.
 *
 * This is a safer version of ft_atoll that returns a Result type for
 * better error handling with overflow detection.
 *
 * @param nptr The string to parse.
 * @return Ok(long long*) on success, Err(error_msg) on failure.
 *
 * @example
 *   t_result res = ft_atoll_result("9223372036854775807");
 *   long long *num = ft_result_expect(res, "parse failed");
 */
t_result	ft_atoll_result(const char *nptr)
{
	unsigned long long	res;
	int					sign;
	size_t				i;
	t_result			overflow_check;

	if (!nptr)
		return (ft_result_err("NULL pointer"));
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		sign = (nptr[i++] == '-') ? -1 : 1;
	if (!ft_isdigit(nptr[i]))
		return (ft_result_err("No digits found"));
	res = 0;
	while (ft_isdigit(nptr[i]))
	{
		overflow_check = check_overflow(res, sign, nptr[i]);
		if (ft_result_is_err(overflow_check))
			return (overflow_check);
		res = res * BASE + (nptr[i++] - '0');
	}
	return (ft_result_ok(create_llong(sign == 1 ? res : -res)));
}

static long long	*create_llong(long long value)
{
	long long	*result;

	result = malloc(sizeof(long long));
	if (!result)
		return (NULL);
	*result = value;
	return (result);
}

static t_result	check_overflow(unsigned long long res, int sign, char next)
{
	unsigned long long	max_val;
	unsigned long long	next_digit;

	next_digit = next - '0';
	if (sign == 1)
		max_val = LLONG_MAX;
	else
		max_val = -(unsigned long long)LLONG_MIN;
	if (res > max_val / BASE)
		return (ft_result_err("Integer overflow"));
	if (res == max_val / BASE && next_digit > max_val % BASE)
		return (ft_result_err("Integer overflow"));
	return (ft_result_ok(NULL));
}
