/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 17:53:18 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/22 15:28:42 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (1);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& (unsigned char)s1[i] != '\0')
		i++;
	if ((unsigned char)s1[i] != (unsigned char)s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
