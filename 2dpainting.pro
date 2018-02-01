QT          += widgets

HEADERS     = glwidget.h \
              helper.h \
              widget.h \
              window.h \
    uxp.h \
    uxtumbler.h
SOURCES     = glwidget.cpp \
              helper.cpp \
              main.cpp \
              widget.cpp \
              window.cpp \
    uxp.cpp \
    uxtumbler.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
INSTALLS += target
