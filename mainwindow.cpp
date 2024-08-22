
# Author: FaOrdi
# Date: 2024-06-01
# Description:  SNMP getwalk DIO.



#include "mainwindow.h"
#include <QProcess>
#include <QStringList>
#include <QDebug>
///
/// \brief MainWindow::MainWindow
/// \param parent
///
///
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Create widgets
    versionLineEdit = new QLineEdit(this);
    communityLineEdit = new QLineEdit(this);
    hostnameLineEdit = new QLineEdit(this);
    oidLineEdit = new QLineEdit(this);
    executeButton = new QPushButton("Execute SNMP WALK", this);
    outputTextEdit = new QTextEdit(this);

    // Set placeholder text for the line edits
    versionLineEdit->setPlaceholderText("Enter SNMP version (e.g., 2c)");
    communityLineEdit->setPlaceholderText("Enter community string");
    hostnameLineEdit->setPlaceholderText("Enter hostname or IP address");
    oidLineEdit->setPlaceholderText("Enter OID (e.g., 1.3.6.1.2.1.1)");

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(versionLineEdit);
    layout->addWidget(communityLineEdit);
    layout->addWidget(hostnameLineEdit);
    layout->addWidget(oidLineEdit);
    layout->addWidget(executeButton);
    layout->addWidget(outputTextEdit);

    // Create a central widget and set layout
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connect button click signal to the slot
    connect(executeButton, &QPushButton::clicked, this, &MainWindow::onExecuteButtonClicked);
}

MainWindow::~MainWindow() {
}

void MainWindow::onExecuteButtonClicked() {
    QString version = versionLineEdit->text();
    QString community = communityLineEdit->text();
    QString hostname = hostnameLineEdit->text();
    QString oid = oidLineEdit->text();

    executeSnmpWalk(version, community, hostname, oid);
}
///
/// \brief MainWindow::executeSnmpWalk
/// \param version
/// \param community
/// \param hostname
/// \param oid
///
void MainWindow::executeSnmpWalk(const QString &version, const QString &community, const QString &hostname, const QString &oid) {
    // Clear previous output
    outputTextEdit->clear();

    // Construct the command
    QString command = "snmpwalk -v " + version + " -c " + community + " " + hostname + " " + oid;

    // Execute the command
    QProcess process;
    process.start(command);
    process.waitForFinished();

    // Capture the output
    QString output = process.readAllStandardOutput();
    QString error = process.readAllStandardError();

    // Print the output and error
    outputTextEdit->setPlainText("Output:\n" + output + "\nError:\n" + error);
}
