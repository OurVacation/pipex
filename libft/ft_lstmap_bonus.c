/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:25:48 by taewonki          #+#    #+#             */
/*   Updated: 2025/04/12 15:58:17 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*next_node;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		next_node = ft_lstnew(f(lst->content));
		if (next_node == NULL)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, next_node);
		lst = lst->next;
	}
	return (nlst);
}
