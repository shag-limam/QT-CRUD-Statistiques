#include "uimain.h"

UImain::UImain()
{
    //setFixedSize(800, 800);
}

//taille : 645
//taille : 367
void UImain::information(QWidget *parent, QString title, QString content)
{
 QMessageBox::information(parent, title, content) ;
}

int UImain::warning(QWidget *parent, QString title, QString content)
{
    return
    QMessageBox::warning(parent, title, content) ;
}

int UImain::question(QWidget *parent, QString title, QString content)
{
    return
            QMessageBox::question(parent, title, content) ;
}
