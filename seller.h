#ifndef SELLER_H
#define SELLER_H

#include <QObject>
#include "count.h"
#include "wallet.h"

class CSeller : public QObject
{
    Q_OBJECT
public:
    explicit CSeller(QObject *parent = nullptr);
    CSeller(CCount* pCount, CWallet* pWallet);
private:
    CCount* m_pCount;
    CWallet* m_pWallet;
signals:

};

#endif // SELLER_H
