#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: true if file is an executable command, false otherwise
 */
bool is_cmd(info_t *info, const char *path)
{
    struct stat st;

    if (!path || stat(path, &st) == -1)
        return false;

    return (st.st_mode & S_IFREG) != 0;
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(const char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0, k = 0;

    for (k = 0, i = start; i < stop; i++)
    {
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    }
    buf[k] = '\0';
    return buf;
}

/**
 * find_path - finds the full path of a command in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the command to find
 *
 * Return: the full path of the command if found, NULL otherwise
 */
char *find_path(info_t *info, const char *pathstr, const char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path = NULL;

    if (!pathstr)
        return NULL;

    if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return _strdup(cmd);
    }

    while (true)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = dup_chars(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (is_cmd(info, path))
                return path;
            if (!pathstr[i])
                break;
            curr_pos = i + 1;
        }
        i++;
    }
    return NULL;
}