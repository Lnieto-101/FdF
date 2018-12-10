/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 10:02:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:49:21 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*duplic;

	i = 0;
	duplic = 0;
	i = ft_strlen(src);
	if (!(duplic = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strcpy(duplic, src);
	return (duplic);
}
