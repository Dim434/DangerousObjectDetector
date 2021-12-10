//
// Created by Dmitry on 29.11.2021.
//

#ifndef DANGEROUSOBJECTSEARCHER_GUI_H
#define DANGEROUSOBJECTSEARCHER_GUI_H
#include <QtWidgets>


class GUI : public QWidget
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = nullptr);
public slots:
    void buttonPushed();

private:
    QLabel *imageLabel;
    void initColor();


};

#endif //DANGEROUSOBJECTSEARCHER_GUI_H
