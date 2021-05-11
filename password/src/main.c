#include "smf.h"

char *HELP = "usage:smf [option] [value]\n\
--init inital data\n\
-a add password\n\
-b <backupdir> buckup data to backupdir\n\
-c <digital> create password len 1 ~ 32(default 16)\n\
-d <name> delete password\n\
-e <name> edit password\n\
-f <filename> (default data)\n\
-h,--help help\n\
-i <filename> import data\n\
-l <digital> length of list(default 5)\n\
-n <name> \n\
-p <password>\n\
-s <name> search password\n\
-t <digital> type 1(default)(digital + letter) 2(digital) 3(char)\n\
-v view data\n\
";

char File_name[NAME_LEN] = ".data.smf"; //-f
char Backup_dir[NAME_LEN] = ".smf";     //-b
char Import_file[NAME_LEN] = {};        //=i
char Name[NAME_LEN] = {};               //-n
char Password[PASS_LEN] = {};           //-p
int Pass_type = 1;                      //-t
int Create_len = 16;                    //-c
int List_len = 5;                       //-l

int MARK_type = 0;     //-t
int MARK_import = 0;   //-i
int MARK_backup = 0;   //-b
int MARK_filename = 0; //-f
int MARK_name = 0;     //-n
int MARK_pass = 0;     //-p
int MARK_create = 0;   //-c
int MARK_list = 0;     //-l
int MARK_show = 0;     //-v
int MARK_del = 0;      //-d
int MARK_find = 0;     //-s
int MARK_add = 0;      //-a
int MARK_edit = 0;     //-e

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "");
    if (strstr(argv[0], "smf") == NULL)
        exit(1);
    int i = 0;
    char argstr[NAME_LEN] = {};

    for (i = 1; i < argc; i++)
    {
        strncpy(argstr, argv[i], NAME_LEN - 1);
        while (strlen(argstr) > 2 && argstr[0] == '-' && argstr[1] != '-')
        {
            if (strstr(argstr, "v") != NULL)
            {
                delch(argstr, 'v');
                MARK_show += 1;
            }
            else if (strstr(argstr, "a") != NULL)
            {
                delch(argstr, 'a');
                MARK_add += 1;
            }
            else if (strstr(argstr, "b") != NULL)
            {
                delch(argstr, 'b');
                MARK_backup += 1;
            }
            else if (strstr(argstr, "d") != NULL)
            {
                delch(argstr, 'd');
                MARK_del += 1;
            }
            else if (strstr(argstr, "c") != NULL)
            {
                delch(argstr, 'c');
                MARK_create += 1;
            }
            else if (strstr(argstr, "e") != NULL)
            {
                delch(argstr, 'e');
                MARK_edit += 1;
            }
            else if (strstr(argstr, "s") != NULL)
            {
                delch(argstr, 's');
                MARK_find += 1;
            }
            else if (strstr(argstr, "l") != NULL)
            {
                delch(argstr, 'l');
                MARK_list += 1;
            }
            else
            {
                delch2(argstr);
            }
        }
        if (strcmp(argstr, "-") == 0)
            continue;
        if (strncmp(argstr, "--init", 7) == 0)
        {
            FILE *fp = fopen(File_name, "r");
            int mark = 0;
            if (fp == NULL)
                mark = 1;
            else
            {
                printf("FILE EXISTS!(OVERWRITE)[y/N]:");
                if (tolower(getchar()) == 'y')
                    mark = 1;
            }

            if (mark)
            {
                if (fp != NULL)
                    fclose(fp);
                fp = NULL;
                initdir(Backup_dir);
                fclose(wfile(File_name));
                printf("[OK]\n");
            }
            exit(0);
        }
        else if (strncmp(argstr, "-h", 3) == 0 || strncmp(argstr, "--help", 7) == 0)
        {
            printf("%s", HELP);
            exit(0);
        }
        else if (strncmp(argstr, "-f", 3) == 0) // && MARK_filename == 0
        {
            i++;
            MARK_filename += 1;
            argvname(argc, argv, File_name, &i, "FILENMAE:");
        }
        else if (strncmp(argstr, "-b", 3) == 0) // && MARK_backup == 0
        {
            i++;
            MARK_backup += 1;
            argvnames(argc, argv, Backup_dir, &i, "Backup_dir:");
        }
        else if (strncmp(argstr, "-i", 3) == 0) // && MARK_import == 0
        {
            i++;
            MARK_import += argvnames(argc, argv, Import_file, &i, "FILENMAE:");
        }
        else if (strncmp(argstr, "-p", 3) == 0) // && MARK_pass == 0
        {
            i++;
            MARK_pass += argvpass(argc, argv, Password, Create_len, Pass_type, &i);
        }
        else if (strncmp(argstr, "-t", 3) == 0) // && MARK_type == 0
        {
            i++;
            MARK_type += argvi(argc, argv, &Pass_type, &i, "TYPE:");
        }
        else if (strncmp(argstr, "-c", 3) == 0) // && MARK_create == 0
        {
            i++;
            MARK_create += 1;
            argvis(argc, argv, &Create_len, &i);
            if (Create_len > PASS_LEN - 1)
                Create_len = 16;
        }
        else if (strncmp(argstr, "-a", 3) == 0) //&& MARK_add == 0
        {
            MARK_add += 1;
        }
        else if (strncmp(argstr, "-d", 3) == 0) // && MARK_del == 0
        {
            i++;
            MARK_del += 1;
            MARK_name += argvnames(argc, argv, Name, &i, "NAME:");
        }
        else if (strncmp(argstr, "-e", 3) == 0) // && MARK_edit == 0
        {
            i++;
            MARK_edit += 1;
            MARK_name += argvnames(argc, argv, Name, &i, "NAME:");
        }
        else if (strncmp(argstr, "-v", 3) == 0) // && MARK_show == 0
        {
            MARK_show += 1;
        }
        else if (strncmp(argstr, "-l", 3) == 0) // && MARK_list == 0
        {
            i++;
            MARK_list += argvis(argc, argv, &List_len, &i); //, "List_len:"
        }
        else if (strncmp(argstr, "-n", 3) == 0) //&& MARK_name == 0
        {
            i++;
            MARK_name += argvname(argc, argv, Name, &i, "NAME:");
        }
        else if (strncmp(argstr, "-s", 3) == 0) // && MARK_find == 0
        {
            i++;
            MARK_find += 1;
            MARK_name += argvnames(argc, argv, Name, &i, "NAME:");
        }
        else if (MARK_name == 0 && argstr[0] != '-')
        {
            strcpy(Name, argstr);
            MARK_find += 1;
            MARK_name += 1;
        }
        else
        {
            printf("Unknown option: %s\n", argstr);
            exit(1);
        }
        /*if ((MARK_add + MARK_del + MARK_edit) > 1)
        {
            printf("Too many parameters!\n");
            exit(1);
        }*/
    }
    if (MARK_backup != 0)
    {
        backup(File_name, Backup_dir);
    }
    if (MARK_import != 0)
    {
        import(File_name, Import_file);
        sort(File_name);
        printf("[OK]");
        exit(0);
    }
    if (MARK_del != 0)
    {
        if (MARK_name == 0)
        {
            inputstr("NAME:", Name, NAME_LEN);
            MARK_name += 1;
        }
        if (del(File_name, Name))
            printf("DEL %s\n", Name);
        //else
        //    printf("%s NOT EXIST!\n", Name);
    }
    if (MARK_edit != 0)
    {
        if (MARK_name == 0)
        {
            inputstr("NAME:", Name, NAME_LEN);
            MARK_name += 1;
        }
        if (MARK_type != 0 || MARK_create != 0 || MARK_pass != 0)
        {
            if (MARK_type == 0)
            {
                Pass_type = inputi("TYPE:");
                MARK_type += 1;
            }
            if (MARK_pass == 0 && MARK_create == 0)
                inputpass(Password, Create_len, Pass_type);
            if (MARK_pass == 0 && MARK_create != 0)
                createpass(Password, Create_len, Pass_type);
            if (MARK_del == 0)
                del(File_name, Name);
            add(File_name, Pass_type, Create_len, Name, Password);
            printf("EDIT %s\n", Name);
        }
        else
        {
            Pass *p = rpass(File_name);
            editpass(p, Name);
            wpass(File_name, p);
            freepass(p);
            p = NULL;
        }
    }
    if (MARK_create != 0 && MARK_add == 0)
    {
        createpass(Password, Create_len, Pass_type);
        printf("%s\n", Password);
    }
    if (MARK_add)
    {
        if (MARK_type == 0)
        {
            Pass_type = inputi("TYPE:");
            MARK_type += 1;
        }
        if (MARK_name == 0)
        {
            inputstr("NAME:", Name, NAME_LEN);
            MARK_name += 1;
        }
        if (MARK_pass == 0 && MARK_create == 0)
            inputpass(Password, Create_len, Pass_type);
        if (MARK_pass == 0 && MARK_create != 0)
            createpass(Password, Create_len, Pass_type);
        add(File_name, Pass_type, Create_len, Name, Password);
    }
    if (MARK_find != 0)
    {
        if (MARK_name == 0)
        {
            inputstr("NAME:", Name, NAME_LEN);
            MARK_name += 1;
        }
        find(File_name, Name, List_len);
    }
    sort(File_name);
    if (MARK_show != 0 && MARK_find == 0)
    {
        show(File_name, List_len, Pass_type, MARK_type);
    }
    return 0;
}