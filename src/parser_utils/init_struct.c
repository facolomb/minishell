/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:54:20 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/24 16:38:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

char	**ft_skip_word(char **tokens)
{
	tokens++;
	while (*tokens)
	{
		if (ft_is_meta(*tokens))
			break ;
		tokens++;
	}
	return (tokens);
}

int	ft_nb_cmd(char **tokens)
{
	int	count;

	count = 0;
	if (ft_tablen(tokens) <= 0)
		return (0);
	while (*tokens)
	{
		count++;
		if (ft_is_redir(*tokens))
			tokens += 2;
		else
			tokens = ft_skip_word(tokens);
	}
	return (count);
}

t_cmd	*ft_init_cmd_array(int nb_cmd)
{
	int			i;
	t_cmd		*cmd_array;

	i = 0;
	cmd_array = ft_calloc(nb_cmd + 1, sizeof(t_cmd));
	while (i <= nb_cmd)
	{
		cmd_array[i].cmd = NULL;
		cmd_array[i].args = NULL;
		cmd_array[i].fd_in = -1;
		cmd_array[i].fd_out = -1;
		i++;
	}
	return (cmd_array);
}

t_cmd_table	*ft_init_table(int nb_cmd)
{
	t_cmd_table	*table;

	table = ft_calloc(1, sizeof(t_cmd_table));
	table->cmd_array = ft_init_cmd_array(nb_cmd);
	table->cmd_count = nb_cmd;
	return (table);
}
