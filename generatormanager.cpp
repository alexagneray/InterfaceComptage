#include "generatormanager.h"
#include <qforeach.h>

CGeneratorManager::CGeneratorManager() {}

void CGeneratorManager::AddGenerator(const CGenerator* pGen, int nPrice)
{
    m_lstGenerators.push_back(TGeneratorBox{pGen, false, nPrice});
    emit ListUpdated();
}
void CGeneratorManager::UpdateGenerators(int nAccount)
{
    foreach(TGeneratorBox tBox, m_lstGenerators)
    {
        tBox._bVisible = (tBox._nPrice >= nAccount ? true : false);
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
