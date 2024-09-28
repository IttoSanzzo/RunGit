/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rungit.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:13:34 by marcosv2          #+#    #+#             */
/*   Updated: 2024/09/27 22:54:17 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rungit.hpp"
int	main(int ac, char **av, char **ev) {
// 0. Checks for argument count
	if (ac < 2) {
		std::cout << "Missing Commit Message! Use:\n\trungit <commit message>" << std::endl;
		return (-1);
	} else if (ac > 2) {
		std::cout << "Too many arguments! Use:\n\trungit <commit message>" << std::endl;
		return (-2);
	}
	rundata dataAdd = rundata(ev, ".", av[1]);
	dataAdd.add();
	dataAdd.commit();
	// dataAdd.push();
}