#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"
#include "authentification.h"
#include "usermodel.h"
#include "edit.h"
#include "uilistpersonn.h"
#include "uiparcour.h"
#include "uilistepersonnemodel.h"
#include "etudiantmodel.h"
#include <QDate>
#include "themewidget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include<QVariant>
#include<QTextStream>
#include<QStringList>
#include <QFileDialog>
class Controller : public QObject
{
    Q_OBJECT
   private:
       /* Le controleur dispose des références
        * aux fenêtres qu'il gère.
        */
       Authentification* authentification;
       MainWindow* mainWindow;
       UIListPersonn* uIListPersonn ;
       //UIListePersonneModel* uIListePersonneModel ;
       PersonModel* personModel ;
       UserModel* um ;
       ThemeWidget* tw ;
       uiParcourr* is;


   public:
       explicit Controller(QObject *parent = nullptr);
       ~Controller();
       void execute ();

   private slots:
       // Les slots de la fenêtre MainWindow
       void onCloseMainWindow();
       void onDisplayMainWindow();

       void onCreateeMainWindow();
       void onListeMainWindow();
       void onUpdateMainWindow();
       void onSearchMainWindow();
       void importer();
       void choisir();
       void enregistrer();
       void onclose();

       // Les slots de la fenêtre Authentification
       void onSubmitAuthentification();
       void onCancelAuthentification();

       //Les slots de la fenetre de UIListePersonne

       //void onActuUIListPersonne();

       void onUpdateUIListPersonne();
       void onDeleteUIListPersonne();
       void onRetourUIListPersonne();

       //

       void onVisualizeChartsAccueil();
       void onCloseThemewidget();
       void onSearchthemewidget();
       void onSearch();




};
#endif // CONTROLLER_H
