#include "etudiantmodel.h"
#include "etudiant.h"
#include <QMetaType>
#include <QtSql/QSqlField>
#include <QtDebug>
#include<QItemSelection>

PersonModel::PersonModel()
{

    selectionModel = new QItemSelectionModel(this);
    dbaccess=DBAccess::getInstance();
}
PersonModel::~PersonModel()
{
    delete dbaccess;
}
void PersonModel::create(Person person)
{

    dbaccess->open();
    QSqlQuery query(dbaccess->database());
    query.prepare("INSERT INTO etudiants (firstname, lastname,genre,class,filliere,option,yearacademic) "
                  "VALUES (:firstname, :lastname, :genre,:classe,:filliere,:option,:yearacademic)");
    query.bindValue(":firstname", person.getFirstname());
     query.bindValue(":lastname", person.getLastname());
     query.bindValue(":genre", person.getGenre());
     query.bindValue(":filliere", person.getFilliere());
     query.bindValue(":classe", person.getClasse());
     query.bindValue(":option", person.getOption());
     query.bindValue(":yearacademic", person.getYearacademic());

    query.exec();
    qDebug("Lancement de reauet insert");
    dbaccess->close();
    readAll();
    // recupère les nouvelles données de la base ...
}

Person PersonModel::read(int id)
{
    Person person;

    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("SELECT * FROM etudiants WHERE id=:id");
    query.bindValue(":id", id);

    query.exec();

    if (query.next())
    {
        person.setId(query.record().field("id").value().toInt());
        person.setFirstname(query.record().field("firstname").value().toString());
        person.setLastname(query.record().field("lastname").value().toString());
        person.setGenre(query.record().field("genre").value().toString());
        person.setFilliere(query.record().field("filliere").value().toString());
        person.setClasse(query.record().field("classe").value().toString());
        person.setoOption(query.record().field("option").value().toString());
        person.setYearacademic(query.record().field("yearacademic").value().toString());
    }

    dbaccess->close();
    //readAll();
    return person;
}

void PersonModel::_delete(int id)
{
    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("DELETE FROM etudiants WHERE id=:id");
    query.bindValue(":id", id);

    query.exec();

    dbaccess->close();
    readAll();// recupère les nouvelles données de la base ...
}

void PersonModel::readAll()
{
    dbaccess->open() ;
    QSqlDatabase database = dbaccess->database() ;
    this->setQuery("select id,firstname, lastname,genre,class,filliere,option,yearacademic from etudiants", database);
    this->setHeaderData(0, Qt::Horizontal, tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, tr("First name"));
    this->setHeaderData(2, Qt::Horizontal, tr("Last name"));
    this->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    this->setHeaderData(4, Qt::Horizontal, tr("Classe"));
    this->setHeaderData(5, Qt::Horizontal, tr("Filliere"));
    this->setHeaderData(6, Qt::Horizontal, tr("Option"));
    this->setHeaderData(7, Qt::Horizontal, tr("YearAcademic"));

    dbaccess->close() ;
}

void PersonModel::readOnly(int id )
{

    dbaccess->open() ;
    QSqlDatabase database = dbaccess->database() ;
    QSqlQuery query(database);
    //
    QString queryStr = "select id,firstname, lastname,genre,class,filliere,option,yearacademic from etudiants where id= ?";
    query.prepare(queryStr);
    query.addBindValue(id);
    //query.exec();
    query.exec();
    //this->setQuey("select id,firstname,lastname, country, birthdate from t_persons where id=25", database);
    //this->bindValue(":id", 3, Qt::EditRole);
    this->setQuery(query);
    this->setHeaderData(0, Qt::Horizontal, tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, tr("First name"));
    this->setHeaderData(2, Qt::Horizontal, tr("Last name"));
    this->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    this->setHeaderData(4, Qt::Horizontal, tr("Classe"));
    this->setHeaderData(5, Qt::Horizontal, tr("Filliere"));
    this->setHeaderData(6, Qt::Horizontal, tr("Option"));
    this->setHeaderData(7, Qt::Horizontal, tr("YearAcademic"));

    dbaccess->close() ;

}

void PersonModel::readOnly(QString id)
{

    dbaccess->open() ;
    QSqlDatabase database = dbaccess->database() ;
    QSqlQuery query(database);
    //query.prepare("SELECT id, nom, prenom,sexe,classe,filiere,option,anneeAcademic,departement from etudiants WHERE nom=:id OR prenom=:id OR classe=:id OR id=:id");
    QString queryStr = "select id,firstname, lastname,genre,class,filliere,option,yearacademic from etudiants where firstname=:id OR lastname=:id OR class=:id OR id=:id";
    query.prepare(queryStr);
    //query.bindValue(id);
    query.bindValue(":id",id);
    //query.exec();
    query.exec();
    //this->setQuey("select id,firstname,lastname, country, birthdate from t_persons where id=25", database);
    //this->bindValue(":id", 3, Qt::EditRole);
    this->setQuery(query);
    this->setHeaderData(0, Qt::Horizontal, tr("ID"));
    this->setHeaderData(1, Qt::Horizontal, tr("First name"));
    this->setHeaderData(2, Qt::Horizontal, tr("Last name"));
    this->setHeaderData(3, Qt::Horizontal, tr("Genre"));
    this->setHeaderData(4, Qt::Horizontal, tr("Classe"));
    this->setHeaderData(5, Qt::Horizontal, tr("Filliere"));
    this->setHeaderData(6, Qt::Horizontal, tr("Option"));
    this->setHeaderData(7, Qt::Horizontal, tr("YearAcademic"));

    dbaccess->close() ;


}



void PersonModel::remove()
{

    //supprimer l'element selectionne
    //QItemSelectionModel -> QModelIndex
    //Delete
    dbaccess->open();
    QModelIndex currentIndex = selectionModel->currentIndex();
    qDebug()<<"Index is valide "<<currentIndex.row() ;

    qDebug() << "model is selected : " << selectionModel->isSelected(currentIndex);
    qDebug() << "index is valid : " << currentIndex.isValid();
    qDebug() << "index is valid : " << currentIndex.row();



    if(currentIndex.isValid()){
        // valide si un élément est sélectionné ...
        int ligne = currentIndex.row();
        QSqlRecord record = this->record(ligne);
        int id = record.field(0).value().toInt();

        QSqlQuery query (dbaccess->database());

        //
        query.prepare("DELETE FROM etudiants WHERE id = :id_m");
        query.bindValue(":id_m",id);
        query.exec();

    }
    dbaccess->close();
    readAll();

}

void PersonModel::update(Person person)
{
    dbaccess->open();
    QSqlQuery query(dbaccess->database());

      query.prepare("UPDATE etudiants SET firstname=:firstname, lastname=:lastname, genre=:genre,filliere=:filliere,  class=:class, option=:option, yearacademic=:yearacademic WHERE id=:id");
       query.bindValue(":id", person.getId());
       query.bindValue(":firstname", person.getFirstname());
       query.bindValue(":lastname", person.getLastname());
       query.bindValue(":genre", person.getGenre());
       query.bindValue(":filliere", person.getFilliere());
       query.bindValue(":class", person.getClasse());
       query.bindValue(":option", person.getOption());
       query.bindValue(":yearacademic", person.getYearacademic());
    query.exec();
    //readAll();
    dbaccess->close();
}

QList<Person> PersonModel::list()
{
    Person person;
    QList<Person>persons;

    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("SELECT * FROM etudiants");
    query.exec();

    while (query.next())
    {

          person.setId(query.record().field("id").value().toInt());
          person.setFirstname(query.record().field("firstname").value().toString());
          person.setLastname(query.record().field("lastname").value().toString());
          person.setGenre(query.record().field("genre").value().toString());
          person.setFilliere(query.record().field("filliere").value().toString());
          person.setClasse(query.record().field("classe").value().toString());
          person.setoOption(query.record().field("option").value().toString());
          person.setYearacademic(query.record().field("yearacademic").value().toString());

        persons.push_back(person);
    }

    dbaccess->close();

    return persons;
}
