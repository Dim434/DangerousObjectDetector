#include "TableWidget.h"
#include <QtWidgets>

TableWidget::TableWidget(QWidget *parent) : QWidget(parent) {
   this->setStyleSheet("QLabel { color : white; }");
}

void TableWidget::operator+=(const QString object){
   auto *label = new QLabel(this);
   label->setText(object);
   layout.addWidget(label);

}
void TableWidget::clear(){
   for (auto &x : this->findChildren<QWidget*>()){
      layout.removeWidget((QWidget*)x);
      x->setParent(NULL);
      delete x;
   }
}