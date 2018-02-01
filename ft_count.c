/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:32:42 by gkabongo          #+#    #+#             */
/*   Updated: 2018/01/28 14:34:36 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count(const char *s, char c)
{
	int		counter;
	int		str;

	str = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (str == 1 && *s == c)
			str = 0;
		if (str == 0 && *s != c)
		{
			str = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}
