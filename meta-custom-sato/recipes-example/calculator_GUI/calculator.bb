DESCRIPTION = "Simple QT5 calculator"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://main.cpp \
           file://mainwindow.ui \
           file://mainwindow.h \
           file://mainwindow.cpp \
           file://calcul.png \
	   file://calculator.desktop \
           file://CMakeLists.txt"

S = "${WORKDIR}" 

DEPENDS += "qtbase wayland"

IMAGE_INSTALL:append = " qtbase cmake"


inherit cmake
inherit cmake_qt5


do_install() {
    install -d ${D}${bindir}
    install -d ${D}${datadir}/applications
    install -d ${D}${datadir}/icons/hicolor/48x48/apps

    install -m 0755 ${B}/calculator ${D}${bindir}/
    install -m 0644 ${WORKDIR}/calcul.png ${D}${datadir}/icons/hicolor/48x48/apps/
    install -m 0644 ${WORKDIR}/calculator.desktop ${D}/${datadir}/applications

}

FILES:${PN} += "${datadir}/applications/calculator.desktop ${datadir}/icons/hicolor/48x48/apps/calcul.png"
