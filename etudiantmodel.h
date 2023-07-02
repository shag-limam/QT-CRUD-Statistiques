#ifndef ETUDIANTMODEL_H
#define ETUDIANTMODEL_H

#include "dbaccess.h"
#include "etudiant.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QSqlQueryModel>
#include<QItemSelectionModel>
#include<QModelIndex>
class PersonModel : public QSqlQueryModel
{
private:
     DBAccess* dbaccess;
     QItemSelectionModel* selectionModel ;//permet de savoir a tout moment les informations
     //sur element selectionnee sur la vue
public:
    PersonModel();
      ~PersonModel();

     void create(Person person);
    //bool readBy(QString login, QString password);

     void update(Person Person);
     Person read(int id);
     void _delete (int id);
     void readAll();
     void readOnly(int id);
     void readOnly(QString firstname );
     void readOnlyf(QString  lastname);
     void remove();

     //supprimer l'element selectionne
      //QItemSelectionModel -> QModelIndex
      //Delete
     QItemSelectionModel* getSelectionModel(){
         return selectionModel ;
     };
     QList<Person> list();
};

#endif // ETUDIANTMODEL_H

