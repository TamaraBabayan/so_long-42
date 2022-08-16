/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:58:46 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/19 17:27:34 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d1;
	unsigned char	*s1;

	d1 = dst;
	s1 = (unsigned char *)src;
	if (d1 > s1)
	{
		while (len)
		{
			*(d1 + len - 1) = *(s1 + len - 1);
			len--;
		}
	}
	else
	{
		while (len)
		{
			*d1 = *s1;
			d1++;
			s1++;
			len--;
		}
	}
	return (dst);
}
