/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:09:57 by tbabayan          #+#    #+#             */
/*   Updated: 2022/04/22 18:03:08 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	func(long int n, int len, char *str)
{
	while (n)
	{
		str[len - 1] = n % 10 + 48;
		len--;
		n /= 10;
	}
}

int	len_of_n(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			lenght;
	long int	a;

	a = n;
	lenght = len_of_n(a);
	str = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	str[lenght] = '\0';
	if (a == 0)
		str[0] = '0';
	if (a < 0)
	{
		str[0] = '-';
		a = -a;
	}
	func(a, lenght, str);
	return (str);
}
