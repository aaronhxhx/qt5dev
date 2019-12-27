#pragma once

#include <QtWidgets/QMainWindow>
#include "macro.h"
#include "ui_ImgProcessor.h"
#include "ShowWidget.h"
#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QColor>
#include <QColorDialog>
#include <QTextList>
#include <QActionGroup>
#include <QApplication>
#include <QMenuBar>


class ImgProcessor : public QMainWindow
{
	Q_OBJECT

public:
	ImgProcessor(QWidget *parent = Q_NULLPTR);
	~ImgProcessor();
	
	void createAction();						//创建动作
	void createMenu();							//创建菜单
	void createToolBar();						//创建工具栏
	void loadFile(QString filename);
	void mergeFormat(QTextCharFormat);
private:
	//菜单栏:文件， 编辑， 旋转，镜像
	QMenu* fileMenu;
	QMenu* zoomMenu;
	QMenu* rotateMenu;
	QMenu* mirrorMenu;

	QImage img;
	QString filename;

	ShowWidget* showWidget;

	//动作
	//文件菜单栏
	QAction* openFileAction;
	QAction* NewFileAction;
	QAction* printTextAction;
	QAction* printImageAction;
	QAction* exitAction;
	//编辑菜单栏
	QAction* copyAction;
	QAction* cutAction;
	QAction* pasteAction;
	QAction* aboutAction;
	QAction* zoomInAction;
	QAction* zoomOutAction;
	QAction* rotate90Action;
	QAction* rotate180Action;
	QAction* rotate270Action;
	//镜像菜单栏
	QAction* mirrorVerticalAction;
	QAction* mirrorHorizontalAction;
	QAction* undoAction;
	QAction* redoAction;
	//工具栏
	QToolBar* fileTool;
	QToolBar* zoomTool;
	QToolBar* rotateTool;
	QToolBar* mirrorTool;
	QToolBar* doToolBar;
	//字体设置
	QLabel* fontLabel1;
	QFontComboBox* fontComboBox;
	QLabel* fontLabel2;
	QComboBox* sizeComboBox;
	QToolButton* boldBtn;
	QToolButton* italicBtn;
	QToolButton* underlineBtn;
	QToolButton* colorBtn;
	QToolBar* fontToolBar;
	//排序设置
	QLabel* listLabel;
	QComboBox* listComboBox;
	QActionGroup* actGrp;
	QAction* leftAction;
	QAction* rightAction;
	QAction* centerAction;
	QAction* justifyAction;
	QToolBar* listToolBar;

	Ui::ImgProcessorClass ui;

private slots:
	void ShowNewFile();
	void ShowOpenFile();
	void ShowPrintText();
	void ShowPrintImage();
	void ShowZoomIn();
	void ShowZoonOut();
	void ShowRotate90();
	void ShowRotate180();
	void ShowRotate270();
	void ShowMirrorVertical();
	void ShowMirrorHorizontal();
	void ShowFontComboBox(QString comboStr);
	void ShowSizeSpinBox(QString spinValue);
	void ShowBoldBtn();
	void ShowItalicBtn();
	void ShowUnderLineBtn();
	void ShowColorBtn();
	void ShowCurrentFormatChanged(const QTextCharFormat &fmt);
	void ShowList(int);
	void ShowAlignment(QAction *act);
	void ShowCursorPositionChanged();

};
