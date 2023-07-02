#include "controller.h"


Controller::Controller(QObject *parent) : QObject(parent),
    authentification(nullptr), mainWindow(nullptr), um(new UserModel), uIListPersonn(nullptr)
  ,personModel(new PersonModel),is(nullptr),tw(nullptr)
{
    qDebug ("Lancement du controller ...");
}
//Main Window
void Controller:: onCloseMainWindow(){
    bool bcloseWindow(true);
    /*
           if(QMessageBox::Yes == mainWindow->question(nullptr,"Save unchanged data","The data have changed. Exit anyway ?")){
               bcloseWindow = true ;
           }

*/
           if (bcloseWindow)
              {
                  mainWindow->close();
                //  authentification->resize(1000, 700);
                  authentification->show();
              }

}


void Controller::onDisplayMainWindow(){
//    mainWindow->information(nullptr,
//                            "Person information",
//                            mainWindow->getFirstName() + " " +
//                            mainWindow->getLastName() + " was born in " +

//                            mainWindow->getGenre() + "  " +
//                            mainWindow->getFilliere() + "  " +
//                            mainWindow->getClasse() +
//                            " !");


//        QMainWindow *window = new QMainWindow();
//        ThemeWidget *widget = new ThemeWidget();
//        window->setCentralWidget(widget);
//       // window->resize(1000, 700);
//        window->show();
//        mainWindow->close();
    tw=new ThemeWidget(this);
    tw->show();
    mainWindow->hide();

}

//OncreateMaine

void Controller::onCreateeMainWindow()
{
    qDebug ("Clicked du create ...");
    QString firstname = mainWindow->getFirstName() ;
    QString lastname= mainWindow->getLastName() ;
    QString genre= mainWindow->getGenre();
    QString filliere= mainWindow->getFilliere();
    QString classe= mainWindow->getClasse();
    QString option= mainWindow->getOption();
    QString yearacademic= mainWindow->getYearacademic();

    if(!firstname.isEmpty() || !lastname.isEmpty() ){

        Person person(firstname,lastname,genre,filliere,classe,option,yearacademic);

        personModel->create(person);

        mainWindow->warning(nullptr,"   Ajout de personne   ","   Ajout reussi   ");
        mainWindow->cleanForm();

   }else{
        mainWindow->warning(nullptr,"   Alert   ","      Forumlaire imcomplet     ");
    }
}

void Controller::onListeMainWindow()
{
    qDebug ("Clicked du Liste ...");

    //Ici la vue est cree
    uIListPersonn = new UIListPersonn(this);

    //connecter la vue et le model
    uIListPersonn->show();
    uIListPersonn->setTableViewModel(personModel);
    personModel->readAll();
    uIListPersonn->show();
    mainWindow->close();
    //mainWindow->close();

    //

}

void Controller::onUpdateMainWindow()
{
 qDebug ("Clicked on update button ") ;
 QString firstname = mainWindow->getFirstName() ;
 QString lastname= mainWindow->getLastName() ;
 QString genre= mainWindow->getGenre();
 QString filliere= mainWindow->getFilliere();
 QString classe= mainWindow->getClasse();
 QString option= mainWindow->getOption();
 QString yearacademic= mainWindow->getYearacademic();
 if(!firstname.isEmpty() || !lastname.isEmpty() ){

     QModelIndex index = personModel->getSelectionModel()->currentIndex() ;
     int id= personModel->record(index.row()).field(0).value().toInt();
     //int id = index.row().field(0).value().toInt() ;
     Person person(id,firstname,lastname,genre,filliere,classe,option,yearacademic);

     personModel->update(person);

     mainWindow->warning(nullptr,"   Mise a jour","Mise a jours reussi avec success");
     personModel->readAll();
     uIListPersonn->show();

}else{
     mainWindow->warning(nullptr," ","");
 }

}

void Controller::onSearchMainWindow()
{
    qDebug("oooo");
    bool ok ;
    int id = QInputDialog::getInt(nullptr, tr("QInputDialog::getInteger()"),
                                     tr("ID :"), 0, 0, 100, 1, &ok);
    if (ok){
        uIListPersonn = new UIListPersonn(this);
        //uIListPersonn->show();
        uIListPersonn->setTableViewModel(personModel);
        personModel->readOnly(id);
        uIListPersonn->show();
        mainWindow->close();
    }

}


void Controller::importer()
{
 is=new uiParcourr(this);
 is->show();
 mainWindow->hide();
}

//Implementation de methode authentification


void Controller::onCancelAuthentification()
{
    if (QMessageBox::Yes ==
                    mainWindow->question(nullptr,
                        "Confirmation de sortie",
                        "Voulez-vous vraiment quitter l'application ?"))
    {
        authentification->close();

    }
}

/*
void Controller::onActuUIListPersonne()
{
    qDebug("Actuu") ;

    QTableView *tableView =  uIListPersonn->getTableView() ;

    qDebug("Actuu") ;
    tableView->setModel( uIListePersonneModel->display() );

    uIListPersonn->show();


}
*/
//implementation methode liste personne

void Controller::onUpdateUIListPersonne()
{
    qDebug ("Clciker suer Update");
    uIListPersonn->hide();
    mainWindow->enableButtonUpdate();
    mainWindow->show();

    //1-Recuperer les informations de la person selectoinne
    //int ligne = personModel->getSelectionModel()->currentIndex().row();
    QModelIndex index = personModel->getSelectionModel()->currentIndex() ;
    if (index.isValid()){
        int ligne  = index.row();
        int id = personModel->record(ligne).field(0).value().toInt();
        QString firstname = personModel->record(ligne).field(1).value().toString();
        QString lastname = personModel->record(ligne).field(2).value().toString();
       // QString birthdateStr = personModel->record(ligne).field(4).value().toString();
        //QDate birthdate = personModel->record(ligne).field(3).value().toDate();
        QString genre = personModel->record(ligne).field(3).value().toString();
        QString filliere = personModel->record(ligne).field(4).value().toString();
        QString classe = personModel->record(ligne).field(5).value().toString();
        QString option = personModel->record(ligne).field(6).value().toString();
        QString yearacademic = personModel->record(ligne).field(7).value().toString();

        //2-Remplir les champs du formulaire du personne selectionnes avec les infos recents
        mainWindow->setInfomation(firstname, lastname, genre,filliere,classe,option,yearacademic);


    }

    //3-mettre a jour au niveau de la base de donnees.

}

void Controller::onDeleteUIListPersonne()
{
    qDebug ("Clciker suer Delete");

    //personModel->remove();

    if(uIListPersonn->question(nullptr, "Suppressionn", "Etes-vous sur de supprimer ? ")){
        personModel->remove();
        uIListPersonn->information(nullptr, "Suppression", "Suprression Effectuer avec success");
        personModel->readAll();
        //uIListPersonn->show();
    }



}

void Controller::onRetourUIListPersonne()
{
    qDebug ("Clciker suer retour");
    //uIListPersonn = new UIListPersonn(this);
    uIListPersonn->close();
    mainWindow->cleanForm();
    mainWindow->disableButtonUpdate();
    mainWindow->show();



}

void Controller::onVisualizeChartsAccueil() {
    // déclaration et initialisation de la variable "tw"
     tw = new ThemeWidget(this);

    // utilisation de la variable "tw"
    mainWindow->hide();
    tw->show();
}

void Controller::onCloseThemewidget() {
    // Fermer le widget de thème personnalisé
    if (tw != nullptr) {
        delete tw;
        tw = nullptr;
        mainWindow->show();
    }


}



void Controller::onSubmitAuthentification()
{

    qDebug ("Clicked du controller ...");
    QString username = authentification->getLogin();
    QString password = authentification->getPassword();
    bool status =  um->readBy(username,password);
    if(status == true)
    {
        //authentification->information(nullptr, "Authentification", "Welcome to my first Qt Application !");
        mainWindow = new MainWindow (this);
        mainWindow->disableButtonUpdate();
        mainWindow->resize(900, 600);
        mainWindow->show();
        authentification->ClearAuth();
        authentification->hide();
    }
    else
    {
        authentification->warning(nullptr, "Authentification", "Incorrect Login/Password, please try again !");
    }
}






/*

QString login authentification->getLogin(); QString password - authentification->getPassword();
bool status um->read By (login, password);
if (status = true)
{
authentification->information (nullptr, "Authentification", "Welcome to my first Qt Application !");
mainWindow new MainWindow (this); mainWindow->show();
authentification->hide();
}
else
{
authentification->warning (nullptr, "Authentification",
"Incorrect Login/Password, please try again !");
}

*/

void Controller::execute()
{
    authentification = new Authentification(this);
    authentification->show();
}


Controller::~Controller()
{
    qDebug ("Destruction du controller ...");
    if (authentification != nullptr) delete authentification;

    if (mainWindow != nullptr) delete mainWindow;
    if (um != nullptr) delete um;
    if (uIListPersonn != nullptr) delete uIListPersonn;
    if (personModel != nullptr) delete personModel;
    DBAccess::release();
}
void Controller::choisir()
{
    QString fi=QFileDialog::getOpenFileName(nullptr,"ouvrez");
      is->setFile(fi);
}

void Controller::onclose() {
    // Fermer le widget de thème personnalisé
    qDebug ("Clciker suer retour");
    //uIListPersonn = new UIListPersonn(this);
    is->close();
    mainWindow->cleanForm();
    mainWindow->disableButtonUpdate();
    mainWindow->show();
}

void Controller::enregistrer(){

    QString file=is->getFile();
        QXlsx::Document xlsx(file);

            if (xlsx.load())
            {
                qDebug("Fichier bien chargé");
                // Obtenir la première feuille de calcul dans le fichier Excel
                // Lire la valeur de la cellule A1
                QXlsx::Worksheet *worksheet = xlsx.currentWorksheet();

                       // Récupération des données de la feuille courante
                       int rows = worksheet->dimension().rowCount();

                       for(int i=2; i<=rows; i++) {
                               QVariant cellValue1 = worksheet->read(i,1);
                               QVariant cellValue2 = worksheet->read(i,2);
                               QVariant cellValue3 = worksheet->read(i,3);
                               QVariant cellValue4 = worksheet->read(i,4);
                               QVariant cellValue5 = worksheet->read(i,5);
                               QVariant cellValue6 = worksheet->read(i,6);
                               QVariant cellValue7 = worksheet->read(i,7);
                               QVariant cellValue8 = worksheet->read(i,8);
                               Person person(cellValue1.toInt(),cellValue2.toString(),cellValue3.toString(),cellValue4.toString(),cellValue5.toString(),cellValue6.toString(),cellValue7.toString(),cellValue8.toString());

                               personModel->create(person);

                       }

                       is->information(is,"Confirmation","Les étudiants ont été bien enregistrés");

                       is->close();
                       mainWindow->show();


            }


}


void Controller::onSearchthemewidget(){
    uIListPersonn->information(nullptr, "FF","ff");
}

void Controller::onSearch(){
    QString vr=uIListPersonn->onSearchtheme();
    personModel->readOnly(vr);
    uIListPersonn->show();
}
