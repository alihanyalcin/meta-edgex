DESCRIPTION = "Device service for reference example."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/device-random"
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
    install -m 0755 ${DEVICEPATH}/cmd/device-random ${D}${EDGEX_BIN}

    install -d ${D}${EDGEX_ETC}/device-random
    install -m 0644 ${WORKDIR}/device-random.toml ${D}${EDGEX_ETC}/device-random/${EDGEX_CONFIGURATION_FILE}
    install -m 0644 ${DEVICEPATH}/cmd/res/device.random.yaml ${D}${EDGEX_ETC}/device-random

    # Launch Script
    install -m 0755 ${WORKDIR}/device-random-launch.sh ${D}${EDGEX_BIN}
}