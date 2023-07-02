#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include "dbaccess.h"
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class Ui_ThemeWidgetForm;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class ThemeWidget;
}

class ThemeWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThemeWidget(QWidget *parent = nullptr);
    ThemeWidget(QObject* controller);

    ~ThemeWidget();

     void initialise();
private slots:
    void updateUI();
    void onChoose();

private:
    void populateThemeBox();
    void populateAnimationBox();
    void populateLegendBox();
    void connectSignals();



    QChart *createAreaChartFiliere() const;
    QChart *createBarChartFiliere() const;
    QChart *createPieChartFiliere() const;
    QChart *createSplineChartFiliere() const;//test
    QChart *createLineChartFiliere() const;//test
    QChart *createScatterChartFiliere() const; //test

    QChart *createAreaChartClass() const;
    QChart *createBarChartClass() const;
    QChart *createPieChartClass() const;
    QChart *createLineChartClass() const;//test


    QChart *createAreaChartSexe() const;
    QChart *createBarChartSexe() const;
    QChart *createPieChartSexe() const;
    QChart *createLineChartSexe() const;//test


    //QChart *createSplineChart() const;
//    QChart *createScatterChart() const;



private:
    QList<QChartView *> m_charts;
    DBAccess* dbaccess;

    Ui::ThemeWidget *m_ui;
};

#endif // THEMEWIDGET_H
