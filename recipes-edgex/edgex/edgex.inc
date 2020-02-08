DESCRIPTION = "EdgeX Foundry Services"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/alihanyalcin/edgex-go"

inherit go

INSANE_SKIP_${PN} = "ldflags textrel file-rdeps"
INSANE_SKIP_${PN}-dev = "ldflags textrel file-rdeps"
INSANE_SKIP_${PN}-staticdev = "file-rdeps"

#IMAGE_INSTALL += "zeromq"

do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH

    mkdir -p ${B}/src/$(dirname ${GO_IMPORT})
    test -e ${B}/src/${GO_IMPORT} || ln -s ${S} ${B}/src/${GO_IMPORT}
    cd ${B}/src/${GO_IMPORT}

    oe_runmake
}