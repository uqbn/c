/**
 * 作者:苏梦凡
 * author:smf
 * target:termux-api
 * **/
#ifndef __TERMUX_API_H__
#define __TERMUX_API_H__
/*------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*define------------------------------------------------*/
/*struct------------------------------------------------*/

typedef struct Termux_record
{
    char *file;    //开始记录到特定文件
    char *encoder; //使用指定的编码器(aac, amr_wb, amr_nb)开始记录
    int limit;     //开始记录指定的限制(以秒为单位, 0不受限制)
    int bitrate;   //开始记录指定的比特率(以kbps为单位)
    int rate;      //开始记录指定的采样率(以Hz为单位)
    int count;     //开始记录指定的通道数(1,2, ...)
} Termux_record;

typedef struct Termux_noti
{
    int alert_once;     //在编辑通知时不会发出警报
    int ongoing;        //固定通知
    int sound;          //在通知中播放声音
    int media_next;     //在媒体下一个按钮上执行的操作
    int media_pause;    //在媒体暂停按钮上执行的操作
    int media_play;     //在媒体播放按钮上执行的操作
    int media_previous; //在媒体上一个按钮上执行的操作

    char *content;        //内容显示在通知中.将优先于stdin.
    char *action;         //按下通知时要执行的动作
    char *button1;        //在第一个通知按钮上显示的文字
    char *button1_action; //在第一个通知按钮上执行的操作
    char *button2;        //在第二个通知按钮上显示的文字
    char *button2_action; //在第二个通知按钮上执行的操作
    char *button3;        //在第三个通知按钮上显示的文字
    char *button3_action; //在第三个通知按钮上执行的操作
    char *group;          //通知组(与同一组的通知一起显示)
    int id;               //通知ID(将覆盖以前所有具有相同ID的通知)
    char *image_path;     //通知中将显示的图像的绝对路径
    char *led_color;      //指示灯的闪烁颜色为RRGGBB(默认值: 无)
    int led_off;          //闪烁时LED熄灭的毫秒数(默认值: 800)
    int led_on;           //指示灯闪烁的毫秒数(默认值: 800)
    char *on_delete;      //清除通知时执行的操作
    char *priority;       //通知优先级(high/low/max/min/default)
    char *title;          //显示的通知标题
    char *vibrate;        //振动模式, 逗号分隔为500,1000,200
    char *type;           //使用的通知样式(default/media)
} Termux_noti;

typedef struct Termux_tts
{
    char *engines;  //要使用的TTS引擎(请参阅termux-tts-engines)
    char *language; //要使用的语言(引擎可能不支持)
    char *region;   //要说的语言区域
    char *variant;  //所用语言的变体
    char *stream;   //要使用的音频流(默认值: NOTIFICATION), 其中一种: ALARM, MUSIC, NOTIFICATION, RING, SYSTEM, VOICE_CALL
    int pitch;      //用于演讲的音调. 1.0是正常音高较低的值会降低合成语音的音调,更大的值会增加它.
    int rate;       //使用的语速. 正常语速是1.0较低的值会使语音变慢(0.5是正常语速的一半)而更大的价值会加速它(2.0是正常语速的两倍).
} Termux_tts;

/*------------------------------------------------------*/

/*  功能: 获取有关音频功能的信息.
    参数: 无
    返回: {
        "PROPERTY_OUTPUT_SAMPLE_RATE": "48000",
        "PROPERTY_OUTPUT_FRAMES_PER_BUFFER": "192",
        "AUDIOTRACK_SAMPLE_RATE": 48000,
        "AUDIOTRACK_BUFFER_SIZE_IN_FRAMES": 3844,
        "AUDIOTRACK_SAMPLE_RATE_LOW_LATENCY": 48000,
        "AUDIOTRACK_BUFFER_SIZE_IN_FRAMES_LOW_LATENCY": 384,
        "BLUETOOTH_A2DP_IS_ON": false,
        "WIREDHEADSET_IS_CONNECTED": false
    }*/
extern char *termux_audio_info(void);

/*  功能: 获取设备电池的状态.
    参数: 无
    返回: {
        "health": "GOOD",
        "percentage": 87,
        "plugged": "PLUGGED_AC",
        "status": "CHARGING",
        "temperature": 35.0,
        "current": -110000
    }*/
extern char *termux_battery_status(void);

/*  功能: 将屏幕亮度设置为0至255或auto.
    参数: 屏幕亮度 -1(auto) 0-255
    返回: 无*/
extern void termux_brightness(int num);

/*  功能: 列出通话记录历史记录
    参数: 
        l   #通话记录列表中的限制偏移量(默认值: 10)
        o   #在呼叫日志列表中的偏移量(默认值: 0)
    返回: {
        'error': 'Call log is no longer permitted by Google'
    }*/
extern char *termux_call_log(int l, int o);

/*  功能: 获取有关设备相机的信息.
    参数: 无
    返回: [{'id': '0', 'facing': 'back', 'jpeg_output_sizes': [{'width': 4160, 'height': 3120}, {'width': 4160, 'height': 2336}, {'width': 3104, 'height': 3104}, {'width': 3264, 'height': 2448}, {'width': 3264, 'height': 1840}, {'width': 1920, 'height': 1080}, {'width': 1600, 'height': 1200}, {'width': 1200, 'height': 1200}, {'width': 1440, 'height': 1080}, {'width': 1280, 'height': 960}, {'width': 1280, 'height': 768}, {'width': 1280, 'height': 720}, {'width': 1024, 'height': 768}, {'width': 960, 'height': 720}, {'width': 800, 'height': 600}, {'width': 864, 'height': 480}, {'width': 800, 'height': 480}, {'width': 720, 'height': 720}, {'width': 720, 'height': 480}, {'width': 640, 'height': 480}, {'width': 640, 'height': 360}, {'width': 480, 'height': 640}, {'width': 480, 'height': 360}, {'width': 480, 'height': 320}, {'width': 352, 'height': 288}, {'width': 320, 'height': 240}, {'width': 240, 'height': 320}, {'width': 176, 'height': 144}], 'focal_lengths': [3.5399999618530273], 'auto_exposure_modes': ['CONTROL_AE_MODE_OFF', 'CONTROL_AE_MODE_ON', 'CONTROL_AE_MODE_ON_AUTO_FLASH', 'CONTROL_AE_MODE_ON_ALWAYS_FLASH'], 'physical_size': {'width': 4.748799800872803, 'height': 3.530240058898926}, 'capabilities': ['backward_compatible', 'manual_post_processing', 6, 4, 7, 9, 'raw']}, {'id': '1', 'facing': 'front', 'jpeg_output_sizes': [{'width': 2592, 'height': 1944}, {'width': 1944, 'height': 1944}, {'width': 2592, 'height': 1456}, {'width': 2048, 'height': 1536}, {'width': 1920, 'height': 1080}, {'width': 1600, 'height': 1200}, {'width': 1440, 'height': 1080}, {'width': 1280, 'height': 960}, {'width': 1280, 'height': 768}, {'width': 1280, 'height': 720}, {'width': 1024, 'height': 768}, {'width': 960, 'height': 720}, {'width': 800, 'height': 600}, {'width': 864, 'height': 480}, {'width': 800, 'height': 480}, {'width': 720, 'height': 720}, {'width': 720, 'height': 480}, {'width': 640, 'height': 480}, {'width': 640, 'height': 360}, {'width': 480, 'height': 640}, {'width': 480, 'height': 360}, {'width': 480, 'height': 320}, {'width': 352, 'height': 288}, {'width': 320, 'height': 240}, {'width': 240, 'height': 320}, {'width': 176, 'height': 144}], 'focal_lengths': [2.0], 'auto_exposure_modes': ['CONTROL_AE_MODE_OFF', 'CONTROL_AE_MODE_ON'], 'physical_size': {'width': 2.9030399322509766, 'height': 2.1772799491882324}, 'capabilities': ['backward_compatible', 'manual_post_processing', 6, 4, 7, 'raw']}]
*/
extern char *termux_camera_info(void);

/*  功能:  拍摄照片并将其保存为JPEG格式的文件.
    参数: 
        c  # 要使用的摄像机的ID(请参阅termux-camera-info),默认值: 0
        filename # 文件名
    返回: 无*/
extern void termux_camera_photo(const char *const filename, int c);

/*  功能: 获取系统剪贴板文本.
    参数: 无
    返回: 字符串*/
extern char *termux_clipboard_get(void);

/*  功能: 设置系统剪贴板文本.要设置的文本要么作为参数提供,要么在未提供参数的情况下从stdin读取.
    参数: 字符串
    返回: 无*/
extern void termux_clipboard_set(const char *const str);

/*  功能: 列出所有联系人
    参数: 无
    返回: [{"name":"","number":""}]*/
extern char *termux_contact_list(void);

/*  功能: 选择一个时间值
    参数: 
        t  #设置对话框的标题(可选)
    返回: {
        'code': -1,
        'text': '00:00'
    }*/
extern char *termux_dialog_time(const char *const t);

/*  功能: 输入文本(如果未指定小部件,则为默认值)
    参数: 
        t   #设置对话框的标题(可选)
        i   #文本提示(可选)
        op  # m 多行而不是单行(可选)* n 输入数字输入(可选)* p 输入密码作为输入(可选)
    }
    返回: {
        'code': -1,
        'text': 'text'
    }
    * 不能将[m]与[n]一起使用*/
extern char *termux_dialog_text(const char *const t, const char *const i, const char *const op);

/*  功能: 使用设备麦克风获取语音
    参数:
        t   #设置对话框的标题(可选)
        i   #文本提示(可选)
    返回: 字符串*/
extern char *termux_dialog_speech(const char *const t, const char *const i);

/*  功能: 从下拉菜单中选择一个值
    参数:
        t   #设置对话框的标题(可选)
        v   #要使用的逗号delim值(必需)
    返回: {
        'code': -1,
        'text': '值1', 
        'index': 0
    }*/
extern char *termux_dialog_spinner(const char *const t, const char *const v);

/*  功能: 从滑动底部表中选择一个值
    参数:
        t   #设置对话框的标题(可选)
        v   #要使用的逗号delim值(必需)
    返回: {
        'code': 0,
        'text': '值1',
        'index': 0
    }*/
extern char *termux_dialog_sheet(const char *const t, const char *const v);

/*  功能: 从单选按钮中选择一个值
    参数:
        t   #设置对话框的标题(可选)
        v   #要使用的逗号delim值(必需)
    返回: {
        'code': -1,
        'text': '值1',
        'index': 0
    }*/
extern char *termux_dialog_radio(const char *const t, const char *const v);

/*  功能: 选择一个日期
    参数:
        t   #设置对话框的标题(可选)
        d   #用于日期小部件输出的SimpleDateFormat模式(可选) 'yyyyMMdd k:m:s'
    返回: {
        'code': -1,
        'text': '20200901 24:0;0',
        'index': 1
    }*/
extern char *termux_dialog_date(const char *const t, const char *const d);

/*  功能: 选择指定范围内的数字
    参数:
        t   #设置对话框的标题(可选) 
        r   #[min,max,start] 要使用的(3)个数字的逗号delim(可选)
    返回: {
        'code': -1,
        'text': '6',
        'index': 1
    }*/
extern char *termux_dialog_counter(const char *const t, const char *const r);

/*  能: 使用复选框选择多个值
    参数:
        t   #设置对话框的标题(可选)
        v   #要使用的逗号delim值(必需)
    返回: {
        'code': -1,
        'text': '[值1, 值2]',
        'index': 1,
        'values': [
            {'index': 0, 'text': '值1'}, 
            {'index': 1, 'text': '值2'}
        ]
    }*/
extern char *termux_dialog_checkbox(const char *const t, const char *const v);

/*  功能: 显示确认对话框
    参数:
        t   #设置对话框的标题(可选)
        i   #文本提示(可选)
    返回: {
        'code': 0,
        'text': 'yes'('no'),
        'index': 1
    }*/
extern char *termux_dialog_confirm(const char *const t, const char *const i);

/*  功能: 使用系统下载管理器下载资源./data/data/com.android.providers.downloads/cache/
    参数:
        url #下载链接
        d   #下载请求通知的描述
        t   #下载请求通知的标题
    返回: 无*/
extern void termux_download(const char *const url, const char *const t, const char *const d);

/*  功能: 使用设备上的指纹传感器检查身份验证
    注意: 仅在Nougat和更高版本上可用
    参数:
        t   #标题
        d   #描述
        s   #字幕
        c   #取消
    返回: {
        'errors': [],
        'failed_attempts': 0,
        'auth_result': 'AUTH_RESULT_SUCCESS'
    }
    {
        'errors': [],
        'failed_attempts': 0,
        'auth_result': 'AUTH_RESULT_FAILURE'
    }*/
extern char *termux_fingerprint(const char *const t, const char *const d, const char *const s, const char *const c);

/*  功能: 查询红外发射器支持的载波频率.
    参数: 无
    返回: []*/
extern char *termux_infrared_frequencies(void);

/*  功能: 发射红外线图案. 该模式以逗号分隔的开/关间隔指定, 例如 "20,50,20,30" . 仅传输短于2秒的码型.
    参数:
        f #IR载波频率, 以赫兹为单位
        num
    返回: 无*/
extern char *termux_infrared_transmit(int f, int num);

/*  功能: 获取设备位置.
    参数:
        p   #程序位置提供程序[gps/network/passive](默认值: gps)
        r   #请求一次[once/last/updates]的请求(默认值: 一次)
    返回:{
        "latitude": 100.455187,
        "longitude": 100.529537,
        "altitude": 0.0,
        "accuracy": 100.0,
        "bearing": 0.0,
        "speed": 0.0,
        "elapsedMs": 4,
        "provider": "network"
    }*/
extern char *termux_location(const char *const p, const char *const r);

/*  功能: 扫描指定的文件, 并将其添加到媒体内容提供程序.
    参数:
        filename    #要扫描的文件名
        op          #r递归扫描目录 v详细模式
    返回: 字符串*/
extern char *termux_media_scan(const char *const filename, const char *const op);

/*   功能: 
    参数:
        op          #play如果暂停则继续播放 info显示当前播放信息  pause暂停播放 stop退出播放
        filename    #播放文件名
    返回:*/
extern char *termux_media_player(const char *const op, const char *const filename);

/*  功能: 使用设备上的麦克风录制
    参数:
        op  # d 使用默认设置开始录制   i获取有关当前录制的信息 q退出录音
        struct_op # struct Termux_record
    返回:*/
extern char *termux_microphone_record(const Termux_record *const struct_op, const char *const op);

/*  功能: 显示系统通知. 内容文本使用 -c/--content 指定或从stdin中读取.
    参数: op # struct Termux_noti
    返回: 无
*/
extern void termux_notification(const Termux_noti *const op);

/*  功能: 显示当前显示的通知列表.
    参数: 无
    返回: [
        {
            "id": 1337,
            "tag": "",
            "key": "0|com.termux|1337|null|10141",
            "group": "",
            "packageName": "com.termux",
            "title": "Termux",
            "content": "1 session",
            "when": 1599015058125
        }
    ]*/
extern char *termux_notification_list(void);

/*  功能: 删除先前用termux-notification --id显示的通知.
    参数: id
    返回: 无*/
extern void termux_notification_remove(int id);

/*  功能: 在外部应用程序中打开文件或URL
    参数: 
        path_url #路径或者链接
        select #0 应共享文件进行查看（默认） 1 文件应该共享以发送 2 应始终显示应用选择器
        type #指定要使用的内容类型
    返回: 无*/
extern void termux_open(const char *const path_url, int select, const char *const type);

/*  功能:打开一个URL进行查看
    参数: 无
    返回: 无*/
extern void termux_open_url(const char *const url);

/*  功能: 获取有关传感器类型以及实时数据的信息
    参数:
        op  #a 全部收听所有传感器(警告! 可能会对电池产生影响) c 清除执行清除(释放传感器资源) l 列表显示可用传感器的列表
        s   #要监听的传感器(可以只包含部分名称)
        ms  #接收新传感器更新之前的延迟时间(以毫秒为单位)
        n   #读取传感器的次数(默认值:连续)(分钟:1)
    返回: json*/
extern char *termux_sensor(const char *const s, int ms, int n, const char *const op);

/*  功能: 列出短信
    参数:
        op  # d显示创建消息的日期 n显示电话号码
        l   # 短信列表中的限制偏移量(默认值: 10)
        o   # 短信列表中的偏移量(默认值: 0)
        t   # 要列出的消息类型(默认值: inbox): all|inbox|sent|draft|outbox
    返回: */
extern char *termux_sms_list(const char *const t, int l, int o, const char *const op);

/*  功能: 将SMS消息发送到指定的收件人号码. 要发送的文本要么作为参数提供, 要么在未提供参数的情况下从stdin读取.
    参数:
        number    #收件人号码-用逗号分隔多个号码
        text      #文本
    返回: 无*/
extern void termux_sms_send(const char *const numbers, const char *const text);

/*  功能: 将语音转换为文本, 将部分匹配项发送到stdout.
    参数: 无
    返回: 字符串*/
extern char *termux_speech_to_text(void);

/*  功能: 向系统请求文件并将其输出到指定文件.
    参数: output-file
    返回: 无*/
extern void termux_storage_get(const char *const filename);

/*  功能: 拨打电话号码
    参数: num
    返回: 无*/
extern void termux_telephony_call(const char *const num);

/*  功能: 从设备上的所有无线电(包括主要和相邻小区)获取有关所有观察到的小区信息的信息.
    参数: 无
    返回: []*/
extern char *termux_telephony_cellinfo(void);

/*  功能: 获取有关电话设备的信息.
    参数: 无
    返回: {
        "data_activity": "none",
        "data_state": "disconnected",
        "device_id": "867441037469887",
        "device_software_version": "04",
        "phone_count": 2,
        "phone_type": "gsm",
        "network_operator": "46000",
        "network_operator_name": "中国移动",
        "network_country_iso": "cn",
        "network_type": "lte",
        "network_roaming": false,
        "sim_country_iso": "cn",
        "sim_operator": "46001",
        "sim_operator_name": "CMCC",
        "sim_serial_number": "8986003231AA73832693",
        "sim_subscriber_id": "460021238352693",
        "sim_state": "ready"
    }*/
extern char *termux_telephony_deviceinfo(void);

/*  功能: 在Toast中显示文本(瞬态弹出窗口). 要显示的文本作为参数提供, 或者如果未提供参数, 则从stdin读取.
    参数:
        s       #1 只显示片刻
        b       #设置背景颜色(default: gray)
        c       #设置文本颜色(default: white)
        g       #设置烤面包的位置 [top, middle, or bottom] (default: middle)
        text    #显示的文本
    返回: 无
    注意: 颜色可以是标准名称(即red)或6/8位十六进制值(即"#FF0000"或"#FFFF0000"), 其顺序为(AA)RRGGBB. 无效的颜色将恢复为默认值.*/
extern void termux_toast(const char *const text, const char *const c, const char *const b, const char *const g, int s);

/*  功能: 在设备上切换LED手电筒
    参数: on 1 0
    返回: 无*/
extern void termux_torch(int on);

/*  功能: 获取有关可用的文本语音转换(TTS)引擎的信息. 可以使用-e选项将引擎的名称提供给termux-tts-speak命令.
    参数: 无
    返回: [
        {
            "name": "com.iflytek.speechsuite",
            "label": "讯飞语音引擎",
            "default": true
        },
        {
            "name": "com.svox.pico",
            "label": "Pico TTS",
            "default": false
        }
    ]*/
extern char *termux_tts_engines(void);

/*  功能: 使用系统文本语音转换(TTS)引擎说出文本. 要说的文本作为参数提供, 或者如果未提供参数, 则从stdin读取.
    参数:
        text    #文本
        op      #struct Termux_tts
    返回: 无*/
extern void termux_tts_speak(const Termux_tts *const op, const char *const text);

/*  功能: 列出或访问USB设备. 无法直接访问设备, 仅使用termux-usb.
    参数:
        path    #路径
        op      # l 列出可用的设备   r 显示许可权请求对话框(如有必要)
        e       #命令执行带有文件描述符的指定命令引用设备作为其参数
    返回: 无*/
extern char *termux_usb(const char *const path, const char *const e, const char *const op);

/*  功能: 振动设备.
    参数:
        ms     #持续时间以毫秒为单位的振动持续时间(默认值: 1000)
        mute   #1 即使在静音模式下也能振动
    返回: 无*/
extern void termux_vibrate(int ms, int mute);

/*  功能: 更改音频流的音量.
    参数:
        s   #alarm, music, notification, ring, system, call
        v   #音量大小
    返回:[
        {
            "stream": "call",
            "volume": 5,
            "max_volume": 5
        },
        {
            "stream": "system",
            "volume": 3,
            "max_volume": 7
        },
        {
            "stream": "ring",
            "volume": 3,
            "max_volume": 7
        },
        {
            "stream": "music",
            "volume": 7,
            "max_volume": 15
        },
        {
            "stream": "alarm",
            "volume": 7,
            "max_volume": 7
        },
        {
            "stream": "notification",
            "volume": 3,
            "max_volume": 7
        }
    ]*/
extern void termux_volume(const char *const s, int v);

/*  功能: 更改设备上的墙纸
    参数: {
        file_url    #从文件设置墙纸或从url资源设置墙纸
        screen      #1 设置用于锁屏的墙纸(Nougat及更高版本)
    返回: 无*/
extern void termux_wallpaper(const char *const file_url, int screen);

/*  功能: 获取Termux唤醒锁,  以防止CPU休眠.
    参数: mark 1(lock) 0(unlock)
    返回: 无*/
extern void termux_wake_lock(int mark);

/*  功能: 开启/关闭Wi-Fi
    参数: mark 1(on) 0(off)
    返回: 无*/
extern void termux_wifi_enable(int mark);

/*  功能: 获取有关上一次wifi扫描的信息.
    参数: 无
    返回: [
        {
            "bssid": "4c:bc:98:04:5a:94",
            "frequency_mhz": 2452,
            "rssi": -41,
            "ssid": "",
            "timestamp": 31569432017,
            "channel_bandwidth_mhz": "40",
            "center_frequency_mhz": 2442
        }
    ]*/
extern char *termux_wifi_scaninfo(void);

/*  功能: 获取有关当前wifi连接的信息
    参数: 无
    返回: */
extern char *termux_wifi_connectioninfo(void);
/*------------------------------------------------------*/
#endif