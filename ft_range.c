/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:11:16 by gaollier          #+#    #+#             */
/*   Updated: 2022/10/06 14:33:20 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	*tab;
	int	j;

	i = end - start;
	if (i < 0)
		i = -i;
	if (i = 0)
		return (0);
	tab = malloc(sizeof(*tab) * (i + 1));
	if(!tab)
		return (NULL);
	j = 0;
	while (i >= 0)
	{
		tab[j] = start;
		j++;
		i--;
		start++;
	}
	return (tab);
}
