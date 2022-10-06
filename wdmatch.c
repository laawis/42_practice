/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:51:23 by gaollier          #+#    #+#             */
/*   Updated: 2022/10/03 12:04:29 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *s)
{
	int	k;

	k = 0;
	while (s[k])
		k++;
	return (k);
}

void	ft_wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
		{
			i++;
		}
		j++;
	}
	if (ft_len(s1) == i)
		write(1, s1, i);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}	
