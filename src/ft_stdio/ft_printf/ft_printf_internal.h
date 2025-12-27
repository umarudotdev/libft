/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@umaru.dev>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2024/12/27 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# define PF_FLAG_MINUS 0x01
# define PF_FLAG_ZERO 0x02
# define PF_FLAG_HASH 0x04
# define PF_FLAG_SPACE 0x08
# define PF_FLAG_PLUS 0x10

typedef struct s_pf
{
	int		fd;
	int		len;
	int		width;
	int		prec;
	char	flags;
	char	spec;
}			t_pf;

void		ft_pf_init(t_pf *pf, int fd);
int			ft_pf_parse(const char **fmt, t_pf *pf);
void		ft_pf_dispatch(t_pf *pf, va_list ap);
void		ft_pf_putchar(t_pf *pf, char c);
void		ft_pf_putstr(t_pf *pf, const char *s, int len);
void		ft_pf_putnchar(t_pf *pf, char c, int n);
void		ft_pf_char(t_pf *pf, va_list ap);
void		ft_pf_str(t_pf *pf, va_list ap);
void		ft_pf_int(t_pf *pf, va_list ap);
void		ft_pf_uint(t_pf *pf, va_list ap);
void		ft_pf_hex(t_pf *pf, va_list ap);
void		ft_pf_ptr(t_pf *pf, va_list ap);
void		ft_pf_pct(t_pf *pf);

#endif
