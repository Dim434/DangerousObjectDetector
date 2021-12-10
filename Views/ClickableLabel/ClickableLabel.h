#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#import <Qt>
#import <QWidget>
#include <QLabel>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel( const QString& text="", QWidget* parent=nullptr );
    ~ClickableLabel();
signals:

    void clicked();
protected:

    void mousePressEvent(QMouseEvent* event);
};
#endif