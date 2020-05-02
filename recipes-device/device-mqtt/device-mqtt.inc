DESCRIPTION = "Device service for connecting a MQTT topic to EdgeX acting like a device/sensor feed."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/device-mqtt-go"
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
    install -m 0755 ${DEVICEPATH}/cmd/device-mqtt ${D}${EDGEX_BIN}

    install -d ${D}${EDGEX_ETC}/device-mqtt
    install -m 0644 ${WORKDIR}/device-mqtt.toml ${D}${EDGEX_ETC}/device-mqtt/${EDGEX_CONFIGURATION_FILE}
    install -m 0644 ${DEVICEPATH}/cmd/res/example/*.yml ${D}${EDGEX_ETC}/device-mqtt

    # Launch Script
    install -m 0755 ${WORKDIR}/device-mqtt-launch.sh ${D}${EDGEX_BIN}
}