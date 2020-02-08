FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

#PACKAGES += "${PN}-dev"
FILES_${PN}-dev += "${libdir}/pkgconfig"
#INSANE_SKIP_${PN} += "pkgconfig"
do_install_append() {
    install -d ${D}${libdir}/pkgconfig
    install -m 0644 ${WORKDIR}/libzmq.pc ${D}${libdir}/pkgconfig
}