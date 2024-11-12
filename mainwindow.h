#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QTimer>

#include "generator.h"
#include "generatormanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_m_btnAdd_clicked();
    void on_count_value_changed(int nNewValue);
    void on_wallet_amount_changed(double fNewValue);
    void on_generator_list_updated();
private:
    Ui::MainWindow *ui;
    CCount m_Count;
    QList<CGenerator*> m_lstGenerator;
    QTimer m_Timer;
    CGeneratorManager m_GenManager;

};
#endif // MAINWINDOW_H
