/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:18:59 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/31 14:10:13 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_first_command(t_info_needed *info, char **argv, char **env)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("open file1");
		return (-1);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(info->pipefd[1], STDOUT_FILENO);
	close(info->pipefd[0]);
	close(info->pipefd[1]);
	execve(info->ci.command1_path, info->ci.command1, env);
	perror("execve");
	return (-1);
}

int	first_comd(t_info_needed *info, char **argv, char **env)
{
	if (info->pids.pid1 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (info->pids.pid1 == 0)
		return (exec_first_command(info, argv, env));
	return (0);
}

int	exec_second_command(t_info_needed *info, char **argv, char **env)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("open file2");
		return (-1);
	}
	dup2(info->pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(info->pipefd[0]);
	close(info->pipefd[1]);
	execve(info->ci.command2_path, info->ci.command2, env);
	perror("execve");
	return (-1);
}

int	second_comd(t_info_needed *info, char **argv, char **env)
{
	if (info->pids.pid2 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (info->pids.pid2 == 0)
		return (exec_second_command(info, argv, env));
	return (0);
}

int	handle_commands(t_info_needed *info, char **argv, char **env)
{
	info->pids.pid1 = fork();
	if (info->pids.pid1 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (info->pids.pid1 == 0)
		return (first_comd(info, argv, env));
	info->pids.pid2 = fork();
	if (info->pids.pid2 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (info->pids.pid2 == 0)
		return (second_comd(info, argv, env));
	close(info->pipefd[0]);
	close(info->pipefd[1]);
	return (EXIT_SUCCESS);
}
