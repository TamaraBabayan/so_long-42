/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:18:44 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/26 17:14:16 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;

	i = 0;
	c1 = c;
	if (!s)
		return (0);
	while (s[i] && s[i] != c1)
		i++;
	if (s[i] == c1)
		return ((char *)&s[i]);
	return (NULL);
}
