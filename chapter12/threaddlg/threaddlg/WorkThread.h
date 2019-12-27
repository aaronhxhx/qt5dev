#pragma once

#include <QThread>
#include <QDebug>

class WorkThread : public QThread
{
	Q_OBJECT

public:
	WorkThread();
	~WorkThread();
protected:
	void run() override;
};
