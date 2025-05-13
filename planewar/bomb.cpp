#include "bomb.h"
#include "config.h"
Bomb::Bomb()
{
    //初始化爆炸图片数组
    for(int i=0;i<BOMB_NUM;i++){
        pix.push_back(QPixmap(QString(BOMB_PATH).arg(i)));
    }
    //初始化坐标
    x=0;
    y=0;
    //初始化空闲状态
    free=true;
    //当前播放图片下标
    index=0;
    //爆炸间隔记录
    record=0;
}
//爆炸信息
void Bomb::updateInfo()
{
    //空闲状态
    if(free){
        return;
    }
    record++;
    if(record<BOMB_INTERVAL){
        //爆炸时间间隔没到返回
        return;
    }
    //重置状态
    record=0;
    //切换爆炸播放图
    index++;
    //图片播放完毕，重置下标
    if(index>BOMB_MAX-1){
        index=0;
        free=true;
    }

}
