#ifndef DANGEROUSOBJECT_TABLEWIDGET_H
#define DANGEROUSOBJECT_TABLEWIDGET_H

#include <QtWidgets>

class TableWidget: public QWidget {
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = nullptr);
    void operator+= (String object);

};


#endif