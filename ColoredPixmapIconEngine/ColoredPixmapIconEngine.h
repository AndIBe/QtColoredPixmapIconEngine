#ifndef COLOREDPIXMAPICONENGINE_H
#define COLOREDPIXMAPICONENGINE_H

#include <QtGui/private/qicon_p.h>

class ColoredPixmapIconEngine : public QPixmapIconEngine
{
public:
    QPixmap pixmap(const QSize &size, QIcon::Mode mode, QIcon::State state) override;
};

#endif // COLOREDPIXMAPICONENGINE_H
