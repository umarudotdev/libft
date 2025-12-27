/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:49:18 by martins           #+#    #+#             */
/*   Updated: 2024/12/15 18:22:29 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include "ft_option.h"
#include "ft_stdio.h"
#include <stdbool.h>
#include <unistd.h>

/**
 * @brief TODO: Parses a color from a string.
 *
 * @param str The string to parse.
 * @return A `t_option` containing the parsed color, or none if parsing failed.
 */
t_option	ft_color_parse_hex(const char *str __attribute__((unused)))
{
	ft_putstr_fd((char *)__func__, STDERR_FILENO);
	ft_putendl_fd(" is not implemented yet", STDERR_FILENO);
	return (ft_option_none());
}
