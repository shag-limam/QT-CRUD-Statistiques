#ifndef DBACCESS_H
#define DBACCESS_H
#include <QtSql/QSqlDatabase>

class DBAccess{
    private :
        QSqlDatabase db ;
        DBAccess();
        //Cette attribut ne sera attribuer a une instance
        static DBAccess* instance ;

    public:
        static DBAccess* getInstance();
        static void release();
        QSqlDatabase database(){
            return db ;
        }
       bool open();
       void close();
       void loadExcelDataToDatabase();
};

#endif // DBACCESS_H


