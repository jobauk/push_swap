/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:41:24 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 14:47:45 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstpush(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (*lst && new)
		(*lst)->next = new;
	return (new);
}

// Should I do `del(content)` on failure knowing that 'content'
// might still be owned by the old list and thus invalidating it?
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tail;
	t_list	*new_lst;
	void	*content;

	tail = NULL;
	new_lst = NULL;
	while (lst && f)
	{
		content = f(lst->content);
		tail = ft_lstpush(&tail, content);
		if (!tail)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (!new_lst)
			new_lst = tail;
		lst = lst->next;
	}
	return (new_lst);
}
