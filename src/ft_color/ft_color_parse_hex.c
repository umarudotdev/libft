/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_parse_hex.c                              :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:49:18 by martins           #+#    #+#             */
/*   Updated: 2024/12/15 18:22:29 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include "ft_option.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stdint.h>

static int		hex_digit_value(char c);
static bool		is_valid_hex_string(const char *str, size_t len);
static t_color	parse_hex_short(const char *hex, size_t len);
static t_color	parse_hex_long(const char *hex, size_t len);

/**
 * @brief Parses a hex color string (#RGB, #RGBA, #RRGGBB, or #RRGGBBAA).
 *
 * @param str The string to parse.
 * @return A `t_option` containing the parsed color, or none if parsing failed.
 */
t_option	ft_color_parse_hex(const char *str)
{
	size_t	len;
	t_color	color;

	if (str == NULL)
		return (ft_option_none());
	if (str[0] == '#')
		str++;
	len = ft_strlen(str);
	if (!is_valid_hex_string(str, len))
		return (ft_option_none());
	if (len == 3 || len == 4)
		color = parse_hex_short(str, len);
	else if (len == 6 || len == 8)
		color = parse_hex_long(str, len);
	else
		return (ft_option_none());
	return (ft_option_some((void *)(uintptr_t)color.value));
}

static int	hex_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

static bool	is_valid_hex_string(const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (hex_digit_value(str[i]) < 0)
			return (false);
		i++;
	}
	return (true);
}

static t_color	parse_hex_short(const char *hex, size_t len)
{
	uint8_t	rgba[COLOR_RGBA_CHANNEL_COUNT];

	rgba[0] = hex_digit_value(hex[0]) * 17;
	rgba[1] = hex_digit_value(hex[1]) * 17;
	rgba[2] = hex_digit_value(hex[2]) * 17;
	if (len == 4)
		rgba[3] = hex_digit_value(hex[3]) * 17;
	else
		rgba[3] = UINT8_MAX;
	return (ft_color_rgba(rgba[0], rgba[1], rgba[2], rgba[3]));
}

static t_color	parse_hex_long(const char *hex, size_t len)
{
	uint8_t	rgba[COLOR_RGBA_CHANNEL_COUNT];

	rgba[0] = hex_digit_value(hex[0]) * 16 + hex_digit_value(hex[1]);
	rgba[1] = hex_digit_value(hex[2]) * 16 + hex_digit_value(hex[3]);
	rgba[2] = hex_digit_value(hex[4]) * 16 + hex_digit_value(hex[5]);
	if (len == 8)
		rgba[3] = hex_digit_value(hex[6]) * 16 + hex_digit_value(hex[7]);
	else
		rgba[3] = UINT8_MAX;
	return (ft_color_rgba(rgba[0], rgba[1], rgba[2], rgba[3]));
}
