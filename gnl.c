#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



int ft_check_line(char *dest)
{
	int i;

	i = 0;
	if (!dest)
		return (0);
	while(dest[i] && dest[i] != '\n')
		i++;
	if (dest[i] == '\n')
		return (1);
	return (0);
}

int ft_strlen_line(char *dest)
{
	int i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i] && dest[i] != '\n')
		i++;
	return (i);
}

int ft_strlen(char *dest)
{
	int i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i])
		i++;
	return (i);
}

char *ft_join_line(char *src, char *buff)
{
	int i;
	int j;
	char *dest;

	i = 0;
	j = 0;
	if (!src)
		dest = malloc(sizeof(char) * ft_strlen_line(buff) + 2);
	else
	{
		dest = malloc(sizeof(char) * (ft_strlen_line(buff) + ft_strlen(src) + 2));
		while (src[i])
		{
			dest[i] = src[i];
			i++;		
		}
		free (src);
	}
	while (buff[j] && buff[j] != '\n')
	{
		dest[i] = buff[j];
		i++;
		j++;
	}
	dest[i] = '\n';
	if (buff[j] == '\n')
		i++;
	dest[i] = '\0';
	if (dest[0] == '\0')
	{
		free(dest);
		return(NULL);
	}
	return (dest);
}

void ft_cut_line(char *dst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	while (dst[i])
	{
		dst[j] = dst[i];
		i++;
		j++;
	}
	dst[j] = '\0';
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	int i;
	char *dest;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (ft_check_line(buff) == 1)
	{
		ft_cut_line(buff);
		dest = ft_join_line(dest, buff);
	}
	while (i > 0 && ft_check_line(buff) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return (dest);
		buff[i] = '\0';
		dest = ft_join_line(dest, buff);
	}
	return (dest);
}

int main()
{
	int i;
	
	char *src;
	i = open("test.txt", O_RDONLY);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	src = get_next_line(i);
	printf("%s", src);
	if (src)
		free(src);
	
}
