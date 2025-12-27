/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	parse_flags(const char **fmt, t_pf *pf);
static void	parse_width(const char **fmt, t_pf *pf);
static void	parse_precision(const char **fmt, t_pf *pf);

void	ft_pf_init(t_pf *pf, int fd)
{
	pf->fd = fd;
	pf->len = 0;
	pf->width = 0;
	pf->prec = -1;
	pf->flags = 0;
	pf->spec = 0;
}

int	ft_pf_parse(const char **fmt, t_pf *pf)
{
	pf->width = 0;
	pf->prec = -1;
	pf->flags = 0;
	pf->spec = 0;
	(*fmt)++;
	parse_flags(fmt, pf);
	parse_width(fmt, pf);
	parse_precision(fmt, pf);
	if (**fmt)
		pf->spec = *(*fmt)++;
	return (pf->spec != 0);
}

static void	parse_flags(const char **fmt, t_pf *pf)
{
	while (**fmt)
	{
		if (**fmt == '-')
			pf->flags |= PF_FLAG_MINUS;
		else if (**fmt == '0')
			pf->flags |= PF_FLAG_ZERO;
		else if (**fmt == '#')
			pf->flags |= PF_FLAG_HASH;
		else if (**fmt == ' ')
			pf->flags |= PF_FLAG_SPACE;
		else if (**fmt == '+')
			pf->flags |= PF_FLAG_PLUS;
		else
			break ;
		(*fmt)++;
	}
}

static void	parse_width(const char **fmt, t_pf *pf)
{
	while (**fmt >= '0' && **fmt <= '9')
	{
		pf->width = pf->width * 10 + (**fmt - '0');
		(*fmt)++;
	}
}

static void	parse_precision(const char **fmt, t_pf *pf)
{
	if (**fmt != '.')
		return ;
	(*fmt)++;
	pf->prec = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		pf->prec = pf->prec * 10 + (**fmt - '0');
		(*fmt)++;
	}
}
