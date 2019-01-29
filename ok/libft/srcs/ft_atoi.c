/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 22:38:40 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:05:50 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	int		neg;

	n = 0;
	neg = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\v' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + *str - '0';
		else
			break ;
		str++;
	}
	return (n * neg);
}
