/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_kind_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

/**
 * @brief Returns a human-readable string for the error kind.
 *
 * @param kind The error category
 * @return A constant string describing the error category
 */
const char	*ft_error_kind_str(t_error_kind kind)
{
	if (kind == FT_ERR_NONE)
		return ("No error");
	if (kind == FT_ERR_INVALID_INPUT)
		return ("Invalid input");
	if (kind == FT_ERR_NULL_POINTER)
		return ("Null pointer");
	if (kind == FT_ERR_OUT_OF_MEMORY)
		return ("Out of memory");
	if (kind == FT_ERR_OUT_OF_BOUNDS)
		return ("Out of bounds");
	if (kind == FT_ERR_OVERFLOW)
		return ("Overflow");
	if (kind == FT_ERR_UNDERFLOW)
		return ("Underflow");
	if (kind == FT_ERR_PARSE_ERROR)
		return ("Parse error");
	if (kind == FT_ERR_NOT_FOUND)
		return ("Not found");
	if (kind == FT_ERR_ALREADY_EXISTS)
		return ("Already exists");
	if (kind == FT_ERR_IO_ERROR)
		return ("I/O error");
	if (kind == FT_ERR_INVALID_STATE)
		return ("Invalid state");
	return ("Unknown error");
}
