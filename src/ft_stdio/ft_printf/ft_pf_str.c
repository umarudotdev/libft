/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_pf_slen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_pf_str(t_pf *pf, va_list ap)
{
	const char	*s;
	int			len;
	int			pad;

	s = va_arg(ap, const char *);
	if (!s)
		s = "(null)";
	len = ft_pf_slen(s);
	if (pf->prec >= 0 && pf->prec < len)
		len = pf->prec;
	pad = pf->width - len;
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS))
		ft_pf_putnchar(pf, ' ', pad);
	ft_pf_putstr(pf, s, len);
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}
