//
// Created by Dmitry on 29.11.2021.
//

#include "GUI.h"
#include <QtWidgets>
#include <QImage>
#include "Views/ClickableLabel/ClickableLabel.h"
#include "Views/TableWidget/TableWidget.h"
#include <iostream>


GUI::GUI(QWidget *parent): QWidget(parent) {
    this->imageLabel = new ClickableLabel();
    this->table = new TableWidget();
  
    connect(imageLabel, SIGNAL(clicked()), SLOT(buttonPushed()));
    // auto *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    auto *mainLayout = new QHBoxLayout();
    
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(table);
    this->setLayout(mainLayout);
    this->initGUI();
    this->initColor();
}

void GUI::initGUI() {
    setImage("1.jpg");
    setWindowTitle(tr("Dangerous object searcher"));
}

void GUI::initColor() {
    QPalette Pal(palette());
    Pal.setColor(QPalette::Window, QColor::fromRgb(27,33,45));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

}

void GUI::buttonPushed() {
    auto fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Address Book"), "",
                                                    tr("Image (*.jpg *.png *.bmp);;All Files (*)"));
    if(fileName.toStdString() == "")
        return;
    setImage(fileName);

}

void GUI::setImage(QString imagePath){
    auto *image = new QPixmap(imagePath);
    const int radius = 30;
    QImage out(image->width(), image->height(), QImage::Format_ARGB32);
    out.fill(Qt::transparent);
    QBrush brush(*image);
    QPen pen;
    pen.setColor(Qt::darkGray);
    pen.setJoinStyle(Qt::RoundJoin);
    QPainter painter(&out);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRoundedRect(0, 0, image->width(), image->height(), radius, radius);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap::fromImage(out.scaled(400,600, Qt::KeepAspectRatio )));
    table->setFixedSize(imageLabel->height(),300);

}