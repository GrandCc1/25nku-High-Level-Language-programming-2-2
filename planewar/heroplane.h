#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>

#include "config.h"
#include "bulltedr.h"

class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x,int y);
public:
    //飞机资源对象
    QPixmap m_plane;
    //飞机坐标
    int x;
    int y;

    //飞机的矩形边框，用于碰撞检测
    QRect m_rect;
    Bulltedr bulltedrs[BULLET_NUM];
    //发射间隔记录
    int  record;

};
#endif // HEROPLANE_H
