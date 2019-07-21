#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	signal_handler(int	signal)
{
	if (signal == SIGINT)
	{
		printf("receive sigint");
		exit(0);
	}
}

int		main(int ac, char **argv, char **env)
{
	char	*tmp;
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		printf("sig erorr");
	pid_t	pid;
	pid = fork();
	if (pid == 0)
	{
		printf("this is the fork\n");
		execve("/bin/ls", argv, env);
	}
	while (1)
	{
		printf("sleeping\n");
		printf("current wkdir = %s\n", getcwd(tmp, 80));
		sleep(1);
	}
	return (0);
}
