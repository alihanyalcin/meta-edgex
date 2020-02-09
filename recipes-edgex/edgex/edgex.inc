DESCRIPTION = "EdgeX Foundry Services"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

GO_IMPORT = "github.com/alihanyalcin/edgex-go"
GO_PKGCONFIG = "github.com/rjeczalik/pkgconfig/cmd/pkg-config"

inherit go

INSANE_SKIP_${PN} = "ldflags textrel file-rdeps"
INSANE_SKIP_${PN}-dev = "ldflags textrel file-rdeps"
INSANE_SKIP_${PN}-staticdev = "file-rdeps"

DEPENDS += "libsodium zeromq"

do_compile() {
    GOPATH="${B}:${S}"
    export GOPATH
    PATH="${B}/bin:$PATH"
    export PATH


    go get github.com/rjeczalik/pkgconfig/cmd/pkg-config 
    cd ${B}/src/${GO_PKGCONFIG}
    go build
    
    PKG_CONFIG_PATH="${B}/lib/linux_arm/libzmq:${B}/lib/linux_arm/libsodium:${B}/lib/linux_arm/libpgm:$PKG_CONFIG_PATH"
    export PKG_CONFIG_PATH
    
    #mkdir -p ${B}/src/$(dirname ${GO_IMPORT})
    #test -e ${B}/src/${GO_IMPORT} || ln -s ${S} ${B}/src/${GO_IMPORT}
    cd ${B}/src/${GO_IMPORT}

    oe_runmake
}