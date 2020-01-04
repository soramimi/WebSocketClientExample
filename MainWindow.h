#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	QWebSocket m_webSocket;
	QUrl m_url;
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:

	void onConnected();
	void onTextMessageReceived(QString message);
	void onClosed();
	void on_pushButton_connect_clicked();

	void on_pushButton_send_clicked();

	void on_pushButton_disconnect_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
