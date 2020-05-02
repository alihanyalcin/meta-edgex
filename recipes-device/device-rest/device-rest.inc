DESCRIPTION = "Device service for REST protocol."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/device-rest-go"
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
    install -m 0755 ${DEVICEPATH}/cmd/device-rest-go ${D}${EDGEX_BIN}/device-rest

    install -d ${D}${EDGEX_ETC}/device-rest
    install -m 0644 ${WORKDIR}/device-rest.toml ${D}${EDGEX_ETC}/device-rest/${EDGEX_CONFIGURATION_FILE}
    install -m 0644 ${DEVICEPATH}/cmd/res/*.yaml ${D}${EDGEX_ETC}/device-rest

    # Launch Script
    install -m 0755 ${WORKDIR}/device-rest-launch.sh ${D}${EDGEX_BIN}
}