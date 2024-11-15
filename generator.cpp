#include "generator.h"


CGenerator::CGenerator():
    m_pCount(nullptr),
    m_nIncVal(1),
    m_nRequiredTimerCount(0),
    m_nCurrentTimerCount(0)
{
}

CGenerator::CGenerator(int nIncVal,QTimer* pTimer, CCount* pCount, int nRequiredTimerCount, bool bAutoStart):
    CGenerator()
{
    m_nIncVal = nIncVal;
    m_pTimer = pTimer;
    m_pCount = pCount;
    m_nRequiredTimerCount = nRequiredTimerCount;

    if(bAutoStart)
    {
        Start();
    }
}

void CGenerator::Start()
{
    if(!m_pTimer || !m_pCount)
    {
        return;
    }
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(IncCount()));
    connect(this, SIGNAL(generator_triggered(int)), m_pCount, SLOT(Increment(int)));
}
void CGenerator::IncCount()
{
    m_nCurrentTimerCount++;
    if(m_nCurrentTimerCount == m_nRequiredTimerCount)
    {
        emit generator_triggered(m_nIncVal);
        m_nCurrentTimerCount = 0;
    }
}

void CGenerator::SetCount(CCount* pCount)
{
    m_pCount = pCount;
}

int CGenerator::GetIncrementValue() const
{
    return m_nIncVal;
}

int CGenerator::GetRequiredTimerCount() const
{
    return m_nRequiredTimerCount;
}
