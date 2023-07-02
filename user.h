#ifndef USER_H
#define USER_H

#include <QObject>

class User
{
private :
    int id ;
    QString login ;
    QString passWord ;

public:
    User() ;
    User(int id, QString login, QString passWord);
    //

    int getId() ;
    QString getLogin()  ;
    QString getPassword() ;
    //
    void setId(int id);
    void setLogin(QString login);
    void setPassword(QString passWord);
    //
    //

};

#endif // USER_H
