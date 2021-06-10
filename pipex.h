#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

char	**ft_split_normal(char *s, char c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *dst, char *src);
char	*get_path(char **envp, char *cmd);
int		ft_fork_pipes (int n, char **av, char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);

#endif