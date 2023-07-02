#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QObject>

class Person{
public:
    Person();
    Person(QString firstname, QString lastname,  QString genre,QString filliere,QString classe,QString option,QString yearacademic);
    Person(int id, QString firstname, QString lastname ,QString genre,QString filliere,QString classe,QString option,QString yearacademic);
    int getId();
    QString getFirstname();
    QString getLastname() ;
    QString getGenre();
    QString getFilliere();
    QString getClasse();
    QString getOption();
    QString getYearacademic();


    void setId(int id){ this->id = id ;}
    void setFirstname(QString firstname){this->firstname = firstname ;}
    void setLastname(QString lastname){this->lastname = lastname ;}
    void setGenre(QString genre){ this->genre = genre ; }
    void setFilliere(QString filliere){ this->filliere = filliere ; }
    void setClasse(QString classe){ this->classe = classe ; }
    void setoOption(QString option){ this->option = option ; }
    void setYearacademic(QString yearacademic){ this->yearacademic = yearacademic ; }


private:
    int id;
    QString firstname;
    QString lastname;
    QString genre;
    QString filliere;
    QString classe;
    QString option;
    QString yearacademic;
};


#endif // ETUDIANT_H
