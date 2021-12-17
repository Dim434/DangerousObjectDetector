//
// Created by Dmitry on 29.11.2021.
//

#ifndef DANGEROUSOBJECTSEARCHER_GUI_H
#define DANGEROUSOBJECTSEARCHER_GUI_H
#include <QtWidgets>
#include "Views/ClickableLabel/ClickableLabel.h"
#include "Views/TableWidget/TableWidget.h"
#include <map>

class GUI : public QWidget
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = nullptr);
public slots:
    void buttonPushed();

private:
    double scale = 0.0;
    ClickableLabel *imageLabel;
    TableWidget *table;
    QString imagePath;
    std::map<QString, QString> classifiers;
    void initColor();
    void initGUI();
    void setImage(QString imagePath);
    void detect(QString filePath);
    void loadCascades();
    int reccount = 0;
};

#endif //DANGEROUSOBJECTSEARCHER_GUI_H
