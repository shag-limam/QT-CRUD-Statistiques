#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uimain.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public UImain
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*Ce second constructeur
     *permet de connecter le controleur à la
     *fenêtre
     */
    MainWindow(QObject *controller) ;
    QString getFirstName() ;
    QString getLastName() ;
//    QString getBirthday();
//    QString getCountry();
    QString getGenre();
    QString getFilliere();
    QString getClasse();
    QString getOption();
    QString getYearacademic();

    void cleanForm() ;
    void disableButtonUpdate();
    void enableButtonUpdate();
    void setInfomation(QString firstName, QString lastName,QString genre,
                       QString filliere,QString classe,QString option,QString yearacademic);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
