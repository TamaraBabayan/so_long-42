/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:30:15 by tbabayan          #+#    #+#             */
/*   Updated: 2022/04/22 17:46:43 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	n;

	a = 0;
	n = 1;
	while (is(*str, "\t\n\v\f\r "))
		str++;
	if (*str == '-')
	{
		n = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a *= 10;
		a += *str - 48;
		str++;
	}
	return (n * a);
}
