#ifndef PARCOUR_H
#define PARCOUR_H

#include <QMainWindow>

namespace Ui {
class parcour;
}

class parcour : public QMainWindow
{
    Q_OBJECT

public:
    explicit parcour(QWidget *parent = nullptr);
    ~parcour();

private:
    Ui::parcour *ui;
};

#endif // PARCOUR_H
