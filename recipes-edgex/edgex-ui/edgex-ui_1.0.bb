require edgex-ui.inc

DESCRIPTION = "EdgeX Web UI"
SUMMARY = "EdgeX Foundry is a vendor-neutral open source project hosted by The Linux Foundation building a common open framework for IoT edge computing."
HOMEPAGE = "https://www.edgexfoundry.org/"

PR = "r1"

LICENSE = "CLOSED"

SRC_URI = "git://github.com/edgexfoundry/edgex-ui-go.git;protocol=https;branch=fuji \
           file://edgex-ui-server.toml \
           file://edgex-ui-launch.sh \
           "
SRCREV = "277361c19809286defc6bccd20bc08e304c6ef7c"