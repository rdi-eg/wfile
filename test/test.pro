TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG(release, debug|release) {
        unix:!macx: LIBS += -L$$PWD/../../lib
}
CONFIG(debug, debug|release) {
        unix:!macx: LIBS += -L$$PWD/../../lib_debug
}

equals(CI, "enabled") {
    message(CI mode is enabled)
    DEFINES+= __CI__
}

SOURCES += \
    main.cpp

INCLUDEPATH += $$PWD/../../include

unix:!macx: LIBS += -lwfile              \
                    -lboost_filesystem	 \
					-lboost_system
