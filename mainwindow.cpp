#include "mainwindow.h"
#include "./ui_mainwindow.h"

const constexpr int TIMER_INTERVAL = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_txtCount->setText("0");
    ui->m_txtWalletAmount->setText("0");

    connect(&m_GenManager, SIGNAL(ListUpdated()), this, SLOT(on_generator_list_updated()));

    // updating displayed text when count changes
    connect(&m_Count, SIGNAL(valueChanged(int)), this, SLOT(on_count_value_changed(int)));

    //  generators for tests, uncomment the section below to get prebuilt generators
    m_lstGenerator.push_back(new CGenerator(100, &m_Timer, &m_Count, 50));
    // m_lstGenerator.push_back(new CGenerator(5, &m_Timer, &m_Count));

    m_GenManager.AddGenerator(100.0, 10, &m_Timer, &m_Count);

    // defining the main timer used to trigger generators
    m_Timer.setInterval(TIMER_INTERVAL);
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

void MainWindow::on_wallet_amount_changed(double fNewValue)
{
    ui->m_txtWalletAmount->setText(QString::number(fNewValue));
}


void MainWindow::on_generator_list_updated()
{
    const QList<CGeneratorManager::TGeneratorBox>& lstGens = m_GenManager.GetList();

    QString strElem;
    for(const CGeneratorManager::TGeneratorBox& b: lstGens)
    {
        QTextStream(&strElem) << b._pGen->GetIncrementValue() << " / " << ( static_cast<double>(b._pGen->GetRequiredTimerCount()) * TIMER_INTERVAL) << " s";
        ui->m_lstGenerators->addItem(strElem);
    }
}
