#ifndef DBOX_H
#define DBOX_H

#include <QMainWindow>

namespace Ui {
class DBOX;
}

class DBOX : public QMainWindow
{
	Q_OBJECT

public:
	explicit DBOX(QWidget *parent = nullptr);
	~DBOX();

private slots:
	void on_preprocessor_radioButton_compactView_clicked();

	void on_preprocessor_radioButton_compareView_clicked();

	void on_preprocessor_treeView_source_clicked(const QModelIndex &index);

private:
	void setupPreprocessorUI();
	void setupFileBrowser();

private:
	Ui::DBOX *m_mainUI;
};

#endif // DBOX_H
