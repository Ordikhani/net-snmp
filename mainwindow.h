#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onExecuteButtonClicked();

private:
    QLineEdit *versionLineEdit;
    QLineEdit *communityLineEdit;
    QLineEdit *hostnameLineEdit;
    QLineEdit *oidLineEdit;
    QPushButton *executeButton;
    QTextEdit *outputTextEdit;

    void executeSnmpWalk(const QString &version, const QString &community, const QString &hostname, const QString &oid);
};

#endif // MAINWINDOW_H
