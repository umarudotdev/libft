/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_pf_nbrlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_pf_putnbr(t_pf *pf, long n, int len)
{
	char	buf[20];
	int		i;

	if (len == 0)
		return ;
	i = len;
	buf[i] = '\0';
	while (i > 0)
	{
		buf[--i] = (n % 10) + '0';
		n /= 10;
	}
	ft_pf_putstr(pf, buf, len);
}

static void	ft_pf_int_out(t_pf *pf, long n, int len, char sign)
{
	int	zeros;
	int	pad;

	zeros = pf->prec - len;
	if (zeros < 0)
		zeros = 0;
	pad = pf->width - len - zeros - (sign != 0);
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS) && !(pf->flags & PF_FLAG_ZERO))
		ft_pf_putnchar(pf, ' ', pad);
	if (sign)
		ft_pf_putchar(pf, sign);
	if (!(pf->flags & PF_FLAG_MINUS) && (pf->flags & PF_FLAG_ZERO)
		&& pf->prec < 0)
		ft_pf_putnchar(pf, '0', pad);
	ft_pf_putnchar(pf, '0', zeros);
	ft_pf_putnbr(pf, n, len);
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}

void	ft_pf_int(t_pf *pf, va_list ap)
{
	long	n;
	int		len;
	char	sign;

	n = va_arg(ap, int);
	sign = 0;
	if (n < 0)
		sign = '-';
	else if (pf->flags & PF_FLAG_PLUS)
		sign = '+';
	else if (pf->flags & PF_FLAG_SPACE)
		sign = ' ';
	if (n < 0)
		n = -n;
	len = ft_pf_nbrlen(n);
	if (pf->prec == 0 && n == 0)
		len = 0;
	ft_pf_int_out(pf, n, len, sign);
}
