/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:44:34 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/27 12:18:19 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstring)
		return (NULL);
	if (s1)
		while (s1[j])
			newstring[i++] = s1[j++];
	while (*s2)
	{
		newstring[i++] = *s2;
		s2++;
	}
	newstring[i] = '\0';
	return (newstring);
}
