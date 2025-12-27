/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_pf_char(t_pf *pf, va_list ap)
{
	char	c;
	int		pad;

	c = (char)va_arg(ap, int);
	pad = pf->width - 1;
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS))
		ft_pf_putnchar(pf, ' ', pad);
	ft_pf_putchar(pf, c);
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}

void	ft_pf_pct(t_pf *pf)
{
	int	pad;

	pad = pf->width - 1;
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS))
		ft_pf_putnchar(pf, ' ', pad);
	ft_pf_putchar(pf, '%');
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}
