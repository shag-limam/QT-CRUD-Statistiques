#include "dbaccess.h"


DBAccess* DBAccess::instance = nullptr ;


DBAccess::DBAccess()
{
    db = QSqlDatabase::addDatabase ("QSQLITE");
   // SQtring nomDB = ""
    db.setDatabaseName("C:\\Users\\y77y1\\Music\\users_sqlite.db");
    qDebug ("Accès à la base de données 'users.db' effectif !");

}


DBAccess* DBAccess::getInstance(){
    if (instance ==nullptr){
        instance = new DBAccess() ;
        return instance;
    }
}

void DBAccess::release()
{
    if(instance != nullptr){
        delete instance ;
    }
}

bool DBAccess::open(){
    if (db.isOpen() == true) return true;
    if (db.open() == true){
        qDebug("Connexion ouverte avec la base de données !"); return true;
    }else{
        qDebug("Echec d'ouverture de la connexion avec la base de données !");
        return false;
    }

}
void DBAccess::close(){
    if (db.isOpen() == false) {
        return;
      }
        qDebug("Fermeture de la connexion effectuée avec succès !");
        db.close();
}



//#include "dbaccess.h"
//#include <QXlsx>
//#include <QDebug>

//DBAccess* DBAccess::instance = nullptr ;

//DBAccess::DBAccess()
//{
//    db = QSqlDatabase::addDatabase ("QSQLITE");
//    db.setDatabaseName("C:\\Users\\y77y1\\Music\\users_sqlite.db");
//    qDebug() << "Accès à la base de données 'users.db' effectif !";
//}

//DBAccess* DBAccess::getInstance(){
//    if (instance ==nullptr){
//        instance = new DBAccess() ;
//        return instance;
//    }
//}

//void DBAccess::release()
//{
//    if(instance != nullptr){
//        delete instance ;
//    }
//}

//bool DBAccess::open(){
//    if (db.isOpen() == true) return true;
//    if (db.open() == true){
//        qDebug() << "Connexion ouverte avec la base de données !";
//        return true;
//    }else{
//        qDebug() << "Echec d'ouverture de la connexion avec la base de données !";
//        return false;
//    }

//}

//void DBAccess::close(){
//    if (db.isOpen() == false) {
//        return;
//    }
//    qDebug() << "Fermeture de la connexion effectuée avec succès !";
//    db.close();
//}


//void DBAccess::loadExcelDataToDatabase()
//{
//    // Chemin vers le fichier Excel
//    QString filePath = "C:\\Users\\y77y1\\OneDrive\\Documents\\MP\\etudiant.xlsx";

//    // Charger le fichier Excel
//    QXlsx::Document xlsx(filePath);

//    // Connexion à la base de données SQLite
//    DBAccess* dbAccess = DBAccess::getInstance();
//    if (dbAccess->open())
//    {
//        int row = 2; // la première ligne est souvent la ligne d'en-tête
//        while (!xlsx.read(row, 1).isNull()) {
//            int id = xlsx.read(row, 1).toInt();
//            QString firstName = xlsx.read(row, 2).toString();
//            QString lastName = xlsx.read(row, 3).toString();
//            QString sexe = xlsx.read(row, 4).toString();
//            QString class = xlsx.read(row, 5).toString();
//            QString filliere = xlsx.read(row, 6).toString();
//            QString option = xlsx.read(row, 7).toString();
//            int yearAcademic = xlsx.read(row, 8).toInt();

//            // Insérer les données dans la base de données
//            QSqlQuery query;
//            query.prepare("INSERT INTO etudiant (id, first_name, last_name, sexe, class, filliere, option, year_academic) VALUES (:id, :firstName, :lastName, :sexe, :class, :filliere, :option, :yearAcademic)");
//            query.bindValue(":id", id);
//            query.bindValue(":firstName", firstName);
//            query.bindValue(":lastName", lastName);
//            query.bindValue(":sexe", sexe);
//            query.bindValue(":class", class);
//            query.bindValue(":filliere", filliere);
//            query.bindValue(":option", option);
//            query.bindValue(":yearAcademic", yearAcademic);
//            query.exec();

//            row++;
//        }
//        dbAccess->close();
//    }
//}



