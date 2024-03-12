/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:15:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/12 16:31:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char const *s, char delimiter)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != delimiter && (!s[i + 1] || s[i + 1] == delimiter))
			word_count++;
		i++;
	}
	return (word_count);
}

static char	*extract_word(char *s, char delimiter)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != delimiter)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != delimiter)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	cleanup(char **word_array, int word_index)
{
	while (word_index >= 0)
	{
		free(word_array[word_index]);
		word_array[word_index] = 0;
		word_index--;
	}
	free(word_array);
	word_array = 0;
}

int	parse_words(char **words, char *s, char delimiter, int word_index)
{
	while (*s && *s == delimiter)
		s++;
	while (*s)
	{
		words[word_index] = extract_word(s, (unsigned char)delimiter);
		if (words[word_index] == 0)
		{
			cleanup(words, word_index);
			return (0);
		}
		word_index++;
		while (*s && *s != delimiter)
			s++;
		while (*s && *s == delimiter)
			s++;
	}
	return (word_index);
}

char	**ft_split(char const *s, char c)
{
	int		counter;
	char	**words;
	int		word_index;

	if (s == NULL)
		return (NULL);
	word_index = 0;
	counter = word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (counter + 1));
	if (words == NULL)
		return (NULL);
	words[counter] = NULL;
	if (counter > 0)
	{
		word_index = parse_words(words, (char *)s, c, word_index);
		if (word_index == 0)
			return (0);
	}
	return (words);
}
