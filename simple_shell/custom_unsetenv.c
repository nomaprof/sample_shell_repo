#include "shell.h"

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t **env = &(info->env);
	list_t *node = *env;
	size_t i = 0;
	int env_changed = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			env_changed = delete_node_at_index(env, i);
			node = *env;
			continue;
		}
		node = node->next;
		i++;
	}
	info->env_changed = env_changed;
	return (env_changed);
}
