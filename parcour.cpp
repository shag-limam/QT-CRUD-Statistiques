#include "parcour.h"
#include "ui_parcour.h"

parcour::parcour(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::parcour)
{
    ui->setupUi(this);
}

parcour::~parcour()
{
    delete ui;
}
