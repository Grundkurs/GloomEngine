TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GloomEngine/release/ -lGloomEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GloomEngine/debug/ -lGloomEngine
else:unix: LIBS += -L$$OUT_PWD/../GloomEngine/ -lGloomEngine

INCLUDEPATH += $$PWD/../GloomEngine
DEPENDPATH += $$PWD/../GloomEngine

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GloomEngine/release/GloomEngine.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GloomEngine/debug/GloomEngine.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../GloomEngine/libGloomEngine.a

QMAKE_CXXFLAGS += -std=c++11
