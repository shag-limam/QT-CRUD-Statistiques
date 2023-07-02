#ifndef UILISTEPERSONNEMODEL_H
#define UILISTEPERSONNEMODEL_H

#include "dbaccess.h"
#include "etudiantmodel.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QMetaType>
#include <QtSql/QSqlField>
#include <QtDebug>
#include <QStandardItemModel>
#include <QStringListModel>

class UIListePersonneModel
{
private :
    DBAccess* dbaccess;

    //QStandardItemModel *uilistepersonneModel = new QStandardItemModel();
    //QAbstractItemModel  ;
    //QStandardItemModel *model ;
    QStandardItemModel* model;
    PersonModel *personModel ;
    Person *person ;

public:
    UIListePersonneModel();
    QStandardItemModel* display();
};

#endif // UILISTEPERSONNEMODEL_H
