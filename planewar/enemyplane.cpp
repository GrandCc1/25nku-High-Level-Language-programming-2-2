#include "enemyplane.h"
#include "config.h"
EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    enemy.load(ENEMY_PATH);
    //敌机位置
    x=0;
    y=0;
    //敌机状态
    free=true;
    //敌机速度
    speed=ENEMY_SPEED;
    //敌机矩形
    rect.setWidth(enemy.width());
    rect.setHeight(enemy.height());
    rect.moveTo(x,y);
}

void EnemyPlane::updatePosition()
{
    //空闲状态不计算坐标
    if(free){
        return;
    }
    y+=speed;
    rect.moveTo(x,y);
    //离开屏幕或者被击毁设置为true
    if(y>=GAME_HEIGHT){

        free=true;
    }
}
