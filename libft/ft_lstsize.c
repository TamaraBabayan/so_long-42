/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:29:08 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/21 16:34:52 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		len;

	len = 0;
	node = lst;
	while (node != NULL)
	{
		node = node -> next;
		len++;
	}
	return (len);
}
