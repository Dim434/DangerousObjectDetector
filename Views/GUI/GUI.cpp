//
// Created by Dmitry on 29.11.2021.
//

#include "GUI.h"
#include <QtWidgets>
#include <QImage>
#include "Views/ClickableLabel/ClickableLabel.h"
#include <iostream>


GUI::GUI(QWidget *parent)
        : QWidget(parent) {
    auto *nameLabel = new QLabel(tr("Name:"));

    auto *image = new QPixmap("1.jpg");

    this->imageLabel = new ClickableLabel();
    connect(imageLabel, SIGNAL(clicked()), SLOT(buttonPushed()));
    auto *button = new QPushButton();
    imageLabel->setPixmap(*image);
    auto *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLayout->addWidget(imageLabel);
    setLayout(mainLayout);
    setWindowTitle(tr("Dangerous object searcher"));
    initColor();
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
    auto *image = new QPixmap(fileName);
    this->imageLabel->setPixmap(*image);

}
