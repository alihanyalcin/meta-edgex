DESCRIPTION = "EdgeX Foundry Services"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go pkgconfig

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/edgexfoundry/edgex-go"
EDGEXPATH = "${B}/src/${GO_IMPORT}"

INSANE_SKIP_${PN} = "file-rdeps"

DEPENDS += "zeromq"

do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH
    PKG_CONFIG_PATH="${WORKDIR}:$PKG_CONFIG_PATH"
    export PKG_CONFIG_PATH

    cd ${EDGEXPATH}

    oe_runmake
}

do_install() {

    install -d ${D}${EDGEX_BIN}

    for microservice in ${MICROSERVICES} ; do
        install -m 0755 ${EDGEXPATH}/cmd/${microservice}/${microservice} ${D}${EDGEX_BIN}
        install -d ${D}${EDGEX_ETC}/${microservice}
        install -m 0644 ${WORKDIR}/${microservice}.toml ${D}${EDGEX_ETC}/${microservice}/${EDGEX_CONFIGURATION_FILE}
    done
    
    # Launch Script
    install -m 0755 ${WORKDIR}/edgex-fuji-launch.sh ${D}${EDGEX_BIN}
}

#addtask do_prepare_edgex_conf after do_compile before do_install
#do_prepare_edgex_conf() {
#    CMD="${B}/src/${GO_IMPORT}"
#
#    for microservice in ${MICROSERVICES} ; do
#        sed -i 's+./logs+${EDGEX_LOG}+g' ${CMD}/cmd/${microservice}/res/${EDGEX_CONFIGURATION_FILE}
#    done
#}