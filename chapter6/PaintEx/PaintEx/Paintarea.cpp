#include "Paintarea.h"

Paintarea::Paintarea(QWidget *parent)
	: QWidget(parent)
{
	//设置窗体背景色
	setPalette(QPalette(Qt::white));
	setAutoFillBackground(true);
	//等同于
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
	update();					//重新绘制窗体
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
	QPainter p(this);					//i虚拟键一个QPainter对象
	p.setPen(pen);
	p.setBrush(brush);
	QRect rect(50, 100, 300, 200);		//设置一个方形区域，伟华长方形，圆三角形，椭圆等准备
	static const QPoint points[4] =		//定义一个QPiont数组，包含四个点，为话多边形，多边线 点做准备
	{
		QPoint(150, 100),
		QPoint(300, 150),
		QPoint(350, 250),
		QPoint(100, 300)
	};
	int startAngle = 30 * 16;			//起始角，弧线与水平方向的夹角
	int spanAngle = 120 * 16;			//跨度角，起点终点连线的角度
	QPainterPath path;					//新建一个QPainterPath对象，为画路径做准备
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);//绘制贝塞尔曲线
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);
	switch (shape)
	{
		//绘制直线
	case Line:
		p.drawLine(rect.topLeft(), rect.bottomRight());
		break;
		//绘制矩形
	case Rectangle:
		p.drawRect(rect);
		break;
		//绘制圆三角形
	case RoundRect:
		p.drawRoundRect(rect);
		break;
		//绘制椭圆形
	case Ellipse:
		p.drawEllipse(rect);
		break;
		//绘制多边形
	case Polygon:
		p.drawPolygon(points, 4);
		break;
		//绘制多边线
	case Polyline:
		p.drawPolyline(points, 4);
		break;
		//点
	case Points:
		p.drawPoints(points, 4);
		break;
		//弧
	case Arc:
		p.drawArc(rect, startAngle, spanAngle);
		break;
		//路径
	case Path:
		p.drawPath(path);
		break;
		//文字
	case Text:
		p.drawText(rect, Qt::AlignCenter, tr("hello qt"));
		break;
		//图片
	case Pixmap:
		p.drawPixmap(150, 150, QPixmap(":/Resources/image.jpg"));
	default:
		break;
	}
}
