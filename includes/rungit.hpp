/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rungit.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:47:17 by marcosv2          #+#    #+#             */
/*   Updated: 2024/09/27 23:06:20 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNGIT_HPP
# define RUNGIT_HPP

// 0. External Includes
	#include <iostream>
	#include <unistd.h>
	#include <stdlib.h>
	#include <sys/wait.h>
	#include <cstring>
	#include <string>

// 1. Macros
	#define GIT "/usr/bin/git"
	#define COLOR_DEFAULT "\033[0m"
	#define COLOR_GREEN "\033[38;5;82m"

// 2. Classes
	class rundata {
		private:
			char**		arguments;
			char**		enviroment;
			std::string	path;
			std::string	message;
			int			ret;
		public:
			~rundata();
			rundata(char **enviroment, std::string path, std::string message);
			void	add(void);
			void	commit(void);
			void	push(void);
		private:
			void	execute(std::string command, char**args);
	};

// 3. Functions
void	ft_nfreestr(char** str);
void	ft_freetab(char** tab);

#endif