#include "seller.h"

CSeller::CSeller(QObject *parent)
    : QObject{parent}
{}

CSeller::CSeller(CCount* pCount, CWallet* pWallet):
    m_pCount(pCount),
    m_pWallet(pWallet)
{
    // connect()
}
