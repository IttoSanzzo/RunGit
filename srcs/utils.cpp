/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:03:10 by marcosv2          #+#    #+#             */
/*   Updated: 2024/09/27 23:12:46 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rungit.hpp"

void	ft_nfreestr(char** str) {
	if (*str != NULL) {
		free(*str);
		*str = NULL;
	}
}

void	ft_freetab(char** tab) {
	if (tab == NULL)
		return;
	int	i = -1;
	while (tab[++i]) {
		free(tab[i]);
	}
	free(tab);
}