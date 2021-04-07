#ifndef WEBCLASS_H
#define WEBCLASS_H

#include <QObject>
#include <QJsonObject>

class WebClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonObject jsonData MEMBER m_jsonData NOTIFY dataChanged)
public:
    WebClass();
signals:
    void dataChanged(const QJsonObject &jsonData);
private:
    QJsonObject m_jsonData;
};

#endif // WEBCLASS_H
