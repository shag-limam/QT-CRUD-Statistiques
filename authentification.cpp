#include "authentification.h"
#include "ui_authentification.h"

Authentification::Authentification(QObject *controller)
    : ui(new Ui::Authentification)
{
    qDebug ("Création/Initialisation de la fenêtre d'authentification ...");
    ui->setupUi(this);
   connect(ui->pushButtonSubmit, SIGNAL(clicked()), controller, SLOT(onSubmitAuthentification()) );
   connect(ui->pushButtonCancel,SIGNAL(clicked()),controller,SLOT(onCancelAuthentification()) );

}

Authentification::Authentification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Authentification)
{
    ui->setupUi(this);
}



Authentification::~Authentification()
{
    qDebug ("Destruction de la fenêtre d'authentification ...");

    delete ui;
}


QString Authentification::getLogin(){
    return ui->lineEditLogin->text();

}
QString Authentification::getPassword(){
    return ui->lineEditPassWord->text();
}

void Authentification::ClearAuth()
{
    ui->lineEditLogin->clear();
    ui->lineEditPassWord->clear();
}




