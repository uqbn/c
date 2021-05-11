/*include-------------------------------------------------*/
#include "termux_api.h"
#include <unistd.h>
/*globle-------------------------------------------------*/
int t = 1;
/*function------------------------------------------------*/

void print(const char *const str)
{
    printf("%s\n", str);
    return;
}

static void show(const char *const str, const char *const filename)
{
    /*    char buff[BUFSIZ] = {};
    sprintf(buff, "%s.out", filename);
    FILE *fp = fopen(buff, "w");
    if (fp == NULL)
        perror(buff);
    else
    {
        fprintf(fp, "%s", str);
        fflush(fp);
        fclose(fp);
    }
*/
    printf("%s\n", str);
    fflush(stdout);
    //    system("mv termux_*.out termux_out");
    sleep(t);
    return;
}

int main(int argc, char *argv[])
{
    char *str = NULL;
    //system("rm -rf termux_out");
    //system("mkdir termux_out");

    /*termux_wake_lock*/
    print("获取Termux唤醒锁,  以防止CPU休眠!");
    termux_wake_lock(1);
    sleep(t);

    /*termux_media_player*/
    print("播放音乐!");
    termux_volume("music", 7);
    str = termux_media_player("play", "data/termux_test.mp3");
    show(str, "termux_media_player");
    free(str);
    str = NULL;

    /*termux_wifi_enable*/
    print("关闭WIFI!");
    termux_wifi_enable(0);
    sleep(t);
    print("打开WIFI!");
    termux_wifi_enable(1);
    sleep(t);

    /*termux_brightness*/
    print("屏幕最暗!");
    termux_brightness(0);
    sleep(t);
    print("屏幕最亮!");
    termux_brightness(255);
    sleep(t);
    print("自动调节亮度!");
    termux_brightness(-1);
    sleep(t);

    /*termux_vibrate*/
    print("震动 1000ms!");
    termux_vibrate(1000, 1);
    sleep(1);

    /*termux_torch*/
    print("打开手电筒!");
    termux_torch(1);
    sleep(t);
    print("关闭手电筒!");
    termux_torch(0);
    sleep(t);

    /*termux_audio_info*/
    print("获取有关音频功能的信息!");
    str = termux_audio_info();
    show(str, "termux_audio_info");
    free(str);
    str = NULL;

    /*termux_battery_status*/
    print("获取设备电池的状态!");
    str = termux_battery_status();
    show(str, "termux_battery_status");
    free(str);
    str = NULL;

    /*termux_call_log*/
    print("列出通话记录历史记录!");
    str = termux_call_log(10, 0);
    show(str, "termux_call_log");
    free(str);
    str = NULL;

    /*termux_camera_info*/
    print("获取有关设备相机的信息!");
    str = termux_camera_info();
    show(str, "termux_camera_info");
    free(str);
    str = NULL;

    /*termux_camera_photo*/
    print("后置摄像头拍照!");
    termux_camera_photo("out.jpg", 0);
    sleep(t);

    /*termux_open*/
    print("打开文件!");
    termux_open("data/termux_wall1.jpg", 0, NULL);
    sleep(t);

    /*termux_clipboard_get*/
    print("获取系统剪贴板文本!");
    str = termux_clipboard_get();
    show(str, "termux_clipboard_get");
    free(str);
    str = NULL;

    /*termux_clipboard_set*/
    print("设置系统剪切板!");
    termux_clipboard_set("欢迎使用termux-api!");
    sleep(t);

    /*termux_contact_list*/
    print("列出所有联系人!");
    str = termux_contact_list();
    show(str, "termux_contact_list");
    free(str);
    str = NULL;

    /*termux_dialog*/
    print("选择一个时间值!");
    str = termux_dialog_time("time");
    show(str, "termux_dialog_time");
    free(str);

    print("输入文本!");
    str = termux_dialog_text("text", "输入文本", "m");
    show(str, "termux_dialog_text");
    free(str);

    print("使用设备麦克风获取语音!");
    str = termux_dialog_speech("speech", "请说话!");
    show(str, "termux_dialog_speech");
    free(str);

    print("从下拉菜单中选择一个值");
    str = termux_dialog_spinner("spinner", "值1,值2,值3");
    show(str, "termux_dialog_spinner");
    free(str);

    print("从滑动底部表中选择一个值!");
    str = termux_dialog_sheet("sheet", "值1,值2,值3");
    show(str, "termux_dialog_sheet");
    free(str);

    print("从单选按钮中选择一个值!");
    str = termux_dialog_radio("radio", "值1,值2,值3");
    show(str, "termux_dialog_radio");
    free(str);

    print("选择一个日期!");
    str = termux_dialog_date("date", "yyyyMMdd k:m:s");
    show(str, "termux_dialog_date");
    free(str);

    print("选择指定范围内的数字!");
    str = termux_dialog_counter("counter", "0,9,5");
    show(str, "termux_dialog_counter");
    free(str);

    print("使用复选框选择多个值!");
    str = termux_dialog_checkbox("checkbox", "值1,值2,值3");
    show(str, "termux_dialog_checkbox");
    free(str);

    /*termux_open_url*/
    print("打开链接!");
    termux_open_url("https://cn.bing.com/th?id=OHR.PicoIsland_ZH-CN6719354511_UHD.jpg");
    sleep(t);

    /*termux_fingerprint*/
    print("使用设备上的指纹传感器检查身份验证!");
    str = termux_fingerprint("fingerprint", "描述", "字幕", "取消");
    show(str, "termux_fingerprint");
    free(str);

    /*termux_download*/
    print("下载文件!");
    termux_download("https://cn.bing.com/th?id=OHR.PicoIsland_ZH-CN6719354511_UHD.jpg", "一头公牛站在皮库山前的田野中，亚速尔群岛皮科岛", "下载测试");
    sleep(t);

    /*termux_infrared_frequencies*/
    print("查询红外发射器支持的载波频率!");
    str = termux_infrared_frequencies();
    show(str, "termux_infrared_frequencies");
    free(str);
    str = NULL;

    /*termux_infrared_transmit*/
    print("发射红外线图案!");
    str = termux_infrared_transmit(50, 0);
    show(str, "termux_infrared_transmit");
    free(str);

    /*termux_location*/
    print("获取设备位置!");
    str = termux_location("network", "once");
    show(str, "termux_location");
    free(str);
    str = NULL;

    /*termux_microphone_record*/
    system("rm -rf out.m4a");
    Termux_record *record = (Termux_record *)calloc(1, sizeof(Termux_record));
    record->file = "out.m4a";
    record->limit = 5;
    print("使用设备上的麦克风录制!");
    str = termux_microphone_record(record, "d");
    sleep(t);
    show(str, "termux_microphone_record");
    free(record);
    record = NULL;
    free(str);
    str = NULL;

    /*termux_media_scan*/
    print("扫描指定的文件, 并将其添加到媒体内容提供程序!");
    str = termux_media_scan(".", "vr");
    show(str, "termux_media_scan");
    free(str);
    str = NULL;

    /*termux_notification*/
    Termux_noti *noti = (Termux_noti *)calloc(1, sizeof(Termux_noti));
    noti->alert_once = 1;
    //noti->ongoing = 1;
    noti->sound = 1;
    noti->media_next = 1;
    noti->media_pause = 1;
    noti->media_play = 1;
    noti->media_previous = 1;
    noti->button1 = "button1";
    noti->button2 = "button2";
    noti->button3 = "button3";
    noti->title = "通知";
    noti->content = "通知内容";
    noti->id = 1111;
    print("显示系统通知!");
    termux_notification(noti);
    free(noti);
    noti = NULL;
    sleep(t);

    /*termux_notification_list*/
    print("显示当前显示的通知列表!");
    str = termux_notification_list();
    show(str, "termux_notification_list");
    free(str);
    str = NULL;

    /*termux_notification_remove*/
    print("删除先前用termux-notification --id显示的通知!");
    termux_notification_remove(1111);
    sleep(t);

    /*termux_sensor*/
    print("获取有关传感器类型以及实时数据的信息");
    str = termux_sensor(NULL, 0, 0, "l");
    show(str, "termux_sensor");
    free(str);
    str = NULL;

    /*termux_sms_list*/
    print("列出短信!");
    str = termux_sms_list("all", 10, 0, "dn");
    show(str, "termux_sms_list");
    free(str);
    str = NULL;

    /*termux_sms_send*/
    print("将SMS消息发送到指定的收件人号码!");
    termux_sms_send("10086", "cxll");
    sleep(t);

    /*ermux_storage_get*/
    print("向系统请求文件并将其输出到指定文件!");
    termux_storage_get("get.in");
    sleep(t);

    /*termux_telephony_cellinfo*/
    print("从设备上的所有无线电(包括主要和相邻小区)获取有关所有观察到的小区信息的信息!");
    str = termux_telephony_cellinfo();
    show(str, "termux_telephony_cellinfo");
    free(str);
    str = NULL;

    /*termux_telephony_deviceinfo*/
    print("获取有关电话设备的信息!");
    str = termux_telephony_deviceinfo();
    show(str, "termux_telephony_deviceinfo");
    free(str);
    str = NULL;

    /*termux_toast*/
    print("在Toast中显示文本(瞬态弹出窗口)!");
    termux_toast("你好", NULL, NULL, NULL, 0);
    sleep(t);

    /*termux_tts_engines*/
    print("获取有关可用的文本语音转换(TTS)引擎的信息!");
    str = termux_tts_engines();
    show(str, "termux_tts_engines");
    free(str);
    str = NULL;

    /*termux_usb*/
    print("列出或访问USB设备!");
    str = termux_usb(NULL, NULL, "l");
    show(str, "termux_usb");
    free(str);
    str = NULL;

    /*termux_wallpaper*/
    print("设置锁屏壁纸!");
    termux_wallpaper("data/termux_wall1.jpg", 1);
    sleep(t);
    print("设置桌面壁纸!");
    termux_wallpaper("data/termux_wall2.jpg", 0);
    sleep(t);

    /*termux_wifi_scaninfo*/
    print("获取有关上一次wifi扫描的信息!");
    str = termux_wifi_scaninfo();
    show(str, "termux_wifi_scaninfo");
    free(str);
    str = NULL;

    /*termux_wifi_connectioninfo*/
    print("获取有关当前wifi连接的信息!");
    str = termux_wifi_connectioninfo();
    show(str, "termux_wifi_connectioninfo");
    free(str);
    str = NULL;

    /*termux_volume*/
    print("媒体音量全开!");
    termux_volume("music", 15);
    sleep(t);

    /*termux_tts_speak*/
    print("使用系统文本语音转换(TTS)引擎说出文本!");
    termux_tts_speak(NULL, "欢迎使用termux-api!");

    /*termux_dialog_confirm*/
    print("显示确认对话框!");
    str = termux_dialog_confirm("confirm", "欢迎使用termux-api!");
    show(str, "termux_dialog_confirm");
    free(str);

    /*termux_telephony_call*/
    print("拨打电话号码!");
    termux_telephony_call("10086");
    sleep(t);
    /*termux_speech_to_text*/
    print("将语音转换为文本!");
    str = termux_speech_to_text();
    show(str, "termux_speech_to_text");
    free(str);
    str = NULL;

    return 0;
}