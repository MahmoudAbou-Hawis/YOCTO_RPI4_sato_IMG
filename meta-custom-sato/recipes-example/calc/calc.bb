DESCRIPTION = "Simple calculator"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://main.cpp \
           file://sum.hpp \
           file://sum.cpp \
           file://multi.hpp \
           file://multi.cpp \
           file://Makefile"

S = "${WORKDIR}" 

EXTRA_OMAKE += "V=0"


do_install() {
	oe_runmake install DESTDIR=${D}/usr/bin/
}
