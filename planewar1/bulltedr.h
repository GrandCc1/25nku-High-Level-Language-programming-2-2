#ifndef BULLTEDR_H
#define BULLTEDR_H
#include<QPixmap>
class Bulltedr
{
public:
    Bulltedr();
    //更新子弹坐标
    void updatePosition();
public:
    QPixmap bulltedr;//子弹资源对象
    //子弹坐标
    int x;
    int y;
    int speed;//子弹移动速度
    bool free;//闲置
    QRect rect;//子弹矩形碰撞检测狂
};


#endif // BULLTEDR_H
