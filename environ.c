#include "shell.h"
/**
 * _myenv - a fuction to prints the current environment
 * @info: Structure parameter that containing potential arguments.
 * Return: Always return 0 on success
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - a function that gets the value of an environ variable
 * @info: Structure parameter containing potential arguments.
 * @name: parameter for inveronment variable name
 * Return: return the value of__
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - a function to Initialize a new environment variable,
 * @info: Structure parameter containing potential arguments.
 *  Return: return 0 on success
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - a function to remove an environment variable
 * @info: Structure parameter that containing potential arguments.
 * Return: rerurn 0 on success
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);
	return (0);
}
/**
 * populate_env_list - a function that populates env linked list
 * @info: Structure parameter that containing potential arguments.
 * Return: return 0 on success
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
