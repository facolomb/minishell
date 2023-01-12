/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:01:03 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/12 13:01:05 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_redir_in(char *token)
{
	if (ft_str_same(token, "LESSLESS") || ft_str_same(token, "LESS"))
		return (1);
	else
		return (0);
}

int	ft_is_redir_out(char *token)
{
	if (ft_str_same(token, "GREATGREAT") || ft_str_same(token, "GREAT"))
		return (1);
	else
		return (0);
}

int	ft_is_pipe(char *token)
{
	if (ft_str_same(token, "PIPE"))
		return (1);
	else
		return (0);
}

int	ft_is_redir(char *token)
{
	if (ft_is_redir_in(token) || ft_is_redir_out(token))
		return (1);
	else
		return (0);
}
