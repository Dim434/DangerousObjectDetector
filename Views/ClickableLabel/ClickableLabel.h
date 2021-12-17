#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <Qt>
#include <QWidget>
#include <QLabel>
#include <vector>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel( const QString& text="", QWidget* parent=nullptr );
    ~ClickableLabel();
    std::vector<QRect> items;
signals:

    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    
};
#endif