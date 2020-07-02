TEMPLATE = app
TARGET = player

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    VideoFrameGrabber.h \
    player.h \
    playercontrols.h \
    playlistmodel.h \
    videowidget.h \
    histogramwidget.h
SOURCES = main.cpp \
    VideoFrameGrabber.cpp \
    player.cpp \
    playercontrols.cpp \
    playlistmodel.cpp \
    videowidget.cpp \
    histogramwidget.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/player
INSTALLS += target
