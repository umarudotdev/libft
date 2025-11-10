/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martins <martins@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by martins           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by martins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

/**
 * @brief Returns the error message.
 *
 * @param error Pointer to the error structure
 * @return The error message, or "Unknown error" if error is NULL
 */
const char	*ft_error_message(const t_error *error)
{
	if (!error)
		return ("Unknown error");
	if (error->message)
		return (error->message);
	return (ft_error_kind_str(error->kind));
}
