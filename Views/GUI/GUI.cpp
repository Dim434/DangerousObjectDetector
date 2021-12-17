//
// Created by Dmitry on 29.11.2021.
//
#include "Views/ClickableLabel/ClickableLabel.h"
#include "Views/TableWidget/TableWidget.h"
#include "GUI.h"
#include "dirent.h"
#include <QtWidgets>
#include <QImage>

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include <boost/algorithm/string.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>

GUI::GUI(QWidget *parent): QWidget(parent) {
    loadCascades();
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
    setImage(std::filesystem::current_path()+"1.jpg");
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
                                                    tr("Open Image"), "",
                                                    tr("Image (*.jpg *.png *.bmp)"));
    if(fileName.toStdString() == "")
        return;
    reccount = 0;
    setImage(fileName);

}

void GUI::setImage(QString imagePath){
    reccount += 1;
    if (reccount > 3)
        exit(1);
    table->clear();
    auto *image = new QPixmap(imagePath);
    if (image->width() == 0){
        if(boost::ends_with(imagePath.toStdString(), ".png")){
            system((std::string("mv ") + imagePath.toStdString() + std::string(" ") + std::string(boost::erase_all_copy(imagePath.toStdString(), ".png")) + std::string(".jpg")).c_str());
            setImage(QString((boost::erase_all_copy(imagePath.toStdString(), ".png")+".jpg").c_str()));
        }
        else if(boost::ends_with(imagePath.toStdString(), ".jpg")){
            system((std::string("mv ") + imagePath.toStdString() + std::string(" ") + std::string(boost::erase_all_copy(imagePath.toStdString(), ".jpg")) + std::string(".png")).c_str());
            setImage(QString((boost::erase_all_copy(imagePath.toStdString(), ".jpg")+".png").c_str()));
        }
        return;
    }
    qDebug() << imagePath;
    const int radius = 30;
    QImage out(image->width(), image->height(), QImage::Format_ARGB32);
    qDebug() << image->width() << image->height();
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
    auto pixmap = QPixmap::fromImage(out.scaled(400,600, Qt::KeepAspectRatio ));
    imageLabel->setPixmap(pixmap);
    table->setFixedSize(imageLabel->height(),300);
    scale = pixmap.width() / (double)image->width();
    detect(imagePath);
}

void GUI::loadCascades(){
    std::vector<std::string> files;
    auto dp = ".";
    struct dirent *entry;
    DIR *dir;
    if((dir = opendir(std::filesystem::current_path().c_str())) != NULL)
        while ((entry = readdir(dir)) != NULL) {
            std::string fname = entry->d_name;
            std::string pattern = std::string(".xml");
            if(std::equal(pattern.rbegin(), pattern.rend(), fname.rbegin()))
                classifiers[QString(boost::erase_all_copy(fname, ".xml").c_str())] = QString(fname.c_str());

        }
}
void GUI::detect(QString filePath){
    qDebug() << filePath;
    cv::Mat frame = cv::imread(filePath.toStdString().c_str());
    cv::Mat frame_gray;
    cv::cvtColor( frame, frame_gray, cv::COLOR_BGR2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );
  //  cv::imshow("321", frame_gray);
    imageLabel->items.clear();
    for(auto &x: classifiers){
       cv::CascadeClassifier classifier(x.second.toStdString().c_str());
       std::vector<cv::Rect> rects;
       classifier.detectMultiScale(frame_gray, rects);
       
       for(auto &y : rects) {
            imageLabel->items.push_back(QRect(y.x * scale, y.y * scale, y.width * scale, y.height * scale));
            *table += x.first;
            qDebug() << scale;
       }
    }
     imageLabel->update();
}