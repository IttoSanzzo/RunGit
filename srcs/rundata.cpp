/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rundata.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:54:16 by marcosv2          #+#    #+#             */
/*   Updated: 2024/09/27 23:09:51 by marcosv2         ###   ########.fr       */
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
	int	pid = fork();
	if (pid == 0) {
		execve(command.c_str(), (char * const*)arguments, this->enviroment);
		std::cout << COLOR_RED << "Could't run " << command << "." << COLOR_DEFAULT << std::endl;
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
	std::cout << COLOR_CIAN << "Files Added..." << COLOR_DEFAULT << std::endl;
};

void rundata::commit(void) {
	this->arguments[1] = strdup("commit");
	this->arguments[2] = strdup("-m");
	this->arguments[3] = strdup(this->message.c_str());
	this->execute(GIT, this->arguments);
	ft_nfreestr(&this->arguments[1]);
	ft_nfreestr(&this->arguments[2]);
	ft_nfreestr(&this->arguments[3]);
	std::cout << COLOR_LGREEN << "Commited..." << COLOR_DEFAULT << std::endl;
};

void rundata::push(void) {
	this->arguments[1] = strdup("push");
	this->execute(GIT, this->arguments);
	ft_nfreestr(&this->arguments[1]);
	std::cout << COLOR_GREEN << "Pushed!" << COLOR_DEFAULT << std::endl;
};