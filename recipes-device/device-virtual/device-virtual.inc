DESCRIPTION = "Virtual Device Service"
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/device-virtual-go"
DEVICEPATH = "${B}/src/${GO_IMPORT}"

INSANE_SKIP_${PN} = "file-rdeps"

do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH

    cd ${DEVICEPATH}

    oe_runmake
}

do_install() {

    install -d ${D}${EDGEX_BIN}
    install -m 0755 ${DEVICEPATH}/cmd/device-virtual ${D}${EDGEX_BIN}

    install -d ${D}${EDGEX_ETC}/device-virtual
    install -m 0644 ${WORKDIR}/device-virtual.toml ${D}${EDGEX_ETC}/device-virtual/${EDGEX_CONFIGURATION_FILE}
    install -m 0644 ${DEVICEPATH}/cmd/res/*.yaml ${D}${EDGEX_ETC}/device-virtual

    # Launch Script
    install -m 0755 ${WORKDIR}/device-virtual-launch.sh ${D}${EDGEX_BIN}
}