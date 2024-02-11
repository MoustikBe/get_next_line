/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:19:41 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/11 20:34:32 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// -- Strucutre de la liste chainer -- //
typedef struct s_list
{
    char            *content; 
    struct s_list   *next; 
}                   t_list; 
// ----------------------------------- //
// --- Declaration des bibliotheque --- // 
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
// ------------------------------------ // 
// - Fonction - //
char *get_next_line(int fd);

// ------------ //
#endif

// -- Pour le buffer -- //
# ifndef BUFFER_SIZE 
#   define  BUFFER_SIZE = 5
# endif
// -------------------- //