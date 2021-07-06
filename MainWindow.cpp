#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(&m_webSocket, &QWebSocket::connected, this, &MainWindow::onConnected);
	connect(&m_webSocket, &QWebSocket::disconnected, this, &MainWindow::onClosed);
	connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &MainWindow::onTextMessageReceived);
}

MainWindow::~MainWindow()
{
	m_webSocket.close();
	delete ui;
}

void MainWindow::onConnected()
{
	qDebug() << "connected";
}

void MainWindow::onClosed()
{
	qDebug() << "disconnected";
}

void MainWindow::onTextMessageReceived(QString message)
{
	ui->statusBar->showMessage(message);
	qDebug() << message;
}

void MainWindow::on_pushButton_connect_clicked()
{
	if (!m_webSocket.isValid()) {
		QString url = "ws://localhost:8000/sock/";
		m_webSocket.open(QUrl(url));
	}
}

void MainWindow::on_pushButton_disconnect_clicked()
{
	if (m_webSocket.isValid()) {
		m_webSocket.close();
	}
}

void MainWindow::on_pushButton_send_clicked()
{
	if (m_webSocket.isValid()) {
		m_webSocket.sendTextMessage("hello");
	}
}

