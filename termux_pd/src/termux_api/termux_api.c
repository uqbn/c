/**
 * 作者:苏梦凡
 * target:termux-api
 * **/
/*include-------------------------------------------*/
#include "termux_api.h"

/*define--------------------------------------------*/

/*termux-audio-info---------------------------------*/

char *termux_audio_info(void)
{
    return cmd("termux-audio-info");
}

/*termux-battery-status-----------------------------*/

char *termux_battery_status(void)
{
    return cmd("termux-battery-status");
}

/*termux-brightness-------------------------------*/

void termux_brightness(int num)
{
    char command[BUFSIZ] = {};

    if (num > -1 && num < 256)
        sprintf(command, "termux-brightness %d", num);
    else
        sprintf(command, "termux-brightness auto");

    cmdno(command);

    return;
}

/*termux-call-log---------------------------------*/

char *termux_call_log(int l, int o)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-call-log");

    if (l > 0)
    {
        sprintf(buff, " \\\n-l %d", l);
        command = cmdcat(command, buff);
    }

    if (o > -1)
    {
        sprintf(buff, " \\\n-o %d", o);
        command = cmdcat(command, buff);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*termux-camera-----------------------------------*/

char *termux_camera_info(void)
{
    return cmd("termux-camera-info");
}

void termux_camera_photo(const char *const filename, int c)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-camera-photo");

    if (c > -1)
    {
        sprintf(buff, " \\\n-c %d", c);
        command = cmdcat(command, buff);
    }

    if (filename != NULL)
    {
        char *cmdin = NULL;

        cmdin = cmdstr(filename);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);
    }

    free(command);

    return;
}

/*termux-clipboard----------------------------------*/

char *termux_clipboard_get(void)
{
    return cmd("termux-clipboard-get");
}

void termux_clipboard_set(const char *const str)
{
    if (str != NULL)
    {
        char *command = (char *)calloc(1, sizeof(char));

        command = cmdcat(command, "termux-clipboard-set \\\n");

        char *cmdin = cmdstr(str);

        command = cmdcat(command, "'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);

        free(command);
    }

    return;
}

/*termux-contact-list--------------------------------*/

char *termux_contact_list(void)
{
    return cmd("termux-contact-list");
}

/*termux-dialog--------------------------------------*/

char *termux_dialog_time(const char *const t)
{
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-dialog time");

    if (t != NULL)
    {
        char *cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_text(const char *const t, const char *const i, const char *const op)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog text");

    if (op != NULL)
    {
        command = cmdcat(command, " -");
        command = cmdcat(command, op);
    }

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (i != NULL)
    {
        cmdin = cmdstr(i);

        command = cmdcat(command, " \\\n-i '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_speech(const char *const t, const char *const i)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog speech");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (i != NULL)
    {
        cmdin = cmdstr(i);

        command = cmdcat(command, " \\\n-i '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_spinner(const char *const t, const char *const v)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog spinner");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (v != NULL)
    {
        cmdin = cmdstr(v);

        command = cmdcat(command, " \\\n-v '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_sheet(const char *const t, const char *const v)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog sheet");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (v != NULL)
    {
        cmdin = cmdstr(v);

        command = cmdcat(command, " \\\n-v '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_radio(const char *const t, const char *const v)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog radio");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (v != NULL)
    {
        cmdin = cmdstr(v);

        command = cmdcat(command, " \\\n-v '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_date(const char *const t, const char *const d)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog date");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (d != NULL)
    {
        cmdin = cmdstr(d);

        command = cmdcat(command, " \\\n-d '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_counter(const char *const t, const char *const r)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog counter");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }
    if (r != NULL)
    {
        cmdin = cmdstr(r);

        command = cmdcat(command, " \\\n-r '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_checkbox(const char *const t, const char *const v)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog checkbox");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }
    if (v != NULL)
    {
        cmdin = cmdstr(v);

        command = cmdcat(command, " \\\n-v '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

char *termux_dialog_confirm(const char *const t, const char *const i)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-dialog confirm");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (i != NULL)
    {
        cmdin = cmdstr(i);

        command = cmdcat(command, " \\\n-i '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*download-------------------------------------------*/

void termux_download(const char *const url, const char *const t, const char *const d)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-download");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (d != NULL)
    {
        cmdin = cmdstr(d);

        command = cmdcat(command, " \\\n-d '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (url != NULL)
    {
        cmdin = cmdstr(url);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);
    }

    return;
}

/*fingerprint-----------------------------------------*/

char *termux_fingerprint(const char *const t, const char *const d, const char *const s, const char *const c)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-fingerprint");

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (d != NULL)
    {
        cmdin = cmdstr(d);

        command = cmdcat(command, " \\\n-d '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (s != NULL)
    {
        cmdin = cmdstr(s);

        command = cmdcat(command, " \\\n-s '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (c != NULL)
    {
        cmdin = cmdstr(c);

        command = cmdcat(command, " \\\n-c '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*termux-infrared-------------------------------------*/

char *termux_infrared_frequencies(void)
{
    return cmd("termux-infrared-frequencies");
}

char *termux_infrared_transmit(int f, int num)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-infrared-transmit");

    sprintf(buff, " \\\n-f '%d' '%d'", f, num);
    command = cmdcat(command, buff);

    char *result = cmd(command);

    free(command);

    return result;
}

/*localtion-------------------------------------------*/

char *termux_location(const char *const p, const char *const r)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-location");

    if (p != NULL)
    {
        cmdin = cmdstr(p);

        command = cmdcat(command, " \\\n-p '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (r != NULL)
    {
        cmdin = cmdstr(r);

        command = cmdcat(command, " \\\n-r '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*media-----------------------------------------------*/

char *termux_media_scan(const char *const filename, const char *const op)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-media-scan");

    if (op != NULL)
    {
        command = cmdcat(command, " -");
        command = cmdcat(command, op);
    }

    if (filename != NULL)
    {
        cmdin = cmdstr(filename);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        char *result = cmd(command);

        free(command);

        return result;
    }

    free(command);

    return NULL;
}

char *termux_media_player(const char *const op, const char *const filename)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-media-player");

    if (op != NULL)
    {
        command = cmdcat(command, " ");
        command = cmdcat(command, op);
    }

    if (filename != NULL)
    {
        cmdin = cmdstr(filename);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*termux-microphone-record---------------------------------------*/

char *termux_microphone_record(const Termux_record *const struct_op, const char *const op)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-microphone-record");

    if (op != NULL)
    {
        sprintf(buff, " -%s", op);
        command = cmdcat(command, buff);
    }

    if (struct_op != NULL)
    {
        if (struct_op->file != NULL)
        {
            cmdin = cmdstr(struct_op->file);

            command = cmdcat(command, " \\\n-f '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (struct_op->limit > -1)
        {
            sprintf(buff, " \\\n-l %d", struct_op->limit);
            command = cmdcat(command, buff);
        }

        if (struct_op->encoder != NULL)
        {
            cmdin = cmdstr(struct_op->encoder);

            command = cmdcat(command, " \\\n-e '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (struct_op->bitrate > 0)
        {
            sprintf(buff, " \\\n-b %d", struct_op->bitrate);
            command = cmdcat(command, buff);
        }

        if (struct_op->rate > 0)
        {
            sprintf(buff, " \\\n-r %d", struct_op->rate);
            command = cmdcat(command, buff);
        }

        if (struct_op->count > 0)
        {
            sprintf(buff, " \\\n-c %d", struct_op->count);
            command = cmdcat(command, buff);
        }
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*termux-notification--------------------------------------------*/

void termux_notification(const Termux_noti *const op)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-notification");

    if (op != NULL)
    {
        if (op->alert_once)
            command = cmdcat(command, " \\\n--alert-once");

        if (op->ongoing)
            command = cmdcat(command, " \\\n--ongoing");

        if (op->sound)
            command = cmdcat(command, " \\\n--sound");

        if (op->media_previous)
            command = cmdcat(command, " \\\n--media-previous");

        if (op->media_next)
            command = cmdcat(command, " \\\n--media-next");

        if (op->media_play)
            command = cmdcat(command, " \\\n--media-play");

        if (op->media_pause)
            command = cmdcat(command, " \\\n--media-pause");

        if (op->content != NULL)
        {
            cmdin = cmdstr(op->content);

            command = cmdcat(command, " \\\n--content '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->action != NULL)
        {
            cmdin = cmdstr(op->action);

            command = cmdcat(command, " \\\n--action '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->button1 != NULL)
        {
            cmdin = cmdstr(op->button1);

            command = cmdcat(command, " \\\n--button1 '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->button1_action != NULL)
        {
            cmdin = cmdstr(op->button1_action);

            command = cmdcat(command, " \\\n--button1-action '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->button2 != NULL)
        {
            cmdin = cmdstr(op->button2);

            command = cmdcat(command, " \\\n--button2 '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->button2_action != NULL)
        {
            cmdin = cmdstr(op->button2_action);

            command = cmdcat(command, " \\\n--button2-action '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->button3 != NULL)
        {
            cmdin = cmdstr(op->button3);

            command = cmdcat(command, " \\\n--button3 '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->button3_action != NULL)
        {
            cmdin = cmdstr(op->button3_action);

            command = cmdcat(command, " \\\n--button3-action '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->group != NULL)
        {
            cmdin = cmdstr(op->group);

            command = cmdcat(command, " \\\n--group '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->image_path != NULL)
        {
            cmdin = cmdstr(op->image_path);

            command = cmdcat(command, " \\\n--image-path '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->led_color != NULL)
        {
            cmdin = cmdstr(op->led_color);

            command = cmdcat(command, " \\\n--led-color '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->on_delete != NULL)
        {
            cmdin = cmdstr(op->on_delete);

            command = cmdcat(command, " \\\n--on-delete '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->priority != NULL)
        {
            cmdin = cmdstr(op->priority);

            command = cmdcat(command, " \\\n--priority '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->title != NULL)
        {
            cmdin = cmdstr(op->title);

            command = cmdcat(command, " \\\n--title '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->vibrate != NULL)
        {
            cmdin = cmdstr(op->vibrate);

            command = cmdcat(command, " \\\n--vibrate '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->type != NULL)
        {
            cmdin = cmdstr(op->type);

            command = cmdcat(command, " \\\n--type '");
            command = cmdcat(command, cmdin);
            command = cmdcat(command, "'");

            free(cmdin);
        }

        if (op->id > 0)
        {
            sprintf(buff, " \\\n--id %d", op->id);
            command = cmdcat(command, buff);
        }

        if (op->led_off > 0)
        {
            sprintf(buff, " \\\n--led-off %d", op->led_off);
            command = cmdcat(command, buff);
        }

        if (op->led_on > 0)
        {
            sprintf(buff, " \\\n--led-on %d", op->led_on);
            command = cmdcat(command, buff);
        }
    }

    cmdno(command);

    free(command);

    return;
}

char *termux_notification_list(void)
{
    return cmd("termux-notification-list");
}

void termux_notification_remove(int id)
{
    if (id > -1)
    {
        char command[BUFSIZ] = {};

        sprintf(command, "termux-notification-remove %d", id);

        cmdno(command);
    }

    return;
}

/*termux-open-----------------------------------------------*/

void termux_open(const char *const path_url, int select, const char *const type)
{
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-open");

    if (select == 1)
        command = cmdcat(command, " \\\n--send");
    else if (select == 2)
        command = cmdcat(command, " \\\n--chooser");
    else
        command = cmdcat(command, " \\\n--view");

    if (type != NULL)
    {
        command = cmdcat(command, " \\\n--content-type ");
        command = cmdcat(command, type);
    }

    if (path_url != NULL)
    {
        command = cmdcat(command, " '");

        char *cmdin = NULL;

        cmdin = cmdstr(path_url);
        command = cmdcat(command, cmdin);
        free(cmdin);

        command = cmdcat(command, "'");

        cmdno(command);
    }

    free(command);

    return;
}

void termux_open_url(const char *const url)
{
    if (url != NULL)
    {
        char *command = (char *)calloc(1, sizeof(char));
        char *cmdin = NULL;

        command = cmdcat(command, "termux-open-url \\\n'");

        cmdin = cmdstr(url);

        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);

        free(command);
    }
    return;
}

/*termux-sensor--------------------------------------------*/

char *termux_sensor(const char *const s, int ms, int n, const char *const op)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-sensor");

    if (op != NULL)
    {
        sprintf(buff, " -%s", op);
        command = cmdcat(command, buff);
    }

    if (s != NULL)
    {
        cmdin = cmdstr(s);

        command = cmdcat(command, " \\\n-s '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (ms > 0)
    {
        sprintf(buff, " \\\n-d %d", ms);
        command = cmdcat(command, buff);
    }

    if (n > 0)
    {
        sprintf(buff, " \\\n-n %d", n);
        command = cmdcat(command, buff);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*termux-sms--------------------------------------------*/

char *termux_sms_list(const char *const t, int l, int o, const char *const op)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-sms-list");

    if (op != NULL)
    {
        sprintf(buff, " -%s", op);
        command = cmdcat(command, buff);
    }

    if (t != NULL)
    {
        cmdin = cmdstr(t);

        command = cmdcat(command, " \\\n-t '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (l > 0)
    {
        sprintf(buff, " \\\n-l %d", l);
        command = cmdcat(command, buff);
    }

    if (o > -1)
    {
        sprintf(buff, " \\\n-o %d", o);
        command = cmdcat(command, buff);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

void termux_sms_send(const char *const numbers, const char *const text)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-sms-send");

    if (numbers != NULL)
    {
        cmdin = cmdstr(numbers);

        command = cmdcat(command, " \\\n-n '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (text != NULL)
    {
        cmdin = cmdstr(text);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);
    }

    free(command);

    return;
}

/*termux-speech-to-text----------------------------------*/

char *termux_speech_to_text(void)
{
    return cmd("termux-speech-to-text");
}

/*termux-storage-get------------------------------------*/

void termux_storage_get(const char *const filename)
{
    char *command = (char *)calloc(1, sizeof(char));

    if (filename != NULL)
    {
        char *cmdin = NULL;

        command = cmdcat(command, "termux-storage-get \\\n'");

        cmdin = cmdstr(filename);
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);
    }

    free(command);

    return;
}

/*termux-telephony--------------------------------------*/

void termux_telephony_call(const char *const num)
{
    char *command = (char *)calloc(1, sizeof(char));

    if (num != NULL)
    {
        char *cmdin = NULL;
        cmdin = cmdstr(num);

        command = cmdcat(command, "termux-telephony-call \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);
    }

    free(command);

    return;
}

char *termux_telephony_cellinfo(void)
{
    return cmd("termux-telephony-cellinfo");
}

char *termux_telephony_deviceinfo(void)
{
    return cmd("termux-telephony-deviceinfo");
}

/*torch----------------------------------------------*/

void termux_toast(const char *const text, const char *const c, const char *const b, const char *const g, int s)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-toast");

    if (s)
        command = cmdcat(command, " -s");

    if (c != NULL)
    {
        cmdin = cmdstr(c);

        command = cmdcat(command, " \\\n-c '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (b != NULL)
    {
        cmdin = cmdstr(b);

        command = cmdcat(command, " \\\n-b '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (g != NULL)
    {
        cmdin = cmdstr(g);

        command = cmdcat(command, " \\\n-g '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (text != NULL)
    {
        cmdin = cmdstr(text);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);

        cmdno(command);
    }

    free(command);

    return;
}

/*torch----------------------------------------------*/

void termux_torch(int on)
{
    if (on)
        cmdno("termux-torch on");
    else
        cmdno("termux-torch off");

    return;
}

/*tts-----------------------------------------------*/

char *termux_tts_engines(void)
{
    return cmd("termux-tts-engines");
}

void termux_tts_speak(const Termux_tts *const op, const char *const text)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-tts-speak");

    if (op != NULL)
    {
        if (op->engines != NULL)
        {
            command = cmdcat(command, " \\\n-e '");

            cmdin = cmdstr(op->engines);
            command = cmdcat(command, cmdin);
            free(cmdin);

            command = cmdcat(command, "'");
        }

        if (op->language != NULL)
        {
            command = cmdcat(command, " \\\n-l '");

            cmdin = cmdstr(op->language);
            command = cmdcat(command, cmdin);
            free(cmdin);

            command = cmdcat(command, "'");
        }

        if (op->region != NULL)
        {
            command = cmdcat(command, " \\\n-n '");

            cmdin = cmdstr(op->region);
            command = cmdcat(command, cmdin);
            free(cmdin);

            command = cmdcat(command, "'");
        }

        if (op->variant != NULL)
        {
            command = cmdcat(command, " \\\n-v '");

            cmdin = cmdstr(op->variant);
            command = cmdcat(command, cmdin);
            free(cmdin);

            command = cmdcat(command, "'");
        }

        if (op->stream != NULL)
        {
            command = cmdcat(command, " \\\n-s '");

            cmdin = cmdstr(op->stream);
            command = cmdcat(command, cmdin);
            free(cmdin);

            command = cmdcat(command, "'");
        }

        if (op->pitch > 0)
        {
            sprintf(buff, " \\\n-e %d", op->pitch);
            command = cmdcat(command, buff);
        }

        if (op->rate > 0)
        {
            sprintf(buff, " \\\n-r %d", op->rate);
            command = cmdcat(command, buff);
        }
    }

    if (text != NULL)
    {
        cmdin = cmdstr(text);
        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");
        free(cmdin);

        command = cmdcat(command, buff);

        cmdno(command);
    }

    free(command);

    return;
}

/*usb-----------------------------------------------*/

char *termux_usb(const char *const path, const char *const e, const char *const op)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-usb");

    if (op != NULL)
    {
        sprintf(buff, " -%s", op); // l r
        command = cmdcat(command, buff);
    }

    if (e != NULL)
    {
        cmdin = cmdstr(e);

        command = cmdcat(command, " \\\n-e '");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    if (path != NULL)
    {
        cmdin = cmdstr(path);

        command = cmdcat(command, " \\\n'");
        command = cmdcat(command, cmdin);
        command = cmdcat(command, "'");

        free(cmdin);
    }

    char *result = cmd(command);

    free(command);

    return result;
}

/*vibrate--------------------------------------------*/

void termux_vibrate(int ms, int mute)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-vibrate");

    if (mute)
    {
        command = cmdcat(command, " -f");
    }

    if (ms > 0)
    {
        sprintf(buff, " \\\n-d %d", ms);
        command = cmdcat(command, buff);

        cmdno(command);
    }

    free(command);

    return;
}

/*volume----------------------------------------------*/

void termux_volume(const char *const s, int v)
{
    char buff[BUFSIZ] = {};
    char *command = (char *)calloc(1, sizeof(char));

    command = cmdcat(command, "termux-volume");

    if (s != NULL && v > -1)
    {
        sprintf(buff, " '%s' %d", s, v);
        command = cmdcat(command, buff);
    }

    cmdno(command);

    free(command);

    return;
}

/*wallpaper-------------------------------------------*/

void termux_wallpaper(const char *const file_url, int screen)
{
    char *command = (char *)calloc(1, sizeof(char));
    char *cmdin = NULL;

    command = cmdcat(command, "termux-wallpaper");

    if (screen)
    {
        command = cmdcat(command, " -l");
    }

    if (strstr(file_url, "http") != NULL)
        command = cmdcat(command, " \\\n-u");
    else
        command = cmdcat(command, " \\\n-f");

    if (file_url != NULL)
    {
        command = cmdcat(command, " '");

        cmdin = cmdstr(file_url);
        command = cmdcat(command, cmdin);
        free(cmdin);

        command = cmdcat(command, "'");

        cmdno(command);
    }

    free(command);

    return;
}

/*wake------------------------------------------------*/

void termux_wake_lock(int mark)
{
    if (mark)
        cmdno("termux-wake-lock");
    else
        cmdno("termux-wake-unlock");

    return;
}

/*wifi------------------------------------------------*/

char *termux_wifi_connectioninfo(void)
{
    return cmd("termux-wifi-connectioninfo");
}

void termux_wifi_enable(int mark)
{
    if (mark)
        cmdno("termux-wifi-enable true");
    else
        cmdno("termux-wifi-enable false");

    return;
}

char *termux_wifi_scaninfo(void)
{
    return cmd("termux-wifi-scaninfo");
}
