#include "usermodel.h"
#include <QMetaType>
#include <QtSql/QSqlField>
#include <QtDebug>

UserModel::UserModel()
{
    //dbaccess = new DBAccess();
    dbaccess = DBAccess::getInstance() ;
}

UserModel::~UserModel()
{
    delete dbaccess;
}

User UserModel::read(int id)
{
    User user;

    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("SELECT * FROM t_users WHERE id=:id");
    query.bindValue(":id", id);

    query.exec();

    if (query.next())
    {
        user.setId(query.record().field("id").value().toInt());
        user.setLogin(query.record().field("login").value().toString());
        user.setPassword(query.record().field("password").value().toString());
    }

    dbaccess->close();

    return user;
}

bool UserModel::readBy(QString login, QString password)
{
    bool status (false);

    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("SELECT * FROM t_users WHERE login=:login AND password=:password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();

    if (query.next()) status = true;

    dbaccess->close();

    return status;
}

void UserModel::create(User user)
{
    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("INSERT INTO t_users (login, password) VALUES (:login, :password)");

    query.bindValue(":login", user.getLogin());
    query.bindValue(":password", user.getPassword());

    query.exec();

    dbaccess->close();
}

void UserModel::update(User user)
{
    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("UPDATE t_users SET login=:login, password=:password WHERE id=:id");

    query.bindValue(":id", user.getId());
    query.bindValue(":login", user.getLogin());
    query.bindValue(":password", user.getPassword());

    query.exec();

    dbaccess->close();
}

void UserModel::_delete(int id)
{
    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("DELETE FROM t_users WHERE id=:id");
    query.bindValue(":id", id);

    query.exec();

    dbaccess->close();
}

QList<User> UserModel::list()
{
    User user;
    QList<User> users;

    dbaccess->open();
    QSqlQuery query(dbaccess->database());

    query.prepare("SELECT * FROM t_users WHERE 1");
    query.exec();

    while (query.next())
    {
        user.setId(query.record().field("id").value().toInt());
        user.setLogin(query.record().field("login").value().toString());
        user.setPassword(query.record().field("password").value().toString());

        users.push_back(user);
    }

    dbaccess->close();

    return users;
}
