DESCRIPTION = "Simple App"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://first.c"

S = "${WORKDIR}" 

do_compile() {
	${CC} first.c ${LDFLAGS} -o APP
}	

do_install() {
	install -d ${D}${bindir}
	install -m 0755 APP ${D}${bindir}
}
