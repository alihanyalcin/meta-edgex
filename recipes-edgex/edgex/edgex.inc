DESCRIPTION = "EdgeX Foundry Services"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

inherit go pkgconfig

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/alihanyalcin/edgex-go"

INSANE_SKIP_${PN} = "ldflags textrel file-rdeps"
INSANE_SKIP_${PN}-dev = "ldflags textrel file-rdeps"
INSANE_SKIP_${PN}-staticdev = "file-rdeps"

DEPENDS += "zeromq "

do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH
    PKG_CONFIG_PATH="${WORKDIR}:$PKG_CONFIG_PATH"
    export PKG_CONFIG_PATH

    
    #mkdir -p ${B}/src/$(dirname ${GO_IMPORT})
    #test -e ${B}/src/${GO_IMPORT} || ln -s ${S} ${B}/src/${GO_IMPORT}
    cd ${B}/src/${GO_IMPORT}

    oe_runmake
}

addtask do_prepare_edgex_conf after do_compile before do_install
do_prepare_edgex_conf() {
    CMD="${B}/src/${GO_IMPORT}"

    sed -i 's+./logs/edgex-config-seed.log+${EDGEX_LOG}${EDGEX_CONFIG_SEED_LOG}+g' ${CMD}/${EDGEX_CONFIG_SEED_CONFIGURATION}
    sed -i 's+./logs/edgex-core-command.log+${EDGEX_LOG}${EDGEX_CORE_COMMAND_LOG}+g' ${CMD}/${EDGEX_CORE_COMMAND_CONFIGURATION}
    sed -i 's+./logs/edgex-core-data.log+${EDGEX_LOG}${EDGEX_CORE_DATA_LOG}+g' ${CMD}/${EDGEX_CORE_DATA_CONFIGURATION}
    sed -i 's+./logs/edgex-core-metadata.log+${EDGEX_LOG}${EDGEX_CORE_METADATA_LOG}+g' ${CMD}/${EDGEX_CORE_METADATA_CONFIGURATION}
    sed -i 's+./logs/edgex-export-client.log+${EDGEX_LOG}${EDGEX_EXPORT_CLIENT_LOG}+g' ${CMD}/${EDGEX_EXPORT_CLIENT_CONFIGURATION}
    sed -i 's+./logs/edgex-export-distro.log+${EDGEX_LOG}${EDGEX_EXPORT_DISTRO_LOG}+g' ${CMD}/${EDGEX_EXPORT_DISTRO_CONFIGURATION}
    sed -i 's+./logs/edgex-support-logging.log+${EDGEX_LOG}${EDGEX_SUPPORT_LOGGING_LOG}+g' ${CMD}/${EDGEX_SUPPORT_LOGGING_CONFIGURATION}
    sed -i 's+./logs/edgex-support-notifications.log+${EDGEX_LOG}${EDGEX_SUPPORT_NOTIFICATIONS_LOG}+g' ${CMD}/${EDGEX_SUPPORT_NOTIFICATIONS_CONFIGURATION}
    sed -i 's+./logs/edgex-support-scheduler.log+${EDGEX_LOG}${EDGEX_SUPPORT_SCHEDULER_LOG}+g' ${CMD}/${EDGEX_SUPPORT_SCHEDULER_CONFIGURATION}
    sed -i 's+./logs/edgex-sys-mgmt-agent.log+${EDGEX_LOG}${EDGEX_MANAGEMENT_AGENT_LOG}+g' ${CMD}/${EDGEX_MANAGEMENT_AGENT_CONFIGURATION}
}