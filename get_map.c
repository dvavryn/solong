#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	printmap(char **map);
char **get_map(char *argv1);
size_t	get_linecount(char *s);

int main(int argc, char **argv)
{
	char **map;
	map = get_map(argv[1]);
	// printmap(map);
}

void	printmap(char **map)
{
	int i = 0;
	int j = 0;
	char *x[] = {"gello", "world", "i", "am", NULL};
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

char **get_map(char *argv1)
{
	char **out;
	int	i;

	i = get_linecount(argv1);
	out = malloc(i * sizeof(char *));
	if (!out)
		return (NULL);
	
	int fd;
	fd = open(argv1, O_RDONLY);

	i = 1;
	out[0] = get_next_line(fd);
	while (out[i] != NULL)
	{
		out[i] = get_next_line(fd);
		printf("%s", out[i]);
		i++;
	}
	return (out);
}

size_t	get_linecount(char *s)
{
	size_t out;

	out = 1;
	int fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		exit(1);
	char buf[1024];
	ft_bzero(buf, sizeof(buf));
	int k;

	out = 1;
	while (read(fd, buf, sizeof(buf)) > 0)
	{
		int j;
		j = 1;
		while(buf[j - 1])
		{
			if (buf[j] == '\n' && buf[j + 1])
				out++;
			j++;
		}
		ft_bzero(buf, sizeof(buf));
	}
	printf("%li lines\n", out);
	return (out);
}
