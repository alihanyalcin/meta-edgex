DESCRIPTION = "ZeroMQ"
SUMMARY = "ZeroMQ looks like an embeddable networking library but acts like a concurrency framework."
HOMEPAGE = "https://zeromq.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "http://mirror.archlinuxarm.org/arm/community/zeromq-4.3.2-1-arm.pkg.tar.xz"
SRC_URI[md5sum] = "6693e168ec03c23c2259f40dde8a775a"
SRC_URI[sha256sum] = "bb5ae9a98b67cb55c8abfdac5279679b4f3db148ce73d24080868747fb4793c0"

#PACKAGECONFIG ??= "libsodium"
#PACKAGECONFIG[libsodium] = "-DWITH_LIBSODIUM=ON,-DWITH_LIBSODIUM=OFF, libsodium"

INSANE_SKIP_${PN} = "already-stripped file-rdeps symlink-to-sysroot staticdev dev-so"
#INHIBIT_PACKAGE_STRIP = "1"
#INHIBIT_SYSROOT_STRIP = "1"
#SOLIBS = ".so.*"
#FILES_SOLIBSDEV = ".so .so.* .a"

#inherit pkgconfig 

S = "${WORKDIR}"
#PACKAGES = "${PN} ${PN}-dev ${PN}-staticdev"
#FILES_${PN} = "${includedir}/* ${libdir}/* ${bindir}/*"
#FILES_${PN}-dev = "${libdir}/libzmq.so ${libdir}/libzmq.so.5"
#FILES_${PN}-staticdev = "${libdir}/libzmq.a"

do_install() {
    #${includedir} = /usr/include
    #${bindir} = /usr/bin
    #${libdir} = /usr/lib
    #${datadir} = /usr/share

    install -d ${D}${bindir}
    install -m 0755 ${S}/usr/bin/curve_keygen ${D}${bindir}

    #install -d ${D}${includedir}
    #install -m 0644 ${S}/usr/include/* ${D}${includedir}

    #install -d ${D}${libdir}/pkgconfig
    #install -m 0644 ${S}/usr/lib/pkgconfig/libzmq.pc ${D}${libdir}/pkgconfig
    #install -m 0644 ${S}/usr/lib/libzmq.a ${D}${libdir}
    #install -m 0755 ${S}/usr/lib/libzmq.so.5.2.2 ${D}${libdir}
    #ln -s ${D}${libdir}/libzmq.so.5.2.2 ${D}${libdir}/libzmq.so
    #ln -s ${D}${libdir}/libzmq.so.5.2.2 ${D}${libdir}/libzmq.so.5
}