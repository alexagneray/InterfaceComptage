#include "wallet.h"

CWallet::CWallet(QObject *parent)
    : QObject{parent},
    m_fTotalAmount(0.0)
{
}


void CWallet::AddMoney(double fAmount)
{
    QMutexLocker Lock(&m_mutTotalAmount);
    m_fTotalAmount += fAmount;
    emit TotalAmountUpdated();
}

void CWallet::RemoveMoney(double fAmount)
{
    QMutexLocker Lock(&m_mutTotalAmount);
    m_fTotalAmount -= fAmount;
    emit TotalAmountUpdated();
}
