#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_txtCount->setText("0");

    // updating displayed text when count changes
    connect(&m_Count, SIGNAL(valueChanged(int)), this, SLOT(on_count_value_changed(int)));

    //  generators for tests, uncomment the section below to get prebuilt generators
    m_lstGenerator.push_back(new CGenerator(100, &m_Timer, &m_Count, 50));
    // m_lstGenerator.push_back(new CGenerator(5, &m_Timer, &m_Count));

    // defining the main timer used to trigger generators
    m_Timer.setInterval(10);
    m_Timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;

    foreach(CGenerator* pGen, m_lstGenerator)
    {
        if(pGen)
        {
            delete pGen;
        }
    }
}

void MainWindow::on_m_btnAdd_clicked()
{
    m_Count.Increment();


}

void MainWindow::on_count_value_changed(int nNewValue)
{
    ui->m_txtCount->setText(QString::number(nNewValue));
}
