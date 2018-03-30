
#include "ColoredPixmapIconEngine.h"

#include <QDebug>
#include <QFileInfo>
#include <QIconEnginePlugin>
#include <QLoggingCategory>
#include <QProcessEnvironment>
#include <QRegularExpression>

Q_LOGGING_CATEGORY(lcColoredPixmapIconEnginePlugin, "ColoredPixmapIconEnginePlugin")

#define lcDebug qCDebug(lcColoredPixmapIconEnginePlugin)
#define lcWarning qCWarning(lcColoredPixmapIconEnginePlugin)


class ColoredPixmapIconEnginePlugin : public QIconEnginePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QIconEngineFactoryInterface_iid FILE "ColoredPixmapIconEngine.json")

public:
    ColoredPixmapIconEnginePlugin(QObject *parent = Q_NULLPTR);
    QIconEngine *create(const QString &filename = QString()) override;
private:
    QRegularExpression m_reColoredFilesFilter;
};

ColoredPixmapIconEnginePlugin::ColoredPixmapIconEnginePlugin(QObject *parent) : QIconEnginePlugin(parent)
{
    const QString fileNamePattern = QProcessEnvironment::systemEnvironment().value("QT_COLORED_ICONS_FILES_PATTERN");
    m_reColoredFilesFilter.setPattern(fileNamePattern);
    m_reColoredFilesFilter.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    lcDebug << "Use regexp pattern:" << fileNamePattern;
}

QIconEngine *ColoredPixmapIconEnginePlugin::create(const QString &filePath)
{
    const QString baseFileName = QFileInfo(filePath).baseName();
    const bool colorizeFile = m_reColoredFilesFilter.match(baseFileName).hasMatch();
    QPixmapIconEngine *engine = colorizeFile ? (new ColoredPixmapIconEngine) : (new QPixmapIconEngine);

    lcDebug << qPrintable(QString("Use %1 icon engine for file:").arg(colorizeFile ? "colored" : "default"))
            << filePath;

    if (!filePath.isEmpty()) {
        engine->addFile(filePath, QSize(), QIcon::Normal, QIcon::Off);
    }

    return engine;
}

#include "main.moc"
