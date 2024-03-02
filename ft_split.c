/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:15:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/02 12:13:50 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char const *s, char delimiter)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter && (s[i + 1] == 0 || s[i + 1] == delimiter))
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
	while (s[i] != '\0' && s[i] != delimiter)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != delimiter)
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
	while (*s != '\0' && *s == delimiter)
		s++;
	while (*s != '\0')
	{
		words[word_index] = extract_word(s, (unsigned char)delimiter);
		if (words[word_index] == 0)
		{
			cleanup(words, word_index);
			return (0);
		}
		word_index++;
		while (*s != '\0' && *s != delimiter)
			s++;
		while (*s != '\0' && *s == delimiter)
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
	if (counter > 0)
	{
		word_index = parse_words(words, (char *)s, c, word_index);
		if (word_index == 0)
			return (0);
	}
	return (words);
}

// #include <stdio.h>
// int main(void)
// {
// 	int i;
// 	char str[] = "What if there was no time";
// 	char **result = ft_split(str, ' ');
// 	if (result != 0)
// 	{
// 		i = 0;
// 		while (result[i])
// 		{
// 			printf("%d: %s\n", i, result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed.");
// 	return (0);
// }