/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rundata.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:54:16 by marcosv2          #+#    #+#             */
/*   Updated: 2024/09/27 23:01:40 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rungit.hpp"

rundata::~rundata() {
	ft_freetab(this->arguments);
}

rundata::rundata(char** enviroment, std::string path, std::string message) {
	this->arguments = (char**)calloc(5, sizeof(char*));
	this->arguments[0] = strdup("rungit");
	this->enviroment = enviroment;
	this->path = path;
	this->message = message;
	this->ret = 0;
};

void rundata::execute(std::string command, char** arguments) {
	(void)command;
	std::cout << "Executing " << arguments[1] << std::endl;
	int	pid = fork();
	if (pid == 0) {
		// execve("/bin/echo", arguments, this->enviroment);
		execve(command.c_str(), (char * const*)arguments, this->enviroment);
		std::cout << "Could't run " << command << "." << std::endl;
		ft_freetab(arguments);
		exit (1);
	}
	wait(&this->ret);
	if (WEXITSTATUS(this->ret) != 0)
		exit (WEXITSTATUS(this->ret));
};

void rundata::add(void) {
	this->arguments[1] = strdup("add");
	this->arguments[2] = strdup(this->path.c_str());
	this->execute(GIT, arguments);
	ft_nfreestr(&this->arguments[1]);
	ft_nfreestr(&this->arguments[2]);
};

void rundata::commit(void) {
	this->arguments[1] = strdup("commit");
	this->arguments[2] = strdup("-m");
	this->arguments[3] = strdup(this->message.c_str());
	std::cout << "Commiting " << arguments[1] << " " << arguments[2] << " " << arguments[3] << std::endl;
	this->execute(GIT, this->arguments);
	ft_nfreestr(&this->arguments[1]);
	ft_nfreestr(&this->arguments[2]);
	ft_nfreestr(&this->arguments[3]);
};

void rundata::push(void) {
	this->arguments[1] = strdup("push");
	this->execute(GIT, this->arguments);
	ft_nfreestr(&this->arguments[1]);
};

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