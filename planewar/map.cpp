#include "map.h"
#include "config.h" //配置文件
//构造函数
Map::Map()
{
    //初始化加载地图对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);
    //设置地图初始坐标
    map1_posY=-GAME_HEIGHT;
    map2_posY=0;
    //设置地图加载速度
    map_scroll_speed=MAP_SCROLL_SPEED;

}
//地图滚动坐标计算
void Map::mapPosition(){
    //处理第一张图片滚动
    map1_posY+=MAP_SCROLL_SPEED;//向下移动
    if(map1_posY>=0){//如果全部移动到了界面 重置位置
        map1_posY=-GAME_HEIGHT;
    }
    //处理第二张图片滚动
    map2_posY+=MAP_SCROLL_SPEED;//向下移动
    if(map2_posY>=GAME_HEIGHT){//如果全部移动到了界面外 重置位置
        map2_posY=0;
    }

}
