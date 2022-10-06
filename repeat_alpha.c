/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:11:57 by gaollier          #+#    #+#             */
/*   Updated: 2022/10/04 16:16:07 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	count1;
	int	count2;

		
	i = 0;
	while (str[i])
	{
		count1 = str[i] - 96;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			while (count1 > 0)
			{
				write(1, &str[i], 1);
				count1--;
			}
		}
		count2 = str[i] - 64; 	
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			while (count2 > 0)
			{
				write(1, &str[i], 1);
				count2--;
			}
		}
		i++;
	}

}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
