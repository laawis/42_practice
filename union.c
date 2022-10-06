/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:38:42 by gaollier          #+#    #+#             */
/*   Updated: 2022/10/03 12:00:38 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	is_in_string(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*k;
	char	s3[_strlen(s1) + _strlen(s2) + 1];

	k = ft_strcat(s1, s2);
	i = 0;
	j = 0;
	while (k[i] != '\0')
	{
		if (!(is_in_string(k[i], s3)))
		{
			s3[j] = k[i];
			j++;
		}
		i++;
	}
	write(1, &s3, j);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
