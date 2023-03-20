/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:29:27 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/20 13:31:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;

	n = ft_strlen(src);
	while (1 < size-- && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (n);
}

unsigned int	get_word_count(char *str, char *delim)
{
	unsigned int	word_num;
	char			*_str;
	char			*_delim;

	word_num = 0;
	_str = str;
	_delim = delim;
	while (1)
	{
		delim = _delim;
		while (*delim && *(str + (delim - _delim)) == *delim)
			delim++;
		if (!*delim)
			word_num++;
		if (!*str)
			break ;
		str++;
	}
	return (word_num + 1);
}

char	*get_next_word(char *str, char *delim)
{
	char			*word;
	unsigned int	word_len;
	char			*_str;
	char			*_delim;

	_str = str;
	_delim = delim;
	while (1)
	{
		delim = _delim;
		while (*delim && *(str + (delim - _delim)) == *delim)
			delim++;
		if (!*delim || !*str)
			break ;
		str++;
	}
	word_len = str - _str;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	ft_strlcpy(word, _str, (word_len + 1));
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char			**result;
	unsigned int	word_count;
	unsigned int	charset_len;
	unsigned int	i;

	word_count = get_word_count(str, charset);
	charset_len = ft_strlen(charset);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	i = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(str, charset);
		str += ft_strlen(result[i]) + charset_len;
		i++;
	}
	result[i] = 0;
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char *str;
	char *charset;
	char **ans;

	str = "_hello__";
	charset = "+_";
	ans = ft_split(str, charset);
	printf("0: %s\n", ans[0]);
	printf("1: %s\n", ans[1]);
	printf("2: %s\n", ans[2]);
	printf("3: %s\n", ans[3]);
	printf("4: %s\n", ans[4]);
}