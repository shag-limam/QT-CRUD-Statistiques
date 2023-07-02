#include "uilistpersonn.h"
#include "ui_uilistpersonn.h"

UIListPersonn::UIListPersonn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIListPersonn)
{
    ui->setupUi(this);
}

UIListPersonn::UIListPersonn(QObject *controller)
    : ui(new Ui::UIListPersonn)
{
    qDebug ("Création/Initialisation de la fenêtre d'UIListPersonn ...");
    ui->setupUi(this);
   connect(ui->pushButtonRetour, SIGNAL(clicked()), controller, SLOT(onRetourUIListPersonne()) );
   connect(ui->pushButtonDelete,SIGNAL(clicked()),controller,SLOT(onDeleteUIListPersonne()) );
   connect(ui->pushButtonUpdate,SIGNAL(clicked()),controller,SLOT(onUpdateUIListPersonne()) );
   //Load
   //connect(ui->pushButton,SIGNAL(clicked()),controller,SLOT(onSearchthemewidget()) );
   connect(ui->pushButton_2,SIGNAL(clicked()),controller,SLOT(onSearch()) );



}

UIListPersonn::~UIListPersonn()
{
    delete ui;
}
/*
QTableView* UIListPersonn::getTableView()
{
    return ui->tableViewListePersonne ;
}
*/
void UIListPersonn::setTableViewModel(PersonModel* model)
{
    ui->tableViewListePersonne->setModel(model);
    ui->tableViewListePersonne->setSelectionModel(model->getSelectionModel()) ;
    ui->tableViewListePersonne->show() ;

}

QString UIListPersonn::onSearchtheme(){
    return ui->lineEdit->text();
}
