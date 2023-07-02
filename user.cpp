#include "user.h"

User::User(){}

User::User(int id, QString login, QString passWord){
    this->id = id ;
    this->login = login;
    this->passWord = passWord ;
}

int User::getId()
{
    return id ;
}

QString User::getLogin()
{
    return login ;
}

QString User::getPassword()
{
    return passWord ;
}

void User::setId(int id)
{
    this->id = id ;
}

void User::setLogin(QString login)
{
    this->login = login ;
}

void User::setPassword(QString passWord)
{
    this->passWord = passWord ;
}
