/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_pf_putchar(t_pf *pf, char c)
{
	(void)!write(pf->fd, &c, 1);
	pf->len++;
}

void	ft_pf_putstr(t_pf *pf, const char *s, int len)
{
	(void)!write(pf->fd, s, len);
	pf->len += len;
}

void	ft_pf_putnchar(t_pf *pf, char c, int n)
{
	while (n-- > 0)
		ft_pf_putchar(pf, c);
}

void	ft_pf_dispatch(t_pf *pf, va_list ap)
{
	if (pf->spec == 'c')
		ft_pf_char(pf, ap);
	else if (pf->spec == 's')
		ft_pf_str(pf, ap);
	else if (pf->spec == 'p')
		ft_pf_ptr(pf, ap);
	else if (pf->spec == 'd' || pf->spec == 'i')
		ft_pf_int(pf, ap);
	else if (pf->spec == 'u')
		ft_pf_uint(pf, ap);
	else if (pf->spec == 'x' || pf->spec == 'X')
		ft_pf_hex(pf, ap);
	else if (pf->spec == '%')
		ft_pf_pct(pf);
}
