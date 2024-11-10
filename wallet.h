#ifndef WALLET_H
#define WALLET_H

#include <QObject>
#include <QMutex>

class CWallet : public QObject
{
    Q_OBJECT
public:
    explicit CWallet(QObject *parent = nullptr);
private:
    double m_fTotalAmount;
    QMutex m_mutTotalAmount;

signals:
    void TotalAmountUpdated();
public slots:
    void AddMoney(double nAmount);
    void RemoveMoney(double nAmount);
};

#endif // WALLET_H
