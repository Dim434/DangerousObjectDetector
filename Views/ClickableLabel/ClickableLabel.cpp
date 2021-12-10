//
// Created by Dmitry on 09.12.2021.
//

#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent): QLabel(parent) {
    setText(text);
}

ClickableLabel::~ClickableLabel() { }

void ClickableLabel::mousePressEvent(QMouseEvent* event) {

    emit clicked();
}