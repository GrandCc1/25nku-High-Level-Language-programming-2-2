#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "bulltedr.h"
#include "enemyplane.h"
#include "bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏 用于启动计时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //重写绘图时间
    void paintEvent(QPaintEvent *);
    //重写鼠标移动
    void mouseMoveEvent(QMouseEvent *);
    //敌人出场
    void enemyToScene();
    //碰撞检测
    void collisionDetection();
    //敌机数组
    EnemyPlane enemys[ENEMY_NUM];
    int m_recorder;
    Map map;//地图对象
    HeroPlane hero;//英雄飞机对象
    //定时器
    QTimer m_Timer;
    Bulltedr t_bulltedr;
    Bomb bombs[BOMB_NUM];
    bool gameOver = false;
    int m_score = 0;


};
#endif // MAINSCENE_H
