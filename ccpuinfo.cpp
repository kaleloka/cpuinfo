/**
  * Coder: Kevin Ching
  * This module reads CPU info during allocation and store data in two lists
  *
 */


#include "ccpuinfo.h"

#include <QFile>
#include <QTextStream>

CCpuInfo::CCpuInfo(QObject *parent) : QObject(parent)
{
    ReadCpuInfo();
}

// get # of CPU properties
int CCpuInfo::size()
{
    return m_oKeys.size();
}

// get CPU property name
QString CCpuInfo::key(int index)
{
    return ( m_oKeys.size() > index ) ? m_oKeys[index] : "";
}
// get CPU properties value
QString CCpuInfo::value(int index)
{
    return ( m_oValues.size() > index ) ? m_oValues[index] : "";
}

void CCpuInfo::ReadCpuInfo()
{
    m_oKeys.clear();
    m_oValues.clear();

    QFile file("/proc/cpuinfo");
    if ( file.open(QFile::ReadOnly) )
    {
        QTextStream in(&file);
        while (1)
        {
            QString line = in.readLine().trimmed();
            if ( line.size() <= 0 )
                break;

            // split CPU info into property name and value
            int sepIndex = line.indexOf(":");
            if ( sepIndex >= 0 )
            {
                QString key = line.mid(0, sepIndex).trimmed();
                QString value = line.mid(sepIndex+1).trimmed();

                m_oKeys.append(key);
                m_oValues.append(value);
            }
        }
    }
}
