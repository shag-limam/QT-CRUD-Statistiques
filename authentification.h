#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QMainWindow>
#include "uimain.h"


namespace Ui {
class Authentification;
}

class Authentification : public QMainWindow, public UImain
{
    Q_OBJECT

public:
    explicit Authentification(QWidget *parent = nullptr);
    /* Ce second constructeur
         * permet de connecter le controleur à la
         * fenêtre
         */
    ~Authentification();
    Authentification(QObject *controller);
    QString getLogin() ;
    QString getPassword() ;

    void ClearAuth() ;

private slots:

    void on_pushButtonSubmit_clicked();

signals:
    void submitClicked();

private:
    Ui::Authentification *ui;
};

#endif // AUTHENTIFICATION_H
