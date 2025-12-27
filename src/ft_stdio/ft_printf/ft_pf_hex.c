/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_pf_hexlen(unsigned long n);
static void	ft_pf_puthex(t_pf *pf, unsigned long n, int len, const char *base);
static void	ft_pf_hex_prefix(t_pf *pf);
static void	ft_pf_hex_core(t_pf *pf, unsigned int n, int len, const char *base);

void	ft_pf_hex(t_pf *pf, va_list ap)
{
	unsigned int	n;
	int				len;
	const char		*base;

	n = va_arg(ap, unsigned int);
	if (pf->spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = ft_pf_hexlen(n);
	if (pf->prec == 0 && n == 0)
		len = 0;
	ft_pf_hex_core(pf, n, len, base);
}

static void	ft_pf_hex_core(t_pf *pf, unsigned int n, int len, const char *base)
{
	int	zeros;
	int	pad;
	int	prefix;

	prefix = 0;
	if ((pf->flags & PF_FLAG_HASH) && n != 0)
		prefix = 2;
	zeros = pf->prec - len;
	if (zeros < 0)
		zeros = 0;
	pad = pf->width - len - zeros - prefix;
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS) && !(pf->flags & PF_FLAG_ZERO))
		ft_pf_putnchar(pf, ' ', pad);
	if (prefix)
		ft_pf_hex_prefix(pf);
	if (!(pf->flags & PF_FLAG_MINUS) && (pf->flags & PF_FLAG_ZERO)
		&& pf->prec < 0)
		ft_pf_putnchar(pf, '0', pad);
	ft_pf_putnchar(pf, '0', zeros);
	ft_pf_puthex(pf, n, len, base);
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}

static void	ft_pf_hex_prefix(t_pf *pf)
{
	if (pf->spec == 'X')
		ft_pf_putstr(pf, "0X", 2);
	else
		ft_pf_putstr(pf, "0x", 2);
}

static int	ft_pf_hexlen(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_pf_puthex(t_pf *pf, unsigned long n, int len, const char *base)
{
	char	buf[16];
	int		i;

	if (len == 0)
		return ;
	i = len;
	buf[i] = '\0';
	while (i > 0)
	{
		buf[--i] = base[n % 16];
		n /= 16;
	}
	ft_pf_putstr(pf, buf, len);
}
