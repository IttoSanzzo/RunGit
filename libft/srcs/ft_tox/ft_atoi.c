/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:46:46 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:46:47 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		total;
	int		signal;

	total = 0;
	signal = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if ((*nptr == '-' || *nptr == '+') && *nptr++ == '-')
		signal *= -1;
	while (*nptr >= '0' && *nptr <= '9')
		total = total * 10 + (*nptr++ - '0');
	return (total * signal);
}
