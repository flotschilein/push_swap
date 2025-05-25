/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:16:08 by fbraune           #+#    #+#             */
/*   Updated: 2025/03/13 19:00:57 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	size_t	n;
// 	int		c;
// 	char	s[] = "Hello, World!";
// 	void 	*result;
// 	c = 'W';
// 	n = 10;

// 	result = ft_memchr(s, c, n);
// 	if (result != NULL)
//         printf("found at %ld\n", (char*)result - s);
//     else
//         printf("not found\n");
// }
