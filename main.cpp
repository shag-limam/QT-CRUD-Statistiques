#include "controller.h"
#include <QApplication>
#include "dbaccess.h"
#include "themewidget.h"
#include "ui_themewidget.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLegendMarker>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //Authentification auth ;
    //auth.show() ;
    //DBAccess DBAccess ;
    //DBAccess.open();
    //DBAccess.close();
    DBAccess* dbaccess = DBAccess::getInstance();
    dbaccess->open();
    Controller controller;
    controller.execute();
    dbaccess->close();
    return a.exec();

    // Open the SQLite database
//            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//            db.setDatabaseName("C:\\Users\\y77y1\\Music\\users_sqlite.db");
//            if (!db.open()) {
//                qDebug() << "Failed to open database";
//                return 1;
//            }

//            // Query the database to retrieve the data
//            QSqlQuery query;
//            if (!query.exec("SELECT COUNT(*) AS nb_etudiants, GROUP_CONCAT(DISTINCT filliere) AS filieres FROM etudiants GROUP BY filliere")) {
//                qDebug() << "Failed to execute query";
//                return 1;
//            }


//            // Create a bar series
//            QBarSeries *series = new QBarSeries();
//            QChart *chart = new QChart();
//            // Loop through the query results and add bar sets to the series
//               while (query.next()) {
//                   int nb_etudiants = query.value(0).toInt();
//                   QString filieres = query.value(1).toString();
//                   QBarSet *set = new QBarSet(filieres);
//                   *set << nb_etudiants;
//                   series->append(set);

//               }


//            // Create a chart view and set the series

//            chart->addSeries(series);

//            QFont font;
//                font.setPixelSize(18);

//            chart->setTitleFont(font);
//            chart->setFont(font);
//            chart->setTitleBrush(QBrush(Qt::black));
//            chart->setTitle("Nombre d'etudiant par filiere ");
//            chart->setAnimationOptions(QChart::AllAnimations);


//            QChartView *chartView = new QChartView(chart);
//            //QBarCategoryAxis *axis = new QBarCategoryAxis();
//             chart->createDefaultAxes();
//             chartView->chart()->setAxisX(new QBarCategoryAxis(), series);
//             chartView->chart()->setAxisY(new QValueAxis(), series);
//             chart->legend()->setVisible(true);
//             chart->legend()->setAlignment(Qt::AlignBottom);


//            // Set the chart title
//            chartView->setRenderHint(QPainter::Antialiasing);
//            // Set the axis labels

//            // Create a main window and set the chart view as its central widget
//            QMainWindow mainWindow;
//            mainWindow.setCentralWidget(chartView);
//            mainWindow.resize(800, 600);
//            mainWindow.show();

//            return a.exec();

}

