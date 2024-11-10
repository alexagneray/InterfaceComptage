#ifndef GENERATOR_H
#define GENERATOR_H

#include "count.h"
#include <QObject>
#include <QTimer>

/**
 * @brief The CGenerator class
 * A generator can add a predefined amount to the global count each time it is triggered.
 * A generator has to be bound with a QTimer and a CCount object
 */
class CGenerator : public QObject
{
    Q_OBJECT
private:
    int m_nIncVal;
    CCount* m_pCount;
    QTimer* m_pTimer;
    int m_nRequiredTimerCount;
    int m_nCurrentTimerCount;
public:
    CGenerator();
    CGenerator(int nIncVal, QTimer* pTimer, CCount* pCount, int nRequiredTimerCount = 100, bool bAutoStart = true);
    void SetCount(CCount* pCount);
    void Start();
public slots:
    void IncCount();
signals:
    void generator_triggered(int nIncVal);
};

#endif // GENERATOR_H
