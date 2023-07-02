#include "etudiant.h"

Person::Person()
{

}

Person::Person(QString firstname, QString lastname
               ,QString genre,QString filliere,QString classe,QString option,QString yearacademic){
    this->firstname = firstname ;
    this->lastname = lastname ;
    this->genre = genre ;
    this->filliere = filliere ;
    this->classe = classe ;
    this->option = option ;
    this->yearacademic = yearacademic ;

}


Person::Person(int id, QString firstname, QString lastname
               ,QString genre,QString filliere,QString classe,QString option,QString yearacademic)
{
    this->id = id ;
    this->firstname = firstname ;
    this->lastname = lastname ;
    this->genre = genre ;
    this->filliere = filliere ;
    this->classe = classe ;
    this->option = option ;
    this->yearacademic = yearacademic ;
}
int Person::getId(){
    return id ;
}

//

QString Person::getFirstname() {
    return firstname ;
}
QString Person::getLastname(){
    return lastname ;
}
QString Person::getGenre(){
    return genre ;
}
QString Person::getFilliere(){
    return filliere ;
}
QString Person::getClasse(){
    return classe ;
}

QString Person::getOption(){
    return option ;
}
QString Person::getYearacademic(){
    return yearacademic ;
}
