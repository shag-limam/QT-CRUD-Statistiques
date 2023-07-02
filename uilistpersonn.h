#ifndef UILISTPERSONN_H
#define UILISTPERSONN_H

#include <QMainWindow>
#include <QTableView>
#include "uimain.h"
#include "person.h"
#include "etudiantmodel.h"
#include <QAbstractTableModel>
namespace Ui {
class UIListPersonn;
}

class UIListPersonn : public QMainWindow, public UImain
{
    Q_OBJECT

public:
    explicit UIListPersonn(QWidget *parent = nullptr);
    UIListPersonn(QObject *controller);
    ~UIListPersonn();
    //By HK
    //QTableView* getTableView();
    //End
    //void setTableViewModel(QAbstractTableModel* model);
    void setTableViewModel(PersonModel* model);
     QString onSearchtheme();
private:
    Ui::UIListPersonn *ui;
};

#endif // UILISTPERSONN_H
