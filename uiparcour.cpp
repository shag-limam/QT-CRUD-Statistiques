#include "uiparcour.h"
#include "ui_uiparcourr.h"

uiParcourr::uiParcourr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::uiParcourr)
{
    ui->setupUi(this);
}
uiParcourr::uiParcourr(QObject *controller): ui(new Ui::uiParcourr)
{
    ui->setupUi(this);
      connect(ui->pushButton_3, SIGNAL(clicked()), controller, SLOT(choisir()));
     connect(ui->pushButton, SIGNAL(clicked()), controller, SLOT(enregistrer()));
    connect(ui->pushButton_2, SIGNAL(clicked()), controller, SLOT(onclose()));
}
uiParcourr::~uiParcourr()
{
    delete ui;
}
QString uiParcourr::getFile(){
    return   ui->lineEdit->text();
}
void uiParcourr::setFile(QString fi){
    ui->lineEdit->setText(fi);

}


