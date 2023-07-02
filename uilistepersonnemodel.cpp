#include "uilistepersonnemodel.h"

UIListePersonneModel::UIListePersonneModel()
{
    personModel = nullptr ;
    person = nullptr ;
    model = nullptr ;
    // Ajouter les en-têtes de colonnes

    //uilistepersonneModel->setHorizontalHeaderLabels({"ID", "First Name", "Last Name", "Birthdate", "Country"});
}

QStandardItemModel* UIListePersonneModel::display()
{
    //model = new QStandardItemModel();
    // Ajouter des en-têtes de colonnes
    model->setHorizontalHeaderLabels(QStringList() << "ID "<< "First Name" << "Last Name" <<"genre"<<"filliere"<<"classe");
    QList<Person> personList =  personModel->list() ;
    // Parcourir la QList de personnes
    for(int i = 0; i < personList.size(); i++) {
        Person currentPerson = personList.at(i);
        QString currentID =QString::number(currentPerson.getId()) ;
        QString currentFirstName = currentPerson.getFirstname() ;
        QString currentLastName = currentPerson.getLastname() ;
        QString currentGenre = currentPerson.getGenre();
        QString currentFilliere= currentPerson.getFilliere();
        QString currentClasse = currentPerson.getClasse();


        // Créer des éléments de données pour chaque propriété de personne
        QStandardItem* idNameItem = new QStandardItem(currentID);
        QStandardItem* firstNameItem = new QStandardItem(currentFirstName);
        QStandardItem* lastNameItem = new QStandardItem(currentLastName);
        QStandardItem* genreItem = new QStandardItem(currentGenre);
        QStandardItem* filliereItem = new QStandardItem(currentFilliere);
        QStandardItem* classeItem = new QStandardItem(currentClasse);

        // Ajouter les éléments de données à la ligne actuelle
        QList<QStandardItem*> rowItems;
        rowItems <<idNameItem << firstNameItem << lastNameItem << genreItem << filliereItem<<classeItem;
        model->appendRow(rowItems);
    }

    // Définir le modèle pour le tableView
    //ui->tableView->setModel(model);
    return model ;
}
