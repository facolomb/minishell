/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:03:34 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/08 12:03:34 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

char	***ft_get_redir_word_tab(void)
{
	static char	***redir_word_tab;

	if (redir_word_tab == NULL)
		redir_word_tab = ft_read_two_way_tab(REDIR_WORDS_FILE, "txt", '=');
	if (redir_word_tab == NULL)
		ft_fatal_error("Cannot read redir_words.txt", NULL, NULL);
	return (redir_word_tab);
}

char	*ft_find_redir_path(char ***redirs, char *str)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (ft_str_same(redirs[i][0], str))
			return (ft_strjoin(REDIR_FOLDER, redirs[i][1]));
		i++;
	}
	return (NULL);
}

char	*ft_get_redir_path(char *str)
{
	char	***redirs;
	char	*redir_path;

	if (str == NULL)
		return (NULL);
	redirs = ft_get_redir_word_tab();
	if (!redirs)
		return (NULL);
	redir_path = ft_find_redir_path(redirs, str);
	return (redir_path);
}
