#include "heroplane.h"
#include "config.h"
HeroPlane::HeroPlane()
{
    //初始化飞机图片资源
    m_plane.load(HERO_PATH);

    //初始化坐标
    x=GAME_WIDTH*0.5-m_plane.width()*0.5;
    y=GAME_HEIGHT-m_plane.height()-20;

    //初始化矩形框
    m_rect.setWidth(m_plane.width());
    m_rect.setHeight(m_plane.height());
    m_rect.moveTo(x,y);
    //初始化发射记录
    //record=0;
}
//射击实现
void HeroPlane::shoot()
{
    //累计时间间隔记录变量
    record++;
    //判断记录数字，如果没有到达发射间隔，直接return
    if(record<BULLET_INTERVAL){
        return;
    }
    //到达发射时间处理
    //重置发射时间记录
    record=0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++){
        //如果是空闲的子弹进行发射
        if(bulltedrs[i].free){
            //将子弹的空闲状态改为假
            bulltedrs[i].free=false;
            //设置发射的子弹坐标
            bulltedrs[i].x=x+m_rect.width()*0.5-10;//飞机位置+飞机宽度一半+初始位置
            bulltedrs[i].y=y-25;
            break;
        }
    }
}

//设置飞机位置，包括碰撞检测框
void HeroPlane::setPosition(int x, int y)
{
    this->x=x;
    this->y=y;
    m_rect.moveTo(x,y);
}
