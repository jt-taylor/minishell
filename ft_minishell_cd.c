/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:03:46 by jtaylor           #+#    #+#             */
/*   Updated: 2019/08/06 16:23:58 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	sometimes an input isn't malloc'ed here ?
**	not sure why but i think it is just for this
*/
static void		set_dir_env_value(char *path)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (3));
	tmp[0] = ft_strdup(path);
	tmp[1] = ft_strdup("OLDPWD");
	tmp[2] = ft_strdup(get_env_variable("PWD"));
	tmp[3] = NULL;
	builtin_setenv(tmp, tmp[0]);
	ft_freestrarr(tmp);
	tmp = (char **)malloc(sizeof(char *) * (3));
	tmp[0] = ft_strdup(path);
	tmp[1] = ft_strdup("PWD");
	tmp[2] = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	tmp[3] = NULL;
	chdir(path);
	getcwd(tmp[2], PATH_MAX);
	builtin_setenv(tmp, tmp[0]);
	ft_freestrarr(tmp);
}

static void		minishell_cd_access_dir(char *path)
{
	char		*msg;
	struct stat	s;

	msg = NULL;
	//do I wanna use stat or lstat ?
	// maybe i need to invert this ,? doesn't actually run lstat on directories ???
	if ((access(path, F_OK) != -1))
		lstat(path, &s);
	else
		msg = "No such file or dir.\n";
	if (!(access(path, R_OK) != -1))
		msg = "Permissions Required";
	if (!S_ISDIR(s.st_mode) && !S_ISLNK(s.st_mode))
		msg = "Not a directory";
	if (msg)
		ft_printf("%s\n", msg);
	else
		set_dir_env_value(path);
}

/*
** doesn't work with paths longer than path max
** would likely only be an issue if a oath of PATH_MAX
** was mounted in the file path
**
**
** fix for the relative path
*/
void		builtin_cd(char **args, char *str)
{
	int		i;
	char		*path;

	(void)str;
	i = 1;
	if (args[1])
	{
		if (!ft_strcmp("-", args[1]))
			path = ft_strdup(get_env_variable("OLDPWD"));
		else if (!ft_strcmp("-L", args[i]) || !ft_strcmp(args[i], "-P"))
			path = ft_strdup(get_env_variable("PWD"));
		else if (args[i][0] == '/')
			path = ft_strdup(args[i]);
		else
		{
			path = ft_strjoin_free(get_env_variable("PWD"), "/", 0);
			path = ft_strjoin_free(path, args[i], 1);//ft_strdup(args[i]);
		}
	}
	else
		path = ft_strdup(get_env_variable("HOME"));
	//check permission && file exists
	minishell_cd_access_dir(path);
	free(path);
}
