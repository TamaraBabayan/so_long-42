/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:38 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/19 17:31:34 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*p;

	p = (unsigned char *)s;
	c1 = c;
	while (n != 0)
	{
		if (*p == c1)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
