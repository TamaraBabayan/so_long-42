/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:36:41 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/18 16:09:13 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	str = 0;
	if (!s1 || !set)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	while (s1[len])
		len++;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, len - i + 1);
	return (str);
}
