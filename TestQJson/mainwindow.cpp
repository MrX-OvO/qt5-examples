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
  // 生成json对象
  QJsonObject obj;
  obj.insert("name", "张三");
  obj.insert("age", 20);
  obj.insert("sex", "男");
  obj.insert("addr", "天津滨海新区");

  QJsonObject subObj;
  subObj.insert("farther", "张二");
  subObj.insert("morther", "李四");

  QJsonArray arr;
  arr.append("张四");
  arr.append("张五");

  subObj.insert("brothers", arr);
  obj.insert("family", subObj);

  obj.insert("isAlive", true);

  // 利用QJsonDocument对QJsonObject进行转换
  QJsonDocument doc(obj);
  // 转成json文本
  QByteArray json = doc.toJson();
  // 写入磁盘
  QFile file("./张三.json");
  bool flag = file.open(QFile::WriteOnly);
  if (flag) {
    qDebug() << "打开文件成功！开始写入数据...";
    file.write(json);
    qDebug() << "写入数据完毕...";
  } else
    qDebug() << "打开文件失败！！！";
  file.close();
}

void MainWindow::readJson() {
  // 从磁盘读文件
  QFile file("./张三.json");
  bool flag = file.open(QFile::ReadOnly);
  QByteArray json;
  if (flag) {
    qDebug() << "打开文件成功！开始读取数据...";
    json = file.readAll();
    qDebug() << "读取数据完毕...";
  } else
    qDebug() << "打开文件失败！！！";
  file.close();

  // 利用QJsonDocument对QByteArray进行转换
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
