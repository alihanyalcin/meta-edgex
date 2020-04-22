DESCRIPTION = "EdgeX Web UI - Fuji Release"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/edgex-ui-go"

INSANE_SKIP_${PN} = "file-rdeps"
FILES_${PN} += "${datadir}/*"
do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH

    cd ${B}/src/${GO_IMPORT}

    oe_runmake
}

do_install() {
    EDGEXUIPATH="${B}/src/${GO_IMPORT}"
    
    install -d ${D}${EDGEX_BIN}
    install -m 0755 ${EDGEXUIPATH}/cmd/edgex-ui-server/edgex-ui-server ${D}${EDGEX_BIN}
    
    install -d ${D}${EDGEX_ETC}/edgex-ui-server
    install -m 0644 ${WORKDIR}/edgex-ui-server.toml ${D}${EDGEX_ETC}/edgex-ui-server/${EDGEX_CONFIGURATION_FILE}
    
    cd ${EDGEXUIPATH}/cmd
    for i in $(find edgex-ui-server/static/ -type d); do
        install -d ${D}${datadir}/"$i"
    done

    for i in $(find edgex-ui-server/static/ -type f); do
        install -m 0644 "$i" ${D}${datadir}/"$i"
    done

    # Launch Script
    install -m 0755 ${WORKDIR}/edgex-ui-launch.sh ${D}${EDGEX_BIN}
}