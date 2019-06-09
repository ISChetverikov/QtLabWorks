#pragma once
#include <QtGui>

class rasterWindow : public QWindow
{
	Q_OBJECT
public:
	explicit rasterWindow(QWindow *parent = nullptr);

	virtual void render(QPainter *painter);

public slots:
	void renderLater();
	void renderNow();

protected:
	bool event(QEvent *event) override;

	void resizeEvent(QResizeEvent *event) override;
	void exposeEvent(QExposeEvent *event) override;

private:
	QBackingStore *m_backingStore;
};
