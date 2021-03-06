#include "mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QJsonDocument doc;
  if (doc.isNull())
    qDebug() << "QJsonDocument doc is null...";
  else if (doc.isEmpty())
    qDebug() << "QJsonDocument doc is empty...";

  writeJson();
  readJson();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::printQJsonArr(const QJsonArray &arr, unsigned *depth) {
  QString space = QString(*depth, ' ');
  qDebug().noquote() << space << "[";
  for (int i = 0; i < arr.size(); ++i) {
    QJsonValue value = arr.at(i);
    if (value.isArray()) {
      ++*depth;
      printQJsonArr(value.toArray(), depth);
    } else if (value.isBool())
      qDebug() << "  " << value.toBool();
    else if (value.isDouble())
      qDebug() << "  " << value.toInt();
    else if (value.isObject()) {
      unsigned *depthSubObj = new unsigned(*depth);
      printQJsonObj(value.toObject(), depthSubObj);
      delete depthSubObj;
    } else if (value.isString())
      qDebug() << "  " << value.toString();
  }
  qDebug().noquote() << space << "]";
}

void MainWindow::printQJsonObj(const QJsonObject &obj, unsigned *depth) {
  QString space = QString(*depth, ' ');
  qDebug().noquote() << space << "{";
  QStringList keys = obj.keys();
  for (int i = 0; i < keys.size(); ++i) {
    QString key = keys.at(i);
    QJsonValue value = obj.value(key);
    if (value.isArray()) {
      qDebug() << "  " << key << ":";
      unsigned *depthSubArr = new unsigned(*depth);
      printQJsonArr(value.toArray(), depthSubArr);
      delete depthSubArr;
    } else if (value.isBool())
      qDebug() << "  " << key << ":" << value.toBool();
    else if (value.isDouble())
      qDebug() << "  " << key << ":" << value.toInt();
    else if (value.isObject()) {
      ++*depth;
      printQJsonObj(value.toObject(), depth);
    } else if (value.isString())
      qDebug() << "  " << key << ":" << value.toString();
  }
  qDebug().noquote() << space << "}";
}

void MainWindow::writeJson() {
  // ??????json??????
  QJsonObject obj;
  obj.insert("name", "??????");
  obj.insert("age", 20);
  obj.insert("sex", "???");
  obj.insert("addr", "??????????????????");

  QJsonObject subObj;
  subObj.insert("farther", "??????");
  subObj.insert("morther", "??????");

  QJsonArray arr;
  arr.append("??????");
  arr.append("??????");

  subObj.insert("brothers", arr);
  obj.insert("family", subObj);

  obj.insert("isAlive", true);

  // ??????QJsonDocument???QJsonObject????????????
  QJsonDocument doc(obj);
  // ??????json??????
  QByteArray json = doc.toJson();
  // ????????????
  QFile file("./??????.json");
  bool flag = file.open(QFile::WriteOnly);
  if (flag) {
    qDebug() << "???????????????????????????????????????...";
    file.write(json);
    qDebug() << "??????????????????...";
  } else
    qDebug() << "???????????????????????????";
  file.close();
}

void MainWindow::readJson() {
  // ??????????????????
  QFile file("./??????.json");
  bool flag = file.open(QFile::ReadOnly);
  QByteArray json;
  if (flag) {
    qDebug() << "???????????????????????????????????????...";
    json = file.readAll();
    qDebug() << "??????????????????...";
  } else
    qDebug() << "???????????????????????????";
  file.close();

  // ??????QJsonDocument???QByteArray????????????
  QJsonDocument doc = QJsonDocument::fromJson(json);
  unsigned *depthArr = new unsigned(0);
  unsigned *depthObj = new unsigned(0);
  if (doc.isNull())
    qDebug() << "QJsonDocument doc is null...";
  else if (doc.isEmpty())
    qDebug() << "QJsonDocument doc is empty...";
  else if (doc.isArray())
    printQJsonArr(doc.array(), depthArr);
  else if (doc.isObject())
    printQJsonObj(doc.object(), depthObj);
  delete depthArr;
  delete depthObj;
}
