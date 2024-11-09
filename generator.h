#ifndef GENERATOR_H
#define GENERATOR_H

#include "count.h"
#include <QObject>
#include <QTimer>

class CGenerator : public QObject
{
    Q_OBJECT
private:
    int m_nIncVal;
    CCount* m_pCount;
    QTimer* m_pTimer;
public:
    CGenerator();
    CGenerator(int nIncVal, QTimer* pTimer, CCount* pCount, bool bAutoStart = true);
    void SetCount(CCount* pCount);
    void Start();
public slots:
    void IncCount();
signals:
    void generator_triggered(int nIncVal);
};

#endif // GENERATOR_H
