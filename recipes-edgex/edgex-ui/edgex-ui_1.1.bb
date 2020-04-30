require edgex-ui.inc

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/edgex-ui-go.git;protocol=https;branch=fuji \
           file://edgex-ui-server.toml \
           file://edgex-ui-launch.sh \
           "
SRCREV = "277361c19809286defc6bccd20bc08e304c6ef7c"