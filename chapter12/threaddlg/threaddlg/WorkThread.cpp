#include "WorkThread.h"

WorkThread::WorkThread()
{
}

WorkThread::~WorkThread()
{
}

void WorkThread::run()
{
	while (true)
	{
		for (int n = 0; n <= 9; n++)
		{
			qDebug() << n << n << n << n << n << n << n << n << n << n;
		}
	}
}
