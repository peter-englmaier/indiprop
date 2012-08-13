/***********************************************************************
 * Copyright © 2012 Aaron Evers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 3 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/

#ifndef INDICLIENT_H
#define INDICLIENT_H

#include <QtCore>
#include <QtNetwork>
#include <QtXml>

#include <QTcpSocket>
#include <QByteArray>

#include <QTextStream>
extern QTextStream qout;

namespace indi
{
	static const char * const VERSION = "1.7";
	static const unsigned short PORT = 7624;
};

class IndiClient : public QObject
{
    Q_OBJECT;

public:
    IndiClient();
	void socketConnect(const QString &hoststring);
	bool connected();
	
	static QString formatNumber(const QString &format, const QString &number, const bool &sexagesimal);

private:
	quint16 mPort;
    QTcpSocket mQTcpSocket;

signals:
	void propertyUpdate(QDomDocument);

private slots:
    void socketConnected();
    void socketDisconnected();
    void socketError(QAbstractSocket::SocketError);
    void socketReadyRead();
};

#endif
