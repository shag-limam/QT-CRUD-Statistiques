#ifndef UIPARCOUR_H
#define UIPARCOUR_H

#include <QMainWindow>
#include "uimain.h"
namespace Ui {
class uiParcourr;
}

class uiParcourr : public QMainWindow,public UImain
{
    Q_OBJECT

public:
    explicit uiParcourr(QWidget *parent = nullptr);
    uiParcourr(QObject *controller);

    QString getFile();
    void setFile(QString fi);
    ~uiParcourr();




private:
    Ui::uiParcourr *ui;
};

#endif // UIPARCOUR_H
