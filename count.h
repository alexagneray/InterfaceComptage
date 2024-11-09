#ifndef COUNT_H
#define COUNT_H
#include <QMutex>
#include <QObject>

class CCount : public QObject
{
Q_OBJECT
public:
    CCount();
    int Get() const;
public slots:
    void Increment(int nIncVal = 1);
private:
    int m_nCount;
    QMutex m_mutCount;
signals:
    void valueChanged(int nNewValue);
};

#endif // COUNT_H
