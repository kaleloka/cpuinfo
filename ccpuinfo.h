/**
  * Coder: Kevin Ching
  * This module reads CPU info during allocation and store data in two lists
  *
 */

#ifndef CCPUINFO_H
#define CCPUINFO_H

#include <QObject>

class CCpuInfo : public QObject
{
    Q_OBJECT

protected:
    QStringList m_oKeys;   // CPU property name
    QStringList m_oValues; // CPU property value

public:
    explicit CCpuInfo(QObject *parent = 0);

    Q_INVOKABLE int size();               // get # of CPU properties
    Q_INVOKABLE QString key(int index);   // get CPU property name
    Q_INVOKABLE QString value(int index); // get CPU properties value

protected:
    void ReadCpuInfo();

signals:

public slots:
};

#endif // CCPUINFO_H
