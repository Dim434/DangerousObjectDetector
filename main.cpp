#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"
#include <QApplication>
#include "Views/GUI/GUI.h"
using namespace std;
using namespace cv;
// изображение для тестирования
// 640 пикселей в ширину и 480 в высоту
// 3 канала (цветное изображение)

int main(int argc, char** argv)
{
    QApplication qapp(argc, argv);
    GUI gui;
    gui.show();
    return qapp.exec();
}