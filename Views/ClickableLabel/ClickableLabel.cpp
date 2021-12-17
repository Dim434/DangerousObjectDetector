//
// Created by Dmitry on 09.12.2021.
//

#include "ClickableLabel.h"
#include <QPainter>
#include <QtWidgets>

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent): QLabel(parent) {
    setText(text);
}

ClickableLabel::~ClickableLabel() { }

void ClickableLabel::mousePressEvent(QMouseEvent* event) {

    emit clicked();
}
void ClickableLabel::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);
    for (auto &y : items){
        qDebug() << QString("drawn");
        QPainter painter(this);
        painter.setBrush(Qt::DiagCrossPattern);
        QPen pen;
        pen.setColor(Qt::green);
        pen.setWidth(5);
        painter.setPen(pen);
        painter.drawRect(y);
    }
}