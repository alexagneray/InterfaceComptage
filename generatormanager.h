#ifndef GENERATORMANAGER_H
#define GENERATORMANAGER_H

#include <QObject>
#include "generator.h"

/**
 * @brief The CGeneratorManager class
 * The GeneratorManager holds the CGenerator list.
 * Each CGenerator is contained in a struct showing metadata about the CGenerator state.
 * Each element of the list indicates the price to unlock the generator and if the generator is visible.
 *
 */
class CGeneratorManager : public QObject
{
    Q_OBJECT
public:
    CGeneratorManager();
public slots:
    void AddGenerator(const CGenerator* pGen, int nPrice);
    void UpdateGenerators(int nAccount);
    void RemoveGenerator(const CGenerator* pGen);
signals:
    void GeneratorReady(const CGenerator* pGen);
    void ListUpdated();
private:
    struct TGeneratorBox
    {
        const CGenerator* _pGen;
        bool _bVisible;
        int _nPrice;
    };
    QList<TGeneratorBox> m_lstGenerators;
};

#endif // GENERATORMANAGER_H
