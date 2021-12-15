//
// Created by Dmitry on 29.11.2021.
//

#ifndef DANGEROUSOBJECTSEARCHER_GUI_H
#define DANGEROUSOBJECTSEARCHER_GUI_H
#include <QtWidgets>
#include "Views/ClickableLabel/ClickableLabel.h"
#include "Views/TableWidget/TableWidget.h"


class GUI : public QWidget
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = nullptr);
public slots:
    void buttonPushed();

private:
    ClickableLabel *imageLabel;
    TableWidget *table;
    void initColor();
    void initGUI();
    void setImage(QString imagePath);

};

#endif //DANGEROUSOBJECTSEARCHER_GUI_H
