#ifndef UIMAIN_H
#define UIMAIN_H
#include <QWidget>
#include<QMessageBox>
#include<QInputDialog>
class UImain
{
public:
    UImain();
    void information (QWidget* parent, QString title, QString content) ;
    int warning (QWidget* parent, QString title, QString content) ;
    int question (QWidget* parent, QString title, QString content) ;
     //
    //


};

#endif // UIMAIN_H
