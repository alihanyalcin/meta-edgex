DESCRIPTION = "EdgeX Foundry Services"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/device-random"

INSANE_SKIP_${PN} = "file-rdeps"

do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH

    cd ${B}/src/${GO_IMPORT}

    oe_runmake
}

do_install() {
    DEVICEPATH="${B}/src/${GO_IMPORT}"

    install -d ${D}${EDGEX_BIN}
    install -m 0755 ${DEVICEPATH}/cmd/device-random ${D}${EDGEX_BIN}

    install -d ${D}${EDGEX_ETC}/device-random
    install -m 0644 ${WORKDIR}/device-random.toml ${D}${EDGEX_ETC}/device-random/${EDGEX_CONFIGURATION_FILE}
    install -m 0644 ${DEVICEPATH}/cmd/res/device.random.yaml ${D}${EDGEX_ETC}/device-random

    # Launch Script
    install -m 0755 ${WORKDIR}/device-random-launch.sh ${D}${EDGEX_BIN}
}