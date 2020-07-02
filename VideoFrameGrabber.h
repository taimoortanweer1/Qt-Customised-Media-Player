#ifndef VIDEOFRAMEGRABBER_H
#define VIDEOFRAMEGRABBER_H

#include <QAbstractVideoSurface>
#include <QtWidgets>

class VideoFrameGrabber : public QAbstractVideoSurface
{
    Q_OBJECT

public:
    VideoFrameGrabber(QWidget *widget, QObject *parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;
    bool isFormatSupported(const QVideoSurfaceFormat &format) const;

    bool start(const QVideoSurfaceFormat &format);
    void stop();

    bool present(const QVideoFrame &frame);

    QRect videoRect() const { return targetRect; }
    void updateVideoRect();

    void paint(QPainter *painter);

private:
    QWidget *widget;
    QImage::Format imageFormat;
    QRect targetRect;
    QSize imageSize;
    QRect sourceRect;
    QVideoFrame currentFrame;

signals:
    void frameAvailable(QImage frame);
};
#endif //VIDEOFRAMEGRABBER_H
