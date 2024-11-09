#include "generator.h"


CGenerator::CGenerator():
    m_pCount(nullptr),
    m_nIncVal(1)
{
}

CGenerator::CGenerator(int nIncVal,QTimer* pTimer, CCount* pCount, bool bAutoStart):
    CGenerator()
{
    m_nIncVal = nIncVal;
    m_pTimer = pTimer;
    m_pCount = pCount;

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
    emit generator_triggered(m_nIncVal);
}

void CGenerator::SetCount(CCount* pCount)
{
    m_pCount = pCount;
}
