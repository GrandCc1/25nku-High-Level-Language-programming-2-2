#include "mainscene.h"
#include "config.h"
#include "QIcon"
#include "QPainter"
#include "QMouseEvent"
#include <QMessageBox>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();

    playGame();
}

MainScene::~MainScene() {}

void MainScene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);
    //设置图标资源
    setWindowIcon(QIcon( GAME_ICON));
    //定时器设置
    m_Timer.setInterval(GAME_RATE);
    //敌机出场间隔
    m_recorder=0;
}


//启动游戏 用于启动计时器对象
void MainScene::playGame()
{
    //播放背景音乐
    //QSound::play(SOUND_BACKGROUND);
    m_Timer.start();
    //监听计时器 用于刷新地图
    connect(&m_Timer,&QTimer::timeout,this,[=](){

        if (gameOver) return;
        //敌机出现
        enemyToScene();
        //更新游戏中元素的坐标
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
        //碰撞检测
        collisionDetection();
    });
}


//更新坐标
void MainScene::updatePosition()
{
    //更新地图坐标
    map.mapPosition();

    //发射子弹
    hero.shoot();
    //计算子弹坐标
    for(int i=0;i<BULLET_NUM;i++){
        //如果子弹为非空闲状态，计算发射位置
        if(!hero.bulltedrs[i].free){
            hero.bulltedrs[i].updatePosition();
        }
    }
    //测试子弹代码
    t_bulltedr.free=false;
    t_bulltedr.updatePosition();


    //计算敌机坐标
    for(int i=0;i<ENEMY_NUM;i++){
        if(enemys[i].free==false){
            enemys[i].updatePosition();
        }
    }
    //计算爆炸坐标
    for(int i=0;i<BOMB_NUM;i++){
        if(bombs[i].free==false){
            bombs[i].updateInfo();
        }
    }
}

//绘图事件
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);
    //绘制英雄飞机
    painter.drawPixmap(hero.x,hero.y,hero.m_plane);

    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++){
        //如果子弹状态为false计算发射位置
        if(!hero.bulltedrs[i].free){
            painter.drawPixmap(hero.bulltedrs[i].x,hero.bulltedrs[i].y,hero.bulltedrs[i].bulltedr);
        }
    }


    //绘制敌机
    for(int i=0;i<ENEMY_NUM;i++){
        if(!enemys[i].free){
            painter.drawPixmap(enemys[i].x,enemys[i].y,enemys[i].enemy);
        }
    }

    //绘制爆炸图片
    for(int i=0;i<BOMB_NUM;i++){
        if(bombs[i].free==false){
            painter.drawPixmap(bombs[i].x,bombs[i].y,bombs[i].pix[bombs[i].index]);
        }
    }

    //测试子弹代码
    painter.drawPixmap(t_bulltedr.x,t_bulltedr.y,t_bulltedr.bulltedr);
}


//重写鼠标移动事件
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    //记录鼠标坐标
    int x=event->x()-hero.m_rect.width()*0.5;//鼠标位置减去碰撞检测矩形位置的一半
    int y=event->y()-hero.m_rect.height()*0.5;//鼠标位置减去碰撞检测矩形位置的一半

    //边界检测
    if(x<=0){
        x=0;
    }
    if(x>GAME_WIDTH-hero.m_rect.width()){
        x=GAME_WIDTH-hero.m_rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y>=GAME_HEIGHT-hero.m_rect.height()){
        y=GAME_HEIGHT-hero.m_rect.height();
    }

    hero.setPosition(x,y);
}

//敌机出现
void MainScene::enemyToScene()
{
    m_recorder++;
    //如果没到达间隔时间（record*timer.interval) 直接返回
    if(m_recorder<ENEMY_INTERVAL){
        return;
    }
    //到达重置间隔
    m_recorder=0;
    //敌机出现
    for(int i=0;i<ENEMY_NUM;i++){
        if(enemys[i].free){//如果为空闲
            //敌机的空闲状态改为false
            enemys[i].free=false;
            //设置坐标
            enemys[i].x=rand()%(GAME_WIDTH-enemys[i].rect.width());
            enemys[i].y=-enemys[i].rect.height();
            break;
        }

    }

}


//碰撞检测
void MainScene::collisionDetection()
{
    //实现方式，遍历所有飞机和子弹，如果发生碰撞，释放为free
    //遍历所有非空闲飞机
    for(int i=0;i<ENEMY_NUM;i++){
        if(enemys[i].free){
            //空闲飞机进入下一次循环
            continue;
        }
        //遍历所有非空闲的子弹
        for(int j=0;j<BULLET_NUM;j++){
            if(hero.bulltedrs[j].free){
                continue;
            }
            //如果相交，发生碰撞 同时变为空闲状态
            if(enemys[i].rect.intersects(hero.bulltedrs[j].rect)){
                //播放爆炸效果
                //QSound::play(SOUND_BOMB);//播放爆炸声
                enemys[i].free=true;
                hero.bulltedrs[j].free=true;

                for(int k=0;k<BOMB_NUM;k++){
                    if(bombs[k].free){
                        //爆炸状态设置为非空闲
                        bombs[k].free=false;
                        //更新坐标
                        bombs[k].x=enemys[i].x;
                        bombs[k].y=enemys[i].y;
                    break;
                    }
                }
            }
        }
    }

    // 检测英雄飞机与敌机的碰撞
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if (enemys[i].free) continue;

        if (hero.m_rect.intersects(enemys[i].rect)) {
            gameOver = true;
            // 停止游戏
            m_Timer.stop();

            // 弹出失败提示框
            QMessageBox::information(this, "游戏失败", "你的飞机被敌人撞毁啦！", QMessageBox::Ok);

            // 你可以选择重启游戏或关闭窗口等
            // qApp->exit(); // 如果你想直接退出游戏
            return;
        }
    }
}

