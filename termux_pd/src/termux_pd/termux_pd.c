#include <limits.h>
#include "cJSON.h"
#include "termux_api.h"
#include "smf_pd.h"

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

int finger_auth(void)
{
    int mark = -1;
    char *result = NULL;

    result = termux_fingerprint("验证指纹", NULL, NULL, "取消");
    cJSON *json = cJSON_Parse(result);
    free(result);
    result = NULL;

    cJSON *item = cJSON_GetObjectItem(json, "auth_result");
    if (strcmp(item->valuestring, "AUTH_RESULT_SUCCESS") == 0)
        mark = 1;
    if (strcmp(item->valuestring, "AUTH_RESULT_FAILURE") == 0)
        mark = 0;

    cJSON_Delete(json);
    json = NULL;

    return mark;
}

int json_code(const char *const result)
{
    cJSON *json = cJSON_Parse(result);
    cJSON *item = cJSON_GetObjectItem(json, "code");

    if (item == NULL)
        return INT_MIN;

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

int json_code_index(const char *const result, int code)
{
    cJSON *json = cJSON_Parse(result);
    cJSON *item = cJSON_GetObjectItem(json, "code");

    if (item == NULL)
        return INT_MIN;

    int num = -1;

    if (item->valueint == code)
    {
        cJSON *itemindex = cJSON_GetObjectItem(json, "index");

        if (itemindex == NULL)
            return INT_MIN;

        num = itemindex->valueint;
    }

    cJSON_Delete(json);
    json = NULL;

    return num;
}

cJSON *json_code_values(const char *const result, int code)
{
    cJSON *json = cJSON_Parse(result);
    cJSON *item = cJSON_GetObjectItem(json, "code");

    if (item == NULL)
        return NULL;

    cJSON *out = NULL;

    if (item->valueint == code)
    {
        cJSON *object = cJSON_GetObjectItem(json, "values");
        if (object == NULL)
            return NULL;

        out = cJSON_CreateArray();
        size_t n = cJSON_GetArraySize(object);

        for (size_t i = 0; i < n; i++)
        {
            item = cJSON_GetArrayItem(object, i);
            cJSON *itemtext = cJSON_GetObjectItem(item, "text");
            if (itemtext == NULL)
                continue;

            cJSON *newitem = cJSON_CreateObject();
            cJSON_AddStringToObject(newitem, "text", itemtext->valuestring);
            cJSON_AddItemToArray(out, newitem);
        }
    }

    cJSON_Delete(json);
    json = NULL;

    return out;
}

char *text_input(const char *const t, const char *const i, const char *const op)
{
    char *str = NULL;
    char *result = termux_dialog_text(t, i, op);

    str = json_code_text(result, -1);

    if (str != NULL && strncmp(str, "", sizeof("")) == 0)
    {
        free(str);
        tapi_window("提示", "请输入内容!");
        str = text_input(t, i, op);
    }

    free(result);

    return str;
}

char *json_getv_name(const cJSON *const json)
{
    char *str = NULL;

    size_t n = cJSON_GetArraySize(json);
    for (size_t i = 0; i < n; i++)
    {
        cJSON *item = cJSON_GetArrayItem(json, i);

        cJSON *itemname = cJSON_GetObjectItem(item, "name");
        if (itemname == NULL)
            continue;

        char *name = itemname->valuestring;
        if (name == NULL)
            continue;

        if (str == NULL)
            str = calloc(1, sizeof(char));

        str = cmdcat(str, name);
        str = cmdcat(str, ",");
    }

    return str;
}

char *getv_name(const char *const filename)
{
    char *result = rfile(filename);
    cJSON *json = cJSON_Parse(result);
    free(result);

    char *str = json_getv_name(json);
    cJSON_Delete(json);

    return str;
}

char *json_show_key(const cJSON *const json, const char *const name)
{
    int i = json_objectin(json, PD_NAME, name);

    if (i < 0)
        return NULL;

    return json_getobject(json, PD_PASSWORD, i);
}

char *show_key(const char *const filename, const char *const name)
{
    char *text = rfile(filename);
    cJSON *root = cJSON_Parse(text);
    free(text);

    text = json_show_key(root, name);

    if (text == NULL)
        return NULL;

    char *key = calloc(PD_LEN + 1, sizeof(char));

    dncrypt(text, key);

    cJSON_Delete(root);

    return key;
}

/**
 * 
*/

void edit_add(const char *const filename)
{
    Password pd;
    char buff[BUFSIZ] = {};

    pd.name = text_input("标识", "输入标识!", NULL);
    if (pd.name == NULL)
        return;

    pd.key = text_input("密码", "输入密码!", "p");
    if (pd.key == NULL)
        return;

    sprintf(buff, "标识:%s\n密码:%s", pd.name, pd.key);

    char *result = termux_dialog_confirm("确认", buff);
    char *text = json_code_text(result, 0);
    free(result);

    if (text != NULL)
    {
        if (strncmp(text, "yes", sizeof("yes")) == 0)
        {
            pd_add(filename, pd.name, pd.key);
        }
        free(text);
    }

    free(pd.key);
    free(pd.name);

    return;
}

void edit_del(const char *const filename)
{
    char *namev = getv_name(filename);
    if (namev == NULL)
    {
        tapi_window("提示", "数据库没有数据!");
        return;
    }

    char *result = termux_dialog_checkbox("删除", namev);
    free(namev);

    cJSON *json = json_code_values(result, -1);
    free(result);

    size_t n = cJSON_GetArraySize(json);
    for (size_t i = 0; i < n; i++)
    {
        cJSON *item = cJSON_GetArrayItem(json, i);
        cJSON *itemtext = cJSON_GetObjectItem(item, "text");
        if (itemtext == NULL)
            continue;

        char *name = itemtext->valuestring;
        result = termux_dialog_confirm("确认删除", name);
        char *text = json_code_text(result, 0);
        free(result);

        if (text != NULL)
        {
            if (strncmp(text, "yes", sizeof("yes")) == 0)
            {
                pd_del(filename, name);
            }

            free(text);
        }
    }

    cJSON_Delete(json);

    return;
}

void edit_mod(const char *const filename)
{
    char *namev = getv_name(filename);
    if (namev == NULL)
    {
        tapi_window("提示", "数据库没有数据!");
        return;
    }

    char *result = termux_dialog_radio("编辑", namev);
    free(namev);

    Password pd;
    pd.name = json_code_text(result, -1);
    free(result);

    if (pd.name != NULL)
    {
        if (strncmp(pd.name, "", sizeof("")) == 0)
        {
            free(pd.name);
            tapi_window("提示", "请选择标识!");
            return edit_mod(filename);
        }

        pd.key = text_input(pd.name, "请输入密码!", "p");
        if (pd.key == NULL)
            return;

        char buff[BUFSIZ] = {};
        char *oldname = show_key(filename, pd.name);
        sprintf(buff, "标识:%s\n旧密码:%s\n新密码:%s", pd.name, oldname, pd.key);
        free(oldname);

        result = termux_dialog_confirm("确认修改", buff);
        char *text = json_code_text(result, 0);
        if (text != NULL)
        {
            if (strncmp(text, "yes", sizeof("yes")) == 0)
            {
                pd_edit(filename, pd.name, pd.key);
            }
            free(text);
        }
        free(pd.name);
        free(pd.key);
    }

    return;
}

void edit_create()
{
    char *result = termux_dialog_spinner("选择密码类型", "字母数字,字母,数字,小写字母,大写字母,标点,字符,打印字符,十六进制");
    int type = json_code_index(result, -1);
    free(result);

    if (type < 0)
        return;

    result = termux_dialog_counter("密码长度", "1,64,16");
    char *str = json_code_text(result, -1);
    free(result);

    if (str == NULL)
        return;

    int len = atoi(str);
    free(str);

    char *key = pd_create(type, len);
    result = termux_dialog_confirm("是否复制", key);
    str = json_code_text(result, 0);
    free(result);

    if (str != NULL)
    {
        if (strncmp(str, "yes", sizeof("yes")) == 0)
            termux_clipboard_set(key);
        free(str);
    }

    return;
}

void query_search(const char *const filename)
{
    char *str = getv_name(filename);
    if (str == NULL)
    {
        tapi_window("提示", "数据库没有数据!");
        return;
    }
    else
        free(str);

    char *namev = text_input("搜索", "输入标识!", NULL);
    if (namev != NULL)
    {
        cJSON *json = pd_find(filename, namev);
        free(namev);

        namev = json_getv_name(json);
        while (namev != NULL)
        {
            str = termux_dialog_radio("搜索结果", namev);
            char *name = NULL;
            name = json_code_text(str, -1);
            free(str);

            if (name != NULL)
            {
                if (strncmp(name, "", sizeof("")) != 0)
                {
                    char *key = json_show_key(json, name);

                    char buff[BUFSIZ] = {};
                    sprintf(buff, "标识:%s\n密码:%s", name, key);
                    str = termux_dialog_confirm("是否复制", buff);

                    char *text = json_code_text(str, 0);
                    free(str);

                    if (text != NULL)
                    {
                        if (strncmp(text, "yes", sizeof("yes")) == 0)
                            termux_clipboard_set(key);
                        free(text);
                    }

                    free(key);
                }
                else
                {
                    tapi_window("提示", "请选择标识!");
                }
                free(name);
            }
            else
            {
                break;
            }
        }
        if (namev == NULL)
            tapi_window("提示", "标识未找到");

        cJSON_Delete(json);
    }

    return;
}

void query_find(const char *const filename)
{
    char *namev = getv_name(filename);
    if (namev == NULL)
    {
        tapi_window("提示", "数据库没有数据!");
        return;
    }

    while (namev != NULL)
    {
        char *result = termux_dialog_radio("查找", namev);
        char *name = json_code_text(result, -1);
        free(result);

        if (name != NULL)
        {
            if (strncmp(name, "", sizeof("")) != 0)
            {
                char *key = show_key(filename, name);

                char buff[BUFSIZ] = {};
                sprintf(buff, "标识:%s\n密码:%s", name, key);
                result = termux_dialog_confirm("是否复制", buff);

                char *text = json_code_text(result, 0);
                free(result);

                if (text != NULL)
                {
                    if (strncmp(text, "yes", sizeof("yes")) == 0)
                        termux_clipboard_set(key);
                    free(text);
                }

                free(key);
            }
            else
            {
                tapi_window("提示", "请选择标识!");
            }
            free(name);
        }
        else
        {
            break;
        }
    }
    if (namev != NULL)
        free(namev);

    return;
}

void tdata_derive(const char *const filename)
{
    char *outname = text_input("文件名", "输入导出文件名", NULL);
    if (outname == NULL)
        return;

    int flag = pd_derive(filename, outname);

    if (flag == 0)
        tapi_window("提示", "导出成功!");

    return;
}

void tdata_import(const char *const filename)
{
    long t = time(NULL);
    char buff1[64] = {};
    char buff2[64] = {};
    sprintf(buff1, "%ld.tmp", t);
    termux_storage_get(buff1);

    size_t i = 0;
    for (; i < 60; i++)
    {
        sleep(1);
        FILE *fp = fopen(buff1, "r");
        if (fp)
        {
            fclose(fp);
            break;
        }
    }

    if (i == 60)
    {
        tapi_window("提示", "导入超时");
        return;
    }

    int flag = pd_import(filename, buff1, 1);
    sprintf(buff2, "rm -rf %s", buff1);
    cmdno(buff2);

    if (flag == 0)
        tapi_window("提示", "导入成功");

    return;
}

void tpd_edit(const char *const filename)
{
    while (1)
    {
        char *result = termux_dialog_sheet("选择", "添加,删除,修改,生成");
        int mark = json_code_index(result, 0);
        free(result);
        switch (mark)
        {
        case 0:
            edit_add(filename);
            break;
        case 1:
            edit_del(filename);
            break;
        case 2:
            edit_mod(filename);
            break;
        case 3:
            edit_create();
            break;
        default:
            return;
        }
    }
}

void tpd_query(const char *const filename)
{
    while (1)
    {
        char *result = termux_dialog_sheet("选择", "搜索,查找");
        int mark = json_code_index(result, 0);
        free(result);
        switch (mark)
        {
        case 0:
            query_search(filename);
            break;
        case 1:
            query_find(filename);
            break;
        default:
            return;
        }
    }
}

void tpd_data(const char *const filename)
{
    while (1)
    {
        char *result = termux_dialog_sheet("选择", "导入,导出");
        int mark = json_code_index(result, 0);
        free(result);
        switch (mark)
        {
        case 0:
            tdata_import(filename);
            break;
        case 1:
            tdata_derive(filename);
            break;
        default:
            return;
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    char *filename = PD_DATANAME;
    if (argc > 1)
        filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        wstr(filename, "[]");
    else
        fclose(fp);

    if (finger_auth() == 0)
    {
        printf("身份验证失败!\n");
        exit(0);
    }

    while (1)
    {
        char *result = termux_dialog_sheet("选择", "查询,编辑,数据");
        int mark = json_code_index(result, 0);
        free(result);

        switch (mark)
        {
        case 0:
            tpd_query(filename);
            break;
        case 1:
            tpd_edit(filename);
            break;
        case 2:
            tpd_data(filename);
            break;
        default:
            return 0;
        }
    }
}
