/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:38:33 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/19 17:40:07 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;
	char	c1;

	c1 = (char)c;
	len = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	while (len != 0 && *ptr != c1)
	{
		ptr--;
		len--;
	}
	if (*ptr == c1)
		return (ptr);
	return (0);
}
