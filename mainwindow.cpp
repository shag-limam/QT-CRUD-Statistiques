#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::disableButtonUpdate(){
    ui->pushButtonUpdate->setEnabled(false);
    ui->pushButtonCreate->setEnabled(true);
}
void MainWindow::enableButtonUpdate(){
    ui->pushButtonUpdate->setEnabled(true);
    ui->pushButtonCreate->setEnabled(false);
}

void MainWindow::setInfomation(QString firstName, QString lastName,
                               QString genre,QString filliere,QString classe,QString option,QString yearacademic)
{
    ui->lineEditFirstName->setText(firstName);
    ui->lineEditLastName->setText(lastName);
    ui->comboBoxGenre->setCurrentText(genre);
    ui->comboBoxFilliere->setCurrentText(filliere);
    ui->comboBoxClasse->setCurrentText(classe);
    ui->comboBoxOption->setCurrentText(option);
    ui->lineEditYearAcademic->setText(yearacademic);

}
MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QObject *controller)
    : ui(new Ui::MainWindow)
{
    qDebug ("Contruction/Initialisation de la fenêtre principale ...");
    ui->setupUi(this);

    connect(ui->pushButtonClose, SIGNAL(clicked()), controller, SLOT(onCloseMainWindow()));
    //connect(ui->pushButtonDisplay, SIGNAL(clicked()), controller, SLOT(onDisplayMainWindow()));
    connect(ui->pushButtonDisplay, SIGNAL(clicked()), controller, SLOT(onVisualizeChartsAccueil()));

   connect(ui->pushButtonCreate, SIGNAL(clicked()), controller, SLOT(onCreateeMainWindow()));
    connect(ui->pushButtonListe, SIGNAL(clicked()), controller, SLOT(onListeMainWindow()));

    connect(ui->pushButtonUpdate, SIGNAL(clicked()), controller, SLOT(onUpdateMainWindow()));

   // connect(ui->pushButtonSearch, SIGNAL(clicked()), controller, SLOT(onSearchMainWindow()));
    connect(ui->pushButton, SIGNAL(clicked()), controller, SLOT(importer()));
}



QString MainWindow::getFirstName()
{
    return ui->lineEditFirstName->text();
}

QString MainWindow::getLastName()
{
    return ui->lineEditLastName ->text();
}

QString MainWindow::getGenre()
{
    return ui->comboBoxGenre->currentText();
}
QString MainWindow::getFilliere()
{
    return ui->comboBoxFilliere->currentText();
}
QString MainWindow::getClasse()
{
    return ui->comboBoxClasse->currentText();
}
QString MainWindow::getOption()
{
    return ui->comboBoxOption->currentText();
}
QString MainWindow::getYearacademic()
{
    return ui->lineEditYearAcademic->text();
}

void MainWindow::cleanForm()
{
    // Effacer le contenu des champs de texte et de la date
    ui->lineEditFirstName->clear();
    ui->lineEditLastName->clear();
    ui->lineEditYearAcademic->clear();


    // Réinitialiser la liste déroulante à la valeur par défaut

    ui->comboBoxClasse->setCurrentIndex(0);
    ui->comboBoxFilliere->setCurrentIndex(0);
    ui->comboBoxGenre->setCurrentIndex(0);
    ui->comboBoxOption->setCurrentIndex(0);
}
