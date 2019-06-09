#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtLabWorks.h"

class QtLabWorks : public QMainWindow
{
	Q_OBJECT

public:
	QtLabWorks(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtLabWorksClass ui;
};
