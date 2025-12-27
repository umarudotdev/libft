/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <stdint.h>

static int	ft_pf_ptrlen(uintptr_t n);
static void	ft_pf_putptr(t_pf *pf, uintptr_t n, int len);
static void	ft_pf_ptr_null(t_pf *pf);
static void	ft_pf_ptr_core(t_pf *pf, uintptr_t n, int len);

void	ft_pf_ptr(t_pf *pf, va_list ap)
{
	void		*ptr;
	uintptr_t	n;
	int			len;

	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		ft_pf_ptr_null(pf);
		return ;
	}
	n = (uintptr_t)ptr;
	len = ft_pf_ptrlen(n);
	ft_pf_ptr_core(pf, n, len);
}

static void	ft_pf_ptr_null(t_pf *pf)
{
	int	pad;

	pad = pf->width - 5;
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS))
		ft_pf_putnchar(pf, ' ', pad);
	ft_pf_putstr(pf, "(nil)", 5);
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}

static void	ft_pf_ptr_core(t_pf *pf, uintptr_t n, int len)
{
	int	pad;

	pad = pf->width - len - 2;
	if (pad < 0)
		pad = 0;
	if (!(pf->flags & PF_FLAG_MINUS))
		ft_pf_putnchar(pf, ' ', pad);
	ft_pf_putstr(pf, "0x", 2);
	ft_pf_putptr(pf, n, len);
	if (pf->flags & PF_FLAG_MINUS)
		ft_pf_putnchar(pf, ' ', pad);
}

static int	ft_pf_ptrlen(uintptr_t n)
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

static void	ft_pf_putptr(t_pf *pf, uintptr_t n, int len)
{
	char		buf[20];
	int			i;
	const char	*base;

	base = "0123456789abcdef";
	i = len;
	buf[i] = '\0';
	while (i > 0)
	{
		buf[--i] = base[n % 16];
		n /= 16;
	}
	ft_pf_putstr(pf, buf, len);
}
