#-------------------------------------------------
#
# Project created by QtCreator 2013-09-01T13:03:45
#
#-------------------------------------------------

QT       -= core gui

TARGET = GloomEngine
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
	src/Renderer/Renderer.cpp \
	src/Renderer/Window.cpp \
	src/Core/Logger.cpp

HEADERS += \
	include/LeeEngine3/Core/TypeTraits.h \
	include/LeeEngine3/Core/Types.h \
	include/LeeEngine3/Core/Logger.h \
	include/Core/TypeTraits.h \
	include/Core/Types.h \
	include/Core/Logger.h \
	include/Core/Factory.h \
	include/Renderer/Renderer.h \
	include/Renderer/Window.h
unix:!symbian {
	maemo5 {
		target.path = /opt/usr/lib
	} else {
		target.path = /usr/lib
	}
	INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++11
