/**
 * 
 * 
*/
/*include-----------------------------------------------*/
#include "smf_pd.h"

/*static variable---------------------------------------*/
static unsigned long srands_next = 1;

/*const variable----------------------------------------*/
/*encode*/
const char *encodetable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
/*ctype*/
const char *alnumtable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char *alphatable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char *digittable = "0123456789";
const char *lowertable = "abcdefghijklmnopqrstuvwxyz";
const char *uppertable = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *puncttable = "!\"#$%&()*+,-./:;<=>?@[\\]^_`{|}~";
const char *graphtable = "!\"#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
const char *printtable = " !\"#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
const char *xdigittable = "0123456789ABCDEFabcdef";

/*static function header--------------------------------*/

/*
    功能:
    参数:
    返回:
*/
static void srands(unsigned long seed);

/*
    功能:
    参数:
    返回:
*/
static unsigned rands(void);

/*type*/

/*
    功能:
    参数:
    返回:
*/
static char pd_createch(Pd_type type);

/*
    功能:
    参数:
    返回:
*/
static Pd_type judgetype(const char *const str);

/*sort*/

/*
    功能:
    参数:
    返回:
*/
static size_t pd_parttion(cJSON *const root, size_t m, size_t n);

/*
    功能:
    参数:
    返回:
*/
static size_t pd_oneofthree(cJSON *const root, size_t m, size_t n);

/*static function---------------------------------------*/

static void srands(unsigned long seed)
{
    srands_next = seed;
}

static unsigned rands(void)
{
    srands_next = srands_next * 1103515245 + 12345;
    return (unsigned)((srands_next / 65536) % 32768);
}

/*type*/

static char pd_createch(Pd_type type)
{
    switch (type)
    {
    case PD_ALPHA:
        return alphatable[rand() % strlen(alphatable)];
    case PD_LOWER:
        return lowertable[rand() % strlen(lowertable)];
    case PD_UPPER:
        return uppertable[rand() % strlen(uppertable)];
    case PD_PUNCT:
        return puncttable[rand() % strlen(puncttable)];
    case PD_DIGIT:
        return digittable[rand() % strlen(digittable)];
    case PD_GRAPH:
        return graphtable[rand() % strlen(graphtable)];
    case PD_PRINT:
        return printtable[rand() % strlen(printtable)];
    case PD_XDIGIT:
        return xdigittable[rand() % strlen(xdigittable)];
    default:
        return alnumtable[rand() % strlen(alnumtable)];
    }
}

static Pd_type judgetype(const char *const str)
{
    size_t n = strlen(str);
    int flag = 0;
    Pd_type type;

    //print
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isprint(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_PRINT;

    //graph
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isgraph(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_GRAPH;

    //punct
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (ispunct(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_PUNCT;

    //alnum
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isalnum(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_ALNUM;

    //xdigit
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isxdigit(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_XDIGIT;

    //upper
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isupper(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_UPPER;

    //lower
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (islower(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_LOWER;

    //digit
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isdigit(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_DIGIT;

    //alpha
    flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isalpha(str[i]))
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        type = PD_ALPHA;

    return type;
}

/*sort*/

static size_t pd_oneofthree(cJSON *const root, size_t m, size_t n)
{
    size_t mid = (m + n) / 2;
    if (pd_namecmp(root, mid, m) > 0)
        pd_swap(root, mid, m);

    if (pd_namecmp(root, mid, n) > 0)
        pd_swap(root, mid, n);

    if (pd_namecmp(root, m, n) > 0)
        pd_swap(root, m, n);

    return m;
}

static size_t pd_parttion(cJSON *const root, size_t m, size_t n)
{
    size_t i = m,
           j = n + 1;

    Password pd;
    pd_getpd(root, pd_oneofthree(root, m, n), &pd);

    while (1)
    {
        while (pd_namecmp(root, i, m) < 0 && i < n)
        {
            i++;
        }

        while (pd_namecmp(root, j, m) > 0)
        {
            j--;
        }

        if (i >= j)
            break;

        pd_swap(root, i, j);
    }

    pd_set(root, m, j);

    pd_setpd(root, j, &pd);

    return j;
}

/*function----------------------------------------------*/

/*encode*/

size_t encrypt(char *const buff, const char *const pass)
{
    size_t table_n = strlen(encodetable);
    size_t pass_n = strlen(pass);
    size_t i = 0,
           j = 0;

    for (; i < PDLEN; i += 16)
    {
        char ch = '\0';
        int site = -1;

        if (j < pass_n)
        {
            ch = pass[j++];
            site = rand() % 4 * 4;
        }

        for (size_t k = 0; k < 16;)
        {
            int temp = k + i + 1;
            if (k == site)
            {
                srands(ch);
                temp = 0;
            }

            buff[i + k++] = encodetable[(rands() + temp) % table_n];
            buff[i + k++] = encodetable[(rands() + temp * 2) % table_n];
            buff[i + k++] = encodetable[(rands() + temp * 3) % table_n];
            buff[i + k++] = encodetable[(rands() + temp * 4) % table_n];
        }
    }
    buff[i] = '\0';

    return pass_n;
}

size_t dncrypt(const char *const buff, char *const pass)
{
    size_t table_n = strlen(encodetable);
    size_t i = 0,
           j = 0;

    for (; i < PDLEN; i += 16)
    {
        char ch = '\0';

        for (size_t k = 0; k < 16; k += 4)
        {
            for (char t = '!'; t <= '~'; t++)
            {
                srands(t);

                if (buff[i + k + 0] == encodetable[rands() % table_n] &&
                    buff[i + k + 1] == encodetable[rands() % table_n] &&
                    buff[i + k + 2] == encodetable[rands() % table_n] &&
                    buff[i + k + 3] == encodetable[rands() % table_n])
                {
                    ch = t;
                    break;
                }
            }

            if (ch != '\0')
                break;
        }

        pass[j++] = ch;
        if (ch == '\0')
            break;
    }

    pass[j] = '\0';

    return j;
}

/*lib*/

char *rfile(const char *const filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror(filename);
        return NULL;
    }

    char *str = (char *)malloc(sizeof(char));
    size_t i = 0;

    while (1)
    {
        char ch = fgetc(fp);
        if (feof(fp))
            break;

        str = realloc(str, i + 2);
        str[i++] = ch;
    }

    str[i] = '\0';

    fclose(fp);

    return str;
}

int wstr(const char *const filename, const char *const str)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror(filename);
        return -1;
    }

    fprintf(fp, "%s", str);

    fclose(fp);

    return 0;
}

int wpd(const char *const filename, cJSON *root)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror(filename);
        return -1;
    }

    if (root == NULL)
        return -2;

    fputc('[', fp);

    size_t len = cJSON_GetArraySize(root);

    for (size_t i = 0; i < len; i++)
    {
        cJSON *item = cJSON_GetArrayItem(root, i);

        char *itemstr = cJSON_PrintUnformatted(item);

        if (i)
            fputc(',', fp);
        fprintf(fp, "%s", itemstr);

        free(itemstr);
    }

    fputc(']', fp);

    fclose(fp);

    return 0;
}

cJSON *pd_read(const char *const dataname, int mark)
{
    char *str = rfile(dataname);
    if (str == NULL)
        return NULL;

    cJSON *root = cJSON_Parse(str);
    free(str);
    str = NULL;

    if (root == NULL)
        return NULL;

    cJSON *out = cJSON_CreateArray();

    size_t n = cJSON_GetArraySize(root);
    for (size_t i = 0; i < n; i++)
    {
        cJSON *item = cJSON_GetArrayItem(root, i);
        cJSON *itemobject = NULL;

        itemobject = cJSON_GetObjectItem(item, PD_NAME);
        if (itemobject == NULL)
            continue;
        char *itemname = itemobject->valuestring;

        itemobject = cJSON_GetObjectItem(item, PD_TYPE);
        if (itemobject == NULL)
            continue;
        int itemtype = itemobject->valueint;

        itemobject = cJSON_GetObjectItem(item, PD_PASSWORD);
        if (itemobject == NULL)
            continue;
        char *itempassword = itemobject->valuestring;

        if (mark)
        {
            str = calloc(PD_LEN + 1, sizeof(char));
            dncrypt(itempassword, str);
        }
        else
            str = itempassword;

        cJSON *newitem = cJSON_CreateObject();
        cJSON_AddNumberToObject(newitem, PD_TYPE, itemtype);
        cJSON_AddStringToObject(newitem, PD_NAME, itemname);
        cJSON_AddStringToObject(newitem, PD_PASSWORD, str);
        cJSON_AddItemToArray(out, newitem);

        if (mark)
            free(str);
        str = NULL;
    }

    cJSON_Delete(root);

    return out;
}

int json_objectin(const cJSON *const datajson, const char *const object, const char *const str)
{
    int high = cJSON_GetArraySize(datajson) - 1;
    int low = 0;

    while (high >= low)
    {
        int mid = (high + low) / 2;

        cJSON *item = cJSON_GetArrayItem(datajson, mid);

        cJSON *itemobject = cJSON_GetObjectItem(item, object);

        char *objectstr = itemobject->valuestring;

        if (strcmp(objectstr, str) > 0)
        {
            high = mid - 1;
        }
        else if (strcmp(objectstr, str) < 0)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

char *json_getobject(const cJSON *const root, const char *const object, size_t i)
{
    cJSON *item = cJSON_GetArrayItem(root, i);
    if (item == NULL)
        return NULL;

    cJSON *itemobject = cJSON_GetObjectItem(item, object);
    if (itemobject == NULL)
        return NULL;

    char *objectstr = itemobject->valuestring;

    return objectstr;
}

int json_objectcmp(const cJSON *const datajson, const char *const object, size_t i, size_t j)
{
    if (i == j)
        return 0;
    return strcmp(json_getobject(datajson, object, i), json_getobject(datajson, object, j));
}

int json_objectsite(const cJSON *const datajson, const char *const object, const char *const str)
{
    size_t n = cJSON_GetArraySize(datajson);
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(json_getobject(datajson, object, i), str) > 0)
            return i;
    }
    return -1;
}

/*name*/

int pd_namesite(const cJSON *const datajson, const char *const str)
{
    return json_objectsite(datajson, PD_NAME, str);
}

int pd_namecmp(const cJSON *const root, size_t i, size_t j)
{
    return json_objectcmp(root, PD_NAME, i, j);
}

/*pd valuable*/

void pd_getpd(const cJSON *const root, size_t i, Password *const pd)
{
    cJSON *itemi = cJSON_GetArrayItem(root, i);
    pd->type = cJSON_GetObjectItem(itemi, PD_TYPE)->valueint;
    pd->name = cJSON_GetObjectItem(itemi, PD_NAME)->valuestring;
    pd->key = cJSON_GetObjectItem(itemi, PD_PASSWORD)->valuestring;
}

void pd_setpd(cJSON *const root, size_t i, Password *const pd)
{
    cJSON *itemi = cJSON_GetArrayItem(root, i);
    cJSON_GetObjectItem(itemi, PD_TYPE)->valueint = pd->type;
    cJSON_GetObjectItem(itemi, PD_NAME)->valuestring = pd->name;
    cJSON_GetObjectItem(itemi, PD_PASSWORD)->valuestring = pd->key;
}

void pd_set(cJSON *const root, size_t i, size_t j)
{
    Password pd;
    pd_getpd(root, j, &pd);
    pd_setpd(root, i, &pd);
}

void pd_swap(cJSON *const root, size_t i, size_t j)
{
    if (i == j)
        return;

    Password pd;

    pd_getpd(root, i, &pd);

    pd_set(root, i, j);

    pd_setpd(root, j, &pd);

    return;
}

/*sort*/

void pd_insort(cJSON *const root, int low, int high)
{
    for (int i = low + 1; i < high; i++)
    {
        int pos = i - 1;

        Password pd;

        pd_getpd(root, i, &pd);

        while (strcmp(json_getobject(root, PD_NAME, pos), pd.name) > 0)
        {
            pd_set(root, pos + 1, pos);
            pos--;
            if (pos < low)
                break;
        }

        pd_setpd(root, pos + 1, &pd);
    }
}

void pd_qsort(cJSON *const root, size_t m, size_t n)
{
    size_t site = 0;
    if ((m - n) + 1 < 10)
    {
        pd_insort(root, m, n);
        return;
    }
    while (m < n)
    {
        site = pd_parttion(root, m, n);
        pd_qsort(root, m, site - 1);
        m = site + 1;
    }
}

/*pd_ppp*/

char *pd_create(Pd_type type, size_t n)
{
    char *str = calloc(n + 1, sizeof(char));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        str[i] = pd_createch(type);
    }
    str[n] = '\0';

    return str;
}

cJSON *pd_find(const char *const dataname, const char *const name)
{
    char *str = rfile(dataname);
    if (str == NULL)
        return NULL;

    cJSON *root = cJSON_Parse(str);
    free(str);
    str = NULL;

    if (root == NULL)
        root = cJSON_CreateArray();

    cJSON *out = cJSON_CreateArray();

    size_t n = cJSON_GetArraySize(root);
    for (size_t i = 0; i < n; i++)
    {
        cJSON *item = cJSON_GetArrayItem(root, i);
        cJSON *itemobject = NULL;

        itemobject = cJSON_GetObjectItem(item, PD_NAME);
        if (itemobject == NULL)
            continue;
        char *itemname = itemobject->valuestring;

        if (strstr(itemname, name) != NULL)
        {
            itemobject = cJSON_GetObjectItem(item, PD_TYPE);
            if (itemobject == NULL)
                continue;
            int itemtype = itemobject->valueint;

            itemobject = cJSON_GetObjectItem(item, PD_PASSWORD);
            if (itemobject == NULL)
                continue;
            char *itempassword = itemobject->valuestring;

            str = calloc(PD_LEN + 1, sizeof(char));
            dncrypt(itempassword, str);

            cJSON *newitem = cJSON_CreateObject();

            cJSON_AddNumberToObject(newitem, PD_TYPE, itemtype);
            cJSON_AddStringToObject(newitem, PD_NAME, itemname);
            cJSON_AddStringToObject(newitem, PD_PASSWORD, str);

            cJSON_AddItemToArray(out, newitem);

            free(str);
            str = NULL;
        }
    }

    cJSON_Delete(root);

    return out;
}

int pd_add(const char *const dataname, const char *const name, const char *const password)
{
    char *str = rfile(dataname);
    if (str == NULL)
        return -1;

    cJSON *root = cJSON_Parse(str);
    free(str);
    str = NULL;

    int i = -1;

    if (root == NULL)
        root = cJSON_CreateArray();
    else
    {
        i = json_objectin(root, PD_NAME, name);
    }

    str = calloc(PDLEN + 1, sizeof(char));
    encrypt(str, password);

    cJSON *item = cJSON_CreateObject();

    cJSON_AddNumberToObject(item, PD_TYPE, judgetype(password));
    cJSON_AddStringToObject(item, PD_NAME, name);
    cJSON_AddStringToObject(item, PD_PASSWORD, str);

    if (i > -1)
        cJSON_ReplaceItemInArray(root, i, item);
    else if ((i = pd_namesite(root, name)) > -1)
        cJSON_InsertItemInArray(root, i, item);
    else
        cJSON_AddItemToArray(root, item);

    free(str);
    str = NULL;

    wpd(dataname, root);

    cJSON_Delete(root);

    return 0;
}

int pd_del(const char *const dataname, const char *const name)
{
    char *str = rfile(dataname);
    if (str == NULL)
        return -1;

    cJSON *root = cJSON_Parse(str);
    free(str);
    str = NULL;

    int i = -1;

    if (root == NULL)
        return -2;
    else
    {
        i = json_objectin(root, PD_NAME, name);
    }

    if (i > -1)
    {
        cJSON_DeleteItemFromArray(root, i);

        wpd(dataname, root);
    }

    cJSON_Delete(root);

    if (i < 0)
        return -3;

    return 0;
}

int pd_edit(const char *const dataname, const char *const name, const char *const password)
{
    char *str = rfile(dataname);
    if (str == NULL)
        return -1;

    cJSON *root = cJSON_Parse(str);
    free(str);
    str = NULL;

    int i = -1;

    if (root == NULL)
        return -2;
    else
    {
        i = json_objectin(root, PD_NAME, name);
    }

    if (i > -1)
    {
        str = calloc(PDLEN + 1, sizeof(char));
        encrypt(str, password);

        cJSON *newitem = cJSON_CreateObject();
        cJSON_AddNumberToObject(newitem, PD_TYPE, judgetype(password));
        cJSON_AddStringToObject(newitem, PD_NAME, name);
        cJSON_AddStringToObject(newitem, PD_PASSWORD, str);

        cJSON_ReplaceItemInArray(root, i, newitem);

        free(str);
        str = NULL;

        wpd(dataname, root);
    }

    cJSON_Delete(root);

    if (i < 0)
        return -3;

    return 0;
}

int pd_derive(const char *const dataname, const char *const outdataname)
{
    if (strcmp(dataname, outdataname) == 0)
        return -5;

    cJSON *datajson = pd_read(dataname, 1);
    if (datajson == NULL)
        return -1;

    wpd(outdataname, datajson);

    cJSON_Delete(datajson);

    return 0;
}

int pd_import(const char *const dataname, const char *const indataname, int mark)
{
    if (strcmp(dataname, indataname) == 0)
        return -5;

    cJSON *datajson = pd_read(dataname, 0);
    if (datajson == NULL)
        return -1;

    cJSON *injson = pd_read(indataname, 0);
    if (injson == NULL)
        return -4;

    size_t n = cJSON_GetArraySize(injson);
    size_t count = 0;

    printf("\r%zu:\n", n);

    for (size_t i = 0; i < n; i++)
    {
        cJSON *item = cJSON_GetArrayItem(injson, i);
        cJSON *itemobject = NULL;

        itemobject = cJSON_GetObjectItem(item, PD_NAME);
        if (itemobject == NULL)
            continue;
        char *name = itemobject->valuestring;

        itemobject = cJSON_GetObjectItem(item, PD_PASSWORD);
        if (itemobject == NULL)
            continue;
        char *password = itemobject->valuestring;

        int j = json_objectin(datajson, PD_NAME, name);
        if (j > -1) //name in datajson
        {
            if (mark) //don't delete
                continue;
        }

        if (strlen(password) <= PD_LEN)
        {
            char *key = calloc(PDLEN + 1, sizeof(char));
            encrypt(key, password);

            cJSON *newitem = cJSON_CreateObject();

            cJSON_AddNumberToObject(newitem, PD_TYPE, judgetype(password));
            cJSON_AddStringToObject(newitem, PD_NAME, name);
            cJSON_AddStringToObject(newitem, PD_PASSWORD, key);

            if (j > -1)
                cJSON_ReplaceItemInArray(datajson, j, newitem);
            else if ((j = pd_namesite(datajson, name)) > -1)
                cJSON_InsertItemInArray(datajson, j, newitem);
            else
                cJSON_AddItemToArray(datajson, newitem);

            free(key);
            key = NULL;

            printf("\r%zu", ++count);
        }
        else
            continue;
    }

    if (count)
        putchar('\n');

    wpd(dataname, datajson);

    cJSON_Delete(injson);

    cJSON_Delete(datajson);

    return 0;
}

/*end---------------------------------------------------*/