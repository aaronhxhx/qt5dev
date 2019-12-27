#include "Paintarea.h"

Paintarea::Paintarea(QWidget *parent)
	: QWidget(parent)
{
	//���ô��屳��ɫ
	setPalette(QPalette(Qt::white));
	setAutoFillBackground(true);
	//��ͬ��
	//QPalette  p = palette();
	//p.setColor(QPalette::Window, Qt::white);
	//setPalette(p);
	setMinimumSize(400, 400);
}

Paintarea::~Paintarea()
{

}

void Paintarea::setShape(Shape s)
{
	shape = s;
	update();					//���»��ƴ���
}

void Paintarea::setPen(QPen p)
{
	pen = p;
	update();
}

void Paintarea::setBrush(QBrush b)
{
	brush = b;
	update();
}

void Paintarea::setFillRule(Qt::FillRule rule)
{
	fillRule = rule;
	update();
}

void Paintarea::paintEvent(QPaintEvent * event)
{
	QPainter p(this);					//i�����һ��QPainter����
	p.setPen(pen);
	p.setBrush(brush);
	QRect rect(50, 100, 300, 200);		//����һ����������ΰ�������Σ�Բ�����Σ���Բ��׼��
	static const QPoint points[4] =		//����һ��QPiont���飬�����ĸ��㣬Ϊ������Σ������ ����׼��
	{
		QPoint(150, 100),
		QPoint(300, 150),
		QPoint(350, 250),
		QPoint(100, 300)
	};
	int startAngle = 30 * 16;			//��ʼ�ǣ�������ˮƽ����ļн�
	int spanAngle = 120 * 16;			//��Ƚǣ�����յ����ߵĽǶ�
	QPainterPath path;					//�½�һ��QPainterPath����Ϊ��·����׼��
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);//���Ʊ���������
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);
	switch (shape)
	{
		//����ֱ��
	case Line:
		p.drawLine(rect.topLeft(), rect.bottomRight());
		break;
		//���ƾ���
	case Rectangle:
		p.drawRect(rect);
		break;
		//����Բ������
	case RoundRect:
		p.drawRoundRect(rect);
		break;
		//������Բ��
	case Ellipse:
		p.drawEllipse(rect);
		break;
		//���ƶ����
	case Polygon:
		p.drawPolygon(points, 4);
		break;
		//���ƶ����
	case Polyline:
		p.drawPolyline(points, 4);
		break;
		//��
	case Points:
		p.drawPoints(points, 4);
		break;
		//��
	case Arc:
		p.drawArc(rect, startAngle, spanAngle);
		break;
		//·��
	case Path:
		p.drawPath(path);
		break;
		//����
	case Text:
		p.drawText(rect, Qt::AlignCenter, tr("hello qt"));
		break;
		//ͼƬ
	case Pixmap:
		p.drawPixmap(150, 150, QPixmap(":/Resources/image.jpg"));
	default:
		break;
	}
}
