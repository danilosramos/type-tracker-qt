#ifndef TYPETRACKER_H
#define TYPETRACKER_H

#include <QTime>
#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <vector>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class TypeTracker;
}
QT_END_NAMESPACE

class BaseTypeTracker
{
public:
    BaseTypeTracker();
    virtual ~BaseTypeTracker();

protected:
    QTime counterTime;
    int wordIndex;
    int error;
    int amount;
    float chars;
    bool pastError;
    vector<string> word;
    vector<string> userWord;
};

class TypeTracker : public QMainWindow, public BaseTypeTracker // Classe derivada e janela principal do Qt

{
    Q_OBJECT

public:
    TypeTracker(QWidget *parent = nullptr);
    ~TypeTracker();

private slots:
    void on_pushButton_clicked();
    void updateCounter();

private:
    Ui::TypeTracker *ui;
    QTimer *timer; // Temporizador para atualizar o contador
};

#endif // TYPETRACKER_H
