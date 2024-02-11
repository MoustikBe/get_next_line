/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:19:46 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/11 21:29:10 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{

	static t_list	*lst = NULL;
	char			*line; // - la ligne que je vais retourner a la fin - // 
	int				readed; //- Va stocker la valeur de retourn de read - // 

	if (fd < 0 || BUFFER_SIZE =< 0 || read(fd, line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	read_sotre(fd, &lst, readed);

	return(line); 
    // 1. Lire et Stocker les valeurs prises par read avec le BUFFEUR_SIZE dans la structure. //
    // Ce que l'on doit faire c'est allouer de la memoire pour le buffer qui va stocker les caractere lu et stocker par read, on va faire un malloc de BUFFER_SIZE + 1
    // Puis read(fd, buf, BUFFER_SIZE) qui va lire les caracteres et on va stocker egalement la valeur de retour de read dans readed, comme sa on va pouvoir 
    // Si on est a la fin on non et vont continuer a lire tant qu'on arrive pas a '\0' ou '\n'
    
}

// Va allouer BUFFER_SIZE + 1 de memoire pour stocker le buffer 
// Ensuite va boucler tant qu'on a pas trouver une nouvelle ligne et tant que readed(valeur de return de read) n'est pas nul 
// La valeur readed va etre redefinis a chaque nouveau passage dans la boucle
void read_sotre(int fd, t_list **lst, int readed)
{
    char *buff; 

    buff = malloc((sizeof char) * BUFFER_SIZE + 1);
    if (!buff)
        return ;
    while (found_n(*lst) == 0 && readed != 0)
    {
        readed = read(fd, buff, BUFFER_SIZE);
        if((*lst) == NULL && readed = 0 || readed = -1)
		{
			free(buff);
			return ;
		}
        buff[readed] = '\0';
    }
}

int found_n(t_list *lst)
{
    int count;

	count = 0; 
	if ((*lst) == NULL)
		return (0);
	lst = lst_last(*lst);
	while(lst->content[count] != '\0')
	{
		if(lst->content[count] == '\n')
			return(1);
		count++; 
	}
	return(0)	
}

void lst_last(t_list *lst)
{
	while(lst != NULL && lst->next != NULL) 
		lst = lst->next; 
	return(lst); 
}

int main(void)
{

    return 0; 
}