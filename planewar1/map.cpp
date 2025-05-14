#include "map.h"
#include "config.h" //配置文件
//构造函数
Map::Map()
{
    //初始化加载地图对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);
    //设置地图初始坐标
    map1_posX=-GAME_WIDTH;
    map2_posX=0;
    //设置地图加载速度
    map_scroll_speed=MAP_SCROLL_SPEED;

}
void Map::mapPosition(){
    //第一张地图向右滚动
    map1_posX += map_scroll_speed;
    if(map1_posX >= 0){  // 移动完一屏，重置到左侧
        map1_posX = -GAME_WIDTH;
    }

    //第二张地图向右滚动
    map2_posX += map_scroll_speed;
    if(map2_posX >= GAME_WIDTH){  // 同样移动完一屏重置
        map2_posX = 0;
    }
}
