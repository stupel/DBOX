#include "dbox.h"
#include "ui_dbox.h"

#include <QDirModel>
#include <QFileSystemModel>
#include <QDebug>

DBOX::DBOX(QWidget *parent) :
	QMainWindow(parent),
	m_mainUI(new Ui::DBOX)
{
	m_mainUI->setupUi(this);

	setupPreprocessorUI();
}

DBOX::~DBOX()
{
	delete m_mainUI;
}

void DBOX::setupPreprocessorUI()
{
	setupFileBrowser();

	if (m_mainUI->preprocessor_radioButton_compareView->isChecked()) {
		m_mainUI->preprocessor_widget_compactView->setVisible(false);
	}
	else {
		m_mainUI->preprocessor_widget_compareView->setVisible(false);
	}

}

void DBOX::setupFileBrowser()
{
	QFileSystemModel *model = new QFileSystemModel;
	model->setRootPath(QDir::homePath());
	model->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
	model->setNameFilters(QStringList() << "*.png" << "*.jpg" << "*.tif" << "*.bmp");
	model->setNameFilterDisables(false);

	m_mainUI->preprocessor_treeView_source->setModel(model);
	m_mainUI->preprocessor_treeView_source->header()->close();
	m_mainUI->preprocessor_treeView_source->hideColumn(1);
	m_mainUI->preprocessor_treeView_source->hideColumn(2);
	m_mainUI->preprocessor_treeView_source->hideColumn(3);
	m_mainUI->preprocessor_treeView_source->setRootIndex(model->index(QDir::homePath()));
	m_mainUI->preprocessor_treeView_source->expandToDepth(0);
	m_mainUI->preprocessor_treeView_source->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
	m_mainUI->preprocessor_treeView_source->header()->setStretchLastSection(false);
}

void DBOX::on_preprocessor_radioButton_compactView_clicked()
{
	m_mainUI->preprocessor_widget_compactView->setVisible(true);
	m_mainUI->preprocessor_widget_compareView->setVisible(false);
}

void DBOX::on_preprocessor_radioButton_compareView_clicked()
{
	m_mainUI->preprocessor_widget_compactView->setVisible(false);
	m_mainUI->preprocessor_widget_compareView->setVisible(true);
}

void DBOX::on_preprocessor_treeView_source_clicked(const QModelIndex &index)
{
	QAbstractItemModel *model = m_mainUI->preprocessor_treeView_source->model();
	QString filePath = QFileSystemModel(model).filePath(index);
	qDebug() << filePath;
}
