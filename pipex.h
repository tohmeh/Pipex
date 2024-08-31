/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:17:12 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/31 14:10:58 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "LIBFT/include/LIBFT.h"

typedef struct t_ci{
	char	*command1_path;
	char	*command2_path;
	char	**command1;
	char	**command2;
}	t_ci;

typedef struct t_pids{
	int	pid1;
	int	pid2;
}	t_pids;

typedef struct t_info_needed{
	t_ci	ci;
	t_pids	pids;
	int		pipefd[2];
}	t_info_needed;

typedef struct paths
{
	char	**paths;
	char	*full_path;
	char	*temp;
}	t_paths;

char	*find_in_2d_array(char **strr, char *to_find);
void	free_2d_array(char **array);
char	*spec_com_path(char **env, char *command);
int		exec_first_command(t_info_needed *info, char **argv, char **env);
int		first_comd(t_info_needed *info, char **argv, char **env);
int		exec_second_command(t_info_needed *info, char **argv, char **env);
int		second_comd(t_info_needed *info, char **argv, char **env);
int		handle_commands(t_info_needed *info, char **argv, char **env);
void	end_of_program_cleanup(int *pipefd, t_pids pids, t_ci ci);

#endif