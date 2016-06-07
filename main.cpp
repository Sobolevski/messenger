#include <QApplication>

#include "chatdialog.h"
#include "username.h"

#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // получить сохраненные конфигурации сети
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // Если сохраненная конфигурация сети в настоящее время не обнаружена, использовать систему по умолчанию
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        QNetworkSession *networkSession = new QNetworkSession(config, &app);
        networkSession->open();
        networkSession->waitForOpened();

        if (networkSession->isOpen()) {
            // Сохранить используемую конфигурацию
            QNetworkConfiguration config = networkSession->configuration();
            QString id;
            if (config.type() == QNetworkConfiguration::UserChoice) {
                id = networkSession->sessionProperty(
                        QLatin1String("UserChoiceConfiguration")).toString();
            } else {
                id = config.identifier();
            }

            QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
            settings.beginGroup(QLatin1String("QtNetwork"));
            settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
            settings.endGroup();
        }
    }

    username Udialog;
        if (Udialog.exec() == QDialog::Rejected) return 0;
       QString un = Udialog.getUserName();

    ChatDialog dialog(Udialog.getUserName());
        dialog.show();
    return app.exec();

}
