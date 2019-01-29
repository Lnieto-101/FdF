/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:32:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 09:59:06 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *dest, const char *src);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);

char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_get_next_line(const int fd, char **line);
void				ft_strdel(char **as);

#endif
