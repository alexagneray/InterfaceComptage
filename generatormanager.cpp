#include "generatormanager.h"
#include <qforeach.h>

CGeneratorManager::CGeneratorManager() {}

void CGeneratorManager::AddGenerator(double fPrice,int nIncVal,QTimer* pTimer, CCount* pCount, int nRequiredTimerCount, bool bAutoStart )
{
    CGenerator* pGen = new CGenerator(nIncVal, pTimer, pCount, nRequiredTimerCount, bAutoStart);
    m_lstGenerators.push_back(TGeneratorBox{pGen, false, fPrice});
    emit ListUpdated();
}
void CGeneratorManager::UpdateGenerators(int nAccount)
{
    foreach(TGeneratorBox tBox, m_lstGenerators)
    {
        tBox._bVisible = (tBox._fPrice >= nAccount ? true : false);
    }
    emit ListUpdated();
}

void CGeneratorManager::RemoveGenerator(const CGenerator* pGen)
{
    int i = 0;
    foreach(TGeneratorBox tBox, m_lstGenerators)
    {
        if(tBox._pGen == pGen)
        {
            m_lstGenerators.removeAt(i);
        }
        i++;
    }
    emit ListUpdated();
}


const QList<CGeneratorManager::TGeneratorBox>& CGeneratorManager::GetList() const
{
    return m_lstGenerators;
}
