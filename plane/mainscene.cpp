#include "mainscene.h"
#include "config.h"
Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
}

Mainscene::~Mainscene() {}



void Mainscene::initScene()
{
    //设置窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);
}
