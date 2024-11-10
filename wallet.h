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
    int m_nTotalAmount;
    QMutex m_mutTotalAmount;

signals:
    void TotalAmountUpdated();
public slots:
    void AddMoney(int nAmount);
    void RemoveMoney(int nAmount);
};

#endif // WALLET_H
