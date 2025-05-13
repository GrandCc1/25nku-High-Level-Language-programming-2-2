#ifndef BOMB_H
#define BOMB_H
#include <QPixmap>
#include<QVector>

class Bomb
{
public:
    Bomb();
    //更新信息
    void updateInfo();
public:
    //爆炸资源数组
    QVector<QPixmap> pix;
    //爆炸位置
    int x;
    int y;
    //爆炸状态
    bool free;
    //爆炸切图的时间间隔
    int record;
    //爆炸时加载图片的下标
    int index;
};

#endif // BOMB_H
