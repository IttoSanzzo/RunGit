/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rungit.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/19 20:32:25 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/19 21:19:02 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int	main(int ac, char *av[], char *ep[])
{
	int		ret;
	int		pid;
	char	*commit;

	commit = NULL;
	if (ac > 2)
	{
		ft_printc(C_RED, "Too much arguments!\n");
		return (10);
	}
	else if (ac == 1)
	{
		ft_printc(C_PURPLE, "Insert a commit comment...\n");
		commit = ft_readline("Commit..: ");
	}
	else
		commit = ft_strdup(av[1]);

	char **args;

	args = (char **)ft_calloc(5, sizeof(char *));
	args[0] = ft_strdup("rungit");
	args[1] = ft_strdup("add");
	args[2] = ft_strdup(".");
	pid = fork ();
	if (pid == 0)
	{
		execve("/usr/bin/git", args, ep);
		free(commit);
		ft_freetab(args);
		return (1);
	}
	wait(&ret);
	if (ret != 0)
	{
		free(commit);
		return (1);
	}
	ft_nfreestr(&args[1]);
	ft_nfreestr(&args[2]);

	args[1] = ft_strdup("commit");
	args[2] = ft_strdup("-m");
	args[3] = ft_strdup(commit);
	free(commit);
	pid = fork();
	if (pid == 0)
	{
		execve("/usr/bin/git", args, ep);
		ft_freetab(args);
		return (2);
	}
	wait(&ret);
	if (ret != 0)
		return (2);
	ft_nfreestr(&args[1]);
	ft_nfreestr(&args[2]);
	ft_nfreestr(&args[3]);

	args[1] = ft_strdup("push");
	pid = fork();
	if (pid == 0)
	{
		execve("/usr/bin/git", args, ep);
		ft_freetab(args);
		return (3);
	}
	wait(&ret);
	if (ret != 0)
		return (3);
	ft_nfreestr(&args[1]);
	ft_nfreetab(&args);
	
	ft_printc(C_GREEN, "DONE!\n");
	return (0);
}
