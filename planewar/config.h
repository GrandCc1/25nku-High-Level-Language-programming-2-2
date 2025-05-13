#ifndef CONFIG_H
#define CONFIG_H


//游戏配置数据
#define GAME_WIDTH 512 //界面宽度
#define GAME_HEIGHT 768//界面高度
#define GAME_TITLE "飞机大战"//标题
#define GAME_ICON ":/res/img/app.ico"


//屏幕刷新时间--帧率
#define GAME_RATE 10    //刷新间隔 帧率 单位毫秒

//地图配置数据
#define MAP_PATH ":/res/img/img_bg_level_1.jpg"  //默认地图1
#define MAP_SCROLL_SPEED 2  //默认地图滚动速度

//飞机配置数据
#define HERO_PATH ":/res/img/hero2.png"//英雄飞机
//子弹配置数据
#define BULLET_PATH ":/res/img/bullet_1"//飞机子弹图片路径
#define BULLET_SPEED 5 //子弹速度
#define BULLET_NUM 30   //弹匣中子弹数目
#define BULLET_INTERVAL 20//子弹发射间隔
//敌机配置数据
#define ENEMY_PATH ":/res/img/img-plane_6.png" //敌机路径
#define ENEMY_SPEED 5  //敌机飞行速度
#define ENEMY_NUM 20   //敌机总量
#define ENEMY_INTERVAL 30  //敌机出场间隔
//爆炸配置数据
#define BOMB_PATH ":/res/img/bomb-%1.png"//爆照效果路径
#define BOMB_NUM   20   //爆炸数量
#define BOMB_MAX    7//爆炸图片最大索引值
#define BOMB_INTERVAL 5 //爆炸切图时间间隔

#endif // CONFIG_H
