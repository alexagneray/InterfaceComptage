#include "count.h"

CCount::CCount():
    m_nCount(0)
{}

void CCount::Increment(int nIncVal)
{
    QMutexLocker mutLock(&m_mutCount);
    m_nCount += nIncVal;
    emit valueChanged(m_nCount);
}


int CCount::Get() const
{
    return m_nCount;
}
