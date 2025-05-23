#ifndef MAP_H
#define MAP_H
#include <QPixmap>//绘图设备
//地图类
class Map{

public:
    //构造函数
    Map();

    //地图滚动坐标计算
    void mapPosition();

public:
    //地图图片对象
    QPixmap map1;
    QPixmap map2;
    //地图Y轴坐标
    int map1_posX;
    int map2_posX;
    //地图滚动幅度
    int map_scroll_speed;

};

#endif // MAP_H
