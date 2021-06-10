#include "pipex.h"

void	msg_error(char *cmd, int e)
{
	write(2, "Pipex: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, ": ", 2);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	if (e == 1)
		exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc < 5)
	{
		write(2, "Please Insert at least 4 arguments\n", 35);
		exit(0);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		msg_error(argv[1], 1);
	fd2 = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd2 == -1)
		msg_error(argv[argc - 1], 1);
	dup2(fd2, 1);
	dup2(fd1, 0);
	ft_fork_pipes(argc - 3, argv + 2, envp);
	return (0);
}
