/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:55:20 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/31 14:10:58 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_in_2d_array(char **strr, char *to_find)
{
	int	i;

	i = 0;
	while (strr[i] != NULL)
	{
		if (ft_strnstr(strr[i], to_find, ft_strlen(to_find)))
			return (ft_strdup(strr[i]));
		i++;
	}
	return (NULL);
}

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*spec_com_path(char **env, char *command)
{
	int		i;
	char	*str;
	t_paths	p;

	i = -1;
	str = find_in_2d_array(env, "PATH=");
	if (!str)
		return (NULL);
	p.paths = ft_split(str + 5, ':');
	free(str);
	while (p.paths[++i] != NULL)
	{
		p.full_path = ft_strjoin(p.paths[i], "/");
		p.temp = ft_strjoin(p.full_path, command);
		free(p.full_path);
		p.full_path = p.temp;
		if (access(p.full_path, X_OK) == 0)
		{
			free_2d_array(p.paths);
			return (p.full_path);
		}
		free(p.full_path);
	}
	free_2d_array(p.paths);
	return (NULL);
}

void	end_of_program_cleanup(int *pipefd, t_pids pids, t_ci ci)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pids.pid1, NULL, 0);
	waitpid(pids.pid2, NULL, 0);
	free(ci.command1_path);
	free(ci.command2_path);
	free_2d_array(ci.command1);
	free_2d_array(ci.command2);
}

int	main(int argc, char **argv, char **env)
{
	t_info_needed	all_info;

	if (argc != 5)
	{
		ft_printf("Usage: %s file1 command1 command2 file2\n", argv[0]);
		return (0);
	}
	all_info.ci.command1 = ft_split(argv[2], ' ');
	all_info.ci.command2 = ft_split(argv[3], ' ');
	all_info.ci.command1_path = spec_com_path(env, all_info.ci.command1[0]);
	all_info.ci.command2_path = spec_com_path(env, all_info.ci.command2[0]);
	if (pipe(all_info.pipefd) == -1)
	{
		perror("pipe");
		return (0);
	}
	if (handle_commands(&all_info, argv, env) == -1)
		return (0);
	end_of_program_cleanup(all_info.pipefd, all_info.pids, all_info.ci);
	return (EXIT_SUCCESS);
}
