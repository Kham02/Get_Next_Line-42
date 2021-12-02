/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:47:52 by estrong           #+#    #+#             */
/*   Updated: 2021/11/25 17:47:17 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 9

char	*get_next_line(int fd);
char	*ft_read(int fd, char *line);
char	*ft_before(char	*line);
char	*ft_after(char	*line);

char	*ft_strchr(const char *s, int n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif
// #endif
