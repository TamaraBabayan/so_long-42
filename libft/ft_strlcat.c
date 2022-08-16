/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:16:46 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/12 18:16:46 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	srclen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	finsize;
	char	*d1;
	char	*s1;

	d1 = dst;
	s1 = (char *)src;
	finsize = dstsize;
	while (finsize-- != 0 && *d1 != '\0')
		d1++;
	dlen = d1 - dst;
	finsize = dstsize - dlen;
	if (finsize == 0)
		return (dlen + srclen(src));
	while (*src != '\0')
	{
		if (finsize > 1)
		{
			*d1++ = *src;
			finsize--;
		}
		src++;
	}
	*d1 = '\0';
	return (dlen + (src - s1));
}
