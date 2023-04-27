#include "shell.h"

/**
 * get_environ - Returns a copy of the environment variables array.
 * @info: The information struct containing potential arguments.
 * Return: The environment variables array.
 */
char **get_environ(info_t *info)
{
    if (!info->environ || info->env_changed)
    {
        info->environ = list_to_strings(info->env);
        info->env_changed = false;
    }
    return (info->environ);
}

/**
 * unset_env_var - Remove an environment variable.
 * @info: The information struct containing potential arguments.
 * @var: The name of the environment variable.
 * Return: 1 on success, 0 on failure.
 */
int unset_env_var(info_t *info, char *var)
{
    if (!var)
        return (0);

    list_t **head = &(info->env);
    list_t *node = *head;
    size_t i = 0;

    while (node)
    {
        char *p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            info->env_changed = true;
            delete_node_at_index(head, i);
            return (1);
        }
        node = node->next;
        i++;
    }
    return (0);
}

/**
 * set_env_var - Initialize a new environment variable, or modify an existing one.
 * @info: The information struct containing potential arguments.
 * @var: The name of the environment variable.
 * @value: The value of the environment variable.
 * Return: 0 on success, 1 on failure.
 */
int set_env_var(info_t *info, char *var, char *value)
{
    if (!var || !value)
        return (1);

    char *buf = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buf)
        return (1);
    _strcpy(buf, var);
    _strcat(buf, "=");
    _strcat(buf, value);

    list_t **head = &(info->env);
    list_t *node = *head;

    while (node)
    {
        char *p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            free(node->str);
            node->str = buf;
            info->env_changed = true;
            return (0);
        }
        node = node->next;
    }

    add_node_end(head, buf);
    free(buf);
    info->env_changed = true;
    return (0);
}
