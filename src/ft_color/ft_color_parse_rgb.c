/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_parse_rgb.c                              :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:49:18 by martins           #+#    #+#             */
/*   Updated: 2024/12/15 18:22:29 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include "ft_ctype.h"
#include "ft_option.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stdint.h>

static const char	*skip_spaces(const char *str);
static const char	*parse_channel(const char *str, int *value);
static const char	*parse_rgba_values(const char *str, int *rgba, int *count);
static int			get_prefix_len(const char *str, bool *has_alpha);

/**
 * @brief Parses an RGB(A) color string (R,G,B / rgb(R,G,B) / rgba(R,G,B,A)).
 *
 * @param str The string to parse.
 * @return A `t_option` containing the parsed color, or none if parsing failed.
 */
t_option	ft_color_parse_rgb(const char *str)
{
	int		rgba[COLOR_RGBA_CHANNEL_COUNT];
	int		prefix_len;
	int		count;
	bool	has_alpha;
	t_color	color;

	if (str == NULL)
		return (ft_option_none());
	str = skip_spaces(str);
	prefix_len = get_prefix_len(str, &has_alpha);
	str = parse_rgba_values(str + prefix_len, rgba, &count);
	if (str == NULL)
		return (ft_option_none());
	if (prefix_len > 0 && *str++ != ')')
		return (ft_option_none());
	if (*skip_spaces(str) != '\0')
		return (ft_option_none());
	if (count == 4)
		color = ft_color_rgba(rgba[0], rgba[1], rgba[2], rgba[3]);
	else
		color = ft_color_rgb(rgba[0], rgba[1], rgba[2]);
	return (ft_option_some((void *)(uintptr_t)color.value));
}

static const char	*skip_spaces(const char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}

static const char	*parse_channel(const char *str, int *value)
{
	str = skip_spaces(str);
	if (!ft_isdigit(*str))
		return (NULL);
	*value = 0;
	while (ft_isdigit(*str))
	{
		*value = *value * 10 + (*str - '0');
		if (*value > 255)
			return (NULL);
		str++;
	}
	return (skip_spaces(str));
}

static const char	*parse_rgba_values(const char *str, int *rgba, int *count)
{
	str = parse_channel(str, &rgba[0]);
	if (str == NULL || *str != ',')
		return (NULL);
	str = parse_channel(str + 1, &rgba[1]);
	if (str == NULL || *str != ',')
		return (NULL);
	str = parse_channel(str + 1, &rgba[2]);
	if (str == NULL)
		return (NULL);
	*count = 3;
	if (*str == ',')
	{
		str = parse_channel(str + 1, &rgba[3]);
		if (str != NULL)
			*count = 4;
	}
	return (str);
}

static int	get_prefix_len(const char *str, bool *has_alpha)
{
	if (ft_strncmp(str, "rgba(", 5) == 0)
	{
		*has_alpha = true;
		return (5);
	}
	if (ft_strncmp(str, "rgb(", 4) == 0)
	{
		*has_alpha = false;
		return (4);
	}
	*has_alpha = false;
	return (0);
}
