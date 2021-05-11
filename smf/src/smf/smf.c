/*******************************
 * 
 * 
*/
#include "smf.h"

int main(int argc, char *argv[])
{
    Use use = USE_FIND;

    if (argc == 1) //
    {
        printf("%s\n", HELP); //打印帮助
        exit(0);
    }
    else
    {
        if (strncmp(argv[1], "init", sizeof("init")) == 0)
            use = USE_INIT;
        else if (strncmp(argv[1], "add", sizeof("add")) == 0)
            use = USE_ADD;
        else if (strncmp(argv[1], "del", sizeof("del")) == 0)
            use = USE_DEL;
        else if (strncmp(argv[1], "edit", sizeof("edit")) == 0)
            use = USE_EDIT;
        else if (strncmp(argv[1], "create", sizeof("create")) == 0)
            use = USE_CREATE;
        else if (strncmp(argv[1], "out", sizeof("out")) == 0)
            use = USE_OUT;
        else if (strncmp(argv[1], "in", sizeof("in")) == 0)
            use = USE_IN;
        else
            use = USE_FIND;
    }

    Password *pd = (Password *)calloc(1, sizeof(Password));
    Pd_data *pd_data = (Pd_data *)calloc(1, sizeof(Pd_data));

    pd_data->dataname = ".smf.mm.json";

    for (size_t i = 2; i < argc; i++)
    {
        char *argch = NULL;
        char *argstr = NULL;

        if (strstr(argv[i], "=") != NULL && strstr(argv[i], "--") != NULL) //--user=user
        {
            argch = calloc(sizeof(char), 1);
            size_t j = 0;

            for (; j < strlen(argv[i]) + 1; j++)
            {
                if (argv[i][j] != '=')
                {
                    argch = realloc(argch, j + 2);
                    argch[j] = argv[i][j];
                }
                else
                {
                    argch[j++] = '\0';
                    break;
                }
            }

            argstr = calloc(sizeof(char), strlen(argv[i]) + 1 - j);

            for (size_t k = 0; j < strlen(argv[i]) + 1; j++)
                argstr[k++] = argv[i][j];
        }
        else if (strlen(argv[i]) > 2 && strstr(argv[i], "--") == NULL) //-uuser
        {
            argch = calloc(sizeof(char), 3);

            size_t j = 0;

            for (; j < 2; j++)
                argch[j] = argv[i][j];
            argch[j] = '\0';

            argstr = calloc(sizeof(char), strlen(argv[i]) + 1 - 2);

            for (size_t k = 0; j < strlen(argv[i]) + 1; j++)
                argstr[k++] = argv[i][j];
        }
        else // -u user | --user user
        {
            argch = calloc(BUFSIZ + 1, sizeof(char));
            argch = strncpy(argch, argv[i], BUFSIZ);

            if (++i >= argc) // -u
            {
                printf("illegal option %s\n", argch);
                free(argch);
                exit(1);
            }

            argstr = calloc(BUFSIZ + 1, sizeof(char));
            argstr = strncpy(argstr, argv[i], BUFSIZ);
        }

        if (strncmp(argch, "-f", 3 * sizeof(char)) == 0 || strncmp(argch, "--file", sizeof("--file")) == 0)
        {
            pd_data->dataname = argstr;
        }
        else if (strncmp(argch, "-o", 3 * sizeof(char)) == 0 || strncmp(argch, "--out", sizeof("--out")) == 0)
        {
            pd_data->outname = argstr;
        }
        else if (strncmp(argch, "-i", 3 * sizeof(char)) == 0 || strncmp(argch, "--in", sizeof("--in")) == 0)
        {
            pd_data->inname = argstr;
        }
        else if (strncmp(argch, "-n", 3 * sizeof(char)) == 0 || strncmp(argch, "--name", sizeof("--name")) == 0)
        {
            pd->name = argstr;
        }
        else if (strncmp(argch, "-l", 3 * sizeof(char)) == 0 || strncmp(argch, "--length", sizeof("--length")) == 0)
        {
            pd->len = atoi(argstr);
            free(argstr);
            argstr = NULL;
        }
        else if (strncmp(argch, "-t", 3 * sizeof(char)) == 0 || strncmp(argch, "--type", sizeof("--type")) == 0)
        {
            pd->type = atoi(argstr);
            free(argstr);
            argstr = NULL;
        }
        else if (strncmp(argch, "-p", 3 * sizeof(char)) == 0 || strncmp(argch, "--password", sizeof("--password")) == 0)
        {
            pd->key = argstr;
        }
        else
        {
            free(argstr);
            argstr = NULL;
        }

        free(argch);
        argch = NULL;
    }

    if (use == USE_FIND)
    {
        pd->name = calloc(BUFSIZ + 1, sizeof(char));
        strncpy(pd->name, argv[1], BUFSIZ);
    }

    runpd(argv[0], use, pd, pd_data);

    return 0;
}

void runpd(const char *const bin, Use use, const Password *const pd, const Pd_data *const pd_data)
{
    int flag = 1;

    if (use == USE_INIT)
    {
        FILE *fp = fopen(pd_data->dataname, "r");
        if (fp == NULL)
            wstr(pd_data->dataname, "[]");
        else
        {
            printf("%s exists!\n", pd_data->dataname);
            fclose(fp);
        }
    }

    if (use == USE_CREATE)
    {
        if (pd->len <= 0)
        {
            printf("missing -l <length>\n");
        }
        else
        {
            char *outstr = pd_create(pd->type, pd->len);
            printf("%s\n", outstr);
            free(outstr);
        }
    }

    if (use == USE_ADD)
    {
        if (pd->name == NULL)
        {
            printf("missing -n <name>\n");
        }
        else if (pd->key == NULL)
        {
            printf("missing -p <password>\n");
        }
        else
        {
            flag = pd_add(pd_data->dataname, pd->name, pd->key);
        }
    }

    if (use == USE_DEL)
    {
        if (pd->name == NULL)
        {
            printf("missing -n <name>\n");
        }
        else
        {
            flag = pd_del(pd_data->dataname, pd->name);
        }
    }

    if (use == USE_EDIT)
    {
        if (pd->name == NULL)
        {
            printf("missing -n <name>\n");
        }
        else if (pd->key == NULL)
        {
            printf("missing -p <password>\n");
        }
        else
        {
            flag = pd_edit(pd_data->dataname, pd->name, pd->key);
        }
    }

    if (use == USE_OUT)
    {
        if (pd_data->outname == NULL)
        {
            printf("missing -o <file>");
        }
        else
        {
            flag = pd_derive(pd_data->dataname, pd_data->outname);
        }
    }

    if (use == USE_IN)
    {
        if (pd_data->inname == NULL)
        {
            printf("missing -i <file>");
        }
        else
        {
            flag = pd_import(pd_data->dataname, pd_data->inname, 1);
        }
    }

    if (use == USE_FIND && pd->name != NULL)
    {
        cJSON *result = pd_find(pd_data->dataname, pd->name);
        if (result == NULL)
        {
            flag = -1;
        }
        else
        {
            for (size_t i = 0; i < cJSON_GetArraySize(result); i++)
            {
                cJSON *itemout = cJSON_GetArrayItem(result, i);

                cJSON_DeleteItemFromObject(itemout, PD_TYPE);

                char *outstr = cJSON_Print(itemout);
                printf("%s", outstr);
                fflush(stdout);

                free(outstr);
            }

            cJSON_Delete(result);
        }
    }

    if (flag == 0)
    {
        printf("\rOK\n");
    }

    if (flag == -1)
        printf("\r%s init -f %s\n", bin, pd_data->dataname);

    if (flag == -2)
        printf("\rJSON Read Error:%s\n", pd_data->dataname);

    if (flag == -3)
        printf("\rNot found Name:%s\n", pd->name);

    if (flag == -4)
        printf("\rJSON Read Error:%s\n", pd_data->inname);

    if (flag == -5)
        printf("\rSame File Name:%s\n", pd_data->dataname);

    return;
}