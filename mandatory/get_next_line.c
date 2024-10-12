#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && s2 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str && str[i])
		i++;
	return i;
}

char *strdup_new_map(char *str, t_info *info)
{
	int i;
	char *s1;
	
	s1 = ft_malloc(info->tmp + 2, info); // error
	i = 0;
	while (i < info->tmp)
	{
		s1[i] = ' ';
		i++;
	}
	i = 0;
	while(i < info->tmp)
	{
		if (ft_strlen(str) - 1 > i)
			s1[i] = str[i];
		i++;
	}
	s1[i++] = '\n';
	s1[i] = '\0';
	return s1;
}

int ft_strlen2(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

char *ft_strdup(char *str, t_info *info)
{
	if (!str)
		return (NULL);
	int i = ft_strlen(str);
	char *s1 = ft_malloc(i + 1, info);
	i = 0;
	while(str[i])
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return s1;
}

char *ft_strchr(char *str, char c)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (&str[i]);
		i++;
	}
	return NULL;
}
char *ft_strjoin(char *s1, char *s2, t_info *info)
{
	int i = ft_strlen(s1) + ft_strlen(s2);
	char *s3 = ft_malloc(i + 1, info);
	int j = 0;
	i = 0;
	while(s1 && s1[i])
	{
		s3[j] = s1[i];
		i++;
		j++;
	} 
	i = 0;
	while(s2[i])
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	 s3[j] = '\0';
	 return s3;
}

void ft_strcpy(char *s1 ,char *s2)
{
	int i =0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	 s1[i] = '\0';
}

char *get_next_line(int fd, t_info *info)
{
	static char buf[BUFFER_SIZE +1];
	char *newline;
	char *line;
	int l;
	line = ft_strdup(buf, info);
	while(!(newline = ft_strchr(line , '\n')) && (l = read(fd,buf, BUFFER_SIZE)))
	{
		buf[l] = '\0';
		line = ft_strjoin(line , buf, info);
	}
	if (ft_strlen(line) == 0)
		return(NULL);
	if(newline)
	{
		ft_strcpy(buf,newline + 1);
		*(newline + 1) = '\0';
	}
	else
		buf[0] = '\0';
	return line;
}
