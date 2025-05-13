#include "bulltedr.h"
#include"config.h"//配置文件
Bulltedr::Bulltedr()
{
    // 加载子弹资源
    bulltedr.load(BULLET_PATH);
    //子弹坐标，初始位置可以随意设置，后续会重置
    x=GAME_WIDTH*0.5-bulltedr.width()*0.5;
    y=GAME_HEIGHT;
    //子弹状态--默认为true;
    free=true;
    //子弹速度
    speed=BULLET_SPEED;

    //子弹矩形框
    rect.setWidth(bulltedr.width());
    rect.setHeight(bulltedr.height());
    rect.moveTo(x,y);
}

//更新子弹坐标
void Bulltedr::updatePosition()
{
    //如果子弹处于闲置状态，不需要进行坐标计算 直接返回
    if(free){
        return;
    }
    //子弹向上移动
    y-=speed;
    rect.moveTo(x,y);
    //如果在界面外，设置为闲置
    if(y<=-rect.height()){
        free=true;
    }
}
