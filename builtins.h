#ifndef BUILTINS_H
#define BUILTINS_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#include "alias.h"
#include "env.h"
#include "error.h"
#include "info.h"
#include "path.h"
#include "string.h"
#include "types.h"

#define ALIAS_HELP "alias [KEY[=VALUE] ...]"
#define ALIAS_DESC

#define CD_HELP
#define CD_DESC

#define EXEC_HELP
#define EXEC_DESC

#define EXIT_HELP
#define EXIT_DESC

#define HELP_HELP
#define HELP_DESC

#define SETENV_HELP
#define SETENV_DESC

#define UNSETENV_HELP
#define UNSETENV_DESC

typedef int (*builtin_fp)(info_t *);

/**
 * struct builtin - builtin command
 * @name: command name
 * @f: function to call
 * @help: command usage
 * @desc: command descripyion
 */
struct builtin
{
	const char *name;
	builtin_fp f;
	const char *help;
	const char *desc;
};

const struct builtin *get_builtin(const char *name);
const struct builtin *get_builtins(void);

int _alias(info_t *info);
int _cd(info_t *info);
int _env(info_t *info);
int _exec(info_t *info);
int _exit(info_t *info);
int _help(info_t *info);
int _history(info_t *info);
int _setenv(info_t *info);
int _unsetenv(info_t *info);

#endif
