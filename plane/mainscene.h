#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>

class Mainscene : public QWidget
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);
    ~Mainscene();



    void initScene();

};
#endif // MAINSCENE_H
