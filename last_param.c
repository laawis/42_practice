/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:33:46 by gaollier          #+#    #+#             */
/*   Updated: 2022/10/03 14:15:55 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 1)
	{
		while (av[(ac - 1)][i] != '\0')
		{
			write(1, &av[(ac - 1)][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}	
