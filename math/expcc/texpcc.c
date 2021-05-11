#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cJSON.h"
#include "expcc.h"
#include "termux_api.h"

static char *cmdcat(char *const ptr, const char *const str)
{
    size_t len = strlen(ptr);
    len += strlen(str) + 1;

    char *newptr = NULL;
    newptr = realloc(ptr, len);

    if (newptr == NULL)
    {
        perror(str);
        exit(EXIT_FAILURE);
    }

    strcat(newptr, str);

    return newptr;
}

static char *cmdstr(const char *const str)
{
    if (str == NULL)
        return NULL;

    char *cmdin = (char *)calloc(1, sizeof(char));

    size_t j = 0;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '\'')
        {
            cmdin = realloc(cmdin, j + 2);
            cmdin[j++] = '\'';
        }

        cmdin = realloc(cmdin, j + 2);
        cmdin[j++] = str[i];
    }

    cmdin[j] = '\0';

    return cmdin;
}

static int cmdno(const char *const cmd)
{

#ifdef CMD_SHOW
    printf("%s\n", cmd);
#endif

    char buff[BUFSIZ] = {};

    FILE *pipe = popen(cmd, "r");

    if (pipe == NULL)
    {
        perror(cmd);
        return -1;
    }

    while (!feof(pipe))
        fgets(buff, BUFSIZ, pipe);

    pclose(pipe);

    return 0;
}

/*
static char *cmd(const char *const cmd)
{

#ifdef CMD_SHOW
    printf("%s\n", cmd);
#endif

    FILE *pipe = popen(cmd, "r");

    if (pipe == NULL)
    {
        perror(cmd);
        return NULL;
    }

    char *str = (char *)calloc(1, sizeof(char));

    size_t i = 0;
    while (1)
    {
        char ch = fgetc(pipe);

        if (feof(pipe))
            break;

        str = realloc(str, i + 2);
        str[i++] = ch;
    }

    str[i] = '\0';
    fflush(pipe);

    pclose(pipe);

    return str;
}
*/

void tapi_window(const char *const t, const char *const i)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog confirm");

    if (t != NULL)
    {
        command = cmdcat(command, " \\\n-t '");

        cmdin = cmdstr(t);
        command = cmdcat(command, cmdin);
        free(cmdin);

        command = cmdcat(command, "'");
    }

    if (i != NULL)
    {
        command = cmdcat(command, " \\\n-i '");

        cmdin = cmdstr(i);
        command = cmdcat(command, cmdin);
        free(cmdin);

        command = cmdcat(command, "'");
    }

    cmdno(command);

    free(command);

    return;
}

int json_code(const char *const result)
{
    cJSON *json = cJSON_Parse(result);
    cJSON *item = cJSON_GetObjectItem(json, "code");

    if (item == NULL)
        return -1000;

    int code = item->valueint;

    cJSON_Delete(json);

    return code;
}

char *json_code_text(const char *const result, int code)
{
    cJSON *json = cJSON_Parse(result);
    cJSON *item = cJSON_GetObjectItem(json, "code");

    if (item == NULL)
        return NULL;

    char *str = NULL;

    if (item->valueint == code)
    {
        cJSON *itemtext = cJSON_GetObjectItem(json, "text");

        if (itemtext == NULL)
            return NULL;

        char *text = itemtext->valuestring;
        str = calloc(strlen(text) + 1, sizeof(char));
        strcpy(str, text);
    }

    cJSON_Delete(json);
    json = NULL;

    return str;
}

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        Decimal result = expcc(argv[i]);
        printf(" = %g %g/%g\n", decimalcc(result), result.a, result.b);
    }

    if (argc > 1)
        return 0;

    char buff[BUFSIZ] = {};

    while (1)
    {
        char *tstr = termux_dialog_text("表达式", NULL, "m");
        char *str = json_code_text(tstr, -1);
        free(tstr);

        char strout[BUFSIZ] = {};

        if (str == NULL)
            break;

        if (strcmp(str, "") == 0)
        {
            free(str);
            continue;
        }

        //char *exp = strtok(str, "\n");
        int count = 0;
        for (size_t i = 0; str[i]; i++)
        {
            size_t j = 0;
            while (str[i] != '\n')
            {
                buff[j++] = str[i++];
                if (!str[i])
                    break;
            }
            buff[j] = '\0';

            if (!strcmp(buff, "") || isalpha(buff[0]))
                continue;

            int mark = 0;
            for (size_t tempi = 0; isblank(buff[tempi]);)
            {
                if (!buff[tempi++])
                    mark = 1;
            }

            if (mark)
                continue;

            count++;

            Decimal result = expcc(buff);
            sprintf(buff, "%d> %g %g/%g\n", count, decimalcc(result), result.a, result.b);
            printf(" = %g %g/%g\n", decimalcc(result), result.a, result.b);
            strcat(strout, buff);
        }

        free(str);

        if (!strcmp(strout, ""))
            continue;

        tapi_window("结果", strout);
    }

    return 0;
}