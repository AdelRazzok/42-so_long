/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:20:37 by arazzok           #+#    #+#             */
/*   Updated: 2023/05/07 13:20:38 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, (s + i), 1);
		i++;
	}
	write (fd, "\n", 1);
}