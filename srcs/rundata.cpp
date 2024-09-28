/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rundata.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:54:16 by marcosv2          #+#    #+#             */
/*   Updated: 2024/09/27 22:02:30 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rungit.hpp"

rundata::~rundata() {
	std::cout << "DESTRUCTED!\n";
}

rundata::rundata(char** enviroment, std::string path, std::string message) {
	std::cout << "CONSTRUCTING\n";
	this->enviroment = enviroment;
	this->path = path;
	this->message = message;
	this->ret = 0;
	std::cout << "CONSTRUCTED!\n";
};

void rundata::execute(std::string command, const char**arguments) {
	int	pid = fork();
	if (pid == 0) {
		execve(command.c_str(), (char * const*)arguments, this->enviroment);
		exit (1);
	}
	wait(&this->ret);
	if (this->ret != 0)
		exit (this->ret);
};

void rundata::add(void) {
	const char* arguments[]= {"add", this->path.c_str()};
	this->execute(GIT, arguments);
};

void rundata::commit(void) {
	const char* arguments[]= {"commit", this->message.c_str()};
	this->execute(GIT, arguments);
};

void rundata::push(void) {
	const char* arguments[]= {"push"};
	this->execute(GIT, arguments);
};