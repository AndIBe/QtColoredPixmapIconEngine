
#include "ColoredPixmapIconEngine.h"

#include <QDebug>
#include <QFileInfo>
#include <QIconEnginePlugin>
#include <QLoggingCategory>
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
    QRegularExpression m_reColoredFiles;
};

ColoredPixmapIconEnginePlugin::ColoredPixmapIconEnginePlugin(QObject *parent) : QIconEnginePlugin(parent)
{
    const QString fileNamePattern = QString::fromLocal8Bit(qgetenv("QT_COLORED_ICONS_FILES_PATTERN"));
    m_reColoredFiles.setPattern(fileNamePattern);
    m_reColoredFiles.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    lcDebug << "Use regexp pattern:" << fileNamePattern;
}

QIconEngine *ColoredPixmapIconEnginePlugin::create(const QString &filePath)
{
    const QString baseFileName = QFileInfo(filePath).baseName();
    const bool colorizeFile = m_reColoredFiles.pattern().isEmpty() ? false
                                                                   : m_reColoredFiles.match(baseFileName).hasMatch();
    QPixmapIconEngine *engine = colorizeFile ? (new ColoredPixmapIconEngine) : (new QPixmapIconEngine);

    lcDebug << qPrintable(QString("Use %1 icon engine for file:").arg(colorizeFile ? "colored" : "default"))
            << filePath;

    if (!filePath.isEmpty()) {
        engine->addFile(filePath, QSize(), QIcon::Normal, QIcon::Off);
    }

    return engine;
}

#include "main.moc"
