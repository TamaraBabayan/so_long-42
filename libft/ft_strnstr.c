/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:06 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/16 15:53:27 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*start;
	char	*sub;
	size_t	l1;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len != 0)
	{
		start = (char *)haystack;
		sub = (char *)needle;
		l1 = len;
		while (*haystack && *sub && *haystack == *sub && l1 != 0)
		{
			haystack++;
			sub++;
			l1--;
		}
		if (*sub == '\0')
			return (start);
		haystack = start + 1;
		len--;
	}
	return (NULL);
}
