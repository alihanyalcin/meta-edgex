DESCRIPTION = "EdgeX Foundry Services"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/device-modbus-go"

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
    install -m 0755 ${DEVICEPATH}/cmd/device-modbus ${D}${EDGEX_BIN}

    install -d ${D}${EDGEX_ETC}/device-modbus
    install -m 0644 ${WORKDIR}/device-modbus.toml ${D}${EDGEX_ETC}/device-modbus/${EDGEX_CONFIGURATION_FILE}
    install -m 0644 ${DEVICEPATH}/cmd/res/example/*.yml ${D}${EDGEX_ETC}/device-modbus
}