/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:19:24 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/18 00:02:14 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	free_all(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	found_n(t_list *lst)
{
    int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	while (lst->content[count] != '\0') 
	{
		if (lst->content[count] == '\n')
			return (1);
		count++;
	}
	return(0);
}

void	reset_lst(t_list **lst, int count, int count_2)
{
	t_list	*clean;
	t_list	*last;

	clean = malloc(sizeof(t_list));
	if (!lst || !clean)
	{
		so_free(lst);
		return ;
	}
	clean->next = NULL;
	last = *lst;
	while (last != NULL && last->next != NULL)
		last = last->next;
	while (last->content[count] && last->content[count] != '\n')
		count++;
	if (last->content && last->content[count] == '\n')
		count++; 
	clean->content = malloc(sizeof(char) * 
	((ft_strlen(last->content) - count) + 1));
	if (clean->content == NULL)
	{
		so_free(lst);
		return free(clean);
	}
	while (last->content[count])
		clean->content[count_2++] = last->content[count++];
	clean->content[count_2] = '\0';
	free_all(*lst);
	*lst = clean;
}

char *so_free(t_list **lst)
{	
	if (*lst == NULL)
		return NULL;
	free_all(*lst);
	*lst = NULL;
	return NULL;
}	
