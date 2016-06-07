#ifndef USERNAME_H
#define USERNAME_H

#include <QDialog>

namespace Ui {
class username;
}

class username : public QDialog
{
    Q_OBJECT

public:
    explicit username(QWidget *parent = 0);
    ~username();

    QString getUserName();


private:
    Ui::username *ui;
};

#endif // username
