#include "wallet.h"

CWallet::CWallet(QObject *parent)
    : QObject{parent}
{}


void CWallet::AddMoney(int nAmount)
{
    QMutexLocker Lock(&m_mutTotalAmount);
    m_nTotalAmount += nAmount;
    emit TotalAmountUpdated();
}

void CWallet::RemoveMoney(int nAmount)
{
    QMutexLocker Lock(&m_mutTotalAmount);
    m_nTotalAmount -= nAmount;
    emit TotalAmountUpdated();
}
