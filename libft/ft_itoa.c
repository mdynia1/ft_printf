/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:42:46 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/29 21:01:02 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len(int nb)
{
	int		l;

	if (!(l = 0) && nb == -2147483648 && (l += 2) != -1)
		nb = 147483648;
	if (nb < 0 && l++ != -1)
		nb *= -1;
	if (nb > 9)
		l += ft_len(nb / 10);
	return (++l);
}

char		*ft_itoa(int n)
{
	int		l;
	char	*str;

	l = ft_len(n);
	if (!(str = ft_strnew(l)))
		return (NULL);
	if (n == -2147483648 && (str[1] = '2'))
		n = -147483648;
	if (n < 0 && (str[0] = '-'))
		n *= -1;
	while (l-- && str[l] != '-' && str[l] != '2')
	{
		str[l] = (n % 10 + '0');
		n /= 10;
	}
	return (str);
}